//colorWell.h

#ifndef GUI_COLORWELL
#define GUI_COLORWELL
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP MyStringView;
	//debug these should probably be static enums???
	#define VIEW_COLOR 0
	#define HIGH_COLOR 1
	#define LOW_COLOR 2
	#define BAR_COLOR 3
	#define FILL_COLOR 4
	#define NO_COLOR 999
	#define roColourDROPPEDMESSAGE B_PASTE

	class UGLY_IMPEXP
	ColorWell	:	
	public	BView
	{
	private:
		BLooper *		mpMessageTarget;
		float			mfTop;
		float			mfLeft;
		int32			mi32ColorToChange;
		BString			mbsValueString;
						ColorWell(	const ColorWell& copy);//not implemented on purpose
		ColorWell&		operator = (	const ColorWell& assign);//not implemented on purpose
	public:
		BString *		mpLabel;
		MyStringView *	mpLabelView;
		float			mfTextOrigin;
		float			mfHeight;
		float			mfLabelWidth;
		float			mfLabelLeft;
		float			mfLabelTop;
		uint8			mui8Width;
		uint8			mui8Height;
						ColorWell(	const char * paramName, 
									int32 parami32ColorToChange,
									const char * paramLabel,
									BLooper * paramMessageTarget,
									LayoutMatrix * paramLayoutMatrix);
						~ColorWell();
		virtual void	AttachedToWindow(	void);
		virtual void	Draw(	BRect rect);
		virtual void	MessageReceived(	BMessage *	paramMessage);
		void			SetTop(	const float paramTop);
		float			GetTop(	void) const;
		void			SetLeft(	const float paramLeft);
		float			GetLeft(	void) const;
	};
#endif