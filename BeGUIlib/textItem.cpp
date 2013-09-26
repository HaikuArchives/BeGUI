//textItem.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "textItem.h"
#include "layoutMatrix.h"

TextItem	::	TextItem(	const char * paramText,
							LayoutMatrix * paramLayoutMatrix)
			:	mpText(paramText)
{
	if (paramLayoutMatrix)
	{
		paramLayoutMatrix->AddToDraw((void *)this);
	}
}//end



TextItem	::	~TextItem()
{
	//leaving blank
}//end