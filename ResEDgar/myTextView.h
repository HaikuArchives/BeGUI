//myTextView.h

#ifndef GUI_MYTEXTVIEW
#define GUI_MYTEXTVIEW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyTextView	:	
	public	BTextView
	{
	private:
						MyTextView(	const MyTextView& copy);//not implemented on purpose
		MyTextView&		operator = (	const MyTextView& assign);//not implemented on purpose
	public:
		float			mfWidth;//only reason these are public is so LayoutMatrixItem may use them
		float			mfHeight;//maybe it should be a friend of this class?????
						MyTextView(	const char * paramName, 
									const char * paramText,
									float paramMaxWidth,
									float paramMaxHeight,
									LayoutMatrix * paramLayoutMatrix);
		virtual			~MyTextView();
		virtual void	AttachedToWindow(	void);
		virtual void	MyGetPreferredSize(	float * paramWidth,
											float * paramHeight);
	};
#endif