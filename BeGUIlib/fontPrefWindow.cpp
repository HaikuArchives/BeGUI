//fontPrefWindow.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DmenuMsg.h"
#include "DcarriageReturn.h"
#include "DnumSpecificWindows.h"
#include "DtinySnooze.h"
#include "s2f.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "myButton.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "myCheckBox.h"
#include "scrollingWindow.h"
#include "prefPanelWindow.h"
#include "fontPrefWindow.h"
#include "fontDisplayWindow.h"
#include "warning.h"
#include "Preferences.h"
#include "myroColour.h"
#include "verify.h"
#include "gadgetBase.h"
#include "floatGadget.h"
#include "myPopUpMenu.h"
#include "myPopUpMenuData.h"
#include "myCheckBox.h"
#include "myPreferences.h"
#include "smallerRect.h"

//ctor
FontPrefWindow	::	FontPrefWindow(	BRect	paramBound,
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
				mbsFullLine(myPrefs->AlphaNumeric),
				mpSizeFloatGadget(NULL),
				mpFontDisplayWindow(NULL),
				mpFontFamilyPUM(NULL),
				mpFontStylePUM(NULL),
				mpDisplayFontCheckBox(NULL),
				mpAntiAliasFontCheckBox(NULL)
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
		LayoutMatrix *	pholdFontPrefWindowLayoutMatrix = new LayoutMatrix(BESTSIZE, 7, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		BFont * pHBFont = new BFont(myPrefs->GetPreferredFont());
		float fontSize = pHBFont->Size();
		fontSize *= 3;
		if (fontSize > 200)
		{
			fontSize = 200;
		}
		pHBFont->SetSize(fontSize);
		pHBFont->SetShear(122);
		MyStringDrawer * pMyStringDrawer = new MyStringDrawer(	"fontPrefMyStringDrawer", 
																myPrefs->FontPrefWindowHeading1,
																pholdFontPrefWindowLayoutMatrix, 
																pHBFont);
////////////////////////////////////////////////////////////////////////////////
		MyButton * pholdBiggerFontMyButton = new MyButton(	"BiggerFontButton", 
															myPrefs->BiggerFontButtonLabel, 
															BIGGER_FONT,
															pholdFontPrefWindowLayoutMatrix);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		MyButton * pholdSmallerFontMyButton = new MyButton(	"SmallerFontButton", 
															myPrefs->SmallerFontButtonLabel, 
															SMALLER_FONT,
															pholdFontPrefWindowLayoutMatrix);
//////////////////////////////////////////////////////////////////
		mpSizeFloatGadget = new FloatGadget(	myPrefs->GetPreferredFont()->Size(),
												"FontSizeFloatControl", 
												myPrefs->EnterFontSizeLabel,
												0,
												this,
												pholdFontPrefWindowLayoutMatrix);
//////////////////////////////////////////////////////////////////
		mpDisplayFontCheckBox = new MyCheckBox(	"displayFont", 
												myPrefs->DisplayFontCheckBoxLabel,
												myPrefs->mbOpenFontDisplay,
												DISPLAY_FONT,
												pholdFontPrefWindowLayoutMatrix);
/////////////////////////////////////////////
	BFont * currentFont = myPrefs->GetPreferredFont();
	currentFont->GetFamilyAndStyle(&mffFamilyName, &mfsStyleName);
	BList * PUMFontFamilyList = new BList();
	int32 numFamilies = count_font_families();
	for (	int i = 0; 
			i < numFamilies;
			i++ ) 
	{ 
		font_family family; 
   		uint32 flags; 
   		if ( get_font_family(i, &family, &flags) == B_OK ) 
   		{
			PopUpMenuData  * PUMFontFamilyData = new PopUpMenuData(family, PUMFontFamilyList);
   		} 
	}
	mpFontFamilyPUM = new MyPopUpMenu(	"fontFamilyPUM", 
										mffFamilyName,
										PUMFontFamilyList, 
										true,
										myPrefs->FontFamilyPUMLabel,
										pholdFontPrefWindowLayoutMatrix);
	if (!mpFontFamilyPUM->Initialize()) 
	{
		warning(myPrefs->FailPUMInitFontWindow);
	}
///////////////////////////////////////////////////////////////////////////
	BList * PUMFontStyleList = new BList();
	int32 numStyles = count_font_styles(mffFamilyName);
	for (	int32 j = 0;
			j < numStyles;
			j++ ) 
	{ 
	    font_style style;
   		uint32 flags; 
	    if ( get_font_style(mffFamilyName, j, &style, &flags) == B_OK ) 
	    { 
	    	PopUpMenuData * PUMDataFontStyle = new PopUpMenuData(style, PUMFontStyleList);
	    } 
	}
	mpFontStylePUM = new MyPopUpMenu(	"fontStylePUM", 
										mfsStyleName,
										PUMFontStyleList, 
										true,
										myPrefs->FontStylePUMLabel,
										pholdFontPrefWindowLayoutMatrix);
	if (!mpFontStylePUM->Initialize()) 
	{
		warning(myPrefs->FailPUMInitFontWindow);
	}
////////////////////////////////////////////////////
		LayoutMatrix *	pAntiAliasCBLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////
		mpAntiAliasFontCheckBox = new MyCheckBox(	"antialiasFont", 
													myPrefs->AntiAliasFont,
													myPrefs->mbAntiAliasFont,
													ANTIALIAS_FONT,
													pAntiAliasCBLayoutMatrix);
///////////////////////////////////////////////
		release_sem(calc_sem);
		pholdFontPrefWindowLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, MATRIXVERTICALOFFSET, calc_sem);
		pAntiAliasCBLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pholdFontPrefWindowLayoutMatrix->mfBottom, calc_sem);
	}
	catch (...)
	{
		warning(myPrefs->CaughtFontPrefWindowCTOR);
		release_sem(calc_sem);
		throw;
	}
	try 
	{
		BMenuItem *	menuItem;
		BMenu * APPMenu = new BMenu(myPrefs->AppMenuLabel);
		menuItem = new BMenuItem(	myPrefs->AboutMenuLabel, 
									new BMessage(ABOUT_FONTPREFWINDOW));
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
	if (myPrefs->mbOpenFontDisplay) 
	{
		OpenFontDisplayWindow();
	}
}//end


