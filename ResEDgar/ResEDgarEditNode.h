//editNode.h

#ifndef EDITNODE
#define EDITNODE
	
	class 
	EditNode
	{
	private:
						EditNode(	const EditNode& copy);//not implemented on purpose
		EditNode&		operator = (	const EditNode& assign);//not implemented on purpose
	public:
						EditNode(	StringGadget * paramSG,
									int32 paramResourceID,
									BList * paramList,
									const char * paramResourceName);
						~EditNode();
		StringGadget *	mpSG;
		const char *	mpResourceName;
		int32			mi32ResourceID;
	};
#endif