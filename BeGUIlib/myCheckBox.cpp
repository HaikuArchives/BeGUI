//myCheckBox.h

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myCheckBox.h"
#include "layoutMatrix.h"
#include "myPreferences.h"
#include "warning.h"

MyCheckBox	::	~MyCheckBox() 
{
	//leaving blank
};//end


//ctor
MyCheckBox	::	MyCheckBox(	const char * paramName, 
							const char * paramLabel,
							int32 paramValue,
							uint32 paramMsg,
							LayoutMatrix * paramLayoutMatrix) 
				: 
					BCheckBox(	BRect(0, 0, 32, 32),
								paramName, 
								paramLabel,
								new BMessage(paramMsg),
								B_FOLLOW_NONE, 
								B_WILL_DRAW)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYCHECKBOX);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	SetFont(myPrefs->GetPreferredFont());
	SetValue(paramValue);
}//end


void 
MyCheckBox	::	AttachedToWindow(	void)
{
	BCheckBox::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyCheckBoxHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyCheckBoxLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredMyCheckBoxViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end