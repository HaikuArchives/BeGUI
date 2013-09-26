//smallerRect.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "commonHeaders.h"
#include "smallerRect.h"

bool
RectASmallerRectB(	BRect paramA,
					BRect paramB)
{
	double a;
	double b;
	a = paramA.Width() * paramA.Height();
	b = paramB.Width() * paramB.Height();
	if (a < b) 
	{
		return true;
	}
	else
	{
		return false;
	}
}//end