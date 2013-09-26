//myPictureButton

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPictureButton.h"
#include "layoutMatrix.h"
#include "myPreferences.h"
#include "warning.h"

MyPictureButton	::	~MyPictureButton() 
{
	//leaving blank
};//end


//ctor
MyPictureButton	::	MyPictureButton(	BRect paramRect, 
										const char * paramName, 
										BPicture * paramOffPicture,
										BPicture * paramOnPicture,
										BPicture * paramOffDisabledPicture,
										BPicture * paramOnDisabledPicture,
										uint32 paramMsg,
										uint32 paramBehavior,
										LayoutMatrix * paramLayoutMatrix,
										bool paramSetEnabled,
										int paramOnOff) 
				: 
					BPictureButton(	paramRect, 
									paramName, 
									paramOffPicture,
									paramOnPicture,
									new BMessage(paramMsg),
									paramBehavior,
									B_FOLLOW_NONE, 
									B_WILL_DRAW)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYPICTUREBUTTON);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	SetDisabledOff(paramOffDisabledPicture);
	SetDisabledOn(paramOnDisabledPicture);
	SetEnabled(paramSetEnabled);
	SetValue(paramOnOff);
}//end


void 
MyPictureButton	::	AttachedToWindow(	void)
{
	BPictureButton::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyPictureButtonHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyPictureButtonLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredMyPictureButtonViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
}//end