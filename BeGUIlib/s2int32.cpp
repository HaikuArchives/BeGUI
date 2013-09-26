//a function to inspect a string to see if it is a valid int32, then convert it if it is
//s2int32.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "s2int32.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"

status_t 
s2int32(	const char * in, 
			int32 * paramFillMe)
{
	/*Joerg (Stegemenn??) said to try using strtoul, so here is a first approximation
	It seems to me we need a whole new range of these:
	uint32 strtouint32(char, char *, int);
	int32 strtoint32(char, char *, int);
	int64 strtoint64(char, char *, int);
	etc.
	I'm not even sure in reality that the following is correct for uint32!
	*/
	//first we must test for negativity in the string--strtoul() does not do this
	uint32 len = strlen(in);//known not utf8
	for (	uint32 i = 0;
			i < len;
			i++)
	{
		if (!(isspace(in[i])))//just skip over whitespaces
		{
			i = len;
		}
	}
	char ** cpError = NULL;
	long result = strtol(in, cpError, 10);
	if (errno == ERANGE)
	{
		warning(myPrefs->S2I32OutOfRange);
		return(B_ERROR);
	}
	else if (cpError)
	{
		warning(*cpError);
		warning(myPrefs->S2I32Invalid);
		return(B_ERROR);
	}
	else 
	{
		*paramFillMe = result;
		return (B_OK);
	}
}//end