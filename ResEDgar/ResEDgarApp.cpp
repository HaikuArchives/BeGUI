//myApp.cpp

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
#include "DcolorControlMessages.h"
#include "fontPrefWindow.h"
#include "specificColorWindow.h"
#include "basicColorWindow.h"
#include "prefPanelWindow.h"
#define NOTX_MYAPP 1
#include "ResEDgarApp.h"
#include "ResEDgarWindow.h"
#include "ResEDgarTitleWindow.h"



MyApp	::	MyApp()
		:	BApplication("application/x-vnd.EFM5.ResEdgar"),//if this sig changes change it in appStrings.r as well
			mpTitleWindow(NULL),
			AppSignature(NULL),
			FailCreateSemaphore(NULL),
			CaughtTitleWindowCTOR(NULL),
			AppMenuLabel(NULL),
			CloseWindow(NULL),
			QuitMenuLabel(NULL),
			TitleWindowTitle(NULL),
			ReallyQuitApp(NULL),
			AboutTitleWindowMsg1(NULL),
			AboutTitleWindowMsg2(NULL),
			AboutTitleWindowMsg3(NULL),
			ProgramName(NULL),
			ProgramNameSubTitle(NULL),
			EditResOf(NULL),
			OrigRes(NULL),
			EdittedRes(NULL),
			CaughtResEdWindowCTOR(NULL),
			Save(NULL),
			FileMenuLabel(NULL),
			AboutResEdWindowMsg1(NULL),
			AboutResEdWindowMsg2(NULL),
			AboutResEdWindowMsg3(NULL),
			FailAddResource(NULL),
			FailRemoveResource(NULL),
			Load(NULL),
			FailEntryInitCheck(NULL),
			FailPathInitCheck(NULL),
			FailPathSetTo(NULL),
			FailFileInitCheck(NULL),
			FailFileFindRef(NULL),
			OpenPanelTitle(NULL),
			ResEdWindow(NULL),
			NoStrRes(NULL),
			FailResourceSetTo(NULL),
			AppPrefFailInit(NULL),
			AppPrefSetFailInit(NULL),
			AppPrefNoSetData(NULL),
			AppsPrefsNoSave(NULL)
{
	myApp = this;
	BResources * appResources = AppResources();
	size_t len;
	AppSignature = (const char *)appResources->FindResource('CSTR', "AppSignature", &len);
	FailCreateSemaphore = (const char *)appResources->FindResource('CSTR', "FailCreateSemaphore", &len);
	CaughtTitleWindowCTOR = (const char *)appResources->FindResource('CSTR', "CaughtTitleWindowCTOR", &len);
	AppMenuLabel = (const char *)appResources->FindResource('CSTR', "AppMenuLabel", &len);
	CloseWindow = (const char *)appResources->FindResource('CSTR', "CloseWindow", &len);
	QuitMenuLabel = (const char *)appResources->FindResource('CSTR', "QuitMenuLabel", &len);
	TitleWindowTitle = (const char *)appResources->FindResource('CSTR', "TitleWindowTitle", &len);
	ReallyQuitApp = (const char *)appResources->FindResource('CSTR', "ReallyQuitApp", &len);
	AboutTitleWindowMsg1 = (const char *)appResources->FindResource('CSTR', "AboutTitleWindowMsg1", &len);
	AboutTitleWindowMsg2 = (const char *)appResources->FindResource('CSTR', "AboutTitleWindowMsg2", &len);
	AboutTitleWindowMsg3 = (const char *)appResources->FindResource('CSTR', "AboutTitleWindowMsg3", &len);
	ProgramName = (const char *)appResources->FindResource('CSTR', "ProgramName", &len);
	ProgramNameSubTitle = (const char *)appResources->FindResource('CSTR', "ProgramNameSubTitle", &len);
	EditResOf = (const char *)appResources->FindResource('CSTR', "EditResOf", &len);
	OrigRes = (const char *)appResources->FindResource('CSTR', "OrigRes", &len);
	EdittedRes = (const char *)appResources->FindResource('CSTR', "EdittedRes", &len);
	CaughtResEdWindowCTOR = (const char *)appResources->FindResource('CSTR', "CaughtResEdWindowCTOR", &len);
	Save = (const char *)appResources->FindResource('CSTR', "Save", &len);
	FileMenuLabel = (const char *)appResources->FindResource('CSTR', "FileMenuLabel", &len);
	AboutResEdWindowMsg1 = (const char *)appResources->FindResource('CSTR', "AboutResEdWindowMsg1", &len);
	AboutResEdWindowMsg2 = (const char *)appResources->FindResource('CSTR', "AboutResEdWindowMsg2", &len);
	AboutResEdWindowMsg3 = (const char *)appResources->FindResource('CSTR', "AboutResEdWindowMsg3", &len);
	FailAddResource = (const char *)appResources->FindResource('CSTR', "FailAddResource", &len);
	FailRemoveResource = (const char *)appResources->FindResource('CSTR', "FailRemoveResource", &len);
	Load = (const char *)appResources->FindResource('CSTR', "Load", &len);
	FailEntryInitCheck = (const char *)appResources->FindResource('CSTR', "FailEntryInitCheck", &len);
	FailPathInitCheck = (const char *)appResources->FindResource('CSTR', "FailPathInitCheck", &len);
	FailPathSetTo = (const char *)appResources->FindResource('CSTR', "FailPathSetTo", &len);
	FailFileInitCheck = (const char *)appResources->FindResource('CSTR', "FailFileInitCheck", &len);
	FailFileFindRef = (const char *)appResources->FindResource('CSTR', "FailFileFindRef", &len);
	OpenPanelTitle = (const char *)appResources->FindResource('CSTR', "OpenPanelTitle", &len);
	ResEdWindow = (const char *)appResources->FindResource('CSTR', "ResEdWindow", &len);
	NoStrRes = (const char *)appResources->FindResource('CSTR', "NoStrRes", &len);
	FailResourceSetTo = (const char *)appResources->FindResource('CSTR', "FailResourceSetTo", &len);
	AppPrefFailInit = (const char *)appResources->FindResource('CSTR', "AppPrefFailInit", &len);
	AppPrefSetFailInit = (const char *)appResources->FindResource('CSTR', "AppPrefSetFailInit", &len);
	AppPrefNoSetData = (const char *)appResources->FindResource('CSTR', "AppPrefNoSetData", &len);
	AppsPrefsNoSave = (const char *)appResources->FindResource('CSTR', "AppsPrefsNoSave", &len);

	Preferences appsPreferences(AppSignature);
	PreferenceSet appsPreferenceSet(	appsPreferences,  
										"hierarchical/extendable/settings", 
										true);
	mpPreferences = new Preferences(AppSignature);
	Preferences& mrPreferences = *mpPreferences;
	mpPreferenceSet = new PreferenceSet(	mrPreferences,  
											"hierarchical/extendable/settings", 
											true);
	if (mpPreferences->InitCheck())
	{
		puts(AppPrefFailInit);
		exit(1);
	}
	if (mpPreferenceSet->InitCheck())
	{
		puts(AppPrefSetFailInit);
		exit(2);
	}
	BRect	screenResolutionRect;
		{//I do screen like this so it goes away fast
			BScreen	screen(B_MAIN_SCREEN_ID);
			if(!screen.IsValid()) 
			{//may not be valid, if not, this is not a critical app--bail out as best we can
				puts(myPrefs->ScreenNotValid);
				exit(3);
			}
			screenResolutionRect = screen.Frame();
		}
	BRect windowPrefArea;
	const void * windowPrefAreaData;
	ssize_t windowPrefAreaSize;
	uint32 windowPrefAreaType = '    ';
	if (	mpPreferenceSet->GetData(	"TitleWindowFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
						//the - 17 and - 37 were determined based upon trial and error
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredTitleWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	"ResEdWindowFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
						//the - 17 and - 37 were determined based upon trial and error
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredResEdWindowRect(windowPrefArea);
}//end


MyApp	::	~MyApp() 
{
	delete mpPreferenceSet;
	delete mpPreferences;
	free((char *)AppSignature);
	free((char *)FailCreateSemaphore);
	free((char *)CaughtTitleWindowCTOR);
	free((char *)AppMenuLabel);
	free((char *)CloseWindow);
	free((char *)QuitMenuLabel);
	free((char *)TitleWindowTitle);
	free((char *)ReallyQuitApp);
	free((char *)AboutTitleWindowMsg1);
	free((char *)AboutTitleWindowMsg2);
	free((char *)AboutTitleWindowMsg3);
	free((char *)ProgramName);
	free((char *)ProgramNameSubTitle);
	free((char *)EditResOf);
	free((char *)OrigRes);
	free((char *)EdittedRes);
	free((char *)CaughtResEdWindowCTOR);
	free((char *)Save);
	free((char *)FileMenuLabel);
	free((char *)AboutResEdWindowMsg1);
	free((char *)AboutResEdWindowMsg2);
	free((char *)AboutResEdWindowMsg3);
	free((char *)FailAddResource);
	free((char *)FailRemoveResource);
	free((char *)Load);
	free((char *)FailEntryInitCheck);
	free((char *)FailPathInitCheck);
	free((char *)FailPathSetTo);
	free((char *)FailFileInitCheck);
	free((char *)FailFileFindRef);
	free((char *)OpenPanelTitle);
	free((char *)ResEdWindow);
	free((char *)NoStrRes);
	free((char *)FailResourceSetTo);
	free((char *)AppPrefFailInit);
	free((char *)AppPrefSetFailInit);
	free((char *)AppPrefNoSetData);
	free((char *)AppsPrefsNoSave);
}//end


bool
MyApp	::	QuitRequested(	void) 
{
	if (mpTitleWindow)
	{
		mpTitleWindow->PostMessage(B_QUIT_REQUESTED);
		while (mpTitleWindow)
		{
			snooze(TINYSNOOZE);
		}
	}
	Preferences appsPreferences(AppSignature);
	PreferenceSet appsPreferenceSet(	appsPreferences,  
										"hierarchical/extendable/settings", 
										true);
	if (appsPreferences.InitCheck())
	{
		puts(myPrefs->PrefFailInit);
		exit(1);
	}
	if (mpPreferenceSet->InitCheck())
	{
		puts(myPrefs->PrefFailGetSettings);
		exit(2);
	}
	bool allSetsOK = true;
	BRect frame;
	GetPreferredTitleWindowRect(&frame);
	if (mpPreferenceSet->SetData("TitleWindowFrame", &frame, sizeof(frame), B_RECT_TYPE))
	{
		warning(myPrefs->PrefNoSetGutFrame);
		allSetsOK = false;
	}
	if (allSetsOK)
	{
		GetPreferredResEdWindowRect(&frame);
		if (mpPreferenceSet->SetData("ResEdWindowFrame", &frame, sizeof(frame), B_RECT_TYPE))
		{
			warning(myPrefs->PrefNoSetGutFrame);
			allSetsOK = false;
		}
	}
	if (allSetsOK)
	{
		if (mpPreferenceSet->Save())
		{
			warning(myPrefs->PrefsNoSaveSet);
		}
	}
	return(BApplication	::	QuitRequested());
}//end


//all apps will need a main window to display on launch
void 
MyApp	::	ReadyToRun(	void) 
{
	OpenTitleWindow();
}//end


void 
MyApp	::	MessageReceived(	BMessage *	message) 
{
	switch(message->what)
	{
		case REOPEN:
		{
			OpenTitleWindow();
			if (myPrefs->pPrefPanelWindow)
			{
				int timeOut = 0;
				while (myPrefs->pPrefPanelWindow && (timeOut < 50)) 
				{
					myPrefs->pPrefPanelWindow->PostMessage(B_QUIT_REQUESTED);
					snooze(TINYSNOOZE);
					timeOut++;
				}
				if (!myPrefs->pPrefPanelWindow) 
				{
					myPrefs->OpenPreferencesPanel();
				}
			}
			myPrefs->mbPrefChangesMade = false;
		}
		break;
		case B_ARGV_RECEIVED:
			warning("debug argv mr");
		break;
		case B_REFS_RECEIVED:
			warning("debug REFS mr");
		break;
//		case 0:	//I am wondering about this
//				//it only shows up when app is launched from 
//				//tracker and resources are present in the file
//				//when run via double-click on the app icon I get a message here
//				//with a message->what == zero
//			warning("got unexpected zero msg in app\n");
//		break;
//		default:
//			//I don't expect any msgs here
//			//warning("got unexpected msg in app\n");
//		break;
	}
}//end


void
MyApp	::	GetPreferredTitleWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredTitleWindowRect;
}//end


void
MyApp	::	SetPreferredTitleWindowRect(	const BRect paramWindowRect)
{
	preferredTitleWindowRect = paramWindowRect;
}//end


void
MyApp	::	GetPreferredResEdWindowRect(	BRect * paramWindowRect) const
{
	*paramWindowRect = preferredResEdWindowRect;
}//end


void
MyApp	::	SetPreferredResEdWindowRect(	const BRect paramWindowRect)
{
	preferredResEdWindowRect = paramWindowRect;
}//end


void
MyApp	::	OpenTitleWindow(	void)
{
	int timeOut = 0;
	while (mpTitleWindow && (timeOut < 50)) 
	{
		if (mpTitleWindow->PostMessage(B_QUIT_REQUESTED))
		{
			mpTitleWindow = NULL;
		}
		else
		{
			snooze(TINYSNOOZE);
			timeOut++;
		}
	}
	if (!mpTitleWindow) 
	{
		try 
		{
			BRect holdRect;
			GetPreferredTitleWindowRect(&holdRect);
			mpTitleWindow = new TitleWindow(	holdRect,
												TitleWindowTitle,
												"titleWindow",
												"TitleWindowFrame");
			mpTitleWindow->Initialize();
		}
		catch (...)
		{
			warning(CaughtTitleWindowCTOR);
			PostMessage(B_QUIT_REQUESTED);
		}
	}
}//end


void
MyApp	::	ArgvReceived(	int32 argc,
							char **argv)
{
	printf("debug ArgvReceived %d, %s\n", argc, argv[0]);
}//end


void
MyApp	::	RefsReceived(	BMessage * paramMessage)
{
	uint32 type;
	int32 count;
	entry_ref ref;
	warning("debug RefsReceived");
	paramMessage->GetInfo("refs", &type, &count); 
	if ( type != B_REF_TYPE )
	{
		return;
	}
	for	(	long i = --count;
			i >= 0;
			i-- 
		)
	{
		if (paramMessage->FindRef("refs", i, &ref) == B_OK )
		{
			BFile file;
			if ( file.SetTo(&ref, B_READ_ONLY) == B_OK )
			{
				warning("debug good file");
			}
		}
	} 
}//end