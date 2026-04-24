/*
 * AbiControl - Abiword plugin for a Bonobo control
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

#include "ut_assert.h"
#include "ut_debugmsg.h"
#include "xap_Module.h"
#include "xap_App.h"
#include "xap_Frame.h"
#include "fv_View.h"
#include "ap_Menu_Id.h"
#include "ev_Menu_Actions.h"
#include "ev_Menu.h"
#include "ev_Menu_Layouts.h"
#include "ev_Menu_Labels.h"
#include "ev_EditMethod.h"
#include "xap_Menu_Layouts.h"
#include "fg_Graphic.h"
#include "ie_imp.h"
#include "ie_impGraphic.h"
#include "ie_exp.h"
#include "ie_types.h"

#include "ut_sleep.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "AbiControl.h"

#if 0
#include <gnome.h>
#include <bonobo.h>
#include <liboaf/liboaf.h>
#endif
//using namespace std;


ABI_PLUGIN_DECLARE(AbiControl)

static bool AbiControl_invoke(AV_View* v, EV_EditMethodCallData *d);

//
// AbiControl_registerMethod()
// -----------------------
//   Adds AbiControl_invoke to the EditMethod list
//
static void AbiControl_registerMethod()
{
    // First we need to get a pointer to the application itself.
    XAP_App *pApp = XAP_App::getApp();

    
    // Create an EditMethod that will link our method's name with
    // it's callback function.  This is used to link the name to 
    // the callback.
    EV_EditMethod *myEditMethod = new EV_EditMethod(
        "AbiControl_invoke",  // name of callback function
        AbiControl_invoke,    // callback function itself.
        0,                      // no additional data required.
        ""                      // description -- allegedly never used for anything
    );
   
    // Now we need to get the EditMethod container for the application.
    // This holds a series of Edit Methods and links names to callbacks.
    EV_EditMethodContainer* pEMC = pApp->getEditMethodContainer();
    
    // We have to add our EditMethod to the application's EditMethodList
    // so that the application will know what callback to call when a call

    pEMC->addEditMethod(myEditMethod);

}


static void AbiControl_RemoveFromMethods ()
{
  // First we need to get a pointer to the application itself.
  XAP_App *pApp = XAP_App::getApp();

  // remove the edit method
  EV_EditMethodContainer* pEMC = pApp->getEditMethodContainer() ;
  EV_EditMethod * pEM = ev_EditMethod_lookup ( "AbiCOmmand_invoke" ) ;
  pEMC->removeEditMethod ( pEM ) ;
  DELETEP( pEM ) ;
}

    
// -----------------------------------------------------------------------
//
//      Abiword Plugin Interface 
//
// -----------------------------------------------------------------------
    
ABI_FAR_CALL
int abi_plugin_register (XAP_ModuleInfo * mi)
{
    mi->name = "AbiControl";
    mi->desc = "This is a bonobo control for AbiWord";
    mi->version = ABI_VERSION_STRING;
    mi->author = "Martin Sevior <msevior@physics.unimelb.edu.au>";
    mi->usage = "AbiControl_invoke";
    
    // Add to AbiWord's menus.
    AbiControl_registerMethod();
    return 1;
}


ABI_FAR_CALL
int abi_plugin_unregister (XAP_ModuleInfo * mi)
{
    mi->name = 0;
    mi->desc = 0;
    mi->version = 0;
    mi->author = 0;
    mi->usage = 0;

    AbiControl_RemoveFromMethods ();

    return 1;
}


ABI_FAR_CALL
int abi_plugin_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release)
{
    return 1; 
}

// -----------------------------------------------------------------------
//
//     AbiControl Invocation Code
//
// -----------------------------------------------------------------------


//
// AbiControl_invoke
// -------------------
//   This is the function that we actually call to make command line 
//   interface.
//
static bool  AbiControl_invoke(AV_View* v, EV_EditMethodCallData *d)
{
//
// Do something useful...
// 
	AbiControl myCommand;
	myCommand.displayDemo("fred.abw");
	return true;
}

AbiControl::AbiControl(void) 
{
	m_wCloseButton = NULL;
	m_wControlFrame = NULL;
	m_wMainWindow = NULL;
	m_wAbiWidget = NULL;
	m_wAbiEntry = NULL;
}

AbiControl::~AbiControl(void)
{
	if(m_wMainWindow != NULL)
	{
		gtk_widget_destroy(m_wMainWindow);
	}
	m_wCloseButton = NULL;
	m_wControlFrame = NULL;
	m_wMainWindow = NULL;
	m_wAbiWidget = NULL;
}

static gboolean s_close(GtkWidget * widget, AbiControl * me)
{
	UT_ASSERT(widget && me);
	me->closeControl();
	return FALSE;
}

static gboolean s_entry_activated(GtkWidget * widget, AbiControl * me)
{
	UT_ASSERT(widget && me);
	me->entryActivate();
	return FALSE;
}


void AbiControl::displayDemo(const char * filename)
{
	_constructWindowDemo();
	AP_UnixApp * pApp = (AP_UnixApp *) XAP_App::getApp();
	m_wAbiWidget = abi_widget_new_with_app_file(pApp,filename);
	UT_DEBUGMSG(("AbiWidget created \n"));
	gtk_container_add (GTK_CONTAINER (m_wControlFrame), m_wAbiWidget);
	UT_DEBUGMSG(("AbiWidget container Add \n"));
	gtk_widget_show(m_wMainWindow);
	UT_DEBUGMSG(("AbiWidget show mainwindow \n"));
	connectSignalsDemo();
	gtk_object_set(GTK_OBJECT(m_wAbiWidget),"AbiWidget::map_to_screen",(gboolean) TRUE,NULL);
	UT_DEBUGMSG(("AbiWidget mapped to screen here \n"));
	gtk_object_set(GTK_OBJECT(m_wAbiWidget),"AbiWidget::draw",(gboolean) TRUE,NULL);
	UT_DEBUGMSG(("AbiWidget drawed here \n"));
	gtk_object_set(GTK_OBJECT(m_wAbiWidget),"AbiWidget::cursoron",(gboolean) TRUE,NULL);
	gtk_object_set(GTK_OBJECT(m_wAbiWidget),"AbiWidget::invoke_noargs",(gchar *) "viewPara",NULL);
	gtk_main();
	gtk_widget_destroy(m_wMainWindow);
	m_wMainWindow = NULL;
}

void AbiControl::closeControl(void)
{
	gtk_main_quit();
}

void AbiControl::entryActivate(void)
{
	gchar *command = const_cast<gchar *>(gtk_entry_get_text (GTK_ENTRY (m_wAbiEntry)));
	printf("command is %s m_wAbiWidget is %x \n",command,m_wAbiWidget);
	gchar ** ptr = g_strsplit(command," ",100);
	gint n = 0;
	while(ptr[n] != NULL)
	{
		n++;
	}
	if(n > 1)
	{
		if(strcmp(ptr[0],"load_file") == 0)
		{
			gtk_object_set(GTK_OBJECT(m_wAbiWidget),"AbiWidget::load_file",(gchar *) ptr[1],NULL);
		}
	}
	else if(strcmp(ptr[0],"cursoron") == 0)
	{
		gtk_object_set(GTK_OBJECT(m_wAbiWidget),"AbiWidget::cursoron",(gboolean ) TRUE,NULL);
	}
	else
	{
		gtk_object_set(GTK_OBJECT(m_wAbiWidget),"AbiWidget::invoke_noargs",(gchar *) command,NULL);
	}
}

GtkWidget * AbiControl::_constructWindowDemo(void)
{
	GtkWidget *window1;
	GtkWidget *vbox1;
	GtkWidget *frame1;
	GtkWidget *hseparator1;
	GtkWidget *closeButton;

	window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW (window1), 813, 644);

	gtk_window_set_title (GTK_WINDOW (window1), "window1");

	vbox1 = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox1);
	gtk_container_add (GTK_CONTAINER (window1), vbox1);

	frame1 = gtk_frame_new ("AbiControl");
	gtk_widget_show (frame1); 
	gtk_box_pack_start (GTK_BOX (vbox1), frame1, TRUE, TRUE, 0);
	gtk_frame_set_label_align (GTK_FRAME (frame1), 0.04, 0.5);
	gtk_frame_set_shadow_type (GTK_FRAME (frame1), GTK_SHADOW_ETCHED_OUT);

	hseparator1 = gtk_hseparator_new ();
	gtk_widget_show (hseparator1);
	gtk_box_pack_start (GTK_BOX (vbox1), hseparator1, FALSE, FALSE, 0);

	GtkWidget * hboxEntry = gtk_hbox_new(FALSE,0);
	gtk_widget_show(hboxEntry);
	gtk_box_pack_start (GTK_BOX (vbox1), hboxEntry, FALSE, FALSE, 0);

	GtkWidget * AbiCommandLabel = gtk_label_new("AbiWidget Command: ");
	gtk_widget_show(AbiCommandLabel);
	gtk_box_pack_start (GTK_BOX (hboxEntry), AbiCommandLabel, FALSE, FALSE, 0);
	
	m_wAbiEntry = gtk_entry_new();
	gtk_widget_show(m_wAbiEntry);
	gtk_box_pack_start (GTK_BOX (hboxEntry), m_wAbiEntry, TRUE, TRUE, 0);

	closeButton = gtk_button_new_with_label ("close");
	gtk_widget_show (closeButton);
	gtk_box_pack_start (GTK_BOX (vbox1), closeButton, FALSE, FALSE, 0);
	m_wCloseButton = closeButton;
	m_wControlFrame = frame1;
	m_wMainWindow = window1;
	return window1;
}


void AbiControl::connectSignalsDemo(void)
{

	// Now connect the signals
	g_signal_connect(G_OBJECT(m_wCloseButton),
					   "clicked",
					   G_CALLBACK(s_close),
					   (gpointer) this);

	g_signal_connect(G_OBJECT(m_wAbiEntry),
					   "activate",
					   G_CALLBACK(s_entry_activated),
					   (gpointer) this);
	
	// the catch-alls
	// Dont use gtk_signal_connect_after for modeless dialogs
	g_signal_connect(G_OBJECT(m_wMainWindow),
							 "delete_event",
							 G_CALLBACK(s_close),
							 (gpointer) this);

	g_signal_connect_after(G_OBJECT(m_wMainWindow),
							 "destroy",NULL, NULL);
}

#if 0

/* 
 * get a value from abiwidget
 */ 
