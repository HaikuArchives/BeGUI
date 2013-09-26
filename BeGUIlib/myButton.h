//myButton.h

#ifndef GUI_MYBUTTON
#define GUI_MYBUTTON
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyButton	:	
	public	BButton
	{
	private:
		BString			mbsLabel;
						MyButton(	const MyButton& copy);//not implemented on purpose
		MyButton&		operator = (	const MyButton& assign);//not implemented on purpose
	public:
						MyButton(	const char * paramName, 
									const char * paramLabel,
									uint32 paramMsg,
									LayoutMatrix * paramLayoutMatrix,
									bool paramSetEnabled = true,
									int paramOnOff = B_CONTROL_OFF);
		virtual			~MyButton();
		virtual void	AttachedToWindow(	void);
		virtual void	MyGetPreferredSize(	float * paramWidth,
											float * paramHeight);
	};
#endif