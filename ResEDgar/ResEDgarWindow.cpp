//ResEdWindow.cpp

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "DtinySnooze.h"
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
#include "stringGadget.h"
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
#include "ResEDgarTitleWindow.h"
#include "ResEDgarWindow.h"
#include "ResEDgarApp.h"
#include "ResEDgarEditNode.h"

//ctor
ResEdWindow	::	ResEdWindow(	BRect paramBound,
								const char * paramWindowTitle,
								const char * paramScrollViewName,
								const char * paramNamePrefFrame,
								TitleWindow * paramTitleWindow,
								bool * success,
								BFile * paramFile)
			: 
				ScrollingWindow(	paramBound, 
									paramWindowTitle, 
									paramScrollViewName,
									paramNamePrefFrame,
									myApp->mpPreferenceSet),
				mpEditList(new BList()),
				mpFile(paramFile),
				mbJustClose(false),
				mpTitleWindow(paramTitleWindow)
{
	*success = true;
	status_t stat = paramFile->InitCheck();
	if (stat == B_NO_ERROR)
	{
		stat = resources.SetTo(paramFile);
		if (stat == B_NO_ERROR)
		{
			int32 resourceID;
			const char * ccp;
			size_t size;
			if (!resources.GetResourceInfo((type_code)'CSTR', 0, &resourceID, &ccp, &size))
			{
				*success = false;
				warning(myApp->NoStrRes);
				mbJustClose = true;
				return;
			}
		}
		else
		{
			*success = false;
			warning(myApp->FailResourceSetTo);
			return;
		}
	}
	else
	{
		*success = false;
		warning(myApp->FailFileInitCheck);
		return;
	}
	sem_id calc_sem;
	if ((calc_sem = create_sem(1, "calc_sem")) < B_NO_ERROR)
	{
		warning(myApp->FailCreateSemaphore);
		*success = false;
		return;
	}
	acquire_sem(calc_sem);
	try 
	{
		LayoutMatrix *	pTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		BFont * pTitleFont = new BFont(myPrefs->GetPreferredFont());
		float fTitleFontSize = pTitleFont->Size();
		fTitleFontSize *= 1.3;
		if (fTitleFontSize > 200)
		{
			fTitleFontSize = 200;
		}
		pTitleFont->SetSize(fTitleFontSize);
		MyStringDrawer * pProgramNameMSD = new MyStringDrawer(	NULL, 
																myApp->EditResOf,
																pTitleLayoutMatrix,
																pTitleFont);
//////////////////////////////////////////////
		BFont * pSubTitleFont = new BFont(myPrefs->GetPreferredFont());
		MyStringDrawer * pProgramNameSubTitleMSD = new MyStringDrawer(	NULL, 
																		((TitleWindow *)mpTitleWindow)->mPathToFile.Path(),
																		pTitleLayoutMatrix,
																		pSubTitleFont);
///////////////////////////////////////////////
		LayoutMatrix *	pLabelLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		MyStringDrawer * pLabelMSD = new MyStringDrawer(	NULL, 
															myApp->OrigRes,
															pLabelLayoutMatrix,
															new BFont(pSubTitleFont));
///////////////////////////////////////////////
		LayoutMatrix *	pLabel1LayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		MyStringDrawer * pLabel1MSD = new MyStringDrawer(	NULL, 
															myApp->EdittedRes,
															pLabel1LayoutMatrix,
															new BFont(pSubTitleFont));
//////////////////////////////////////////////
		int32 numRes = 0;
		{
			const char * ccpResourceName;
			int32 resourceID;
			size_t size;
			for (	int32 i = 0;
					resources.GetResourceInfo('CSTR', i, &resourceID, &ccpResourceName, &size);
					i++
				)
			{
				numRes++;
			}
		}
////////////////////////////////////////////////
		LayoutMatrix *	pResEdLayoutMatrix = new LayoutMatrix(BESTSIZE, numRes, 1, this);//rows,columns
/////////////////////////////////////////////
		const float fEditWidth = 280;
		{
			const char * ccpResourceName;
			int32 resourceID;
			size_t size;
			size_t len;
			for (	int32 i = 0;
					i < numRes;
					i++
				)
			{
				resources.GetResourceInfo('CSTR', i, &resourceID, &ccpResourceName, &size);
				BString bs((const char *)resources.FindResource('CSTR', ccpResourceName, &len));
				bs += " :  ";
				StringGadget * pSG = new StringGadget(	(const char *)resources.FindResource('CSTR', ccpResourceName, &len),
														NULL,
														bs.String(),
														0,
														this,
														pResEdLayoutMatrix);
				EditNode * pholdEditNode = new EditNode(	pSG,
															resourceID,
															mpEditList,
															ccpResourceName);
			}
		}
/////////////////////////////////////////////////
		release_sem(calc_sem);
		pTitleLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, MATRIXVERTICALOFFSET, calc_sem);
		pLabelLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pTitleLayoutMatrix->mfBottom, calc_sem);
		pLabel1LayoutMatrix->Calc(pLabelLayoutMatrix->mfRight + 30, pTitleLayoutMatrix->mfBottom, calc_sem);
		pResEdLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pLabelLayoutMatrix->mfBottom, calc_sem);
	}
	catch (...)
	{
		warning(myApp->CaughtResEdWindowCTOR);
		release_sem(calc_sem);
		*success = false;
		throw;
	}
	try
	{
		BMenuItem *	menuItem;
		BMenu * APPMenu = new BMenu(myApp->AppMenuLabel);
		menuItem = new BMenuItem(	myApp->AboutMenuLabel, 
									new BMessage(ABOUT_RESEDWINDOW));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myApp->PreferenceMenuLabel, 
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
		menuItem = new BMenuItem(	myApp->Save, 
									new BMessage(SAVE));
		FileMenu->AddItem(menuItem);
		mpMenuBar->AddItem(FileMenu);
	}
	catch (...)
	{
		warning(myApp->CaughtResEdWindowCTOR);
		*success = false;
		throw;
	}
}//end


