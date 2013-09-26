//testItem.h

#ifndef GUI_TEXTITEM
#define GUI_TEXTITEM
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	
	class UGLY_IMPEXP LayoutMatrix;
	
	class UGLY_IMPEXP
	TextItem
	{
	private:
						TextItem(	const TextItem& copy);//not implemented on purpose
		TextItem&		operator = (	const TextItem& assign);//not implemented on purpose
	public:
		const char *	mpText;
		float			mfTop;
		float			mfLeft;
						TextItem(	const char * paramText,
									LayoutMatrix * paramLayoutMatrix);
		virtual			~TextItem();
	};
#endif