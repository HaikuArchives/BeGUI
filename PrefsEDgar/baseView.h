//baseView.h

#ifndef GUI_BASEVIEW
#define GUI_BASEVIEW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif

	class UGLY_IMPEXP
	BaseView	:	
	public BView 
	{
	private:
						BaseView(	const BaseView& copy);//not implemented on purpose
		BaseView&		operator = (	const BaseView& assign);//not implemented on purpose
	public:
		BList *			mpTextItemList;
		BList *			mpStringViewList;
						BaseView(	BRect area,
									const char * paramName);
		virtual			~BaseView();
		virtual void	AttachedToWindow(	void);
		virtual void	Draw(	BRect );
	};
#endif