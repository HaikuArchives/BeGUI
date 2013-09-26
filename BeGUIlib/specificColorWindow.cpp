//specificColorWindow.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DmenuMsg.h"
#include "DnumSpecificWindows.h"
#include "DcolorControlMessages.h"
#include "scrollingWindow.h"
#include "s2f.h"
#include "s2uint32.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "Preferences.h"
#include "myTextView.h"
#include "myListView.h"
#include "mySlider.h"
#include "myButton.h"
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
#include "stringGadget.h"
#include "uInt32Control.h"
#include "stringControl.h"
#include "myPictureButton.h"
#include "myStatusBar.h"
#include "myRadioView.h"
#include "myRadioViewData.h"
#include "myStringView.h"
#include "myCheckBox.h"
#include "prefPanelWindow.h"
#include "warning.h"
#include "myroColour.h"
#include "dataNode.h"
#include "dataList.h"
#include "scrollView.h"
#include "verify.h"
#include "colorWell.h"
#include "myColorControl.h"
#include "floatControl.h"
#include "myPreferences.h"
#include "specificColorWindow.h"
#include "filterFloatNumeric.h"
#include "filterIntNumeric.h"
#include "filterUIntNumeric.h"





//dtor
SpecificColorWindow	::	~SpecificColorWindow() 
{
	if (myPrefs->pPrefPanelWindow)//can get a race if not checked
	{
		myPrefs->pPrefPanelWindow->mpPrefWindows[mui32Kind + 1] = NULL;
	}
}//end


