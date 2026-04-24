/* -*- mode: C++; tab-width: 4; c-basic-offset: 4; -*- */

/* AbiWord
 * Copyright (C) 2003 AbiSource, Inc.
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

#ifndef ABI_PLUGIN_BUILTIN_H
#define ABI_PLUGIN_BUILTIN_H

#ifdef ABI_PLUGIN_BUILTIN

/* This function defined below; before including this header, you should
 * #define ABIPGN_BUILTIN_* for any plugins you are linking against.
 */
extern void abipgn_builtin_register ();

#include "xap_ModuleManager.h"

// #undef ABIPGN_BUILTIN_ABICOMMAND
// #undef ABIPGN_BUILTIN_ABIGIMP
// #undef ABIPGN_BUILTIN_AIKSAURUS
// #undef ABIPGN_BUILTIN_BABELFISH
// #undef ABIPGN_BUILTIN_FREETRANSLATION
// #undef ABIPGN_BUILTIN_GDA
// #undef ABIPGN_BUILTIN_GDICT
// #undef ABIPGN_BUILTIN_GOOGLE
// #undef ABIPGN_BUILTIN_GYPSYTHON
// #undef ABIPGN_BUILTIN_OTS
// #undef ABIPGN_BUILTIN_URLDICT
// #undef ABIPGN_BUILTIN_WIKIPEDIA
// #undef ABIPGN_BUILTIN_APPLIX
// #undef ABIPGN_BUILTIN_BZ2ABW
// #undef ABIPGN_BUILTIN_CLARISWORKS
// #undef ABIPGN_BUILTIN_COQUILLE
// #undef ABIPGN_BUILTIN_DOCBOOK
// #undef ABIPGN_BUILTIN_EML
// #undef ABIPGN_BUILTIN_ABIGDKPIXBUF
// #undef ABIPGN_BUILTIN_BMP
// #undef ABIPGN_BUILTIN_JPEG
// #undef ABIPGN_BUILTIN_LIBRSVG
// #undef ABIPGN_BUILTIN_MAGICK
// #undef ABIPGN_BUILTIN_WMF
// #undef ABIPGN_BUILTIN_HANCOM
// #undef ABIPGN_BUILTIN_HRTEXT
// #undef ABIPGN_BUILTIN_ISCII_TEXT
// #undef ABIPGN_BUILTIN_KWORD
// #undef ABIPGN_BUILTIN_LATEX
// #undef ABIPGN_BUILTIN_MIF
// #undef ABIPGN_BUILTIN_MSWRITE
// #undef ABIPGN_BUILTIN_NROFF
// #undef ABIPGN_BUILTIN_OPENWRITER
// #undef ABIPGN_BUILTIN_PDB
// #undef ABIPGN_BUILTIN_PSION
// #undef ABIPGN_BUILTIN_SDW
// #undef ABIPGN_BUILTIN_T602
// #undef ABIPGN_BUILTIN_WML
// #undef ABIPGN_BUILTIN_WORDPERFECT
// #undef ABIPGN_BUILTIN_XHTML
// #undef ABIPGN_BUILTIN_XSL_FO
// #undef ABIPGN_BUILTIN_SHELL

