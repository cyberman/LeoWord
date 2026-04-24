/* AbiWord
 * Copyright (C) 1998 AbiSource, Inc.
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


#include <stdlib.h>
#include <string.h>
#include <locale.h>

#include "ut_string.h"
#include "ut_bytebuf.h"
#include "ut_base64.h"
#include "ut_units.h"
#include "ut_debugmsg.h"
#include "pt_Types.h"
#include "ie_exp_WML.h"
#include "pd_Document.h"
#include "pp_AttrProp.h"
#include "px_ChangeRecord.h"
#include "px_CR_Object.h"
#include "px_CR_Span.h"
#include "px_CR_Strux.h"
#include "ie_Table.h"
#include "fd_Field.h"
#include "xap_App.h"

#include "ut_path.h"
#include "xap_EncodingManager.h"

#include "ut_string_class.h"

// first declare the listener

/*****************************************************************/
/*****************************************************************/

class s_WML_Listener : public PL_Listener
{
public:
	s_WML_Listener(PD_Document * pDocument,
		       IE_Exp_WML * pie);
	virtual ~s_WML_Listener();

	virtual bool		populate(PL_StruxFmtHandle sfh,
					 const PX_ChangeRecord * pcr);

	virtual bool		populateStrux(PL_StruxDocHandle sdh,
					      const PX_ChangeRecord * pcr,
					      PL_StruxFmtHandle * psfh);

	virtual bool		change(PL_StruxFmtHandle sfh,
				       const PX_ChangeRecord * pcr);

	virtual bool		insertStrux(PL_StruxFmtHandle sfh,
					    const PX_ChangeRecord * pcr,
					    PL_StruxDocHandle sdh,
					    PL_ListenerId lid,
					    void (* pfnBindHandles)(PL_StruxDocHandle sdhNew,
								    PL_ListenerId lid,
								    PL_StruxFmtHandle sfhNew));
  
        virtual bool		signal(UT_uint32 iSignal);

protected:
	void				_closeSection(void);
	void				_closeBlock(void);
	void				_closeSpan(void);
	void				_closeAnchor(void);
	void				_closeHyperlink(void);
	void				_openParagraph(PT_AttrPropIndex api);
	void				_openSection(PT_AttrPropIndex api);
	void				_openSpan(PT_AttrPropIndex api);
	char *				_stripSuffix(const char* from, char delimiter);

  void _openTable(PT_AttrPropIndex api) ;
  void _closeTable(void);
  void _openCell(PT_AttrPropIndex api);
  void _closeCell(void);
  void _closeRow(void);

	void				_outputData(const UT_UCSChar * p, UT_uint32 length);
	void				_handleDataItems();
	
	PD_Document *		m_pDocument;
	IE_Exp_WML *		m_pie;
	bool			m_bInBlock;
	bool			m_bInSpan;
	bool			m_bInAnchor;
	bool			m_bInHyperlink;
	bool			m_bInCell;
	bool			m_bInRow;
	bool			m_bInTable;
	bool			m_bWasSpace;

	const PP_AttrProp*	m_pAP_Span;

  UT_Vector		m_utvDataIDs;	// list of data ids for image enumeration
  ie_Table mTableHelper;
};

/*****************************************************************/
/*****************************************************************/

IE_Exp_WML::IE_Exp_WML(PD_Document * pDocument)
	: IE_Exp(pDocument)
{
	m_error = 0;
	m_pListener = NULL;
}

IE_Exp_WML::~IE_Exp_WML()
{
}

/*****************************************************************/
/*****************************************************************/

IE_Exp_WML_Sniffer::IE_Exp_WML_Sniffer (const char * name) :
  IE_ExpSniffer(name)
{
  // 
}

bool IE_Exp_WML_Sniffer::recognizeSuffix(const char * szSuffix)
{
	return (!UT_stricmp(szSuffix,".wml"));
}

UT_Error IE_Exp_WML_Sniffer::constructExporter(PD_Document * pDocument,
											   IE_Exp ** ppie)
{
	IE_Exp_WML * p = new IE_Exp_WML(pDocument);
	*ppie = p;
	return UT_OK;
}