//dtor
FontPrefWindow	::	~FontPrefWindow() 
{
	if (mpFontDisplayWindow)
	{
		mpFontDisplayWindow->PostMessage(B_QUIT_REQUESTED);
		while (mpFontDisplayWindow)
		{
			snooze(TINYSNOOZE);
		}
	}
	if (myPrefs->pPrefPanelWindow)//can get a race if not checked
	{
		myPrefs->pPrefPanelWindow->mpFontPrefWindow = NULL;
	}
	if (myPrefs->mbPrefChangesMade)
	{
		if (myPrefs->pPrefPanelWindow)
		{
			myPrefs->pPrefPanelWindow->PostMessage(B_QUIT_REQUESTED);
			while (myPrefs->pPrefPanelWindow)
			{
				snooze(TINYSNOOZE);
			}
		}
	}
}//end


void
FontPrefWindow	::	MessageReceived(	BMessage * paramMessage) 
{
	switch(paramMessage->what) 
	{
		case BIGGER_FONT:
		case SMALLER_FONT:
		{
	       	float oldSize = (myPrefs->GetPreferredFont())->Size();
			if (paramMessage->what == BIGGER_FONT) 
			{
				oldSize++;
			}
			else
			{
				oldSize--;
			}
			ResetFontSize(oldSize);
		}
		break;
		case CARRIAGE_RETURN:
		{
			float size;
			if (s2f(mpSizeFloatGadget->Text(), &size) == B_OK)
			{
				ResetFontSize(size);
			}
		}
		break;
		case DISPLAY_FONT:
			myPrefs->mbOpenFontDisplay = mpDisplayFontCheckBox->Value();
			if (myPrefs->mbOpenFontDisplay)
			{
				if (!mpFontDisplayWindow)
				{
					OpenFontDisplayWindow();
				}
				else
				{
					mpFontDisplayWindow->Activate();
				}
			}
			else
			{
				if (mpFontDisplayWindow)
				{
					mpFontDisplayWindow->PostMessage(B_QUIT_REQUESTED);
					while (mpFontDisplayWindow)
					{
						snooze(TINYSNOOZE);
					}
				}
			}
		break;
		case ANTIALIAS_FONT:
			if (mpAntiAliasFontCheckBox->Value())
			{
				myPrefs->mbAntiAliasFont = false;
			}
			else
			{
				myPrefs->mbAntiAliasFont = true;
			}
			myPrefs->GetPreferredFont()->SetFlags(myPrefs->mbAntiAliasFont);
			if (myPrefs->mbOpenFontDisplay)
			{
				OpenFontDisplayWindow();
			}
		break;
		case ABOUT_FONTPREFWINDOW:	
		{
			BString warn = myPrefs->AboutFontPrefWindowMsg1;
			warn += myPrefs->AboutFontPrefWindowMsg2;
			warn += myPrefs->AboutFontPrefWindowMsg3;
			warn += myPrefs->AboutFontPrefWindowMsg4;
			warn += myPrefs->AboutFontPrefWindowMsg5;
			warn += myPrefs->AboutFontPrefWindowMsg6;
			warning(warn.String());
		}
		break;
		case QUIT_APP:
			if (Verify(myPrefs->ReallyQuitApp))
			{
				be_app->PostMessage(B_QUIT_REQUESTED);
			}
		break;
		case BEGUIPUM:
		{
			BFont * currentFont = myPrefs->GetPreferredFont();
			const char * msgString;
			if (paramMessage->FindString("menuName", &msgString) == B_OK) 
			{
				if (!strcmp(msgString, "fontFamilyPUM"))
				{
					if (paramMessage->FindString("itemName", &msgString) == B_OK)
					{
						if (strcmp(mffFamilyName, msgString))
						{
							font_family oldFamily;
							font_style oldStyle;
							currentFont->GetFamilyAndStyle(&oldFamily, &oldStyle);
							currentFont->SetFamilyAndStyle(msgString, NULL);
							font_family newFamily;
							font_style newStyle;
							currentFont->GetFamilyAndStyle(&newFamily, &newStyle);
							myPrefs->mbPrefChangesMade = true;
							BPopUpMenu * bpum = (BPopUpMenu *)mpFontStylePUM->ItemAt(0)->Submenu();
							int32 numItems = bpum->CountItems();
							for (	int32 j = (numItems - 1);
									j > -1;
									j--) 
							{
								BMenuItem * item = bpum->RemoveItem(j);
								delete item;
							}
							int32 numStyles = count_font_styles(newFamily);
							bool reStyle = true;
							font_style styleOne;
							for (	int32 j = 0;
									j < numStyles;
									j++ ) 
							{
								font_style style;
						   		uint32 flags; 
							    if ( get_font_style(newFamily, j, &style, &flags) == B_OK ) 
							    { 
							    	try
							    	{
								    	BMessage * msg = new BMessage(BEGUIPUM);
										msg->AddString("menuName", "fontStylePUM");
										msg->AddString("itemName", style);
										if (j == 0)
										{
											strcpy(styleOne, style);
										}
										if (!strcmp(style, oldStyle))
										{
											reStyle = false;
										}
								    	BMenuItem * item = new BMenuItem(style, msg);
								    	if (!bpum->AddItem(item))
								    	{
								    		warning(myPrefs->NoAdditem);
								    		throw;
								    	}
							    	}
							    	catch (...)
							    	{
							    		warning(myPrefs->failMenu);
							    		throw;
							    	}
							    } 
							}
							if (reStyle)
							{
								strcpy(mfsStyleName, styleOne);
								BPopUpMenu * bpum = (BPopUpMenu *)mpFontStylePUM->ItemAt(0)->Submenu();
								BMenuItem * bmi = bpum->ItemAt(0);
								bmi->SetMarked(true);
								currentFont->SetFamilyAndStyle(NULL, mfsStyleName);
							}
							strcpy(mffFamilyName, newFamily);
						}
					}
				}
				else if (!strcmp(msgString, "fontStylePUM"))
				{
					if (paramMessage->FindString("itemName", &msgString) == B_OK)
					{
						if (strcmp(mfsStyleName, msgString))
						{
							currentFont->SetFamilyAndStyle(NULL, msgString);
							currentFont->GetFamilyAndStyle(&mffFamilyName, &mfsStyleName);
							myPrefs->mbPrefChangesMade = true;
						}
					}
				}
			}
		}
		break;
		default:
			ScrollingWindow::MessageReceived(paramMessage);
		break;
	}
	switch(paramMessage->what) 
	{
		case BIGGER_FONT:
		case SMALLER_FONT:
		case CARRIAGE_RETURN:
		case BEGUIPUM:
			if (mpDisplayFontCheckBox->Value())
			{
				OpenFontDisplayWindow();
			}
		break;
	}
}//end


