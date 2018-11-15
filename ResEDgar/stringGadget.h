//stringGadget.h

#ifndef GUI_STRINGGADGET
#define GUI_STRINGGADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP GadgetBase;
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	StringGadget	:	
	public	GadgetBase
	{
	private:
						StringGadget(		const StringGadget& copy);//not implemented on purpose
		StringGadget&	operator = (	const StringGadget& assign);//not implemented on purpose
	public:
						StringGadget(	const char * paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~StringGadget();
		virtual void 	MessageReceived(	BMessage * paramMessage);
		virtual void 	AttachedToWindow();
	};
#endif