bool
SpecificColorWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	if (mpViewColorControl)//if you got one you got 'em all
	{
		rgb_color viewColor(mpViewColorControl->ValueAsColor());
		rgb_color highColor(mpHighColorControl->ValueAsColor());
		rgb_color lowColor(mpLowColorControl->ValueAsColor());
		switch (mui32Kind) 
		{
			case SPECIFIC_COLOR_BUTTON:
				myPrefs->SetPreferredMyButtonViewColor(&viewColor);
				myPrefs->SetPreferredMyButtonHighColor(&highColor);
				myPrefs->SetPreferredMyButtonLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_PICTURE:
				myPrefs->SetPreferredMyPictureButtonViewColor(&viewColor);
				myPrefs->SetPreferredMyPictureButtonHighColor(&highColor);
				myPrefs->SetPreferredMyPictureButtonLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_RADIOVIEW:
				myPrefs->SetPreferredMyRadioViewViewColor(&viewColor);
				myPrefs->SetPreferredMyRadioViewHighColor(&highColor);
				myPrefs->SetPreferredMyRadioViewLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_CHECKBOX:
				myPrefs->SetPreferredMyCheckBoxViewColor(&viewColor);
				myPrefs->SetPreferredMyCheckBoxHighColor(&highColor);
				myPrefs->SetPreferredMyCheckBoxLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_STATUSBAR:
				myPrefs->SetPreferredMyStatusBarViewColor(&viewColor);
				myPrefs->SetPreferredMyStatusBarHighColor(&highColor);
				myPrefs->SetPreferredMyStatusBarLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_SLIDER:
				myPrefs->SetPreferredMySliderViewColor(&viewColor);
				myPrefs->SetPreferredMySliderHighColor(&highColor);
				myPrefs->SetPreferredMySliderLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_COLORCONTROL:
				myPrefs->SetPreferredMyColorControlViewColor(&viewColor);
				myPrefs->SetPreferredMyColorControlHighColor(&highColor);
				myPrefs->SetPreferredMyColorControlLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_TEXTVIEW:
				myPrefs->SetPreferredMyTextViewViewColor(&viewColor);
				myPrefs->SetPreferredMyTextViewHighColor(&highColor);
				myPrefs->SetPreferredMyTextViewLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_LISTVIEW:
				myPrefs->SetPreferredMyListViewViewColor(&viewColor);
				myPrefs->SetPreferredMyListViewHighColor(&highColor);
				myPrefs->SetPreferredMyListViewLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_UINT32CONTROL:
				myPrefs->SetPreferredUInt32ControlViewColor(&viewColor);
				myPrefs->SetPreferredUInt32ControlHighColor(&highColor);
				myPrefs->SetPreferredUInt32ControlLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_INT8GADGET:
				myPrefs->SetPreferredInt8GadgetViewColor(&viewColor);
				myPrefs->SetPreferredInt8GadgetHighColor(&highColor);
				myPrefs->SetPreferredInt8GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_UINT8GADGET:
				myPrefs->SetPreferredUInt8GadgetViewColor(&viewColor);
				myPrefs->SetPreferredUInt8GadgetHighColor(&highColor);
				myPrefs->SetPreferredUInt8GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_INT16GADGET:
				myPrefs->SetPreferredInt16GadgetViewColor(&viewColor);
				myPrefs->SetPreferredInt16GadgetHighColor(&highColor);
				myPrefs->SetPreferredInt16GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_UINT16GADGET:
				myPrefs->SetPreferredUInt16GadgetViewColor(&viewColor);
				myPrefs->SetPreferredUInt16GadgetHighColor(&highColor);
				myPrefs->SetPreferredUInt16GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_INT32GADGET:
				myPrefs->SetPreferredInt32GadgetViewColor(&viewColor);
				myPrefs->SetPreferredInt32GadgetHighColor(&highColor);
				myPrefs->SetPreferredInt32GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_UINT32GADGET:
				myPrefs->SetPreferredUInt32GadgetViewColor(&viewColor);
				myPrefs->SetPreferredUInt32GadgetHighColor(&highColor);
				myPrefs->SetPreferredUInt32GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_INT64GADGET:
				myPrefs->SetPreferredInt64GadgetViewColor(&viewColor);
				myPrefs->SetPreferredInt64GadgetHighColor(&highColor);
				myPrefs->SetPreferredInt64GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_UINT64GADGET:
				myPrefs->SetPreferredUInt64GadgetViewColor(&viewColor);
				myPrefs->SetPreferredUInt64GadgetHighColor(&highColor);
				myPrefs->SetPreferredUInt64GadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_FLOATGADGET:
				myPrefs->SetPreferredFloatGadgetViewColor(&viewColor);
				myPrefs->SetPreferredFloatGadgetHighColor(&highColor);
				myPrefs->SetPreferredFloatGadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_STRINGGADGET:
				myPrefs->SetPreferredStringGadgetViewColor(&viewColor);
				myPrefs->SetPreferredStringGadgetHighColor(&highColor);
				myPrefs->SetPreferredStringGadgetLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_FLOATCONTROL:
				myPrefs->SetPreferredFloatControlViewColor(&viewColor);
				myPrefs->SetPreferredFloatControlHighColor(&highColor);
				myPrefs->SetPreferredFloatControlLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_STRINGCONTROL:
				myPrefs->SetPreferredStringControlViewColor(&viewColor);
				myPrefs->SetPreferredStringControlHighColor(&highColor);
				myPrefs->SetPreferredStringControlLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_COLORWELL:
				myPrefs->SetPreferredColorWellViewColor(&viewColor);
				myPrefs->SetPreferredColorWellHighColor(&highColor);
				myPrefs->SetPreferredColorWellLowColor(&lowColor);
			break;
			case SPECIFIC_COLOR_STRINGDRAWER:
				myPrefs->SetPreferredMyStringDrawerViewColor(&viewColor);
				myPrefs->SetPreferredMyStringDrawerHighColor(&highColor);
				myPrefs->SetPreferredMyStringDrawerLowColor(&lowColor);
			break;
			default:
				warning(myPrefs->BadSpecKindQR);
				throw;
			break;
		}
	}
	switch (mui32Kind) 
	{
		case SPECIFIC_COLOR_BUTTON:
			myPrefs->SetPreferredSpecificColorButtonWindowRect(frame);
		break;
		case SPECIFIC_COLOR_PICTURE:
			myPrefs->SetPreferredSpecificColorPictureButtonWindowRect(frame);
		break;
		case SPECIFIC_COLOR_RADIOVIEW:
			myPrefs->SetPreferredSpecificColorRadioButtonWindowRect(frame);
		break;
		case SPECIFIC_COLOR_CHECKBOX:
			myPrefs->SetPreferredSpecificColorCheckBoxWindowRect(frame);
		break;
		case SPECIFIC_COLOR_STATUSBAR:
		{
			myPrefs->SetPreferredSpecificColorStatusBarWindowRect(frame);
			rgb_color barColor(mpBarColorControl->ValueAsColor());
			myPrefs->SetPreferredMyBarStatusColor(&barColor);
			float height;
			if (s2f(mpBarHeightGadget->Text(), &height) == B_OK)
			{
				myPrefs->SetPreferredBarHeight(height);
			}
		}
		break;
		case SPECIFIC_COLOR_SLIDER:
		{
			myPrefs->SetPreferredSpecificColorSliderWindowRect(frame);
			rgb_color barColor(mpBarColorControl->ValueAsColor());
			myPrefs->SetPreferredMyBarSliderColor(&barColor);
		}
		break;
		case SPECIFIC_COLOR_COLORCONTROL:
			myPrefs->SetPreferredSpecificColorColorControlWindowRect(frame);
		break;
		case SPECIFIC_COLOR_TEXTVIEW:
			myPrefs->SetPreferredSpecificColorTextViewWindowRect(frame);
		break;
		case SPECIFIC_COLOR_LISTVIEW:
			myPrefs->SetPreferredSpecificColorListViewWindowRect(frame);
		break;
		case SPECIFIC_COLOR_UINT32CONTROL:
			myPrefs->SetPreferredSpecificColorUInt32ControlWindowRect(frame);
		break;
		case SPECIFIC_COLOR_INT8GADGET:
			myPrefs->SetPreferredSpecificColorInt8GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_UINT8GADGET:
			myPrefs->SetPreferredSpecificColorUInt8GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_INT16GADGET:
			myPrefs->SetPreferredSpecificColorInt16GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_UINT16GADGET:
			myPrefs->SetPreferredSpecificColorUInt16GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_INT32GADGET:
			myPrefs->SetPreferredSpecificColorInt32GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_UINT32GADGET:
			myPrefs->SetPreferredSpecificColorUInt32GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_INT64GADGET:
			myPrefs->SetPreferredSpecificColorInt64GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_UINT64GADGET:
			myPrefs->SetPreferredSpecificColorUInt64GadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_FLOATGADGET:
			myPrefs->SetPreferredSpecificColorFloatGadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_STRINGGADGET:
			myPrefs->SetPreferredSpecificColorStringGadgetWindowRect(frame);
		break;
		case SPECIFIC_COLOR_FLOATCONTROL:
			myPrefs->SetPreferredSpecificColorFloatControlWindowRect(frame);
		break;
		case SPECIFIC_COLOR_STRINGCONTROL:
			myPrefs->SetPreferredSpecificColorStringControlWindowRect(frame);
		break;
		case SPECIFIC_COLOR_COLORWELL:
			myPrefs->SetPreferredSpecificColorColorWellWindowRect(frame);
			uint32 holdUInt8;
			if (s2uint32(mpColorWellWidthGadget->Text(), &holdUInt8) == B_OK)
			{
				if (holdUInt8 <= MAX_UI8)
				{
					myPrefs->SetPreferredColorWellWidth((uint8)holdUInt8);
				}
			}
			if (s2uint32(mpColorWellHeightGadget->Text(), &holdUInt8) == B_OK)
			{
				if (holdUInt8 <= MAX_UI8)
				{
					myPrefs->SetPreferredColorWellHeight((uint8)holdUInt8);
				}
			}
		break;
		case SPECIFIC_COLOR_STRINGDRAWER:
			myPrefs->SetPreferredSpecificColorStringDrawerWindowRect(frame);
		break;
		default:
			warning(myPrefs->BadSpecKindQR);
			throw;
		break;
	}
	return(ScrollingWindow::QuitRequested());
}//end


