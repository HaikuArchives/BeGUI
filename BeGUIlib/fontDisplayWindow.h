//fontDisplayWindow.h

#ifndef FONTDISPLAYWINDOW
#define FONTDISPLAYWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP ScrollingWindow;
	#define ABOUT_FONTDISPLAYWINDOW 'afdw'

	class UGLY_IMPEXP
	FontDisplayWindow	:
	public ScrollingWindow
	{
	private:
		const char *			mpPutString;
								FontDisplayWindow(		const FontDisplayWindow& copy);//not implemented on purpose
		FontDisplayWindow&		operator = (	const FontDisplayWindow& assign);//not implemented on purpose
	public:
								FontDisplayWindow(	BRect paramBound,
													const char * paramWindowTitle,
													const char * paramScrollViewName,
													const char * paramNamePrefFrame,
													const char * paramPutString);
		virtual					~FontDisplayWindow();
		virtual bool			QuitRequested(		void);
		virtual void			MessageReceived(	BMessage *	paramMessage);
	};
#endif