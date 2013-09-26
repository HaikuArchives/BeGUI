//dataList.h

#ifndef DATALIST
#define DATALIST
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP DataNode;
	
	class UGLY_IMPEXP
	DataList 
	{
	private:
				DataList(	const DataList& copy);//not implemented on purpose
	DataList&	operator = (	const DataList& assign);//not implemented on purpose
	public:
		BList *	mpList;
		int32	i32Kind;
				DataList(	void);
				~DataList();
		bool	AddItem(	DataNode * paramItem);
		int32	CountItems(	void) const 
					{
						if (mpList) 
						{
							return (mpList->CountItems());
						}
						else 
						{
							return (0);
						}
					};
	};
#endif