bool
FontPrefWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	myPrefs->SetPreferredFontPrefWindowRect(frame);
	float fontSize;
	if (s2f(mpSizeFloatGadget->Text(), &fontSize) == B_OK)
	{
		if (fontSize != myPrefs->GetPreferredFont()->Size())
		{
			myPrefs->mbPrefChangesMade = true;
			if (fontSize < 1)
			{
				warning(myPrefs->FailMinFontSize);
			}
			else if (fontSize > 51000)
			{
				warning(myPrefs->FailMaxFontSize);
			}
			else
			{
				myPrefs->GetPreferredFont()->SetSize(fontSize);
			}
		}
	}
	return(ScrollingWindow::QuitRequested());
}//end


void
FontPrefWindow	::	OpenFontDisplayWindow(	void)
{
	if (mpFontDisplayWindow) 
	{
		int timeOut = 0;
		while (mpFontDisplayWindow && (timeOut < 100)) 
		{
			if (mpFontDisplayWindow->PostMessage(B_QUIT_REQUESTED))
			{
				mpFontDisplayWindow = NULL;
			}
			else
			{
				snooze(TINYSNOOZE);
				timeOut++;
			}
		}
	}
	if (!mpFontDisplayWindow) 
	{
		try 
		{
			BRect holdRect;
			myPrefs->GetPreferredFontDisplayWindowRect(&holdRect);
			mpFontDisplayWindow = new FontDisplayWindow(	holdRect,
															"FontDisplayWindow",
															myPrefs->FontDisplayWindowTitle,
															"FontDisplayWindowFrame",
															mbsFullLine.String());
			mpFontDisplayWindow->Initialize();
			BRect tpr = mpFontDisplayWindow->Bounds();
			if (RectASmallerRectB(holdRect, tpr)) 
			{
				mpFontDisplayWindow->ResizeTo(holdRect.Width(), holdRect.Height());
			}
			mpFontDisplayWindow->Show();
		}
		catch (...) 
		{
			warning(myPrefs->FailFontDisplayWindow);
			throw;
		}
	}
	else
	{
		warning(myPrefs->FontDisplayNotNull);
		be_app->PostMessage(B_QUIT_REQUESTED);
	}
}//end


