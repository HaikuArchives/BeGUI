//basicColorWindow.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DmenuMsg.h"
#include "DnumSpecificWindows.h"
#include "DcolorControlMessages.h"
#include "scrollingWindow.h"
#include "s2f.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "Preferences.h"
#include "myCheckBox.h"
#include "myColorControl.h"
#include "colorWell.h"
#include "prefPanelWindow.h"
#include "basicColorWindow.h"
#include "warning.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "verify.h"
#include "colorWell.h"
#include "myColorControl.h"
	

//ctor
BasicColorWindow	::	BasicColorWindow(	BRect	paramBound,
									const char * paramWindowTitle,
									const char * paramScrollViewName,
									const char * paramNamePrefFrame)
				: 
				ScrollingWindow(	paramBound, 
									paramWindowTitle, 
									paramScrollViewName,
									paramNamePrefFrame,
									myPrefs->mpPreferenceSet,
									true,
									false),
				mpViewColorControl(NULL),
				mpHighColorControl(NULL),
				mpLowColorControl(NULL),
				mpViewColorWell(NULL),
				mpHighColorWell(NULL),
				mpLowColorWell(NULL)
{
	sem_id calc_sem;
	if ((calc_sem = create_sem(1, "calc_sem")) < B_NO_ERROR)
	{
		warning(myPrefs->FailCreateSemaphore);
		return;
	}
	acquire_sem(calc_sem);
	try 
	{
		LayoutMatrix * pholdTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		BFont * pBFont = new BFont(myPrefs->GetPreferredFont());
		float fontSize = pBFont->Size();
		fontSize *= 2;
		if (fontSize > 200)
		{
			fontSize = 200;
		}
		pBFont->SetSize(fontSize);
		pBFont->SetShear(122);
		//will need offset for demo--use a seperate matrix and get it's bottom
		MyStringDrawer * pMyStringDrawer = new MyStringDrawer(	"basicColorHeading", 
																myPrefs->BasicColorWindowHeading1,
																pholdTitleLayoutMatrix,
																pBFont);
/////////////////////////////
		if (!myPrefs->mbUseColorControl && !myPrefs->mbUseColorWell)
		{
			warning(myPrefs->noCCenabled);
		}
		LayoutMatrix * pholdViewCCLayoutMatrix = NULL;
		LayoutMatrix * pholdHighCCLayoutMatrix = NULL;
		LayoutMatrix * pholdLowCCLayoutMatrix = NULL;
		MyStringDrawer * pMyStringDrawerAXX = NULL;
		MyStringDrawer * pMyStringDrawerBXX = NULL;
		MyStringDrawer * pMyStringDrawerCXX = NULL;
		rgb_color color;//re-use for every setvalue
		if (myPrefs->mbUseColorControl)
		{
			pholdViewCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	/////////////////////////////////////////////////////////////////////////////////////
			pMyStringDrawerAXX = new MyStringDrawer(	"MyStringDrawerAXX", 
														myPrefs->ColorWindowHeading2,
														pholdViewCCLayoutMatrix);
	////////////////////////////////////////////////////////////////////
			mpViewColorControl = new MyColorControl(	myPrefs->mCCL,
														"ColorControlAXX", 
														COLORCONTROL_VIEW,
														pholdViewCCLayoutMatrix);
			myPrefs->GetPreferredViewColor(&color);
			mpViewColorControl->SetValue(color);
	/////////////////////
			pholdHighCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	////////////////////////////////
			pMyStringDrawerBXX = new MyStringDrawer(	"MyStringDrawerBXX", 
														myPrefs->ColorWindowHeading3,
														pholdHighCCLayoutMatrix);
	/////////////////////////////////////////////
			mpHighColorControl = new MyColorControl(	myPrefs->mCCL,
														"HighColorControlBXX", 
														COLORCONTROL_HIGH, 
														pholdHighCCLayoutMatrix);
			myPrefs->GetPreferredHighColor(&color);
			mpHighColorControl->SetValue(color);
	//////////////////////////////////////////////////////////////
			pholdLowCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	///////////////////////////////////////////////////
			pMyStringDrawerCXX = new MyStringDrawer(	"MyStringDrawerCXX", 
														myPrefs->ColorWindowHeading4,
														pholdLowCCLayoutMatrix);
	///////////////////////////////////////////////////////////////////
			mpLowColorControl = new MyColorControl(	myPrefs->mCCL,
													"LowColorControlCXX", 
													COLORCONTROL_LOW, 
													pholdLowCCLayoutMatrix);
			myPrefs->GetPreferredLowColor(&color);
			mpLowColorControl->SetValue(color);
		}
////////////////////////
		LayoutMatrix * pholdColorWellLayoutMatrix = NULL;
		if (myPrefs->mbUseColorWell)
		{
			pholdColorWellLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 3, this);//rows,columns
	//////////////
			mpViewColorWell = new ColorWell(	"ColorWellViewColorPref",
												VIEW_COLOR,
												myPrefs->ColorWindowHeading5,
												this,
												pholdColorWellLayoutMatrix);
	//////////////////////////////////////////////////////////
	
			mpHighColorWell = new ColorWell(	"ColorWellHighColorPref", 
												HIGH_COLOR,
												myPrefs->ColorWindowHeading6,
												this,
												pholdColorWellLayoutMatrix);
	//////////////////////////////////////////////////////////////
			mpLowColorWell = new ColorWell(	"ColorWellLowColorPref", 
											LOW_COLOR,
											myPrefs->ColorWindowHeading7,
											this,
											pholdColorWellLayoutMatrix);
		}
//////////////
		release_sem(calc_sem);
		pholdTitleLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, MATRIXVERTICALOFFSET, calc_sem);
		float bottom = pholdTitleLayoutMatrix->mfBottom;
		if (myPrefs->mbUseColorControl)
		{
			pholdViewCCLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, bottom, calc_sem);
			pholdHighCCLayoutMatrix->Calc(pholdViewCCLayoutMatrix->mfRight, bottom, calc_sem);
			pholdLowCCLayoutMatrix->Calc(pholdHighCCLayoutMatrix->mfRight, bottom, calc_sem);
			bottom = pholdLowCCLayoutMatrix->mfBottom;
			if (bottom < pholdHighCCLayoutMatrix->mfBottom)
			{
				bottom = pholdHighCCLayoutMatrix->mfBottom;
			}
			if (bottom < pholdViewCCLayoutMatrix->mfBottom)
			{
				bottom = pholdViewCCLayoutMatrix->mfBottom;
			}
		}
		if (myPrefs->mbUseColorWell)
		{
			pholdColorWellLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, bottom, calc_sem);
		}
	}
	catch (...)
	{
		warning(myPrefs->CaughtBasicColorWindowCTOR);
		release_sem(calc_sem);
		throw;
	}
	try 
	{
		BMenuItem *	menuItem;
		BMenu *		APPMenu = new BMenu(myPrefs->AppMenuLabel);
		menuItem = new BMenuItem(	myPrefs->AboutMenuLabel, 
									new BMessage(ABOUT_BASICCOLORWINDOW));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->CloseWindow, 
									new BMessage(B_QUIT_REQUESTED));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->QuitMenuLabel, 
									new BMessage(QUIT_APP));
		APPMenu->AddItem(menuItem);
		mpMenuBar->AddItem(APPMenu);
	}
	catch(...) 
	{
		throw;
	}
}//end


