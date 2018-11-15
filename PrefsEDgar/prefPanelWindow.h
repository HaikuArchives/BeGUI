//prefpanelWindow.h

#ifndef PREFPANELWINDOW
#define PREFPANELWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP ScrollingWindow;
	class UGLY_IMPEXP MyCheckBox;
	#define ABOUT_PREFPANELWINDOW 'ppan'
	#define DISPLAY_CC 'd cc'
	#define DISPLAY_CW 'd cw'
	//debug array indexes make enums??
	#define PP_BASIC 0
	#define PP_COLOR_BUTTON 1
	#define PP_COLOR_PICTURE 2
	#define PP_COLOR_RADIOVIEW 3
	#define PP_COLOR_CHECKBOX 4
	#define PP_COLOR_STATUSBAR 5
	#define PP_COLOR_COLORCONTROL 6
	#define PP_COLOR_COLORWELL 7
	#define PP_COLOR_INT8GADGET 8
	#define PP_COLOR_UINT8GADGET 9
	#define PP_COLOR_INT16GADGET 10
	#define PP_COLOR_UINT16GADGET 11
	#define PP_COLOR_INT32GADGET 12
	#define PP_COLOR_UINT32GADGET 13
	#define PP_COLOR_INT64GADGET 14
	#define PP_COLOR_UINT64GADGET 15
	#define PP_COLOR_FLOATGADGET 16
	#define PP_COLOR_STRINGGADGET 17
	#define PP_COLOR_STRINGCONTROL 18
	#define PP_COLOR_TEXTVIEW 19
	#define PP_COLOR_STRINGDRAWER 20
	#define PP_COLOR_LISTVIEW 21
	#define PP_COLOR_FLOATCONTROL 22
	#define PP_COLOR_UINT32CONTROL 23
	#define PP_COLOR_SLIDER 24
	
	class UGLY_IMPEXP
	PrefPanelWindow	:
	public ScrollingWindow
	{
	private:
							PrefPanelWindow(	const PrefPanelWindow& copy);//not implemented on purpose
		PrefPanelWindow&	operator = (		const PrefPanelWindow& assign);//not implemented on purpose
	public:
		ScrollingWindow *	mpFontPrefWindow;
		ScrollingWindow *	mpPrefWindows[NUMPREFPANELS];
		MyCheckBox *		mpDisplayColorControlCheckBox;
		MyCheckBox *		mpDisplayColorWellCheckBox;
							PrefPanelWindow(	BRect paramBound,
												const char * paramWindowTitle,
												const char * paramScrollViewName,
												const char * paramNamePrefFrame);
		virtual				~PrefPanelWindow();
		virtual bool		QuitRequested(		void);
		virtual void		MessageReceived(	BMessage *	paramMessage);
		void				OpenFontPanel(	void);
		void				OpenBasicColorPanel(	void);
		void				OpenSpecificColorPanel(uint32 whichOne);
	};
#endif