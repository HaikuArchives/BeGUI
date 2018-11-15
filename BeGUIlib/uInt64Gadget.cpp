//uInt64Gadget.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "s2uint64.h"
#include "filterUIntNumeric.h"
#include "myStringView.h"
#include "gadgetBase.h"
#include "uInt64Gadget.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "warning.h"
#include "widestDigit.h"

UInt64Gadget	::	~UInt64Gadget() 
{
	//leaving blank
};//end


//ctor
UInt64Gadget	::	UInt64Gadget(	uint64 ui64paramInitValue,
									const char * paramName, 
									const char * paramLabel, 
									float paramTextViewWidth,
									BLooper * paramMessageTarget,
									LayoutMatrix * paramLayoutMatrix,
									bool paramMakeFocus) 
				: 	GadgetBase(	paramName,
								paramLabel,
								paramMessageTarget,
								paramMakeFocus)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_UINT64GADGET);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
		if (paramLabel)
		{
			rgb_color * rgbV = new rgb_color;
			myPrefs->GetPreferredUInt64GadgetViewColor(rgbV);
			rgb_color * rgbH = new rgb_color;
			myPrefs->GetPreferredUInt64GadgetHighColor(rgbH);
			rgb_color * rgbL = new rgb_color;
			myPrefs->GetPreferredUInt64GadgetLowColor(rgbL);
			mpLabelView->SetViewColor(*rgbV);
			mpLabelView->SetViewColor(*rgbH);
			mpLabelView->SetViewColor(*rgbL);
		}
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren(this);
	char buf[DIGITSnUI64];
	sprintf(buf, "%Lu", ui64paramInitValue);
	SetText(buf);
	if (paramTextViewWidth > 0)
	{
		mfTextViewWidth = paramTextViewWidth;
	}
	else
	{
		mfTextViewWidth = WidestDigit() * (DIGITSnUI64 - 1);
	}
	BMessageFilter * bmf = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
												B_LOCAL_SOURCE, 
												'_KYD', 
												filterUIntNumeric);
	AddFilter(bmf);
}//end


void 
UInt64Gadget	::	AttachedToWindow(	void)
{
	BTextView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredUInt64GadgetLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredUInt64GadgetViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	myPrefs->GetPreferredUInt64GadgetHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	SetFontAndColor(	myPrefs->GetPreferredFont(),
						B_FONT_ALL,
						&tempRgbColor);
	if (mbMakeFocus) 
	{
		MakeFocus();
	}
}//end


void 
UInt64Gadget	::	MessageReceived(	BMessage * paramMessage)
{
	const char * entry = Text();
	uint32 len = strlen(entry);//known not utf8
	int32 maxdigits = DIGITSnUI64 - 2;
	if (entry[0] == '+')
	{
		maxdigits++;
	}
	bool notFailed = true;
	if (len > maxdigits)
	{
		warning(myPrefs->NumStrTooLong);
		notFailed = false;
		SetText(mbsValueString.String());
	}
	if (notFailed)
	{
		for (	int32 i = 1;
				i < maxdigits;
				i++
			)
		{
			if (entry[i] == 0xa)
			{
				i = maxdigits;
			}
			else
			{
				if (entry[i] == '+')
				{
					notFailed = false;
				}
			}
		}
	}
	if (notFailed)
	{
		uint64 value;
		if (s2uint64(entry, &value) == B_OK)
		{
			if (value > MAX_UI64)
			{
				notFailed = false;
				warning(myPrefs->NumTooBig);
			}
			else if (value < MIN_UI64)
			{
				notFailed = false;
				warning(myPrefs->NumTooSmall);
			}
		}
		else
		{
			notFailed = false;
		}
	}
	if (notFailed)
	{
		mbsValueString = entry;
		BMessage * msg = new BMessage(*paramMessage);
		mpMessageTarget->PostMessage(msg);
		return;
	}
	BTextView::MessageReceived(paramMessage);
}//end