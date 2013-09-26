//myColorControl

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DcolorControlMessages.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myColorControl.h"
#include "myPreferences.h"
#include "warning.h"

MyColorControl	::	~MyColorControl() 
{
	//leaving blank
};//end


//ctor
MyColorControl	::	MyColorControl(	color_control_layout paramColorControlLayout,
									const char * paramName,
									uint32 paramMsg,
									LayoutMatrix * paramLayoutMatrix, 
									float paramCellSize,
									bool paramUseOffscreen) 
				: 
					BColorControl(	BPoint(0, 0),
									paramColorControlLayout, 
									paramCellSize,
									paramName,
									new BMessage(paramMsg),
									paramUseOffscreen)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYCOLORCONTROL);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
}//end


void 
MyColorControl	::	AttachedToWindow(	void)
{
	BColorControl::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyColorControlHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyColorControlLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredMyColorControlViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end