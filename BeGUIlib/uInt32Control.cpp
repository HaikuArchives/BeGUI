//uInt32Control.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "DControl.h"
#include "uInt32Control.h"
#include "gadgetBase.h"
#include "uInt32Gadget.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "warning.h"
#include "stringBoundsBox.h"

UInt32Control	::	~UInt32Control() 
{
	//leaving blank
};//end


//ctor
UInt32Control	::	UInt32Control(	uint32 paramInitValue,
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
														KIND_UINT32CONTROL);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren(this);
	SetFont(myPrefs->GetPreferredFont());
	char buf[DIGITSnUI32];
	sprintf(buf, "%lu", paramInitValue);
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
UInt32Control	::	AttachedToWindow(	void)
{
	SetDrawingMode(B_OP_OVER);
	BTextControl::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredUInt32ControlHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredUInt32ControlLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredUInt32ControlViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	if (mbMakeFocus) 
	{
		MakeFocus();
	}
}//end
