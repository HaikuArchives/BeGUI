//myStatusBar.h

#ifndef GUI_MYSTATUSBAR
#define GUI_MYSTATUSBAR
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyStatusBar	:	
	public	BStatusBar
	{
	private:
						MyStatusBar(	const MyStatusBar& copy);//not implemented on purpose
		MyStatusBar&	operator = (	const MyStatusBar& assign);//not implemented on purpose
	public:
		float			mfValue;
		float			mfMaxValue;
		float			mfWidthPref;
		float			mfHeightPref;
						MyStatusBar(	const char * paramName,
										const char * paramLabel,
										const char * paramTrailingLabel,
										float paramMaxValue,
										float paramValue,
										LayoutMatrix * paramLayoutMatrix);
		virtual			~MyStatusBar();
		virtual void	AttachedToWindow(	void);
		virtual void	MyGetPreferredSize(	float * paramWidth,
											float * paramHeight);
	};
#endif