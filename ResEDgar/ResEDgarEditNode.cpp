//editNode.cpp

#include "commonHeaders.h"
#include "gadgetBase.h"
#include "stringGadget.h"
#include "warning.h"
#include "ResEDgarEditNode.h"

EditNode	::	EditNode(	StringGadget * paramSG,
							int32 paramResourceID,
							BList * paramList,
							const char * paramResourceName)
			:	mpSG(paramSG),
				mi32ResourceID(paramResourceID),
				mpResourceName(paramResourceName)
{
	paramList->AddItem((void *)this);
}//end


EditNode	::	~EditNode()
{
	//left blank
}//end