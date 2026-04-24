/* AbiSource
 * 
 * Copyright (C) 2002 Dom Lachowicz <cinamod@hotmail.com>
 * Copyright (C) 2004 Robert Staudinger <robsta@stereolyzer.net>
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
#include "ODe_AbiDocListener.h"

// Internal includes
#include "ODe_AbiDocListenerImpl.h"
#include "ODe_Main_Listener.h"

// Abiword includes
#include <pd_Document.h>
#include <px_ChangeRecord.h>
#include <px_CR_Span.h>
#include <px_CR_Strux.h>
#include <px_CR_Object.h>


/**
 * Constructor
 * 
 * @param deleteWhenPop "true" if the implementation object is to be deleted
 *                      when it pops itself.
 */
ODe_AbiDocListener::ODe_AbiDocListener (PD_Document* pDocument,
                                        ODe_AbiDocListenerImpl* pListenerImpl,
                                        bool deleteWhenPop)
    : PL_Listener (),
      m_pCurrentField(NULL),
      m_apiLastSpan(0),
      m_bInSpan(false),
      m_bInBlock(false),
      m_bInHyperlink(false),
      m_bInSection(false),
      m_iInTable(0),
      m_iInCell(0),
      m_pDocument(pDocument),
      m_pCurrentImpl(pListenerImpl),
      m_deleteCurrentWhenPop(deleteWhenPop)
{
    UT_ASSERT(pListenerImpl != NULL);
}


/**
 * Destructor
 */
ODe_AbiDocListener::~ODe_AbiDocListener() {
    UT_ASSERT(m_implStack.getItemCount() == 0);
    if (m_deleteCurrentWhenPop) {
        DELETEP(m_pCurrentImpl);
    }
}


/**
 * 
 */
