//colorWell.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "colorWell.h"
#include "Preferences.h"
#include "myroColour.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "myPreferences.h"
#include "warning.h"
#include "myStringView.h"


ColorWell	::	~ColorWell() 
{
	//leaving blank
};//end


//ctor
ColorWell	::	ColorWell(	const char * paramName, 
							int32 parami32ColorToChange,
							const char * paramLabel,
							BLooper * paramMessageTarget,
							LayoutMatrix * paramLayoutMatrix) 
				: 
				BView(	BRect(0, 0, myPrefs->GetPreferredColorWellWidth(), myPrefs->GetPreferredColorWellHeight()), 
						paramName, 
						B_FOLLOW_NONE, 
						B_WILL_DRAW),
				mfTop(0),
				mi32ColorToChange(parami32ColorToChange),
				mpMessageTarget(paramMessageTarget),
				mpLabel(NULL),
				mpLabelView(NULL)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_COLORWELL);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
		if (paramLabel)
		{
			rgb_color * rgbV = new rgb_color;
			myPrefs->GetPreferredStringGadgetViewColor(rgbV);
			rgb_color * rgbH = new rgb_color;
			myPrefs->GetPreferredStringGadgetHighColor(rgbH);
			rgb_color * rgbL = new rgb_color;
			myPrefs->GetPreferredStringGadgetLowColor(rgbL);
			mpLabelView = new MyStringView(	"ColorWellView", 
											paramLabel,
											NULL,
											rgbV,
											rgbH,
											rgbL);
			mpLabel = new BString(paramLabel);
		}
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	mui8Width = myPrefs->GetPreferredColorWellWidth();
	mui8Height = myPrefs->GetPreferredColorWellHeight();
}//end


void 
ColorWell	::	AttachedToWindow(	void)
{
	BView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredColorWellHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredColorWellLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredColorWellViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end


void 
ColorWell	::	Draw(	BRect rect) 
{
	BView::Draw(rect);
	SetPenSize(1);
	rgb_color originalColor(HighColor());
	rgb_color newColor(originalColor);
	bool redUp = false;
	bool greenUp = false;
	bool blueUp = false;
	BRect frame(0, 0, mui8Width, mui8Height);
	uint8 leastDiminsion = mui8Width;
	if (leastDiminsion > mui8Height)
	{
		leastDiminsion = mui8Height;
	}
	int colorRange;
	if (originalColor.red < originalColor.green ) 
	{
		if (originalColor.red < originalColor.blue ) 
		{
			redUp = true;
			colorRange = 255 - originalColor.red;
		}
		else
		{
			blueUp = true;
			colorRange = 255 - originalColor.blue;
		}
	}
	else
	{
		if (originalColor.green < originalColor.blue ) 
		{
			greenUp = true;
			colorRange = 255 - originalColor.green;
		}
		else
		{
			blueUp = true;
			colorRange = 255 - originalColor.blue;
		}
	}
	colorRange /= leastDiminsion;
	for (	uint8 i = leastDiminsion;
			i > 0;
			i--)
	{
		if (redUp)
		{
			newColor.red += colorRange;
		}
		else 
		{
			if (greenUp)
			{
				newColor.green += colorRange;
			}
			else
			{
				newColor.blue += colorRange;
			}
		}
		SetHighColor(newColor);
		frame.InsetBy(1, 1);
		StrokeRect(frame);
	}
	SetHighColor(originalColor);
}//end


void 
ColorWell	::	MessageReceived(	BMessage * paramMessage) 
{
	beep();//just so feedback occures
	paramMessage->AddInt32("ColorToChange", mi32ColorToChange);
	BView::MessageReceived(paramMessage);
}//end


void
ColorWell	::	SetTop(	const float paramTop)
{
	mfTop = paramTop;
}//end


float
ColorWell	::	GetTop(	void) const
{
	return mfTop;
}//end


void
ColorWell	::	SetLeft(	const float paramLeft)
{
	mfLeft = paramLeft;
}//end


float
ColorWell	::	GetLeft(	void) const
{
	return mfLeft;
}//end