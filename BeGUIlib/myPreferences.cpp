//myPreferences.cpp

#define BUILDING_LIB 1
//#define NOTX_MYPREF 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "DmenuMsg.h"
#include "DtinySnooze.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "myButton.h"
#include "stringControl.h"
#include "uInt32Control.h"
#include "warning.h"
#include "fontData.h"
#include "layoutMatrix.h"
#include "colorWell.h"
#include "myColorControl.h"
#include "myTextView.h"
#include "myListView.h"
#include "scrollingWindow.h"
#include "myCheckBox.h"
#include "gadgetBase.h"
#include "floatGadget.h"
#include "specificColorWindow.h"
#include "scrollingWindow.h"
#include "prefPanelWindow.h"
#include "smallerRect.h"


MyPreferences	::	~MyPreferences() 
{
	bool allSetsOK = true;
	rgb_color tempRgbColor;
	GetPreferredColorWellHighColor(&tempRgbColor);
	if (mpPreferenceSet->SetData(	"PreferredColorWellHighColor", 
									&tempRgbColor, 
									sizeof(tempRgbColor), 
									B_RGB_COLOR_TYPE))
	{
		warning(PrefsNoSetColorWellHighColor);
		allSetsOK = false;
	}
	if (allSetsOK) 
	{
		GetPreferredColorWellLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredColorWellLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetolorWellLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredColorWellViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredColorWellViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetColorWellViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt32ControlHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt32ControlHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt32ControlHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt8GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt8GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt8GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt8GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt8GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt8GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt16GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt16GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt16GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt16GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt16GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt16GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt32GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt32GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt32GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt32GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt32GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt32GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt64GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt64GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt64GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt64GadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt64GadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt64GadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredFloatGadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredFloatGadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetFloatGadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredHexGadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredHexGadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetHexGadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredStringGadgetHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredStringGadgetHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetStringGadgetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredFloatControlHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredFloatControlHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetFloatControlHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyButtonHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyButtonHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyButtonHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyButtonLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyButtonLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyButtonLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyButtonViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyButtonViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyButtonViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyPictureButtonHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyPictureButtonHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyPictureButtonHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyPictureButtonLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyPictureButtonLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyPictureButtonLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyPictureButtonViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyPictureButtonViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyPictureButtonViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyCheckBoxHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyCheckBoxHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyCheckBoxHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyCheckBoxLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyCheckBoxLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyCheckBoxLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyCheckBoxViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyCheckBoxViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyCheckBoxViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyBarStatusColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyBarStatusColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyBarStatusColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyStatusBarHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyStatusBarHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyStatusBarHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyStatusBarLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyStatusBarLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyStatusBarLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyStatusBarViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyStatusBarViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyStatusBarViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyColorControlHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyColorControlHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyColorControlHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyBarSliderColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyBarSliderColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyBarSliderColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyBarFillSliderColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyBarFillSliderColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyBarFillSliderColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"MYSLIDERBARCOLOR", 
										&mui32ColorSliderBar, 
										sizeof(mui32ColorSliderBar), 
										B_INT32_TYPE))
		{
			warning(PrefsNoSetMyBarColorSlider);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"MYSLIDERBARFILL", 
										&mui32FillSliderBar, 
										sizeof(mui32FillSliderBar), 
										B_INT32_TYPE))
		{
			warning(PrefsNoSetMyBarFillSlider);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMySliderHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMySliderHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMySliderHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMySliderLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMySliderLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMySliderLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMySliderViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMySliderViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMySliderViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyColorControlHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyColorControlHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyColorControlHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyColorControlLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyColorControlLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyColorControlLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyColorControlViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyColorControlViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyColorControlViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyStringDrawerHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyStringDrawerHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyStringDrawerHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyStringDrawerLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyStringDrawerLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyStringDrawerLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyStringDrawerViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyStringDrawerViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyStringDrawerViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyRadioViewHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyRadioViewHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyRadioViewHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyRadioViewLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyRadioViewLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyRadioViewLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyRadioViewViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyRadioViewViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyRadioViewViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyTextViewHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyTextViewHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyTextViewHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyTextViewLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyTextViewLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyTextViewLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyTextViewViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyTextViewViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyTextViewViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyListViewHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyListViewHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyListViewHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyListViewLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyListViewLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyListViewLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredMyListViewViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredMyListViewViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetMyListViewViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt32ControlLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt32ControlLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt32ControlLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt8GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt8GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt8GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt8GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt8GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt8GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt16GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt16GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt16GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt16GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt16GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt16GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt32GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt32GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt32GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt32GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt32GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt32GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt64GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt64GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt64GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt64GadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt64GadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt64GadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredFloatGadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredFloatGadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetFloatGadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredHexGadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredHexGadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetHexGadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredStringGadgetLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredStringGadgetLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetStringGadgetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt32ControlViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt32ControlViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt32ControlViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt8GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt8GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt8GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt8GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt8GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt8GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt16GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt16GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt16GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt16GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt16GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt16GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt32GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt32GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt32GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt32GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt32GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt32GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredInt64GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredInt64GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetInt64GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredUInt64GadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredUInt64GadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetUInt64GadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredFloatGadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredFloatGadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetFloatGadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredHexGadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredHexGadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetHexGadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredStringGadgetViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredStringGadgetViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetStringGadgetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredFloatControlLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredFloatControlLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetFloatControlLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredFloatControlViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredFloatControlViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetFloatControlViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredHighColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredHighColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetHighColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredLowColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredLowColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetLowColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		GetPreferredViewColor(&tempRgbColor);
		if (mpPreferenceSet->SetData(	"PreferredViewColor", 
										&tempRgbColor, 
										sizeof(tempRgbColor), 
										B_RGB_COLOR_TYPE))
		{
			warning(PrefsNoSetViewColor);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		FontData windowFontData(GetPreferredFont());
		if (mpPreferenceSet->SetData(	"FONTDATA_SIZE_TYPE", 
										&windowFontData.mfSize, 
										sizeof(windowFontData.mfSize), 
										FONTDATA_SIZE_TYPE))
		{
			warning(PrefsNoSetFont);
			allSetsOK = false;
		}
		if (allSetsOK) 
		{
			if (mpPreferenceSet->SetData(	"FONTDATA_SHEAR_TYPE", 
											&windowFontData.mfShear, 
											sizeof(windowFontData.mfShear), 
											FONTDATA_SHEAR_TYPE))
			{
				warning(PrefsNoSetFont);
				allSetsOK = false;
			}
		}
		if (allSetsOK) 
		{
			if (mpPreferenceSet->SetData(	"FONTDATA_ROTATION_TYPE", 
											&windowFontData.mfRotation, 
											sizeof(windowFontData.mfRotation), 
											FONTDATA_ROTATION_TYPE))
			{
				warning(PrefsNoSetFont);
				allSetsOK = false;
			}
		}
		if (allSetsOK) 
		{
			if (mpPreferenceSet->SetData(	"FONTDATA_FLAGS_TYPE", 
											&windowFontData.mui32Flags, 
											sizeof(windowFontData.mui32Flags), 
											FONTDATA_FLAGS_TYPE))
			{
				warning(PrefsNoSetFont);
				allSetsOK = false;
			}
		}
		if (allSetsOK) 
		{
			if (mpPreferenceSet->SetData(	"FONTDATA_FACE_TYPE", 
											&windowFontData.mui16Face, 
											sizeof(windowFontData.mui16Face), 
											FONTDATA_FACE_TYPE))
			{
				warning(PrefsNoSetFont);
				allSetsOK = false;
			}
		}
		if (allSetsOK) 
		{
			if (mpPreferenceSet->SetData(	"FONTDATA_SPACING_TYPE", 
											&windowFontData.mui8Spacing, 
											sizeof(windowFontData.mui8Spacing), 
											FONTDATA_SPACING_TYPE))
			{
				warning(PrefsNoSetFont);
				allSetsOK = false;
			}
		}
		if (allSetsOK) 
		{
			if (mpPreferenceSet->SetData(	"FONTDATA_ENOCDING_TYPE", 
											&windowFontData.mui8Encoding, 
											sizeof(windowFontData.mui8Encoding), 
											FONTDATA_ENOCDING_TYPE))
			{
				warning(PrefsNoSetFont);
				allSetsOK = false;
			}
		}
		if (allSetsOK) 
		{
			if (mpPreferenceSet->SetData(	"FONTDATA_FANDS_TYPE", 
											&windowFontData.mui32FamilyAndStyle, 
											sizeof(windowFontData.mui32FamilyAndStyle), 
											FONTDATA_FANDS_TYPE))
			{
				warning(PrefsNoSetFont);
				allSetsOK = false;
			}
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"OPENFONTDISPLAY_TYPE", 
										&mbOpenFontDisplay, 
										sizeof(mbOpenFontDisplay), 
										OPENFONTDISPLAY_TYPE))
		{
			warning(PrefsNoSetOpenFontDisplay);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"ANTIALIASFONT_TYPE", 
										&mbAntiAliasFont, 
										sizeof(mbAntiAliasFont), 
										ANTIALIASFONT_TYPE))
		{
			warning(PrefsNoSetAntiAliasFont);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		float barHeight = GetPreferredBarHeight();
		if (mpPreferenceSet->SetData(	"BARHEIGHT", 
										&barHeight, 
										sizeof(barHeight), 
										BARHEIGHT))
		{
			warning(PrefsNoSetBarHeight);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		uint8 colorWellWidth = GetPreferredColorWellWidth();
		if (mpPreferenceSet->SetData(	"COLORWELLWIDTH", 
										&colorWellWidth, 
										sizeof(colorWellWidth), 
										COLORWELLWIDTH))
		{
			warning(PrefsNoSetColorWellWidth);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		uint8 colorWellHeight = GetPreferredColorWellHeight();
		if (mpPreferenceSet->SetData(	"COLORWELLHEIGHT", 
										&colorWellHeight, 
										sizeof(colorWellHeight), 
										COLORWELLHEIGHT))
		{
			warning(PrefsNoSetColorWellHeight);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"USECOLORWELL", 
										&mbUseColorWell, 
										sizeof(mbUseColorWell), 
										USECOLORWELL))
		{
			warning(PrefsNoSetUseColorWell);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"USECOLORCONTROL", 
										&mbUseColorControl, 
										sizeof(mbUseColorControl), 
										USECOLORCONTROL))
		{
			warning(PrefsNoSetUseColorControl);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"THUMBSTYLE", 
										&mtsThumbStyle, 
										sizeof(mtsThumbStyle), 
										THUMBSTYLE))
		{
			warning(PrefsNoSetThumbStyle);
			allSetsOK = false;
		}
	}
	if (allSetsOK) 
	{
		if (mpPreferenceSet->SetData(	"CCLAYOUT", 
										&mCCL, 
										sizeof(mCCL), 
										CCLAYOUT))
		{
			warning(PrefsNoSetCCLayout);
			allSetsOK = false;
		}
	}
	if (allSetsOK)
	{
		if (mpPreferenceSet->Save())
		{
			warning(PrefsNoSaveSet);
		}
	}
	delete preferredFont;
	if (pPrefPanelWindow)
	{
		pPrefPanelWindow->PostMessage(B_QUIT_REQUESTED);
		while (pPrefPanelWindow)
		{
			snooze(TINYSNOOZE);
		}
	}
	free ((char *)VerifyCancel);
	free ((char *)AntiAliasFont);
	free ((char *)NoAdditem);
	free ((char *)failMenu);
	free ((char *)PrefsNoSetAntiAliasFont);
	free ((char *)EnterBarHeightLabel);
	free ((char *)EnterColorWellWidthLabel);
	free ((char *)EnterColorWellHeightLabel);
	free ((char *)PrefsNoSetBarHeight);
	free ((char *)PrefsNoSetColorWellWidth);
	free ((char *)PrefsNoSetColorWellHeight);
	free ((char *)BMsgAddXFailPUMInit);
	free ((char *)VerifyDoNot);
	free ((char *)PrefSignature);
	free ((char *)VerifyDo);
	free ((char *)AboutMenuLabel);
	free ((char *)FontFamilyPUMLabel);
	free ((char *)FontStylePUMLabel);
	free ((char *)AboutPrefPanelWindow);
	free ((char *)AboutFontPrefWindowMsg1);
	free ((char *)AboutFontPrefWindowMsg2);
	free ((char *)AboutFontPrefWindowMsg3);
	free ((char *)AboutFontPrefWindowMsg4);
	free ((char *)AboutFontPrefWindowMsg5);
	free ((char *)AboutFontPrefWindowMsg6);
	free ((char *)AboutGutMsg);
	free ((char *)AboutBasicColorWindowMsg1);
	free ((char *)AboutBasicColorWindowMsg2);
	free ((char *)AboutSpecColorWindow);
	free ((char *)AboutFontDisplayWindow);
	free ((char *)FailLockLooper);
	free ((char *)ReallyQuitApp);
	free ((char *)CaughtFontPrefWindowCTOR);
	free ((char *)CaughtPrefPanelWindowCTOR);
	free ((char *)NoPrefPanelWindow);
	free ((char *)CaughtBasicColorWindowCTOR);
	free ((char *)CaughtSpecificColorWindowCTOR);
	free ((char *)BadSpecColorKindView);
	free ((char *)BadSpecColorKindHigh);
	free ((char *)BadSpecColorKindLow);
	free ((char *)WarningOKLabel);
	free ((char *)FailMemory);
	free ((char *)FailScrollView);
	free ((char *)PreferenceMenuLabel);
	free ((char *)PrefFailInit);
	free ((char *)PrefFailGetSettings);
	free ((char *)PrefFailSetSettings);
	free ((char *)PreferencePanelWindowTitle);
	free ((char *)PrefsNoSetColorWellHighColor);
	free ((char *)PrefsNoSetolorWellLowColor);
	free ((char *)PrefsNoSetColorWellViewColor);
	free ((char *)PrefsNoSetMyButtonHighColor);
	free ((char *)PrefsNoSetMyButtonLowColor);
	free ((char *)PrefsNoSetMyButtonViewColor);
	free ((char *)PrefsNoSetMyPictureButtonHighColor);
	free ((char *)PrefsNoSetMyPictureButtonLowColor);
	free ((char *)PrefsNoSetMyPictureButtonViewColor);
	free ((char *)PrefsNoSetMyCheckBoxHighColor);
	free ((char *)PrefsNoSetMyCheckBoxLowColor);
	free ((char *)PrefsNoSetMyCheckBoxViewColor);
	free ((char *)PrefsNoSetMyStatusBarHighColor);
	free ((char *)PrefsNoSetMyStatusBarLowColor);
	free ((char *)PrefsNoSetMyStatusBarViewColor);
	free ((char *)PrefsNoSetMyBarStatusColor);
	free ((char *)PrefsNoSetMySliderHighColor);
	free ((char *)PrefsNoSetMySliderLowColor);
	free ((char *)PrefsNoSetMySliderViewColor);
	free ((char *)PrefsNoSetMyBarSliderColor);
	free ((char *)PrefsNoSetMyColorControlHighColor);
	free ((char *)PrefsNoSetMyColorControlLowColor);
	free ((char *)PrefsNoSetMyColorControlViewColor);
	free ((char *)PrefsNoSetMyStringDrawerHighColor);
	free ((char *)PrefsNoSetMyStringDrawerLowColor);
	free ((char *)PrefsNoSetMyStringDrawerViewColor);
	free ((char *)PrefsNoSetMyRadioViewHighColor);
	free ((char *)PrefsNoSetMyRadioViewLowColor);
	free ((char *)PrefsNoSetMyRadioViewViewColor);
	free ((char *)PrefsNoSetMyTextViewHighColor);
	free ((char *)PrefsNoSetMyTextViewLowColor);
	free ((char *)PrefsNoSetMyTextViewViewColor);
	free ((char *)PrefsNoSetUInt32ControlHighColor);
	free ((char *)PrefsNoSetUInt32ControlLowColor);
	free ((char *)PrefsNoSetUInt32ControlViewColor);
	free ((char *)PrefsNoSetInt8GadgetHighColor);
	free ((char *)PrefsNoSetInt8GadgetLowColor);
	free ((char *)PrefsNoSetInt8GadgetViewColor);
	free ((char *)PrefsNoSetUInt8GadgetHighColor);
	free ((char *)PrefsNoSetUInt8GadgetLowColor);
	free ((char *)PrefsNoSetUInt8GadgetViewColor);
	free ((char *)PrefsNoSetInt16GadgetHighColor);
	free ((char *)PrefsNoSetInt16GadgetLowColor);
	free ((char *)PrefsNoSetInt16GadgetViewColor);
	free ((char *)PrefsNoSetUInt16GadgetHighColor);
	free ((char *)PrefsNoSetUInt16GadgetLowColor);
	free ((char *)PrefsNoSetUInt16GadgetViewColor);
	free ((char *)PrefsNoSetInt32GadgetHighColor);
	free ((char *)PrefsNoSetInt32GadgetLowColor);
	free ((char *)PrefsNoSetInt32GadgetViewColor);
	free ((char *)PrefsNoSetUInt32GadgetHighColor);
	free ((char *)PrefsNoSetUInt32GadgetLowColor);
	free ((char *)PrefsNoSetUInt32GadgetViewColor);
	free ((char *)PrefsNoSetInt64GadgetHighColor);
	free ((char *)PrefsNoSetInt64GadgetLowColor);
	free ((char *)PrefsNoSetInt64GadgetViewColor);
	free ((char *)PrefsNoSetUInt64GadgetHighColor);
	free ((char *)PrefsNoSetUInt64GadgetLowColor);
	free ((char *)PrefsNoSetUInt64GadgetViewColor);
	free ((char *)PrefsNoSetFloatGadgetHighColor);
	free ((char *)PrefsNoSetFloatGadgetLowColor);
	free ((char *)PrefsNoSetFloatGadgetViewColor);
	free ((char *)PrefsNoSetHexGadgetHighColor);
	free ((char *)PrefsNoSetHexGadgetLowColor);
	free ((char *)PrefsNoSetHexGadgetViewColor);
	free ((char *)PrefsNoSetStringGadgetHighColor);
	free ((char *)PrefsNoSetStringGadgetLowColor);
	free ((char *)PrefsNoSetStringGadgetViewColor);
	free ((char *)PrefsNoSetFloatControlHighColor);
	free ((char *)PrefsNoSetFloatControlLowColor);
	free ((char *)PrefsNoSetFloatControlViewColor);
	free ((char *)PrefsNoSetHighColor);
	free ((char *)PrefsNoSetLowColor);
	free ((char *)PrefsNoSetViewColor);
	free ((char *)FontPrefWindowTitle);
	free ((char *)FontPrefWindowHeading1);
	free ((char *)BiggerFontButtonLabel);
	free ((char *)SmallerFontButtonLabel);
	free ((char *)EnterFontSizeLabel);
	free ((char *)DisplayFontCheckBoxLabel);
	free ((char *)FontDisplayNotNull);
	free ((char *)FontDisplayWindowTitle);
	free ((char *)FailFontDisplayWindow);
	free ((char *)FailMinFontSize);
	free ((char *)FailMaxFontSize);
	free ((char *)PrefsNoSetFont);
	free ((char *)PrefsNoSetOpenFontDisplay);
	free ((char *)PrefsNoSetUseColorWell);
	free ((char *)PrefsNoSetUseColorControl);
	free ((char *)PrefsNoSaveSet);
	free ((char *)PrefPanelWindowHeading1);
	free ((char *)PrefPanelFontButtonLabel);
	free ((char *)PrefPanelWindowHeading2);
	free ((char *)BarCWLabel);
	free ((char *)BarCCLabel);
	free ((char *)PrefsNoSetMyListViewHighColor);
	free ((char *)PrefsNoSetMyListViewLowColor);
	free ((char *)PrefsNoSetMyListViewViewColor);
	free ((char *)FailCreateSemaphore);
	free ((char *)FailAqSem);
	free ((char *)AppMenuLabel);
	free ((char *)QuitMenuLabel);
	free ((char *)CloseWindow);
	free ((char *)ScreenNotValid);
	free ((char *)NotFoundScrollView);
	free ((char *)PrefNoSetGutFrame);
	free ((char *)S2UI32Neg);
	free ((char *)S2UI32OutOfRange);
	free ((char *)S2UI32Invalid);
	free ((char *)BasicColorWindowHeading1);
	free ((char *)ColorWindowHeading2);
	free ((char *)ColorWindowHeading3);
	free ((char *)ColorWindowHeading4);
	free ((char *)ColorWindowHeading5);
	free ((char *)ColorWindowHeading6);
	free ((char *)ColorWindowHeading7);
	free ((char *)DemoRoNo);
	free ((char *)RoBadMsg);
	free ((char *)BarColorTitle);
	free ((char *)DemoButtonLabel);
	free ((char *)DemoRadio1Label);
	free ((char *)DemoRadio2Label);
	free ((char *)DemoRadio3Label);
	free ((char *)RadioViewFailInit);
	free ((char *)DemoCheckBoxLabel);
	free ((char *)DemoStatusBarLeadLabel);
	free ((char *)DemoStatusBarTrailLabel);
	free ((char *)StringControlLabel);
	free ((char *)TextGadgetLabel);
	free ((char *)ListViewSample1);
	free ((char *)ListViewSample2);
	free ((char *)ListViewSample3);
	free ((char *)SelectFromList);
	free ((char *)InvokeFromList);
	free ((char *)UInt32ControlLabel);
	free ((char *)FloatControlLabel);
	free ((char *)DemoRoLabel);
	free ((char *)DemoTextItemText);
	free ((char *)BadSpecItemKind);
	free ((char *)BadSpecKindQR);
	free ((char *)BadSpecKindColorSetView);
	free ((char *)BadSpecKindColorSetHigh);
	free ((char *)BadSpecKindColorSetLow);
	free ((char *)DisplayBColorControls);
	free ((char *)DisplayroColourWells);
	free ((char *)BasicColorWindowTitle);
	free ((char *)NoBasicColorWindow);
	free ((char *)NoSpecColorWindow);
	free ((char *)FailPUMInitFontWindow);
	free ((char *)FailPUMInit);
	free ((char *)FailRadioInit);
	free ((char *)truncShort);
	free ((char *)noCCenabled);
	free ((char *)MessageFindBytes);
	free ((char *)NumStrTooLong);
	free ((char *)NumTooBig);
	free ((char *)NumTooSmall);
	free ((char *)S2I32OutOfRange);
	free ((char *)S2I32Invalid);
	free ((char *)S2I64OutOfRange);
	free ((char *)S2I64Invalid);
	free ((char *)S2UI64OutOfRange);
	free ((char *)S2I64Invalid);
	free ((char *)WrongKindLMI);
	free ((char *)AboutSimpleWindowMsg);
	free ((char *)GetInt8GadgetLabel);
	free ((char *)GetUInt8GadgetLabel);
	free ((char *)GetInt16GadgetLabel);
	free ((char *)GetUInt16GadgetLabel);
	free ((char *)GetInt32GadgetLabel);
	free ((char *)GetUInt32GadgetLabel);
	free ((char *)GetInt64GadgetLabel);
	free ((char *)GetUInt64GadgetLabel);
	free ((char *)GetFloatGadgetLabel);
	free ((char *)GetHexGadgetLabel);
	free ((char *)GetDoubleGadgetLabel);
	free ((char *)GetLongDoubleGadgetLabel);
	free ((char *)GetStringGadgetLabel);
	free ((char *)PrefNoSetBaseFrame);
	free ((char *)AboutBaseMsg);
	free ((char *)DemoRadioLabelThumbRect);
	free ((char *)DemoRadioLabelThumbTri);
	free ((char *)PrefsNoSetThumbStyle);
	free ((char *)IllegalThumb);
	free ((char *)ColorSliderBarCBLabel);
	free ((char *)FillSliderBarCBLabel);
	free ((char *)SliderBarFillColorLabel);
	free ((char *)PrefsNoSetMyBarFillSliderColor);
	free ((char *)PrefsNoSetMyBarColorSlider);
	free ((char *)PrefsNoSetMyBarFillSlider);
	free ((char *)FillCWLabel);
	free ((char *)FillCCLabel);
	free ((char *)ColorControlKind);
	free ((char *)CC_4x64_Cell);
	free ((char *)CC_8x32_Cell);
	free ((char *)CC_16x16_Cell);
	free ((char *)CC_32x8_Cell);
	free ((char *)CC_64x4_Cell);
	free ((char *)PrefsNoSetCCLayout);
	free ((char *)FailReopen);
	free ((char *)StringTooLongToMeasure);
	free ((char *)AlphaNumeric);
	for (	uint32 i = 0;
			i < NUMPREFPANELS;
			i++)
	{	
		free ((char *)buttonLabels[i]);
	}
	for (	uint32 i = 0;
			i < (NUMPREFPANELS - 1);
			i++)
	{	
		free ((char *)lvwTitleStr[i]);
	}
	delete mpPreferenceSet;
	delete mpPreferences;
}//end


