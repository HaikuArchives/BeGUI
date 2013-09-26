//layoutMatrix.cpp

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
#include "myPopUpMenu.h"
#include "myPopUpMenuData.h"
#include "myRadioView.h"
#include "myRadioViewData.h"
#include "myTextView.h"
#include "myStatusBar.h"
#include "myListView.h"
#include "baseWindow.h"
#include "layoutMatrix.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "myColorControl.h"
#include "mySlider.h"
#include "mySpacer.h"
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
#include "scrollingWindow.h"
#include "baseWindow.h"

//ctor for ScrollingWindow
LayoutMatrix	::	LayoutMatrix(	const uint32 paramFlags, 
									const uint32 paramRows, 
									const uint32 paramColumns,
									ScrollingWindow * paramScrollingWindow)
				: 	mpItemsList(new BList()),
					mpChildrenToAdd(new BList()),
					mpItemsToDraw(new BList()),
					mpLayoutMatrixItems(new BList()),
					mfBottom(0),
					mfRight(0),
					mui32Rows(paramRows), 
					mui32Columns(paramColumns), 
					mui32Flags(paramFlags)
{
	paramScrollingWindow->AddToLayoutMatrixList(this);
}//end


//ctor for 
LayoutMatrix	::	LayoutMatrix(	const uint32 paramFlags, 
									const uint32 paramRows, 
									const uint32 paramColumns,
									BaseWindow * paramBaseWindow)
				: 	mpItemsList(new BList()),
					mpChildrenToAdd(new BList()),
					mpItemsToDraw(new BList()),
					mpLayoutMatrixItems(new BList()),
					mfBottom(0),
					mfRight(0),
					mui32Rows(paramRows), 
					mui32Columns(paramColumns), 
					mui32Flags(paramFlags)
{
	paramBaseWindow->AddToLayoutMatrixList(this);
}//end


//dtor
LayoutMatrix	::	~LayoutMatrix() 
{
	delete mpChildrenToAdd;
	delete mpItemsToDraw;
	LayoutMatrixItem * lmi = (LayoutMatrixItem *)mpLayoutMatrixItems->LastItem();
	while (lmi)
	{
		mpLayoutMatrixItems->RemoveItem((void *)lmi);
		delete lmi;
		lmi = (LayoutMatrixItem *)mpLayoutMatrixItems->LastItem();
	}
}//end


