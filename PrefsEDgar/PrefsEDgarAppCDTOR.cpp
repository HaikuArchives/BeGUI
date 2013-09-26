//PrefsEDgarApp.cpp

#include "commonHeaders.h"
#include "DtinySnooze.h"
#include "DnumSpecificWindows.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "warning.h"
#include "scrollingWindow.h"
#include "simpleWindow.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
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
#include "PrefsEDgarApp.h"
#include "PrefsEDgarWindow.h"
#include "smallerRect.h"

MyApp	::	MyApp()
		:	BApplication("application/x-vnd.EFM5.PrefsEDgar"),//if this sig changes change it in appStrings.r as well
			AppSignature(NULL),
			CaughtPrefsEDgarWindowCTOR(NULL),
			AppMenuLabel(NULL),
			CloseWindow(NULL),
			QuitMenuLabel(NULL),
			PrefsEDgarWindowTitle(NULL),
			ReallyQuitApp(NULL),
			AboutPrefsEDgarWindowMsg1(NULL),
			AboutPrefsEDgarWindowMsg2(NULL),
			AboutPrefsEDgarWindowMsg3(NULL),
			ProgramName(NULL),
			ProgramNameSubTitle(NULL),
			AppPrefFailInit(NULL),
			AppPrefSetFailInit(NULL),
			AppPrefNoSetData(NULL),
			AppsPrefsNoSave(NULL),
			FailFetchBitmapFile(NULL),
			FailFetchBitmapBTranslatorRoster(NULL),
			FailFetchBitmapTranslate(NULL),
			NoBitmap(NULL)
{
	myApp = this;
	BResources * appResources = AppResources();
	size_t len;
	AppSignature = (const char *)appResources->FindResource('CSTR', "AppSignature", &len);
	CaughtPrefsEDgarWindowCTOR = (const char *)appResources->FindResource('CSTR', "CaughtPrefsEDgarWindowCTOR", &len);
	AppMenuLabel = (const char *)appResources->FindResource('CSTR', "AppMenuLabel", &len);
	CloseWindow = (const char *)appResources->FindResource('CSTR', "CloseWindow", &len);
	QuitMenuLabel = (const char *)appResources->FindResource('CSTR', "QuitMenuLabel", &len);
	PrefsEDgarWindowTitle = (const char *)appResources->FindResource('CSTR', "PrefsEDgarWindowTitle", &len);
	ReallyQuitApp = (const char *)appResources->FindResource('CSTR', "ReallyQuitApp", &len);
	AboutPrefsEDgarWindowMsg1 = (const char *)appResources->FindResource('CSTR', "AboutPrefsEDgarWindowMsg1", &len);
	AboutPrefsEDgarWindowMsg2 = (const char *)appResources->FindResource('CSTR', "AboutPrefsEDgarWindowMsg2", &len);
	AboutPrefsEDgarWindowMsg3 = (const char *)appResources->FindResource('CSTR', "AboutPrefsEDgarWindowMsg3", &len);
	ProgramName = (const char *)appResources->FindResource('CSTR', "ProgramName", &len);
	ProgramNameSubTitle = (const char *)appResources->FindResource('CSTR', "ProgramNameSubTitle", &len);
	AppPrefFailInit = (const char *)appResources->FindResource('CSTR', "AppPrefFailInit", &len);
	AppPrefSetFailInit = (const char *)appResources->FindResource('CSTR', "AppPrefSetFailInit", &len);
	AppPrefNoSetData = (const char *)appResources->FindResource('CSTR', "AppPrefNoSetData", &len);
	AppsPrefsNoSave = (const char *)appResources->FindResource('CSTR', "AppsPrefsNoSave", &len);
	FailFetchBitmapFile = (const char *)appResources->FindResource('CSTR', "FailFetchBitmapFile", &len);
	FailFetchBitmapBTranslatorRoster = (const char *)appResources->FindResource('CSTR', "FailFetchBitmapBTranslatorRoster", &len);
	FailFetchBitmapTranslate = (const char *)appResources->FindResource('CSTR', "FailFetchBitmapTranslate", &len);
	NoBitmap = (const char *)appResources->FindResource('CSTR', "NoBitmap", &len);

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
	BRect screenResolutionRect;
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
	if (	mpPreferenceSet->GetData(	"PrefsEDgarWindowFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	33,
							73, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	preferredPrefsEDgarWindowRect = windowPrefArea;
}//end


MyApp	::	~MyApp() 
{
	delete mpPreferenceSet;
	delete mpPreferences;
	free((char *)AppSignature);
	free((char *)CaughtPrefsEDgarWindowCTOR);
	free((char *)AppMenuLabel);
	free((char *)CloseWindow);
	free((char *)QuitMenuLabel);
	free((char *)PrefsEDgarWindowTitle);
	free((char *)ReallyQuitApp);
	free((char *)AboutPrefsEDgarWindowMsg1);
	free((char *)AboutPrefsEDgarWindowMsg2);
	free((char *)AboutPrefsEDgarWindowMsg3);
	free((char *)ProgramName);
	free((char *)ProgramNameSubTitle);
	free((char *)AppPrefFailInit);
	free((char *)AppPrefSetFailInit);
	free((char *)AppPrefNoSetData);
	free((char *)AppsPrefsNoSave);
	free((char *)FailFetchBitmapFile);
	free((char *)FailFetchBitmapBTranslatorRoster);
	free((char *)FailFetchBitmapTranslate);
	free((char *)NoBitmap);
}//end