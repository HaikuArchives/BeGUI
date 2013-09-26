//scrolling title window

#include "commonHeaders.h"
#include "DtinySnooze.h"
#include "DnumSpecificWindows.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "warning.h"
#include "scrollingWindow.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "gadgetBase.h"
#include "myButton.h"
#include "myCheckBox.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "myPopUpMenu.h"
#include "myPictureButton.h"
#include "myColorControl.h"
#include "myStatusBar.h"
#include "myRadioView.h"
#include "myTextView.h"
#include "mySpacer.h"
#include "DmenuMsg.h"
#include "myroColour.h"
#include "verify.h"
#include "ResEDgarWindow.h"
#include "ResEDgarTitleWindow.h"
#include "ResEDgarApp.h"

//ctor
TitleWindow	::	TitleWindow(	BRect paramBound,
								const char * paramWindowTitle,
								const char * paramScrollViewName,
								const char * paramNamePrefFrame)
			: 
				ScrollingWindow(	paramBound, 
									paramWindowTitle, 
									paramScrollViewName,
									paramNamePrefFrame,
									myApp->mpPreferenceSet),
				mpLoad(NULL),
				mpSave(NULL),
				mpLoadPanel(NULL), 
				mpLoadMessenger(NULL),
				mpResEdWin(NULL),
				mpSaveBMI(NULL),
				mpLoadBMI(NULL)
{
	sem_id calc_sem;
	if ((calc_sem = create_sem(1, "calc_sem")) < B_NO_ERROR)
	{
		warning(myApp->FailCreateSemaphore);
		return;
	}
	acquire_sem(calc_sem);
	try 
	{
		LayoutMatrix *	pTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		BFont * pTitleFont = new BFont(myPrefs->GetPreferredFont());
		float fTitleFontSize = pTitleFont->Size();
		fTitleFontSize *= 2;
		if (fTitleFontSize > 200)
		{
			fTitleFontSize = 200;
		}
		pTitleFont->SetSize(fTitleFontSize);
		pTitleFont->SetShear(122);
		MyStringDrawer * pProgramNameMSD = new MyStringDrawer(	NULL, 
																myApp->ProgramName,
																pTitleLayoutMatrix,
																pTitleFont);
//////////////////////////////////////////////
		BFont * pSubTitleFont = new BFont(myPrefs->GetPreferredFont());
		float fSubTitleFontSize = pSubTitleFont->Size();
		fSubTitleFontSize *= 1.3;
		if (fSubTitleFontSize > 200)
		{
			fSubTitleFontSize = 200;
		}
		pSubTitleFont->SetSize(fSubTitleFontSize);
		MyStringDrawer * pProgramNameSubTitleMSD = new MyStringDrawer(	NULL, 
																		myApp->ProgramNameSubTitle,
																		pTitleLayoutMatrix,
																		pSubTitleFont);
////////////////////////////////////////////////
		LayoutMatrix *	pFileLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
////////////////////////////////////////////////////////////////
		mpLoad = new MyButton(	"loadButton", 
								myApp->Load, 
								LOAD, 
								pFileLayoutMatrix);
///////////////////////////////////////////////////////////////
		mpSave = new MyButton(	"saveButton", 
								myApp->Save, 
								SAVE, 
								pFileLayoutMatrix);
		mpSave->SetEnabled(false);
//////////////////////////////////////////////////////////////
		release_sem(calc_sem);
		pTitleLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, MATRIXVERTICALOFFSET, calc_sem);
		pFileLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pTitleLayoutMatrix->mfBottom, calc_sem);
	}
	catch (...)
	{
		warning(myApp->CaughtTitleWindowCTOR);
		release_sem(calc_sem);
		throw;
	}
	try
	{
		BMenuItem *	menuItem;
		BMenu * APPMenu = new BMenu(myApp->AppMenuLabel);
		menuItem = new BMenuItem(	myPrefs->AboutMenuLabel, 
									new BMessage(ABOUT_TITLEWINDOW));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->PreferenceMenuLabel, 
									new BMessage(PREFSMSG));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myApp->CloseWindow, 
									new BMessage(B_QUIT_REQUESTED));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myApp->QuitMenuLabel, 
									new BMessage(QUIT_APP));
		APPMenu->AddItem(menuItem);
		mpMenuBar->AddItem(APPMenu);
		BMenu * FileMenu = new BMenu(myApp->FileMenuLabel);
		mpLoadBMI = new BMenuItem(	myApp->Load, 
									new BMessage(LOAD));
		FileMenu->AddItem(mpLoadBMI);
		mpSaveBMI = new BMenuItem(	myApp->Save, 
									new BMessage(SAVE));
		FileMenu->AddItem(mpSaveBMI);
		mpSaveBMI->SetEnabled(false);
		mpMenuBar->AddItem(FileMenu);
	}
	catch (...)
	{
		warning(myApp->CaughtTitleWindowCTOR);
		throw;
	}
}//end


