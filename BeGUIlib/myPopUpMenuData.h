//myPopUpMenuData.h

#ifndef GUI_MYPOPUPMENUDATA
#define GUI_MYPOPUPMENUDATA
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif

	class UGLY_IMPEXP
	PopUpMenuData
	{
	private:
						PopUpMenuData(	const PopUpMenuData& copy);//not implemented on purpose
		PopUpMenuData&	operator = (	const PopUpMenuData& assign);//not implemented on purpose
	public:
		const char *	mpItemName;
		BString *		mLabel;
		bool			mbSetMark;
						PopUpMenuData(	const char * paramLabel,
										BList * paramList,
										bool paramSetMark = false);
		virtual			~PopUpMenuData();
	};
#endif