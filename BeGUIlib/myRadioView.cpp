//myRadioView

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "myRadioView.h"
#include "myRadioViewData.h"
#include "warning.h"
#include "Preferences.h"
#include "layoutMatrix.h"
#include "myPreferences.h"

MyRadioView	::	~MyRadioView() 
{
	//leaving blank
	//mpList deleted in Initialize()
};//end


//ctor
MyRadioView	::	MyRadioView(	const char * paramName, 
								bool paramVertical,
								BList * paramList,
								BFont * paramFont,
								LayoutMatrix * paramLayoutMatrix) 
			: 
				BView(	BRect(0, 0, 32, 32), 
						paramName, 
						B_FOLLOW_NONE, 
						B_WILL_DRAW),
				mbVertical(paramVertical),
				mpList(paramList),
				mpFont(paramFont)
{
	paramLayoutMatrix->AddToChildren((void *)this);
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYRADIOVIEW);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
}//end


//do all the real work of construction so we can Fail gracefully
bool 
MyRadioView	::	Initialize(	void) 
{
	//sanity check:
	if (	!mpList 
			|| 
			!mpFont)
	{
		warning(myPrefs->FailRadioInit);
		return false;
	}
	int32 numItems = mpList->CountItems();
	if (!numItems) return true;
	SetFont(mpFont);
	try
	{
		auto_ptr<BList> apButtonList(new BList(/*numItems*/));
		BList * pButtonList = apButtonList.get();
		BRadioButton * holdBRB;
		bool oneSelected = false;
		for (	int i = 0;
				i < numItems;
				i++)
		{
			RadioViewData * rvd = (RadioViewData *)mpList->ItemAt(i);
			BRadioButton * brb = new BRadioButton(	BRect(0, 0, 32, 32), 
													rvd->mLabel,
													rvd->mLabel,
													rvd->mpMsg,
													B_FOLLOW_NONE,
													B_WILL_DRAW);
			if (i == 0)
			{
				holdBRB = brb;
			}
			AddChild(brb);
			if (rvd->mbSelected)
			{
				brb->SetValue(B_CONTROL_ON);
				oneSelected = true;
			}
			brb->ResizeToPreferred();
			pButtonList->AddItem((void *)brb);
		}
		if (!oneSelected)
		{
			holdBRB->SetValue(B_CONTROL_ON);
		}
		float pad = 2;
		float localLeft = pad;
		float localTop = pad;
		float widest = 0;
		float tallest = 0;
		float width;
		float height;
		for (	int i = 0;
				i < numItems;
				i++)
		{
			BRadioButton * brb = (BRadioButton *)pButtonList->ItemAt(i);
			brb->MoveTo(localLeft, localTop);
			width = brb->Frame().IntegerWidth();
			height = brb->Frame().IntegerHeight();
			if (width > widest) widest = width;
			if (height > tallest) tallest = height;
			if (mbVertical)
			{
				localTop = localTop + pad + height;
			}
			else//orient horizontal
			{
				localLeft = localLeft + pad + width;
			}
		}
		if (localTop != pad)
		{
			ResizeTo(widest + pad, localTop - pad);
		}
		else//orient horizontal
		{
			ResizeTo(localLeft - pad, tallest + pad);
		}
	}
	catch (...)
	{
		for (	int i = 0;
				i < numItems;
				i++)
		{
			RadioViewData * rvd = (RadioViewData *)mpList->ItemAt(i);
			delete rvd;
		}
		delete mpList;
		warning(myPrefs->FailMemory);
		return false;
	}
	for (	int i = 0;
			i < numItems;
			i++)
	{
		RadioViewData * rvd = (RadioViewData *)mpList->ItemAt(i);
		delete rvd;
	}
	delete mpList;
	return true;
}//end


void 
MyRadioView	::	AttachedToWindow(	void)
{
	BView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyRadioViewHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyRadioViewLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredMyRadioViewViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end


RadioViewData	::	RadioViewData(	uint32 paramMessageValue, 
									const char * paramLabel,
									BList * paramList,
									bool paramSelected)
				:	mbSelected(paramSelected),
					mpMsg(new BMessage(paramMessageValue)),
					mLabel(paramLabel)
{
	paramList->AddItem((void *)this);
}//end


RadioViewData	::	~RadioViewData()
{
	//leaving blank
}