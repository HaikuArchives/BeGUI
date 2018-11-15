//specificColorWindow.h

#ifndef SPECIFICCOLORWINDOW
#define SPECIFICCOLORWINDOW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP MyRadioView;
	class UGLY_IMPEXP ColorWell;
	class UGLY_IMPEXP MyColorControl;
	class UGLY_IMPEXP ScrollingWindow;
	class UGLY_IMPEXP FloatGadget;
	class UGLY_IMPEXP UInt8Gadget;
	#define DEMOBUTTONMSG 'dbm '
	#define DEMOPICTUREBUTTONMSG 'dpbm'
	#define DEMOCHECKBOXMSG 'dcbm'
	#define DEMOCOLORCONTROLMSG 'dccm'
	#define DEMOINTCONTROLMSG 'digm'
	#define DEMOFLOATCONTROLMSG 'dfgm'
	#define DEMOSTRINGCONTROLMSG 'dsgm'
	#define ABOUT_SPECIFICCOLORWINDOW 'abcw'
	#define THUMB_RECT 'ThbR'
	#define THUMB_TRI 'ThbT'
	#define SLIDERBARCB 'SlBr'
	#define SLIDERBARFILLCB 'SlBf'
	#define CCL4x64RV '4x64'
	#define CCL8x32RV '8x32'
	#define CCL16x16RV ' 6x6'
	#define CCL32x8RV '32x8'
	#define CCL64x4RV '64x4'

	class UGLY_IMPEXP
	SpecificColorWindow	:
	public ScrollingWindow
	{
	private:
		uint32					mui32Kind;
								SpecificColorWindow(	const SpecificColorWindow& copy);//not implemented on purpose
		SpecificColorWindow&	operator = (	const SpecificColorWindow& assign);//not implemented on purpose
	public:
		MyColorControl *		mpViewColorControl;
		MyColorControl *		mpHighColorControl;
		MyColorControl *		mpLowColorControl;
		MyColorControl *		mpBarColorControl;
		MyColorControl *		mpFillColorControl;
		ColorWell *				mpViewColorWell;
		ColorWell *				mpHighColorWell;
		ColorWell *				mpLowColorWell;
		ColorWell *				mpBarColorWell;
		ColorWell *				mpFillColorWell;
		FloatGadget *			mpBarHeightGadget;
		UInt8Gadget *			mpColorWellWidthGadget;
		UInt8Gadget *			mpColorWellHeightGadget;
		MyRadioView *			mpThumbRadioView;
		MyRadioView *			mpCCLrv;
		MyCheckBox *			mpSliderBarCB;
		MyCheckBox *			mpSliderBarFillCB;
		void *					mpDemoItem;
								SpecificColorWindow(	BRect paramBound,
														uint32 kind);
		virtual					~SpecificColorWindow();
		virtual bool			QuitRequested(	void);
		virtual void			MessageReceived(	BMessage *	paramMessage);
		void					ResetDemo(	void);
	};
#endif