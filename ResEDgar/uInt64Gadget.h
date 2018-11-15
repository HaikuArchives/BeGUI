//int64Gadget.h

#ifndef GUI_UINT64GADGET
#define GUI_UINT64GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnUI64 22
	#define MAX_UI64 18446744073709551615ULL
	#define MIN_UI64 0

	class UGLY_IMPEXP
	UInt64Gadget	:	
	public	GadgetBase
	{
	private:
						UInt64Gadget(		const UInt64Gadget& copy);//not implemented on purpose
		UInt64Gadget&	operator = (	const UInt64Gadget& assign);//not implemented on purpose
	public:
						UInt64Gadget(	uint64 ui64paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~UInt64Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