void
SpecificColorWindow	::	ResetDemo(	void)
{
	myPrefs->mbPrefChangesMade = true;
	rgb_color viewColor(mpViewColorControl->ValueAsColor());
	rgb_color highColor(mpHighColorControl->ValueAsColor());
	rgb_color lowColor(mpLowColorControl->ValueAsColor());
	if (LockLooper())
	{
		if (mui32Kind == SPECIFIC_COLOR_TEXTVIEW)
		{
			((BTextView *)mpDemoItem)->SetViewColor(viewColor);
			((BTextView *)mpDemoItem)->SetLowColor(lowColor);
			((BTextView *)mpDemoItem)->SetFontAndColor(myPrefs->GetPreferredFont(), B_FONT_ALL, &highColor);
			((BTextView *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
		}
		else if (mui32Kind == SPECIFIC_COLOR_STRINGDRAWER)
		{
			rgb_color originalHighColor(mpBaseView->HighColor());
			rgb_color originalLowColor(mpBaseView->LowColor());
			rgb_color originalViewColor(mpBaseView->ViewColor());
			BFont originalFont;
			mpBaseView->GetFont(&originalFont);
			mpBaseView->SetViewColor(viewColor);
			mpBaseView->SetHighColor(highColor);
			mpBaseView->SetLowColor(lowColor);
			TextItem * textItem = ((MyStringDrawer *)mpDemoItem)->GetTextItem();
			mpBaseView->SetFont(((MyStringDrawer *)mpDemoItem)->GetFont());
			mpBaseView->MovePenTo(textItem->mfLeft, textItem->mfTop);
			mpBaseView->DrawString(textItem->mpText);
			mpBaseView->SetHighColor(originalHighColor);
			mpBaseView->SetLowColor(originalLowColor);
			mpBaseView->SetViewColor(originalViewColor);
			mpBaseView->SetFont(&originalFont);
		}
		else if (mui32Kind == SPECIFIC_COLOR_STATUSBAR)
		{
			rgb_color barColor(mpBarColorControl->ValueAsColor());
			((BStatusBar *)mpDemoItem)->SetBarColor(barColor);
			((BStatusBar *)mpDemoItem)->SetViewColor(viewColor);
			((BStatusBar *)mpDemoItem)->SetHighColor(highColor);
			((BStatusBar *)mpDemoItem)->SetLowColor(lowColor);
			float height;
			if (s2f(mpBarHeightGadget->Text(), &height) == B_OK)
			{
				((BStatusBar *)mpDemoItem)->SetBarHeight(height);
			}
			((BStatusBar *)mpDemoItem)->Invalidate(((BStatusBar *)mpDemoItem)->Bounds());
		}
		else if (mui32Kind == SPECIFIC_COLOR_SLIDER)
		{
			rgb_color barColor(mpBarColorControl->ValueAsColor());
			((BSlider *)mpDemoItem)->SetBarColor(barColor);
			((BSlider *)mpDemoItem)->SetViewColor(viewColor);
			((BSlider *)mpDemoItem)->SetHighColor(highColor);
			((BSlider *)mpDemoItem)->SetLowColor(lowColor);
			rgb_color fillColor(mpFillColorControl->ValueAsColor());
			myPrefs->SetPreferredMyBarFillSliderColor(&fillColor);
			if (myPrefs->mui32ColorSliderBar)
			{
				((BSlider *)mpDemoItem)->UseFillColor(	true, 
														&fillColor);
			}
			if (B_BLOCK_THUMB == myPrefs->GetPreferredThumbStyle())
			{
				((BSlider *)mpDemoItem)->SetStyle(B_BLOCK_THUMB);
			}
			else
			{
				((BSlider *)mpDemoItem)->SetStyle(B_TRIANGLE_THUMB);
			}
			BView * osv = ((BSlider *)mpDemoItem)->OffscreenView();
			if (osv->LockLooper())
			{
				osv->SetViewColor(viewColor);
				osv->SetHighColor(highColor);
				osv->SetLowColor(lowColor);
				osv->UnlockLooper();
			}
			else
			{
				warning(myPrefs->FailLockLooper);
			}
			((BStatusBar *)mpDemoItem)->Invalidate(((BStatusBar *)mpDemoItem)->Bounds());
		}
		else if (mui32Kind == SPECIFIC_COLOR_COLORWELL)
		{
			((ColorWell *)mpDemoItem)->SetViewColor(viewColor);
			((ColorWell *)mpDemoItem)->SetHighColor(highColor);
			((ColorWell *)mpDemoItem)->SetLowColor(lowColor);
			((ColorWell *)mpDemoItem)->Invalidate(((BView *)mpDemoItem)->Bounds());
			if (((ColorWell *)mpDemoItem)->mpLabelView)
			{
				((ColorWell *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((ColorWell *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((ColorWell *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((ColorWell *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((ColorWell *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_COLORCONTROL)
		{
			((BColorControl *)mpDemoItem)->RemoveSelf();
			((BColorControl *)mpDemoItem)->SetViewColor(viewColor);
			((BColorControl *)mpDemoItem)->SetHighColor(highColor);
			((BColorControl *)mpDemoItem)->SetLowColor(lowColor);
			((BColorControl *)mpDemoItem)->SetLayout(myPrefs->mCCL);
			mpBaseView->AddChild((BColorControl *)mpDemoItem);
			bool setRange = false;
			float maxCCRight = ((BColorControl *)mpDemoItem)->Frame().right;
			if (maxCCRight > mfUnderViewWidth)
			{
				mfUnderViewWidth = maxCCRight;
				setRange = true;
			}
			float maxCCBottom = ((BColorControl *)mpDemoItem)->Frame().bottom;
			if (maxCCBottom > mfUnderViewHeight)
			{
				mfUnderViewHeight = maxCCBottom;
				setRange = true;
			}
			if (setRange)
			{
				UpdateScrollBars();
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_STRINGGADGET)
		{
			((StringGadget *)mpDemoItem)->SetViewColor(viewColor);
			((StringGadget *)mpDemoItem)->SetHighColor(highColor);
			((StringGadget *)mpDemoItem)->SetLowColor(lowColor);
			((StringGadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((StringGadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((StringGadget *)mpDemoItem)->mpLabelView)
			{
				((StringGadget *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((StringGadget *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((StringGadget *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((StringGadget *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((StringGadget *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_FLOATGADGET)
		{
			((FloatGadget *)mpDemoItem)->SetViewColor(viewColor);
			((FloatGadget *)mpDemoItem)->SetHighColor(highColor);
			((FloatGadget *)mpDemoItem)->SetLowColor(lowColor);
			((FloatGadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((FloatGadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((FloatGadget *)mpDemoItem)->mpLabelView)
			{
				((FloatGadget *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((FloatGadget *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((FloatGadget *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((FloatGadget *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((FloatGadget *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_INT8GADGET)
		{
			((Int8Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((Int8Gadget *)mpDemoItem)->SetHighColor(highColor);
			((Int8Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((Int8Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((Int8Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((Int8Gadget *)mpDemoItem)->mpLabelView)
			{
				((Int8Gadget *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((Int8Gadget *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((Int8Gadget *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((Int8Gadget *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((Int8Gadget *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_UINT8GADGET)
		{
			((UInt8Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((UInt8Gadget *)mpDemoItem)->SetHighColor(highColor);
			((UInt8Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((UInt8Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((UInt8Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((UInt8Gadget *)mpDemoItem)->mpLabelView)
			{
				((UInt8Gadget *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((UInt8Gadget *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((UInt8Gadget *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((UInt8Gadget *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((UInt8Gadget *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_INT16GADGET)
		{
			((Int16Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((Int16Gadget *)mpDemoItem)->SetHighColor(highColor);
			((Int16Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((Int16Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((Int16Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((GadgetBase *)mpDemoItem)->mpLabelView)
			{
				((GadgetBase *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((GadgetBase *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_UINT16GADGET)
		{
			((UInt16Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((UInt16Gadget *)mpDemoItem)->SetHighColor(highColor);
			((UInt16Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((UInt16Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((UInt16Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((GadgetBase *)mpDemoItem)->mpLabelView)
			{
				((GadgetBase *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((GadgetBase *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_INT32GADGET)
		{
			((Int32Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((Int32Gadget *)mpDemoItem)->SetHighColor(highColor);
			((Int32Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((Int32Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((Int32Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((GadgetBase *)mpDemoItem)->mpLabelView)
			{
				((GadgetBase *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((GadgetBase *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_UINT32GADGET)
		{
			((UInt32Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((UInt32Gadget *)mpDemoItem)->SetHighColor(highColor);
			((UInt32Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((UInt32Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((UInt32Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((GadgetBase *)mpDemoItem)->mpLabelView)
			{
				((GadgetBase *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((GadgetBase *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_INT64GADGET)
		{
			((Int64Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((Int64Gadget *)mpDemoItem)->SetHighColor(highColor);
			((Int64Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((Int64Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((Int64Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((GadgetBase *)mpDemoItem)->mpLabelView)
			{
				((GadgetBase *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((GadgetBase *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_UINT64GADGET)
		{
			((UInt64Gadget *)mpDemoItem)->SetViewColor(viewColor);
			((UInt64Gadget *)mpDemoItem)->SetHighColor(highColor);
			((UInt64Gadget *)mpDemoItem)->SetLowColor(lowColor);
			((UInt64Gadget *)mpDemoItem)->SetFontAndColor(	myPrefs->GetPreferredFont(),
															B_FONT_ALL,
															&highColor);
			((UInt64Gadget *)mpDemoItem)->Invalidate(((BTextView *)mpDemoItem)->Bounds());
			if (((GadgetBase *)mpDemoItem)->mpLabelView)
			{
				((GadgetBase *)mpDemoItem)->mpLabelView->SetViewColor(viewColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetHighColor(highColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->SetLowColor(lowColor);
				((GadgetBase *)mpDemoItem)->mpLabelView->Invalidate(((BView *)((GadgetBase *)mpDemoItem)->mpLabelView)->Bounds());
			}
		}
		else
		{
			((BView *)mpDemoItem)->SetViewColor(viewColor);
			((BView *)mpDemoItem)->SetHighColor(highColor);
			((BView *)mpDemoItem)->SetLowColor(lowColor);
			((BView *)mpDemoItem)->Invalidate(((BView *)mpDemoItem)->Bounds());
		}
		UnlockLooper();
	}
	else
	{
		warning(myPrefs->FailLockLooper);
	}
}//end


void
SpecificColorWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	uint32 what = paramMessage->what;
	switch(paramMessage->what) 
	{
		case 'selc':
			warning(myPrefs->SelectFromList);
		break;
		case 'invc':
			warning(myPrefs->InvokeFromList);
		break;
		case SLIDERBARCB:
			myPrefs->mui32ColorSliderBar = mpSliderBarCB->Value();
		break;
		case THUMB_TRI:
			myPrefs->SetPreferredThumbStyle(B_TRIANGLE_THUMB);
		break;
		case THUMB_RECT:
			myPrefs->SetPreferredThumbStyle(B_BLOCK_THUMB);
		break;
		case CCL4x64RV:
			myPrefs->mCCL = B_CELLS_4x64;
		break;
		case CCL8x32RV:
			myPrefs->mCCL = B_CELLS_8x32;
		break;
		case CCL16x16RV:
			myPrefs->mCCL = B_CELLS_16x16;
		break;
		case CCL32x8RV:
			myPrefs->mCCL = B_CELLS_32x8;
		break;
		case CCL64x4RV:
			myPrefs->mCCL = B_CELLS_64x4;
		break;
		case ABOUT_SPECIFICCOLORWINDOW:	
			warning(myPrefs->AboutSpecColorWindow);
		break;
		case QUIT_APP:
			if (Verify(myPrefs->ReallyQuitApp))
			{
				be_app->PostMessage(B_QUIT_REQUESTED);
			}
		break;
		case roColourDROPPEDMESSAGE: 
		{
    		rgb_color * pRGBColor;
    		rgb_color color;   		
    		int32 numRGBBytes = sizeof(struct rgb_color);
	        if (	paramMessage->FindData(	"RGBColor",
		       									B_RGB_COLOR_TYPE, 
												(const void**)&pRGBColor, 
												&numRGBBytes ) 
					== B_OK)
	        {
	           	color = *pRGBColor;
	            if (paramMessage->WasDropped()) 
	            {
					int32 colorToChange;
					if (	paramMessage->FindInt32(	"ColorToChange",
														&colorToChange)
							 == B_OK)
					{
						switch(colorToChange)
						{
							case BAR_COLOR:
								myPrefs->SetPreferredMyBarStatusColor(&color);
								mpBarColorControl->SetValue(color);
							break;
							case FILL_COLOR:
								myPrefs->SetPreferredMyBarFillSliderColor(&color);
								mpFillColorControl->SetValue(color);
							break;
							case VIEW_COLOR:
								switch(mui32Kind)
								{
									case SPECIFIC_COLOR_BUTTON:
										myPrefs->SetPreferredMyButtonViewColor(&color);
									break;
									case SPECIFIC_COLOR_PICTURE:
										myPrefs->SetPreferredMyPictureButtonViewColor(&color);
									break;
									case SPECIFIC_COLOR_RADIOVIEW:
										myPrefs->SetPreferredMyRadioViewViewColor(&color);
									break;
									case SPECIFIC_COLOR_CHECKBOX:
										myPrefs->SetPreferredMyCheckBoxViewColor(&color);
									break;
									case SPECIFIC_COLOR_STATUSBAR:
										myPrefs->SetPreferredMyStatusBarViewColor(&color);
									break;
									case SPECIFIC_COLOR_SLIDER:
										myPrefs->SetPreferredMySliderViewColor(&color);
									break;
									case SPECIFIC_COLOR_COLORCONTROL:
										myPrefs->SetPreferredMyColorControlViewColor(&color);
									break;
									case SPECIFIC_COLOR_TEXTVIEW:
										myPrefs->SetPreferredMyTextViewViewColor(&color);
									break;
									case SPECIFIC_COLOR_LISTVIEW:
										myPrefs->SetPreferredMyListViewViewColor(&color);
									break;
									case SPECIFIC_COLOR_UINT32CONTROL:
										myPrefs->SetPreferredUInt32ControlViewColor(&color);
									break;
									case SPECIFIC_COLOR_INT8GADGET:
										myPrefs->SetPreferredInt8GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_UINT8GADGET:
										myPrefs->SetPreferredUInt8GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_INT16GADGET:
										myPrefs->SetPreferredInt16GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_UINT16GADGET:
										myPrefs->SetPreferredUInt16GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_INT32GADGET:
										myPrefs->SetPreferredInt32GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_UINT32GADGET:
										myPrefs->SetPreferredUInt32GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_INT64GADGET:
										myPrefs->SetPreferredInt64GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_UINT64GADGET:
										myPrefs->SetPreferredUInt64GadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_FLOATGADGET:
										myPrefs->SetPreferredFloatGadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGGADGET:
										myPrefs->SetPreferredStringGadgetViewColor(&color);
									break;
									case SPECIFIC_COLOR_FLOATCONTROL:
										myPrefs->SetPreferredFloatControlViewColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGCONTROL:
										myPrefs->SetPreferredStringControlViewColor(&color);
									break;
									case SPECIFIC_COLOR_COLORWELL:
										myPrefs->SetPreferredColorWellViewColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGDRAWER:
										myPrefs->SetPreferredMyStringDrawerViewColor(&color);
									break;
									default:
										warning(myPrefs->BadSpecKindColorSetView);
										throw;
									break;
								}
								mpViewColorControl->SetValue(color);
							break;
							case HIGH_COLOR:
								switch(mui32Kind)
								{
									case SPECIFIC_COLOR_BUTTON:
										myPrefs->SetPreferredMyButtonHighColor(&color);
									break;
									case SPECIFIC_COLOR_PICTURE:
										myPrefs->SetPreferredMyPictureButtonHighColor(&color);
									break;
									case SPECIFIC_COLOR_RADIOVIEW:
										myPrefs->SetPreferredMyRadioViewHighColor(&color);
									break;
									case SPECIFIC_COLOR_CHECKBOX:
										myPrefs->SetPreferredMyCheckBoxHighColor(&color);
									break;
									case SPECIFIC_COLOR_STATUSBAR:
										myPrefs->SetPreferredMyStatusBarHighColor(&color);
									break;
									case SPECIFIC_COLOR_SLIDER:
										myPrefs->SetPreferredMySliderHighColor(&color);
									break;
									case SPECIFIC_COLOR_COLORCONTROL:
										myPrefs->SetPreferredMyColorControlHighColor(&color);
									break;
									case SPECIFIC_COLOR_TEXTVIEW:
										myPrefs->SetPreferredMyTextViewHighColor(&color);
									break;
									case SPECIFIC_COLOR_LISTVIEW:
										myPrefs->SetPreferredMyListViewHighColor(&color);
									break;
									case SPECIFIC_COLOR_UINT32CONTROL:
										myPrefs->SetPreferredUInt32ControlHighColor(&color);
									break;
									case SPECIFIC_COLOR_INT8GADGET:
										myPrefs->SetPreferredInt8GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_UINT8GADGET:
										myPrefs->SetPreferredUInt8GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_INT16GADGET:
										myPrefs->SetPreferredInt16GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_UINT16GADGET:
										myPrefs->SetPreferredUInt16GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_INT32GADGET:
										myPrefs->SetPreferredInt32GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_UINT32GADGET:
										myPrefs->SetPreferredUInt32GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_INT64GADGET:
										myPrefs->SetPreferredInt64GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_UINT64GADGET:
										myPrefs->SetPreferredUInt64GadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_FLOATGADGET:
										myPrefs->SetPreferredFloatGadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGGADGET:
										myPrefs->SetPreferredStringGadgetHighColor(&color);
									break;
									case SPECIFIC_COLOR_FLOATCONTROL:
										myPrefs->SetPreferredFloatControlHighColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGCONTROL:
										myPrefs->SetPreferredStringControlHighColor(&color);
									break;
									case SPECIFIC_COLOR_COLORWELL:
										myPrefs->SetPreferredColorWellHighColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGDRAWER:
										myPrefs->SetPreferredMyStringDrawerHighColor(&color);
									break;
									default:
										warning(myPrefs->BadSpecKindColorSetHigh);
										throw;
									break;
								}
								mpHighColorControl->SetValue(color);
							break;
							case LOW_COLOR:
								switch(mui32Kind)
								{
									case SPECIFIC_COLOR_BUTTON:
										myPrefs->SetPreferredMyButtonLowColor(&color);
									break;
									case SPECIFIC_COLOR_PICTURE:
										myPrefs->SetPreferredMyPictureButtonLowColor(&color);
									break;
									case SPECIFIC_COLOR_RADIOVIEW:
										myPrefs->SetPreferredMyRadioViewLowColor(&color);
									break;
									case SPECIFIC_COLOR_CHECKBOX:
										myPrefs->SetPreferredMyCheckBoxLowColor(&color);
									break;
									case SPECIFIC_COLOR_STATUSBAR:
										myPrefs->SetPreferredMyStatusBarLowColor(&color);
									break;
									case SPECIFIC_COLOR_SLIDER:
										myPrefs->SetPreferredMySliderLowColor(&color);
									break;
									case SPECIFIC_COLOR_COLORCONTROL:
										myPrefs->SetPreferredMyColorControlLowColor(&color);
									break;
									case SPECIFIC_COLOR_TEXTVIEW:
										myPrefs->SetPreferredMyTextViewLowColor(&color);
									break;
									case SPECIFIC_COLOR_LISTVIEW:
										myPrefs->SetPreferredMyListViewLowColor(&color);
									break;
									case SPECIFIC_COLOR_UINT32CONTROL:
										myPrefs->SetPreferredUInt32ControlLowColor(&color);
									break;
									case SPECIFIC_COLOR_INT8GADGET:
										myPrefs->SetPreferredInt8GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_UINT8GADGET:
										myPrefs->SetPreferredUInt8GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_INT16GADGET:
										myPrefs->SetPreferredInt16GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_UINT16GADGET:
										myPrefs->SetPreferredUInt16GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_INT32GADGET:
										myPrefs->SetPreferredInt32GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_UINT32GADGET:
										myPrefs->SetPreferredUInt32GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_INT64GADGET:
										myPrefs->SetPreferredInt64GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_UINT64GADGET:
										myPrefs->SetPreferredUInt64GadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_FLOATGADGET:
										myPrefs->SetPreferredFloatGadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGGADGET:
										myPrefs->SetPreferredStringGadgetLowColor(&color);
									break;
									case SPECIFIC_COLOR_FLOATCONTROL:
										myPrefs->SetPreferredFloatControlLowColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGCONTROL:
										myPrefs->SetPreferredStringControlLowColor(&color);
									break;
									case SPECIFIC_COLOR_COLORWELL:
										myPrefs->SetPreferredColorWellLowColor(&color);
									break;
									case SPECIFIC_COLOR_STRINGDRAWER:
										myPrefs->SetPreferredMyStringDrawerLowColor(&color);
									break;
									default:
										warning(myPrefs->BadSpecKindColorSetLow);
										throw;
									break;
								}
								mpLowColorControl->SetValue(color);
							break;
							case NO_COLOR:
								warning(myPrefs->DemoRoNo);
							break;
							default:
								warning(myPrefs->RoBadMsg);
							break;
						}
					}
				}
			}
		break;
		}
		default:
			ScrollingWindow::MessageReceived(paramMessage);
		break;
	}
	switch(what) 
	{
		case COLORCONTROL_VIEW:
		case COLORCONTROL_HIGH:
		case COLORCONTROL_LOW:
		case BARCOLORCONTROL:
		case FILLCOLORCONTROL:
		case 0x63636f6c://<CR> from color control 
		case 0x62485320://<CR> from bar height
		case roColourDROPPEDMESSAGE:
		case DEMOPICTUREBUTTONMSG:
		case SLIDERBARCB:
		case THUMB_RECT:
		case THUMB_TRI:
		case CCL4x64RV:
		case CCL8x32RV:
		case CCL16x16RV:
		case CCL32x8RV:
		case CCL64x4RV:
			ResetDemo();
		break;
	}
}//end