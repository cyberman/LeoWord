/*
* * Copyright (C) 2004 Luca Padovani <lpadovan@cs.unibo.it>
 * Copyright (C) 2005 Martin Sevior <msevior@physics.unimelb.edu.au>
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
#define abi_plugin_register abipgn_abigochart_register
#define abi_plugin_unregister abipgn_abigochart_unregister
#define abi_plugin_supports_version abipgn_abigochart_supports_version
#endif

#include "pd_Document.h"
#include "pp_Property.h"
#include "pp_AttrProp.h"
#include "ut_mbtowc.h"
#include "gr_Painter.h"
#include "gr_Image.h"
#include "xad_Document.h"
#include "xap_Module.h"
#include "ap_App.h"
#include "ie_imp_GOChart.h"
#include "ie_imp.h"
#include "ie_impGraphic.h"
#include "ut_assert.h"
#include "ut_debugmsg.h"
#include "xap_Module.h"
#include "xap_App.h"
#include "xap_Frame.h"
#include "fp_Run.h"
#include "fv_View.h"
#include "ap_Menu_Id.h"
#include "ev_Menu_Actions.h"
#include "ev_Menu.h"
#include "ev_Menu_Layouts.h"
#include "ev_Menu_Labels.h"
#include "ev_EditMethod.h"
#include "xap_Menu_Layouts.h"
#include "ie_exp.h"
#include "ie_types.h"
#include "xap_Dialog_Id.h"
#include "ap_Dialog_Id.h"
#include "xap_Dlg_FileOpenSaveAs.h"
#include "xap_DialogFactory.h"
#include "xap_Dlg_MessageBox.h"
#include "ap_Strings.h"
#include "ap_Dialog_Latex.h"
#include "ut_mbtowc.h"
#include "xap_UnixFrameImpl.h"
#include "ut_locale.h"
#include "ut_sleep.h"
#include "AbiGOChart.h"
#include "gr_UnixImage.h"

#include <gtk/gtkentry.h>
#include <goffice/app/go-plugin.h>
#include <goffice/app/go-plugin-loader-module.h>
#include <goffice/graph/gog-data-allocator.h>
#include <goffice/graph/gog-series.h>
#include <goffice/graph/gog-guru.h>
#include <goffice/graph/gog-renderer-pixbuf.h>
#include <goffice/graph/gog-data-set.h>
#include <goffice/graph/gog-object-xml.h>
#include <goffice/data/go-data-simple.h>
#include <goffice/graph/gog-renderer-gnome-print.h>
#include <goffice/utils/go-format.h>
#include <gsf/gsf-impl-utils.h>
#include <gsf/gsf-output-memory.h>
#include <gsf/gsf-libxml.h>

#include "ut_sleep.h"
#include <sys/types.h>  
#include <sys/stat.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include "ut_files.h"
#endif
#include "gr_UnixGraphics.h"
#include "xap_UnixGnomePrintGraphics.h"
//
// AbiContolGui object
//
#define ABI_CONTROL_GUI_TYPE     (abi_control_gui_get_type ())
#define ABI_CONTROL_GUI(obj)     (G_TYPE_CHECK_INSTANCE_CAST ((obj), ABI_CONTROL_GUI_TYPE, AbiControlGUI))
#define IS_ABI_CONTROL_GUI(o)    (G_TYPE_CHECK_INSTANCE_TYPE ((o), ABI_CONTROL_GUI_TYPE))

class AbiGO_LocaleTransactor
{
 public:

  AbiGO_LocaleTransactor (int category, const char * locale);
  ~AbiGO_LocaleTransactor ();

 private:
  
  int mCategory;
  char * mOldLocale;
};

AbiGO_LocaleTransactor::AbiGO_LocaleTransactor (int category, const char * locale)
  : mCategory (category), mOldLocale (0)
{
	mOldLocale = UT_strdup(setlocale(category, NULL));
	go_setlocale (category, locale);

	// TODO: win32 may need to free old_locale
}

AbiGO_LocaleTransactor::~AbiGO_LocaleTransactor ()
{
	go_setlocale (mCategory, mOldLocale);
	FREEP(mOldLocale);
}

typedef struct _AbiControlGUI
{
	GObject base;
	char *object_id;
	PD_Document * pDoc;
	GOChartView * pView;
};

typedef struct _AbiControlGUI AbiControlGUI;
typedef GObjectClass AbiControlGUIClass;

static GType abi_control_gui_get_type ();

//
// GOCmdContext interface implementation for AbiControlGUI
//
// we should implement it at least for errors reporting
/*static void
abi_cmd_context_init (GOCmdContextClass *iface)
{
	iface->get_password	    = abi_get_password;
	iface->set_sensitive	    = abi_set_sensitive;
	iface->error.error	    = abi_error_error;
	iface->error.error_info	    = abi_error_error_info;
	iface->progress_set	    = abi_progress_set;
	iface->progress_message_set = abi_progress_message_set;
}*/
	
//
// GogDataAllocator interface implementation for AbiControlGUI
//

static void
abi_data_allocator_allocate (GogDataAllocator *dalloc, GogPlot *plot)
{
//	SheetControlGUI *scg = wbcg_cur_scg (WORKBOOK_CONTROL_GUI (dalloc));
//	sv_selection_to_plot (sc_view (SHEET_CONTROL (scg)), plot);
}

typedef struct {
	GtkEntry *entry;
	GogDataset *dataset;
	int dim_i;
	GogDataType data_type;
} GraphDimEditor;

