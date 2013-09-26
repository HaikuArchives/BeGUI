//dataNode.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "warning.h"
#include "dataNode.h"
#include "dataList.h"


DataNode	::	DataNode(const char * paramText) 
			:	mpText(new BString(paramText))
{
	//leaving blank
}//end


DataNode	::	~DataNode() 
{
	free(mpText);
}//end


const char *
DataNode	::	GetText(	void) const
{
	return mpText->String();
}//end