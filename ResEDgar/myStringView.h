//myStringView.h

#ifndef GUI_MYSTRINGVIEW
#define GUI_MYSTRINGVIEW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif

	class UGLY_IMPEXP
	MyStringView	:	
	public	BView
	{
	private:
						MyStringView(	const MyStringView& copy);//not implemented on purpose
		MyStringView&	operator = (	const MyStringView& assign);//not implemented on purpose
	public:
		BFont *			mpFont;
		rgb_color *		mrgbViewColor;
		rgb_color *		mrgbHighColor;
		rgb_color *		mrgbLowColor;
		float			mfBaseline;
		BString			mbsText;
						MyStringView(	const char * paramName, 
										const char * paramText,
										BFont * paramFont = NULL,
										rgb_color * paramViewColor = NULL,
										rgb_color * paramHighColor = NULL,
										rgb_color * paramLowColor = NULL);
		virtual			~MyStringView();
		virtual void	AttachedToWindow(	void);
		virtual void	Draw(	BRect paramRect);
	};
#endif