BFont *	
MyPreferences	::	GetPreferredFont(		void) const
{
	return preferredFont;
}//end


void
MyPreferences	::	SetPreferredFont(		const BFont * paramFont)
{
	*preferredFont = *paramFont;
}//end


void
MyPreferences	::	SetToPreferredFont(		BFont * paramFont)
{
	paramFont->SetFamilyAndStyle(	preferredFont->FamilyAndStyle());
	paramFont->SetSize(	preferredFont->Size());
	paramFont->SetShear(	preferredFont->Shear());
	paramFont->SetRotation(	preferredFont->Rotation());
	paramFont->SetSpacing(	preferredFont->Spacing());
	paramFont->SetEncoding(	preferredFont->Encoding());
	paramFont->SetFace(	preferredFont->Face());
	paramFont->SetFlags(	preferredFont->Flags());
	//?? paramFont->Direction = preferredFont->Direction;
}//end


void
MyPreferences	::	SetPreferredFontFromData(	FontData * paramFontData)
{
	preferredFont->SetFamilyAndStyle(paramFontData->mui32FamilyAndStyle);
	preferredFont->SetSize(paramFontData->mfSize);
	preferredFont->SetShear(paramFontData->mfShear);
	preferredFont->SetRotation(paramFontData->mfRotation);
	preferredFont->SetSpacing(paramFontData->mui8Spacing);
	preferredFont->SetFace(paramFontData->mui16Face);
	preferredFont->SetFlags(paramFontData->mui32Flags);
}//end


