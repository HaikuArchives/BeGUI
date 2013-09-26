//scrolling pref window

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DmenuMsg.h"
#include "DnumSpecificWindows.h"
#include "textItem.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "myStringDrawer.h"
#include "warning.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myCheckBox.h"
#include "scrollingWindow.h"
#include "prefPanelWindow.h"
#include "fontPrefWindow.h"
#include "fontDisplayWindow.h"
#include "verify.h"
#include "myPreferences.h"

//ctor
FontDisplayWindow	::	FontDisplayWindow(	BRect paramBound,
											const char * paramWindow,
											const char * paramScrollViewName,
											const char * paramNamePrefFrame,
											const char * paramPutString)
			: 
				ScrollingWindow(	paramBound, 
									paramWindow, 
									paramScrollViewName,
									paramNamePrefFrame,
									myPrefs->mpPreferenceSet,
									true,
									false),
				mpPutString(paramPutString)
{
	sem_id calc_sem;
	if ((calc_sem = create_sem(1, "calc_sem")) < B_NO_ERROR)
	{
		warning(myPrefs->FailCreateSemaphore);
		return;
	}
	acquire_sem(calc_sem);
	try 
	{
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		LayoutMatrix *	pholdStringDrawerLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		MyStringDrawer * pMyStringDrawer = new MyStringDrawer(	"displayFontMyStringDrawer", 
																mpPutString, 
																pholdStringDrawerLayoutMatrix);
///////////////////////////////////////////////////////////////////////////////////////////////////////
		release_sem(calc_sem);
		pholdStringDrawerLayoutMatrix->Calc(	MATRIXHORIZONTALOFFSET, 
												MATRIXVERTICALOFFSET, 
												calc_sem);
	}
	catch (...)
	{
		release_sem(calc_sem);
		throw;
	}
	try 
	{
		BMenuItem *	menuItem;
		BMenu * appMenu = new BMenu(myPrefs->AppMenuLabel);
		menuItem = new BMenuItem(	myPrefs->AboutMenuLabel, 
									new BMessage(ABOUT_FONTDISPLAYWINDOW));
		appMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->CloseWindow, 
									new BMessage(B_QUIT_REQUESTED));
		appMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->QuitMenuLabel, 
									new BMessage(QUIT_APP));
		appMenu->AddItem(menuItem);
		mpMenuBar->AddItem(appMenu);
	}
	catch(...) 
	{
		throw;
	}
}//end


//dtor
FontDisplayWindow	::	~FontDisplayWindow() 
{
	if (myPrefs->pPrefPanelWindow)
	{
		if (myPrefs->pPrefPanelWindow->mpFontPrefWindow)
		{
			((FontPrefWindow *)(myPrefs->pPrefPanelWindow->mpFontPrefWindow))->mpFontDisplayWindow = NULL;
		}
	}
}//end


void
FontDisplayWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	switch(paramMessage->what) 
	{
		
		case ABOUT_FONTDISPLAYWINDOW:	
		{
			warning(myPrefs->AboutFontDisplayWindow);
		break;
		}
		case QUIT_APP:
			if (Verify(myPrefs->ReallyQuitApp))
			{
				be_app->PostMessage(B_QUIT_REQUESTED);
			}
		break;
		default:
			ScrollingWindow::MessageReceived(paramMessage);
		break;
	}
}//end


bool
FontDisplayWindow	::	QuitRequested() 
{
	BRect frame = Frame();
	myPrefs->SetPreferredFontDisplayWindowRect(frame);
	return(ScrollingWindow::QuitRequested());
}//end
