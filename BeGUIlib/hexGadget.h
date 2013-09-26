//hexGadget.h

#ifndef GUI_HEXGADGET
#define GUI_HEXGADGET
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define DIGITSnHEX 16//debug figure this out

	class UGLY_IMPEXP
	HexGadget	:	
	public	GadgetBase
	{
	private:
						HexGadget(		const HexGadget& copy);//not implemented on purpose
		HexGadget&	operator = (	const HexGadget& assign);//not implemented on purpose
	public:
						HexGadget(	const char * paramInitValue,
									const char * paramName, 
									const char * paramLabel, 
									float paramTextViewWidth,
									BLooper * paramMessageTarget,
									LayoutMatrix * paramLayoutMatrix,
									bool paramMakeFocus = false);
		virtual			~HexGadget();
		virtual void 	AttachedToWindow();
		virtual void 	MessageReceived(	BMessage * paramMessage);
	};
#endif
