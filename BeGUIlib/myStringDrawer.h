//myStringDrawer.h

#ifndef GUI_MYSTRINGDRAWER
#define GUI_MYSTRINGDRAWER
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP TextItem;
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyStringDrawer	:	
	public	BStringView
	{
	private:
		BFont *			mpFont;
		TextItem *		mpTextItem;
						MyStringDrawer(	const MyStringDrawer& copy);//not implemented on purpose
		MyStringDrawer&	operator = (	const MyStringDrawer& assign);//not implemented on purpose
	public:
		float			mfDescender;
						MyStringDrawer(	const char * paramName, 
										const char * paramText,
										LayoutMatrix * paramLayoutMatrix,
										BFont * paramFont = NULL);
		virtual			~MyStringDrawer();
		virtual void	AttachedToWindow(	void);
		virtual void	MyGetPreferredSize(	float * paramWidth,
											float * paramHeight);
		BFont *			GetFont(	void) const;
		TextItem *		GetTextItem(	void) const;
	};
#endif
