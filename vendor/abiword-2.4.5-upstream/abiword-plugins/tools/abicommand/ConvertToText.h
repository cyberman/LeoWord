/*
 * ConvertFileToText using the AbiWord command line interface.
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
 */
#ifndef ABI_CONVERTTEXT_H
#define ABI_CONVERTTEXT_H

int  convertFileToText(const char * inFile, const char * outFile);
int  convertFileToPNG(const char * inFile, const char * outFile, int iWidth, int iHeight);
int  finalizeConversions(void);
#endif /* ABI_CONVERTTEXT_H */