static void
cb_graph_dim_editor_update (GtkEntry *gee,
			    GraphDimEditor *editor)
{

	/* Ignore changes while we are insensitive. useful for displaying
	 * values, without storing then as Data.  Also ignore updates if the
	 * dataset has been cleared via the weakref handler  */
	if (!GTK_WIDGET_SENSITIVE (gee) || editor->dataset == NULL)
		return;

	GOData *data = NULL;
	double val;
	char sep[2], col_sep[2], *end;
	sep[0] = format_get_arg_sep ();
	col_sep[0] = format_get_col_sep ();
	sep[1] = col_sep[1]= 0;
	char const* str = gtk_entry_get_text (gee);
	if (str == NULL)
		return;
	data = NULL;
	switch (editor->data_type) {
	case GOG_DATA_SCALAR:
		if (!*str)
			break;
		val = g_ascii_strtod (str, &end);
		if (*end == 0)
			data = go_data_scalar_val_new (val);
		else
			data = go_data_scalar_str_new (g_strdup (str), TRUE);
		break;
	case GOG_DATA_VECTOR:
	{
		// try to get values, but on error, get strings
		data = go_data_vector_val_new (NULL, 0, NULL);
		if (go_data_from_str (data, str))
			break;
		g_object_unref (data);
		data = go_data_vector_str_new (NULL, 0, NULL);
		if (go_data_from_str (data, str))
			break;
		g_object_unref (data);
		data = NULL;
	}
		break;
	case GOG_DATA_MATRIX:
		data = go_data_matrix_val_new (NULL, 0, 0, NULL);
		if (go_data_from_str (data, str))
			break;
		g_object_unref (data);
		data = NULL;
	}

	if (!data) {
		/* display "Invalid Data message" */
	} else
		gog_dataset_set_dim (editor->dataset, editor->dim_i, data, NULL);
}

static void
cb_graph_dim_entry_unmap (GtkEntry *gee, GraphDimEditor *editor)
{
	cb_graph_dim_editor_update (gee, /*FALSE, */editor);
}

static void
cb_graph_dim_entry_unrealize (GtkEntry *gee, GraphDimEditor *editor)
{
	cb_graph_dim_editor_update (gee, /*FALSE, */editor);
}

static void
cb_dim_editor_weakref_notify (GraphDimEditor *editor, GogDataset *dataset)
{
	g_return_if_fail (editor->dataset == dataset);
	editor->dataset = NULL;
}

static void
graph_dim_editor_free (GraphDimEditor *editor)
{
	if (editor->dataset)
		g_object_weak_unref (G_OBJECT (editor->dataset),
			(GWeakNotify) cb_dim_editor_weakref_notify, editor);
	g_free (editor);
}

static gpointer
abi_data_allocator_editor (GogDataAllocator *dalloc,
			    GogDataset *dataset, int dim_i, GogDataType data_type)
{
	AbiControlGUI *acg = ABI_CONTROL_GUI (dalloc);
	GraphDimEditor *editor;
	GOData *val;

	editor = g_new (GraphDimEditor, 1);
	editor->dataset		= dataset;
	editor->dim_i		= dim_i;
	editor->data_type	= data_type;
	editor->entry  		= GTK_ENTRY (gtk_entry_new ());
	g_object_weak_ref (G_OBJECT (editor->dataset),
		(GWeakNotify) cb_dim_editor_weakref_notify, editor);

//	gnm_expr_entry_set_update_policy (editor->entry,
//		GTK_UPDATE_DISCONTINUOUS);

	val = gog_dataset_get_dim (dataset, dim_i);
	if (val != NULL) {
		char *txt = go_data_as_str (val);
		gtk_entry_set_text (editor->entry, txt);
		g_free (txt);
	}
//	gnm_expr_entry_set_flags (editor->entry,
//		GNM_EE_ABS_COL|GNM_EE_ABS_ROW, GNM_EE_MASK);

/*	g_signal_connect (G_OBJECT (editor->entry),
		"update",
		G_CALLBACK (cb_graph_dim_editor_update), editor);*/
	g_signal_connect (G_OBJECT (editor->entry),
		"activate",
		G_CALLBACK (cb_graph_dim_editor_update), editor);
	g_signal_connect (G_OBJECT (editor->entry),
		"unmap",
		G_CALLBACK (cb_graph_dim_entry_unmap), editor);
	g_signal_connect (G_OBJECT (editor->entry),
		"unrealize",
		G_CALLBACK (cb_graph_dim_entry_unrealize), editor);
	g_object_set_data_full (G_OBJECT (editor->entry),
		"editor", editor, (GDestroyNotify) graph_dim_editor_free);

	return editor->entry;
}

static void
abi_go_plot_data_allocator_init (GogDataAllocatorClass *iface)
{
	iface->allocate   = abi_data_allocator_allocate;
	iface->editor	  = abi_data_allocator_editor;
}

static void
abi_control_gui_init (GObject *object)
{
	AbiControlGUI *control = ABI_CONTROL_GUI (object);
	control->object_id = NULL;
}

static void
abi_control_gui_finalize (GObject *object)
{
	AbiControlGUI *control = ABI_CONTROL_GUI (object);
	if (control->object_id)
		g_free (control->object_id);
}

static void
abi_control_gui_class_init (GObjectClass *klass)
{
	klass->finalize = abi_control_gui_finalize;
}

GSF_CLASS_FULL (AbiControlGUI, abi_control_gui,
		NULL, NULL, abi_control_gui_class_init, NULL,
		abi_control_gui_init, G_TYPE_OBJECT, 0,
		GSF_INTERFACE (abi_go_plot_data_allocator_init, GOG_DATA_ALLOCATOR_TYPE);
		/*GSF_INTERFACE (abi_cmd_context_init, GO_CMD_CONTEXT_TYPE)*/)

/*
static void
cb_graph_guru_done (WorkbookControlGUI *wbcg)
{
	wbcg_edit_detach_guru (wbcg);
	wbcg_edit_finish (wbcg, WBC_EDIT_REJECT, NULL);
}

void
sheet_object_graph_guru (WorkbookControlGUI *wbcg, GogGraph *graph,
			 GClosure *closure)
{
	GtkWidget *dialog = gog_guru (graph, GOG_DATA_ALLOCATOR (wbcg),
		       GO_CMD_CONTEXT (wbcg), wbcg_toplevel (wbcg),
		       closure);
	wbcg_edit_attach_guru (wbcg, dialog);
	g_object_set_data_full (G_OBJECT (dialog),
		"guru", wbcg, (GDestroyNotify) cb_graph_guru_done);
}*/

