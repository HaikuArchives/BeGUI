//prefPanelWindow.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DmenuMsg.h"
#include "DtinySnooze.h"
#include "DcolorControlMessages.h"
#include "DnumSpecificWindows.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "myButton.h"
#include "mySpacer.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "scrollingWindow.h"
#include "fontPrefWindow.h"
#include "gadgetBase.h"
#include "floatGadget.h"
#include "specificColorWindow.h"
#include "basicColorWindow.h"
#include "prefPanelWindow.h"
#include "warning.h"
#include "Preferences.h"
#include "myroColour.h"
#include "verify.h"
#include "myCheckBox.h"
#include "myPreferences.h"
#include "smallerRect.h"

#define PREFPANEL_COLOR_BASIC 'Pcb '
#define PREFPANEL_COLOR_BUTTON 'Pcbb'
#define PREFPANEL_COLOR_RADIOVIEW 'Pcrv'
#define PREFPANEL_COLOR_STRINGDRAWER 'Pcsp'
#define PREFPANEL_COLOR_CHECKBOX 'Pccb'
#define PREFPANEL_COLOR_PICTURE 'Pcp '
#define PREFPANEL_COLOR_COLORCONTROL 'Pccc'
#define PREFPANEL_COLOR_STATUSBAR 'Pcsb'
#define PREFPANEL_COLOR_UINT32CONTROL 'Pcig'
#define PREFPANEL_COLOR_STRINGCONTROL 'Pcsg'
#define PREFPANEL_COLOR_COLORWELL 'Pccw'
#define PREFPANEL_COLOR_TEXTVIEW 'Pctv'
#define PREFPANEL_COLOR_LISTVIEW 'Pclv'
#define PREFPANEL_FONTS 'Pfnt'
#define PREFPANEL_COLOR_FLOATCONTROL 'Pcfg'
#define PREFPANEL_COLOR_INT8GADGET 'g  8'
#define PREFPANEL_COLOR_UINT8GADGET 'gU 8'
#define PREFPANEL_COLOR_INT16GADGET 'g 16'
#define PREFPANEL_COLOR_UINT16GADGET 'gU16'
#define PREFPANEL_COLOR_INT32GADGET 'g 32'
#define PREFPANEL_COLOR_UINT32GADGET 'gU32'
#define PREFPANEL_COLOR_INT64GADGET 'g 64'
#define PREFPANEL_COLOR_UINT64GADGET 'gU64'
#define PREFPANEL_COLOR_FLOATGADGET 'gFlt'
#define PREFPANEL_COLOR_STRINGGADGET 'gStr'
#define PREFPANEL_COLOR_SLIDER 'Psli'

uint32 buttonMessages[NUMPREFPANELS] =
	{
		PREFPANEL_COLOR_BASIC,
		PREFPANEL_COLOR_BUTTON,
		PREFPANEL_COLOR_PICTURE,
		PREFPANEL_COLOR_RADIOVIEW,
		PREFPANEL_COLOR_CHECKBOX,
		PREFPANEL_COLOR_STATUSBAR,
		PREFPANEL_COLOR_COLORCONTROL,
		PREFPANEL_COLOR_COLORWELL,
		PREFPANEL_COLOR_INT8GADGET,
		PREFPANEL_COLOR_UINT8GADGET,
		PREFPANEL_COLOR_INT16GADGET,
		PREFPANEL_COLOR_UINT16GADGET,
		PREFPANEL_COLOR_INT32GADGET,
		PREFPANEL_COLOR_UINT32GADGET,
		PREFPANEL_COLOR_INT64GADGET,
		PREFPANEL_COLOR_UINT64GADGET,
		PREFPANEL_COLOR_FLOATGADGET,
		PREFPANEL_COLOR_STRINGGADGET,
		PREFPANEL_COLOR_STRINGCONTROL,
		PREFPANEL_COLOR_TEXTVIEW,
		PREFPANEL_COLOR_STRINGDRAWER,
		PREFPANEL_COLOR_LISTVIEW,
		PREFPANEL_COLOR_FLOATCONTROL,
		PREFPANEL_COLOR_UINT32CONTROL,
		PREFPANEL_COLOR_SLIDER
	};
