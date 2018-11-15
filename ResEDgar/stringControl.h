//stringControl.h

#ifndef GUI_STRINGCONTROL
#define GUI_STRINGCONTROL
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	
	class UGLY_IMPEXP
	StringControl	:	
	public	BTextControl
	{
	private:
						StringControl(	const StringControl& copy);//not implemented on purpose
		StringControl&	operator = (	const StringControl& assign);//not implemented on purpose
	public:
		float			mfTextViewWidth;
		bool			mbMakeFocus;
						StringControl(	const char * paramName, 
										const char * paramLabel, 
										const char * paramText, 
										uint32 paramMsg, 
										float paramTextViewWidth,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~StringControl(); 
		virtual void 	AttachedToWindow(	void);
	};
#endif