//int8Gadget.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "filterIntNumeric.h"
#include "s2int32.h"
#include "myStringView.h"
#include "gadgetBase.h"
#include "int8Gadget.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "warning.h"
#include "widestDigit.h"


Int8Gadget	::	~Int8Gadget() 
{
	//leaving blank
};//end


//ctor
Int8Gadget	::	Int8Gadget(	int8 i8paramInitValue,
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
														KIND_INT8GADGET);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
		if (paramLabel)
		{
			rgb_color * rgbV = new rgb_color;
			myPrefs->GetPreferredInt8GadgetViewColor(rgbV);
			rgb_color * rgbH = new rgb_color;
			myPrefs->GetPreferredInt8GadgetHighColor(rgbH);
			rgb_color * rgbL = new rgb_color;
			myPrefs->GetPreferredInt8GadgetLowColor(rgbL);
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
	char buf[DIGITSnI8];
	sprintf(buf, "%d", i8paramInitValue);
	SetText(buf);
	mbsValueString = buf;
	if (paramTextViewWidth > 0)
	{
		mfTextViewWidth = paramTextViewWidth;
	}
	else
	{
		mfTextViewWidth = WidestDigit() * (DIGITSnI8 - 1);
	}
	BMessageFilter * bmf = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
												B_LOCAL_SOURCE, 
												'_KYD', 
												filterIntNumeric);
	AddFilter(bmf);
}//end


void 
Int8Gadget	::	AttachedToWindow(	void)
{
	BTextView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredInt8GadgetLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredInt8GadgetViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	myPrefs->GetPreferredInt8GadgetHighColor(&tempRgbColor);
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
Int8Gadget	::	MessageReceived(	BMessage * paramMessage)
{
	const char * entry = Text();
	uint32 len = strlen(entry);//known not utf8
	uint32 maxdigits = DIGITSnI8 - 2;
	if ((entry[0] == '-') || (entry[0] == '+'))
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
				if ((entry[i] == '+') || (entry[i] == '-'))
				{
					notFailed = false;
				}
			}
		}
	}
	if (notFailed)
	{
		int32 value;
		if(s2int32(entry, &value) == B_OK)
		{
			if (value > MAX_I8)
			{
				notFailed = false;
				warning(myPrefs->NumTooBig);
			}
			else if (value < MIN_I8)
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