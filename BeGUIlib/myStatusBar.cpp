//myStatusBar.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "myStatusBar.h"
#include "layoutMatrix.h"
#include "warning.h"
#include "stringBoundsBox.h"

MyStatusBar	::	~MyStatusBar() 
{
	//leaving blank
};//end


//ctor
MyStatusBar	::	MyStatusBar(	const char * paramName,
								const char * paramLabel,
								const char * paramTrailingLabel,
								float paramMaxValue,
								float paramValue,
								LayoutMatrix * paramLayoutMatrix) 
				: 
					BStatusBar(	BRect(1, 1, 32, 32),
								paramName,
								paramLabel,
								paramTrailingLabel),
					mfValue(paramValue),
					mfMaxValue(paramMaxValue)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYSTATUSBAR);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	};
	paramLayoutMatrix->AddToChildren((void *)this);
	SetFont(myPrefs->GetPreferredFont());
}//end


void
MyStatusBar	::	MyGetPreferredSize(	float * paramWidth,
									float * paramHeight)
{
	float leftOffset;
	float baseline;
	float width;
	float height;
	*paramHeight = myPrefs->GetPreferredBarHeight();
	if (!StringBoundsBox(	"MM",//needs some padding;
							&width,
							&height,
							&leftOffset,
							&baseline))
	{
		throw;
	}
	*paramWidth = width;
	if (Text())
	{
		if (!StringBoundsBox(	Text(),
								&width,
								&height,
								&leftOffset,
								&baseline))
		{
			throw;
		}
		*paramWidth += width;
	}
	if (TrailingText())
	{
		if (!StringBoundsBox(	TrailingText(),
								&width,
								&height,
								&leftOffset,
								&baseline))
		{
			throw;
		}
		*paramWidth += width;
	}
	if (Label())
	{
		if (!StringBoundsBox(	Label(),
								&width,
								&height,
								&leftOffset,
								&baseline))
		{
			throw;
		}
		*paramWidth += width;
	}
	if (TrailingLabel())
	{
		if (!StringBoundsBox(	TrailingLabel(),
								&width,
								&height,
								&leftOffset,
								&baseline))
		{
			throw;
		}
		*paramWidth += width;
	}
	SetBarHeight(*paramHeight);
	*paramHeight += (height + 2);
	mfWidthPref = *paramWidth;
	mfHeightPref = *paramHeight;
}//end


void 
MyStatusBar	::	AttachedToWindow(	void)
{
	BStatusBar::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyStatusBarHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyStatusBarLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredMyStatusBarViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	myPrefs->GetPreferredMyBarStatusColor(&tempRgbColor);
	SetBarColor(tempRgbColor);
	BString label(Label());
	BString trailingLabel(TrailingLabel());
	Reset(label.String(), trailingLabel.String());
	SetMaxValue(mfMaxValue);
	ResizeTo(mfWidthPref, mfHeightPref);
	Update(mfValue);
}//end