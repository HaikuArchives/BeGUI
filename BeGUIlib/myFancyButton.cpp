//myFancyButton.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "Preferences.h"
#include "myPictureButton.h"
#include "myFancyButton.h"
#include "layoutMatrix.h"
#include "myPreferences.h"
#include "warning.h"
#include "stringBoundsBox.h"

MyFancyButton	::	~MyFancyButton() 
{
	//leaving blank
};//end


//ctor
MyFancyButton	::	MyFancyButton(	const char * paramName, 
									const char * paramLabel,
									uint32 paramMsg,
									LayoutMatrix * paramLayoutMatrix,
									rgb_color * paramHighColor,
									rgb_color * paramLowColor,
									rgb_color * paramViewColor,
									BFont * paramFont,
									uint32 paramBehavior,
									bool paramSetEnabled,
									int paramOnOff) 
				:
					mpBPictureButton(NULL),
					mbsLabel(paramLabel)
{
	try
	{
		BFont * useFont = paramFont;
		if (!paramFont)
		{
			useFont = myPrefs->GetPreferredFont();
		}
		BRect boundsRect(0, 0, 32, 32);
		float boundsWidth;
		float boundsHeight;
		float textLeftEdge;
		float textBaseline;
		if (StringBoundsBox(	paramLabel,
								&boundsWidth,
								&boundsHeight,
								&textLeftEdge,
								&textBaseline,
								useFont))
		{
			float rightAdjustment = textLeftEdge;
			textLeftEdge *= -1;
			textLeftEdge += 6;
			textBaseline += 6;
			boundsRect.right = boundsWidth + 10 - rightAdjustment;
			boundsRect.bottom = boundsHeight + 11;
		}
		else
		{
			boundsRect.right = DEFAULT_MAX_FANCY_WIDTH;
			boundsRect.bottom = DEFUALT_MAX_FANCY_HEIGHT;
		}
		BWindow * bWindow = new BWindow(	boundsRect, //BWindow manditory for BPicture
											NULL, 
											B_DOCUMENT_WINDOW, 
											0);
		BView * bView = new BView(	boundsRect, 
									NULL, 
									B_FOLLOW_NONE, 
									0);
		bWindow->AddChild(bView);
		bView->SetFont(useFont);
		font_height fontHeight;
		bView->GetFontHeight(&fontHeight);
		BPicture * pOnPicture;
		BPicture * pOnDisabledPicture;
		BPicture * pOffPicture;
		BPicture * pOffDisabledPicture;
		rgb_color highColor;
		if (paramHighColor)
		{
			highColor.red = paramHighColor->red;
			highColor.green = paramHighColor->green;
			highColor.blue = paramHighColor->blue;
			highColor.alpha = paramHighColor->alpha;
		}
		else
		{
			myPrefs->GetPreferredHighColor(&highColor);
		}
		bView->SetHighColor(highColor);
		rgb_color lowColor;
		if (paramLowColor)
		{
			lowColor.red = paramLowColor->red;
			lowColor.green = paramLowColor->green;
			lowColor.blue = paramLowColor->blue;
			lowColor.alpha = paramLowColor->alpha;
		}
		else
		{
			myPrefs->GetPreferredLowColor(&lowColor);
		}
		bView->SetLowColor(lowColor);
		rgb_color viewColor;
		if (paramViewColor)
		{
			viewColor.red = paramViewColor->red;
			viewColor.green = paramViewColor->green;
			viewColor.blue = paramViewColor->blue;
			viewColor.alpha = paramViewColor->alpha;
		}
		else
		{
			myPrefs->GetPreferredViewColor(&viewColor);
		}
		bView->SetViewColor(viewColor);
		rgb_color viewMostDimColor(viewColor);
		viewMostDimColor.red *= .85;
		viewMostDimColor.green *= .85;
		viewMostDimColor.blue *= .85;
		rgb_color viewLeastDimColor(viewColor);
		viewLeastDimColor.red *= .95;
		viewLeastDimColor.green *= .95;
		viewLeastDimColor.blue *= .95;
		rgb_color viewBrightGlintColor;
		viewBrightGlintColor.red = 255;
		viewBrightGlintColor.green = 255;
		viewBrightGlintColor.blue = 235;
		rgb_color viewDimGlintColor(viewBrightGlintColor);
		viewDimGlintColor.red = 220;
		viewDimGlintColor.green = 220;
		viewDimGlintColor.blue = 200;
		rgb_color viewDarkShadowColor;
		viewDarkShadowColor.red = 90;
		viewDarkShadowColor.green = 90;
		viewDarkShadowColor.blue = 100;
		rgb_color viewLightShadowColor(viewDarkShadowColor);
		viewLightShadowColor.red = 135;
		viewLightShadowColor.green = 135;
		viewLightShadowColor.blue = 145;
		
		bView->BeginPicture(new BPicture);
		{
			bView->SetHighColor(viewColor);
			bView->FillRect(boundsRect);
			bView->SetHighColor(viewLeastDimColor);
			bView->StrokeRect(boundsRect);
			BRect framer(boundsRect);
			framer.InsetBy(1, 1);
			bView->SetHighColor(viewMostDimColor);
			bView->StrokeRect(framer);
			bView->SetHighColor(viewLeastDimColor);
			bView->StrokeLine(BPoint(1, 1), BPoint(1, 1));
			bView->StrokeLine(BPoint(framer.right, 1), BPoint(framer.right, 1));
			bView->StrokeLine(BPoint(1, framer.bottom), BPoint(1, framer.bottom));
			bView->StrokeLine(BPoint(framer.right, framer.bottom), BPoint(framer.right, framer.bottom));
			bView->StrokeLine(BPoint(2, 2), BPoint(2, framer.bottom - 1));
			bView->StrokeLine(BPoint(2, 2), BPoint(framer.right - 1, 2));
			bView->SetHighColor(viewBrightGlintColor);
			bView->StrokeLine(BPoint(3, 3), BPoint(framer.right - 2, 3));
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeLine(BPoint(5, 4), BPoint(framer.right - 3, 4));
			bView->SetHighColor(viewBrightGlintColor);
			bView->StrokeLine(BPoint(3, 4), BPoint(3, framer.bottom - 2));
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeLine(BPoint(4, 5), BPoint(4, framer.bottom - 3));
			bView->SetHighColor(viewDarkShadowColor);
			bView->StrokeLine(BPoint(framer.right - 1, 3), BPoint(framer.right - 1, framer.bottom - 2));
			bView->StrokeLine(BPoint(3, framer.bottom - 1), BPoint(framer.right - 1, framer.bottom - 1));
			bView->SetHighColor(viewLightShadowColor);
			bView->StrokeLine(BPoint(framer.right - 2, 4), BPoint(framer.right - 2, framer.bottom - 3));
			bView->StrokeLine(BPoint(4, framer.bottom - 2), BPoint(framer.right - 2, framer.bottom - 2));
			bView->SetHighColor(highColor);
			bView->MovePenTo(textLeftEdge, textBaseline);
			bView->DrawString(paramLabel);
		}
		pOffPicture = bView->EndPicture();
		
		bView->BeginPicture(new BPicture);
		{
			bView->SetHighColor(viewMostDimColor);
			bView->FillRect(boundsRect);
			bView->SetHighColor(viewBrightGlintColor);
			bView->StrokeRect(boundsRect);
			BRect framer(boundsRect);
			framer.InsetBy(1, 1);
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeRect(framer);
			bView->SetHighColor(viewLeastDimColor);
			bView->StrokeLine(BPoint(1, 1), BPoint(1, 1));
			bView->StrokeLine(BPoint(framer.right, 1), BPoint(framer.right, 1));
			bView->StrokeLine(BPoint(1, framer.bottom), BPoint(1, framer.bottom));
			bView->StrokeLine(BPoint(framer.right, framer.bottom), BPoint(framer.right, framer.bottom));
			bView->StrokeLine(BPoint(2, 2), BPoint(2, framer.bottom - 1));
			bView->StrokeLine(BPoint(2, 2), BPoint(framer.right - 1, 2));
			bView->SetHighColor(viewDarkShadowColor);
			bView->StrokeLine(BPoint(3, 3), BPoint(framer.right - 2, 3));
			bView->SetHighColor(viewLightShadowColor);
			bView->StrokeLine(BPoint(5, 4), BPoint(framer.right - 3, 4));
			bView->SetHighColor(viewDarkShadowColor);
			bView->StrokeLine(BPoint(3, 4), BPoint(3, framer.bottom - 2));
			bView->SetHighColor(viewLightShadowColor);
			bView->StrokeLine(BPoint(4, 5), BPoint(4, framer.bottom - 3));
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeLine(BPoint(framer.right - 1, 3), BPoint(framer.right - 1, framer.bottom - 2));
			bView->StrokeLine(BPoint(3, framer.bottom - 1), BPoint(framer.right - 1, framer.bottom - 1));
			bView->SetHighColor(highColor);
			bView->MovePenTo(textLeftEdge, textBaseline);
			bView->DrawString(paramLabel);
		}
		pOnPicture = bView->EndPicture();
		
		rgb_color rgbRed;
		rgbRed.red = 255;
		rgbRed.green = 0;
		rgbRed.blue = 0;
		
		bView->BeginPicture(new BPicture);
		{
			bView->SetHighColor(viewColor);
			bView->FillRect(boundsRect);
			bView->SetHighColor(viewLeastDimColor);
			bView->StrokeRect(boundsRect);
			BRect framer(boundsRect);
			framer.InsetBy(1, 1);
			bView->SetHighColor(viewMostDimColor);
			bView->StrokeRect(framer);
			bView->SetHighColor(viewLeastDimColor);
			bView->StrokeLine(BPoint(1, 1), BPoint(1, 1));
			bView->StrokeLine(BPoint(framer.right, 1), BPoint(framer.right, 1));
			bView->StrokeLine(BPoint(1, framer.bottom), BPoint(1, framer.bottom));
			bView->StrokeLine(BPoint(framer.right, framer.bottom), BPoint(framer.right, framer.bottom));
			bView->StrokeLine(BPoint(2, 2), BPoint(2, framer.bottom - 1));
			bView->StrokeLine(BPoint(2, 2), BPoint(framer.right - 1, 2));
			bView->SetHighColor(viewBrightGlintColor);
			bView->StrokeLine(BPoint(3, 3), BPoint(framer.right - 2, 3));
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeLine(BPoint(5, 4), BPoint(framer.right - 3, 4));
			bView->SetHighColor(viewBrightGlintColor);
			bView->StrokeLine(BPoint(3, 4), BPoint(3, framer.bottom - 2));
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeLine(BPoint(4, 5), BPoint(4, framer.bottom - 3));
			bView->SetHighColor(viewDarkShadowColor);
			bView->StrokeLine(BPoint(framer.right - 1, 3), BPoint(framer.right - 1, framer.bottom - 2));
			bView->StrokeLine(BPoint(3, framer.bottom - 1), BPoint(framer.right - 1, framer.bottom - 1));
			bView->SetHighColor(viewLightShadowColor);
			bView->StrokeLine(BPoint(framer.right - 2, 4), BPoint(framer.right - 2, framer.bottom - 3));
			bView->StrokeLine(BPoint(4, framer.bottom - 2), BPoint(framer.right - 2, framer.bottom - 2));
			bView->SetHighColor(highColor);
			bView->MovePenTo(textLeftEdge, textBaseline);
			bView->DrawString(paramLabel);
			bView->SetPenSize(2);
			framer.InsetBy(3, 3);
			bView->SetHighColor(rgbRed);
			bView->StrokeEllipse(framer);
			framer.InsetBy(framer.Width() * .75, framer.Height() * .75);
			bView->StrokeLine(BPoint(framer.right, framer.top), BPoint(framer.left, framer.bottom));
		}
		pOffDisabledPicture = bView->EndPicture();
		
		bView->BeginPicture(new BPicture);
		{
			bView->SetHighColor(viewMostDimColor);
			bView->FillRect(boundsRect);
			bView->SetHighColor(viewBrightGlintColor);
			bView->StrokeRect(boundsRect);
			BRect framer(boundsRect);
			framer.InsetBy(1, 1);
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeRect(framer);
			bView->SetHighColor(viewLeastDimColor);
			bView->StrokeLine(BPoint(1, 1), BPoint(1, 1));
			bView->StrokeLine(BPoint(framer.right, 1), BPoint(framer.right, 1));
			bView->StrokeLine(BPoint(1, framer.bottom), BPoint(1, framer.bottom));
			bView->StrokeLine(BPoint(framer.right, framer.bottom), BPoint(framer.right, framer.bottom));
			bView->StrokeLine(BPoint(2, 2), BPoint(2, framer.bottom - 1));
			bView->StrokeLine(BPoint(2, 2), BPoint(framer.right - 1, 2));
			bView->SetHighColor(viewDarkShadowColor);
			bView->StrokeLine(BPoint(3, 3), BPoint(framer.right - 2, 3));
			bView->SetHighColor(viewLightShadowColor);
			bView->StrokeLine(BPoint(5, 4), BPoint(framer.right - 3, 4));
			bView->SetHighColor(viewDarkShadowColor);
			bView->StrokeLine(BPoint(3, 4), BPoint(3, framer.bottom - 2));
			bView->SetHighColor(viewLightShadowColor);
			bView->StrokeLine(BPoint(4, 5), BPoint(4, framer.bottom - 3));
			bView->SetHighColor(viewDimGlintColor);
			bView->StrokeLine(BPoint(framer.right - 1, 3), BPoint(framer.right - 1, framer.bottom - 2));
			bView->StrokeLine(BPoint(3, framer.bottom - 1), BPoint(framer.right - 1, framer.bottom - 1));
			bView->SetHighColor(highColor);
			bView->MovePenTo(textLeftEdge, textBaseline);
			bView->DrawString(paramLabel);
			bView->SetPenSize(2);
			framer.InsetBy(3, 3);
			bView->SetHighColor(rgbRed);
			bView->StrokeEllipse(framer);
			framer.InsetBy(framer.Width() * .75, framer.Height() * .75);
			bView->StrokeLine(BPoint(framer.right, framer.top), BPoint(framer.left, framer.bottom));
		}
		pOnDisabledPicture = bView->EndPicture();
		//bView.RemoveSelf();
		bWindow->Run();
		bWindow->PostMessage(B_QUIT_REQUESTED);
		mpBPictureButton = new MyPictureButton(	boundsRect,
												paramName, 
												pOffPicture,
												pOnPicture,
												pOffDisabledPicture,
												pOnDisabledPicture,
												paramMsg,
												paramBehavior,
												paramLayoutMatrix,
												paramSetEnabled,
												paramOnOff);
	}
	catch(...)
	{
		warning(myPrefs->FailMemory);
		throw;
	}
}//end