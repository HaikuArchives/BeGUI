//myApp.h
#ifndef MYAPP
#define MYAPP
	class PrefsEDgarWindow;
	
	class 
	MyApp	:
	public	BApplication
	{
	private:
							MyApp(	const MyApp& copy);//not implemented on purpose
		MyApp&				operator = (	const MyApp& assign);//not implemented on purpose
		MyPreferences		mp;
	public:
		PrefsEDgarWindow *	mpPrefsEDgarWindow;
		Preferences *		mpPreferences;
		PreferenceSet *		mpPreferenceSet;
		BRect				preferredPrefsEDgarWindowRect;
		const char			* AppSignature,
							* CaughtPrefsEDgarWindowCTOR,
							* AppMenuLabel,
							* CloseWindow,
							* QuitMenuLabel,
							* PrefsEDgarWindowTitle,
							* ReallyQuitApp,
							* AboutPrefsEDgarWindowMsg1,
							* AboutPrefsEDgarWindowMsg2,
							* AboutPrefsEDgarWindowMsg3,
							* ProgramName,
							* ProgramNameSubTitle,
							* AppPrefFailInit,
							* AppPrefSetFailInit,
							* AppPrefNoSetData,
							* AppsPrefsNoSave,
							* FailFetchBitmapFile,
							* FailFetchBitmapBTranslatorRoster,
							* FailFetchBitmapTranslate,
							* NoBitmap;
							MyApp();
							~MyApp();
		void				MessageReceived(	BMessage * message);
		void				ReadyToRun(	void);
		bool				QuitRequested(	void);
		void				OpenPrefsEDgarWindow(	void);
	};
	#if NOTX_MYAPP
		MyApp * myApp;
	#else
		extern MyApp * myApp;
	#endif
#endif