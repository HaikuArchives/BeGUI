//myFancyButton.h

#ifndef GUI_MYFANCYBUTTON
#define GUI_MYFANCYBUTTON
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyFancyButton
	{
	private:
		BString				mbsLabel;
							MyFancyButton(	const MyFancyButton& copy);//not implemented on purpose
		MyFancyButton&		operator = (	const MyFancyButton& assign);//not implemented on purpose
	public:
		BPictureButton *	mpBPictureButton;
		float				mfWidth;
		float				mfHeight;
							MyFancyButton(	const char * paramName, 
											const char * paramLabel, 
											uint32 paramMsg,
											LayoutMatrix * paramLayoutMatrix,
											rgb_color * paramHighColor = NULL,
											rgb_color * paramLowColor = NULL,
											rgb_color * paramViewColor = NULL,
											BFont * paramFont = NULL,
											uint32 paramBehavior = B_ONE_STATE_BUTTON,
											bool paramSetEnabled = true,
											int paramOnOff = B_CONTROL_OFF);
		virtual				~MyFancyButton();
	};
#endif