//uInt32Gadget.h

#ifndef GUI_UINT32GADGET
#define GUI_UINT32GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP GadgetBase;
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnUI32 12
	#define MAX_UI32 4294967295U
	#define MIN_UI32 0

	class UGLY_IMPEXP
	UInt32Gadget	:	
	public	GadgetBase
	{
	private:
						UInt32Gadget(		const UInt32Gadget& copy);//not implemented on purpose
		UInt32Gadget&	operator = (	const UInt32Gadget& assign);//not implemented on purpose
	public:
						UInt32Gadget(	uint32 paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~UInt32Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
