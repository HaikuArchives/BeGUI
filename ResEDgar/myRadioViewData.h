//MyRadioViewData.h

#ifndef GUI_MYRADIOVIEWDATA
#define GUI_MYRADIOVIEWDATA
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif

	class UGLY_IMPEXP
	RadioViewData
	{
	private:
						RadioViewData(	const RadioViewData& copy);//not implemented on purpose
		RadioViewData&	operator = (	const RadioViewData& assign);//not implemented on purpose
	public:
		BMessage *		mpMsg;
		const char *	mLabel;
		bool			mbSelected;
						RadioViewData(	uint32 paramMessageValue, 
										const char * paramLabel,
										BList * paramList,
										bool paramSelected = false);
		virtual			~RadioViewData();
	};
#endif