//dtor
ResEdWindow	::	~ResEdWindow() 
{
	EditNode * pEditNode = (EditNode *)mpEditList->LastItem();
	while(pEditNode)
	{
		mpEditList->RemoveItem((void *)pEditNode);
		delete pEditNode;
		pEditNode = (EditNode *)mpEditList->LastItem();
	}
	delete mpEditList;
	if (mpTitleWindow)
	{
		if (mpTitleWindow->LockLooper())
		{
			((TitleWindow * )mpTitleWindow)->mpSave->SetEnabled(false);
			((TitleWindow * )mpTitleWindow)->mpLoad->SetEnabled(true);
			mpTitleWindow->Unlock();
		}
		else
		{
			warning(myPrefs->FailLockLooper);
		}
		((TitleWindow * )mpTitleWindow)->mpResEdWin = NULL;
	}
	if (!mbJustClose)
	{
		if (!myPrefs->mbPrefChangesMade)
		{
			myApp->PostMessage(B_QUIT_REQUESTED);
		}
	}
}//end


void
ResEdWindow	::	MessageReceived(	BMessage * pparamMessage) 
{
	switch(pparamMessage->what) 
	{
		case ABOUT_RESEDWINDOW:	
		{
			BString warn = myApp->AboutResEdWindowMsg1;
			warn += myApp->AboutResEdWindowMsg2;
			warn += myApp->AboutResEdWindowMsg3;
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
		case SAVE:
			Save();
		break;
		default:
			ScrollingWindow::MessageReceived(pparamMessage);
		break;
	}
}//end


bool
ResEdWindow	::	QuitRequested(	void) 
{
	BRect frame = Frame();
	myApp->SetPreferredResEdWindowRect(frame);
	mbJustClose = true;
	return(ScrollingWindow::QuitRequested());
}//end


bool
ResEdWindow	::	Save(	void)
{
	int32 numItems = mpEditList->CountItems();
	for (	int32 i = 0;
			i < numItems;
			i++
		)
	{
		EditNode * pEditNode = (EditNode *)mpEditList->ItemAt(i);
		StringGadget * pSG = pEditNode->mpSG;
		if (strcmp(pSG->mpLabel->String(), pSG->Text()))
		{
			status_t stat = resources.RemoveResource('CSTR', pEditNode->mi32ResourceID);
			if (stat == B_OK)
			{
				stat = resources.AddResource(	'CSTR', 
												pEditNode->mi32ResourceID,
												(const void *)pSG->Text(),
												strlen(pSG->Text()) + 1,
												pEditNode->mpResourceName);
				if (stat != B_OK)
				{
					warning(myApp->FailAddResource);
					return false;
				}
			}
			else
			{
				warning(myApp->FailRemoveResource);
				return false;
			}
		}
	}
	return true;
}//end