//
// AbiGOChart_addToMenus
// -----------------------
//   Adds "Object" "Gnome Office Chart" options to AbiWord's Main Menu.
//

static bool AbiGOChart_FileInsert(AV_View* v, EV_EditMethodCallData *d);
static bool AbiGOChart_Create(AV_View* v, EV_EditMethodCallData *d);


// FIXME make these translatable strings

static const char * Object_MenuLabelObject = "Object";
static const char * Object_MenuTooltipObject = "Insert Emebable Object";
static const char* AbiGOChart_MenuLabelInsert = "Gnome Office Chart";
static const char* AbiGOChart_MenuTooltipInsert = "Create a chart";

/*
static const char * AbiMathView_MenuLabelEquation = NULL;
static const char * AbiMathView_MenuTooltipEquation = NULL;
static const char* AbiMathView_MenuLabelFileInsert = NULL;
static const char* AbiMathView_MenuTooltipFileInsert = NULL;
static const char* AbiMathView_MenuLabelLatexInsert = NULL;
static const char* AbiMathView_MenuTooltipLatexInsert = NULL;
*/
static void AbiGOChart_addToMenus()
{
    // First we need to get a pointer to the application itself.
    XAP_App *pApp = XAP_App::getApp();
    //
    // Translated Strings
    //
//     const XAP_StringSet * pSS = pApp->getStringSet();
//     AbiMathView_MenuLabelEquation= pSS->getValue(AP_STRING_ID_MENU_LABEL_INSERT_EQUATION);
//     AbiMathView_MenuTooltipEquation = pSS->getValue(AP_STRING_ID_MENU_LABEL_TOOLTIP_INSERT_EQUATION);
//     AbiMathView_MenuLabelFileInsert = pSS->getValue(AP_STRING_ID_MENU_LABEL_INSERT_EQUATION_FILE);
//     AbiMathView_MenuTooltipFileInsert = pSS->getValue(AP_STRING_ID_MENU_LABEL_TOOLTIP_INSERT_EQUATION_FILE);
    
    // Create an EditMethod that will link our method's name with
    // it's callback function.  This is used to link the name to 
    // the callback.
    EV_EditMethod *myEditMethodFile = new EV_EditMethod(
        "AbiGOChart_Create",  // name of callback function
        AbiGOChart_Create,    // callback function itself.
        0,                      // no additional data required.
        ""                      // description -- allegedly never used for anything
    );
   
    // Now we need to get the EditMethod container for the application.
    // This holds a series of Edit Methods and links names to callbacks.
    EV_EditMethodContainer* pEMC = pApp->getEditMethodContainer();
    
    // We have to add our EditMethod to the application's EditMethodList
    // so that the application will know what callback to call when a call
    // to "AbiMathView_FileInsert" is received.
    pEMC->addEditMethod(myEditMethodFile);
  

    // Now we need to grab an ActionSet.  This is going to be used later
    // on in our for loop.  Take a look near the bottom.
    EV_Menu_ActionSet* pActionSet = pApp->getMenuActionSet();

    
    // We need to go through and add the menu element to each "frame" 
    // of the application.  We can iterate through the frames by doing
    // XAP_App::getFrameCount() to tell us how many frames there are,
    // then calling XAP_App::getFrame(i) to get the i-th frame.

    int frameCount = pApp->getFrameCount();
    XAP_Menu_Factory * pFact = pApp->getMenuFactory();

    // Look to see if "Object" has been loaded already..
    XAP_Menu_Id newObjectID= 0;
    /*
    XAP_Menu_Id newObjectID= pFact->addNewMenuAfter("Main",NULL,"Object",EV_MLF_BeginSubMenu);
   UT_DEBUGMSG(("newObjectID %d \n",newObjectID));
    */
   bool bObjectExists = true;
   if(newObjectID <= 0)
   {
     // Put it after Insert Picture in the Main menu
     // FIXME put it before!
     bObjectExists = false;
     newObjectID= pFact->addNewMenuBefore("Main",NULL,"&Picture",EV_MLF_BeginSubMenu);
   }

   UT_DEBUGMSG(("newObjectID %d \n",newObjectID));


    pFact->addNewLabel(NULL,newObjectID,Object_MenuLabelObject, Object_MenuTooltipObject);

    // Create the Action that will be called.
    EV_Menu_Action* myObjectAction = new EV_Menu_Action(
	newObjectID,          // id that the layout said we could use
	1,                      // yes, we have a sub menu.
	0,                      // no, we don't raise a dialog.
	0,                      // no, we don't have a checkbox.
	0,                      // no radio buttons for me, thank you
	NULL,                   //  no callback function to call.
	NULL,                   // don't know/care what this is for
	NULL                    // don't know/care what this is for
        );

    // Now what we need to do is add this particular action to the ActionSet
    // of the application.  This forms the link between our new ID that we 
    // got for this particular frame with the EditMethod that knows how to 
    // call our callback function.  

    pActionSet->addAction(myObjectAction);

    XAP_Menu_Id InsertGOChartID= pFact->addNewMenuAfter("Main",NULL,"Object",EV_MLF_Normal);
   UT_DEBUGMSG(("GOChart ID %d \n",InsertGOChartID));

    pFact->addNewLabel(NULL, InsertGOChartID,AbiGOChart_MenuLabelInsert, AbiGOChart_MenuTooltipInsert);


    // Create the Action that will be called.
    EV_Menu_Action* myFileAction = new EV_Menu_Action(
	InsertGOChartID,        // id that the layout said we could use
	0,                      // no, we don't have a sub menu.
	1,                      // yes, we raise a dialog.
	0,                      // no, we don't have a checkbox.
	0,                      // no radio buttons for me, thank you
	"AbiGOChart_Create",  // name of callback function to call.
	NULL,                   // don't know/care what this is for
	NULL                    // don't know/care what this is for
        );

    // Now what we need to do is add this particular action to the ActionSet
    // of the application.  This forms the link between our new ID that we 
    // got for this particular frame with the EditMethod that knows how to 
    // call our callback function.  

    pActionSet->addAction(myFileAction);

    if(!bObjectExists)
    {

      XAP_Menu_Id endObjectID= pFact->addNewMenuAfter("Main",NULL,AbiGOChart_MenuLabelInsert,EV_MLF_EndSubMenu);
      UT_DEBUGMSG(("End Object ID %d \n",endObjectID));
      pFact->addNewLabel(NULL,endObjectID,NULL,NULL);
 // Create the Action that will be called.
      EV_Menu_Action* myEndObjectAction = new EV_Menu_Action(
							       endObjectID,          // id that the layout said we could use
	0,                      // no, we don't have a sub menu.
	0,                      // no, we raise a dialog.
	0,                      // no, we don't have a checkbox.
	0,                      // no radio buttons for me, thank you
	NULL,                   // name of callback function to call.
	NULL,                   // don't know/care what this is for
	NULL                    // don't know/care what this is for
        );


      pActionSet->addAction(myEndObjectAction);
    }

    for(int i = 0;i < frameCount;++i)
    {
        // Get the current frame that we're iterating through.
		XAP_Frame* pFrame = pApp->getFrame(i);
		pFrame->rebuildMenus();
    }
}

