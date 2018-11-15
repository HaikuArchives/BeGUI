//baseWindow.h

#ifndef BASEWINDOW
#define BASEWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	class UGLY_IMPEXP BaseView;
	class UGLY_IMPEXP PreferenceSet;
	#define MIN_BASEWINDOW_WIDTH 20
	#define MIN_BASEWINDOW_HEIGHT 20
	#define MATRIXVERTICALOFFSETBASE 3
	#define MATRIXHORIZONTALOFFSETBASE 3
	#define ABOUT_BASEWINDOW 'aBbw'
	
	class UGLY_IMPEXP
	BaseWindow	:
	public BWindow
	{
	private:
		const char *		mpNamePrefFrame;
		const char *		mpBaseViewName;
		BList *				mpLayoutMatrixList;
		PreferenceSet *		mpPreferenceSet;
		float				mfTitleWidth;
		bool				mbHasMenu;
		bool				mbShowInInit;
							BaseWindow(		const BaseWindow& copy);//not implemented on purpose
		BaseWindow&			operator = (	const BaseWindow& assign);//not implemented on purpose
	public:
		BMenuBar *			mpMenuBar;
		BaseView *			mpBaseView;
		float				mfMenuBarHeight;
							BaseWindow(	BRect paramBound,
										const char * paramWindowTitle,
										const char * paramBaseViewName,
										const char * paramNamePrefFrame,
										PreferenceSet *	paramPreferenceSet,
										bool paramHasMenu = true,
										bool paramShowInInit = true);
		virtual				~BaseWindow();
		bool				Initialize(	void);
		virtual void		MessageReceived(	BMessage *	paramMessage);
		virtual bool		QuitRequested(	void);
		virtual void		AddToLayoutMatrixList(	LayoutMatrix * paramLayoutMatrix);
	};
#endif