bool IE_Exp_WML_Sniffer::getDlgLabels(const char ** pszDesc,
									  const char ** pszSuffixList,
									  IEFileType * ft)
{
	*pszDesc = "WML (.wml)";
	*pszSuffixList = "*.wml";
	*ft = getFileType();
	return true;
}

/*****************************************************************/
/*****************************************************************/

UT_Error IE_Exp_WML::_writeDocument(void)
{
	m_pListener = new s_WML_Listener(getDoc(),this);
	if (!m_pListener)
		return UT_IE_NOMEMORY;
	if (!getDoc()->tellListener(static_cast<PL_Listener *>(m_pListener)))
		return UT_ERROR;
	delete m_pListener;

	m_pListener = NULL;
	
	return ((m_error) ? UT_IE_COULDNOTWRITE : UT_OK);
}

/*****************************************************************/
/*****************************************************************/

s_WML_Listener::s_WML_Listener(PD_Document * pDocument,
			       IE_Exp_WML * pie)
  : mTableHelper(pDocument)
{
	m_pDocument = pDocument;
	m_pie = pie;
	m_bInBlock = false;
	m_bInSpan = false;
	m_bInAnchor = false;
	m_bInHyperlink = false;
	m_bInCell = false;
	m_bInRow = false;
	m_bInTable = false;
	m_bWasSpace = false;

	m_pie->write("<!DOCTYPE wml PUBLIC \"-//PHONE.COM//DTD WML 1.1//EN\"\n");
	m_pie->write("\t\"http://www.phone.com/dtd/wml11.dtd\" >\n");

	/* keep ads to a minimum. size is at a premium */
	m_pie->write("<!-- This WML file was created by AbiWord -->\n");
	m_pie->write("<!-- See http://www.abisource.com/ -->\n\n");

	m_pie->write("<wml>\n");
	m_pie->write("<card>\n");
}

s_WML_Listener::~s_WML_Listener()
{
	_closeSpan();
	_closeBlock();
	_closeSection();
	_handleDataItems();

	UT_VECTOR_FREEALL(char*, m_utvDataIDs);

	m_pie->write("</card>\n");
	m_pie->write("</wml>\n");
}

/*****************************************************************/
/*****************************************************************/

char *s_WML_Listener::_stripSuffix(const char* from, char delimiter)
{
    char * fremove_s = static_cast<char *>(malloc(strlen(from)+1));
    strcpy(fremove_s, from);

    char * p = fremove_s + strlen(fremove_s);
    while ((p >= fremove_s) && (*p != delimiter))
        p--;

    if (p >= fremove_s)
	*p = '\0';

    return fremove_s;
}

void s_WML_Listener::_closeAnchor()
{
  if(!m_bInAnchor)
  {
    return;
  }

  m_pie->write("</anchor>");
  m_bInAnchor = false;
}

void s_WML_Listener::_closeHyperlink()
{
  if(!m_bInHyperlink)
  {
    return;
  }

  m_pie->write("</a>");
  m_bInHyperlink = false;
}

void s_WML_Listener::_closeTable()
{
  if(!m_bInTable)
  {
    return;
  }

  _closeCell();
  _closeRow();
  m_pie->write("</table>\n</p>\n");
  m_bInTable = false;
}

void s_WML_Listener::_closeRow()
{
  if(!m_bInRow || !m_bInTable)
  {
    return;
  }

  m_pie->write("</tr>\n");
  m_bInRow = false;
}

void s_WML_Listener::_closeCell()
{
  if(!m_bInCell || !m_bInTable)
  {
    return;
  }

  m_pie->write("</td>\n");
  m_bInCell = false;

  if ( mTableHelper.getNumCols () == mTableHelper.getRight () )
    {
      // logical end of a row
      _closeRow();
    } 
}

void s_WML_Listener::_openTable(PT_AttrPropIndex api)
{
  if(m_bInTable)
  {
    return; //no nested tables
  }

  UT_sint32 nCols = mTableHelper.getNumCols();
  
  UT_String tableSpec = UT_String_sprintf("<p>\n<table columns=\"%d\">\n",nCols);
  m_pie->write(tableSpec.c_str(), tableSpec.size());
  m_bInTable = true;
}

