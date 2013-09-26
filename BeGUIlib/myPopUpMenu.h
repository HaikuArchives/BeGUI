//myPopUpMenu.h

#ifndef GUI_MYPOPUPMENU
#define GUI_MYPOPUPMENU
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	class UGLY_IMPEXP MyStringView;
	#define BEGUIPUM 'BgPM'

	class UGLY_IMPEXP
	MyPopUpMenu	:	
	public	BMenuBar
	{
	private:
		BList *			mpList;//list of PopUpMenuDatas
		const char *	mpTitle;
		bool			mbIsRadioMode;
		float			mfTop;
		float			mfLeft;
						MyPopUpMenu(	const MyPopUpMenu& copy);//not implemented on purpose
		MyPopUpMenu&	operator = (	const MyPopUpMenu& assign);//not implemented on purpose
	public:
		BString *		mpLabel;
		BString *		mpMenuName;
		MyStringView *	mpLabelView;
		float			mfLabelHeight;
		float			mfLabelWidth;
		float			mfLabelLeft;
		float			mfLabelTop;
		float			mfWidest;
		float			mfHeight;
						MyPopUpMenu(	const char * paramName, 
										const char * paramTitle,
										BList * paramList,
										bool paramIsRadioMode,
										const char * paramLabel,
										LayoutMatrix * paramLayoutMatrix);
		virtual			~MyPopUpMenu();
		bool			Initialize(	void);
		virtual void	MyGetPreferredSize(	float * paramWidth,
											float * paramHeight);
		void			SetLeft(	const float paramLeft);
		float			GetLeft(	void) const;
	};
#endif