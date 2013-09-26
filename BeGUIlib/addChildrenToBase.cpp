//addChildrenToBase.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "addChildrenToBase.h"
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
#include "hexGadget.h"
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

void
AddChildrenToBase(	BList * paramBList,
					BView * paramBView,
					int32 paramNumItems,
					BList * paramBListSVL,
					BList * paramBListTIL,
					BLooper * paramLooper)
{
	int32 numLayoutMatrixListItems = paramBList->CountItems();
	for (	int32 j = 0;
			j < numLayoutMatrixListItems;
			j++)
	{
		LayoutMatrix * holdLayoutMatrix = (LayoutMatrix *)paramBList->ItemAt(j);
		int32 numThingsTo = holdLayoutMatrix->mpChildrenToAdd->CountItems();
		for (	int32 intd = 0;
				intd < numThingsTo;
				intd++)
		{
			BView * item = (BView *)holdLayoutMatrix->mpChildrenToAdd->ItemAt(intd);
			MyButton * myButton = dynamic_cast<MyButton *>(item);
			GadgetBase * gadgetBase = dynamic_cast<GadgetBase *>(item);
			UInt32Control * uInt32Control = dynamic_cast<UInt32Control *>(item);
			FloatControl * floatControl = dynamic_cast<FloatControl *>(item);
			MyPopUpMenu * myPopUpMenu = dynamic_cast<MyPopUpMenu *>(item);
			MyTextView * myTextView = dynamic_cast<MyTextView *>(item);
			StringControl * stringControl = dynamic_cast<StringControl *>(item);
			MyCheckBox * myCheckBox = dynamic_cast<MyCheckBox *>(item);
			MyPictureButton * myPictureButton = dynamic_cast<MyPictureButton *>(item);
			TextItem * textItem = dynamic_cast<TextItem *>(item);
			ColorWell * colorWell = dynamic_cast<ColorWell *>(item);
			MyColorControl * myColorControl = dynamic_cast<MyColorControl *>(item);
			MyStatusBar * myStatusBar = dynamic_cast<MyStatusBar *>(item);
			MyStringDrawer * myStringDrawer = dynamic_cast<MyStringDrawer *>(item);
			MyRadioView * myRadioView = dynamic_cast<MyRadioView *>(item);
			MyListView * myListView = dynamic_cast<MyListView *>(item);
			MySpacer * mySpacer = dynamic_cast<MySpacer *>(item);
			MySlider * mySlider = dynamic_cast<MySlider *>(item);
			if (gadgetBase)
			{
				if (gadgetBase->mpLabelView)
				{
					gadgetBase->mpLabelView->MoveTo(gadgetBase->mfLabelLeft, gadgetBase->mfLabelTop);
					gadgetBase->mpLabelView->ResizeTo(gadgetBase->mfLabelWidth + 1, gadgetBase->mfHeight);
					gadgetBase->mpLabelView->SetFont(myPrefs->GetPreferredFont());
					paramBView->AddChild(gadgetBase->mpLabelView);
				}
				gadgetBase->MoveTo(gadgetBase->GetLeft(), gadgetBase->GetTop());
				gadgetBase->ResizeTo(gadgetBase->mfTextViewWidth, gadgetBase->mfHeight);
				BRect textRect(gadgetBase->Bounds());
				textRect.top -= 2;
				textRect.bottom -= 2;
				gadgetBase->SetTextRect(textRect);
				paramBView->AddChild(gadgetBase);
			}
			else if (myButton)
			{
				paramBView->AddChild(myButton);
			}
			else if (mySlider)
			{
				paramBView->AddChild(mySlider);
			}
			else if (floatControl)
			{
				paramBView->AddChild(floatControl);
				floatControl->SetTarget(paramLooper);
			}
			else if (uInt32Control)
			{
				paramBView->AddChild(uInt32Control);
				uInt32Control->SetTarget(paramLooper);
			}
			else if (myPopUpMenu)
			{
				if (myPopUpMenu->mpLabelView)
				{
					myPopUpMenu->mpLabelView->MoveTo(myPopUpMenu->mfLabelLeft, myPopUpMenu->mfLabelTop);
					myPopUpMenu->mpLabelView->ResizeTo(myPopUpMenu->mfLabelWidth + 1, myPopUpMenu->mfLabelHeight);
					myPopUpMenu->mpLabelView->SetFont(myPrefs->GetPreferredFont());
					paramBView->AddChild(myPopUpMenu->mpLabelView);
				}
				myPopUpMenu->MoveTo(myPopUpMenu->GetLeft() + myPopUpMenu->mfLabelWidth + 2, myPopUpMenu->mfLabelTop);
				paramBView->AddChild(myPopUpMenu);
			}
			else if (myTextView)
			{
				BRect textRect(myTextView->Bounds());
				textRect.top -= 3;
				textRect.bottom -= 3;
				myTextView->SetTextRect(textRect);
				paramBView->AddChild(myTextView);
			}
			else if (stringControl)
			{
				paramBView->AddChild(stringControl);
			}
			else if (myCheckBox)
			{
				paramBView->AddChild(myCheckBox);
			}
			else if (myPictureButton)
			{
				paramBView->AddChild(myPictureButton);
			}
			else if (colorWell)
			{
				if (colorWell->mpLabelView)
				{
					colorWell->mpLabelView->MoveTo(colorWell->mfLabelLeft, colorWell->mfLabelTop);
					colorWell->mpLabelView->ResizeTo(colorWell->mfLabelWidth, colorWell->mfHeight);
					colorWell->mpLabelView->SetFont(myPrefs->GetPreferredFont());
					paramBView->AddChild(colorWell->mpLabelView);
				}
				colorWell->MoveTo(colorWell->GetLeft(), colorWell->GetTop() - colorWell->mui8Height);
				paramBView->AddChild(colorWell);
			}
			else if (myColorControl)
			{
				paramBView->AddChild(myColorControl);
			}
			else if (myStatusBar)
			{
				paramBView->AddChild(myStatusBar);
			}
			else if (myStringDrawer)
			{
				paramBListSVL->AddItem((void *)myStringDrawer);
			}
			else if (myRadioView)
			{
				paramBView->AddChild(myRadioView);
			}
			else if (myListView)
			{
				paramBView->AddChild(myListView);
			}
			else if (textItem)
			{
				//nothing to do
			}
			else if (mySpacer)
			{
				//nothing to do
			}
			else
			{
				warning(myPrefs->WrongKindLMI);
			}
		}
		numThingsTo = holdLayoutMatrix->mpItemsToDraw->CountItems();
		for (	int32 i = 0;
				i < numThingsTo;
				i++)
		{
			paramBListTIL->AddItem(holdLayoutMatrix->mpItemsToDraw->ItemAt(i));
		}
	}
	//paramNumItems = paramBList->CountItems();
	for (	int32 i = 0;
			i < paramNumItems;
			i++)
	{
		delete (LayoutMatrix *)paramBList->ItemAt(i);
	}
	delete paramBList;
}//end