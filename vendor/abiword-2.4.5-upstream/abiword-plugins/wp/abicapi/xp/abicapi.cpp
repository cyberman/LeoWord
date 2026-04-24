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

#ifdef ABI_PLUGIN_BUILTIN
#define abi_plugin_register abipgn_capi_register
#define abi_plugin_unregister abipgn_capi_unregister
#define abi_plugin_supports_version abipgn_capi_supports_version
#endif

#include "abicapi.h"
#include "xap_Module.h"

ABI_PLUGIN_DECLARE("AbiCapi")

ABICAPI_API(int)
abi_plugin_register (XAP_ModuleInfo * mi)
{
  mi->name = "AbiCapi";
  mi->desc = "C API for AbiWord";
  mi->version = ABI_VERSION_STRING;
  mi->author = "Dom Lachowicz <cinamod@hotmail.com>";
  mi->usage = "No Usage";
  
  /* exists just to load the symbols into memory */
  return 1;
}

ABICAPI_API(int)
abi_plugin_unregister (XAP_ModuleInfo * mi)
{
  /* will just unload the symbols from memory */
  return 1;
}

ABICAPI_API(int)
abi_plugin_supports_version (UT_uint32 major, 
			     UT_uint32 minor, 
			     UT_uint32 release)
{
  return 1;
}
