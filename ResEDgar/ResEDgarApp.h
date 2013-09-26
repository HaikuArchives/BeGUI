//myApp.h
#ifndef MYAPP
#define MYAPP
	class TitleWindow;
	class MyPreferences;
	
	class 
	MyApp	:
	public	BApplication
	{
	private:
		BRect			preferredTitleWindowRect;
		BRect			preferredResEdWindowRect;
		MyPreferences	mp;
						MyApp(	const MyApp& copy);//not implimented on purpose
		MyApp&			operator = (	const MyApp& assign);//not implimented on purpose
	public:
		TitleWindow *	mpTitleWindow;
		Preferences *	mpPreferences;
		PreferenceSet *	mpPreferenceSet;
		const char		* AppSignature,
						* FailCreateSemaphore,
						* CaughtTitleWindowCTOR,
						* AppMenuLabel,
						* CloseWindow,
						* QuitMenuLabel,
						* TitleWindowTitle,
						* ReallyQuitApp,
						* AboutTitleWindowMsg1,
						* AboutTitleWindowMsg2,
						* AboutTitleWindowMsg3,
						* ProgramName,
						* ProgramNameSubTitle,
						* EditResOf,
						* OrigRes,
						* EdittedRes,
						* CaughtResEdWindowCTOR,
						* Save,
						* FileMenuLabel,
						* AboutMenuLabel,
						* PreferenceMenuLabel,
						* AboutResEdWindowMsg1,
						* AboutResEdWindowMsg2,
						* AboutResEdWindowMsg3,
						* FailAddResource,
						* FailRemoveResource,
						* Load,
						* FailEntryInitCheck,
						* FailPathInitCheck,
						* FailPathSetTo,
						* FailFileInitCheck,
						* FailFileFindRef,
						* OpenPanelTitle,
						* ResEdWindow,
						* NoStrRes,
						* FailResourceSetTo,
						* AppPrefFailInit,
						* AppPrefSetFailInit,
						* AppPrefNoSetData,
						* AppsPrefsNoSave;
						MyApp();
						~MyApp();
		void			MessageReceived(	BMessage * message);
		void			ArgvReceived(	int32 argc,
										char **argv);
		void			RefsReceived(	BMessage * paramMessage);
		void			ReadyToRun(	void);
		bool			QuitRequested(	void);
		void			OpenTitleWindow(	void);
		void			GetPreferredTitleWindowRect(	BRect * paramWindowRect) const;
		void			SetPreferredTitleWindowRect(	const BRect paramWindowRect);
		void			GetPreferredResEdWindowRect(	BRect * paramWindowRect) const;
		void			SetPreferredResEdWindowRect(	const BRect paramWindowRect);
	};
	#if NOTX_MYAPP
		MyApp * myApp;
	#else
		extern MyApp * myApp;
	#endif
#endif