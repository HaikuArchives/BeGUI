//myColorControl.h

#ifndef GUI_MYCOLORCONTROL
#define GUI_MYCOLORCONTROL
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyColorControl	:	
	public	BColorControl
	{
	private:
						MyColorControl(	const MyColorControl& copy);//not implemented on purpose
		MyColorControl&	operator = (	const MyColorControl& assign);//not implemented on purpose
	public:
						MyColorControl(	color_control_layout paramColorControlLayout,
										const char * paramName,
										uint32 paramMsg,
										LayoutMatrix * paramLayoutMatrix, 
										float paramCellSize = 1,
										bool paramUseOffscreen = true);
		virtual			~MyColorControl();
		virtual void	AttachedToWindow(	void);
	};
#endif