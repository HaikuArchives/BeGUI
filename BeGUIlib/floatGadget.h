//floatGadget.h

#ifndef GUI_FLOATGADGET
#define GUI_FLOATGADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP GadgetBase;
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnFLOAT 32//debug figure this out

	class UGLY_IMPEXP
	FloatGadget	:	
	public	GadgetBase
	{
	private:
						FloatGadget(		const FloatGadget& copy);//not implemented on purpose
		FloatGadget&	operator = (	const FloatGadget& assign);//not implemented on purpose
	public:
						FloatGadget(	float paramInitValue,
										const char * paramName, 
										const char * paramLabel, 
										float paramTextViewWidth,
										BLooper * paramMessageTarget,
										LayoutMatrix * paramLayoutMatrix,
										bool paramMakeFocus = false);
		virtual			~FloatGadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
