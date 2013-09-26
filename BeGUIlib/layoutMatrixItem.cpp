//layoutMatrixItem.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "uInt32Control.h"
#include "floatControl.h"
#include "stringControl.h"
#include "warning.h"
#include "colorWell.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "myStatusBar.h"
#include "myPopUpMenu.h"
#include "myPopUpMenuData.h"
#include "myTextView.h"
#include "myStringView.h"
#include "myButton.h"
#include "myListView.h"
#include "myRadioView.h"
#include "myRadioViewData.h"
#include "layoutMatrix.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "mySpacer.h"
#include "mySlider.h"
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
#include "hexGadget.h"
#include "stringGadget.h"
#include "myPreferences.h"
#include "stringBoundsBox.h"

//dtor
LayoutMatrixItem	::	~LayoutMatrixItem()
{
	//leaving blank
}


//ctor
LayoutMatrixItem	::	LayoutMatrixItem(	void * paramItem, 
											LayoutMatrix * paramLayoutMatrix,
											const uint32 paramKind)
					: 	mpItem(paramItem), 
						mui32Kind(paramKind)
{
	paramLayoutMatrix->mpItemsList->AddItem(this);
}//end


//calculates the minimum appropriate width and height
//of a matrix item
void 
LayoutMatrixItem	::	Calc() 
{
	const float pad = 11;
	const float cfAlignPad = 6;
	//use pad to give a bit of room at each end of the
	//button to set off the button text
	BRect br(-100, 0, -32, 32);
	//still need BWindow attached view for the BTextControl based stuff!//
	BWindow * bWindow = new BWindow(	br, 
										NULL, 
										B_DOCUMENT_WINDOW, 
										0);
	BView * bView = new BView(	br, 
								NULL, 
								B_FOLLOW_NONE, 
								0);
	//need to attach some items to a BView before they can be measured
	bWindow->AddChild(bView);
	float leftOffset;
	float baseline;
	float width;
	float height;
	const char * gadgetLabel = NULL;
	BFont * useFont = NULL;
	const char * gadgetValue = "0xX123456789";
	switch (mui32Kind) 
	{
		case KIND_STRINGDRAWER:
			gadgetLabel = ((BStringView *)mpItem)->Text();
			useFont = ((MyStringDrawer *)mpItem)->GetFont();
		break;
		case KIND_MYCHECKBOX:
			gadgetLabel = ((BCheckBox *)mpItem)->Label();
		break;
		case KIND_STRINGCONTROL:
			gadgetLabel = ((StringControl *)mpItem)->Label();
		break;
		case KIND_FLOATCONTROL:
			gadgetLabel = ((FloatControl *)mpItem)->Label();
		break;
		case KIND_UINT32CONTROL:
			gadgetLabel = ((UInt32Control *)mpItem)->Label();
		break;
		case KIND_TEXT:
			gadgetLabel = ((TextItem *)mpItem)->mpText;
		break;
		case KIND_COLORWELL:
			gadgetLabel = (((ColorWell *)mpItem)->mpLabel)->String();
		break;
		case KIND_INT8GADGET:
		case KIND_UINT8GADGET:
		case KIND_INT16GADGET:
		case KIND_UINT16GADGET:
		case KIND_INT32GADGET:
		case KIND_UINT32GADGET:
		case KIND_INT64GADGET:
		case KIND_UINT64GADGET:
		case KIND_FLOATGADGET:
		case KIND_HEXGADGET:
			gadgetLabel = (((GadgetBase *)mpItem)->mpLabel)->String();
		break;
		case KIND_STRINGGADGET:
			gadgetLabel = (((GadgetBase *)mpItem)->mpLabel)->String();
			gadgetValue = myPrefs->AlphaNumeric;
		break;
	}
	if (gadgetLabel)
	{
		if (!StringBoundsBox(	gadgetLabel,
								&width,
								&height,
								&leftOffset,
								&baseline,
								useFont))
		{
			throw;
		}
	}
	if (	(mui32Kind == KIND_INT8GADGET) ||
			(mui32Kind == KIND_UINT8GADGET) ||
			(mui32Kind == KIND_INT16GADGET) ||
			(mui32Kind == KIND_UINT16GADGET) ||
			(mui32Kind == KIND_INT32GADGET) ||
			(mui32Kind == KIND_UINT32GADGET) ||
			(mui32Kind == KIND_INT64GADGET) ||
			(mui32Kind == KIND_UINT64GADGET) ||
			(mui32Kind == KIND_FLOATGADGET) ||
			(mui32Kind == KIND_HEXGADGET) ||
			(mui32Kind == KIND_STRINGGADGET)
		)
	{
		float otherHeight;
		float otherWidth;
		float otherLO;
		float otherBL;
		if (!StringBoundsBox(	gadgetValue,
								&otherWidth,
								&otherHeight,
								&otherLO,
								&otherBL,
								useFont))
		{
			throw;
		}
		if (otherHeight > height)
		{
			height = otherHeight;
		}
	}
	switch (mui32Kind) 
	{
		case KIND_STRINGDRAWER:
		{
			width += pad;
			((MyStringDrawer *)mpItem)->MyGetPreferredSize(&mfWidthPref, &mfHeightPref);
			//PreferredSize uses a huge pad--I dislike the wasted space
			//so I compute width plus some small padding...
			if (width > mfWidthPref) 
			{
				mfWidthPref = width;
			}
			else 
			{
				width = mfWidthPref;
			}
			//then use the smaller width--might be good to perform
			//the same opperation for height, though the preferred 
			//height seems OK
			((BStringView *)mpItem)->ResizeTo(width, mfHeightPref);
		}
		break;
		case KIND_MYPOPUPMENU:
		{
			float prefWidth;
			float prefHeight;
			((MyPopUpMenu *)mpItem)->MyGetPreferredSize(&prefWidth, &prefHeight);
			if (prefHeight > ((MyPopUpMenu *)mpItem)->mfLabelHeight)
			{
				mfHeightPref = prefHeight;
			}
			else
			{
				mfHeightPref = ((MyPopUpMenu *)mpItem)->mfLabelHeight;
			}
			mfWidthPref = ((MyPopUpMenu *)mpItem)->mfWidest;
			if (prefWidth > mfWidthPref)
			{
				mfWidthPref = prefWidth;
			}
			((MyPopUpMenu *)mpItem)->ResizeTo(mfWidthPref, prefHeight);
		}
		break;
		case KIND_MYTEXTVIEW:
			((MyTextView *)mpItem)->MyGetPreferredSize(&mfWidthPref, &mfHeightPref);
		break;
		case KIND_MYLISTVIEW:
		{
			((BListView *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
			float	width,
					height;
			((MyListView *)mpItem)->MyGetPreferredSize(&width, &height);
			if (width > mfWidthPref)
			{
				if (height > mfHeightPref)
					{
					((BListView *)mpItem)->ResizeTo(width, height);
				}
				else
				{
					((BListView *)mpItem)->ResizeTo(width, mfHeightPref);
				}
			}
			if (height > mfHeightPref)
			{
				if (width > mfWidthPref)
				{
					((BListView *)mpItem)->ResizeTo(width, height);
				}
				else
				{
					((BListView *)mpItem)->ResizeTo(mfWidthPref, height);
				}
			}
		}
		break;
		case KIND_MYBUTTON: 
		{
			((MyButton *)mpItem)->MyGetPreferredSize(&mfWidthPref, &mfHeightPref);
			//PreferredSize uses a huge pad--I dislike the wasted space
			((BButton *)mpItem)->ResizeTo(mfWidthPref, mfHeightPref);
			mfHeightPref++;
		}
		break;
		case KIND_MYSLIDER: 
		{
			((BSlider *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
			((BSlider *)mpItem)->ResizeTo(mfWidthPref, mfHeightPref);
			mfHeightPref++;
		}
		break;
		case KIND_MYSPACER:
			if (((MySpacer *)mpItem)->mbSAMEFromWidest)
			{
				((MySpacer *)mpItem)->MyGetPreferredSize(&mfWidthPref, &mfHeightPref);
			}
		break;
		case KIND_MYCHECKBOX: 
		{
			width += pad;
			((BCheckBox *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
			//PreferredSize uses a huge pad--I dislike the wasted space
			//so I compute width plus some small padding...
			if (width > mfWidthPref) 
			{
				mfWidthPref = width;
			}
			else 
			{
				width = mfWidthPref;
			}
			//then use the smaller width--might be good to perform
			//the same opperation for height, though the preferred 
			//height seems OK, and may be needed for the box height
			((BCheckBox *)mpItem)->ResizeTo(width, mfHeightPref);
		}
		break;
		case KIND_MYSTATUSBAR: 
			((MyStatusBar *)mpItem)->MyGetPreferredSize(&mfWidthPref, &mfHeightPref);
			mfHeightPref++;
		break;
		case KIND_MYCOLORCONTROL: 
		{
			((BColorControl *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
			((BColorControl *)mpItem)->ResizeTo(mfWidthPref, mfHeightPref);
			mfHeightPref++;
		}
		break;
		case KIND_MYRADIOVIEW: 
		{
			((MyRadioView *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
		}
		break;
		case KIND_UINT32CONTROL: 
		{
			bView->AddChild((UInt32Control *)mpItem);
			((UInt32Control *)mpItem)->SetAlignment(B_ALIGN_RIGHT, B_ALIGN_LEFT);
			((UInt32Control *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
			((UInt32Control *)mpItem)->SetDivider(width + cfAlignPad);
			mfWidthPref = width + ((UInt32Control *)mpItem)->mfTextViewWidth + cfAlignPad;
			((UInt32Control *)mpItem)->ResizeTo(mfWidthPref, mfHeightPref);
			bView->RemoveChild((UInt32Control *)mpItem);
		}
		break;
		case KIND_FLOATCONTROL: 
		{
			bView->AddChild((FloatControl *)mpItem);
			((FloatControl *)mpItem)->SetAlignment(B_ALIGN_RIGHT, B_ALIGN_LEFT);
			((FloatControl *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
			((FloatControl *)mpItem)->SetDivider(width + cfAlignPad);
			mfWidthPref = width + ((FloatControl *)mpItem)->mfTextViewWidth + cfAlignPad;
			((FloatControl *)mpItem)->ResizeTo(mfWidthPref, mfHeightPref);
			bView->RemoveChild((FloatControl *)mpItem);
		}
		break;
		case KIND_STRINGCONTROL: 
		{
			bView->AddChild((StringControl *)mpItem);
			((StringControl *)mpItem)->SetAlignment(B_ALIGN_RIGHT, B_ALIGN_LEFT);
			((StringControl *)mpItem)->GetPreferredSize(&mfWidthPref, &mfHeightPref);
			((StringControl *)mpItem)->SetDivider(width + cfAlignPad);
			mfWidthPref = width + ((StringControl *)mpItem)->mfTextViewWidth + cfAlignPad;
			((StringControl *)mpItem)->ResizeTo(mfWidthPref, mfHeightPref);
			bView->RemoveChild((StringControl *)mpItem);
		}
		break;
		case KIND_TEXT: 
		{
			mfWidthPref = width + pad;
		}
		break;
		case KIND_COLORWELL: 
		{
			((ColorWell *)mpItem)->mpLabelView->mfBaseline = baseline;
			((ColorWell *)mpItem)->mfTextOrigin = baseline / 2;
			if (((ColorWell *)mpItem)->mui8Height > height)
			{
				mfHeightPref = ((ColorWell *)mpItem)->mui8Height;
			}
			else
			{
				mfHeightPref = height;
			}
			((ColorWell *)mpItem)->mfHeight = height;
			((ColorWell *)mpItem)->SetTop(mfHeightPref);//store this temp value until time to really place item
			if (((ColorWell *)mpItem)->mpLabel)
			{
				mfWidthPref = width;
			}
			else
			{
				mfWidthPref = 0;
			}
			((ColorWell *)mpItem)->mfLabelWidth = mfWidthPref;
			mfWidthPref += ((ColorWell *)mpItem)->mui8Width + 1;
			((ColorWell *)mpItem)->SetLeft(((ColorWell *)mpItem)->mfLabelWidth + 3);
			uint8 framingWidth = ((ColorWell *)mpItem)->mui8Width;
			if (!(framingWidth % 2))
			{
				framingWidth--;
			}
			uint8 framingHeight = ((ColorWell *)mpItem)->mui8Height;
			if (!(framingHeight % 2))
			{
				framingHeight--;
			}
			((ColorWell *)mpItem)->ResizeTo(framingWidth, framingHeight);
		}
		break;
		case KIND_INT8GADGET: 
		case KIND_UINT8GADGET: 
		case KIND_INT16GADGET: 
		case KIND_UINT16GADGET: 
		case KIND_INT32GADGET: 
		case KIND_UINT32GADGET: 
		case KIND_INT64GADGET: 
		case KIND_UINT64GADGET: 
		case KIND_FLOATGADGET: 
		case KIND_HEXGADGET:
		case KIND_STRINGGADGET: 
		{
			((GadgetBase *)mpItem)->mfHeight = height;
			mfHeightPref = height;
			((GadgetBase *)mpItem)->mpLabelView->mfBaseline = baseline;
			if (((GadgetBase *)mpItem)->mpLabel)
			{
				mfWidthPref = width;
			}
			else
			{
				mfWidthPref = 0;
			}
			((GadgetBase *)mpItem)->mfLabelWidth = mfWidthPref;
			mfWidthPref += ((GadgetBase *)mpItem)->mfTextViewWidth + 1;
			((GadgetBase *)mpItem)->SetLeft(((GadgetBase *)mpItem)->mfLabelWidth + 3);
		}
		break;
	}
	bWindow->Run();
	bWindow->PostMessage(B_QUIT_REQUESTED);
}//end