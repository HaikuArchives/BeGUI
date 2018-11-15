//myListView.h 

#ifndef GUI_MYLISTVIEW
#define GUI_MYLISTVIEW
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP DataList;
	class UGLY_IMPEXP LayoutMatrix;

	class UGLY_IMPEXP
	MyListView	:	
	public	BListView
	{
	private:
						MyListView(	const MyListView& copy);//not implemented on purpose
		MyListView&		operator = (	const MyListView& assign);//not implemented on purpose
	public:
		float		mfWidth;//only reason these are public is so LayoutMatrixItem may use them
		float		mfHeight;//maybe it should be a friend of this class?????
						MyListView(	const char * paramName,
									DataList * paramDataList,
									uint32 paramSelectMsg,
									uint32 paramInvokeMsg,
									list_view_type paramSelectType,
									LayoutMatrix * paramLayoutMatrix);
		virtual			~MyListView();
		virtual void	AttachedToWindow();
		virtual void	MyGetPreferredSize(	float * paramWidth,
											float * paramHeight);
	};
#endif