static void
AbiGOChart_removeFromMenus ()
{
  // First we need to get a pointer to the application itself.
  XAP_App *pApp = XAP_App::getApp();

  // remove the edit method
  EV_EditMethodContainer* pEMC = pApp->getEditMethodContainer() ;
  EV_EditMethod * pEM = ev_EditMethod_lookup ( "AbiGOChart_Create" ) ;
  pEMC->removeEditMethod ( pEM ) ;
  DELETEP( pEM ) ;

  // now remove crap from the menus
  int frameCount = pApp->getFrameCount();
  XAP_Menu_Factory * pFact = pApp->getMenuFactory();

  pFact->removeMenuItem("Main",NULL,AbiGOChart_MenuLabelInsert);
  for(int i = 0;i < frameCount;++i)
  {
      // Get the current frame that we're iterating through.
      XAP_Frame* pFrame = pApp->getFrame(i);
      pFrame->rebuildMenus();
  }
}
 

XAP_Dialog_MessageBox::tAnswer s_CouldNotLoadFileMessage(XAP_Frame * pFrame, const char * pNewFile, UT_Error errorCode)
{
	XAP_String_Id String_id;

	switch (errorCode)
	  {
	  case -301:
		String_id = AP_STRING_ID_MSG_IE_FileNotFound;
		break;
	  case -302:
		String_id = AP_STRING_ID_MSG_IE_NoMemory;
		break;

	  case -303:
		String_id = AP_STRING_ID_MSG_IE_UnsupportedType;
		//AP_STRING_ID_MSG_IE_UnknownType;
		break;

	  case -304:
		String_id = AP_STRING_ID_MSG_IE_BogusDocument;
		break;

	  case -305:
		String_id = AP_STRING_ID_MSG_IE_CouldNotOpen;
		break;

	  case -306:
		String_id = AP_STRING_ID_MSG_IE_CouldNotWrite;
		break;

	  case -307:
		String_id = AP_STRING_ID_MSG_IE_FakeType;
		break;

	  case -311:
		String_id = AP_STRING_ID_MSG_IE_UnsupportedType;
		break;

	  default:
		String_id = AP_STRING_ID_MSG_ImportError;
	  }

	return pFrame->showMessageBox(String_id,
									XAP_Dialog_MessageBox::b_O,
									XAP_Dialog_MessageBox::a_OK,
									pNewFile);
}

static bool s_AskForGOChartPathname(XAP_Frame * pFrame,
					   char ** ppPathname,
					   IEGraphicFileType * iegft)
{
	// raise the file-open dialog for inserting a MathML equation.
	// return a_OK or a_CANCEL depending on which button
	// the user hits.
	// return a pointer a UT_strdup()'d string containing the
	// pathname the user entered -- ownership of this goes
	// to the caller (so free it when you're done with it).

	UT_DEBUGMSG(("s_AskForGOChartPathname: frame %p\n",
				 pFrame));

	UT_return_val_if_fail (ppPathname, false);
	*ppPathname = NULL;

	pFrame->raise();

	XAP_DialogFactory * pDialogFactory
		= static_cast<XAP_DialogFactory *>(pFrame->getDialogFactory());

	XAP_Dialog_FileOpenSaveAs * pDialog
		= static_cast<XAP_Dialog_FileOpenSaveAs *>(pDialogFactory->requestDialog(XAP_DIALOG_ID_INSERTOBJECT));
	UT_return_val_if_fail (pDialog, false);

	pDialog->setCurrentPathname(NULL);
	pDialog->setSuggestFilename(false);

	// to fill the file types popup list, we need to convert AP-level
	// ImpGraphic descriptions, suffixes, and types into strings.

	UT_uint32 filterCount = IE_ImpGraphic::getImporterCount();

	const char ** szDescList = static_cast<const char **>(UT_calloc(filterCount + 1, sizeof(char *)));
	const char ** szSuffixList = static_cast<const char **>(UT_calloc(filterCount + 1, sizeof(char *)));
	IEGraphicFileType * nTypeList = (IEGraphicFileType *)
		 UT_calloc(filterCount + 1,	sizeof(IEGraphicFileType));
	UT_uint32 k = 0;

	while (IE_ImpGraphic::enumerateDlgLabels(k, &szDescList[k], &szSuffixList[k], &nTypeList[k]))
		k++;

	pDialog->setFileTypeList(szDescList, szSuffixList, static_cast<const UT_sint32 *>(nTypeList));
	if (iegft != NULL)
	  pDialog->setDefaultFileType(*iegft);
	pDialog->runModal(pFrame);

	XAP_Dialog_FileOpenSaveAs::tAnswer ans = pDialog->getAnswer();
	bool bOK = (ans == XAP_Dialog_FileOpenSaveAs::a_OK);

	if (bOK)
	{
		const char * szResultPathname = pDialog->getPathname();
		UT_DEBUGMSG(("OBJECT Path Name selected = %s \n",szResultPathname));
		if (szResultPathname && *szResultPathname)
			UT_cloneString(*ppPathname,szResultPathname);

		UT_sint32 type = pDialog->getFileType();

		// If the number is negative, it's a special type.
		// Some operating systems which depend solely on filename
		// suffixes to identify type (like Windows) will always
		// want auto-detection.
		if (type < 0)
			switch (type)
			{
			case XAP_DIALOG_FILEOPENSAVEAS_FILE_TYPE_AUTO:
				// do some automagical detecting
				*iegft = IEGFT_Unknown;
				break;
			default:
				// it returned a type we don't know how to handle
				UT_ASSERT_HARMLESS(UT_SHOULD_NOT_HAPPEN);
			}
		else
			*iegft = static_cast<IEGraphicFileType>(pDialog->getFileType());
	}

	FREEP(szDescList);
	FREEP(szSuffixList);
	FREEP(nTypeList);

	pDialogFactory->releaseDialog(pDialog);

	return bOK;
}