//dtor
BasicColorWindow	::	~BasicColorWindow() 
{
	if (myPrefs->pPrefPanelWindow)//can get a race if not checked
	{
		myPrefs->pPrefPanelWindow->mpPrefWindows[PP_BASIC] = NULL;
	}
}//end


bool
BasicColorWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	myPrefs->SetPreferredBasicColorWindowRect(frame);
	if (mpViewColorControl)//if you got one you got 'em all
	{
		rgb_color color(mpViewColorControl->ValueAsColor());
		myPrefs->SetPreferredViewColor(&color);
		color = mpHighColorControl->ValueAsColor();
		myPrefs->SetPreferredHighColor(&color);
		color = mpLowColorControl->ValueAsColor();
		myPrefs->SetPreferredLowColor(&color);
	}
	return(ScrollingWindow::QuitRequested());
}//end


void
BasicColorWindow	::	ResetDemo(	void)
{
	myPrefs->mbPrefChangesMade = true;
}//end


void
BasicColorWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	switch(paramMessage->what) 
	{
		case ABOUT_BASICCOLORWINDOW:
		{
			BString warn = myPrefs->AboutBasicColorWindowMsg1;
			warn += myPrefs->AboutBasicColorWindowMsg2;
			warning(warn.String());
		break;
		}
		case QUIT_APP:
			if (Verify(myPrefs->ReallyQuitApp))
			{
				be_app->PostMessage(B_QUIT_REQUESTED);
			}
		break;
		case COLORCONTROL_VIEW:
		case COLORCONTROL_HIGH:
		case COLORCONTROL_LOW:
			ResetDemo();
		break;
		case roColourDROPPEDMESSAGE: 
		{
    		rgb_color * pRGBColor;
    		rgb_color color;  		
    		int32 numRGBBytes = sizeof(struct rgb_color);
	        if (	paramMessage->FindData(	"RGBColor",
		       									B_RGB_COLOR_TYPE, 
												(const void**)&pRGBColor, 
												&numRGBBytes ) 
					== B_OK)
	        {
	           	color = *pRGBColor;
	            if (paramMessage->WasDropped()) 
	            {
					int32 colorToChange;
					if (	paramMessage->FindInt32(	"ColorToChange",
														&colorToChange)
							 == B_OK)
					{
						switch(colorToChange)
						{
							case VIEW_COLOR:
								myPrefs->SetPreferredViewColor(&color);
								mpViewColorControl->SetValue(color);
							break;
							case HIGH_COLOR:
								myPrefs->SetPreferredHighColor(&color);
								mpHighColorControl->SetValue(color);
							break;
							case LOW_COLOR:
								myPrefs->SetPreferredLowColor(&color);
								mpLowColorControl->SetValue(color);
							break;
							case NO_COLOR:
								warning(myPrefs->DemoRoNo);
							break;
							default:
								warning(myPrefs->RoBadMsg);
								throw;
							break;
						}
						ResetDemo();
					}
				}
			}
		break;
		}
		default:
			ScrollingWindow::MessageReceived(paramMessage);
		break;
	}
}//end
