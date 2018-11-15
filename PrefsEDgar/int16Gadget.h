//int16Gadget.h

#ifndef GUI_INT16GADGET
#define GUI_INT16GADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP GadgetBase;
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnI16 7
	#define MAX_I16 32767
	#define MIN_I16 (-32768)

	class UGLY_IMPEXP
	Int16Gadget	:	
	public	GadgetBase
	{
	private:
						Int16Gadget(		const Int16Gadget& copy);//not implemented on purpose
		Int16Gadget&	operator = (	const Int16Gadget& assign);//not implemented on purpose
	public:
						Int16Gadget(	int16 i16paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~Int16Gadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