bool ODe_AbiDocListener::populate(PL_StruxFmtHandle sfh,
                                 const PX_ChangeRecord * pcr)
{
    switch (pcr->getType()) {
        
    case PX_ChangeRecord::PXT_InsertSpan:
    {
        const PX_ChangeRecord_Span * pcrs =
            static_cast<const PX_ChangeRecord_Span *> (pcr);
            
        if (pcrs->getField()!=m_pCurrentField) {
            _closeField();
        }
        
        PT_AttrPropIndex api = pcr->getIndexAP();
        _openSpan(api);

        PT_BufIndex bi = pcrs->getBufIndex();
        
        UT_UTF8String utf8String (m_pDocument->getPointer(bi),
                                    pcrs->getLength());
                        
        _outputData(m_pDocument->getPointer(bi), pcrs->getLength());
    }
    break;
        
    case PX_ChangeRecord::PXT_InsertObject:
        {
            const PX_ChangeRecord_Object * pcro =
                static_cast<const PX_ChangeRecord_Object *> (pcr);
                
            PT_AttrPropIndex api = pcr->getIndexAP();
            switch (pcro->getObjectType())
            {
            case PTO_Image:
                {
                    _closeSpan();
                    _closeField();
                    _insertInlinedImage(api);
                    return true;
                }
                
            case PTO_Field:
                {
                    _closeSpan();
                    _closeField();
                    _openField(pcro, api);
                    return true;
                }
                
            case PTO_Math:
                {
                    _closeSpan();
                    _closeField();
                    //_openTag("math","/",false,api,pcr->getXID());
                    /*const XML_Char* image_name = getObjectKey(api, static_cast<const XML_Char*>("dataid"));
                    if (image_name)
                    {
                        UT_DEBUGMSG(("resource name #%s# recorded \n",image_name));
                        UT_UTF8String * sPNGname = new UT_UTF8String("snapshot-png-");
                        m_vecSnapNames.addItem(sPNGname);
                        *sPNGname += image_name;
                        UT_DEBUGMSG(("resource name #%s# recorded \n",sPNGname->utf8_str()));
                    }
                    const XML_Char* latex_name = getObjectKey(api, static_cast<const XML_Char*>("latexid"));
                    if(latex_name)
                    {
                        UT_DEBUGMSG(("resource name #%s# recorded \n",latex_name));
                        m_pUsedImages.insert(latex_name);
                    }*/
                    return true;
                }
                
            case PTO_Embed:
                {
                    _closeSpan();
                    _closeField();
                    //_openTag("embed","/",false,api,pcr->getXID());
                    /*const XML_Char* image_name = getObjectKey(api, static_cast<const XML_Char*>("dataid"));
                    if (image_name)
                    {
                        UT_DEBUGMSG(("resource name #%s# recorded \n",image_name));
                        UT_UTF8String * sPNGname = new UT_UTF8String("snapshot-png-");
                        m_vecSnapNames.addItem(sPNGname);
                        *sPNGname += image_name;
                        UT_DEBUGMSG(("resource name #%s# recorded \n",sPNGname->utf8_str()));
                    }*/
                    return true;
                }
                
            case PTO_Bookmark:
                {
                    _closeSpan();
                    _closeField();
                    //_openTag("bookmark", "/",false, api,pcr->getXID(),true);
                    return true;
                }

            case PTO_Hyperlink:
                {
                    _closeSpan();
                    _closeField();
                    const PP_AttrProp* pAP = NULL;
                    m_pDocument->getAttrProp(api,&pAP);
                    const XML_Char* pName;
                    const XML_Char* pValue;
                    bool bFound = false;
                    UT_uint32 k = 0;

                    while(pAP->getNthAttribute(k++, pName, pValue)) {
                        bFound = (0 == UT_XML_strnicmp(pName,"xlink:href",10));
                        if(bFound)
                            break;
                    }

                    if(bFound) {
                        _openHyperlink(api);
                    } else {
                        _closeHyperlink();
                    }
                    
                    return true;
                }


            default:
                UT_ASSERT_NOT_REACHED();
                return false;
            }
        }
        
    case PX_ChangeRecord::PXT_InsertFmtMark:
        // fmt marks are temporary placeholders for props and
        // attributes and should not be saved
        return true;

    default:
      UT_ASSERT_NOT_REACHED();
        return false;
    }

    
    return true;
}


/**
 * 
 */
bool ODe_AbiDocListener::populateStrux(PL_StruxDocHandle sdh,
                                       const PX_ChangeRecord* pcr,
                                       PL_StruxFmtHandle* psfh)
{
    UT_return_val_if_fail(pcr->getType() == PX_ChangeRecord::PXT_InsertStrux, false);
    bool returnVal = true;
    
    const PX_ChangeRecord_Strux * pcrx =
        static_cast<const PX_ChangeRecord_Strux *> (pcr);
        
    *psfh = 0;                          // we don't need it.

    PT_AttrPropIndex api = pcr->getIndexAP();
    //const XML_Char* image_name =
    //    _getObjectKey(api, static_cast<const XML_Char*>(PT_STRUX_IMAGE_DATAID));
        

    switch (pcrx->getStruxType())
    {
    case PTX_Section:
    case PTX_SectionHdrFtr:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _closeSection();
            _openSection(api);
        }
        break;

    case PTX_SectionTable:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _openTable(api);
        }
        break;

    case PTX_SectionCell:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _openCell(api);
        }
        break;

    case PTX_SectionFootnote:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _openFootnote(api);
        }
        break;

    case PTX_SectionEndnote:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _openEndnote(api);
        }
        break;

    case PTX_SectionTOC:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _openTOC(api);
        }
        break;

    case PTX_SectionMarginnote:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            //_openTag("margin","",true,pcr->getIndexAP(),pcr->getXID());
        }
        break;

    case PTX_SectionFrame:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _openFrame(api);
        }
        break;

    case PTX_EndTable:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _closeTable();
        }
        break;

    case PTX_EndCell:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _closeCell();
        }
        break;

    case PTX_EndFootnote:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _closeFootnote();
        }
        break;

    case PTX_EndEndnote:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _closeEndnote();
        }
        break;

    case PTX_EndTOC:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _closeTOC();
        }
        break;

    case PTX_EndMarginnote:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
        }
        break;

    case PTX_EndFrame:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _closeFrame();
        }
        break;

    case PTX_Block:
        {
            _closeSpan();
            _closeField();
            _closeHyperlink();
            _closeBlock();
            _openBlock(api);
        }
        break;

    default:
      UT_ASSERT_NOT_REACHED();
        returnVal = false;
    }

    return returnVal;
}


