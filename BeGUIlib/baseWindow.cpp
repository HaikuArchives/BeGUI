//baseWindow.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "gadgetBase.h"
#include "int8Gadget.h"
#include "uInt8Gadget.h"
#include "int16Gadget.h"
#include "uInt16Gadget.h"
#include "int32Gadget.h"
#include "uInt32Gadget.h"
#include "int64Gadget.h"
#include "uInt64Gadget.h"
#include "floatGadget.h"
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
#include "myStringView.h"
#include "stringControl.h"
#include "stringGadget.h"
#include "myPictureButton.h"
#include "myColorControl.h"
#include "myRadioView.h"
#include "myRadioViewData.h"
#include "myStatusBar.h"
#include "mySlider.h"
#include "warning.h"
#include "Preferences.h"
#include "myroColour.h"
#include "colorWell.h"
#include "mySpacer.h"
#include "myPreferences.h"
#include "baseView.h"
#include "baseWindow.h"
#include "layoutMatrix.h"
#include "addChildrenToBase.h"
#include "stringBoundsBox.h"

//ctor 
BaseWindow	::	BaseWindow(	BRect paramBound,
										const char * paramWindowTitle,
										const char * paramBaseViewName,
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
				mpBaseViewName(paramBaseViewName),
				mpLayoutMatrixList(new BList()),
				mpPreferenceSet(paramPreferenceSet),
				mbHasMenu(paramHasMenu),
				mbShowInInit(paramShowInInit),
				mpMenuBar(	new BMenuBar(	BRect(0, 0, 1000, 15), "BaseWindowMenuBar")),
				mpBaseView(NULL)
{
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
BaseWindow	::	~BaseWindow() 
{
	//leaving blank
}//end

//do all the real work of construction so we can fail gracefully
bool 
BaseWindow	::	Initialize(	void) 
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
	float maxRight = MIN_BASEWINDOW_WIDTH;
	float maxBottom = MIN_BASEWINDOW_HEIGHT;
	LayoutMatrix * tempLayoutMatrix;
	int32 numItems = mpLayoutMatrixList->CountItems();
	if (numItems)
	{
		tempLayoutMatrix = (LayoutMatrix *)mpLayoutMatrixList->ItemAt(0);
		maxRight = tempLayoutMatrix->mfRight;
		maxBottom = tempLayoutMatrix->mfBottom;
		for (	int32 i = 1;
				i < numItems;
				i++)
		{
			tempLayoutMatrix = (LayoutMatrix *)mpLayoutMatrixList->ItemAt(i);//dynamic cast??
			if (tempLayoutMatrix->mfRight > maxRight)
			{
				maxRight = tempLayoutMatrix->mfRight;
			}
			if (tempLayoutMatrix->mfBottom > maxBottom)
			{
				maxBottom = tempLayoutMatrix->mfBottom;
			}
		}
	}
	maxRight += MATRIXHORIZONTALOFFSETBASE;
	if (maxRight < mfTitleWidth)
	{
		maxRight = mfTitleWidth;
	}
	maxBottom += (2 * MATRIXVERTICALOFFSETBASE);
	//gives a bit of pad spacing between the items and the view's right & lower edges
	
	//insure the widow is appropriately sized--as small as
	//needed, or if need be (underlaying view larger than screen
	//resolution) as large as will fit on the screen nicely
	BRect	screenResolutionRect;
	{
		BScreen	screen(B_MAIN_SCREEN_ID);
		if(!screen.IsValid()) 
		{
			warning(myPrefs->ScreenNotValid);
			return false;
		}
		screenResolutionRect = screen.Frame();
	}
	float horizFudge = 9;//so our window nicely fits inside screen
	float vertFudge = 8;//so our window nicely fits inside screen
	float newWindowWidth = screenResolutionRect.IntegerWidth() - (B_V_SCROLL_BAR_WIDTH + horizFudge);
	if (maxRight < newWindowWidth)
	{
		newWindowWidth = maxRight;
	}
	float newWindowHeight = screenResolutionRect.IntegerHeight() - (B_H_SCROLL_BAR_HEIGHT + MATRIXVERTICALOFFSETBASE + mfMenuBarHeight + vertFudge);
	if (maxBottom < newWindowHeight)
	{
		newWindowHeight = maxBottom;
	}
	ResizeTo(	newWindowWidth, 
				newWindowHeight + mfMenuBarHeight);
	try 
	{
		//this is the view into which we will place our gadgets
		//notice the "mfMenuBarHeight + 1", in the second element
		mpBaseView = new BaseView(	BRect(	0, 
									mfMenuBarHeight + 1,
									maxRight,
									maxBottom + mfMenuBarHeight - 1),
									mpBaseViewName);
		mpBaseView->SetFont(myPrefs->GetPreferredFont());
	}
	catch(...) 
	{
		warning(myPrefs->FailMemory);
		return false;
	}
	AddChild(mpBaseView);
	AddChildrenToBase(	mpLayoutMatrixList,
						(BView *)mpBaseView,
						numItems,
						mpBaseView->mpStringViewList,
						mpBaseView->mpTextItemList,
						this);
	if (mbShowInInit)
	{
		Show();
	}
	return true;
}//end


bool
BaseWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	if (mpPreferenceSet->SetData(	mpNamePrefFrame, 
									&frame, 
									sizeof(frame), 
									B_RECT_TYPE))
	{
		warning(myPrefs->PrefNoSetBaseFrame);
	}
	return true;
}//end


void
BaseWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	switch(paramMessage->what) 
	{
		case ABOUT_BASEWINDOW:	
		{
			warning(myPrefs->AboutBaseMsg);//should never get here!
		break;
		}
		default:
			BWindow::MessageReceived(paramMessage);
		break;
	}
}//end


void
BaseWindow	::	AddToLayoutMatrixList(	LayoutMatrix * paramLayoutMatrix)
{
	mpLayoutMatrixList->AddItem((void *)paramLayoutMatrix);
}//end