void s_WML_Listener::_openCell(PT_AttrPropIndex api)
{
  if(!m_bInTable)
  {
    return;
  }

  //wml 1.1 doesn't support colspan or rowspan

  if (mTableHelper.getLeft() == 0)
  {
    _closeCell();
    _closeRow();
  }

  if(!m_bInRow)
  {
    // beginning of a new row
    m_pie->write("<tr>\n");
    m_bInRow = true;
  }

  m_pie->write("<td>");
  m_bInCell = true;
}

/*****************************************************************/
/*****************************************************************/

void s_WML_Listener::_closeSection(void)
{
  // wml is simple: 1 section per document
  // we could get fancy with cards later
  return;
}

void s_WML_Listener::_openSection(PT_AttrPropIndex /* api*/)
{
  // wml is simple: 1 section per document
  // we could get fancy with cards later
  return;
}

void s_WML_Listener::_closeBlock(void)
{
	_closeAnchor();
	_closeHyperlink();

	if(!m_bInBlock)
	{
		return;
	}
	if(!m_bInTable)
	{
		m_pie->write("</p>\n");
	}

	m_bInBlock = false;
	return;
}

void s_WML_Listener::_openParagraph(PT_AttrPropIndex api)
{
        UT_DEBUGMSG(("OpenParagraph called!\n"));

	const PP_AttrProp * pAP = NULL;
	bool bHaveProp = m_pDocument->getAttrProp(api,&pAP);

	if (m_bInTable) //<p> tags aren't allowed inside of table-related tags
	{
		m_bInBlock = true;
		return;
	}
	
	if (bHaveProp && pAP)
	{
		const XML_Char * szValue;

		m_pie->write("<p");
		if (pAP->getProperty("text-align", szValue))
		{
		  if (!UT_strcmp(szValue, "center")) 
			m_pie->write(" align=\"center\"");
		  else if (!UT_strcmp(szValue, "right"))
		        m_pie->write(" align=\"right\"");
		  else //left or block-justify
		        m_pie->write(" align=\"left\"");
		}
		m_pie->write(">");
		
	}
	else 
	{
	  // <p> with no style attribute, and no properties either
	  m_pie->write("<p>");
	}

	m_bInBlock = true;
}

/*****************************************************************/
/*****************************************************************/

