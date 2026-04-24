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

#ifndef ABICAPI_PRIVATE_H
#define ABICAPI_PRIVATE_H

#include <sys/types.h>

#include "xap_App.h"
#include "xap_Frame.h"
#include "pd_Document.h"
#include "ut_string_class.h"
#include "fv_View.h"

#ifdef __cplusplus
extern "C" {
#endif /* C++ */

  struct str_AbiApp
  {
    XAP_App * pApp;
    bool allocd;
  };
  
  struct str_AbiFrame
  {
    XAP_Frame * pFrame;
    bool allocd;
  };

  struct str_AbiDoc
  {
    PD_Document * pDoc;
    bool allocd;

    UT_UTF8String metaDataVal;
  };

  struct str_AbiView
  {
    FV_View * pView;
    bool allocd;
  };

#ifdef __cplusplus
}
#endif /* C++ */

#endif /* ABICAPI_PRIVATE_H */
