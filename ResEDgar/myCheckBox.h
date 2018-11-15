//myCheckBox.h

#ifndef GUI_MYCHECKBOX
#define GUI_MYCHECKBOX
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyCheckBox	:	
	public	BCheckBox
	{
	private:
						MyCheckBox(	const MyCheckBox& copy);//not implemented on purpose
		MyCheckBox&		operator = (	const MyCheckBox& assign);//not implemented on purpose
	public:
						MyCheckBox(	const char * paramName, 
									const char * paramLabel,
									int32 paramValue,
									uint32 paramMsg,
									LayoutMatrix * paramLayoutMatrix);
		virtual			~MyCheckBox();
		virtual void	AttachedToWindow(	void);
	};
#endif