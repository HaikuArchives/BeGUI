//fontPrefWindow.h

#ifndef FONTPREFWINDOW
#define FONTPREFWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP FloatGadget;
	class UGLY_IMPEXP MyPopUpMenu;
	class UGLY_IMPEXP ScrollingWindow;
	class UGLY_IMPEXP MyCheckBox;
	#define ABOUT_FONTPREFWINDOW 'afpw'
	#define DISPLAY_FONT 'dfnt'
	#define ANTIALIAS_FONT 'aafn'
	#define BIGGER_FONT 'bfnt'
	#define SMALLER_FONT 'sfnt'
	#define FONT_SIZE_STR 'ftss'

	class UGLY_IMPEXP
	FontPrefWindow	:
	public ScrollingWindow
	{
	private:
		font_family			mffFamilyName;
		font_style			mfsStyleName;
							FontPrefWindow(	const FontPrefWindow& copy);//not implemented on purpose
		FontPrefWindow&		operator = (	const FontPrefWindow& assign);//not implemented on purpose
		void				OpenFontDisplayWindow(	void);
	public:
		BString				mbsFullLine;
		FloatGadget *		mpSizeFloatGadget;
		ScrollingWindow *	mpFontDisplayWindow;
		MyPopUpMenu *		mpFontFamilyPUM;
		MyPopUpMenu *		mpFontStylePUM;
		MyCheckBox *		mpDisplayFontCheckBox;
		MyCheckBox *		mpAntiAliasFontCheckBox;
							FontPrefWindow(	BRect paramBound,
											const char * paramWindowTitle,
											const char * paramScrollViewName,
											const char * paramNamePrefFrame);
		virtual				~FontPrefWindow();
		virtual bool		QuitRequested(	void);
		virtual void		MessageReceived(	BMessage *	paramMessage);
		void				ResetFontSize(	float newSize);
	};
#endif