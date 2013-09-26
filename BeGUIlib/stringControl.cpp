//stringControl.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "DControl.h"
#include "stringControl.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "warning.h"
#include "stringBoundsBox.h"

StringControl	::	~StringControl() 
{
	//leaving blank
};//end


//ctor
StringControl	::	StringControl(	const char * paramName, 
									const char * paramLabel, 
									const char * paramText, 
									uint32 paramMsg, 
									float paramTextViewWidth,
									LayoutMatrix * paramLayoutMatrix,
									bool paramMakeFocus) 
		: 
			BTextControl(	BRect(0, 0, 32, 32), 
							paramName, 
							paramLabel, 
							paramText, 
							new BMessage(paramMsg), 
							B_FOLLOW_NONE, 
							B_WILL_DRAW | B_NAVIGABLE),
			 mbMakeFocus(	paramMakeFocus)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_STRINGCONTROL);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	SetFont(myPrefs->GetPreferredFont());
	if (paramTextViewWidth > 0)
	{
		mfTextViewWidth = paramTextViewWidth;
	}
	else
	{
		if (paramText)
		{
			float leftOffset;
			float baseline;
			float height;
			if (!StringBoundsBox(	paramText,
									&mfTextViewWidth,
									&height,
									&leftOffset,
									&baseline))
			{
				throw;
			}
		}
		else
		{
			mfTextViewWidth = DEFAULT_ENTRY_WIDTH;
		}
	}
}//end


void 
StringControl	::	AttachedToWindow(	void)
{
	SetDrawingMode(B_OP_OVER);
	BTextControl::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredStringControlHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredStringControlLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredStringControlViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	if (mbMakeFocus) 
	{
		MakeFocus();
	}
}//end