void
MyPreferences	::	GetPreferredPrefPanelWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredPrefPanelWindowRect;
}//end


void
MyPreferences	::	SetPreferredPrefPanelWindowRect(	const BRect paramWindowRect)
{
	preferredPrefPanelWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredFontPrefWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredFontPrefWindowRect;
}//end


void
MyPreferences	::	SetPreferredFontPrefWindowRect(	const BRect paramWindowRect)
{
	preferredFontPrefWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredFontDisplayWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredFontDisplayWindowRect;
}//end


void
MyPreferences	::	SetPreferredFontDisplayWindowRect(	const BRect paramWindowRect)
{
	preferredFontDisplayWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredBasicColorWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredBasicColorWindowRect;
}//end


void
MyPreferences	::	SetPreferredBasicColorWindowRect(	const BRect paramWindowRect)
{
	preferredBasicColorWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorButtonWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorButtonWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorButtonWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorButtonWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorPictureButtonWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorPictureButtonWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorPictureButtonWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorPictureButtonWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorRadioButtonWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorRadioButtonWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorRadioButtonWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorRadioButtonWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorCheckBoxWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorCheckBoxWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorCheckBoxWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorCheckBoxWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorStringDrawerWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorStringDrawerWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorStringDrawerWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorStringDrawerWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredListViewWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredListViewWindowRect;
}//end


