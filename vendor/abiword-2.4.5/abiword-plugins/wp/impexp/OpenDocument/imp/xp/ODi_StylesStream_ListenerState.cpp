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
#include "ODi_StylesStream_ListenerState.h"

// Internal includes
#include "ODi_Office_Styles.h"
#include "ODi_Style_MasterPage.h"
#include "ODi_Style_PageLayout.h"
#include "ODi_Style_Style.h"
#include "ODi_Style_List.h"
#include "ODi_NotesConfiguration.h"
#include "ODi_ListenerStateAction.h"
#include "ODi_StartTag.h"

// AbiWord includes
#include <ut_assert.h>


/**
 * Constructor
 * 
 * @param pDocument The AbiWord document to be built.
 * 
 * @param pMasterStyles The master styles place holder to be filled by
 *                      this listener.
 * @param pStyles The styles (common and automatic) place holder to be filled
 *                by this listener.
 */
ODi_StylesStream_ListenerState::ODi_StylesStream_ListenerState (
    PD_Document* pAbiDocument,
    GsfInfile* pGsfInfile,
    ODi_Office_Styles* pStyles,
    ODi_ElementStack& rElementStack)
            : ODi_ListenerState("StylesStream", rElementStack),
              m_pAbiDocument (pAbiDocument),
              m_pGsfInfile (pGsfInfile),
              m_pStyles (pStyles)
{
    UT_ASSERT(m_pStyles);
    UT_ASSERT(m_pAbiDocument);
    UT_ASSERT(m_pGsfInfile);
}

/**
 * Destructor
 */
ODi_StylesStream_ListenerState::~ODi_StylesStream_ListenerState()
{
}

/**
 * 
 */
void ODi_StylesStream_ListenerState::startElement (const XML_Char* pName,
                                            const XML_Char** ppAtts,
                                            ODi_ListenerStateAction& rAction)
{
    
    if (!UT_strcmp (pName, "style:master-page")) {

        ODi_ListenerState* pMasterStyle = m_pStyles->addMasterPage(ppAtts,
                                                                  m_pAbiDocument,
                                                                  m_rElementStack);
            
        rAction.pushState(pMasterStyle, false);

    } else if (!strcmp (pName, "style:style")) {

        ODi_ListenerState* pStyle;

        pStyle = m_pStyles->addStyle(ppAtts, m_rElementStack);
        
        // pStyle can be null for unsupported (ignored) styles.
        if (pStyle) {
            rAction.pushState(pStyle, false);
        }

    } else if (!strcmp (pName, "style:page-layout")) {
        
        ODi_ListenerState* pStylePageLayout;

        pStylePageLayout = m_pStyles->addPageLayout(ppAtts, m_rElementStack);
        
        rAction.pushState(pStylePageLayout, false);
        
    } else if (!strcmp (pName, "style:default-style")) {
        ODi_ListenerState* pStyle;
        
        pStyle = m_pStyles->addDefaultStyle(ppAtts, m_rElementStack);
        
        if (pStyle) {
            rAction.pushState(pStyle, false);
        }
        
    } else if (!strcmp (pName, "text:list-style")) {
        
        if (!UT_strcmp("office:automatic-styles",
                      m_rElementStack.getStartTag(0)->getName())) {

            // An automatic list style defined on the styles stream means
            // that it is used on headers/footers.
            // AbiWord doesn't support lists on header/footers, so, I will ignore
            // this style.
        } else {
            ODi_ListenerState* pStyle;
            
            // It's a regular style.
            pStyle = m_pStyles->addList(ppAtts, m_rElementStack);
            rAction.pushState(pStyle, false);
        }
        
    } else if (!strcmp (pName, "text:notes-configuration")) {
        
        ODi_ListenerState* pNotesConfig;

        pNotesConfig = m_pStyles->addNotesConfiguration(ppAtts, m_rElementStack);
        
        rAction.pushState(pNotesConfig, false);
        
    }
    
}

/**
 * Reads the data between the "start" and "end" tags.
 * e.g: <bla>char_data</bla>
 */
void ODi_StylesStream_ListenerState::charData (
                            const XML_Char* pBuffer, int length)
{
}

/**
 * 
 */
void ODi_StylesStream_ListenerState::endElement (const XML_Char* pName,
                                                ODi_ListenerStateAction& rAction)
{
    if (!strcmp (pName, "office:document-styles")) {
        // We're done.
        rAction.popState();
    }
}