bool s_WML_Listener::populate(PL_StruxFmtHandle /*sfh*/,
				 const PX_ChangeRecord * pcr)
{
	switch (pcr->getType())
	{
	case PX_ChangeRecord::PXT_InsertSpan:
		{
			const PX_ChangeRecord_Span * pcrs = static_cast<const PX_ChangeRecord_Span *> (pcr);

			PT_AttrPropIndex api = pcr->getIndexAP();
			if (api)
			{
				_openSpan(api);
			}
			
			PT_BufIndex bi = pcrs->getBufIndex();
			_outputData(m_pDocument->getPointer(bi),pcrs->getLength());

			if (api)
				_closeSpan();
			return true;
		}

	case PX_ChangeRecord::PXT_InsertObject:
		{
			const PX_ChangeRecord_Object * pcro =
				static_cast<const PX_ChangeRecord_Object *> (pcr);
			const XML_Char* szValue;
			UT_String buf;

			fd_Field* field;
			PT_AttrPropIndex api = pcr->getIndexAP();
			const PP_AttrProp * pAP = NULL;
			bool bHaveProp = m_pDocument->getAttrProp(api,&pAP);

			switch (pcro->getObjectType())
			{
			case PTO_Image:

				if(bHaveProp && pAP && pAP->getAttribute("dataid", szValue))
				{
					char* dataid = strdup(static_cast<const char*>(szValue));

					m_utvDataIDs.push_back(dataid);

					char * temp = _stripSuffix(UT_basename(szValue), '_');
					char * fstripped = _stripSuffix(temp, '.');
					FREEP(temp);
					UT_String_sprintf(buf, "%s.png", fstripped);
					FREEP(fstripped);
					m_pie->write("<img alt=\"AbiWord Image ");
					m_pie->write(buf);
					m_pie->write("\" src=\"");
					m_pie->write(UT_basename(m_pie->getFileName()));
					m_pie->write("_data/");
					m_pie->write(buf);
					m_pie->write("\" ");
					const XML_Char * szWidth = 0;
					const XML_Char * szHeight = 0;

					const char * old_locale = setlocale(LC_NUMERIC, "C");

					if(pAP->getProperty("width", szWidth) &&
					   pAP->getProperty("height", szHeight))
					  {
					    if(szWidth)
					      {
						UT_String_sprintf(buf, "%f", UT_convertToDimension(szWidth, DIM_PX));
						m_pie->write (" width=\"");
						m_pie->write (buf);
						m_pie->write ("\" ");
					      }
					    if(szHeight)
					      {
						UT_String_sprintf(buf, "%f", UT_convertToDimension(szHeight, DIM_PX));
						m_pie->write (" height=\"");
						m_pie->write (buf);
						m_pie->write ("\" ");
					      }
					  }
					
					setlocale(LC_NUMERIC, old_locale);

					m_pie->write(" />");
				}
				return true;

			case PTO_Field:
				if(bHaveProp && pAP && pAP->getAttribute("type", szValue) && !(m_bInTable && (!m_bInRow || !m_bInCell)))
				{
					field = pcro->getField();

					if(UT_strcmp(szValue, "list_label") != 0)
					{
						m_pie->write(szValue);
					}
				}
				return true;

			case PTO_Hyperlink:
				if(bHaveProp && pAP && pAP->getAttribute("xlink:href", szValue))
				{
					UT_UTF8String url = szValue;
					url.escapeURL();
					_closeAnchor();
					_closeHyperlink();
					if(url.length() > 0)
					{
						m_pie->write("<a href=\"");
						m_pie->write(url.utf8_str());
						m_pie->write("\">");
						m_bInHyperlink = true;
					}
				}
				else
				{
					_closeHyperlink();
				}
				return true;

			case PTO_Bookmark:
				if(bHaveProp && pAP && pAP->getAttribute("type", szValue))
				{
					if( UT_XML_stricmp(szValue, "start") == 0 && m_bInHyperlink == 0 )
					{
						_closeAnchor(); //nested anchors not allowed
						pAP->getAttribute("name", szValue);
						m_pie->write("<anchor id=\"");
						m_pie->write(szValue);
						m_pie->write("\">");
						m_bInAnchor = true;
					}
					else
					{
						_closeAnchor();						
					}
				}
				return true;

			default:
				UT_ASSERT(UT_TODO);
				return true;
			}
		}

	case PX_ChangeRecord::PXT_InsertFmtMark:
		return true;
		
	default:
		UT_ASSERT(UT_TODO);
		return true;
	}
}

bool s_WML_Listener::populateStrux(PL_StruxDocHandle sdh,
				      const PX_ChangeRecord * pcr,
				      PL_StruxFmtHandle * psfh)
{
	UT_ASSERT(pcr->getType() == PX_ChangeRecord::PXT_InsertStrux);
	const PX_ChangeRecord_Strux * pcrx = static_cast<const PX_ChangeRecord_Strux *> (pcr);
	*psfh = 0;							// we don't need it.

	switch (pcrx->getStruxType())
	{
	case PTX_Block:
	  {
		_closeSpan();
		_closeBlock();
		_openParagraph(pcr->getIndexAP());
		return true;
	  }

	case PTX_SectionTable:
	  {
	    mTableHelper.OpenTable(sdh,pcr->getIndexAP()) ;
	    _closeSpan();
	    _closeBlock();
	    _openTable(pcr->getIndexAP());
	    return true ;
	  }
	case PTX_EndTable:
	  {
	    _closeBlock();
	    _closeTable();
	    mTableHelper.CloseTable();
	    return true ;
	  }
	case PTX_SectionCell:
	  {
	    mTableHelper.OpenCell(pcr->getIndexAP()) ;
	    _closeSpan();
	    _closeBlock();
	    _openCell(pcr->getIndexAP());
	    return true ;
	  }
	case PTX_EndCell:
	  {
	    _closeBlock();
	    _closeCell();
	    mTableHelper.CloseCell();
	    return true;
	  }

	case PTX_SectionEndnote:
	case PTX_SectionHdrFtr:
	case PTX_Section:
	case PTX_EndFrame:
	case PTX_EndMarginnote:
	case PTX_EndFootnote:
	case PTX_SectionFrame:
	case PTX_SectionMarginnote:
	case PTX_SectionFootnote:
	case PTX_EndEndnote:
	default:
		UT_ASSERT(UT_TODO);
		return true;
	}
}

