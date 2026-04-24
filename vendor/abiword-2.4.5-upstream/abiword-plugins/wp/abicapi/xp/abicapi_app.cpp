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
abi_app_assert (const AbiApp * pApp)
{
	if (!pApp)
		return 0;
	if (!pApp->pApp)
		return 0;
	return 1;
}

static AbiApp * thisApp = NULL;

ABICAPI_API(void)
abi_app_shutdown (void)
{
  UT_return_if_fail (abi_app_assert (thisApp));

  if (thisApp->allocd) { 
    // don't allow people to shutdown an instance of abi
    // if they didn't allocate it themselves
#if 0
    abi_app_platform_shutdown (thisApp->pApp);
#endif
    delete thisApp->pApp;
  }

  FREEP (thisApp);
}

ABICAPI_API(AbiError_t)
abi_app_init (int argc, char ** argv)
{
  // try and get the current app if one exists
  // but be annoying about it...
  UT_return_val_if_fail (abi_app_get_current (), UT_OK);

#if 0
  // TODO - code this function
  thisApp = abi_app_platform_init (argc, argv);
#endif

  if (!thisApp)
    return UT_ERROR;

  thisApp->allocd = true;

  return UT_OK;
}

/**
 * Gets the current running AbiApp.
 * returned object may be null
 */
ABICAPI_API(AbiApp *)
abi_app_get_current (void)
{
  XAP_App * pApp;

  if (!thisApp || !thisApp->pApp) {    
    pApp = XAP_App::getApp ();
    if (!pApp)
      return NULL;

    thisApp = (AbiApp *)malloc (sizeof (AbiApp));
    if (!thisApp)
      return NULL;

    thisApp->allocd = false;
    thisApp->pApp = XAP_App::getApp ();
  }
  
  return thisApp;
}

/**
 * Creates a new frame
 * Can return null. Returned frame
 * must be free'd
 */
ABICAPI_API(AbiFrame *)
abi_app_new_frame (AbiApp * pApp)
{
	AbiFrame * pFrame;
	XAP_Frame * xap_Frame;

	UT_return_val_if_fail (abi_app_assert (pApp), NULL);

	xap_Frame = pApp->pApp->newFrame ();
	if (!xap_Frame)
		return NULL;

	pFrame = (AbiFrame *)malloc (sizeof (AbiFrame));
	if (!pFrame) {
		delete xap_Frame;
		return NULL;
	}

	pFrame->pFrame = xap_Frame;
	pFrame->allocd = true;

	return pFrame;
}

/**
 * Get the frame represented by which, or null
 */
ABICAPI_API(AbiFrame *)
abi_app_get_frame (AbiApp * pApp, size_t which)
{
	AbiFrame * pFrame;
	XAP_Frame * xap_Frame;

	UT_return_val_if_fail (abi_app_assert (pApp), NULL);

	xap_Frame = pApp->pApp->getFrame ((UT_sint32)which);
	if (!xap_Frame)
		return NULL;

	pFrame = (AbiFrame *)malloc (sizeof (AbiFrame));
	if (!pFrame) {
		delete xap_Frame;
		return NULL;
	}

	pFrame->pFrame = xap_Frame;
	pFrame->allocd = false;

	return pFrame;
}

/**
 * Get the # of frames, or -1 on error
 */
ABICAPI_API(ssize_t)
abi_app_get_frame_count (AbiApp * pApp)
{
	UT_return_val_if_fail (abi_app_assert (pApp), -1);

	return (ssize_t) pApp->pApp->getFrameCount ();
}

/**
 * Find the frame with this filename, or -1
 */
ABICAPI_API(ssize_t)
abi_app_find_frame (AbiApp * pApp, const char * szFilename)
{
	UT_return_val_if_fail (abi_app_assert (pApp), -1);

	return (ssize_t) pApp->pApp->findFrame (szFilename);
}

/**
 * Find the # for this existing frame, or -1 on error
 */
ABICAPI_API(ssize_t)
abi_app_find_existing_frame (AbiApp * pApp, AbiFrame * pFrame)
{
	UT_return_val_if_fail (abi_app_assert (pApp), -1);

	return (ssize_t) pApp->pApp->findFrame (pFrame->pFrame);
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_default_encoding (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getDefaultEncoding ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_application_title (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getApplicationTitleForTitleBar ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_application_name (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getApplicationName ();
}

ABICAPI_API(int)
abi_app_can_paste (AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), 0);

  return (int) pApp->pApp->canPasteFromClipboard ();
}

ABICAPI_API(AbiFrame *)
abi_app_find_valid_frame (AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  XAP_Frame * xap_Frame = pApp->pApp->findValidFrame ();
  if (!xap_Frame)
    return NULL;

  AbiFrame * pFrame = (AbiFrame *)malloc (sizeof (AbiFrame));
  if (!pFrame) {
    delete xap_Frame;
    return NULL;
  }
  
  pFrame->pFrame = xap_Frame;
  pFrame->allocd = false;
  
  return pFrame;
}

ABICAPI_API(AbiFrame *)
abi_app_last_focussed_frame (AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  XAP_Frame * xap_Frame = pApp->pApp->getLastFocussedFrame ();
  if (!xap_Frame)
    return NULL;

  AbiFrame * pFrame = (AbiFrame *)malloc (sizeof (AbiFrame));
  if (!pFrame) {
    delete xap_Frame;
    return NULL;
  }
  
  pFrame->pFrame = xap_Frame;
  pFrame->allocd = false;
  
  return pFrame;
}

ABICAPI_API(int)
abi_app_make_directory (const AbiApp * pApp, 
			const char * path, int mode)
{
  UT_return_val_if_fail (abi_app_assert (pApp), 0);

  return pApp->pApp->makeDirectory (path, mode);
}

/**************************************************************/
/**************************************************************/

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_build_id (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getBuildId ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_build_version (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getBuildVersion ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_build_options (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getBuildOptions ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_build_target (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getBuildTarget ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_build_compile_time (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getBuildCompileTime ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_build_compile_date (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getBuildCompileDate ();
}

ABICAPI_API(ABI_CONST_RETURN char *)
abi_app_get_suite_home (const AbiApp * pApp)
{
  UT_return_val_if_fail (abi_app_assert (pApp), NULL);

  return (ABI_CONST_RETURN char *) pApp->pApp->getAbiSuiteHome ();
}

/**************************************************************/
/**************************************************************/

ABICAPI_API(int)
abi_app_get_pref_value (const AbiApp * pApp, 
			const char * key, const char ** value)
{
  UT_return_val_if_fail (abi_app_assert (pApp), 0);

  return pApp->pApp->getPrefsValue (key, value);
}

ABICAPI_API(int)
abi_app_get_pref_value_bool (const AbiApp * pApp,
			     const char * key, int * value)
{
  UT_return_val_if_fail (abi_app_assert (pApp), 0);

  bool bValue;

  int status = pApp->pApp->getPrefsValueBool (key, &bValue);

  *value = bValue;

  return status;
}

/**************************************************************/
/**************************************************************/