//calculate the view positions of all the MatrixLayoutItems
//on the items list with offsets based upon matrixLeft
//and matrixTop
void 
LayoutMatrix	::	Calc(	const float paramMatrixLeft,  
							const float paramMatrixTop,
							sem_id paramSemID) 
{
	int32 numItems = mpItemsList->CountItems();
	if (!numItems) return;
	if (acquire_sem(paramSemID) != B_NO_ERROR)
	{
		warning(myPrefs->FailAqSem);
		return;
	}
	bool hasPopUpMenu = false;
	TextItem *	scratchTextItem;
	for (	int i = 0;
			i < numItems;
			i++)
	{
		((LayoutMatrixItem *)(mpItemsList->ItemAt(i)))->Calc();
	}
	float widest = 0;
	float tallest = 0;
	int32 index = 0;
	for (	int i = 0;
			i < numItems;
			i++)
	{
		LayoutMatrixItem * lmi = (LayoutMatrixItem *)mpItemsList->ItemAt(index++);
		if (lmi->mfWidthPref > widest) 
		{
			widest = lmi->mfWidthPref;
		}
		if (lmi->mfHeightPref > tallest) 
		{
			tallest = lmi->mfHeightPref;
		}
	}
	if (mui32Flags & SAMESIZE) 
	{//SAMESIZE makes all items the same size as the largest
		index = 0;
		//Resize all items to match largest:
		for (	uint32 i = 0;
				i < mui32Rows;
				i++) 
		{
			for (	uint32 j = 0;
					j < mui32Columns;
					j++) 
			{
				LayoutMatrixItem * lmi = (LayoutMatrixItem *)mpItemsList->ItemAt(index++);
				switch (lmi->mui32Kind)
				{
					case KIND_MYSPACER:
					{
						MySpacer * scratchMySpacer = (MySpacer *)lmi->mpItem;
						if (scratchMySpacer->mbSAMEFromWidest)
						{
							scratchMySpacer->ResizeTo(widest, tallest);
						}
					}
					break;
					case KIND_MYBUTTON:
					{
						BButton * scratchMyButton = (BButton *)lmi->mpItem;
						scratchMyButton->ResizeTo(widest, tallest);
					}
					break;
					case KIND_MYSLIDER:
					{
						BSlider * scratchMySlider = (BSlider *)lmi->mpItem;
						scratchMySlider->ResizeTo(widest, tallest);
					}
					break;
					case KIND_STRINGDRAWER:
					{
						BStringView * scratchMyStringView = (BStringView *)lmi->mpItem;
						scratchMyStringView->ResizeTo(widest, tallest);
					}
					break;
					case KIND_MYCHECKBOX:
					{
						BCheckBox * scratchMyCheckBox = (BCheckBox *)lmi->mpItem;
						scratchMyCheckBox->ResizeTo(widest, tallest);
					}
					break;
					case KIND_MYPICTUREBUTTON:
					{
						BPictureButton * scratchMyPictureButton = (BPictureButton *)lmi->mpItem;
						scratchMyPictureButton->ResizeTo(widest, tallest);
					}
					break;
					case KIND_MYCOLORCONTROL:
					{
						BColorControl * scratchMyColorControl = (BColorControl *)lmi->mpItem;
						scratchMyColorControl->ResizeTo(widest, tallest);
					}
					break;
					case KIND_MYSTATUSBAR:
					{
						BStatusBar * scratchMyStatusBar = (BStatusBar *)lmi->mpItem;
						scratchMyStatusBar->ResizeTo(widest, tallest);
					}
					break;
					case KIND_UINT32CONTROL:
					{
						UInt32Control * scratchUInt32Control = (UInt32Control *)lmi->mpItem;
						scratchUInt32Control->ResizeTo(widest, tallest);
					}
					break;
					case KIND_FLOATCONTROL:
					{
						FloatControl * scratchFloatControl = (FloatControl *)lmi->mpItem;
						scratchFloatControl->ResizeTo(widest, tallest);
					}
					break;
					case KIND_STRINGCONTROL:
					{
						StringControl * scratchStringControl = (StringControl *)lmi->mpItem;
						scratchStringControl->ResizeTo(widest, tallest);
					}
					break;
				}
			}
		}
	}
	index = 0;
	//move every item based upon size and padding:
	const float hpad = 2;//horizontal spacing between items
	const float vpad = 2;//vertical spacing between items
	float localLeft;
	float localTop = vpad + paramMatrixTop;
	float excessRight = 0, excessRightHold = 0;
	float excessBottom = 0, excessBottomHold = 0;
	for (	uint32 ii = 0;
			ii < mui32Rows;
			ii++) 
	{
		localLeft = paramMatrixLeft + hpad;
		float columnRight = 0;
		excessBottom = 0;
		for (	uint32 jj = 0;
				jj < mui32Columns;
				jj++) 
		{
			excessRight = 0;
			LayoutMatrixItem * lmi = (LayoutMatrixItem *)mpItemsList->ItemAt(index++);
			switch (lmi->mui32Kind) 
			{
				case KIND_MYPOPUPMENU:
				{
					hasPopUpMenu = true;
					MyPopUpMenu * scratchPopUpMenu = (MyPopUpMenu *)lmi->mpItem;
					scratchPopUpMenu->mfLabelLeft = localLeft;
					excessRightHold = lmi->mfWidthPref + scratchPopUpMenu->mfLabelWidth;
					scratchPopUpMenu->SetLeft(localLeft);
					scratchPopUpMenu->mfLabelTop = localTop;
					if ((scratchPopUpMenu->mfHeight + 9) > scratchPopUpMenu->mfLabelHeight)
					{
						excessBottomHold = scratchPopUpMenu->mfHeight + 10;
					}
					else
					{
						excessBottomHold = scratchPopUpMenu->mfLabelHeight + 1;
					}
				}
				break;
				case KIND_MYTEXTVIEW:
				{
					BTextView * scratchTextView = (BTextView *)lmi->mpItem;
					scratchTextView->MoveTo(localLeft, localTop);
					excessRightHold = ((MyTextView *)scratchTextView)->mfWidth;
					excessBottomHold = ((MyTextView *)scratchTextView)->mfHeight;
				}
				break;
				case KIND_MYLISTVIEW:
				{
					BListView * scratchListView = (BListView *)lmi->mpItem;
					scratchListView->MoveTo(localLeft, localTop);
					((BListView *)(lmi->mpItem))->GetPreferredSize(&excessRightHold, &excessBottomHold);
				}
				break;
				case KIND_MYBUTTON:
				{
					BButton * scratchMyButton = (BButton *)lmi->mpItem;
					scratchMyButton->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_MYSLIDER:
				{
					BSlider * scratchMySlider = (BSlider *)lmi->mpItem;
					scratchMySlider->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_MYSPACER:
				{
					MySpacer * scratchMySpacer = (MySpacer *)lmi->mpItem;
					if (	(mui32Flags & SAMESIZE) 
							&& 
							scratchMySpacer->mbSAMEFromWidest)
					{
						excessRightHold = widest;
						excessBottomHold = tallest;
					}
					else
					{
						excessRightHold = scratchMySpacer->mfPreferredWidth;
						excessBottomHold = scratchMySpacer->mfPreferredHeight;
					}
				}
				break;
				case KIND_MYRADIOVIEW:
				{
					MyRadioView * scratchRadioView = (MyRadioView *)lmi->mpItem;
					scratchRadioView->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_STRINGDRAWER:
				{
					BStringView * scratchMyStringView = (BStringView *)lmi->mpItem;
					TextItem * scratchTextItem = ((MyStringDrawer *)lmi->mpItem)->GetTextItem();
					scratchTextItem->mfLeft = localLeft;
					scratchTextItem->mfTop = localTop + lmi->mfHeightPref - ((MyStringDrawer *)lmi->mpItem)->mfDescender - vpad;
					scratchMyStringView->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_MYCHECKBOX:
				{
					BCheckBox * scratchMyCheckBox = (BCheckBox *)lmi->mpItem;
					scratchMyCheckBox->MoveTo(localLeft, localTop + 1);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref + 1;
				}
				break;
				case KIND_MYPICTUREBUTTON:
				{
					BPictureButton * scratchMyPictureButton = (BPictureButton *)lmi->mpItem;
					scratchMyPictureButton->MoveTo(localLeft, localTop);
					excessRightHold = scratchMyPictureButton->Bounds().Width() + 1;
					excessBottomHold = scratchMyPictureButton->Bounds().Height() + 1;
				}
				break;
				case KIND_MYCOLORCONTROL:
				{
					BColorControl * scratchMyColorControl = (BColorControl *)lmi->mpItem;
					scratchMyColorControl->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
					;
				}
				break;
				case KIND_MYSTATUSBAR:
				{
					MyStatusBar * scratchMyStatusBar = (MyStatusBar *)lmi->mpItem;
					scratchMyStatusBar->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_UINT32CONTROL:
				{
					UInt32Control * scratchUInt32Control = (UInt32Control *)lmi->mpItem;
					scratchUInt32Control->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_FLOATCONTROL:
				{
					FloatControl * scratchFloatControl = (FloatControl *)lmi->mpItem;
					scratchFloatControl->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_STRINGCONTROL:
				{
					StringControl * scratchStringControl = (StringControl *)lmi->mpItem;
					scratchStringControl->MoveTo(localLeft, localTop);
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				}
				break;
				case KIND_TEXT:
					scratchTextItem = (TextItem *)lmi->mpItem;
					scratchTextItem->mfLeft = localLeft;
					scratchTextItem->mfTop = localTop + lmi->mfHeightPref;
					excessRightHold = lmi->mfWidthPref;
					excessBottomHold = lmi->mfHeightPref;
				break;
				case KIND_COLORWELL:
					((ColorWell *)lmi->mpItem)->mfLabelLeft = localLeft;
					((ColorWell *)lmi->mpItem)->SetLeft(((ColorWell *)lmi->mpItem)->GetLeft() + localLeft);
					excessRightHold = lmi->mfWidthPref;
					((ColorWell *)lmi->mpItem)->mfLabelTop = localTop;
					((ColorWell *)lmi->mpItem)->SetTop(((ColorWell *)lmi->mpItem)->GetTop() + localTop);
					excessBottomHold = lmi->mfHeightPref;
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
					((GadgetBase *)lmi->mpItem)->mfLabelLeft = localLeft;
					((GadgetBase *)lmi->mpItem)->SetLeft(((GadgetBase *)lmi->mpItem)->GetLeft() + localLeft);
					excessRightHold = lmi->mfWidthPref;
					((GadgetBase *)lmi->mpItem)->mfLabelTop = localTop;
					((GadgetBase *)lmi->mpItem)->SetTop(((GadgetBase *)lmi->mpItem)->GetTop() + localTop);
					excessBottomHold = lmi->mfHeightPref + 1;
				break;
			}
			if (mui32Flags & SAMESIZE)
			{
				excessRightHold = widest;
				excessBottomHold = tallest;
			}
			excessRightHold += hpad;
			if (excessRightHold > excessRight)
			{
				excessRight = excessRightHold;
			}
			localLeft += excessRight;
			if (mui32Columns - 1) 
			{
				if (jj != (mui32Columns - 1)) 
				{
					if (localLeft > columnRight) 
					{
						columnRight = localLeft;
					}
				}
				else 
				{
					columnRight = localLeft;
				}
			}
			else 
			{
				if (localLeft > columnRight) 
				{
					columnRight = localLeft;
				}
			}
			//mfRight is stored so that another MatrixLayout
			//can know where a previous one ended up
			if (excessBottomHold > excessBottom)
			{
				excessBottom = excessBottomHold;
			}
		}
		if (columnRight > mfRight)
		{
			mfRight = columnRight;
		}
		excessBottomHold += vpad;
		localTop += excessBottom;
		if (mui32Rows - 1) 
		{
			if (ii != (mui32Rows - 1)) 
			{
				if (localTop > mfBottom) 
				{
					mfBottom = localTop;
				}
			}
			else 
			{
				mfBottom = localTop;
			}
		}
		else 
		{
			if (localTop > mfBottom) 
			{
				mfBottom = localTop;
			}
		}
		//mfBottom is stored so that another MatrixLayout
		//can know where a previous one ended up
	}
	if (hasPopUpMenu)
	{
		mfRight += 30;
	}
	release_sem(paramSemID);
}//end


void
LayoutMatrix	::	AddToChildren(	void * paramItem) 
{
	mpChildrenToAdd->AddItem(paramItem);
}//end


void
LayoutMatrix	::	AddToDraw(	void * paramItem) 
{
	mpItemsToDraw->AddItem(paramItem);
}//end
