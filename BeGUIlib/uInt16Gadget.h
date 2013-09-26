//int16Gadget.h

#ifndef GUI_UINT16GADGET
#define GUI_UINT16GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnUI16 7
	#define MAX_UI16 65535
	#define MIN_UI16 0

	class UGLY_IMPEXP
	UInt16Gadget	:	
	public	GadgetBase
	{
	private:
						UInt16Gadget(		const UInt16Gadget& copy);//not implemented on purpose
		UInt16Gadget&	operator = (	const UInt16Gadget& assign);//not implemented on purpose
	public:
						UInt16Gadget(	uint16 ui16paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~UInt16Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
