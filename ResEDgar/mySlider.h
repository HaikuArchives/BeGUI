//mySlider.h

#ifndef GUI_MYSLIDER
#define GUI_MYSLIDER
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MySlider	:	
	public	BSlider
	{
	private:
						MySlider(	const MySlider& copy);//not implemented on purpose
		MySlider&		operator = (	const MySlider& assign);//not implemented on purpose
	public:
						MySlider(	BRect paramFrame,
									const char * paramName,
									const char * paramLabel,
									uint32 paramMessageValue,
									int32 paramMinValue,
									int32 paramMaxValue,
									float paramPosition,
									LayoutMatrix * paramLayoutMatrix);
		virtual			~MySlider();
		virtual void	AttachedToWindow(	void);
	};
#endif