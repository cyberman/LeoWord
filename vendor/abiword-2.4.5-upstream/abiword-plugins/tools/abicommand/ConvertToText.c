/*
 * Convert WordProcessor Files To plain Text using remotely running AbiWord-2.2
 * process via it's command line interface.
 *
 * Copyright (C) (2003) by Martin Sevior <msevior@physics.unimelb.edu.au>
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public License
 *  as published by the Free Software Foundation; either version 2 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * The program is fault tolerant and will report if a requested
 * file is not capable of being coverted.
 * 
 * It will also restart AbiWord if it does crash on the next invocation
 * of convertFileToText.
 *
 * Remove the demo main program if you want to use these functions in your
 * own programs.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "ConvertToText.h"

static int m_iAbiRunning = -1;
static int m_iAbiPID = -1;
static FILE * m_AbiWritePipe;
static char m_szErrorFile[100];

/* Start the AbiWord process and set up pointers so we can communicate
 * with it.
 * Return 0 on success;
 */
static int startAbiRunning(void)
{
	char fullCommand[200];
	pid_t mypid;
	char pidName[40];
	struct stat myNameStat;
	int loop,iMyStat;
	FILE * fAbiPIDFile;
	fullCommand[0] = 0;
/*
    Uncomment to debug
*/
/*    strcat(fullCommand,"AbiWord-2.2 --plugin AbiCommand "); */
	strcat(fullCommand,"AbiWord-2.2 --plugin AbiCommand >& /dev/null ");
	fflush(stdout);
	m_AbiWritePipe = popen(fullCommand,"w");
	fflush(stdout);
	if(m_AbiWritePipe == NULL)
	{
		m_iAbiRunning = -1;
		return -1;
	}
	fullCommand[0] = 0;
	mypid=getpid();
	pidName[0] = 0;
	sprintf(pidName,"/tmp/abiconv_%d.txt",mypid);
	strcat(fullCommand,"writepid ");
	strcat(fullCommand,pidName);
/*	printf("File Name is %s \n",pidName); */
/*	printf("Full command is %s \n",fullCommand); */
	fflush(stdout);
	fprintf(m_AbiWritePipe,"%s \n",fullCommand);
	fflush(m_AbiWritePipe);
	iMyStat = -1;
	loop = 0;
	while((iMyStat == -1) && (loop < 1000))
	{
		iMyStat = stat(pidName,&myNameStat);
		if(iMyStat == 0)
		{
			if(myNameStat.st_size > 0)
			{
				break;
			}
		}
		usleep(100000);
	}
	if(iMyStat < 0)
	{
		m_iAbiRunning = -1;
		return -1;
	}
	fAbiPIDFile = fopen(pidName,"r");
	fscanf(fAbiPIDFile,"%d",&m_iAbiPID);
	fclose(fAbiPIDFile);
/*	printf("PID of remote AbiWord process is %d \n",m_iAbiPID); */
	unlink(pidName);
	m_iAbiRunning = 0;
	fprintf(m_AbiWritePipe,"server %s \n");
	fflush(m_AbiWritePipe);
	m_szErrorFile[0] = 0;
	sprintf(m_szErrorFile,"/tmp/AbiCommandError%d.txt",m_iAbiPID);
	printf("Error file is %s \n",m_szErrorFile);
	return 0;
}

/*
 * Returns 0 if the AbiWord process of PID given in our member variable
 * is running.
 * returns -1 if it isn't
 */
static int checkAbiIsRunning(void)
{
	char fullCommand[200];
	char szPID[40];
	FILE * psRes;
	fullCommand[0] = 0;
	szPID[0] = 0;
	sprintf(szPID,"%d",m_iAbiPID);
	sprintf(fullCommand,"ps %d ",m_iAbiPID);
	fflush(stdin);
	int iFound;
	psRes = popen(fullCommand,"r");
/*
 * Now read though all the output and look for our PID.
 */	
	iFound = -1;
	while ( !feof(psRes) && iFound == -1 )
	{
		fullCommand[0] = 0;
		fscanf(psRes,"%s",fullCommand);	
		if(strstr(fullCommand,szPID) != 0)
		{
			iFound = 0;
			break;
		}
	}
	pclose(psRes);
	if(iFound == 0)
	{
		m_iAbiRunning = 0;
		return 0;
	}
	m_iAbiRunning = -1;
	return -1;
}

/*
 * Looks to see if the conversion to the output file given by
 * outFile is completed.
 * It returns 0 if it's completed.
 * It returns -1 if it's not finished.
 * It returns -2 if The coversion was not successful.
 */
static int isConvertCompleted(const char * outFile)
{
	if(checkAbiIsRunning() == -1)
	{
		return -2;
	}
	struct stat myNameStat;
	int iMyStat;
	iMyStat = stat(outFile,&myNameStat);
	if(iMyStat == 0)
	{
		if(myNameStat.st_size > 0)
		{
			return 0;
		}
	}
	iMyStat = stat(m_szErrorFile,&myNameStat);
	if(iMyStat == 0)
	{
		return -3;
	}
	return -1;
}
/*
 * The function is fault tolerant and will report if a requested
 * file is not capable of being coverted.
 * 
 * It will also restart AbiWord if it does crash on the next invocation
 * of convertFileToText.
 *
 * Inputs: inFile - The path to the word processor file to be converted.
 *         outFile - The path to the file containing the plain text of the
 *                   word processor file.
 * The function blocks until the conversion is complete or until 
 * the conversion fails.
 * 
 * It returns 0 upon a successful conversion
 *    and -1 if the conversion fails.
 */