static void
get_prop (BonoboPropertyBag 	*bag,
	  BonoboArg 		*arg,
	  guint 		 arg_id,
	  CORBA_Environment 	*ev,
	  gpointer 		 user_data)
{
	AbiWidget 	*abi;
	
	g_return_if_fail (IS_ABI_WIDGET(user_data));
		
	/*
	 * get data from our AbiWidget
	 */
//
// first create a fresh gtkargument.
//
	GtkArg * gtk_arg = (GtkArg *) g_new0 (GtkArg,1);
//
// Now copy the bonobo argument to this so we know what to extract from
// AbiWidget.
//
	bonobo_arg_to_gtk(gtk_arg,arg);
//
// OK get the data from the widget. Only one argument at a time.
//
	abi = ABI_WIDGET(user_data); 
	gtk_object_getv(GTK_OBJECT(abi),1,gtk_arg);
//
// Now copy it back to the bonobo argument.
//
	bonobo_arg_from_gtk (arg, gtk_arg);
//
// Free up allocated memory
//
	if (gtk_arg->type == GTK_TYPE_STRING && GTK_VALUE_STRING (*gtk_arg))
	{
		g_free (GTK_VALUE_STRING (*gtk_arg));
	}
	g_free(gtk_arg);
}

/*
 * Tell abiwidget to do something.
 */
