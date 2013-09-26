//PrefsEDgarApp.cpp

#include "commonHeaders.h"
#include "DtinySnooze.h"
#include "DnumSpecificWindows.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "warning.h"
#include "scrollingWindow.h"
#include "simpleWindow.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "myButton.h"
#include "myCheckBox.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "myPopUpMenu.h"
#include "myPictureButton.h"
#include "myColorControl.h"
#include "myStatusBar.h"
#include "myRadioView.h"
#include "myTextView.h"
#include "mySpacer.h"
#include "DmenuMsg.h"
#include "DcolorControlMessages.h"
#include "prefPanelWindow.h"
#define NOTX_MYAPP 1
#include "PrefsEDgarApp.h"
#include "PrefsEDgarWindow.h"
#include "smallerRect.h"

bool
MyApp	::	QuitRequested(	void) 
{
	if (mpPrefsEDgarWindow)
	{
		mpPrefsEDgarWindow->PostMessage(B_QUIT_REQUESTED);
		while (mpPrefsEDgarWindow)
		{
			snooze(TINYSNOOZE);
		}
	}
	return(BApplication::QuitRequested());
}//end


void 
MyApp	::	ReadyToRun(	void) 
{
	OpenPrefsEDgarWindow();
}//end


void 
MyApp	::	MessageReceived(	BMessage *	message) 
{
	switch(message->what)
	{
		case REOPEN:
		{
			OpenPrefsEDgarWindow();
			if (myPrefs->pPrefPanelWindow)
			{
				int timeOut = 0;
				while (myPrefs->pPrefPanelWindow && (timeOut < 50)) 
				{
					myPrefs->pPrefPanelWindow->PostMessage(B_QUIT_REQUESTED);
					snooze(TINYSNOOZE);
					timeOut++;
				}
				if (!myPrefs->pPrefPanelWindow) 
				{
					myPrefs->OpenPreferencesPanel();
				}
			}
			myPrefs->mbPrefChangesMade = false;
		break;
		}
//		case 0:	//I am wondering about this
//				//it only shows up when app is launched from 
//				//tracker and resources are present in the file
//				//when run via double-click on the app icon I get a message here
//				//with a message->what == zero
//			warning("got unexpected zero msg in app\n");
//		break;
//		default:
//			//I don't expect any msgs here
//			//warning("got unexpected msg in app\n");
//		break;
	}
}//end