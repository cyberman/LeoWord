/* AbiSource
 * 
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

#ifndef _ODI_OFFICE_STYLES_H_
#define _ODI_OFFICE_STYLES_H_

// Internal includes
#include "ODi_Style_Style_Family.h"

// AbiWord includes
#include <ut_hash.h>
#include <ut_vector.h>
#include <ut_IntStrMap.h>

// Internal classes
class ODi_FontFaceDecls;
class ODi_Style_Style;
class ODi_Style_PageLayout;
class ODi_Style_MasterPage;
class ODi_Style_List;
class ODi_NotesConfiguration;
class ODi_ElementStack;

// AbiWord classes
class PD_Document;



/**
 * This class holds all the styles defined by the OpenDocument stream, both the
 * common (defined inside <office:styles>), automatic (definded
 * inside <office:automatic-styles>) and master page ones (defined inside
 * <office:master-styles>).
 * 
 * It includes the page layouts (<style:page-layout>).
 * 
 * Usage:
 * 1 - Add (and parse) all styles
 * 2 - Call addedAllStyles
 */
class ODi_Office_Styles {
public:

    ODi_Office_Styles() {}
    ~ODi_Office_Styles();

    ODi_Style_Style* addStyle(const XML_Char** ppAtts,
    						 ODi_ElementStack& rElementStack);

    ODi_Style_PageLayout* addPageLayout(const XML_Char** ppAtts,
    								   ODi_ElementStack& rElementStack);

    ODi_Style_MasterPage* addMasterPage(const XML_Char** ppAtts,
                                       PD_Document* pDocument,
                                       ODi_ElementStack& rElementStack);

    ODi_Style_Style* addDefaultStyle(const XML_Char** ppAtts,
    								ODi_ElementStack& rElementStack);
    
    ODi_Style_List* addList(const XML_Char** ppAtts,
    					   ODi_ElementStack& rElementStack);
                           
    ODi_NotesConfiguration* addNotesConfiguration(const XML_Char** ppAtts,
                                               ODi_ElementStack& rElementStack);

    /**
     * Will do some post-processing and then define all AbiWord styles.
     */
    void addedAllStyles(PD_Document* pDocument,
                        ODi_FontFaceDecls& rFontFaceDecls) {
        _fixStyles();
        _linkStyles();
        _buildAbiPropsAttrString(rFontFaceDecls);
        _defineAbiStyles(pDocument);
    }
    
    const ODi_Style_Style* getTextStyle(const XML_Char* pStyleName,
                                       bool bOnContentStream);
    
    const ODi_Style_Style* getParagraphStyle(const XML_Char* pStyleName,
                                            bool bOnContentStream);
    
    const ODi_Style_Style* getSectionStyle(const XML_Char* pStyleName,
                                          bool bOnContentStream);
                                          
    const ODi_Style_Style* getGraphicStyle(const XML_Char* pStyleName,
                                          bool bOnContentStream);
                                          
    const ODi_Style_Style* getTableStyle(const XML_Char* pStyleName,
                                        bool bOnContentStream);
                                        
    const ODi_Style_Style* getTableColumnStyle(const XML_Char* pStyleName,
                                              bool bOnContentStream);
                                              
    const ODi_Style_Style* getTableRowStyle(const XML_Char* pStyleName,
                                           bool bOnContentStream);
                                           
    const ODi_Style_Style* getTableCellStyle(const XML_Char* pStyleName,
                                            bool bOnContentStream);
    
    const ODi_Style_Style* getDefaultParagraphStyle() const {
        return m_paragraphStyleStyles.getDefaultStyle();
    }
    
    const ODi_Style_PageLayout* getPageLayoutStyle(
                                             const XML_Char* pStyleName) const {
        return m_pageLayoutStyles.pick(pStyleName);
    }
    
    const ODi_Style_MasterPage* getMasterPageStyle(
                                             const XML_Char* pStyleName) const {
        return m_masterPageStyles.pick(pStyleName);
    }
    
    ODi_Style_List* getList(const XML_Char* pStyleName) {
        return m_listStyles.pick(pStyleName);
    }
    
    const ODi_NotesConfiguration* getNotesConfiguration(
                                               const XML_Char* pNoteClass) const {
        return m_notesConfigurations.pick(pNoteClass);
    }
    
private:

    void _fixStyles();    
    void _linkStyles();
    void _buildAbiPropsAttrString(ODi_FontFaceDecls& rFontFaceDecls);
    void _defineAbiStyles(PD_Document* pDocument) const;
    
    void _linkMasterStyles();
    void _linkListStyles();


    ////
    // Styles (<style:style>) are separated by family.

    // <style:style style:family="text"> 
    ODi_Style_Style_Family m_textStyleStyles;    
    
    // <style:style style:family="paragraph"> 
    ODi_Style_Style_Family m_paragraphStyleStyles;

    // <style:style style:family="section"> 
    ODi_Style_Style_Family m_sectionStyleStyles;

    // <style:style style:family="graphic"> 
    ODi_Style_Style_Family m_graphicStyleStyles;

    // <style:style style:family="table"> 
    ODi_Style_Style_Family m_tableStyleStyles;

    // <style:style style:family="table-column"> 
    ODi_Style_Style_Family m_tableColumnStyleStyles;

    // <style:style style:family="table-row"> 
    ODi_Style_Style_Family m_tableRowStyleStyles;

    // <style:style style:family="table-cell"> 
    ODi_Style_Style_Family m_tableCellStyleStyles;



    // <text:list-style> 
    UT_GenericStringMap<ODi_Style_List*> m_listStyles;
    
    // <style:page-layout>
    UT_GenericStringMap<ODi_Style_PageLayout*> m_pageLayoutStyles;
    
    // <style:master-page>
    UT_GenericStringMap<ODi_Style_MasterPage*> m_masterPageStyles;
    
    // <text:notes-configuration>
    UT_GenericStringMap<ODi_NotesConfiguration*> m_notesConfigurations;
};

#endif //_ODI_OFFICE_STYLES_H_
