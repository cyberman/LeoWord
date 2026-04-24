/* AbiSource
 * 
 * Copyright (C) 2002 Dom Lachowicz <cinamod@hotmail.com>
 * Copyright (C) 2004 Robert Staudinger <robsta@stereolyzer.net>
 * Copyright (C) 2005 Daniel d'Andrada T. de Carvalho
 * <daniel.carvalho@indt.org.br>
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  
 * 02111-1307, USA.
 */
 
// Class definition include
#include "ie_imp_OpenDocument_Sniffer.h"

// Internal includes
#include "ie_imp_OpenDocument.h"


 
/**
 * Constructor
 * 
 */
IE_Imp_OpenDocument_Sniffer::IE_Imp_OpenDocument_Sniffer () :
    IE_ImpSniffer("OpenDocument::ODT")
{
    
}




/**
 * Destructor
 * 
 */
IE_Imp_OpenDocument_Sniffer::~IE_Imp_OpenDocument_Sniffer ()
{
}





/**
 * Recognize the well-known suffixes, if any
 * 
 */
UT_Confidence_t IE_Imp_OpenDocument_Sniffer::recognizeSuffix (const char * szSuffix)
{
	if (!UT_stricmp(szSuffix, ".odt")) {
	    return UT_CONFIDENCE_PERFECT;
	}

    return UT_CONFIDENCE_ZILCH;
}




 
/**
 * Recognize the contents as best we can
 * 
 */
UT_Confidence_t IE_Imp_OpenDocument_Sniffer::recognizeContents (
                                                 const char * szBuf, 
                                                 UT_uint32 iNumbytes)
{
    // BOGUS - will identify any zip file, also contains null characters
    static const char magic[10] = {'P','K',0x03,0x04,0x14,'\0','\0','\0','\0','\0'};  
    UT_uint32 magic_len = sizeof ( magic );
  
    if (iNumbytes < magic_len) {
        return UT_CONFIDENCE_ZILCH;
    }
  
    if ( !strncmp (szBuf, magic, magic_len) ) {
        return UT_CONFIDENCE_SOSO;
    }
    
    return UT_CONFIDENCE_ZILCH;
}








/**
 * Construct an importer for ourselves
 * 
 */
UT_Error IE_Imp_OpenDocument_Sniffer::constructImporter (
                                        PD_Document* pDocument,
                                        IE_Imp** ppie)
{
    IE_Imp_OpenDocument* p = new IE_Imp_OpenDocument(pDocument);
    *ppie = p;
  
    return UT_OK;
}






/**
 * Get the dialog labels
 * 
 */
bool IE_Imp_OpenDocument_Sniffer::getDlgLabels (const char ** szDesc,
                          const char ** szSuffixList,
                          IEFileType * ft)
{
	*szDesc = "OpenDocument (.odt)";
	*szSuffixList = "*.odt";
	*ft = getFileType();
  
    return true;
}