//
// AbiMathView_FileInsert
// -------------------
//   This is the function that we actually call to insert the MathML.
//
bool 
AbiGOChart_FileInsert(AV_View* v, EV_EditMethodCallData *d)
{
    // Get the current view that the user is in.
    XAP_Frame *pFrame = XAP_App::getApp()->getLastFocussedFrame();
    FV_View* pView = static_cast<FV_View*>(pFrame->getCurrentView());
    PD_Document * pDoc = static_cast<PD_Document *>(pFrame->getCurrentDoc());
    char* pNewFile = NULL;


    IEGraphicFileType iegft = IEGFT_Unknown;
    bool bOK = s_AskForGOChartPathname(pFrame,&pNewFile,&iegft);
	
    if (!bOK || !pNewFile)
    {
      UT_DEBUGMSG(("ARRG! bOK = %d pNewFile = %x \n",bOK,pNewFile));
      return false;
    }
    UT_UTF8String sNewFile = pNewFile;

    // we own storage for pNewFile and must free it.
    FREEP(pNewFile);


    UT_DEBUGMSG(("fileInsertObject: loading [%s]\n",sNewFile.utf8_str()));
   
    IE_Imp_Object * pImpObject = new IE_Imp_Object(pDoc);
    UT_Error errorCode = pImpObject->importFile(sNewFile.utf8_str());

    if(errorCode != UT_OK)
    {
      s_CouldNotLoadFileMessage(pFrame, sNewFile.utf8_str(), errorCode);
      DELETEP(pImpObject);
      return false;
    }


// Insert the object

    const char* mimetypeGOChart = "application/x-goffice-graph";

    const char * szProps = "embed-type: GOChart";
    UT_ByteBuf * pBuf = pImpObject->getByteBuf();
    pView->cmdInsertEmbed(pBuf,pView->getPoint(),mimetypeGOChart,szProps);

    DELETEP(pImpObject);

    return true;
}

//
// AbiMathView_FileInsert
// -------------------
//   This is the function that we actually call to create the Chart.
//

static void
graph_user_config_free_data (gpointer data,
					  GClosure *closure)
{
	closure->data = NULL;
}

static void
cb_update_graph (GogGraph *graph, gpointer data)
{
	g_return_if_fail (IS_GOG_GRAPH (graph));
	AbiControlGUI *acg = ABI_CONTROL_GUI (data);
	acg->pView->SetGuru (NULL);
	AbiGO_LocaleTransactor tn(LC_NUMERIC, "C");
	AbiGO_LocaleTransactor tm(LC_MONETARY, "C");
	GsfOutput* output = gsf_output_memory_new ();
	GsfXMLOut* xml = gsf_xml_out_new (output);
	gog_object_write_xml_sax(GOG_OBJECT (graph), xml);
	UT_Byte const *bytes = gsf_output_memory_get_bytes (GSF_OUTPUT_MEMORY (output));
	UT_ByteBuf myByteBuf;
	myByteBuf.append(bytes, gsf_output_size (output));
	FV_View* pView = acg->pView->getRun ()->getBlock ()->getView ();

	const char* mimetypeGOChart = "application/x-goffice-graph";
	const char * szProps="embed-type: GOChart";
	UT_DEBUGMSG(("Doing Embed Update from GOG callback \n"));
	pView->cmdUpdateEmbed(acg->pView->getRun (), &myByteBuf,mimetypeGOChart,szProps);

	g_object_unref (xml);
	g_object_unref (output);
	g_object_unref (acg);
}

static void
guru_destroyed_cb (GOChartView *pView)
{
	pView->SetGuru (NULL);
}

bool 
AbiGOChart_Create(AV_View* v, EV_EditMethodCallData *d)
{
    XAP_Frame *pFrame = XAP_App::getApp()->getLastFocussedFrame();
	XAP_UnixFrameImpl *pFrameImpl = static_cast<XAP_UnixFrameImpl*>(pFrame->getFrameImpl());
    FV_View* pView = static_cast<FV_View*>(pFrame->getCurrentView());
	UT_ByteBuf myByteBuf;
	static unsigned id = 0;

	AbiControlGUI *acg = ABI_CONTROL_GUI (g_object_new (ABI_CONTROL_GUI_TYPE, NULL));
	
	acg->pDoc = static_cast<PD_Document *>(pFrame->getCurrentDoc());

	GogGraph *graph = (GogGraph *) g_object_new (GOG_GRAPH_TYPE, NULL);
	/* by default, create one chart and add it to the graph */
	gog_object_add_by_name (GOG_OBJECT (graph), "Chart", NULL);
	GsfOutput* output = gsf_output_memory_new ();
	GsfXMLOut* xml = gsf_xml_out_new (output);
	{
		AbiGO_LocaleTransactor tn(LC_NUMERIC, "C");
		AbiGO_LocaleTransactor tm(LC_NUMERIC, "C");
		gog_object_write_xml_sax (GOG_OBJECT (graph), xml);
	}
	UT_Byte const *bytes = gsf_output_memory_get_bytes (GSF_OUTPUT_MEMORY (output));
	myByteBuf.append(bytes, gsf_output_size (output));

	const char* mimetypeGOChart = "application/x-goffice-graph";
	const char * szProps="embed-type: GOChart";
	PT_DocPosition pos = pView->getPoint();
	pView->cmdInsertEmbed(&myByteBuf,pView->getPoint(),mimetypeGOChart,szProps);
	pView->cmdSelect(pos,pos+1);
	acg->pView = GR_GOChartManager::last_created_view;
	GtkWidget *dialog = gog_guru (graph, GOG_DATA_ALLOCATOR (acg),
		       NULL /*GO_CMD_CONTEXT (wbcg)*/, GTK_WINDOW(pFrameImpl->getTopLevelWindow()),
		       g_cclosure_new (G_CALLBACK (cb_update_graph), acg,
					(GClosureNotify) graph_user_config_free_data));
	acg->pView->SetGuru (dialog);
	g_signal_connect_swapped (G_OBJECT (dialog), "destroy", G_CALLBACK (guru_destroyed_cb), acg->pView);

	g_object_unref (xml);
	g_object_unref (output);
	g_object_unref (G_OBJECT (graph));

	return true;
}

