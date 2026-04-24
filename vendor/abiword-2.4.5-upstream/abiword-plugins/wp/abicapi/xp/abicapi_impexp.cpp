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

#include "ie_imp.h"
#include "ie_exp.h"

ABICAPI_API(AbiFile_t)
abi_imp_type_for_contents (const char * buf, size_t nbytes)
{
  UT_return_val_if_fail (buf || nbytes, (AbiFile_t)-1);
  return (AbiFile_t)IE_Imp::fileTypeForContents (buf, (UT_uint32)nbytes);
}

ABICAPI_API(AbiFile_t)
abi_imp_type_for_suffix (const char * suffix)
{
  UT_return_val_if_fail (suffix, (AbiFile_t)-1);
  return (AbiFile_t) IE_Imp::fileTypeForSuffix (suffix);
}

ABICAPI_API(AbiFile_t)
abi_imp_type_for_suffixes (const char * suffixes)
{
  UT_return_val_if_fail (suffixes, (AbiFile_t)-1);
  return (AbiFile_t)IE_Imp::fileTypeForSuffixes (suffixes);
}

ABICAPI_API(AbiFile_t)
abi_imp_type_for_description (const char * desc)
{
  UT_return_val_if_fail (desc, (AbiFile_t)-1);
  return (AbiFile_t)IE_Imp::fileTypeForDescription (desc);
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_imp_suffixes_for_type (AbiFile_t type)
{
  return (ABI_CONST_RETURN char *) IE_Imp::suffixesForFileType ((IEFileType)type);
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_imp_description_for_type (AbiFile_t type)
{
  return (ABI_CONST_RETURN char *) IE_Imp::descriptionForFileType ((IEFileType)type);
}

ABICAPI_API(size_t)
abi_imp_count_importers (void)
{
  return (size_t) IE_Imp::getImporterCount ();
}

/*******************************************************************/
/*******************************************************************/

ABICAPI_API(AbiFile_t)
abi_exp_type_for_suffix (const char * suffix)
{
  UT_return_val_if_fail (suffix, (AbiFile_t)-1);
  return (AbiFile_t) IE_Exp::fileTypeForSuffix (suffix);
}

ABICAPI_API(AbiFile_t)
abi_exp_type_for_suffixes (const char * suffixes)
{
  UT_return_val_if_fail (suffixes, (AbiFile_t)-1);
  return (AbiFile_t) IE_Exp::fileTypeForSuffixes (suffixes);
}

ABICAPI_API(AbiFile_t)
abi_exp_type_for_description (const char * desc)
{
  UT_return_val_if_fail (desc, (AbiFile_t)-1);
  return (AbiFile_t) IE_Exp::fileTypeForDescription (desc);
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_exp_suffixes_for_type (AbiFile_t type)
{
  return (ABI_CONST_RETURN char *) IE_Exp::suffixesForFileType ((IEFileType)type);
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_exp_description_for_type (AbiFile_t type)
{
  return (ABI_CONST_RETURN char *) IE_Exp::descriptionForFileType ((IEFileType)type);
}

ABICAPI_API(size_t)
abi_exp_count_exporters (void)
{
  return (size_t) IE_Exp::getExporterCount ();
}