ABI_FAR_CALL int abipgn_abicommand_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_abicommand_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_abicommand_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_abigimp_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_abigimp_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_abigimp_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_aiksaurus_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_aiksaurus_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_aiksaurus_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_babelfish_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_babelfish_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_babelfish_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_freetranslation_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_freetranslation_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_freetranslation_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_gda_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_gda_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_gda_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_gdict_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_gdict_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_gdict_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_google_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_google_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_google_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_gypsython_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_gypsython_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_gypsython_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_ots_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_ots_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_ots_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_urldict_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_urldict_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_urldict_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_wikipedia_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wikipedia_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wikipedia_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_applix_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_applix_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_applix_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_bz2abw_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_bz2abw_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_bz2abw_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_clarisworks_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_clarisworks_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_clarisworks_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_coquille_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_coquille_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_coquille_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_docbook_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_docbook_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_docbook_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_eml_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_eml_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_eml_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_AbiGdkPixbuf_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_AbiGdkPixbuf_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_AbiGdkPixbuf_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_bmp_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_bmp_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_bmp_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_jpeg_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_jpeg_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_jpeg_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_librsvg_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_librsvg_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_librsvg_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_magick_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_magick_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_magick_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_wmf_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wmf_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wmf_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_hancom_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_hancom_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_hancom_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_hrtext_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_hrtext_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_hrtext_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_iscii_text_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_iscii_text_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_iscii_text_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_kword_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_kword_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_kword_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_latex_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_latex_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_latex_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_mif_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_mif_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_mif_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_mswrite_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_mswrite_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_mswrite_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_nroff_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_nroff_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_nroff_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_OpenWriter_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_OpenWriter_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_OpenWriter_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_pdb_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_pdb_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_pdb_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_psion_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_psion_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_psion_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_sdw_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_sdw_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_sdw_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_t602_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_t602_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_t602_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_wml_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wml_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wml_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_wordperfect_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wordperfect_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_wordperfect_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_xhtml_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_xhtml_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_xhtml_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_xsl_fo_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_xsl_fo_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_xsl_fo_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

ABI_FAR_CALL int abipgn_shell_register (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_shell_unregister (XAP_ModuleInfo * mi);
ABI_FAR_CALL int abipgn_shell_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release);

