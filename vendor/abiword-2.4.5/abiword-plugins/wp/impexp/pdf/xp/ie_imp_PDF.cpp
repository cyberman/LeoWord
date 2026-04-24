/* AbiWord
 * Copyright (C) 2005 Dom Lachowicz <cinamod@hotmail.com>
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ut_string.h"
#include "ut_types.h"
#include "ie_imp_Text.h"

#include "xap_Module.h"

/* XPDF/Poppler includes */
#include "GlobalParams.h"
#include "Object.h"
#include "Stream.h"
#include "Array.h"
#include "Dict.h"
#include "XRef.h"
#include "Catalog.h"
#include "Page.h"
#include "PDFDoc.h"
#include "TextOutputDev.h"
#include "CharTypes.h"
#include "UnicodeMap.h"
#include "Error.h"

class ABI_EXPORT IE_Imp_PDF : public IE_Imp
{
public:

  IE_Imp_PDF (PD_Document * pDocument)
    : IE_Imp(pDocument)
  {
  }

  virtual ~IE_Imp_PDF ()
  {
  }
  
  virtual UT_Error importFile(const char * szFilename)
  {
    UT_Error rval = UT_ERROR;

    GooString * fileName = new GooString(szFilename);
  
    PDFDoc * doc = new PDFDoc(fileName);

    globalParams = new GlobalParams("");
    globalParams->setTextEncoding("UTF-8");
    globalParams->setTextEOL("\n");
    globalParams->setTextPageBreaks(gFalse);
    globalParams->setErrQuiet(gTrue);

    if(doc->isOk()) {
      char temporary_file[2048];

      UT_tmpnam(temporary_file);

      TextOutputDev *textOut = new TextOutputDev(temporary_file, gFalse, gFalse, gFalse);
      doc->displayPages(textOut, 1, doc->getNumPages(), 72, 72, 0, gTrue, gFalse);
      delete textOut;

      IE_Imp_Text txt_imp(getDoc(), "UTF-8");      
      rval = txt_imp.importFile(temporary_file);

      remove(temporary_file);
    }

    delete globalParams;

    delete fileName;

    return rval;
  }

};

/*****************************************************************/
/*****************************************************************/

class ABI_EXPORT IE_Imp_PDF_Sniffer : public IE_ImpSniffer
{
public:

  IE_Imp_PDF_Sniffer()
    : IE_ImpSniffer("application/pdf", false)
  {
  }
	
  virtual ~IE_Imp_PDF_Sniffer()
  {
  }
  
  UT_Confidence_t supportsMIME (const char * szMIME)
  {
    if (strncmp (szMIME, "application/pdf", 15) == 0)
      {
	return UT_CONFIDENCE_PERFECT;
      }
    return UT_CONFIDENCE_ZILCH;
  }

  virtual UT_Confidence_t recognizeContents (const char * szBuf,
					     UT_uint32 iNumbytes)
  {
    if (!strncmp (szBuf, "%PDF-", 5))
      return UT_CONFIDENCE_PERFECT;
    return UT_CONFIDENCE_ZILCH;
  }

  const char * recognizeContentsType (const char * szBuf,
				      UT_uint32 iNumbytes)
  {
    return "none";
  }

  virtual UT_Confidence_t recognizeSuffix (const char * szSuffix)
  {
    if (!UT_stricmp (szSuffix, ".pdf"))
      return UT_CONFIDENCE_PERFECT;
    return UT_CONFIDENCE_ZILCH;
  }

  virtual bool getDlgLabels (const char ** pszDesc,
			     const char ** pszSuffixList,
			     IEFileType * ft)
  {
    *pszDesc = "PDF (.pdf)";
    *pszSuffixList = "*.pdf";
    *ft = getFileType();
    return true;
  }

  virtual UT_Error constructImporter (PD_Document * pDocument,
				      IE_Imp ** ppie)
  {
    IE_Imp_PDF * p = new IE_Imp_PDF(pDocument);
    *ppie = p;
    return UT_OK;
  }
};

/*****************************************************************/
/* General plugin stuff                                          */
/*****************************************************************/

ABI_PLUGIN_DECLARE("PDF")

// we use a reference-counted sniffer
static IE_Imp_PDF_Sniffer * m_impSniffer = 0;

ABI_FAR_CALL
int abi_plugin_register (XAP_ModuleInfo * mi)
{
  if (!m_impSniffer)
    {
      m_impSniffer = new IE_Imp_PDF_Sniffer ();
    }
  else
    {
      m_impSniffer->ref();
    }
  
  mi->name    = "PDF Import Filter";
  mi->desc    = "Import Adobe PDF Documents";
  mi->version = ABI_VERSION_STRING;
  mi->author  = "Dom Lachowicz <cinamod@hotmail.com>";
  mi->usage   = "No Usage";
  
  IE_Imp::registerImporter (m_impSniffer);
  return 1;
}

ABI_FAR_CALL
int abi_plugin_unregister (XAP_ModuleInfo * mi)
{
  mi->name = 0;
  mi->desc = 0;
  mi->version = 0;
  mi->author = 0;
  mi->usage = 0;
  
  UT_ASSERT (m_impSniffer);

  IE_Imp::unregisterImporter (m_impSniffer);
  if (!m_impSniffer->unref())
    {
      m_impSniffer = 0;
    }

  return 1;
}

ABI_FAR_CALL
int abi_plugin_supports_version (UT_uint32 major, UT_uint32 minor, 
				 UT_uint32 release)
{
  return 1;
}
