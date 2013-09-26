//myListView.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "Preferences.h"
#include "myroColour.h"
#include "dataNode.h"
#include "myListView.h"
#include "warning.h"
#include "dataList.h"
#include "myPreferences.h"
#include "stringBoundsBox.h"

MyListView	::	~MyListView() 
{
	//leaving blank
};//end


//ctor
MyListView	::	MyListView(	const char * paramName,
							DataList * paramDataList,
							uint32 paramSelectMsg,
							uint32 paramInvokeMsg,
							list_view_type paramSelectType,
							LayoutMatrix * paramLayoutMatrix) 
				: 
					BListView(	BRect(0,0,32,32), 
								paramName, 
								paramSelectType, 
								B_FOLLOW_LEFT | B_FOLLOW_TOP, 
								B_WILL_DRAW | B_NAVIGABLE | B_FRAME_EVENTS),
					mfWidth(0),
					mfHeight(0)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYLISTVIEW);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	try
	{
		float tempWidth = 0;
		float tempHeight = 0;
		float leftOffset;
		float baseline;
		DataNode * node;
		//#pragma warn_possunwant off
		for (	int32 i = 0; 
				node = (DataNode *)paramDataList->mpList->ItemAt(i); 
				i++) 
		{
		//#pragma warn_possunwant reset
			const char * name = node->GetText();
			BStringItem * bsi = new BStringItem(name);
			AddItem(bsi);
			bsi->SetEnabled(true);
			if (!StringBoundsBox(	name,
									&tempWidth,
									&tempHeight,
									&leftOffset,
									&baseline))
			{
				throw;
			}
			if (tempWidth > mfWidth)
			{
				mfWidth = tempWidth;
			}
			if (tempHeight > mfHeight)
			{
				mfHeight = tempHeight;
			}
		}
		tempHeight = mfHeight;
		mfHeight *= paramDataList->mpList->CountItems();
		tempHeight *= .5;
		mfHeight += tempHeight;
		if (!StringBoundsBox(	"ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890",
								&tempWidth,
								&tempHeight,
								&leftOffset,
								&baseline))
		{
			throw;
		}
		tempWidth /= 36;
		mfWidth += (tempWidth / 2);
		if (paramSelectMsg)
		{
			SetSelectionMessage(new BMessage(paramSelectMsg));
		}
		if (paramInvokeMsg)
		{
			SetInvocationMessage(new BMessage(paramInvokeMsg));
		}
		rgb_color viewColor;
		myPrefs->GetPreferredMyListViewViewColor(&viewColor);
		SetViewColor(viewColor);
		myPrefs->GetPreferredMyListViewHighColor(&viewColor);
		SetHighColor(viewColor);
		myPrefs->GetPreferredMyListViewLowColor(&viewColor);
		SetLowColor(viewColor);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		throw;
	}
}//end


void 
MyListView	::	AttachedToWindow(	void)
{
	BListView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyListViewViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	myPrefs->GetPreferredMyListViewHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyListViewLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
}//end


void
MyListView	::	MyGetPreferredSize(	float * paramWidth,
									float * paramHeight)
{
	*paramHeight = mfHeight;
	*paramWidth = mfWidth;
}//end