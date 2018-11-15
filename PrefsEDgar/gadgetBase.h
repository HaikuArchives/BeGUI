//gadgetBase.h

#ifndef GUI_GADGETBASE
#define GUI_GADGETBASE
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP MyStringView;

	class UGLY_IMPEXP
	GadgetBase	:
	public	BTextView
	{
	private:
		float			mfTop;
		float			mfLeft;
						GadgetBase(		const GadgetBase& copy);//not implemented on purpose
		GadgetBase&		operator = (	const GadgetBase& assign);//not implemented on purpose
	public:
		BLooper *		mpMessageTarget;
		BString			mbsValueString;
		BString *		mpLabel;
		MyStringView *	mpLabelView;
		float			mfTextViewWidth;
		float			mfHeight;
		float			mfLabelWidth;
		float			mfLabelLeft;
		float			mfLabelTop;
		bool			mbMakeFocus;
						GadgetBase(	const char * paramName,
									const char * paramLabel,
									BLooper * paramMessageTarget,
									bool paramMakeFocus = false);
		virtual			~GadgetBase();
		void			SetTop(	const float paramTop);
		float			GetTop(	void) const;
		void			SetLeft(	const float paramLeft);
		float			GetLeft(	void) const;
	};
#endif