void abipgn_builtin_register ()
{
	XAP_ModuleManager & MM = XAP_ModuleManager::instance ();

#ifdef ABIPGN_BUILTIN_ABICOMMAND
	MM.loadPreloaded (abipgn_abicommand_register, abipgn_abicommand_unregister, abipgn_abicommand_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_ABIGIMP
	MM.loadPreloaded (abipgn_abigimp_register, abipgn_abigimp_unregister, abipgn_abigimp_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_AIKSAURUS
	MM.loadPreloaded (abipgn_aiksaurus_register, abipgn_aiksaurus_unregister, abipgn_aiksaurus_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_BABELFISH
	MM.loadPreloaded (abipgn_babelfish_register, abipgn_babelfish_unregister, abipgn_babelfish_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_FREETRANSLATION
	MM.loadPreloaded (abipgn_freetranslation_register, abipgn_freetranslation_unregister, abipgn_freetranslation_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_GDA
	MM.loadPreloaded (abipgn_gda_register, abipgn_gda_unregister, abipgn_gda_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_GDICT
	MM.loadPreloaded (abipgn_gdict_register, abipgn_gdict_unregister, abipgn_gdict_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_GOOGLE
	MM.loadPreloaded (abipgn_google_register, abipgn_google_unregister, abipgn_google_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_GYPSYTHON
	MM.loadPreloaded (abipgn_gypsython_register, abipgn_gypsython_unregister, abipgn_gypsython_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_OTS
	MM.loadPreloaded (abipgn_ots_register, abipgn_ots_unregister, abipgn_ots_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_URLDICT
	MM.loadPreloaded (abipgn_urldict_register, abipgn_urldict_unregister, abipgn_urldict_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_WIKIPEDIA
	MM.loadPreloaded (abipgn_wikipedia_register, abipgn_wikipedia_unregister, abipgn_wikipedia_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_APPLIX
	MM.loadPreloaded (abipgn_applix_register, abipgn_applix_unregister, abipgn_applix_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_BZ2ABW
	MM.loadPreloaded (abipgn_bz2abw_register, abipgn_bz2abw_unregister, abipgn_bz2abw_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_CLARISWORKS
	MM.loadPreloaded (abipgn_clarisworks_register, abipgn_clarisworks_unregister, abipgn_clarisworks_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_COQUILLE
	MM.loadPreloaded (abipgn_coquille_register, abipgn_coquille_unregister, abipgn_coquille_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_DOCBOOK
	MM.loadPreloaded (abipgn_docbook_register, abipgn_docbook_unregister, abipgn_docbook_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_EML
	MM.loadPreloaded (abipgn_eml_register, abipgn_eml_unregister, abipgn_eml_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_ABIGDKPIXBUF
	MM.loadPreloaded (abipgn_AbiGdkPixbuf_register, abipgn_AbiGdkPixbuf_unregister, abipgn_AbiGdkPixbuf_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_BMP
	MM.loadPreloaded (abipgn_bmp_register, abipgn_bmp_unregister, abipgn_bmp_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_JPEG
	MM.loadPreloaded (abipgn_jpeg_register, abipgn_jpeg_unregister, abipgn_jpeg_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_LIBRSVG
	MM.loadPreloaded (abipgn_librsvg_register, abipgn_librsvg_unregister, abipgn_librsvg_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_MAGICK
	MM.loadPreloaded (abipgn_magick_register, abipgn_magick_unregister, abipgn_magick_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_WMF
	MM.loadPreloaded (abipgn_wmf_register, abipgn_wmf_unregister, abipgn_wmf_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_HANCOM
	MM.loadPreloaded (abipgn_hancom_register, abipgn_hancom_unregister, abipgn_hancom_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_HRTEXT
	MM.loadPreloaded (abipgn_hrtext_register, abipgn_hrtext_unregister, abipgn_hrtext_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_ISCII_TEXT
	MM.loadPreloaded (abipgn_iscii_text_register, abipgn_iscii_text_unregister, abipgn_iscii_text_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_KWORD
	MM.loadPreloaded (abipgn_kword_register, abipgn_kword_unregister, abipgn_kword_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_LATEX
	MM.loadPreloaded (abipgn_latex_register, abipgn_latex_unregister, abipgn_latex_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_MIF
	MM.loadPreloaded (abipgn_mif_register, abipgn_mif_unregister, abipgn_mif_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_MSWRITE
	MM.loadPreloaded (abipgn_mswrite_register, abipgn_mswrite_unregister, abipgn_mswrite_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_NROFF
	MM.loadPreloaded (abipgn_nroff_register, abipgn_nroff_unregister, abipgn_nroff_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_OPENWRITER
	MM.loadPreloaded (abipgn_OpenWriter_register, abipgn_OpenWriter_unregister, abipgn_OpenWriter_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_PDB
	MM.loadPreloaded (abipgn_pdb_register, abipgn_pdb_unregister, abipgn_pdb_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_PSION
	MM.loadPreloaded (abipgn_psion_register, abipgn_psion_unregister, abipgn_psion_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_SDW
	MM.loadPreloaded (abipgn_sdw_register, abipgn_sdw_unregister, abipgn_sdw_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_T602
	MM.loadPreloaded (abipgn_t602_register, abipgn_t602_unregister, abipgn_t602_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_WML
	MM.loadPreloaded (abipgn_wml_register, abipgn_wml_unregister, abipgn_wml_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_WORDPERFECT
	MM.loadPreloaded (abipgn_wordperfect_register, abipgn_wordperfect_unregister, abipgn_wordperfect_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_XHTML
	MM.loadPreloaded (abipgn_xhtml_register, abipgn_xhtml_unregister, abipgn_xhtml_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_XSL_FO
	MM.loadPreloaded (abipgn_xsl_fo_register, abipgn_xsl_fo_unregister, abipgn_xsl_fo_supports_version);
#endif
#ifdef ABIPGN_BUILTIN_SHELL
	MM.loadPreloaded (abipgn_shell_register, abipgn_shell_unregister, abipgn_shell_supports_version);
#endif
}

#endif /* ABI_PLUGIN_BUILTIN */

#endif /* ! ABI_PLUGIN_BUILTIN_H */
