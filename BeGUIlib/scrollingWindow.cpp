//scrollingWindow.cpp

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
#include "warning.h"
#include "Preferences.h"
#include "myroColour.h"
#include "colorWell.h"
#include "mySpacer.h"
#include "mySlider.h"
#include "myPreferences.h"
#include "layoutMatrix.h"
#include "scrollView.h"
#include "scrollingWindow.h"
#include "addChildrenToBase.h"
#include "stringBoundsBox.h"


//ctor 
ScrollingWindow	::	ScrollingWindow(	BRect paramBound,
										const char * paramWindowTitle,
										const char * paramScrollViewName,
										const char * paramNamePrefFrame,
										PreferenceSet *	paramPreferenceSet,
										bool paramHasMenu,
										bool paramShowInInit)
			: 
				BWindow(	paramBound, 
							paramWindowTitle,
							B_DOCUMENT_WINDOW, 
							0), 
				mpScrollViewName(paramScrollViewName),
				mpNamePrefFrame(paramNamePrefFrame),
				mpLayoutMatrixList(new BList()),
				mpPreferenceSet(paramPreferenceSet),
				mbHasMenu(paramHasMenu),
				mbShowInInit(paramShowInInit),
				mpMenuBar(	new BMenuBar(	BRect(0, 0, 1000, 15), "ScrollingWindowMenuBar")),
				mpScrollView(NULL),
				mpBaseView(NULL)
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
ScrollingWindow	::	~ScrollingWindow() 
{
	//leaving blank
}//end

//do all the real work of construction so we can fail gracefully
bool 
ScrollingWindow	::	Initialize(	void) 
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
	float maxRight = MIN_GUTSWINDOW_WIDTH;
	float maxBottom = MIN_GUTSWINDOW_HEIGHT;
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
	maxRight += MATRIXHORIZONTALOFFSETGUTS;
	if (maxRight < mfTitleWidth)
	{
		maxRight = mfTitleWidth;
	}
	maxBottom += (2 * MATRIXVERTICALOFFSETGUTS);
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
	float newWindowHeight = screenResolutionRect.IntegerHeight() - (B_H_SCROLL_BAR_HEIGHT + MATRIXVERTICALOFFSETGUTS + mfMenuBarHeight + vertFudge);
	if (maxBottom < newWindowHeight)
	{
		newWindowHeight = maxBottom;
	}
	ResizeTo(	newWindowWidth + B_V_SCROLL_BAR_WIDTH, 
				newWindowHeight + B_H_SCROLL_BAR_HEIGHT + mfMenuBarHeight);
	mfUnderViewWidth = maxRight;
	mfUnderViewHeight = maxBottom;
	try 
	{
		//this is the view into which we will place our gadgets
		//notice the "mfMenuBarHeight + 1", in the second element
		mpBaseView = new ScrollView(	BRect(	0, 
										mfMenuBarHeight + 1,
										maxRight,
										maxBottom + mfMenuBarHeight - 1));
		mpBaseView->SetFont(myPrefs->GetPreferredFont());
	}
	catch(...) 
	{
		warning(myPrefs->FailScrollView);
		return false;
	}
	try 
	{
		//this is the scroll bar stuff:
		mpScrollView = new BScrollView(	mpScrollViewName, 
										(BView *)mpBaseView, 
										B_FOLLOW_ALL, 
										B_WILL_DRAW, 
										true, 
										true, 
										B_NO_BORDER);
	}
	catch(...) 
	{
		warning(myPrefs->FailMemory);
		return false;
	}
	AddChild(mpScrollView);
	//to the older sized window
	
	mpScrollView->ResizeTo(	newWindowWidth + B_V_SCROLL_BAR_WIDTH + 1, 
							newWindowHeight + B_H_SCROLL_BAR_HEIGHT - 1);
	//BScrollViews get thier initial size from the underlaying BView (mpBaseView)
	AddChildrenToBase(	mpLayoutMatrixList,
						(BView *)mpBaseView,
						numItems,
						mpBaseView->mpStringViewList,
						mpBaseView->mpTextItemList,
						this);
	UpdateScrollBars();//adjust knobs position and proportions
	if (mbShowInInit)
	{
		Show();
	}
	return true;
}//end


