/* AbiSource
 * 
 * Copyright (C) 2005 INdT
 * Author: Daniel d'Andrada T. de Carvalho <daniel.carvalho@indt.org.br>
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
#include "ODe_Style_MasterPage.h"

// Internal includes
#include "ODe_Common.h"

// AbiWord includes
#include <pp_AttrProp.h>


/**
 * Constructor
 */
ODe_Style_MasterPage::ODe_Style_MasterPage (const XML_Char* pName,
                                            const XML_Char* pPageLayoutName) {

    m_name = pName;
    m_pageLayoutName = pPageLayoutName;

    m_pFooterContentTemp = tmpfile();
    m_pHeaderContentTemp = tmpfile();
}


/**
 * Destructor
 */
ODe_Style_MasterPage::~ODe_Style_MasterPage() {
    if (m_pHeaderContentTemp != NULL) {
        fclose(m_pHeaderContentTemp);
    }
    
    if (m_pFooterContentTemp != NULL) {
        fclose(m_pFooterContentTemp);
    }
}


/**
 * Fetches info from an AbiWord <section> tag (from its attributes as properties).
 */
void ODe_Style_MasterPage::fetchAttributesFromAbiSection(const PP_AttrProp* pAP) {
    const XML_Char* pValue;
    bool ok;
    
    ok = pAP->getAttribute("header", pValue);
    if (ok && pValue != NULL) {
        m_abiHeaderId = pValue;
    }
    
    ok = pAP->getAttribute("footer", pValue);
    if (ok && pValue != NULL) {
        m_abiFooterId = pValue;
    }
}


/**
 * 
 */
bool ODe_Style_MasterPage::write(GsfOutput* pODT) const {
    
    UT_UTF8String output;
    size_t bytesRead;
    UT_Byte byteBuffer[1000];
    
    UT_UTF8String_sprintf(output,
        "  <style:master-page style:name=\"%s\" style:page-layout-name=\"%s\">\n",
        m_name.utf8_str(), m_pageLayoutName.utf8_str());
        
    ODe_writeUTF8String(pODT, output);
    
    if (!m_abiHeaderId.empty()) {
        // It has a header
        ODe_writeUTF8String(pODT, "   <style:header>\n");

        rewind(m_pHeaderContentTemp);

        while (feof(m_pHeaderContentTemp) == 0) {
            bytesRead = fread((void *)byteBuffer, 1, 1000, m_pHeaderContentTemp);
            
            ODe_gsf_output_write(pODT, bytesRead, (guint8 const *)byteBuffer);
        }        
        
        ODe_writeUTF8String(pODT, "   </style:header>\n");
    }

    if (!m_abiFooterId.empty()) {
        // It has a footer
        ODe_writeUTF8String(pODT, "   <style:footer>\n");

        rewind(m_pFooterContentTemp);

        while (feof(m_pFooterContentTemp) == 0) {
            bytesRead = fread((void *)byteBuffer, 1, 1000, m_pFooterContentTemp);
            
            ODe_gsf_output_write(pODT, bytesRead, (guint8 const *)byteBuffer);
        }        

        ODe_writeUTF8String(pODT, "   </style:footer>\n");
    }


    ODe_writeUTF8String(pODT, "  </style:master-page>\n");

    return true;
}