const char * buttonNames[NUMPREFPANELS] =
	{
		"underlying",
		"button",
		"pictureButton",
		"radiobuttons",
		"checkBox",
		"statusBar",
		"colorControl",
		"roColourColorWell",
		"int8Gadget",
		"uint8Gadget",
		"int16Gadget",
		"uint16Gadget",
		"int32Gadget",
		"uint32Gadget",
		"int64Gadget",
		"uint64Gadget",
		"floatGadget",
		"stringGadget",
		"stringControl",
		"textview",
		"stringDraw",
		"listview",
		"floatControl",
		"uint32Control",
		"slider"
	};

//ctor
PrefPanelWindow	::	PrefPanelWindow(	BRect	paramBound,
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
				mpFontPrefWindow(NULL)
{
	printf("%s\n", myPrefs->mbsVersion.String());
	for (	uint32 i = 0;
			i < NUMPREFPANELS;
			i++)
	{
		mpPrefWindows[i] = NULL;
	}
	sem_id calc_sem;
	if ((calc_sem = create_sem(1, "calc_sem")) < B_NO_ERROR)
	{
		warning(myPrefs->FailCreateSemaphore);
		return;
	}
	acquire_sem(calc_sem);
	try 
	{
		LayoutMatrix *	pholdTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 3, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		BFont * pBFont = new BFont(myPrefs->GetPreferredFont());
		float fontSize = pBFont->Size();
		fontSize *= 3;
		if (fontSize > 200)
		{
			fontSize = 200;
		}
		pBFont->SetSize(fontSize);
		pBFont->SetShear(122);
		MyStringDrawer * pMyStringDrawer = new MyStringDrawer(	"prefPanelMyStringDrawer", 
																myPrefs->PrefPanelWindowHeading1,
																pholdTitleLayoutMatrix, 
																pBFont);
//////////////////////////////////////////////////
		MyButton * pholdFontMyButton = new MyButton(	"FontButton", 
														myPrefs->PrefPanelFontButtonLabel, 
														PREFPANEL_FONTS,
														pholdTitleLayoutMatrix);
////////////////////////////////////////////////
		BFont * pS2BFont = new BFont(myPrefs->GetPreferredFont());
		float fontS2Size = pS2BFont->Size();
		fontS2Size *= 2;
		if (fontS2Size > 200)
		{
			fontS2Size = 200;
		}
		pS2BFont->SetSize(fontS2Size);
		MyStringDrawer * pColorMyStringDrawer = new MyStringDrawer(	"prefPanelColorMyStringDrawer", 
																	myPrefs->PrefPanelWindowHeading2,
																	pholdTitleLayoutMatrix, 
																	pS2BFont);
//////////////////////////////////////////////////////////////////////////////////////////////
		LayoutMatrix *	pholdCheckLayoutMatrix = new LayoutMatrix(SAMESIZE, 1, 2, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		mpDisplayColorControlCheckBox = new MyCheckBox(	"displayCC", 
														myPrefs->DisplayBColorControls,
														myPrefs->mbUseColorControl,
														DISPLAY_CC,
														pholdCheckLayoutMatrix);
//////////////////////////////////////////////////////////////////////////////////////
		mpDisplayColorWellCheckBox = new MyCheckBox(	"displayCW", 
														myPrefs->DisplayroColourWells, 
														myPrefs->mbUseColorWell,
														DISPLAY_CW,
														pholdCheckLayoutMatrix);
//////////////////////////////////////////////////////////////////////////////////////////////
		LayoutMatrix *	pholdPrefPanelLayoutMatrix = new LayoutMatrix(SAMESIZE, 5, 5, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		for (	uint32 iButton = 0;
				iButton < NUMPREFPANELS;
				iButton++)
		{
			MyButton * button = new MyButton(	buttonNames[iButton], 
												myPrefs->buttonLabels[iButton], 
												buttonMessages[iButton], 
												pholdPrefPanelLayoutMatrix);
		}
///////////////////////////////////////////////////////////////////////
		release_sem(calc_sem);
		pholdTitleLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, MATRIXVERTICALOFFSET, calc_sem);
		pholdCheckLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pholdTitleLayoutMatrix->mfBottom, calc_sem);
		pholdPrefPanelLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pholdCheckLayoutMatrix->mfBottom, calc_sem);
	}
	catch (...)
	{
		warning(myPrefs->CaughtPrefPanelWindowCTOR);
		release_sem(calc_sem);
		throw;
	}
	try 
	{
		BMenuItem *	menuItem;
		BMenu * APPMenu = new BMenu(myPrefs->AppMenuLabel);
		menuItem = new BMenuItem(	myPrefs->AboutMenuLabel, 
									new BMessage(ABOUT_PREFPANELWINDOW));
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
PrefPanelWindow	::	~PrefPanelWindow() 
{
	for (	uint32 i = 0;
			i < NUMPREFPANELS;
			i++)
	{
		if (mpPrefWindows[i])
		{
			mpPrefWindows[i]->PostMessage(B_QUIT_REQUESTED);
			while (mpPrefWindows[i])
			{
				snooze(TINYSNOOZE);
			}
		}
	}
	if (mpFontPrefWindow)
	{
		mpFontPrefWindow->PostMessage(B_QUIT_REQUESTED);
		while (mpFontPrefWindow)
		{
			snooze(TINYSNOOZE);
		}
	}
	if (myPrefs->mbPrefChangesMade)
	{
		be_app->PostMessage(REOPEN);
	}
	myPrefs->pPrefPanelWindow = NULL;
}//end


void
PrefPanelWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	switch(paramMessage->what) 
	{
		case PREFPANEL_COLOR_BASIC://debug might re-enroll this case by simply adding a demo item to it
			OpenBasicColorPanel();//makes all windows equal and greatly simplifies things--see version 2 <smile>
		break;
		case PREFPANEL_FONTS:
			OpenFontPanel();
		break;
		case PREFPANEL_COLOR_BUTTON:
			OpenSpecificColorPanel(SPECIFIC_COLOR_BUTTON);
		break;
		case PREFPANEL_COLOR_RADIOVIEW:
			OpenSpecificColorPanel(SPECIFIC_COLOR_RADIOVIEW);
		break;
		case PREFPANEL_COLOR_STRINGDRAWER:
			OpenSpecificColorPanel(SPECIFIC_COLOR_STRINGDRAWER);
		break;
		case PREFPANEL_COLOR_CHECKBOX:
			OpenSpecificColorPanel(SPECIFIC_COLOR_CHECKBOX);
		break;
		case PREFPANEL_COLOR_PICTURE:
			OpenSpecificColorPanel(SPECIFIC_COLOR_PICTURE);
		break;
		case PREFPANEL_COLOR_COLORCONTROL:
			OpenSpecificColorPanel(SPECIFIC_COLOR_COLORCONTROL);
		break;
		case PREFPANEL_COLOR_STATUSBAR:
			OpenSpecificColorPanel(SPECIFIC_COLOR_STATUSBAR);
		break;
		case PREFPANEL_COLOR_SLIDER:
			OpenSpecificColorPanel(SPECIFIC_COLOR_SLIDER);
		break;
		case PREFPANEL_COLOR_UINT32CONTROL:
			OpenSpecificColorPanel(SPECIFIC_COLOR_UINT32CONTROL);
		break;
		case PREFPANEL_COLOR_FLOATCONTROL:
			OpenSpecificColorPanel(SPECIFIC_COLOR_FLOATCONTROL);
		break;
		case PREFPANEL_COLOR_STRINGCONTROL:
			OpenSpecificColorPanel(SPECIFIC_COLOR_STRINGCONTROL);
		break;
		case PREFPANEL_COLOR_COLORWELL:
			OpenSpecificColorPanel(SPECIFIC_COLOR_COLORWELL);
		break;
		case PREFPANEL_COLOR_TEXTVIEW:
			OpenSpecificColorPanel(SPECIFIC_COLOR_TEXTVIEW);
		break;
		case PREFPANEL_COLOR_LISTVIEW:
			OpenSpecificColorPanel(SPECIFIC_COLOR_LISTVIEW);
		break;
		case PREFPANEL_COLOR_INT8GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_INT8GADGET);
		break;
		case PREFPANEL_COLOR_UINT8GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_UINT8GADGET);
		break;
		case PREFPANEL_COLOR_INT16GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_INT16GADGET);
		break;
		case PREFPANEL_COLOR_UINT16GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_UINT16GADGET);
		break;
		case PREFPANEL_COLOR_INT32GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_INT32GADGET);
		break;
		case PREFPANEL_COLOR_UINT32GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_UINT32GADGET);
		break;
		case PREFPANEL_COLOR_INT64GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_INT64GADGET);
		break;
		case PREFPANEL_COLOR_UINT64GADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_UINT64GADGET);
		break;
		case PREFPANEL_COLOR_FLOATGADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_FLOATGADGET);
		break;
		case PREFPANEL_COLOR_STRINGGADGET:
			OpenSpecificColorPanel(SPECIFIC_COLOR_STRINGGADGET);
		break;
		case ABOUT_PREFPANELWINDOW:	
			warning(myPrefs->AboutPrefPanelWindow);
		break;
		case QUIT_APP:
			if (Verify(myPrefs->ReallyQuitApp))
			{
				be_app->PostMessage(B_QUIT_REQUESTED);
			}
		break;
		case DISPLAY_CC:
			myPrefs->mbUseColorControl = (bool)mpDisplayColorControlCheckBox->Value();
		break;
		case DISPLAY_CW:
			myPrefs->mbUseColorWell = (bool)mpDisplayColorWellCheckBox->Value();
		break;
		default:
			ScrollingWindow::MessageReceived(paramMessage);
		break;
	}
}//end


