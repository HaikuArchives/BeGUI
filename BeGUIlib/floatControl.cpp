//floatControl.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "DControl.h"
#include "floatControl.h"
#include "gadgetBase.h"
#include "floatGadget.h"
#include "Preferences.h"
#include "myroColour.h"
#include "layoutMatrix.h"
#include "myPreferences.h"
#include "warning.h"
#include "stringBoundsBox.h"

FloatControl	::	~FloatControl() 
{
	//leaving blank
};//end


//ctor
FloatControl	::	FloatControl(	float paramInitValue,
						const char * paramName, 
						const char * paramLabel, 
						uint32 paramMsg, 
						float paramTextViewWidth,
						LayoutMatrix * paramLayoutMatrix,
						bool paramMakeFocus) 
		: 	BTextControl(	BRect(0, 0, 32, 32), 
							paramName, 
							paramLabel, 
							NULL, 
							new BMessage(paramMsg), 
							B_FOLLOW_NONE, 
							B_WILL_DRAW | B_NAVIGABLE),
			 mbMakeFocus(	paramMakeFocus)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_FLOATCONTROL);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren(this);
	SetFont(myPrefs->GetPreferredFont());
	char buf[DIGITSnFLOAT];
	sprintf(buf, "%f", paramInitValue);
	SetText(buf);
	if (paramTextViewWidth > 0)
	{
		mfTextViewWidth = paramTextViewWidth;
	}
	else
	{
		mfTextViewWidth = DEFAULT_ENTRY_WIDTH;
	}
}//end


void 
FloatControl	::	AttachedToWindow(	void)
{
	SetDrawingMode(B_OP_OVER);
	BTextControl::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredFloatControlHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredFloatControlLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredFloatControlViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	if (mbMakeFocus) 
	{
		MakeFocus();
	}
}//end
