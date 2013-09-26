//int32Gadget.h

#ifndef GUI_INT32GADGET
#define GUI_INT32GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnI32 12
	#define MAX_I32 2147483647L
	#define MIN_I32 (-2147483648L)

	class UGLY_IMPEXP
	Int32Gadget	:	
	public	GadgetBase
	{
	private:
						Int32Gadget(		const Int32Gadget& copy);//not implemented on purpose
		Int32Gadget&	operator = (	const Int32Gadget& assign);//not implemented on purpose
	public:
						Int32Gadget(	int32 paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~Int32Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