bool
PrefPanelWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	myPrefs->SetPreferredPrefPanelWindowRect(frame);
	myPrefs->mbUseColorWell = (bool)mpDisplayColorWellCheckBox->Value();
	myPrefs->mbUseColorControl = (bool)mpDisplayColorControlCheckBox->Value();
	return(ScrollingWindow::QuitRequested());
}//end


void
PrefPanelWindow	::	OpenFontPanel(void)
{
	if (mpFontPrefWindow)
	{
		mpFontPrefWindow->Activate(true);
	}
	else
	{
		try 
		{
			BRect holdRect;
			myPrefs->GetPreferredFontPrefWindowRect(&holdRect);
			mpFontPrefWindow = new FontPrefWindow(	holdRect,
													myPrefs->FontPrefWindowTitle,
													"fontPrefWindow",
													"FontPrefFrame");
			mpFontPrefWindow->Initialize();
			BRect tpr = mpFontPrefWindow->Bounds();
			if (RectASmallerRectB(holdRect, tpr)) 
			{
				mpFontPrefWindow->ResizeTo(holdRect.Width(), holdRect.Height());
			}
			mpFontPrefWindow->Show();
		}
		catch (...) 
		{
			warning(myPrefs->CaughtFontPrefWindowCTOR);
			throw;
		}
	}
}//end


