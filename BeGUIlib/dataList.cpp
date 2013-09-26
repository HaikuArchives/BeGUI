//dataList.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "dataList.h"
#include "dataNode.h"

DataList	::	DataList(	void) 
			:	mpList(new BList())
{
	//leaving blank
}//end  DataList()


DataList	::	~DataList() 
{
	if (mpList->CountItems()) 
	{
		DataNode * node;
		for (	int32 i = 0;
				//#pragma warn_possunwant off
				node = (DataNode *)mpList->ItemAt(i);
				//#pragma warn_possunwant reset
				i++) 
		{
			delete node;
		}
	}
	delete mpList;
}//end


bool 
DataList	::	AddItem(	DataNode * paramItem) 
{
	return(mpList->AddItem((void *)paramItem));
}//end