GR_AbiGOChartItems::GR_AbiGOChartItems(void):
  m_iAPI(0),
  m_bHasSnapshot(false)
{
}

GR_AbiGOChartItems::~GR_AbiGOChartItems(void)
{
}


GR_GOChartManager::GR_GOChartManager(GR_Graphics* pG)
  : GR_EmbedManager(pG), 
    m_CurrentUID(-1),
    m_pDoc(NULL)
{
  m_vecGOChartView.clear();
  m_vecItems.clear();
}

GR_GOChartManager::~GR_GOChartManager()
{ 
     UT_VECTOR_PURGEALL(GR_AbiGOChartItems *,m_vecItems);
     UT_VECTOR_PURGEALL(GOChartView *,m_vecGOChartView);
}

GR_EmbedManager * GR_GOChartManager::create(GR_Graphics * pG)
{
  return static_cast<GR_EmbedManager *>(new GR_GOChartManager(pG));
}

const char * GR_GOChartManager::getObjectType(void) const
{
  return "GOChart";
}

GOChartView * GR_GOChartManager::last_created_view = NULL;

void GR_GOChartManager::initialize(void)
{
  // Load the GOChart library
}

/*!
 * Create a specific GOChart view and associate it with a UID.
 */ 
UT_sint32  GR_GOChartManager::_makeGOChartView(void)
{
     last_created_view = new GOChartView(this);
     m_vecGOChartView.addItem(last_created_view);
     return static_cast<UT_sint32>(m_vecGOChartView.getItemCount()-1);
}

void GR_GOChartManager::_loadGOChartXML(UT_sint32 uid, UT_UTF8String & sGOChartBuf)
{
  GOChartView * pGOChartView = m_vecGOChartView.getNthItem(uid);
  UT_return_if_fail(pGOChartView);
  pGOChartView->loadBuffer(sGOChartBuf);
}

void GR_GOChartManager::setDefaultFontSize(UT_sint32 uid, UT_sint32 iSize)
{
  GOChartView * pGOChartView = m_vecGOChartView.getNthItem(uid);
  UT_return_if_fail(pGOChartView);
  pGOChartView->setDefaultFontSize(iSize);
}

UT_sint32 GR_GOChartManager::makeEmbedView(AD_Document * pDoc, UT_uint32 api, const char * szDataID)
{
  if(m_pDoc == NULL)
  {
    m_pDoc = static_cast<PD_Document *>(pDoc);
  }
  else
  {
    UT_ASSERT(m_pDoc == static_cast<PD_Document *>(pDoc));
  }
  UT_sint32 iNew = _makeGOChartView();
  GR_AbiGOChartItems * pItem = new GR_AbiGOChartItems();
  pItem->m_iAPI = api;
  pItem->m_bHasSnapshot = false;
  m_vecItems.addItem(pItem);
  UT_ASSERT(static_cast<UT_sint32>(m_vecItems.getItemCount()) == (iNew+1));
  return iNew;
}

void GR_GOChartManager::makeSnapShot(UT_sint32 uid, UT_Rect & rec)
{
  if(!getGraphics()->queryProperties(GR_Graphics::DGP_SCREEN))
    {
      return;
    }
  GR_AbiGOChartItems * pItem = m_vecItems.getNthItem(uid);
  UT_return_if_fail(pItem);  
  const PP_AttrProp * pSpanAP = NULL;
  PT_AttrPropIndex api = pItem->m_iAPI;
  /* bool b = */ m_pDoc->getAttrProp(api, &pSpanAP);
  const char * pszDataID = NULL;
  bool bFoundDataID = pSpanAP->getAttribute("dataid", pszDataID);
  if(pItem->m_bHasSnapshot)
    {
       updatePNGSnapshot(static_cast<AD_Document *>(m_pDoc),rec,pszDataID);
    }
  else
    {
       createPNGSnapshot(static_cast<AD_Document *>(m_pDoc),rec,pszDataID);
       pItem->m_bHasSnapshot = true;
    }
}

bool GR_GOChartManager::isDefault(void)
{
  return false;
}


bool GR_GOChartManager::createPNGSnapshot(AD_Document * pDoc, UT_Rect & rec,
					   const char * szDataID)
{
  if(isDefault())
  {
    return false;
  }
  if((rec.width == 0) || (rec.height ==0))
  {
    return false;
  }
  GR_Painter painter(getGraphics());
  GR_Image * pImage = painter.genImageFromRectangle(rec);
  UT_ByteBuf * pBuf = NULL;
  pImage->convertToBuffer(&pBuf);
  UT_UTF8String sID = "snapshot-png-";
  sID += szDataID;
  const char* mimetypePNG = NULL;
  mimetypePNG = UT_strdup("image/png");
  pDoc->createDataItem(sID.utf8_str(),false,reinterpret_cast< const UT_ByteBuf *>(pBuf),mimetypePNG,NULL);
  delete pBuf;
  delete pImage;
  return true;
}