void
PrefPanelWindow	::	OpenBasicColorPanel(void)
{
	if (mpPrefWindows[PP_BASIC])
	{
		mpPrefWindows[PP_BASIC]->Activate(true);
	}
	else
	{
		try 
		{
			BRect holdRect;
			myPrefs->GetPreferredBasicColorWindowRect(&holdRect);
			mpPrefWindows[PP_BASIC] = new BasicColorWindow(	holdRect,
															myPrefs->BasicColorWindowTitle,
															"basicColorWindow",
															"BasicColorWindowFrame");
			mpPrefWindows[PP_BASIC]->Initialize();
			BRect tpr = mpPrefWindows[PP_BASIC]->Bounds();
			if (RectASmallerRectB(holdRect, tpr)) 
			{
				mpPrefWindows[PP_BASIC]->ResizeTo(holdRect.Width(), holdRect.Height());
			}
			mpPrefWindows[PP_BASIC]->Show();
		}
		catch (...) 
		{
			warning(myPrefs->NoBasicColorWindow);
			throw;
		}
	}
}//end


void
PrefPanelWindow	::	OpenSpecificColorPanel(uint32 whichOne)
{
	if (mpPrefWindows[whichOne + 1])//whichOne references an array with button at zero
	{			//mpPrefWindows[] is an array with basic at zero and button at one
		mpPrefWindows[whichOne + 1]->Activate(true);//debug dump plus one in ver .2 <smile>
	}
	else
	{
		try 
		{
			BRect holdRect;
			switch (whichOne)
			{
				case SPECIFIC_COLOR_BUTTON:
					myPrefs->GetPreferredSpecificColorButtonWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_PICTURE:
					myPrefs->GetPreferredSpecificColorPictureButtonWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_RADIOVIEW:
					myPrefs->GetPreferredSpecificColorRadioButtonWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_CHECKBOX:
					myPrefs->GetPreferredSpecificColorCheckBoxWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_STATUSBAR:
					myPrefs->GetPreferredSpecificColorStatusBarWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_SLIDER:
					myPrefs->GetPreferredSpecificColorSliderWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_COLORCONTROL:
					myPrefs->GetPreferredSpecificColorColorControlWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_TEXTVIEW:
					myPrefs->GetPreferredSpecificColorTextViewWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_LISTVIEW:
					myPrefs->GetPreferredSpecificColorListViewWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_UINT32CONTROL:
					myPrefs->GetPreferredSpecificColorUInt32ControlWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_INT8GADGET:
					myPrefs->GetPreferredSpecificColorInt8GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_UINT8GADGET:
					myPrefs->GetPreferredSpecificColorUInt8GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_INT16GADGET:
					myPrefs->GetPreferredSpecificColorInt16GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_UINT16GADGET:
					myPrefs->GetPreferredSpecificColorUInt16GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_INT32GADGET:
					myPrefs->GetPreferredSpecificColorInt32GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_UINT32GADGET:
					myPrefs->GetPreferredSpecificColorUInt32GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_INT64GADGET:
					myPrefs->GetPreferredSpecificColorInt64GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_UINT64GADGET:
					myPrefs->GetPreferredSpecificColorUInt64GadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_FLOATGADGET:
					myPrefs->GetPreferredSpecificColorFloatGadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_STRINGGADGET:
					myPrefs->GetPreferredSpecificColorStringGadgetWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_FLOATCONTROL:
					myPrefs->GetPreferredSpecificColorFloatControlWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_STRINGCONTROL:
					myPrefs->GetPreferredSpecificColorStringControlWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_COLORWELL:
					myPrefs->GetPreferredSpecificColorColorWellWindowRect(&holdRect);
				break;
				case SPECIFIC_COLOR_STRINGDRAWER:
					myPrefs->GetPreferredSpecificColorStringDrawerWindowRect(&holdRect);
				break;
			}
			mpPrefWindows[whichOne + 1] = new SpecificColorWindow(	holdRect,
																	whichOne);
			mpPrefWindows[whichOne + 1]->Initialize();
			BRect tpr = mpPrefWindows[whichOne + 1]->Bounds();
			if (RectASmallerRectB(holdRect, tpr)) 
			{
				mpPrefWindows[whichOne + 1]->ResizeTo(holdRect.Width(), holdRect.Height());
			}
			mpPrefWindows[whichOne + 1]->Show();
		}
		catch (...) 
		{
			warning(myPrefs->NoSpecColorWindow);
			throw;
		}
	}
}//end
