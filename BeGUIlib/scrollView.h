//scrollView.h

#ifndef GUI_SCROLLVIEW
#define GUI_SCROLLVIEW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif

	class UGLY_IMPEXP
	ScrollView	:	
	public BView 
	{
	private:
						ScrollView(	const ScrollView& copy);//not implemented on purpose
		ScrollView&		operator = (	const ScrollView& assign);//not implemented on purpose
	public:
		BList *			mpTextItemList;
		BList *			mpStringViewList;
						ScrollView(	BRect area);
		virtual			~ScrollView();
		virtual void	AttachedToWindow(	void);
		virtual void	Draw(	BRect );
	};
#endif