//myButton.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myButton.h"
#include "layoutMatrix.h"
#include "myPreferences.h"
#include "warning.h"
#include "stringBoundsBox.h"

MyButton	::	~MyButton() 
{
	//leaving blank
};//end


//ctor
MyButton	::	MyButton(	const char * paramName, 
							const char * paramLabel,
							uint32 paramMsg,
							LayoutMatrix * paramLayoutMatrix,
							bool paramSetEnabled,
							int paramOnOff) 
				: 
					BButton(	BRect(0, 0, 32, 32), 
								paramName, 
								paramLabel,
								new BMessage(paramMsg),
								B_FOLLOW_NONE, 
								B_WILL_DRAW),
					mbsLabel(paramLabel)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYBUTTON);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	SetFont(myPrefs->GetPreferredFont());
	SetEnabled(paramSetEnabled);
	SetValue(paramOnOff);
}//end


void 
MyButton	::	AttachedToWindow(	void)
{
	BButton::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyButtonHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyButtonLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredMyButtonViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end


void
MyButton	::	MyGetPreferredSize(	float * paramWidth,
									float * paramHeight)
{
	float leftOffset;
	float baseline;
	float width;
	float height;
	if (!StringBoundsBox(	mbsLabel.String(),
							&width,
							&height,
							&leftOffset,
							&baseline))
	{
		throw;
	}
	*paramWidth = width + 11;
	*paramHeight = height + 11;
}//end