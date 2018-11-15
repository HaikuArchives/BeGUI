//scrollingWindow.h

#ifndef SCROLLINGWINDOW
#define SCROLLINGWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	class UGLY_IMPEXP ScrollView;
	class UGLY_IMPEXP PreferenceSet;
	#define MIN_GUTSWINDOW_WIDTH 20
	#define MIN_GUTSWINDOW_HEIGHT 20
	#define MATRIXVERTICALOFFSETGUTS 3
	#define MATRIXHORIZONTALOFFSETGUTS 3
	#define ABOUT_WINDOWGUTS 'aBwt'
	
	class UGLY_IMPEXP
	ScrollingWindow	:
	public BWindow
	{
	private:
		const char *		mpScrollViewName;
		const char *		mpNamePrefFrame;
		BList *				mpLayoutMatrixList;
		PreferenceSet *		mpPreferenceSet;
		float				mfTitleWidth;
		bool				mbHasMenu;
		bool				mbShowInInit;
							ScrollingWindow(		const ScrollingWindow& copy);//not implemented on purpose
		ScrollingWindow&	operator = (	const ScrollingWindow& assign);//not implemented on purpose
	public:
		BMenuBar *			mpMenuBar;
		BScrollView	*		mpScrollView;
		ScrollView	*		mpBaseView;
		float				mfUnderViewWidth;
		float				mfUnderViewHeight;
		float				mfMenuBarHeight;
							ScrollingWindow(	BRect paramBound,
												const char * paramWindowTitle,
												const char * paramScrollViewName,
												const char * paramNamePrefFrame,
												PreferenceSet *	paramPreferenceSet,
												bool paramHasMenu = true,
												bool paramShowInInit = true);
		virtual				~ScrollingWindow();
		bool				Initialize(	void);
		virtual void		MessageReceived(	BMessage *	paramMessage);
		virtual void		FrameResized(	float, 
											float);
		virtual bool		QuitRequested(	void);
		virtual void		UpdateScrollBars(	void);
		virtual void		AddToLayoutMatrixList(	LayoutMatrix * paramLayoutMatrix);
	};
#endif