bool GR_GOChartManager::updatePNGSnapshot(AD_Document * pDoc, UT_Rect & rec,
					   const char * szDataID)
{
  if(isDefault())
  {
    return false;
  }
  GR_Painter painter(getGraphics());
  GR_Image * pImage = painter.genImageFromRectangle(rec);
  UT_ByteBuf * pBuf = NULL;
  pImage->convertToBuffer(&pBuf);
  UT_UTF8String sID = "snapshot-png-";
  sID += szDataID;
   pDoc->replaceDataItem(sID.utf8_str(),reinterpret_cast< const UT_ByteBuf *>(pBuf));
  delete pBuf;
  delete pImage;
  return true;
}

bool GR_GOChartManager::modify(UT_sint32 uid)
{
  GOChartView * pGOChartView = m_vecGOChartView.getNthItem(uid);
  pGOChartView->modify();
  return false;
}

bool  GR_GOChartManager::isEdittable(UT_sint32 uid)
{
  return true;
}

void GR_GOChartManager::initializeEmbedView(UT_sint32 uid)
{
  // FIXME write code for this.
}

void GR_GOChartManager::loadEmbedData(UT_sint32 uid)
{
  GOChartView * pGOChartView = m_vecGOChartView.getNthItem(uid);
  UT_return_if_fail(pGOChartView);
  const PP_AttrProp * pSpanAP = NULL;
  GR_AbiGOChartItems * pItem = m_vecItems.getNthItem(uid);
  UT_return_if_fail(pItem);  
  PT_AttrPropIndex api = pItem->m_iAPI;
  /* bool b = */ m_pDoc->getAttrProp(api, &pSpanAP);
  const char * pszDataID = NULL;
  bool bFoundDataID = pSpanAP->getAttribute("dataid", pszDataID);
  UT_UTF8String sGOChartXML;
  if (bFoundDataID && pszDataID)
  {
       const UT_ByteBuf * pByteBuf = NULL;
       bFoundDataID = m_pDoc->getDataItemDataByName(pszDataID, 
						    const_cast<const UT_ByteBuf **>(&pByteBuf),
						    NULL, NULL);

       UT_UCS4_mbtowc myWC;
       sGOChartXML.appendBuf( *pByteBuf, myWC);
  }
 UT_return_if_fail(bFoundDataID);
 UT_return_if_fail(pszDataID);
  UT_DEBUGMSG(("GO Chart string is... \n %s \n",sGOChartXML.utf8_str()));
  _loadGOChartXML(uid, sGOChartXML);
}

UT_sint32 GR_GOChartManager::getWidth(UT_sint32 uid)
{
    // FIXME write code this draws a square
    return 5000;
}


UT_sint32 GR_GOChartManager::getAscent(UT_sint32 uid)
{
  // FIXME write code this draws a square
  return 5000;
}


UT_sint32 GR_GOChartManager::getDescent(UT_sint32 uid)
{
  // FIXME write code
 return 0;

}

void GR_GOChartManager::setColor(UT_sint32 uid, UT_RGBColor c)
{
  // FIXME write code
}

/*!
 * This method renders the GOChart identified by uid onto the screen
 * rectangle given by rec
 */
void GR_GOChartManager::render(UT_sint32 uid, UT_Rect & rec)
{
  // FIXME write code
  GOChartView * pGOChartView = m_vecGOChartView.getNthItem(uid);
  UT_return_if_fail(pGOChartView);
  pGOChartView->render(rec);
}

void GR_GOChartManager::releaseEmbedView(UT_sint32 uid)
{
  GOChartView * pGOChartView = m_vecGOChartView.getNthItem(uid);
  delete pGOChartView;
  m_vecGOChartView.setNthItem(uid,NULL,NULL); //NULL it out so we don't affect the other uid's
}

bool GR_GOChartManager::convert(UT_uint32 iConType, UT_ByteBuf & From, UT_ByteBuf & To)
{
  return false;
}

void GR_GOChartManager::setRun(UT_sint32 uid, fp_Run *pRun)
{
	GOChartView * pGOChartView = m_vecGOChartView.getNthItem(uid);
	pGOChartView->SetRun (pRun);
}

GOChartView::GOChartView(GR_GOChartManager * pGOMan): m_pGOMan(pGOMan)
{
	m_Graph = NULL;
	m_Image = NULL;
	m_Renderer = GOG_RENDERER (g_object_new (GOG_RENDERER_PIXBUF_TYPE, NULL));
	width = height = 0;
	m_Guru = NULL;
}

GOChartView::~GOChartView(void)
{
	g_object_unref (m_Renderer);
	if (m_Graph)
		g_object_unref (m_Graph);
	if (m_Image)
		delete m_Image;
	if (m_Guru)
		gtk_widget_destroy (m_Guru);
}

