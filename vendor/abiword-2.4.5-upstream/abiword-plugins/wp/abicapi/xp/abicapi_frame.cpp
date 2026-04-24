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

#include "xap_App.h"
#include "xap_Frame.h"

#include "ut_assert.h"

static int
abi_frame_assert (const AbiFrame * pFrame)
{
	if (!pFrame)
		return 0;
	if (!pFrame->pFrame)
		return 0;
	return 1;
}

/**
 * Frees the frame
 */
ABICAPI_API(void)
abi_frame_free (AbiFrame * pFrame)
{
	UT_return_if_fail (abi_frame_assert (pFrame));

	delete pFrame->pFrame;
	FREEP (pFrame);
}

/**
 * Clones this frame, or NULL
 */
ABICAPI_API(AbiFrame *)
abi_frame_clone (AbiFrame * pFrame)
{
	AbiFrame * pNewFrame;
	XAP_Frame * xap_Frame;

	UT_return_val_if_fail (abi_frame_assert (pFrame), NULL);

	xap_Frame = pFrame->pFrame->cloneFrame ();
	if (!xap_Frame)
		return NULL;

	pNewFrame = (AbiFrame *)malloc (sizeof (AbiFrame));
	if (!pNewFrame) {
		delete xap_Frame;
		return NULL;
	}

	pNewFrame->pFrame = xap_Frame;
	pNewFrame->allocd = true;

	return pFrame;	
}

/**
 * Make this frame load the document
 */
ABICAPI_API(AbiError_t)  
abi_frame_load_document (AbiFrame * pFrame, const char * szFile,
						 AbiFile_t ieft, int create_new)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), (AbiError_t)UT_ERROR);

	return (AbiError_t)pFrame->pFrame->loadDocument (szFile, ieft, create_new);
}

/**
 * Make this frame 'import' the document
 */
ABICAPI_API(AbiError_t)
abi_frame_import_document (AbiFrame * pFrame, const char * szFile,
						   AbiFile_t ieft, int mark_clean)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), (AbiError_t)UT_ERROR);

	return (AbiError_t)pFrame->pFrame->importDocument (szFile, ieft, mark_clean);
}

/**
 * Close this frame. Return true or false
 */
ABICAPI_API(int)
abi_frame_close (AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return pFrame->pFrame->close ();
}

/**
 * Raise this frame. Return true or false
 */
ABICAPI_API(int)
abi_frame_raise (AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return pFrame->pFrame->raise ();
}

/**
 * Show this frame. Return true or false
 */
ABICAPI_API(int)
abi_frame_show (AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return pFrame->pFrame->show ();
}

/**
 * Update this frame's title. Return true or false
 */
ABICAPI_API(int)
abi_frame_update_title (AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return pFrame->pFrame->updateTitle ();
}

/**
 * Set this frame's title.
 */
ABICAPI_API(void)
abi_frame_set_cursor (AbiFrame * pFrame, AbiCursor_t type)
{
	UT_return_if_fail (abi_frame_assert (pFrame));
	pFrame->pFrame->setCursor ((GR_Graphics::Cursor)type);
}

ABICAPI_API(void)
abi_frame_set_full_screen (AbiFrame * pFrame, int on)
{
	UT_return_if_fail (abi_frame_assert (pFrame));
	pFrame->pFrame->setFullScreen (on);
}

/**
 * Open this url. Return true or false;
 */
ABICAPI_API(int)
abi_frame_open_url (AbiFrame * pFrame, const char * szUrl)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return XAP_App::getApp()->openURL (szUrl);
}

/**
 * Open this url in a help browser. Return true or false;
 */
ABICAPI_API(int)
abi_frame_open_help_url (AbiFrame * pFrame, const char * szUrl)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return XAP_App::getApp()->openHelpURL (szUrl);
}

/**
 * Return this frame's filename. Or null
 */
ABICAPI_API(ABI_CONST_RETURN char *)
abi_frame_get_filename (const AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), NULL);
	return pFrame->pFrame->getFilename ();
}

/**
 * Return this frame's title. Or null
 */
ABICAPI_API(ABI_CONST_RETURN char *)
abi_frame_get_title (const AbiFrame * pFrame, size_t len)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), NULL);
	return pFrame->pFrame->getTitle ((int)len);
}

/**
 * Return this frame's undecorated title. Or null
 */
ABICAPI_API(ABI_CONST_RETURN char *)
abi_frame_get_undecorated_title (const AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), NULL);
	return pFrame->pFrame->getNonDecoratedTitle ();
}

ABICAPI_API(int)
abi_frame_is_dirty (const AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return pFrame->pFrame->isDirty ();
}

ABICAPI_API(void)
abi_frame_zoom(AbiFrame * pFrame, int zoom)
{
  	UT_return_if_fail (abi_frame_assert (pFrame));
	pFrame->pFrame->quickZoom (zoom);
}

ABICAPI_API(int)
abi_frame_get_zoom(AbiFrame * pFrame)
{
  	UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
	return pFrame->pFrame->getZoomPercentage ();
}

ABICAPI_API(void)
abi_frame_toggle_top_ruler (AbiFrame * pFrame, int on)
{
  UT_return_if_fail (abi_frame_assert (pFrame));
  pFrame->pFrame->toggleTopRuler (on);
}

ABICAPI_API(void)
abi_frame_toggle_left_ruler (AbiFrame * pFrame, int on)
{
  UT_return_if_fail (abi_frame_assert (pFrame));
  pFrame->pFrame->toggleLeftRuler (on);
}

ABICAPI_API(void)
abi_frame_toggle_status_bar (AbiFrame * pFrame, int on)
{
  UT_return_if_fail (abi_frame_assert (pFrame));
  pFrame->pFrame->toggleStatusBar (on);
}

ABICAPI_API(void)
abi_frame_set_status_message (AbiFrame * pFrame, const char * msg)
{
  UT_return_if_fail (abi_frame_assert (pFrame));
  pFrame->pFrame->setStatusMessage (msg);
}

ABICAPI_API(int)
abi_frame_is_menu_bar_shown (const AbiFrame * pFrame)
{
  UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
  return pFrame->pFrame->isMenuBarShown ();
}

ABICAPI_API(int)
abi_frame_is_status_bar_shown (const AbiFrame * pFrame)
{
  UT_return_val_if_fail (abi_frame_assert (pFrame), 0);
  return pFrame->pFrame->isStatusBarShown ();
}
