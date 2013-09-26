//simpleWindow.h

#ifndef SIMPLEWINDOW
#define SIMPLEWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP PreferenceSet;
	#define ABOUT_SIMPLEWINDOW 'aBsw'
	
	class UGLY_IMPEXP
	SimpleWindow	:
	public BWindow
	{
	private:
		const char *	mpNamePrefFrame;
		float			mfTitleWidth;
		PreferenceSet *	mpPreferenceSet;
		bool			mbHasMenu;
		bool			mbShowInInit;
						SimpleWindow(		const SimpleWindow& copy);//not implemented on purpose
		SimpleWindow&	operator = (	const SimpleWindow& assign);//not implemented on purpose
	public:
		BMenuBar *		mpMenuBar;
		float			mfMenuBarHeight;
						SimpleWindow(	BRect paramBound,
										const char * paramWindowTitle,
										const char * paramNamePrefFrame,
										PreferenceSet *	paramPreferenceSet,
										bool paramHasMenu = true,
										bool paramShowInInit = true);
		virtual			~SimpleWindow();
		bool			Initialize(	void);
		virtual void	MessageReceived(	BMessage *	paramMessage);
		bool			QuitRequested(	void);
	};
#endif