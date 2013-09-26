//myPopUpMenu

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "myPopUpMenu.h"
#include "myPopUpMenuData.h"
#include "warning.h"
#include "Preferences.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "myPreferences.h"
#include "myStringView.h"
#include "stringBoundsBox.h"

MyPopUpMenu	::	~MyPopUpMenu() 
{
	delete mpMenuName;
	delete mpLabel;
	//mpList deleted in Initialize()
};//end


//ctor
MyPopUpMenu	::	MyPopUpMenu(	const char * paramName, 
								const char * paramTitle,
								BList * paramList,
								bool paramIsRadioMode,
								const char * paramLabel,
								LayoutMatrix * paramLayoutMatrix) 
			: 
				BMenuBar(	BRect(0, 0, 32, 32), 
							paramName, 
							B_FOLLOW_NONE,
							B_ITEMS_IN_COLUMN),
				mpList(paramList),
				mpTitle(paramTitle),
				mbIsRadioMode(paramIsRadioMode),
				mfTop(0),
				mpLabel(NULL),
				mpMenuName(NULL),
				mfLabelHeight(0),
				mfLabelWidth(0),
				mfWidest(0),
				mfHeight(0)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYPOPUPMENU);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
		if (paramLabel)
		{
			rgb_color * rgbV = new rgb_color;
			myPrefs->GetPreferredColorWellViewColor(rgbV);
			rgb_color * rgbH = new rgb_color;
			myPrefs->GetPreferredColorWellHighColor(rgbH);
			rgb_color * rgbL = new rgb_color;
			myPrefs->GetPreferredColorWellLowColor(rgbL);
			mpLabelView = new MyStringView(	"PUMView", 
											paramLabel,
											NULL,
											rgbV,
											rgbH,
											rgbL);
			mpLabel = new BString(paramLabel);
		}
		if (paramName)
		{
			mpMenuName = new BString(paramName);
		}
		paramLayoutMatrix->AddToChildren((void *)this);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
}//end


//do all the real work of construction so we can Fail gracefully
bool 
MyPopUpMenu	::	Initialize(	void) 
{
	//sanity check:
	if (!mpList)
	{
		warning(myPrefs->FailPUMInit);
		return false;
	}
	int32 numItems = mpList->CountItems();
	if (!numItems) return true;
	try
	{
		BPopUpMenu * bpum = new BPopUpMenu(mpTitle);
		AddItem(bpum);
		bpum->SetRadioMode(mbIsRadioMode);
		BList * pMenuItemList = new BList(/*numItems*/);
		for (	int i = 0;
				i < numItems;
				i++)
		{
			PopUpMenuData * pumd = (PopUpMenuData *)mpList->ItemAt(i);
			BMessage * msg = new BMessage(BEGUIPUM);
			if (msg->AddString("menuName", mpMenuName->String()) != B_OK) 
			{
				warning(myPrefs->BMsgAddXFailPUMInit);
				throw;
			}
			if (msg->AddString("itemName", pumd->mLabel->String()) != B_OK)
			{
				warning(myPrefs->BMsgAddXFailPUMInit);
				throw;
			}
			BMenuItem * bmi = new BMenuItem(pumd->mLabel->String(), msg);
			bmi->SetMarked(pumd->mbSetMark);
			bpum->AddItem(bmi);
			pMenuItemList->AddItem((void *)pumd->mLabel->String());
		}
		menu_info menuInfo;
		get_menu_info(&menuInfo);
		BFont font;
		font.SetFamilyAndStyle(menuInfo.f_family, menuInfo.f_style);
		font.SetSize(menuInfo.font_size);
		float width;
		float height;
		float leftOffset;
		float baseline;
		if (!StringBoundsBox(	mpTitle,
								&width,
								&height,
								&leftOffset,
								&baseline,
								&font))
		{
			throw;
		}
		mfWidest = width;
		mfHeight = height;
		for (	int i = 0;
				i < numItems;
				i++)
		{
			const char * text = (const char *)pMenuItemList->ItemAt(i);
			if (!StringBoundsBox(	text,
									&width,
									&height,
									&leftOffset,
									&baseline,
									&font))
			{
				throw;
			}
			if (width > mfWidest) 
			{
				mfWidest = width;
			}
			if (height > mfHeight) 
			{
				mfHeight = height;
			}
		}
		if (mpLabel)
		{
			if (!StringBoundsBox(	mpLabel->String(),
									&width,
									&height,
									&leftOffset,
									&baseline,
									NULL))
			{
				throw;
			}
			mfLabelWidth = width;
			mpLabelView->mfBaseline = baseline;
			mfLabelHeight = height;
		}
	}
	catch (...)
	{
		for (	int i = 0;
				i < numItems;
				i++)
		{
			PopUpMenuData * pumd = (PopUpMenuData *)mpList->ItemAt(i);
			delete pumd;
		}
		delete mpList;
		warning(myPrefs->FailMemory);
		throw;
	}
	for (	int i = 0;
			i < numItems;
			i++)
	{
		PopUpMenuData * pumd = (PopUpMenuData *)mpList->ItemAt(i);
		delete pumd;
	}
	delete mpList;
	return true;
}//end


void
MyPopUpMenu	::	MyGetPreferredSize(	float * paramWidth,
									float * paramHeight)
{
	*paramWidth = mfWidest;
	*paramHeight = mfHeight;
}//end


void
MyPopUpMenu	::	SetLeft(	const float paramLeft)
{
	mfLeft = paramLeft;
}//end


float
MyPopUpMenu	::	GetLeft(	void) const
{
	return mfLeft;
}//end


PopUpMenuData	::	PopUpMenuData(	const char * paramLabel,
									BList * paramList,
									bool paramSetMark)
				:	mLabel(new BString(paramLabel)),
					mbSetMark(paramSetMark)
{
	paramList->AddItem((void *)this);
}//end


PopUpMenuData	::	~PopUpMenuData()
{
	delete mLabel;
}//end