static void
set_prop (BonoboPropertyBag 	*bag,
	  const BonoboArg 	*arg,
	  guint 		 arg_id,
	  CORBA_Environment 	*ev,
	  gpointer 		 user_data)
{
	AbiWidget 	*abi;
	
	g_return_if_fail (IS_ABI_WIDGET(user_data));
		
	abi = ABI_WIDGET (user_data); 
//
// Have to translate BonoboArg to GtkArg now. This is really easy.
//
	GtkArg * gtk_arg = (GtkArg *) g_new0 (GtkArg,1);
	bonobo_arg_to_gtk(gtk_arg,arg);
//
// Can only pass one argument at a time.
//
	gtk_object_setv(GTK_OBJECT(abi),1,gtk_arg);
//
// Free up allocated memory
//
	if (gtk_arg->type == GTK_TYPE_STRING && GTK_VALUE_STRING (*gtk_arg))
	{
		g_free (GTK_VALUE_STRING (*gtk_arg));
	}
	g_free(gtk_arg);
}

 /*
 *  produce a brand new bonobo_AbiWord_control
 *  (this is a callback function, registered in 
 *  	'bonobo_generic_factory_new')
 */
static BonoboObject*
bonobo_AbiWidget_factory  (BonoboGenericFactory *factory, void *closure)
{
	BonoboControl* 		 control;
	BonoboPropertyBag 	*prop_bag;
	GtkWidget*     		 abi;

	/*
	 * create a new AbiWidget instance
	 */
	AP_UnixApp * pApp = (AP_UnixApp *) XAP_App::getApp();
	abi = abi_widget_new_with_app (pApp);
	gtk_widget_show (abi);
	
	/* create a BonoboControl from a widget */
	control = bonobo_control_new (abi);

	/* 
	 * create a property bag:
	 * we provide our accessor functions for properties, 	and 
	 * the gtk widget
	 * */
	prop_bag = bonobo_property_bag_new (get_prop, set_prop, abi);
	bonobo_control_set_properties (control, prop_bag);

	/* put all AbiWidget's arguments in the property bag - way cool!! */

	bonobo_property_bag_add_gtk_args (prop_bag,GTK_OBJECT(abi)); 

	/*
	 *  we don't need the property bag anymore here, so unref it
	 */
	bonobo_object_unref (BONOBO_OBJECT(prop_bag));

	return BONOBO_OBJECT (control);
}

int AbiControl::mainBonobo(int argc, char * argv[])
{
	BonoboGenericFactory 	*factory;
	CORBA_ORB 		 orb;

	g_print ("starting Bonobo_AbiWord control!\n");
	
	/* intialize gnome */
	gnome_init_with_popt_table ("AbiSource_AbiWord_Control_1_0",  "0.0",
				     argc, argv, oaf_popt_options, 0, NULL);
	/*
	 * initialize oaf and bonobo
	 */
	orb = oaf_init (argc, argv);
	if (!orb)
		g_error ("initializing orb failed");
	
	if (!bonobo_init (orb, NULL, NULL))
		g_error ("initializing Bonobo failed");


	/* register the factory (using OAF) */
	factory = bonobo_generic_factory_new
		("OAFIID:AbiSource_AbiWord_Control_1_0",
		 bonobo_AbiWidget_factory, NULL);
	if (!factory)
		g_error ("Registration of Bonobo button factory failed");
	
	/*
	 *  make sure we're unreffing upon exit;
	 *  enter the bonobo main loop
	 */
	bonobo_running_context_auto_exit_unref (BONOBO_OBJECT(factory));
	bonobo_main ();
	
	return 0;
}
#endif









