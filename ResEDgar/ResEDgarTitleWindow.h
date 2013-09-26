//titleWindow.h
#ifndef TITLEWINDOW
#define TITLEWINDOW
	#define ABOUT_TITLEWINDOW 'tITL'
	#define SAVE 'Save'
	#define LOAD 'Load'
	#define LOADFROMPANEL 'LfrP'
	class MyButton;
	class ResEdWindow;

	class TitleWindow :
	public ScrollingWindow
	{
	private:
							TitleWindow(		const TitleWindow& copy);//not implimented on purpose
		TitleWindow&		operator = (	const TitleWindow& assign);//not implimented on purpose
		bool				OpenEdWin(	BFile * paramFile);
	public:
							TitleWindow(	BRect paramBound,
											const char * paramWindowTitle,
											const char * paramScrollViewName,
											const char * paramNamePrefFrame);
							~TitleWindow();
		virtual bool		QuitRequested(		void);
		virtual void		MessageReceived(	BMessage *	pparamMessage);
		MyButton *			mpLoad;
		MyButton *			mpSave;
		BFilePanel * 		mpLoadPanel;
		BMessenger * 		mpLoadMessenger;
		ResEdWindow *		mpResEdWin;
		BMenuItem *			mpSaveBMI;
		BMenuItem *			mpLoadBMI;
		BPath				mPathToFile;
	};
#endif