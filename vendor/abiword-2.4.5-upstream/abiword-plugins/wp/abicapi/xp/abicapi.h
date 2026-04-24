/* AbiSource Application Framework
 * Copyright (C) 2003 Dom Lachowicz
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

#ifndef ABICAPI_H
#define ABICAPI_H

#include <sys/types.h>

#ifdef __cplusplus
#define ABICAPI_C_CALL extern "C"

extern "C" {
#else
#define ABICAPI_C_CALL
#endif /* C++ */

  typedef struct str_AbiApp   AbiApp;
  typedef struct str_AbiFrame AbiFrame;
  typedef struct str_AbiView  AbiView;
  typedef struct str_AbiDoc   AbiDoc;
  
  typedef int AbiFile_t;
  typedef int AbiCursor_t;
  typedef int AbiError_t;
  
#ifdef WIN32
  #ifndef ABI_DLL
    #define ABICAPI_API(X) ABICAPI_C_CALL __declspec(dllexport) X
  #else 
    #define ABICAPI_API(X) ABICAPI_C_CALL __declspec(dllimport) X
  #endif
#else
  #define ABICAPI_API(X) ABICAPI_C_CALL X
#endif

#define ABI_CONST_RETURN const
  
  ABICAPI_API(AbiApp *)    abi_app_get_current (void);
  ABICAPI_API(AbiError_t)  abi_app_init (int argc, char ** argv);
  ABICAPI_API(void)        abi_app_shutdown (void);
  ABICAPI_API(AbiFrame *)  abi_app_new_frame (AbiApp * pApp);
  ABICAPI_API(AbiFrame *)  abi_app_get_frame (AbiApp * pApp, size_t which);
  ABICAPI_API(ssize_t)     abi_app_get_frame_count (AbiApp * pApp);
  ABICAPI_API(ssize_t)     abi_app_find_frame (AbiApp * pApp, const char * szFilename);
  ABICAPI_API(ssize_t)     abi_app_find_existing_frame (AbiApp * pApp, AbiFrame * pFrame);
  
  ABICAPI_API(void)        abi_frame_free (AbiFrame * pFrame);
  ABICAPI_API(AbiFrame *)  abi_frame_clone (AbiFrame * pFrame);
  ABICAPI_API(AbiError_t)  abi_frame_load_document (AbiFrame * pFrame, const char * szFile, AbiFile_t ieft, int create_new);
  ABICAPI_API(AbiError_t)  abi_frame_import_document (AbiFrame * pFrame, const char * szFile, AbiFile_t ieft, int mark_clean);
  ABICAPI_API(int)         abi_frame_close (AbiFrame * pFrame);
  ABICAPI_API(int)         abi_frame_raise (AbiFrame * pFrame);
  ABICAPI_API(int)         abi_frame_show (AbiFrame * pFrame);
  ABICAPI_API(int)         abi_frame_update_title (AbiFrame * pFrame);
  ABICAPI_API(void)        abi_frame_set_cursor (AbiFrame * pFrame, AbiCursor_t type);
  ABICAPI_API(int)         abi_frame_open_url (AbiFrame * pFrame, const char * szUrl);
  ABICAPI_API(int)         abi_frame_open_help_url (AbiFrame * pFrame, const char * szUrl);
  
  ABICAPI_API(ABI_CONST_RETURN char *) abi_frame_get_filename (const AbiFrame * pFrame);  
  ABICAPI_API(ABI_CONST_RETURN char *) abi_frame_get_title (const AbiFrame * pFrame, size_t len);  
  ABICAPI_API(ABI_CONST_RETURN char *) abi_frame_get_undecorated_title (const AbiFrame * pFrame);
  
  ABICAPI_API(AbiFile_t) abi_imp_type_for_contents (const char * buf, size_t nbytes);
  ABICAPI_API(AbiFile_t) abi_imp_type_for_suffix (const char * suffix);
  ABICAPI_API(AbiFile_t) abi_imp_type_for_suffixes (const char * suffixes);
  ABICAPI_API(AbiFile_t) abi_imp_type_for_description (const char * desc);
  
  ABICAPI_API(ABI_CONST_RETURN char *) abi_imp_suffixes_for_type (AbiFile_t type);
  ABICAPI_API(ABI_CONST_RETURN char *) abi_imp_description_for_type (AbiFile_t type);
  ABICAPI_API(size_t) abi_imp_count_importers (void);

  ABICAPI_API(AbiFile_t) abi_exp_type_for_suffix (const char * suffix);
  ABICAPI_API(AbiFile_t) abi_exp_type_for_suffixes (const char * suffixes);
  ABICAPI_API(AbiFile_t) abi_exp_type_for_description (const char * desc);
  
  ABICAPI_API(ABI_CONST_RETURN char *) abi_exp_suffixes_for_type (AbiFile_t type);
  ABICAPI_API(ABI_CONST_RETURN char *) abi_exp_description_for_type (AbiFile_t type);
  ABICAPI_API(size_t) abi_exp_count_exporters (void);

#ifdef __cplusplus
}
#endif /* C++ */

#endif /* ABICAPI_H */