void
MyPreferences	::	SetPreferredListViewWindowRect(	const BRect paramWindowRect)
{
	preferredListViewWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorStatusBarWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorStatusBarWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorStatusBarWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorStatusBarWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorSliderWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorSliderWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorSliderWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorSliderWindowRect = paramWindowRect;
}//end



void
MyPreferences	::	GetPreferredSpecificColorColorControlWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorColorControlWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorColorControlWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorColorControlWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorTextViewWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorTextViewWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorTextViewWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorTextViewWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorListViewWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorListViewWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorListViewWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorListViewWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorUInt32ControlWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorUInt32ControlWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorUInt32ControlWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorUInt32ControlWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorInt8GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorInt8GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorInt8GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorInt8GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorUInt8GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorUInt8GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorUInt8GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorUInt8GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorInt16GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorInt16GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorInt16GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorInt16GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorUInt16GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorUInt16GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorUInt16GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorUInt16GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorInt32GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorInt32GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorInt32GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorInt32GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorUInt32GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorUInt32GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorUInt32GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorUInt32GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorInt64GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorInt64GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorInt64GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorInt64GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorUInt64GadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorUInt64GadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorUInt64GadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorUInt64GadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorFloatGadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorFloatGadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorFloatGadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorFloatGadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorHexGadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorHexGadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorHexGadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorHexGadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorStringGadgetWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorStringGadgetWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorStringGadgetWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorStringGadgetWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorFloatControlWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorFloatControlWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorFloatControlWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorFloatControlWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorStringControlWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorStringControlWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorStringControlWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorStringControlWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredSpecificColorColorWellWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredSpecificColorColorWellWindowRect;
}//end


void
MyPreferences	::	SetPreferredSpecificColorColorWellWindowRect(	const BRect paramWindowRect)
{
	preferredSpecificColorColorWellWindowRect = paramWindowRect;
}//end