//adjust scroll bars to reflect new situation
void 
ScrollingWindow	::	UpdateScrollBars() 
{
	//puts the scroll bars in the proper perspective
	//this code was grabbed from the mandx sample
	//and converted from BBitMap to BView stuff
	if (!mpBaseView)
	{
		return;
	}
	if (LockLooper())
	{
		BScrollView * scrollview;
		BScrollBar * scrollbar;
		BRect visibleExtent;
		BRect totalExtent;
		BRect bound;
		BRect myBounds;
		float max;
		scrollview = (BScrollView *)FindView(mpScrollViewName);
		if (scrollview) 
		{
			bound.Set(0, 0, mfUnderViewWidth, mfUnderViewHeight);
			myBounds = Bounds();
			visibleExtent = bound & myBounds;
			totalExtent = bound | myBounds;
			scrollbar = scrollview->ScrollBar(B_HORIZONTAL);
			max = bound.Width() - myBounds.Width() + B_V_SCROLL_BAR_WIDTH;
			if (max < 0) 
			{
				max = 0;
			}
			scrollbar->SetRange(0, max);
			float proportion = visibleExtent.Width() / totalExtent.Width();
			scrollbar->SetProportion(proportion);
			float smallStep;
			float bigStep;
			if (proportion == .5)
			{
				smallStep = visibleExtent.Width() * .015;
				bigStep = visibleExtent.Width() / 2;
			}
			else if (proportion > .5)
			{
				smallStep = visibleExtent.Width() * .006;
				bigStep = totalExtent.Width() - visibleExtent.Width();
			}
			else 
			{
				smallStep = visibleExtent.Width() * .015;
				bigStep = totalExtent.Width() * proportion;
			}
			if (smallStep > SHRT_MAX)
			{
				smallStep > SHRT_MAX;
			}
			smallStep = ceil(smallStep);
			if (bigStep > SHRT_MAX)
			{
				bigStep > SHRT_MAX;
			}
			bigStep = ceil(bigStep);
			scrollbar->SetSteps(smallStep, bigStep);
			scrollbar = scrollview->ScrollBar(B_VERTICAL);
			max = bound.Height() - myBounds.Height() + mfMenuBarHeight + B_H_SCROLL_BAR_HEIGHT;
			if (max < 0) 
			{
				max = 0;
			}
			scrollbar->SetRange(0, max);
			proportion = visibleExtent.Height() / totalExtent.Height();
			scrollbar->SetProportion(proportion);
			if (proportion == .5)
			{
				smallStep = visibleExtent.Height() * .015;
				bigStep = visibleExtent.Height() / 2;
			}
			else if (proportion > .5)
			{
				smallStep = visibleExtent.Height() * .006;
				bigStep = totalExtent.Height() - visibleExtent.Height();
			}
			else 
			{
				smallStep = visibleExtent.Height() * .015;
				bigStep = totalExtent.Height() * proportion;
			}
			if (smallStep > SHRT_MAX)
			{
				smallStep > SHRT_MAX;
			}
			smallStep = ceil(smallStep);
			if (bigStep > SHRT_MAX)
			{
				bigStep > SHRT_MAX;
			}
			bigStep = ceil(bigStep);
			scrollbar->SetSteps(smallStep, bigStep);
			mpBaseView->Invalidate(mpBaseView->Bounds());
		}
		else 
		{
			warning(myPrefs->NotFoundScrollView);
		}
		UnlockLooper();
	}
	else
	{
		warning(myPrefs->FailLockLooper);
	}
}//end


void 
ScrollingWindow	::	FrameResized(	float, /*note that by NOT naming these we avoid the "unused parameter" warning*/
								float) 
{
	UpdateScrollBars();
}//end


bool
ScrollingWindow	::	QuitRequested(	void) 
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


void
ScrollingWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	switch(paramMessage->what) 
	{
		case ABOUT_WINDOWGUTS:	
		{
			warning(myPrefs->AboutGutMsg);//should never get here!
		break;
		}
		default:
			BWindow::MessageReceived(paramMessage);
		break;
	}
}//end


void
ScrollingWindow	::	AddToLayoutMatrixList(	LayoutMatrix * paramLayoutMatrix)
{
	mpLayoutMatrixList->AddItem((void *)paramLayoutMatrix);
}//end