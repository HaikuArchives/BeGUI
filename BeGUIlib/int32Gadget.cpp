//int32Gadget.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "s2int32.h"
#include "filterIntNumeric.h"
#include "myStringView.h"
#include "gadgetBase.h"
#include "int32Gadget.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "warning.h"
#include "widestDigit.h"

Int32Gadget	::	~Int32Gadget() 
{
	//leaving blank
};//end


//ctor
Int32Gadget	::	Int32Gadget(	int32 paramInitValue,
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
														KIND_INT32GADGET);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
		if (paramLabel)
		{
			rgb_color * rgbV = new rgb_color;
			myPrefs->GetPreferredInt32GadgetViewColor(rgbV);
			rgb_color * rgbH = new rgb_color;
			myPrefs->GetPreferredInt32GadgetHighColor(rgbH);
			rgb_color * rgbL = new rgb_color;
			myPrefs->GetPreferredInt32GadgetLowColor(rgbL);
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
	char buf[DIGITSnI32];
	sprintf(buf, "%d", paramInitValue);
	SetText(buf);
	if (paramTextViewWidth > 0)
	{
		mfTextViewWidth = paramTextViewWidth;
	}
	else
	{
		mfTextViewWidth = WidestDigit() * (DIGITSnI32 - 1);
	}
	BMessageFilter * bmf = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
												B_LOCAL_SOURCE, 
												'_KYD', 
												filterIntNumeric);
	AddFilter(bmf);
}//end


void 
Int32Gadget	::	AttachedToWindow(	void)
{
	BTextView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredInt32GadgetLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredInt32GadgetViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	myPrefs->GetPreferredInt32GadgetHighColor(&tempRgbColor);
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
Int32Gadget	::	MessageReceived(	BMessage * paramMessage)
{
	const char * entry = Text();
	uint32 len = strlen(entry);//known not utf8
	int32 maxdigits = DIGITSnI32 - 2;
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
		if(s2int32(entry, &value) != B_OK)
		{
			notFailed = false;
		}
	}
	if (notFailed)
	{
		mbsValueString = entry;
		BMessage * msg = new BMessage(paramMessage);
		mpMessageTarget->PostMessage(msg);
		return;
	}
	BTextView::MessageReceived(paramMessage);
}//end