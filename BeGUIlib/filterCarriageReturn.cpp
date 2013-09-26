//filterCarriageReturn.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "truncateString.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "filterCarriageReturn.h"
#include "DcarriageReturn.h"

filter_result 
filterCarriageReturn(	BMessage * message, 
						BHandler **,// target, 
						BMessageFilter *)// messageFilter)
{
	const char * keypress;
	if (message->FindString("bytes", &keypress) == B_OK) 
	{
		if (keypress[0] == 0xa) 
		{
			message->what = CARRIAGE_RETURN;
		}
	}
	else 
	{
		warning(myPrefs->MessageFindBytes);
	}
	return B_DISPATCH_MESSAGE;
}//end