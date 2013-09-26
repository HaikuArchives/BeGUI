//int8Gadget.h

#ifndef GUI_INT8GADGET
#define GUI_INT8GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnI8 5
	#define MAX_I8 127
	#define MIN_I8 (-128)

	class UGLY_IMPEXP
	Int8Gadget	:	
	public	GadgetBase
	{
	private:
						Int8Gadget(		const Int8Gadget& copy);//not implemented on purpose
		Int8Gadget&		operator = (	const Int8Gadget& assign);//not implemented on purpose
	public:
						Int8Gadget(	int8 i8paramInitValue,
									const char * paramName, 
									const char * paramLabel, 
									float paramTextViewWidth,
									BLooper * paramMessageTarget,
									LayoutMatrix * paramLayoutMatrix,
									bool paramMakeFocus = false);
		virtual			~Int8Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
