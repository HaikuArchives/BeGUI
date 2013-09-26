//a function to inspect a string to see if it is a valid float, then convert it if it is

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "s2f.h"
//#include "warning.h"

status_t 
s2f(	const char * in, 
		float *paramFillMe)
{
	//this is horrible--no error checking debug
	*paramFillMe = atof(in);
	return B_OK;
}//end