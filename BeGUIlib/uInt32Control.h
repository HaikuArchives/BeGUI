//uInt32Control.h

#ifndef GUI_UINT32CONTROL
#define GUI_UINT32CONTROL
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	UInt32Control	:	
	public	BTextControl
	{
	private:
						UInt32Control(		const UInt32Control& copy);//not implemented on purpose
		UInt32Control&	operator = (	const UInt32Control& assign);//not implemented on purpose
	public:
		float			mfTextViewWidth;
		bool			mbMakeFocus;
						UInt32Control(	uint32 paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										uint32 paramMsg, 
										float paramTextViewWidth,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual void 	AttachedToWindow();
		virtual			~UInt32Control();
	};
#endif