void
MyPreferences	::	GetPreferredHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredHighColor.red;
	paramRGBColor->green = preferredHighColor.green;
	paramRGBColor->blue = preferredHighColor.blue;
	paramRGBColor->alpha = preferredHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredHighColor(	const rgb_color * paramRGBColor)
{
	preferredHighColor.red = paramRGBColor->red;
	preferredHighColor.green = paramRGBColor->green;
	preferredHighColor.blue = paramRGBColor->blue;
	preferredHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredLowColor.red;
	paramRGBColor->green = preferredLowColor.green;
	paramRGBColor->blue = preferredLowColor.blue;
	paramRGBColor->alpha = preferredLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredLowColor(	const rgb_color * paramRGBColor)
{
	preferredLowColor.red = paramRGBColor->red;
	preferredLowColor.green = paramRGBColor->green;
	preferredLowColor.blue = paramRGBColor->blue;
	preferredLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredViewColor.red;
	paramRGBColor->green = preferredViewColor.green;
	paramRGBColor->blue = preferredViewColor.blue;
	paramRGBColor->alpha = preferredViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredViewColor(	const rgb_color * paramRGBColor)
{
	preferredViewColor.red = paramRGBColor->red;
	preferredViewColor.green = paramRGBColor->green;
	preferredViewColor.blue = paramRGBColor->blue;
	preferredViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt32ControlHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt32ControlHighColor.red;
	paramRGBColor->green = preferredUInt32ControlHighColor.green;
	paramRGBColor->blue = preferredUInt32ControlHighColor.blue;
	paramRGBColor->alpha = preferredUInt32ControlHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt32ControlHighColor(	const rgb_color * paramRGBColor)
{
	preferredUInt32ControlHighColor.red = paramRGBColor->red;
	preferredUInt32ControlHighColor.green = paramRGBColor->green;
	preferredUInt32ControlHighColor.blue = paramRGBColor->blue;
	preferredUInt32ControlHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt32ControlLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt32ControlLowColor.red;
	paramRGBColor->green = preferredUInt32ControlLowColor.green;
	paramRGBColor->blue = preferredUInt32ControlLowColor.blue;
	paramRGBColor->alpha = preferredUInt32ControlLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt32ControlLowColor(	const rgb_color * paramRGBColor)
{
	preferredUInt32ControlLowColor.red = paramRGBColor->red;
	preferredUInt32ControlLowColor.green = paramRGBColor->green;
	preferredUInt32ControlLowColor.blue = paramRGBColor->blue;
	preferredUInt32ControlLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt32ControlViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt32ControlViewColor.red;
	paramRGBColor->green = preferredUInt32ControlViewColor.green;
	paramRGBColor->blue = preferredUInt32ControlViewColor.blue;
	paramRGBColor->alpha = preferredUInt32ControlViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt32ControlViewColor(	const rgb_color * paramRGBColor)
{
	preferredUInt32ControlViewColor.red = paramRGBColor->red;
	preferredUInt32ControlViewColor.green = paramRGBColor->green;
	preferredUInt32ControlViewColor.blue = paramRGBColor->blue;
	preferredUInt32ControlViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt8GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt8GadgetHighColor.red;
	paramRGBColor->green = preferredUInt8GadgetHighColor.green;
	paramRGBColor->blue = preferredUInt8GadgetHighColor.blue;
	paramRGBColor->alpha = preferredUInt8GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt8GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredUInt8GadgetHighColor.red = paramRGBColor->red;
	preferredUInt8GadgetHighColor.green = paramRGBColor->green;
	preferredUInt8GadgetHighColor.blue = paramRGBColor->blue;
	preferredUInt8GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt8GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt8GadgetLowColor.red;
	paramRGBColor->green = preferredUInt8GadgetLowColor.green;
	paramRGBColor->blue = preferredUInt8GadgetLowColor.blue;
	paramRGBColor->alpha = preferredUInt8GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt8GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredUInt8GadgetLowColor.red = paramRGBColor->red;
	preferredUInt8GadgetLowColor.green = paramRGBColor->green;
	preferredUInt8GadgetLowColor.blue = paramRGBColor->blue;
	preferredUInt8GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt8GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt8GadgetViewColor.red;
	paramRGBColor->green = preferredUInt8GadgetViewColor.green;
	paramRGBColor->blue = preferredUInt8GadgetViewColor.blue;
	paramRGBColor->alpha = preferredUInt8GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt8GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredUInt8GadgetViewColor.red = paramRGBColor->red;
	preferredUInt8GadgetViewColor.green = paramRGBColor->green;
	preferredUInt8GadgetViewColor.blue = paramRGBColor->blue;
	preferredUInt8GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt8GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt8GadgetHighColor.red;
	paramRGBColor->green = preferredInt8GadgetHighColor.green;
	paramRGBColor->blue = preferredInt8GadgetHighColor.blue;
	paramRGBColor->alpha = preferredInt8GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt8GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredInt8GadgetHighColor.red = paramRGBColor->red;
	preferredInt8GadgetHighColor.green = paramRGBColor->green;
	preferredInt8GadgetHighColor.blue = paramRGBColor->blue;
	preferredInt8GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt8GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt8GadgetLowColor.red;
	paramRGBColor->green = preferredInt8GadgetLowColor.green;
	paramRGBColor->blue = preferredInt8GadgetLowColor.blue;
	paramRGBColor->alpha = preferredInt8GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt8GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredInt8GadgetLowColor.red = paramRGBColor->red;
	preferredInt8GadgetLowColor.green = paramRGBColor->green;
	preferredInt8GadgetLowColor.blue = paramRGBColor->blue;
	preferredInt8GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt8GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt8GadgetViewColor.red;
	paramRGBColor->green = preferredInt8GadgetViewColor.green;
	paramRGBColor->blue = preferredInt8GadgetViewColor.blue;
	paramRGBColor->alpha = preferredInt8GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt8GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredInt8GadgetViewColor.red = paramRGBColor->red;
	preferredInt8GadgetViewColor.green = paramRGBColor->green;
	preferredInt8GadgetViewColor.blue = paramRGBColor->blue;
	preferredInt8GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt16GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt16GadgetHighColor.red;
	paramRGBColor->green = preferredUInt16GadgetHighColor.green;
	paramRGBColor->blue = preferredUInt16GadgetHighColor.blue;
	paramRGBColor->alpha = preferredUInt16GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt16GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredUInt16GadgetHighColor.red = paramRGBColor->red;
	preferredUInt16GadgetHighColor.green = paramRGBColor->green;
	preferredUInt16GadgetHighColor.blue = paramRGBColor->blue;
	preferredUInt16GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt16GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt16GadgetLowColor.red;
	paramRGBColor->green = preferredUInt16GadgetLowColor.green;
	paramRGBColor->blue = preferredUInt16GadgetLowColor.blue;
	paramRGBColor->alpha = preferredUInt16GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt16GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredUInt16GadgetLowColor.red = paramRGBColor->red;
	preferredUInt16GadgetLowColor.green = paramRGBColor->green;
	preferredUInt16GadgetLowColor.blue = paramRGBColor->blue;
	preferredUInt16GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt16GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt16GadgetViewColor.red;
	paramRGBColor->green = preferredUInt16GadgetViewColor.green;
	paramRGBColor->blue = preferredUInt16GadgetViewColor.blue;
	paramRGBColor->alpha = preferredUInt16GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt16GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredUInt16GadgetViewColor.red = paramRGBColor->red;
	preferredUInt16GadgetViewColor.green = paramRGBColor->green;
	preferredUInt16GadgetViewColor.blue = paramRGBColor->blue;
	preferredUInt16GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt16GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt16GadgetHighColor.red;
	paramRGBColor->green = preferredInt16GadgetHighColor.green;
	paramRGBColor->blue = preferredInt16GadgetHighColor.blue;
	paramRGBColor->alpha = preferredInt16GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt16GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredInt16GadgetHighColor.red = paramRGBColor->red;
	preferredInt16GadgetHighColor.green = paramRGBColor->green;
	preferredInt16GadgetHighColor.blue = paramRGBColor->blue;
	preferredInt16GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt16GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt16GadgetLowColor.red;
	paramRGBColor->green = preferredInt16GadgetLowColor.green;
	paramRGBColor->blue = preferredInt16GadgetLowColor.blue;
	paramRGBColor->alpha = preferredInt16GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt16GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredInt16GadgetLowColor.red = paramRGBColor->red;
	preferredInt16GadgetLowColor.green = paramRGBColor->green;
	preferredInt16GadgetLowColor.blue = paramRGBColor->blue;
	preferredInt16GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt16GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt16GadgetViewColor.red;
	paramRGBColor->green = preferredInt16GadgetViewColor.green;
	paramRGBColor->blue = preferredInt16GadgetViewColor.blue;
	paramRGBColor->alpha = preferredInt16GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt16GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredInt16GadgetViewColor.red = paramRGBColor->red;
	preferredInt16GadgetViewColor.green = paramRGBColor->green;
	preferredInt16GadgetViewColor.blue = paramRGBColor->blue;
	preferredInt16GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt32GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt32GadgetHighColor.red;
	paramRGBColor->green = preferredUInt32GadgetHighColor.green;
	paramRGBColor->blue = preferredUInt32GadgetHighColor.blue;
	paramRGBColor->alpha = preferredUInt32GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt32GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredUInt32GadgetHighColor.red = paramRGBColor->red;
	preferredUInt32GadgetHighColor.green = paramRGBColor->green;
	preferredUInt32GadgetHighColor.blue = paramRGBColor->blue;
	preferredUInt32GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt32GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt32GadgetLowColor.red;
	paramRGBColor->green = preferredUInt32GadgetLowColor.green;
	paramRGBColor->blue = preferredUInt32GadgetLowColor.blue;
	paramRGBColor->alpha = preferredUInt32GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt32GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredUInt32GadgetLowColor.red = paramRGBColor->red;
	preferredUInt32GadgetLowColor.green = paramRGBColor->green;
	preferredUInt32GadgetLowColor.blue = paramRGBColor->blue;
	preferredUInt32GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt32GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt32GadgetViewColor.red;
	paramRGBColor->green = preferredUInt32GadgetViewColor.green;
	paramRGBColor->blue = preferredUInt32GadgetViewColor.blue;
	paramRGBColor->alpha = preferredUInt32GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt32GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredUInt32GadgetViewColor.red = paramRGBColor->red;
	preferredUInt32GadgetViewColor.green = paramRGBColor->green;
	preferredUInt32GadgetViewColor.blue = paramRGBColor->blue;
	preferredUInt32GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt32GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt32GadgetHighColor.red;
	paramRGBColor->green = preferredInt32GadgetHighColor.green;
	paramRGBColor->blue = preferredInt32GadgetHighColor.blue;
	paramRGBColor->alpha = preferredInt32GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt32GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredInt32GadgetHighColor.red = paramRGBColor->red;
	preferredInt32GadgetHighColor.green = paramRGBColor->green;
	preferredInt32GadgetHighColor.blue = paramRGBColor->blue;
	preferredInt32GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt32GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt32GadgetLowColor.red;
	paramRGBColor->green = preferredInt32GadgetLowColor.green;
	paramRGBColor->blue = preferredInt32GadgetLowColor.blue;
	paramRGBColor->alpha = preferredInt32GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt32GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredInt32GadgetLowColor.red = paramRGBColor->red;
	preferredInt32GadgetLowColor.green = paramRGBColor->green;
	preferredInt32GadgetLowColor.blue = paramRGBColor->blue;
	preferredInt32GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt32GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt32GadgetViewColor.red;
	paramRGBColor->green = preferredInt32GadgetViewColor.green;
	paramRGBColor->blue = preferredInt32GadgetViewColor.blue;
	paramRGBColor->alpha = preferredInt32GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt32GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredInt32GadgetViewColor.red = paramRGBColor->red;
	preferredInt32GadgetViewColor.green = paramRGBColor->green;
	preferredInt32GadgetViewColor.blue = paramRGBColor->blue;
	preferredInt32GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt64GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt64GadgetHighColor.red;
	paramRGBColor->green = preferredUInt64GadgetHighColor.green;
	paramRGBColor->blue = preferredUInt64GadgetHighColor.blue;
	paramRGBColor->alpha = preferredUInt64GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt64GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredUInt64GadgetHighColor.red = paramRGBColor->red;
	preferredUInt64GadgetHighColor.green = paramRGBColor->green;
	preferredUInt64GadgetHighColor.blue = paramRGBColor->blue;
	preferredUInt64GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt64GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt64GadgetLowColor.red;
	paramRGBColor->green = preferredUInt64GadgetLowColor.green;
	paramRGBColor->blue = preferredUInt64GadgetLowColor.blue;
	paramRGBColor->alpha = preferredUInt64GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt64GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredUInt64GadgetLowColor.red = paramRGBColor->red;
	preferredUInt64GadgetLowColor.green = paramRGBColor->green;
	preferredUInt64GadgetLowColor.blue = paramRGBColor->blue;
	preferredUInt64GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredUInt64GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredUInt64GadgetViewColor.red;
	paramRGBColor->green = preferredUInt64GadgetViewColor.green;
	paramRGBColor->blue = preferredUInt64GadgetViewColor.blue;
	paramRGBColor->alpha = preferredUInt64GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredUInt64GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredUInt64GadgetViewColor.red = paramRGBColor->red;
	preferredUInt64GadgetViewColor.green = paramRGBColor->green;
	preferredUInt64GadgetViewColor.blue = paramRGBColor->blue;
	preferredUInt64GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt64GadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt64GadgetHighColor.red;
	paramRGBColor->green = preferredInt64GadgetHighColor.green;
	paramRGBColor->blue = preferredInt64GadgetHighColor.blue;
	paramRGBColor->alpha = preferredInt64GadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt64GadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredInt64GadgetHighColor.red = paramRGBColor->red;
	preferredInt64GadgetHighColor.green = paramRGBColor->green;
	preferredInt64GadgetHighColor.blue = paramRGBColor->blue;
	preferredInt64GadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt64GadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt64GadgetLowColor.red;
	paramRGBColor->green = preferredInt64GadgetLowColor.green;
	paramRGBColor->blue = preferredInt64GadgetLowColor.blue;
	paramRGBColor->alpha = preferredInt64GadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt64GadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredInt64GadgetLowColor.red = paramRGBColor->red;
	preferredInt64GadgetLowColor.green = paramRGBColor->green;
	preferredInt64GadgetLowColor.blue = paramRGBColor->blue;
	preferredInt64GadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredInt64GadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredInt64GadgetViewColor.red;
	paramRGBColor->green = preferredInt64GadgetViewColor.green;
	paramRGBColor->blue = preferredInt64GadgetViewColor.blue;
	paramRGBColor->alpha = preferredInt64GadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredInt64GadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredInt64GadgetViewColor.red = paramRGBColor->red;
	preferredInt64GadgetViewColor.green = paramRGBColor->green;
	preferredInt64GadgetViewColor.blue = paramRGBColor->blue;
	preferredInt64GadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredFloatGadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredFloatGadgetHighColor.red;
	paramRGBColor->green = preferredFloatGadgetHighColor.green;
	paramRGBColor->blue = preferredFloatGadgetHighColor.blue;
	paramRGBColor->alpha = preferredFloatGadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredFloatGadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredFloatGadgetHighColor.red = paramRGBColor->red;
	preferredFloatGadgetHighColor.green = paramRGBColor->green;
	preferredFloatGadgetHighColor.blue = paramRGBColor->blue;
	preferredFloatGadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredFloatGadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredFloatGadgetLowColor.red;
	paramRGBColor->green = preferredFloatGadgetLowColor.green;
	paramRGBColor->blue = preferredFloatGadgetLowColor.blue;
	paramRGBColor->alpha = preferredFloatGadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredFloatGadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredFloatGadgetLowColor.red = paramRGBColor->red;
	preferredFloatGadgetLowColor.green = paramRGBColor->green;
	preferredFloatGadgetLowColor.blue = paramRGBColor->blue;
	preferredFloatGadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredFloatGadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredFloatGadgetViewColor.red;
	paramRGBColor->green = preferredFloatGadgetViewColor.green;
	paramRGBColor->blue = preferredFloatGadgetViewColor.blue;
	paramRGBColor->alpha = preferredFloatGadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredFloatGadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredFloatGadgetViewColor.red = paramRGBColor->red;
	preferredFloatGadgetViewColor.green = paramRGBColor->green;
	preferredFloatGadgetViewColor.blue = paramRGBColor->blue;
	preferredFloatGadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredHexGadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredHexGadgetHighColor.red;
	paramRGBColor->green = preferredHexGadgetHighColor.green;
	paramRGBColor->blue = preferredHexGadgetHighColor.blue;
	paramRGBColor->alpha = preferredHexGadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredHexGadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredHexGadgetHighColor.red = paramRGBColor->red;
	preferredHexGadgetHighColor.green = paramRGBColor->green;
	preferredHexGadgetHighColor.blue = paramRGBColor->blue;
	preferredHexGadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredHexGadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredHexGadgetLowColor.red;
	paramRGBColor->green = preferredHexGadgetLowColor.green;
	paramRGBColor->blue = preferredHexGadgetLowColor.blue;
	paramRGBColor->alpha = preferredHexGadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredHexGadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredHexGadgetLowColor.red = paramRGBColor->red;
	preferredHexGadgetLowColor.green = paramRGBColor->green;
	preferredHexGadgetLowColor.blue = paramRGBColor->blue;
	preferredHexGadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredHexGadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredHexGadgetViewColor.red;
	paramRGBColor->green = preferredHexGadgetViewColor.green;
	paramRGBColor->blue = preferredHexGadgetViewColor.blue;
	paramRGBColor->alpha = preferredHexGadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredHexGadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredHexGadgetViewColor.red = paramRGBColor->red;
	preferredHexGadgetViewColor.green = paramRGBColor->green;
	preferredHexGadgetViewColor.blue = paramRGBColor->blue;
	preferredHexGadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredStringGadgetHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredStringGadgetHighColor.red;
	paramRGBColor->green = preferredStringGadgetHighColor.green;
	paramRGBColor->blue = preferredStringGadgetHighColor.blue;
	paramRGBColor->alpha = preferredStringGadgetHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredStringGadgetHighColor(	const rgb_color * paramRGBColor)
{
	preferredStringGadgetHighColor.red = paramRGBColor->red;
	preferredStringGadgetHighColor.green = paramRGBColor->green;
	preferredStringGadgetHighColor.blue = paramRGBColor->blue;
	preferredStringGadgetHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredStringGadgetLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredStringGadgetLowColor.red;
	paramRGBColor->green = preferredStringGadgetLowColor.green;
	paramRGBColor->blue = preferredStringGadgetLowColor.blue;
	paramRGBColor->alpha = preferredStringGadgetLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredStringGadgetLowColor(	const rgb_color * paramRGBColor)
{
	preferredStringGadgetLowColor.red = paramRGBColor->red;
	preferredStringGadgetLowColor.green = paramRGBColor->green;
	preferredStringGadgetLowColor.blue = paramRGBColor->blue;
	preferredStringGadgetLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredStringGadgetViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredStringGadgetViewColor.red;
	paramRGBColor->green = preferredStringGadgetViewColor.green;
	paramRGBColor->blue = preferredStringGadgetViewColor.blue;
	paramRGBColor->alpha = preferredStringGadgetViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredStringGadgetViewColor(	const rgb_color * paramRGBColor)
{
	preferredStringGadgetViewColor.red = paramRGBColor->red;
	preferredStringGadgetViewColor.green = paramRGBColor->green;
	preferredStringGadgetViewColor.blue = paramRGBColor->blue;
	preferredStringGadgetViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredFloatControlHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredFloatControlHighColor.red;
	paramRGBColor->green = preferredFloatControlHighColor.green;
	paramRGBColor->blue = preferredFloatControlHighColor.blue;
	paramRGBColor->alpha = preferredFloatControlHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredFloatControlHighColor(	const rgb_color * paramRGBColor)
{
	preferredFloatControlHighColor.red = paramRGBColor->red;
	preferredFloatControlHighColor.green = paramRGBColor->green;
	preferredFloatControlHighColor.blue = paramRGBColor->blue;
	preferredFloatControlHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredFloatControlLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredFloatControlLowColor.red;
	paramRGBColor->green = preferredFloatControlLowColor.green;
	paramRGBColor->blue = preferredFloatControlLowColor.blue;
	paramRGBColor->alpha = preferredFloatControlLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredFloatControlLowColor(	const rgb_color * paramRGBColor)
{
	preferredFloatControlLowColor.red = paramRGBColor->red;
	preferredFloatControlLowColor.green = paramRGBColor->green;
	preferredFloatControlLowColor.blue = paramRGBColor->blue;
	preferredFloatControlLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredFloatControlViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredFloatControlViewColor.red;
	paramRGBColor->green = preferredFloatControlViewColor.green;
	paramRGBColor->blue = preferredFloatControlViewColor.blue;
	paramRGBColor->alpha = preferredFloatControlViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredFloatControlViewColor(	const rgb_color * paramRGBColor)
{
	preferredFloatControlViewColor.red = paramRGBColor->red;
	preferredFloatControlViewColor.green = paramRGBColor->green;
	preferredFloatControlViewColor.blue = paramRGBColor->blue;
	preferredFloatControlViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyCheckBoxHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyCheckBoxHighColor.red;
	paramRGBColor->green = preferredMyCheckBoxHighColor.green;
	paramRGBColor->blue = preferredMyCheckBoxHighColor.blue;
	paramRGBColor->alpha = preferredMyCheckBoxHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyCheckBoxHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyCheckBoxHighColor.red = paramRGBColor->red;
	preferredMyCheckBoxHighColor.green = paramRGBColor->green;
	preferredMyCheckBoxHighColor.blue = paramRGBColor->blue;
	preferredMyCheckBoxHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyCheckBoxLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyCheckBoxLowColor.red;
	paramRGBColor->green = preferredMyCheckBoxLowColor.green;
	paramRGBColor->blue = preferredMyCheckBoxLowColor.blue;
	paramRGBColor->alpha = preferredMyCheckBoxLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyCheckBoxLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyCheckBoxLowColor.red = paramRGBColor->red;
	preferredMyCheckBoxLowColor.green = paramRGBColor->green;
	preferredMyCheckBoxLowColor.blue = paramRGBColor->blue;
	preferredMyCheckBoxLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyCheckBoxViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyCheckBoxViewColor.red;
	paramRGBColor->green = preferredMyCheckBoxViewColor.green;
	paramRGBColor->blue = preferredMyCheckBoxViewColor.blue;
	paramRGBColor->alpha = preferredMyCheckBoxViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyCheckBoxViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyCheckBoxViewColor.red = paramRGBColor->red;
	preferredMyCheckBoxViewColor.green = paramRGBColor->green;
	preferredMyCheckBoxViewColor.blue = paramRGBColor->blue;
	preferredMyCheckBoxViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyPictureButtonHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyPictureButtonHighColor.red;
	paramRGBColor->green = preferredMyPictureButtonHighColor.green;
	paramRGBColor->blue = preferredMyPictureButtonHighColor.blue;
	paramRGBColor->alpha = preferredMyPictureButtonHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyPictureButtonHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyPictureButtonHighColor.red = paramRGBColor->red;
	preferredMyPictureButtonHighColor.green = paramRGBColor->green;
	preferredMyPictureButtonHighColor.blue = paramRGBColor->blue;
	preferredMyPictureButtonHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyPictureButtonLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyPictureButtonLowColor.red;
	paramRGBColor->green = preferredMyPictureButtonLowColor.green;
	paramRGBColor->blue = preferredMyPictureButtonLowColor.blue;
	paramRGBColor->alpha = preferredMyPictureButtonLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyPictureButtonLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyPictureButtonLowColor.red = paramRGBColor->red;
	preferredMyPictureButtonLowColor.green = paramRGBColor->green;
	preferredMyPictureButtonLowColor.blue = paramRGBColor->blue;
	preferredMyPictureButtonLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyPictureButtonViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyPictureButtonViewColor.red;
	paramRGBColor->green = preferredMyPictureButtonViewColor.green;
	paramRGBColor->blue = preferredMyPictureButtonViewColor.blue;
	paramRGBColor->alpha = preferredMyPictureButtonViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyPictureButtonViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyPictureButtonViewColor.red = paramRGBColor->red;
	preferredMyPictureButtonViewColor.green = paramRGBColor->green;
	preferredMyPictureButtonViewColor.blue = paramRGBColor->blue;
	preferredMyPictureButtonViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyStatusBarHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyStatusBarHighColor.red;
	paramRGBColor->green = preferredMyStatusBarHighColor.green;
	paramRGBColor->blue = preferredMyStatusBarHighColor.blue;
	paramRGBColor->alpha = preferredMyStatusBarHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyStatusBarHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyStatusBarHighColor.red = paramRGBColor->red;
	preferredMyStatusBarHighColor.green = paramRGBColor->green;
	preferredMyStatusBarHighColor.blue = paramRGBColor->blue;
	preferredMyStatusBarHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyStatusBarLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyStatusBarLowColor.red;
	paramRGBColor->green = preferredMyStatusBarLowColor.green;
	paramRGBColor->blue = preferredMyStatusBarLowColor.blue;
	paramRGBColor->alpha = preferredMyStatusBarLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyStatusBarLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyStatusBarLowColor.red = paramRGBColor->red;
	preferredMyStatusBarLowColor.green = paramRGBColor->green;
	preferredMyStatusBarLowColor.blue = paramRGBColor->blue;
	preferredMyStatusBarLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyStatusBarViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyStatusBarViewColor.red;
	paramRGBColor->green = preferredMyStatusBarViewColor.green;
	paramRGBColor->blue = preferredMyStatusBarViewColor.blue;
	paramRGBColor->alpha = preferredMyStatusBarViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyStatusBarViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyStatusBarViewColor.red = paramRGBColor->red;
	preferredMyStatusBarViewColor.green = paramRGBColor->green;
	preferredMyStatusBarViewColor.blue = paramRGBColor->blue;
	preferredMyStatusBarViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyBarStatusColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyBarStatusColor.red;
	paramRGBColor->green = preferredMyBarStatusColor.green;
	paramRGBColor->blue = preferredMyBarStatusColor.blue;
	paramRGBColor->alpha = preferredMyBarStatusColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyBarStatusColor(	const rgb_color * paramRGBColor)
{
	preferredMyBarStatusColor.red = paramRGBColor->red;
	preferredMyBarStatusColor.green = paramRGBColor->green;
	preferredMyBarStatusColor.blue = paramRGBColor->blue;
	preferredMyBarStatusColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMySliderHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMySliderHighColor.red;
	paramRGBColor->green = preferredMySliderHighColor.green;
	paramRGBColor->blue = preferredMySliderHighColor.blue;
	paramRGBColor->alpha = preferredMySliderHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMySliderHighColor(	const rgb_color * paramRGBColor)
{
	preferredMySliderHighColor.red = paramRGBColor->red;
	preferredMySliderHighColor.green = paramRGBColor->green;
	preferredMySliderHighColor.blue = paramRGBColor->blue;
	preferredMySliderHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMySliderLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMySliderLowColor.red;
	paramRGBColor->green = preferredMySliderLowColor.green;
	paramRGBColor->blue = preferredMySliderLowColor.blue;
	paramRGBColor->alpha = preferredMySliderLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMySliderLowColor(	const rgb_color * paramRGBColor)
{
	preferredMySliderLowColor.red = paramRGBColor->red;
	preferredMySliderLowColor.green = paramRGBColor->green;
	preferredMySliderLowColor.blue = paramRGBColor->blue;
	preferredMySliderLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMySliderViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMySliderViewColor.red;
	paramRGBColor->green = preferredMySliderViewColor.green;
	paramRGBColor->blue = preferredMySliderViewColor.blue;
	paramRGBColor->alpha = preferredMySliderViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMySliderViewColor(	const rgb_color * paramRGBColor)
{
	preferredMySliderViewColor.red = paramRGBColor->red;
	preferredMySliderViewColor.green = paramRGBColor->green;
	preferredMySliderViewColor.blue = paramRGBColor->blue;
	preferredMySliderViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyBarSliderColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyBarSliderColor.red;
	paramRGBColor->green = preferredMyBarSliderColor.green;
	paramRGBColor->blue = preferredMyBarSliderColor.blue;
	paramRGBColor->alpha = preferredMyBarSliderColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyBarSliderColor(	const rgb_color * paramRGBColor)
{
	preferredMyBarSliderColor.red = paramRGBColor->red;
	preferredMyBarSliderColor.green = paramRGBColor->green;
	preferredMyBarSliderColor.blue = paramRGBColor->blue;
	preferredMyBarSliderColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyBarFillSliderColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyBarFillSliderColor.red;
	paramRGBColor->green = preferredMyBarFillSliderColor.green;
	paramRGBColor->blue = preferredMyBarFillSliderColor.blue;
	paramRGBColor->alpha = preferredMyBarFillSliderColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyBarFillSliderColor(	const rgb_color * paramRGBColor)
{
	preferredMyBarFillSliderColor.red = paramRGBColor->red;
	preferredMyBarFillSliderColor.green = paramRGBColor->green;
	preferredMyBarFillSliderColor.blue = paramRGBColor->blue;
	preferredMyBarFillSliderColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyColorControlHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyColorControlHighColor.red;
	paramRGBColor->green = preferredMyColorControlHighColor.green;
	paramRGBColor->blue = preferredMyColorControlHighColor.blue;
	paramRGBColor->alpha = preferredMyColorControlHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyColorControlHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyColorControlHighColor.red = paramRGBColor->red;
	preferredMyColorControlHighColor.green = paramRGBColor->green;
	preferredMyColorControlHighColor.blue = paramRGBColor->blue;
	preferredMyColorControlHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyColorControlLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyColorControlLowColor.red;
	paramRGBColor->green = preferredMyColorControlLowColor.green;
	paramRGBColor->blue = preferredMyColorControlLowColor.blue;
	paramRGBColor->alpha = preferredMyColorControlLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyColorControlLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyColorControlLowColor.red = paramRGBColor->red;
	preferredMyColorControlLowColor.green = paramRGBColor->green;
	preferredMyColorControlLowColor.blue = paramRGBColor->blue;
	preferredMyColorControlLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyColorControlViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyColorControlViewColor.red;
	paramRGBColor->green = preferredMyColorControlViewColor.green;
	paramRGBColor->blue = preferredMyColorControlViewColor.blue;
	paramRGBColor->alpha = preferredMyColorControlViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyColorControlViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyColorControlViewColor.red = paramRGBColor->red;
	preferredMyColorControlViewColor.green = paramRGBColor->green;
	preferredMyColorControlViewColor.blue = paramRGBColor->blue;
	preferredMyColorControlViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredColorWellHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredColorWellHighColor.red;
	paramRGBColor->green = preferredColorWellHighColor.green;
	paramRGBColor->blue = preferredColorWellHighColor.blue;
	paramRGBColor->alpha = preferredColorWellHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredColorWellHighColor(	const rgb_color * paramRGBColor)
{
	preferredColorWellHighColor.red = paramRGBColor->red;
	preferredColorWellHighColor.green = paramRGBColor->green;
	preferredColorWellHighColor.blue = paramRGBColor->blue;
	preferredColorWellHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredColorWellLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredColorWellLowColor.red;
	paramRGBColor->green = preferredColorWellLowColor.green;
	paramRGBColor->blue = preferredColorWellLowColor.blue;
	paramRGBColor->alpha = preferredColorWellLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredColorWellLowColor(	const rgb_color * paramRGBColor)
{
	preferredColorWellLowColor.red = paramRGBColor->red;
	preferredColorWellLowColor.green = paramRGBColor->green;
	preferredColorWellLowColor.blue = paramRGBColor->blue;
	preferredColorWellLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredColorWellViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredColorWellViewColor.red;
	paramRGBColor->green = preferredColorWellViewColor.green;
	paramRGBColor->blue = preferredColorWellViewColor.blue;
	paramRGBColor->alpha = preferredColorWellViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredColorWellViewColor(	const rgb_color * paramRGBColor)
{
	preferredColorWellViewColor.red = paramRGBColor->red;
	preferredColorWellViewColor.green = paramRGBColor->green;
	preferredColorWellViewColor.blue = paramRGBColor->blue;
	preferredColorWellViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyButtonHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyButtonHighColor.red;
	paramRGBColor->green = preferredMyButtonHighColor.green;
	paramRGBColor->blue = preferredMyButtonHighColor.blue;
	paramRGBColor->alpha = preferredMyButtonHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyButtonHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyButtonHighColor.red = paramRGBColor->red;
	preferredMyButtonHighColor.green = paramRGBColor->green;
	preferredMyButtonHighColor.blue = paramRGBColor->blue;
	preferredMyButtonHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyButtonLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyButtonLowColor.red;
	paramRGBColor->green = preferredMyButtonLowColor.green;
	paramRGBColor->blue = preferredMyButtonLowColor.blue;
	paramRGBColor->alpha = preferredMyButtonLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyButtonLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyButtonLowColor.red = paramRGBColor->red;
	preferredMyButtonLowColor.green = paramRGBColor->green;
	preferredMyButtonLowColor.blue = paramRGBColor->blue;
	preferredMyButtonLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyButtonViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyButtonViewColor.red;
	paramRGBColor->green = preferredMyButtonViewColor.green;
	paramRGBColor->blue = preferredMyButtonViewColor.blue;
	paramRGBColor->alpha = preferredMyButtonViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyButtonViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyButtonViewColor.red = paramRGBColor->red;
	preferredMyButtonViewColor.green = paramRGBColor->green;
	preferredMyButtonViewColor.blue = paramRGBColor->blue;
	preferredMyButtonViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyStringDrawerHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyStringDrawerHighColor.red;
	paramRGBColor->green = preferredMyStringDrawerHighColor.green;
	paramRGBColor->blue = preferredMyStringDrawerHighColor.blue;
	paramRGBColor->alpha = preferredMyStringDrawerHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyStringDrawerHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyStringDrawerHighColor.red = paramRGBColor->red;
	preferredMyStringDrawerHighColor.green = paramRGBColor->green;
	preferredMyStringDrawerHighColor.blue = paramRGBColor->blue;
	preferredMyStringDrawerHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyStringDrawerLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyStringDrawerLowColor.red;
	paramRGBColor->green = preferredMyStringDrawerLowColor.green;
	paramRGBColor->blue = preferredMyStringDrawerLowColor.blue;
	paramRGBColor->alpha = preferredMyStringDrawerLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyStringDrawerLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyStringDrawerLowColor.red = paramRGBColor->red;
	preferredMyStringDrawerLowColor.green = paramRGBColor->green;
	preferredMyStringDrawerLowColor.blue = paramRGBColor->blue;
	preferredMyStringDrawerLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyStringDrawerViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyStringDrawerViewColor.red;
	paramRGBColor->green = preferredMyStringDrawerViewColor.green;
	paramRGBColor->blue = preferredMyStringDrawerViewColor.blue;
	paramRGBColor->alpha = preferredMyStringDrawerViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyStringDrawerViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyStringDrawerViewColor.red = paramRGBColor->red;
	preferredMyStringDrawerViewColor.green = paramRGBColor->green;
	preferredMyStringDrawerViewColor.blue = paramRGBColor->blue;
	preferredMyStringDrawerViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredStringControlHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredStringControlHighColor.red;
	paramRGBColor->green = preferredStringControlHighColor.green;
	paramRGBColor->blue = preferredStringControlHighColor.blue;
	paramRGBColor->alpha = preferredStringControlHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredStringControlHighColor(	const rgb_color * paramRGBColor)
{
	preferredStringControlHighColor.red = paramRGBColor->red;
	preferredStringControlHighColor.green = paramRGBColor->green;
	preferredStringControlHighColor.blue = paramRGBColor->blue;
	preferredStringControlHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredStringControlLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredStringControlLowColor.red;
	paramRGBColor->green = preferredStringControlLowColor.green;
	paramRGBColor->blue = preferredStringControlLowColor.blue;
	paramRGBColor->alpha = preferredStringControlLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredStringControlLowColor(	const rgb_color * paramRGBColor)
{
	preferredStringControlLowColor.red = paramRGBColor->red;
	preferredStringControlLowColor.green = paramRGBColor->green;
	preferredStringControlLowColor.blue = paramRGBColor->blue;
	preferredStringControlLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredStringControlViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredStringControlViewColor.red;
	paramRGBColor->green = preferredStringControlViewColor.green;
	paramRGBColor->blue = preferredStringControlViewColor.blue;
	paramRGBColor->alpha = preferredStringControlViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredStringControlViewColor(	const rgb_color * paramRGBColor)
{
	preferredStringControlViewColor.red = paramRGBColor->red;
	preferredStringControlViewColor.green = paramRGBColor->green;
	preferredStringControlViewColor.blue = paramRGBColor->blue;
	preferredStringControlViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyRadioViewHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyRadioViewHighColor.red;
	paramRGBColor->green = preferredMyRadioViewHighColor.green;
	paramRGBColor->blue = preferredMyRadioViewHighColor.blue;
	paramRGBColor->alpha = preferredMyRadioViewHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyRadioViewHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyRadioViewHighColor.red = paramRGBColor->red;
	preferredMyRadioViewHighColor.green = paramRGBColor->green;
	preferredMyRadioViewHighColor.blue = paramRGBColor->blue;
	preferredMyRadioViewHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyRadioViewLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyRadioViewLowColor.red;
	paramRGBColor->green = preferredMyRadioViewLowColor.green;
	paramRGBColor->blue = preferredMyRadioViewLowColor.blue;
	paramRGBColor->alpha = preferredMyRadioViewLowColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyRadioViewLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyRadioViewLowColor.red = paramRGBColor->red;
	preferredMyRadioViewLowColor.green = paramRGBColor->green;
	preferredMyRadioViewLowColor.blue = paramRGBColor->blue;
	preferredMyRadioViewLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyRadioViewViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyRadioViewViewColor.red;
	paramRGBColor->green = preferredMyRadioViewViewColor.green;
	paramRGBColor->blue = preferredMyRadioViewViewColor.blue;
	paramRGBColor->alpha = preferredMyRadioViewViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyRadioViewViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyRadioViewViewColor.red = paramRGBColor->red;
	preferredMyRadioViewViewColor.green = paramRGBColor->green;
	preferredMyRadioViewViewColor.blue = paramRGBColor->blue;
	preferredMyRadioViewViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyTextViewHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyTextViewHighColor.red;
	paramRGBColor->green = preferredMyTextViewHighColor.green;
	paramRGBColor->blue = preferredMyTextViewHighColor.blue;
	paramRGBColor->alpha = preferredMyTextViewHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyTextViewHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyTextViewHighColor.red = paramRGBColor->red;
	preferredMyTextViewHighColor.green = paramRGBColor->green;
	preferredMyTextViewHighColor.blue = paramRGBColor->blue;
	preferredMyTextViewHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	SetPreferredMyTextViewLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyTextViewLowColor.red = paramRGBColor->red;
	preferredMyTextViewLowColor.green = paramRGBColor->green;
	preferredMyTextViewLowColor.blue = paramRGBColor->blue;
	preferredMyTextViewLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyTextViewLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyTextViewLowColor.red;
	paramRGBColor->green = preferredMyTextViewLowColor.green;
	paramRGBColor->blue = preferredMyTextViewLowColor.blue;
	paramRGBColor->alpha = preferredMyTextViewLowColor.alpha;
}//end


void
MyPreferences	::	GetPreferredMyTextViewViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyTextViewViewColor.red;
	paramRGBColor->green = preferredMyTextViewViewColor.green;
	paramRGBColor->blue = preferredMyTextViewViewColor.blue;
	paramRGBColor->alpha = preferredMyTextViewViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyTextViewViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyTextViewViewColor.red = paramRGBColor->red;
	preferredMyTextViewViewColor.green = paramRGBColor->green;
	preferredMyTextViewViewColor.blue = paramRGBColor->blue;
	preferredMyTextViewViewColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyListViewHighColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyListViewHighColor.red;
	paramRGBColor->green = preferredMyListViewHighColor.green;
	paramRGBColor->blue = preferredMyListViewHighColor.blue;
	paramRGBColor->alpha = preferredMyListViewHighColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyListViewHighColor(	const rgb_color * paramRGBColor)
{
	preferredMyListViewHighColor.red = paramRGBColor->red;
	preferredMyListViewHighColor.green = paramRGBColor->green;
	preferredMyListViewHighColor.blue = paramRGBColor->blue;
	preferredMyListViewHighColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	SetPreferredMyListViewLowColor(	const rgb_color * paramRGBColor)
{
	preferredMyListViewLowColor.red = paramRGBColor->red;
	preferredMyListViewLowColor.green = paramRGBColor->green;
	preferredMyListViewLowColor.blue = paramRGBColor->blue;
	preferredMyListViewLowColor.alpha = paramRGBColor->alpha;
}//end


void
MyPreferences	::	GetPreferredMyListViewLowColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyListViewLowColor.red;
	paramRGBColor->green = preferredMyListViewLowColor.green;
	paramRGBColor->blue = preferredMyListViewLowColor.blue;
	paramRGBColor->alpha = preferredMyListViewLowColor.alpha;
}//end



void
MyPreferences	::	GetPreferredMyListViewViewColor(	rgb_color * paramRGBColor) const
{
	paramRGBColor->red = preferredMyListViewViewColor.red;
	paramRGBColor->green = preferredMyListViewViewColor.green;
	paramRGBColor->blue = preferredMyListViewViewColor.blue;
	paramRGBColor->alpha = preferredMyListViewViewColor.alpha;
}//end


void
MyPreferences	::	SetPreferredMyListViewViewColor(	const rgb_color * paramRGBColor)
{
	preferredMyListViewViewColor.red = paramRGBColor->red;
	preferredMyListViewViewColor.green = paramRGBColor->green;
	preferredMyListViewViewColor.blue = paramRGBColor->blue;
	preferredMyListViewViewColor.alpha = paramRGBColor->alpha;
}//end


float
MyPreferences	::	GetPreferredBarHeight(	void) const
{
	return preferredBarHeight;
}//end

void
MyPreferences	::	SetPreferredBarHeight(	const float paramBarHeight)
{
	preferredBarHeight = paramBarHeight;
}//end


thumb_style
MyPreferences	::	GetPreferredThumbStyle(	void) const
{
	return mtsThumbStyle;
}//end


void
MyPreferences	::	SetPreferredThumbStyle(	const thumb_style paramThumbStyle)
{
	if 	(	(paramThumbStyle == B_BLOCK_THUMB)
			||
			(paramThumbStyle == B_TRIANGLE_THUMB)
		)
	{
		mtsThumbStyle = paramThumbStyle;
	}
	else
	{
		mtsThumbStyle = B_BLOCK_THUMB;
		warning(IllegalThumb);
	}
}//end


uint8
MyPreferences	::	GetPreferredColorWellHeight(	void) const
{
	return preferredColorWellHeight;
}//end

void
MyPreferences	::	SetPreferredColorWellHeight(	const uint8 paramColorWellHeight)
{
	preferredColorWellHeight = paramColorWellHeight;
}//end


uint8
MyPreferences	::	GetPreferredColorWellWidth(	void) const
{
	return preferredColorWellWidth;
}//end

void
MyPreferences	::	SetPreferredColorWellWidth(	const uint8 paramColorWellWidth)
{
	preferredColorWellWidth = paramColorWellWidth;
}//end


void
MyPreferences		::	  OpenPreferencesPanel(	void)
{
	if (pPrefPanelWindow)
	{
		pPrefPanelWindow->Activate(true);
	}
	else
	{
		try 
		{
			BRect holdRect;
			GetPreferredPrefPanelWindowRect(&holdRect);
			pPrefPanelWindow = new PrefPanelWindow(	holdRect,
													PreferencePanelWindowTitle,
													"PrefPanel",
													"PrefPanelFrame");
			pPrefPanelWindow->Initialize();
			BRect tpr = pPrefPanelWindow->Bounds();
			if (RectASmallerRectB(holdRect, tpr)) 
			{
				pPrefPanelWindow->ResizeTo(holdRect.Width(), holdRect.Height());
			}
			pPrefPanelWindow->Show();
		}
		catch (...) 
		{
			warning(NoPrefPanelWindow);
			throw;
		}
	}
}//end

