//myStringDrawer.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myStringDrawer.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "myPreferences.h"
#include "warning.h"
#include "stringBoundsBox.h"

MyStringDrawer	::	~MyStringDrawer() 
{
	delete mpTextItem;
	delete mpFont;
};//end


//ctor
MyStringDrawer	::	MyStringDrawer(	const char * paramName, 
									const char * paramText,
									LayoutMatrix * paramLayoutMatrix,
									BFont * paramFont) 
				: 
					BStringView(	BRect(0, 0, 32, 32),
									paramName, 
									paramText,
									B_FOLLOW_NONE,
									B_WILL_DRAW),
					mpTextItem(	new TextItem(	paramText,
												NULL/*paramLayoutMatrix*/))
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_STRINGDRAWER);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	if (paramFont)
	{
		mpFont = paramFont;
	}
	else
	{
		mpFont = new BFont(myPrefs->GetPreferredFont());
	}
	SetFont(mpFont);
}//end


void 
MyStringDrawer	::	AttachedToWindow(	void)
{
	BStringView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyStringDrawerHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyStringDrawerLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredMyStringDrawerViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end


void
MyStringDrawer	::	MyGetPreferredSize(	float * paramWidth,
										float * paramHeight)
{
	float leftOffset;
	float baseline;
	float width;
	float height;
	if (!StringBoundsBox(	((BStringView *)this)->Text(),
							&width,
							&height,
							&leftOffset,
							&baseline,
							mpFont))
	{
		throw;
	}
	mfDescender = height - baseline;
	*paramHeight = height + 1;
	*paramWidth = width;
	float shear = mpFont->Shear();
	//shear will always be between 45 and 135
	if (shear < 90)
	{
		SetAlignment(B_ALIGN_RIGHT);
	}
	else if (shear > 90)
	{
		SetAlignment(B_ALIGN_LEFT);
	}
}//end


BFont *
MyStringDrawer	::	GetFont(	void) const
{
	return mpFont;
}//end


TextItem *
MyStringDrawer	::	GetTextItem(	void) const
{
	return mpTextItem;
}//end
