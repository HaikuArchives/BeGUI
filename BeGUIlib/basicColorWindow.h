//basicColorWindow.h

#ifndef BASICCOLORWINDOW
#define BASICCOLORWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP ColorWell;
	class UGLY_IMPEXP MyColorControl;
	class UGLY_IMPEXP ScrollingWindow;
	#define ABOUT_BASICCOLORWINDOW 'abcw'
	
	class UGLY_IMPEXP
	BasicColorWindow	:
	public ScrollingWindow
	{
	private:
							BasicColorWindow(	const BasicColorWindow& copy);//not implemented on purpose
		BasicColorWindow&	operator = (	const BasicColorWindow& assign);//not implemented on purpose
	public:
		MyColorControl *	mpViewColorControl;
		MyColorControl *	mpHighColorControl;
		MyColorControl *	mpLowColorControl;
		ColorWell *			mpViewColorWell;
		ColorWell *			mpHighColorWell;
		ColorWell *			mpLowColorWell;
							BasicColorWindow(	BRect paramBound,
												const char * paramWindowTitle,
												const char * paramScrollViewName,
												const char * paramNamePrefFrame);
							~BasicColorWindow();
		virtual void		MessageReceived(	BMessage *	paramMessage);
		virtual bool		QuitRequested(	void);
		void				ResetDemo(	void);
	};
#endif