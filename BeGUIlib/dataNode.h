//dataNode.h

#ifndef DATANODE
#define DATANODE
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif

	class UGLY_IMPEXP
	DataNode 
	{
	private:
		BString	*		mpText;
						DataNode(	const DataNode& copy);//not implemented on purpose
		DataNode&		operator = (	const DataNode& assign);//not implemented on purpose
	public:
						DataNode(const char * paramText);
		virtual			~DataNode();
		const char *	GetText(	void) const;
	};
#endif