void GOChartView::render(UT_Rect & rec)
{
	if (m_pGOMan->getGraphics()->queryProperties(GR_Graphics::DGP_PAPER))
	{
	        XAP_UnixGnomePrintGraphics * pUGG = static_cast< XAP_UnixGnomePrintGraphics *>(m_pGOMan->getGraphics());
		GnomePrintContext *ctx = pUGG->getGnomePrintContext();
		UT_sint32 myWidth = pUGG->tdu(rec.width);
		UT_sint32 myHeight = pUGG->tdu(rec.height);
		UT_sint32 x = pUGG->tdu(rec.left);
		UT_sint32 y = pUGG->tdu(rec.top);
		//
		// gnome_print places y = 0 at the bottom of the page
		// and as y increases, it gets placed further from the bottom.
		//
		// This is the opposite of AbiWord where y = 0 is the top
		// and y > 0 is further from the top.
		//
		// scale_ydir fixes this (and gets the landscape/portrait right 
		// too).
		//
		y = pUGG->scale_ydir(y);
		gnome_print_gsave (ctx);

		gnome_print_translate (ctx, x, y+myHeight);
		gog_graph_print_to_gnome_print(m_Graph,ctx,myWidth,myHeight);
		gnome_print_grestore(ctx);
	}
	else 
	{
		GR_Graphics *pUGG = m_pGOMan->getGraphics();
		UT_sint32 _width = pUGG->tdu(rec.width);
		UT_sint32 _height = pUGG->tdu(rec.height);
		UT_sint32 x = pUGG->tdu(rec.left);
		UT_sint32 y = pUGG->tdu(rec.top);
		if (_width != width || _height != height)
		{
			GdkPixbuf *pixbuf;
			width = _width;
			height = _height;
			gog_renderer_pixbuf_update (GOG_RENDERER_PIXBUF (m_Renderer), _width, _height, 1.0);	
			if (m_Image)
				delete m_Image;
			pixbuf = gog_renderer_pixbuf_get (GOG_RENDERER_PIXBUF (m_Renderer));
			m_Image = new GR_UnixImage(NULL, pixbuf);
			g_object_ref(pixbuf);
			m_Image->scaleImageTo(m_pGOMan->getGraphics(),rec);
		}
		GR_Painter painter(m_pGOMan->getGraphics());
		painter.drawImage (m_Image, rec.left, rec.top - rec.height);
	}
}

void GOChartView::loadBuffer(UT_UTF8String & sGOChartXML)
{
	if (m_Graph)
		g_object_unref (m_Graph);
	AbiGO_LocaleTransactor tn(LC_NUMERIC, "C");
	AbiGO_LocaleTransactor tm(LC_MONETARY, "C");
	xmlDocPtr xml = xmlParseMemory((const char*)sGOChartXML.utf8_str(), sGOChartXML.byteLength());
	m_Graph = GOG_GRAPH (gog_object_new_from_xml (NULL, xml->children));
	if (m_Graph)
		g_object_set (G_OBJECT (m_Renderer), "model", m_Graph, NULL);
	width = height = 0; // force pixbuf update
}


void GOChartView::setDefaultFontSize( UT_sint32 iSize)
{

}

void GOChartView::modify()
{
    XAP_Frame *pFrame = XAP_App::getApp()->getLastFocussedFrame();
	XAP_UnixFrameImpl *pFrameImpl = static_cast<XAP_UnixFrameImpl*>(pFrame->getFrameImpl());
	AbiControlGUI *acg = ABI_CONTROL_GUI (g_object_new (ABI_CONTROL_GUI_TYPE, NULL));
	
	acg->pDoc = static_cast<PD_Document *>(pFrame->getCurrentDoc());
	acg->pView = this;

	GtkWidget *dialog = gog_guru (m_Graph, GOG_DATA_ALLOCATOR (acg),
		       NULL /*GO_CMD_CONTEXT (wbcg)*/, GTK_WINDOW(pFrameImpl->getTopLevelWindow()),
		       g_cclosure_new (G_CALLBACK (cb_update_graph), acg,
					(GClosureNotify) graph_user_config_free_data));
	acg->pView->SetGuru (dialog);
	g_signal_connect_swapped (G_OBJECT (dialog), "destroy", G_CALLBACK (guru_destroyed_cb), acg->pView);
}

static UT_uint32 GOChartManagerUID = 0; 
static GR_GOChartManager  *pGOChartManager = NULL;

// we use a reference-counted sniffer
static IE_Imp_Object_Sniffer  * m_impSniffer = 0;

ABI_PLUGIN_DECLARE(AbiGOChart)

// -----------------------------------------------------------------------
//
//      Abiword Plugin Interface 
//
// -----------------------------------------------------------------------

  
ABI_FAR_CALL
int abi_plugin_register (XAP_ModuleInfo * mi)
{
    mi->name = "AbiGOChart";
    mi->desc = "The plugin enables Gnome Office Charts to be displayed in AbiWord";
    mi->version = ABI_VERSION_STRING;
    mi->author = "Martin Sevior <msevior@physics.unimelb.edu.au>";
    mi->usage = "No Usage";

    // Add to AbiWord's plugin importers
    m_impSniffer = new IE_Imp_Object_Sniffer();
    IE_Imp::registerImporter (m_impSniffer);    

    // Add to AbiWord's plugin listeners
    XAP_App * pApp = XAP_App::getApp();	
    pGOChartManager = new GR_GOChartManager(NULL);
    GOChartManagerUID = pApp->registerEmbeddable(pGOChartManager);
	// the message below makes valgrind scream because there is only one parameter where
	// 2 are expected. disabled.
    xxx_UT_DEBUGMSG(("Class  %x created! Listener Id %d \n", GOChartManagerUID));
   // Add to AbiWord's menus.
    AbiGOChart_addToMenus();
 	/* Initialize libgoffice */
	libgoffice_init ();
	/* Initialize plugins manager */
	go_plugins_init (NULL, NULL, NULL, NULL, TRUE, GO_PLUGIN_LOADER_MODULE_TYPE);
	/* Ensure some types are created */
 	GO_DATA_SCALAR_STR_TYPE;
	GO_DATA_VECTOR_STR_TYPE;
 	GO_DATA_SCALAR_VAL_TYPE;
	GO_DATA_VECTOR_VAL_TYPE;
 	GO_DATA_MATRIX_VAL_TYPE;
	/* the resolution of symbols in libgoffice must be forced because when
	creating the guru window, libglade needs foo_canvas_new. There might
	be a better solution..., I could not find one */
	g_module_close (g_module_open ("libgoffice-1", (GModuleFlags)0));
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

    IE_Imp::unregisterImporter (m_impSniffer);

    if (!m_impSniffer->unref())
    {
         m_impSniffer = 0;
    }

    XAP_App * pApp = XAP_App::getApp();
    pApp->unRegisterEmbeddable(GOChartManagerUID);
    DELETEP(pGOChartManager);
    AbiGOChart_removeFromMenus();

    return 1;
}


ABI_FAR_CALL
int abi_plugin_supports_version (UT_uint32 major, UT_uint32 minor, UT_uint32 release)
{
    return 1; 
}
