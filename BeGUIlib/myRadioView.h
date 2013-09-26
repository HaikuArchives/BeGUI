//MyRadioView.h

#ifndef GUI_MYRADIOVIEW
#define GUI_MYRADIOVIEW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyRadioView	:	
	public	BView
	{
	private:
						MyRadioView(	const MyRadioView& copy);//not implemented on purpose
		MyRadioView&	operator = (	const MyRadioView& assign);//not implemented on purpose
	public:
		BList *			mpList;//list of RadioViewDatas
		BFont *			mpFont;
		bool			mbVertical;//button alignment
						MyRadioView(	const char * paramName, 
										bool paramVertical,
										BList * paramList,
										BFont * paramFont,
										LayoutMatrix * paramLayoutMatrix);
		virtual			~MyRadioView();
		virtual void	AttachedToWindow(	void);
		bool			Initialize(	void);
	};
#endif