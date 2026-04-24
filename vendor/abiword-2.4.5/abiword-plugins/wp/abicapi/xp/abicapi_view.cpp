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
abi_view_assert (const AbiView * pView)
{
  if (!pView)
    return 0;
  if (!pView->pView)
    return 0;

  return 1;
}

ABICAPI_API(size_t)
abi_view_get_point(const AbiView * pView)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);
  return pView->pView->getPoint ();
}

ABICAPI_API(size_t)
abi_view_get_selection_anchor(const AbiView * pView)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);
  return pView->pView->getSelectionAnchor ();
}

ABICAPI_API(int)
abi_view_can_undo(const AbiView * pView)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);
  return pView->pView->canDo (true);
}

ABICAPI_API(int)
abi_view_can_redo(const AbiView * pView)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);
  return pView->pView->canDo (false);
}

ABICAPI_API(void)
abi_view_undo(const AbiView * pView, size_t count)
{
  UT_return_if_fail (abi_view_assert (pView));
  return pView->pView->cmdUndo (count);
}

ABICAPI_API(void)
abi_view_redo(const AbiView * pView, size_t count)
{
  UT_return_if_fail (abi_view_assert (pView));
  return pView->pView->cmdRedo (count);
}

ABICAPI_API(AbiError_t)
abi_view_save (AbiView * pView)
{
  UT_return_val_if_fail (abi_view_assert (pView), (AbiError_t)UT_ERROR);
  return (AbiError_t) pView->pView->cmdSave ();
}

ABICAPI_API(AbiError_t)
abi_view_save_as_ex (AbiView * pView, const char * filename, AbiFile_t type,
		     int copy)
{
  UT_return_val_if_fail (abi_view_assert (pView), (AbiError_t)UT_ERROR);
  UT_return_val_if_fail (filename, (AbiError_t)UT_ERROR);
  return (AbiError_t) pView->pView->cmdSaveAs (filename, type, copy);
}

ABICAPI_API(AbiError_t)
abi_view_save_as (AbiView * pView, const char * filename, AbiFile_t type)
{
  return abi_view_save_as_ex (pView, filename, type, false);
}

ABICAPI_API(AbiError_t)
abi_view_insert_field_ex (AbiView * pView, const char * name,
			  const char ** extra_attrs,
			  const char ** extra_props)
{
  UT_return_val_if_fail (abi_view_assert (pView), (AbiError_t)UT_ERROR);
  UT_return_val_if_fail (name, (AbiError_t)UT_ERROR);

  return (AbiError_t)pView->pView->cmdInsertField (name, extra_attrs,
						   extra_props);
}

ABICAPI_API(AbiError_t)
abi_view_insert_field (AbiView * pView, const char * name)
{
  return abi_view_insert_field_ex (pView, name, NULL, NULL);
}

ABICAPI_API(AbiError_t)
abi_view_insert_bookmark(AbiView * pView, const char * name)
{
  UT_return_val_if_fail (abi_view_assert (pView), (AbiError_t)UT_ERROR);
  UT_return_val_if_fail (name, (AbiError_t)UT_ERROR);

  return (AbiError_t)pView->pView->cmdInsertBookmark (name);
}

ABICAPI_API(AbiError_t)
abi_view_delete_bookmark(AbiView * pView, const char * name)
{
  UT_return_val_if_fail (abi_view_assert (pView), (AbiError_t)UT_ERROR);
  UT_return_val_if_fail (name, (AbiError_t)UT_ERROR);

  return (AbiError_t)pView->pView->cmdDeleteBookmark (name);
}

ABICAPI_API(AbiError_t)
abi_view_insert_hyperlink(AbiView * pView, const char * name)
{
  UT_return_val_if_fail (abi_view_assert (pView), (AbiError_t)UT_ERROR);
  UT_return_val_if_fail (name, (AbiError_t)UT_ERROR);

  return (AbiError_t)pView->pView->cmdInsertHyperlink (name);
}

ABICAPI_API(AbiError_t)
abi_view_delete_hyperlink(AbiView * pView)
{
  UT_return_val_if_fail (abi_view_assert (pView), (AbiError_t)UT_ERROR);

  return (AbiError_t)pView->pView->cmdDeleteHyperlink ();
}

ABICAPI_API(void)
abi_view_set_paper_color (AbiView * pView, const char * color)
{
  UT_return_if_fail (abi_view_assert (pView));
  UT_return_if_fail (color);

  pView->pView->setPaperColor (color);
}

ABICAPI_API(void)
abi_view_copy_ex (AbiView * pView, int toClipboard)
{
  UT_return_if_fail (abi_view_assert (pView));

  pView->pView->cmdCopy (toClipboard);
}

ABICAPI_API(void)
abi_view_copy (AbiView * pView)
{
  abi_view_copy_ex (pView, true);
}

ABICAPI_API(void)
abi_view_cut (AbiView * pView)
{
  UT_return_if_fail (abi_view_assert (pView));

  pView->pView->cmdCut ();
}

ABICAPI_API(void)
abi_view_paste_ex (AbiView * pView, int honor_formatting)
{
  UT_return_if_fail (abi_view_assert (pView));

  pView->pView->cmdPaste (honor_formatting);
}

ABICAPI_API(void)
abi_view_paste (AbiView * pView)
{
  abi_view_paste_ex (pView, true);
}

ABICAPI_API(int)
abi_view_is_selection_empty (AbiView * pView)
{
  UT_return_val_if_fail (abi_view_assert (pView), 1);

  return pView->pView->isSelectionEmpty ();
}

ABICAPI_API(void)
abi_view_unselect_selection (AbiView * pView)
{
  UT_return_if_fail (abi_view_assert (pView));

  pView->pView->cmdUnselectSelection ();
}

ABICAPI_API(int)
abi_view_set_section_format (AbiView * pView, const char ** properties)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);

  return pView->pView->setSectionFormat (properties);
}

ABICAPI_API(int)
abi_view_get_section_format (AbiView * pView, const char *** out_properties)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);

  return pView->pView->getSectionFormat (out_properties);
}

ABICAPI_API(int)
abi_view_set_block_format (AbiView * pView, const char ** properties)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);

  return pView->pView->setBlockFormat (properties);
}

ABICAPI_API(int)
abi_view_get_block_format (AbiView * pView, const char *** out_properties)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);

  return pView->pView->getBlockFormat (out_properties);
}

ABICAPI_API(int)
abi_view_set_char_format_ex (AbiView * pView,
			     const char ** properties,
			     const char ** attributes)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);

  return pView->pView->setCharFormat (properties, attributes);
}

ABICAPI_API(int)
abi_view_set_char_format (AbiView * pView,
			  const char ** properties)
{
  return abi_view_set_char_format_ex (pView, properties, NULL);
}

ABICAPI_API(int)
abi_view_get_char_format_ex (AbiView * pView,
			     const char *** out_properties,
			     int expand_styles)
{
  UT_return_val_if_fail (abi_view_assert (pView), 0);

  return pView->pView->getCharFormat(out_properties, expand_styles);
}

ABICAPI_API(int)
abi_view_get_char_format (AbiView * pView,
			  const char *** out_properties)
{
  return abi_view_get_char_format_ex (pView, out_properties, true);
}
