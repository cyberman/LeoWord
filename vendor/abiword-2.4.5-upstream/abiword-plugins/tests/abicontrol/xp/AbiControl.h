/*
 * AbiControl - Abiword plugin for a Bonobo Control
 * Copyright (C) 2002 by Martin Sevior
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

#ifndef PLUGIN_ABICONTROL_H
#define PLUGIN_ABICONTROL_H
#define ABIWORD_INTERNAL 1
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk/gdkx.h>
#include "glib.h"
#include "glibconfig.h"
#include "gdkconfig.h"

#include "ut_assert.h"
#include "ut_debugmsg.h"
#include "xap_Module.h"
#include "xap_App.h"
#include "xap_Frame.h"
#include "xav_View.h"
#include "fv_View.h"
#include "fv_View.h"
#include "ev_Menu_Layouts.h"
#include "ev_Menu_Labels.h"
#include "ev_EditMethod.h"
#include "pd_Document.h"
#include "xap_UnixNullGraphics.h"
#include "fg_Graphic.h"
#include "ie_imp.h"
#include "ie_impGraphic.h"
#include "ie_exp.h"
#include "ie_types.h"
#include "fl_DocLayout.h"
#include "ut_sleep.h"
#include "xap_Frame.h"
#include "xap_UnixFrameImpl.h"
#include "ap_Frame.h"
#include "ap_UnixFrame.h"
#include "ap_UnixApp.h"
#include "abiwidget.h"
class AbiControl
{
public:
	AbiControl(void);
	virtual   ~AbiControl(void);
	void displayDemo(const char * filename);
	void closeControl(void);
	void connectSignalsDemo(void);
	void entryActivate(void);
#if 0
    int mainBonobo(int arc, char * argv[]);
#endif
protected:
	GtkWidget * _constructWindowDemo(void);
private:
	GtkWidget *	m_wCloseButton;
	GtkWidget *	m_wControlFrame;
	GtkWidget *	m_wMainWindow;
	GtkWidget *	m_wAbiWidget;
	GtkWidget * m_wAbiEntry;
};

#endif /* PLUGIN_ABICONTROL_H */