bool s_WML_Listener::change(PL_StruxFmtHandle /*sfh*/,
			       const PX_ChangeRecord * /*pcr*/)
{
  UT_ASSERT(0);	    // this function is not used.
  return false;
}

bool s_WML_Listener::insertStrux(PL_StruxFmtHandle /*sfh*/,
				     const PX_ChangeRecord * /*pcr*/,
				     PL_StruxDocHandle /*sdh*/,
				     PL_ListenerId /* lid */,
				     void (* /*pfnBindHandles*/)(PL_StruxDocHandle /* sdhNew */,
								 PL_ListenerId /* lid */,
																 PL_StruxFmtHandle /* sfhNew */))
{
  UT_ASSERT(0);	    // this function is not used.
  return false;
}

bool s_WML_Listener::signal(UT_uint32 /* iSignal */)
{
	UT_ASSERT(UT_SHOULD_NOT_HAPPEN);
	return false;
}

void s_WML_Listener::_handleDataItems()
{
 	const char * szName;
	const char * szMimeType;
	const UT_ByteBuf * pByteBuf;

	for (UT_uint32 k=0; (m_pDocument->enumDataItems(k,NULL,&szName,&pByteBuf,reinterpret_cast<const void**>(&szMimeType))); k++)
	{
		UT_sint32 loc = -1;
		for (UT_uint32 i = 0; i < m_utvDataIDs.getItemCount(); i++)
		{
			if(UT_strcmp(static_cast<const char*>(m_utvDataIDs[i]), szName) == 0)
			{
				loc = i;
				break;
			}
		}

		if(loc > -1)
		{
			FILE *fp;
			UT_String fname;
#ifndef LEGIONS
			UT_String_sprintf(fname, "%s_data", m_pie->getFileName());
#else
			fname = "images";
#endif
			UT_sint32 result = m_pDocument->getApp()->makeDirectory(fname.c_str(), 0750);
			if (result < 0)
			{
				UT_DEBUGMSG(("Failed to create directory\n"));
				/* we might want to return an error here, 
				 * but I don't think so. */
			}

			if (!UT_strcmp(szMimeType, "image/svg+xml"))
				UT_String_sprintf(fname, "%s/%s_%d.svg", fname.c_str(), szName, loc);
			if (!UT_strcmp(szMimeType, "application/mathml+xml"))
				UT_String_sprintf(fname, "%s/%s_%d.mathml", fname.c_str(), szName, loc);
			else // PNG Image
			{
				char * temp = _stripSuffix(UT_basename(szName), '_');
				char * fstripped = _stripSuffix(temp, '.');
				FREEP(temp);
				UT_String_sprintf(fname, "%s/%s.png", fname.c_str(), fstripped);
				FREEP(fstripped);
			}

			if (!UT_isRegularFile(fname.c_str()))
			{
			    fp = fopen (fname.c_str(), "wb+");

			    if(!fp)
				    continue;

			    int cnt = 0, len = pByteBuf->getLength();

			    while (cnt < len)
			    {
				    cnt += fwrite (pByteBuf->getPointer(cnt),
						   sizeof(UT_Byte), len-cnt, fp);
			    }

			    fclose(fp);
			}
		}
	}
}

/*****************************************************************/
/*****************************************************************/

