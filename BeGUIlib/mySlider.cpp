//mySlider.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "mySlider.h"
#include "layoutMatrix.h"
#include "warning.h"

MySlider	::	~MySlider() 
{
	//leaving blank
};//end


//ctor
MySlider	::	MySlider(	BRect paramFrame,
							const char * paramName,
							const char * paramLabel,
							uint32 paramMessageValue,
							int32 paramMinValue,
							int32 paramMaxValue,
							float paramPosition,
							LayoutMatrix * paramLayoutMatrix) 
				: 
					BSlider(	paramFrame,
								paramName,
								paramLabel,
								new BMessage(paramMessageValue),
								paramMinValue,
								paramMaxValue)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYSLIDER);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	SetPosition(paramPosition);
	paramLayoutMatrix->AddToChildren((void *)this);
}//end


void 
MySlider	::	AttachedToWindow(	void) 
{
	BSlider::AttachedToWindow();
	if (B_BLOCK_THUMB == myPrefs->GetPreferredThumbStyle())
	{
		BSlider::SetStyle(B_BLOCK_THUMB);
	}
	else
	{
		BSlider::SetStyle(B_TRIANGLE_THUMB);
	}
	BView * osv = OffscreenView();
	if (osv->LockLooper())
	{
		rgb_color tempRgbColor;
		myPrefs->GetPreferredMySliderHighColor(&tempRgbColor);
		osv->SetHighColor(tempRgbColor);
		myPrefs->GetPreferredMySliderLowColor(&tempRgbColor);
		osv->SetLowColor(tempRgbColor);
		if (myPrefs->mui32FillSliderBar)
		{
			myPrefs->GetPreferredMyBarFillSliderColor(&tempRgbColor);
			UseFillColor(true, &tempRgbColor);
		}
		if (myPrefs->mui32ColorSliderBar)
		{
			myPrefs->GetPreferredMyBarSliderColor(&tempRgbColor);
			SetBarColor(tempRgbColor);
		}
		myPrefs->GetPreferredMySliderViewColor(&tempRgbColor);
		osv->SetViewColor(tempRgbColor);
		osv->SetFont(myPrefs->GetPreferredFont());
		osv->UnlockLooper();
	}
	else
	{
		warning(myPrefs->FailLockLooper);
	}
}//end