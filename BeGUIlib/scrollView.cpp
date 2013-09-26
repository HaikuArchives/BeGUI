//scrollView.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "scrollView.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "layoutMatrix.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"

ScrollView	::	ScrollView(	BRect area) 
			: 	BView(	area, 
						"target", 
						B_FOLLOW_ALL, 
						B_WILL_DRAW | B_FULL_UPDATE_ON_RESIZE),
				mpTextItemList(new BList()),
				mpStringViewList(new BList())
{
	//leaving blank
}//end


ScrollView	::	~ScrollView() 
{
	delete mpTextItemList;
	int32 numStringViewListItems = mpStringViewList->CountItems();
	for (	int32 i = 0;
			i < numStringViewListItems;
			i++)
	{
		MyStringDrawer * holpMyStringDrawer = (MyStringDrawer *)mpStringViewList->ItemAt(i);
		delete holpMyStringDrawer;
	}
	delete mpStringViewList;
}//end


void 
ScrollView	::	AttachedToWindow(	void)
{
	BView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end


void 
ScrollView	::	Draw(	BRect ) 
{
	FillRect(Bounds());
	//need to learn how to DoForEach(), need to understand pointers to functions
	rgb_color originalHighColor(HighColor());
	rgb_color originalLowColor(LowColor());
	rgb_color originalViewColor(ViewColor());
	rgb_color newColor;
	myPrefs->GetPreferredMyStringDrawerHighColor(&newColor);
	SetHighColor(newColor);
	myPrefs->GetPreferredMyStringDrawerLowColor(&newColor);
	SetLowColor(newColor);
	myPrefs->GetPreferredMyStringDrawerViewColor(&newColor);
	SetViewColor(newColor);
	int32 numItems = mpTextItemList->CountItems();
	for (	int i = 0;
			i < numItems;
			i++)
	{
		TextItem * textItem = (TextItem *)mpTextItemList->ItemAt(i);
		MovePenTo(textItem->mfLeft, textItem->mfTop);
		DrawString(textItem->mpText);
	}
	numItems = mpStringViewList->CountItems();
	if (numItems)
	{
		for (	int i = 0;
				i < numItems;
				i++)
		{
			MyStringDrawer * myStringDrawer = (MyStringDrawer *)mpStringViewList->ItemAt(i);
			TextItem * textItem = myStringDrawer->GetTextItem();
			SetFont(myStringDrawer->GetFont());
			MovePenTo(textItem->mfLeft, textItem->mfTop);
			DrawString(textItem->mpText);
		}
	}
	SetHighColor(originalHighColor);
	SetLowColor(originalLowColor);
	SetViewColor(originalViewColor);
}//end