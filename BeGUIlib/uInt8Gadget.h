//int8Gadget.h

#ifndef GUI_UINT8GADGET
#define GUI_UINT8GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnUI8 5
	#define MAX_UI8 255
	#define MIN_UI8 0

	class UGLY_IMPEXP
	UInt8Gadget	:	
	public	GadgetBase
	{
	private:
						UInt8Gadget(		const UInt8Gadget& copy);//not implemented on purpose
		UInt8Gadget&	operator = (	const UInt8Gadget& assign);//not implemented on purpose
	public:
						UInt8Gadget(	uint8 paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~UInt8Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
