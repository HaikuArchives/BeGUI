//int64Gadget.h

#ifndef GUI_INT64GADGET
#define GUI_INT64GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnI64 21
	#define MAX_I64 9223372036854775807LL
	#define MIN_I64 (-9223372036854775808LL)

	class UGLY_IMPEXP
	Int64Gadget	:	
	public	GadgetBase
	{
	private:
						Int64Gadget(		const Int64Gadget& copy);//not implemented on purpose
		Int64Gadget&	operator = (	const Int64Gadget& assign);//not implemented on purpose
	public:
						Int64Gadget(	int64 i64paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~Int64Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
