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

#include "abicapi.h"
#include "abicapi_private.h"
#include "ut_assert.h"

static int
abi_doc_assert (const AbiDoc * pDoc)
{
  if (!pDoc)
    return 0;
  if (!pDoc->pDoc)
    return 0;

  return 1;
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_doc_get_filename (const AbiDoc * pDoc)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), NULL);
  return (ABI_CONST_RETURN char *) pDoc->pDoc->getFilename ();
}

ABICAPI_API(AbiFile_t)
abi_doc_get_last_saved_type (AbiDoc * pDoc)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), -1);
  return (AbiFile_t) pDoc->pDoc->getLastSavedAsType ();
}

ABICAPI_API(AbiError_t)
abi_doc_load_file_ex (AbiDoc * pDoc, const char * szFileName, AbiFile_t type,
		      const char * props)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), (AbiError_t)UT_ERROR);
  return (AbiError_t) pDoc->pDoc->readFromFile (szFileName, (int)type, props);
}

ABICAPI_API(AbiError_t)
abi_doc_load_file (AbiDoc * pDoc, const char * szFileName, AbiFile_t type)
{
  return abi_doc_load_file_ex (pDoc, szFileName, type, NULL);
}

ABICAPI_API(AbiError_t)
abi_doc_import_file_ex (AbiDoc * pDoc, const char * szFileName, AbiFile_t type,
			int markClean, int importStylesFirst, const char * props)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), (AbiError_t)UT_ERROR);
  return (AbiError_t) pDoc->pDoc->importFile (szFileName, type, markClean,
					      importStylesFirst, props);
}

ABICAPI_API(AbiError_t)
abi_doc_import_file (AbiDoc * pDoc, const char * szFileName, AbiFile_t type)
{
  return abi_doc_import_file_ex (pDoc, szFileName, type, 0, 1, NULL);
}

ABICAPI_API(AbiError_t)
abi_doc_new_doc (AbiDoc * pDoc)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), (AbiError_t)UT_ERROR);
  return (AbiError_t) pDoc->pDoc->newDocument ();
}

ABICAPI_API(int)
abi_doc_is_dirty (const AbiDoc * pDoc)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), 0);
  return (int) pDoc->pDoc->isDirty ();
}

ABICAPI_API(int)
abi_doc_can_undo (const AbiDoc * pDoc)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), 0);
  return (int) pDoc->pDoc->canDo (true);
}

ABICAPI_API(int)
abi_doc_can_redo (const AbiDoc * pDoc)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), 0);
  return (int) pDoc->pDoc->canDo (false);
}

ABICAPI_API(int)
abi_doc_undo_cmd (AbiDoc * pDoc, size_t nb_undo)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), 0);
  return (int) pDoc->pDoc->undoCmd (nb_undo);
}

ABICAPI_API(int)
abi_doc_redo_cmd (AbiDoc * pDoc, size_t nb_redo)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), 0);
  return (int) pDoc->pDoc->redoCmd (nb_redo);
}

ABICAPI_API(AbiError_t)
abi_doc_save (AbiDoc * pDoc)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), (AbiError_t)UT_ERROR);
  return (AbiError_t) pDoc->pDoc->save ();
}

ABICAPI_API(AbiError_t)
abi_doc_save_as_ex (AbiDoc * pDoc, const char * szFileName, 
		    AbiFile_t type, const char * props)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), (AbiError_t)UT_ERROR);
  UT_return_val_if_fail (szFileName, (AbiError_t)UT_ERROR);
  return (AbiError_t) pDoc->pDoc->saveAs (szFileName, type, props);
}

ABICAPI_API(AbiError_t)
abi_doc_save_as (AbiDoc * pDoc, const char * szFileName, AbiFile_t type)
{
  return abi_doc_save_as_ex (pDoc, szFileName, type, NULL);
}

ABICAPI_API(AbiError_t)
abi_doc_export_ex (AbiDoc * pDoc, const char * szFileName, 
		    AbiFile_t type, const char * props)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), (AbiError_t)UT_ERROR);
  UT_return_val_if_fail (szFileName, (AbiError_t)UT_ERROR);
  return (AbiError_t) pDoc->pDoc->saveAs (szFileName, type, true, props);
}

ABICAPI_API(AbiError_t)
abi_doc_export (AbiDoc * pDoc, const char * szFileName, AbiFile_t type)
{
  return abi_doc_export_ex (pDoc, szFileName, type, NULL);
}

ABICAPI_API(void)
abi_doc_set_meta_data (AbiDoc * pDoc, const char * key, const char * val)
{
  UT_return_if_fail (abi_doc_assert (pDoc));
  UT_return_if_fail (key);
  UT_return_if_fail (val);

  pDoc->pDoc->setMetaDataProp (key, val);
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_doc_get_meta_data (AbiDoc * pDoc, const char * key)
{
  UT_return_val_if_fail (abi_doc_assert (pDoc), NULL);
  UT_return_val_if_fail (key, NULL);

  if (pDoc->pDoc->getMetaDataProp (key, pDoc->metaDataVal))
    return pDoc->metaDataVal.utf8_str();
  return NULL;
}

/****************************************************/
/****************************************************/

ABICAPI_API(void)
abi_doc_begin_atomic_glob (AbiDoc * pDoc)
{
  UT_return_if_fail (abi_doc_assert (pDoc));
  pDoc->pDoc->beginUserAtomicGlob ();
}

ABICAPI_API(void)
abi_doc_end_atomic_glob (AbiDoc * pDoc)
{
  UT_return_if_fail (abi_doc_assert (pDoc));
  pDoc->pDoc->endUserAtomicGlob ();
}
