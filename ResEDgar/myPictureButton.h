//myPictureButton.h

#ifndef GUI_MYPICTUREBUTTON
#define GUI_MYPICTUREBUTTON
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyPictureButton	:	
	public	BPictureButton
	{
	private:
							MyPictureButton(	const MyPictureButton& copy);//not implemented on purpose
		MyPictureButton&	operator = (	const MyPictureButton& assign);//not implemented on purpose
	public:
							MyPictureButton(	BRect paramRect, 
												const char * paramName, 
												BPicture * paramOffPicture,
												BPicture * paramOnPicture,
												BPicture * paramOffDisabledPicture,
												BPicture * paramOnDisabledPicture,
												uint32 paramMsg,
												uint32 paramBehavior,
												LayoutMatrix * paramLayoutMatrix,
												bool paramSetEnabled = true,
												int paramOnOff = B_CONTROL_OFF);
		virtual				~MyPictureButton();
		virtual void		AttachedToWindow(	void);
	};
#endif