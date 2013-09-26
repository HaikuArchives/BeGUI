//simpleWindow.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "uInt32Control.h"
#include "floatControl.h"
#include "myButton.h"
#include "myPopUpMenu.h"
#include "myPopUpMenuData.h"
#include "textItem.h"
#include "myTextView.h"
#include "myListView.h"
#include "myCheckBox.h"
#include "myStringDrawer.h"
#include "stringControl.h"
#include "myPictureButton.h"
#include "myColorControl.h"
#include "myRadioView.h"
#include "myRadioViewData.h"
#include "myStatusBar.h"
#include "warning.h"
#include "Preferences.h"
#include "myroColour.h"
#include "colorWell.h"
#include "mySpacer.h"
#include "mySlider.h"
#include "myPreferences.h"
#include "layoutMatrix.h"
#include "scrollView.h"
#include "simpleWindow.h"
#include "stringBoundsBox.h"

//ctor 
SimpleWindow	::	SimpleWindow(	BRect paramBound,
									const char * paramWindowTitle,
									const char * paramNamePrefFrame,
									PreferenceSet *	paramPreferenceSet,
									bool paramHasMenu,
									bool paramShowInInit)
			: 
				BWindow(	paramBound, 
							paramWindowTitle,
							B_TITLED_WINDOW, 
							0), 
				mpNamePrefFrame(paramNamePrefFrame),
				mpPreferenceSet(paramPreferenceSet),
				mbHasMenu(paramHasMenu),
				mbShowInInit(paramShowInInit),
				mpMenuBar(	new BMenuBar(	BRect(0, 0, 1000, 15), "SimpleWindowMenuBar"))
{
	BView	bv(BRect(0, 0, 32, 32), NULL, B_FOLLOW_NONE, 0);
	if (paramWindowTitle)
	{
		float leftOffset;
		float baseline;
		float width;
		float height;
		if (!StringBoundsBox(	paramWindowTitle,
								&width,
								&height,
								&leftOffset,
								&baseline,
								&BFont(be_plain_font)))
		{
			throw;
		}
		mfTitleWidth = width + 64/*width of close + zoom gadgets + padding*/;
	}
	else
	{
		mfTitleWidth = 0;
	}
}//end


//dtor
SimpleWindow	::	~SimpleWindow() 
{
	//leaving blank
}//end


bool
SimpleWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	if (mpPreferenceSet->SetData(	mpNamePrefFrame, 
									&frame, 
									sizeof(frame), 
									B_RECT_TYPE))
	{
		warning(myPrefs->PrefNoSetGutFrame);
	}
	return true;
}//end


//do all the real work of construction so we can Fail gracefully
bool 
SimpleWindow	::	Initialize(	void)
{
	if (mbHasMenu)
	{
		AddChild(mpMenuBar);
		mfMenuBarHeight = mpMenuBar->Bounds().Height();
	}
	else
	{
		delete mpMenuBar;
		mfMenuBarHeight = 0;
	}
	if (mbShowInInit)
	{
		Show();
	}
	return true;
}//end


void
SimpleWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	switch(paramMessage->what) 
	{
		case ABOUT_SIMPLEWINDOW:	
		{
			warning(myPrefs->AboutSimpleWindowMsg);//should never get here!
		break;
		}
		default:
			BWindow::MessageReceived(paramMessage);
		break;
	}
}//end