int convertFileToText(const char * inFile, const char * outFile)
{
	char fullCommand[200];
	int finished = -1;
	int iLoop = 0;
	if(m_iAbiRunning < 0)
	{
		startAbiRunning();
	}
	if(checkAbiIsRunning() < 0)
	{
		startAbiRunning();
		if(checkAbiIsRunning() < 0)
		{
			return -1;
		}
	}
	fullCommand[0] = 0;
	strcat(fullCommand,"converttotext ");
	strcat(fullCommand,inFile);
	if(outFile != NULL)
	{
		strcat(fullCommand," ");
		strcat(fullCommand,outFile);
	}
	fprintf(m_AbiWritePipe, "%s \n", fullCommand);
	fflush(m_AbiWritePipe);
	finished = -1;
	iLoop = 0;
	while(finished == -1 && (iLoop < 1000))
	{
		finished = isConvertCompleted(outFile);
		usleep(100000);
	}
	if(finished == -3)
	{
		unlink(m_szErrorFile);
		return -3;
	}
	if(iLoop >= 1000)
	{
/*		printf("Conversion timed out \n"); */
	}
	if(finished == 0)
	{
		return 0;
	}
	return -1;
}
/*
 * The function is fault tolerant and will report if a requested
 * file is not capable of being coverted.
 * 
 * It will also restart AbiWord if it does crash on the next invocation
 * of convertFileToText.
 *
 * Inputs: inFile - The path to the word processor file to be converted.
 *         outFile - The path to the PNG image of the first page of the doc
 *         iWidth - width in pixels of the document.
 *         iHeight - height in pixels of the document.
 * The function blocks until the conversion is complete or until 
 * the conversion fails.
 * 
 * It returns 0 upon a successful conversion
 *    and -1 if the conversion fails.
 */
int convertFileToPNG(const char * inFile, const char * outFile, int iWidth, int iHeight)
{
	char fullCommand[200];
	int finished = -1;
	int iLoop = 0;
	if(m_iAbiRunning < 0)
	{
		startAbiRunning();
	}
	if(checkAbiIsRunning() < 0)
	{
		startAbiRunning();
		if(checkAbiIsRunning() < 0)
		{
			return -1;
		}
	}
	fullCommand[0] = 0;
	sprintf(fullCommand,"previewpng %s %s %d %d",inFile,outFile,iWidth,iHeight);
	fprintf(m_AbiWritePipe, "%s \n", fullCommand);
	fflush(m_AbiWritePipe);
	finished = -1;
	iLoop = 0;
	while(finished == -1 && (iLoop < 1000))
	{
		finished = isConvertCompleted(outFile);
		usleep(100000);
	}
	if(finished == -3)
	{
		unlink(m_szErrorFile);
		return -3;
	}
	if(iLoop >= 1000)
	{
/*		printf("Conversion timed out \n"); */
	}
	if(finished == 0)
	{
		return 0;
	}
	return -1;
}

/*
 * Call this method after all conversions have completed. Otherwise you'll 
 * have a runaway AbiWord-2.2 process.
 */
int finalizeConversions(void)
{
	struct stat myNameStat;
	int iMyStat;
	if(checkAbiIsRunning() == 0)
	{
		fprintf(m_AbiWritePipe,"%s","quit");
		fflush(m_AbiWritePipe);
		pclose(m_AbiWritePipe);
		m_iAbiRunning = -1;
		m_iAbiPID = 0;
		m_AbiWritePipe = NULL;
	}
	iMyStat = stat(m_szErrorFile,&myNameStat);
	if(iMyStat == 0)
	{
		unlink(m_szErrorFile);
	}
}

/*
 * make this #ifdef 0 if you want to link these functions into your
 * program.
 */
#if 1
int main (int argc, char *argv [])
{
	int iWidth,iHeight;
	printf("Type: quit to exit this program \n");
	printf("Type: text to convert a file to text \n");
	printf("Type: png to convert a file to text \n");
	m_iAbiRunning = -1;
	m_iAbiPID = 0;
	int iQuit = -1;
	int isucc = -1;
	char inFile[100];
	char outFile[100];
	char command[100];
	command[0] = 0;
	while(iQuit == -1)
	{
		printf("Convert: ");
		scanf("%s",&command);
		if(strstr(command,"quit") != NULL)
		{
			iQuit = 0;
			finalizeConversions();
		}
		else if(strstr(command,"text") != NULL)
		{
			printf("give input and output names: ");
			scanf("%s %s",&inFile,&outFile);
			isucc = convertFileToText(inFile,outFile);
			if(isucc == 0)
			{
				printf("Conversion was successful \n");
			}
			else
			{
				printf("Conversion failed \n");
			}
		}
		else if(strstr(command,"png") != NULL)
		{
			printf("Give document filename, png filename, width and height of image \n");
			printf(": ");
			scanf("%s %s %d %d",&inFile,&outFile,&iWidth,&iHeight);
			isucc = convertFileToPNG(inFile,outFile,iWidth,iHeight);
			if(isucc == 0)
			{
				printf("Conversion was successful \n");
			}
			else
			{
				printf("Conversion failed \n");
			}
		}
	}
	exit(0);
}
#endif
