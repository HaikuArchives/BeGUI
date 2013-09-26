//PrefsEDgarAppOpenWindows.cpp

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
#include "PrefsEDgarApp.h"
#include "PrefsEDgarWindow.h"
#include "smallerRect.h"


void
MyApp	::	OpenPrefsEDgarWindow(	void)
{
	int timeOut = 0;
	while (	mpPrefsEDgarWindow 
			&& 
			(timeOut < 50)
		  ) 
	{
		if (!mpPrefsEDgarWindow->PostMessage(B_QUIT_REQUESTED))
		{
			snooze(TINYSNOOZE);
			timeOut++;
		}
	}
	if (!mpPrefsEDgarWindow) 
	{
		try 
		{
			mpPrefsEDgarWindow = new PrefsEDgarWindow();
			mpPrefsEDgarWindow->Initialize();
		}
		catch (...)
		{
			warning(CaughtPrefsEDgarWindowCTOR);
			PostMessage(B_QUIT_REQUESTED);
		}
	}
	else
	{
		warning(myPrefs->FailReopen);
		PostMessage(B_QUIT_REQUESTED);
	}
}//end