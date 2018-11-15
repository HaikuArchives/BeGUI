//floatControl.h

#ifndef GUI_FLOATCONTROL
#define GUI_FLOATCONTROL	
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	FloatControl	:	
	public	BTextControl
	{
	private:
						FloatControl(	const FloatControl& copy);//not implemented on purpose
		FloatControl&	operator = (	const FloatControl& assign);//not implemented on purpose
	public:
		float			mfTextViewWidth;
		bool			mbMakeFocus;
						FloatControl(	float paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										uint32 paramMsg, 
										float paramTextViewWidth,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual void 	AttachedToWindow();
		virtual			~FloatControl();
	};
#endif