/**
 * 
 */
bool ODe_AbiDocListener::change(PL_StruxFmtHandle sfh, const PX_ChangeRecord * pcr)
{
    UT_ASSERT_NOT_REACHED();
    return true;
}


/**
 * 
 */
bool ODe_AbiDocListener::insertStrux(PL_StruxFmtHandle sfh,
                            const PX_ChangeRecord * pcr,
                            PL_StruxDocHandle sdh,
                            PL_ListenerId lid,
                            void (* pfnBindHandles)(PL_StruxDocHandle sdhNew,
                                                    PL_ListenerId lid,
                                                    PL_StruxFmtHandle sfhNew))
{
    UT_ASSERT_NOT_REACHED();
    return true;
}


/**
 * 
 */
bool ODe_AbiDocListener::signal(UT_uint32 iSignal)
{
    UT_ASSERT_NOT_REACHED();
    return true;
}


/**
 * 
 */
void ODe_AbiDocListener::finished() {
    _closeSpan();
    _closeHyperlink();
    _closeBlock();
    _closeField();
    
    _closeCell();
    _closeTable();
    
    _closeSection();
}


/**
 * 
 */
void ODe_AbiDocListener::_openSpan(PT_AttrPropIndex api) {
    const PP_AttrProp* pAP;
    bool ok;
    
    if (m_bInSpan)
    {
        if (m_apiLastSpan == api)
            return;
        _closeSpan();
    }

    if (!api)               // don't write tag for empty A/P
        return;

    m_bInSpan = true;
    m_apiLastSpan = api;
    
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_pCurrentImpl->openSpan(pAP);
    return;
}


/**
 * 
 */
void ODe_AbiDocListener::_closeSpan(void) {
    if (!m_bInSpan)
        return;

    m_bInSpan = false;
    
    m_pCurrentImpl->closeSpan();
    return;
}


/**
 * 
 */
void ODe_AbiDocListener::_openBlock(PT_AttrPropIndex api) {
    const PP_AttrProp* pAP;
    bool ok;
    
    m_bInBlock = true;
    
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }

    m_listenerImplAction.reset();    
    m_pCurrentImpl->openBlock(pAP, m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_openBlock(api);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_closeBlock() {
    if (m_bInBlock) {
        m_bInBlock = false;
        m_pCurrentImpl->closeBlock();
    }
}


/**
 *
 */
void ODe_AbiDocListener::_openSection(PT_AttrPropIndex api, bool recursiveCall) {
    const PP_AttrProp* pAP;
    bool ok;
    
    if (!recursiveCall) {
        UT_ASSERT(!m_bInSection);
        
        m_bInSection = true;
    }
    
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->openSection(pAP, m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_openSection(api, true);
        }
    }

}


/**
 * 
 */