//dtor
TitleWindow	::	~TitleWindow() 
{
	if (mpResEdWin)
	{
		mpResEdWin->PostMessage(B_QUIT_REQUESTED);
		while (mpResEdWin)
		{
			snooze(TINYSNOOZE);
		}
	}
	myApp->mpTitleWindow = NULL;
	delete mpLoadPanel;
	delete mpLoadMessenger;
	if (!myPrefs->mbPrefChangesMade)
	{
		myApp->PostMessage(B_QUIT_REQUESTED);
	}
}//end


void
TitleWindow	::	MessageReceived(	BMessage * pparamMessage) 
{
	switch(pparamMessage->what) 
	{
		case B_ARGV_RECEIVED:
			warning("debug TW argv mr");
		break;
		case B_REFS_RECEIVED:
			warning("debug tw REFS mr");
		break;
		case ABOUT_TITLEWINDOW:	
		{
			BString warn = myApp->AboutTitleWindowMsg1;
			warn += myApp->AboutTitleWindowMsg2;
			warn += myApp->AboutTitleWindowMsg3;
			warning(warn.String());
		}
		break;
		case QUIT_APP:
			if (Verify(myApp->ReallyQuitApp))
			{
				myApp->PostMessage(B_QUIT_REQUESTED);
			}
		break;
		case PREFSMSG:
		{
			myPrefs->OpenPreferencesPanel();
		break;
		}
		case LOADFROMPANEL:	
		{
			entry_ref ref;
			if (pparamMessage->FindRef("refs", &ref) >= B_OK) 
			{
				BFile file(&ref, B_READ_WRITE);
				status_t fileStatus;
				if ((fileStatus = file.InitCheck()) == B_NO_ERROR) 
				{
					BEntry file_entry(&ref, true);
					fileStatus = file_entry.InitCheck();
					if (fileStatus != B_NO_ERROR)
					{
						warning(myApp->FailEntryInitCheck);
						return;
					}
					fileStatus = mPathToFile.SetTo(&file_entry);
					if (fileStatus == B_NO_ERROR)
					{
						fileStatus = mPathToFile.InitCheck();
						if (fileStatus != B_NO_ERROR)
						{
							warning(myApp->FailPathInitCheck);
							return;
						}
					}
					else
					{
						warning(myApp->FailPathSetTo);
						return;
					}
					mpLoad->SetEnabled(false);
					mpLoadBMI->SetEnabled(false);
					if (OpenEdWin(&file))
					{
						mpSave->SetEnabled(true);
						mpSaveBMI->SetEnabled(true);
					}
					else
					{
						mpLoad->SetEnabled(true);
						mpLoadBMI->SetEnabled(true);
					}
				}
				else warning(myApp->FailFileInitCheck);
			}
			else warning(myApp->FailFileFindRef);
		break;
		}
		case LOAD:
			if (!mpLoadPanel) 
			{
				try 
				{
					mpLoadMessenger = new BMessenger(this);
				}
				catch (...) 
				{
					warning(myPrefs->FailMemory);
					mpLoadMessenger = NULL;
					return;
				}
				try 
				{
					mpLoadPanel = new BFilePanel(	B_OPEN_PANEL, 
													mpLoadMessenger, 
													NULL, 
													B_FILE_NODE, 
													false, 
													new BMessage(LOADFROMPANEL), 
													NULL, 
													false, 
													true);
					
					BWindow * panelWindow = mpLoadPanel->Window();
					panelWindow->SetTitle(myApp->OpenPanelTitle);
					mpLoadPanel->Show();
				}
				catch (...) 
				{
					warning(myPrefs->FailMemory);
					mpLoadPanel = NULL;
					return;
				}
			}
			else mpLoadPanel->Show();
		break;
		case SAVE:
			if (mpResEdWin) 
			{
				mpResEdWin->PostMessage(SAVE);
			}
		break;
		default:
			ScrollingWindow::MessageReceived(pparamMessage);
		break;
	}
}//end


bool
TitleWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	myApp->SetPreferredTitleWindowRect(frame);
	if (mpResEdWin)
	{
		((ResEdWindow *)mpResEdWin)->mpTitleWindow = NULL;
	}
	return(ScrollingWindow::QuitRequested());
}//end


bool
TitleWindow	::	OpenEdWin(	BFile * paramFile)
{
	bool bOpened;
	int timeOut = 0;
	while (mpResEdWin && (timeOut < 50)) 
	{
		if (mpResEdWin->PostMessage(B_QUIT_REQUESTED))
		{
			mpResEdWin = NULL;
		}
		else
		{
			snooze(TINYSNOOZE);
			timeOut++;
		}
	}
	if (!mpResEdWin) 
	{
		try 
		{
			BRect holdRect;
			myApp->GetPreferredResEdWindowRect(&holdRect);
			mpResEdWin = new ResEdWindow(	holdRect,
											myApp->ResEdWindow,
											"resEdWindow",
											"ResEdWindowFrame",
											this,
											&bOpened,
											paramFile);
			mpResEdWin->Initialize();
			if (!bOpened)
			{
				mpResEdWin->PostMessage(B_QUIT_REQUESTED);
				while (mpResEdWin)
				{
					snooze(TINYSNOOZE);
				}
				return false;
			}
		}
		catch (...)
		{
			warning(myApp->CaughtResEdWindowCTOR);
			myApp->PostMessage(B_QUIT_REQUESTED);
			return false;
		}
	}
	return true;
}//end