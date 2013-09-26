//stringGadget.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "gadgetBase.h"
#include "stringGadget.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "warning.h"
#include "filterCarriageReturn.h"
#include "myStringView.h"
#include "stringBoundsBox.h"

StringGadget	::	~StringGadget() 
{
	delete mpLabel;
};//end


//ctor
StringGadget	::	StringGadget(	const char * paramInitValue,
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
														KIND_STRINGGADGET);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
		if (paramLabel)
		{
			rgb_color * rgbV = new rgb_color;
			myPrefs->GetPreferredStringGadgetViewColor(rgbV);
			rgb_color * rgbH = new rgb_color;
			myPrefs->GetPreferredStringGadgetHighColor(rgbH);
			rgb_color * rgbL = new rgb_color;
			myPrefs->GetPreferredStringGadgetLowColor(rgbL);
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
	if (paramInitValue)
	{
		SetText(paramInitValue);
	}
	if (paramTextViewWidth > 0)
	{
		mfTextViewWidth = paramTextViewWidth;
	}
	else if (paramInitValue)
	{
		float leftOffset;
		float baseline;
		float height;
		if (!StringBoundsBox(	paramInitValue,
								&mfTextViewWidth,
								&height,
								&leftOffset,
								&baseline))
		{
			throw;
		}
		mfTextViewWidth += 10;
	}
	else
	{
		mfTextViewWidth = MINVIEWGADGETWIDTH;
	}
	BMessageFilter * bmf = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
												B_LOCAL_SOURCE, 
												'_KYD', 
												filterCarriageReturn);
	AddFilter(bmf);
}//end


void 
StringGadget	::	AttachedToWindow(	void)
{
	BTextView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredStringGadgetLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
	myPrefs->GetPreferredStringGadgetViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	myPrefs->GetPreferredStringGadgetHighColor(&tempRgbColor);
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
StringGadget	::	MessageReceived(	BMessage * paramMessage)
{
	BMessage * msg = new BMessage(paramMessage);
	mpMessageTarget->PostMessage(msg);
	BTextView::MessageReceived(paramMessage);
}//end