void
FontPrefWindow	::	ResetFontSize(	float newSize)
{
	myPrefs->mbPrefChangesMade = true;
	char fontSizeStr[DIGITSnFLOAT];
	if (newSize < 1)
	{
		warning(myPrefs->FailMinFontSize);
		sprintf(fontSizeStr, "%f", myPrefs->GetPreferredFont()->Size());
		mpSizeFloatGadget->SetText(fontSizeStr);
	}
	else if (newSize > 51000)
	{
		warning(myPrefs->FailMaxFontSize);
		sprintf(fontSizeStr, "%f", myPrefs->GetPreferredFont()->Size());
		mpSizeFloatGadget->SetText(fontSizeStr);
	}
	else
	{
		myPrefs->GetPreferredFont()->SetSize(newSize);
		sprintf(fontSizeStr, "%f", myPrefs->GetPreferredFont()->Size());
		mpSizeFloatGadget->SetText(fontSizeStr);
	}
	if (myPrefs->mbOpenFontDisplay) 
	{
		if (mpFontDisplayWindow)
		{
			if (mpFontDisplayWindow->LockLooper())
			{
				if (mpFontDisplayWindow->IsHidden())
				{
					do
					{
						mpFontDisplayWindow->Show();
					} while (mpFontDisplayWindow->IsHidden());
				}
				mpFontDisplayWindow->UnlockLooper();
			}
			else
			{
				warning(myPrefs->FailLockLooper);
			}
		}
		else
		{
			OpenFontDisplayWindow();
		}
	}
	else
	{
		if (mpFontDisplayWindow)
		{
			mpFontDisplayWindow->PostMessage(B_QUIT_REQUESTED);
			while (mpFontDisplayWindow)
			{
				snooze(TINYSNOOZE);
			}
		}
	}
}//end