void s_WML_Listener::_openSpan(PT_AttrPropIndex api)
{
	if (!m_bInBlock || m_bInHyperlink || m_bInAnchor || (m_bInTable && (!m_bInRow || !m_bInCell)))
	{
		return;
	}
	
	const PP_AttrProp * pAP = NULL;
	bool bHaveProp = m_pDocument->getAttrProp(api,&pAP);

	if (bHaveProp && pAP)
	{
		const XML_Char * szValue;

		if (
			(pAP->getProperty("font-weight", szValue))
			&& !UT_strcmp(szValue, "bold")
			)
		{
		  m_pie->write("<b>");
		}
		
		if (
			(pAP->getProperty("font-style", szValue))
			&& !UT_strcmp(szValue, "italic")
			)
		{
		  m_pie->write("<i>");
		}

		
		if (
			(pAP->getProperty("text-decoration", szValue))
			)
		{
			const XML_Char* pszDecor = szValue;

			XML_Char* p;
			if (!UT_cloneString((char *&)p, pszDecor))
			{
				// TODO outofmem
			}
			
			UT_ASSERT(p || !pszDecor);
			XML_Char*	q = strtok(p, " ");

			while (q)
			{
				if (0 == UT_strcmp(q, "underline"))
				{
				      m_pie->write("<u>");
				}

				q = strtok(NULL, " ");
			}
			free(p);
		}

		// In my WML world...
		// superscript = big
		// subscript = small
		if (pAP->getProperty("text-position", szValue))
		{
			if (!UT_strcmp("superscript", szValue))
			{
				m_pie->write("<big>");
			}
			else if (!UT_strcmp("subscript", szValue))
			{
				m_pie->write("<small>");
			}
		}
		
		m_bInSpan = true;
		m_pAP_Span = pAP;
	}
}

void s_WML_Listener::_outputData(const UT_UCSChar * data, UT_uint32 length)
{
	if (!m_bInBlock || (m_bInTable && (!m_bInRow || !m_bInCell)))
	{
		return;
	}
	
	// TODO deal with unicode.
	// TODO for now, just squish it into ascii.
	
	UT_UTF8String sBuf;
	const UT_UCSChar * pData;

	for (pData=data; (pData<data+length); /**/)
	{
		switch (*pData)
		{
		case '<':
			sBuf += "&lt;";
			pData++;
			break;
			
		case '>':
			sBuf += "&gt;";
			pData++;
			break;
			
		case '&':
			sBuf += "&amp;";
			pData++;
			break;

		case UCS_VTAB:					// column break, export as a linebreak for now
		case UCS_FF:					// page break, export as a linebreak for now
		case UCS_LF:					// LF -- representing a Forced-Line-Break
			sBuf += "<br/>";
			pData++;
			break;

		case ' ':
		case '\t':
		  // try to honor multiple spaces
		  // tabs get treated as a single space
		  //
		  if(m_bWasSpace)
		    {
				sBuf += "&nbsp;";
				pData++;
		    }
		  else
		    {
		      // just tack on a single space to the textrun
		      m_bWasSpace = true;
		      sBuf += " ";
		      pData++;
		    }
		  break;

		default:
		  sBuf.appendUCS4(pData, 1);
		  pData++;
		}
	}

	m_pie->write(sBuf.utf8_str(),sBuf.byteLength());
}

void s_WML_Listener::_closeSpan(void)
{
	if (!m_bInSpan || m_bInHyperlink || m_bInAnchor)
		return;

	const PP_AttrProp * pAP = m_pAP_Span;
	
	if (pAP)
	{

		const XML_Char * szValue;
		
		if (pAP->getProperty("text-position", szValue))
		{
			if (!UT_strcmp("superscript", szValue))
			{
				m_pie->write("</big>");
			}
			else if (!UT_strcmp("subscript", szValue))
			{
				m_pie->write("</small>");
			}
		}

		if ((pAP->getProperty("text-decoration", szValue)))
		{
			const XML_Char* pszDecor = szValue;

			XML_Char* p;
			if (!UT_cloneString((char *&)p, pszDecor))
			{
				// TODO outofmem
			}
			
			UT_ASSERT(p || !pszDecor);
			XML_Char*	q = strtok(p, " ");

			while (q)
			{
				if (0 == UT_strcmp(q, "underline"))
				{
				      m_pie->write("</u>");
				}

				q = strtok(NULL, " ");
			}
			free(p);
		}

		if (
			(pAP->getProperty("font-style", szValue))
			&& !UT_strcmp(szValue, "italic")
			)
		{
		  m_pie->write("</i>");
		}
		
		if (
			(pAP->getProperty("font-weight", szValue))
			&& !UT_strcmp(szValue, "bold")
			)
		{
		  m_pie->write("</b>");
		}

		m_pAP_Span = NULL;
	}

	m_bInSpan = false;
	return;
}
