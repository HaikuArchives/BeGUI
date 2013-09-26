//myStringView.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myStringView.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "myPreferences.h"
#include "warning.h"

MyStringView	::	~MyStringView() 
{
	delete mpFont;
	delete mrgbViewColor;
	delete mrgbHighColor;
	delete mrgbLowColor;
	
};//end


//ctor
MyStringView	::	MyStringView(	const char * paramName, 
									const char * paramText,
									BFont * paramFont,
									rgb_color * paramViewColor,
									rgb_color * paramHighColor,
									rgb_color * paramLowColor) 
				: 
					BView(	BRect(0, 0, 32, 32),
									paramName, 
									B_FOLLOW_NONE,
									B_WILL_DRAW),
					mpFont(paramFont),
					mrgbViewColor(paramViewColor),
					mrgbHighColor(paramHighColor),
					mrgbLowColor(paramLowColor),
					mfBaseline(0),
					mbsText(paramText)
					
{
	try 
	{
		if (!paramFont)
		{
			mpFont = new BFont(myPrefs->GetPreferredFont());
		}
		SetFont(mpFont);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
	}
}//end


void 
MyStringView	::	AttachedToWindow(	void) 
{
	BView::AttachedToWindow();
	rgb_color rgb;
	if (mrgbHighColor)
	{
		SetHighColor(*mrgbHighColor);
	}
	else
	{
		//myPrefs->GetPreferredHighColor(&rgb);
		myPrefs->GetPreferredMyStringDrawerHighColor(&rgb);
		SetHighColor(rgb);
	}
	if (mrgbLowColor)
	{
		SetLowColor(*mrgbLowColor);
	}
	else
	{
		//myPrefs->GetPreferredLowColor(&rgb);
		myPrefs->GetPreferredMyStringDrawerLowColor(&rgb);
		SetLowColor(rgb);
	}
	if (mrgbViewColor)
	{
		SetViewColor(*mrgbViewColor);
	}
	else
	{
		//myPrefs->GetPreferredViewColor(&rgb);
		myPrefs->GetPreferredMyStringDrawerViewColor(&rgb);
		SetViewColor(rgb);
	}
}//end


void
MyStringView	::	Draw(	BRect paramRect)
{
	BView::Draw(paramRect);
	MovePenTo(0, mfBaseline);
	DrawString(mbsText.String());
}//end