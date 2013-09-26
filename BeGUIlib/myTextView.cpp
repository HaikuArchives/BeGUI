//myTextView.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myTextView.h"
#include "myPreferences.h"
#include "layoutMatrix.h"
#include "warning.h"



MyTextView	::	~MyTextView() 
{
	//leaving blank
};//end


//ctor
MyTextView	::	MyTextView(	const char * paramName, 
							const char * paramText,
							float paramMaxWidth,
							float paramMaxHeight,
							LayoutMatrix * paramLayoutMatrix) 
				: 
					BTextView(	BRect(0,0,paramMaxWidth,paramMaxHeight), 
								paramName, 
								BRect(1,1,paramMaxWidth - 2,paramMaxWidth - 2), 
								B_FOLLOW_NONE, 
								B_WILL_DRAW),
					mfWidth(	paramMaxWidth),
					mfHeight(	paramMaxHeight)
{
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYTEXTVIEW);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
	paramLayoutMatrix->AddToChildren((void *)this);
	SetText(paramText);
	MakeResizable(false);
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyTextViewHighColor(&tempRgbColor);
	SetFontAndColor(myPrefs->GetPreferredFont(), B_FONT_ALL, &tempRgbColor);
}//end


void 
MyTextView	::	AttachedToWindow(	void)
{
	BTextView::AttachedToWindow();
	rgb_color tempRgbColor;
	myPrefs->GetPreferredMyTextViewViewColor(&tempRgbColor);
	SetViewColor(tempRgbColor);
	myPrefs->GetPreferredMyTextViewHighColor(&tempRgbColor);
	SetHighColor(tempRgbColor);
	myPrefs->GetPreferredMyTextViewLowColor(&tempRgbColor);
	SetLowColor(tempRgbColor);
}//end


void
MyTextView	::	MyGetPreferredSize(	float * paramWidth,
									float * paramHeight)
{
	*paramHeight = mfHeight;
	*paramWidth = mfWidth;
}//end