void ODe_AbiDocListener::_closeSection(bool recursiveCall) {
    
    if (!recursiveCall) {    
        if (!m_bInSection)
            return;
    
        m_bInSection = false;
    }
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->closeSection(m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_closeSection(true);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_openField(const PX_ChangeRecord_Object* pcro,
                                    PT_AttrPropIndex api) {
    const PP_AttrProp* pAP;
    bool ok;
                                        
    m_pCurrentField = pcro->getField();
    UT_ASSERT_HARMLESS(m_pCurrentField);
    
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_pCurrentImpl->openField(pAP);
}


/**
 * 
 */
void ODe_AbiDocListener::_closeField(void) {
    if (!m_pCurrentField)
        return;
    _closeSpan();

    m_pCurrentField = NULL;
    
    m_pCurrentImpl->closeField();
}


/**
 * 
 */
void ODe_AbiDocListener::_openFootnote(PT_AttrPropIndex api) {
    const PP_AttrProp* pAP;
    bool ok;
                                        
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->openFootnote(pAP, m_listenerImplAction);
    
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_openFootnote(api);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_closeFootnote() {
    m_bInBlock = true;
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->closeFootnote(m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_closeFootnote();
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_openEndnote(PT_AttrPropIndex api) {
    const PP_AttrProp* pAP;
    bool ok;
                                        
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }

    m_listenerImplAction.reset();    
    m_pCurrentImpl->openEndnote(pAP, m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_openEndnote(api);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_closeEndnote() {
    m_bInBlock = true;
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->closeEndnote(m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_closeEndnote();
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_openTable(PT_AttrPropIndex api, bool recursiveCall) {
    const PP_AttrProp* pAP;
    bool ok;


    if (!recursiveCall) {
        m_iInTable++;
    }
    
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->openTable(pAP, m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_openTable(api, true);
        }
    }
    
}


/**
 * 
 */
void ODe_AbiDocListener::_closeTable(bool recursiveCall) {
    
    if (!recursiveCall) {
        if (m_iInTable == 0)
            return;
    
        m_iInTable--;
    }
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->closeTable(m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_closeTable(true);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_openCell(PT_AttrPropIndex api, bool recursiveCall) {
    const PP_AttrProp* pAP;
    bool ok;
    
    if (!recursiveCall) {
        m_iInCell++;
    }
    
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_listenerImplAction.reset();
    m_pCurrentImpl->openCell(pAP, m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_openCell(api, true);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_closeCell(bool recursiveCall) {
    
    if (!recursiveCall) {
        if (m_iInCell == 0)
            return;
    
        m_iInCell--;
    }

    m_listenerImplAction.reset();
    m_pCurrentImpl->closeCell(m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_closeCell(true);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_openFrame(PT_AttrPropIndex api) {
    const PP_AttrProp* pAP;
    bool ok;
                                        
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }

    m_listenerImplAction.reset();
    m_pCurrentImpl->openFrame(pAP, m_listenerImplAction);
    

    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_openFrame(api);
        }
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_closeFrame() {
    m_listenerImplAction.reset();
    m_pCurrentImpl->closeFrame(m_listenerImplAction);
    
    if (m_listenerImplAction.getAction() != m_listenerImplAction.ACTION_NONE) {
        ODe_AbiDocListenerImpl* pPreviousImpl;
        
        pPreviousImpl = m_pCurrentImpl;
        _handleListenerImplAction();
        
        if (m_pCurrentImpl != NULL && pPreviousImpl != m_pCurrentImpl) {
            // The implementation has changed.
            this->_closeFrame();
        }
    }    
}


/**
 * 
 */
void ODe_AbiDocListener::_openTOC(PT_AttrPropIndex api) {
    const PP_AttrProp* pAP;
    bool ok;
                                        
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_pCurrentImpl->openTOC(pAP);
}


/**
 * 
 */
void ODe_AbiDocListener::_closeTOC() {
    m_pCurrentImpl->closeTOC();
}


/**
 * 
 */
void ODe_AbiDocListener::_openHyperlink(PT_AttrPropIndex api) {
    m_bInHyperlink = true;
    
    const PP_AttrProp* pAP;
    bool ok;
                                        
    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }
    
    m_pCurrentImpl->openHyperlink(pAP);
}


/**
 * 
 */
void ODe_AbiDocListener::_closeHyperlink() {
    if (!m_bInHyperlink)
        return;
        
    _closeSpan();

    m_bInHyperlink = false;
    m_pCurrentImpl->closeHyperlink();
}


/**
 * 
 */
const XML_Char* ODe_AbiDocListener::_getObjectKey(const PT_AttrPropIndex& api,
                                                  const XML_Char* key) {
    const PP_AttrProp * pAP = NULL;
    bool bHaveProp = m_pDocument->getAttrProp(api,&pAP);
    if (bHaveProp && pAP)
    {
        const XML_Char* value;
        if (pAP->getAttribute(key, value))
            return value;
    }

    return 0;
}


/**
 * 
 */
void ODe_AbiDocListener::_insertInlinedImage(PT_AttrPropIndex api) {
    const XML_Char* pImageName;
    const PP_AttrProp* pAP;
    bool ok;

    ok = m_pDocument->getAttrProp (api, &pAP);
    if (!ok) {
        pAP = NULL;        
    }

    pImageName = 
        _getObjectKey(api, static_cast<const XML_Char*>("dataid"));

    m_pCurrentImpl->insertInlinedImage(pImageName, pAP);
}


/**
 * 
 */
void ODe_AbiDocListener::_outputData(const UT_UCSChar* pData, UT_uint32 length) {
    UT_UTF8String sBuf;
    const UT_UCSChar* p;

    UT_ASSERT(sizeof(UT_Byte) == sizeof(char));

    for (p=pData; (p<pData+length); /**/)
    {
        switch (*p)
        {
        case '<':
            sBuf += "&lt;";
            p++;
            break;

        case '>':
            sBuf += "&gt;";
            p++;
            break;

        case '&':
            sBuf += "&amp;";
            p++;
            break;

        case UCS_LF:               // LF -- representing a Forced-Line-Break
            m_pCurrentImpl->insertText(sBuf);
            m_pCurrentImpl->insertLineBreak();
            sBuf.clear();
            p++;
            break;

        case UCS_VTAB:             // VTAB -- representing a Forced-Column-Break
            m_pCurrentImpl->insertText(sBuf);
            m_pCurrentImpl->insertColumnBreak();
            sBuf.clear();
            p++;
            break;

        case UCS_TAB:
            m_pCurrentImpl->insertTabChar();
            p++;
            break;

        case UCS_FF:               // FF -- representing a Forced-Page-Break
            m_pCurrentImpl->insertText(sBuf);
            m_pCurrentImpl->insertPageBreak();
            sBuf.clear();
            p++;
            break;

        default:
            if (*p < 0x20)         // Silently eat these characters.
                p++;
            else
                {
                    sBuf.appendUCS4 (p, 1);
                    p++;
                }
        }
    }

    if (!sBuf.empty()) {
        m_pCurrentImpl->insertText(sBuf);
    }
}


/**
 * 
 */
void ODe_AbiDocListener::_handleListenerImplAction() {
    switch (m_listenerImplAction.getAction()) {
        case ODe_ListenerAction::ACTION_PUSH:
            m_implStack.push_back(
                ODe_AbiDocListener::StackCell(m_pCurrentImpl, m_deleteCurrentWhenPop));
                
            m_pCurrentImpl = m_listenerImplAction.getListenerImpl();
            m_deleteCurrentWhenPop = m_listenerImplAction.deleteWhenPop();

            UT_ASSERT(m_pCurrentImpl);
            break;
        
        case ODe_ListenerAction::ACTION_POP:
            if (m_deleteCurrentWhenPop) {
                DELETEP(m_pCurrentImpl);
            } else {
                m_pCurrentImpl = NULL;
            }

            if (m_implStack.getItemCount() > 0) {
                StackCell stackCell;
                stackCell = m_implStack.getLastItem();            
                m_pCurrentImpl = stackCell.m_pListenerImpl;
                m_deleteCurrentWhenPop = stackCell.m_deleteWhenPop;
                
                m_implStack.pop_back();
            }
            break;
    }
}
