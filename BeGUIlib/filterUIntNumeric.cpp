//filterUIntNumeric.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "truncateString.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "filterUIntNumeric.h"
#include "DcarriageReturn.h"

filter_result 
filterUIntNumeric(	BMessage * message,
					BHandler **,// target, 
					BMessageFilter *)// messageFilter)
{
	const char * keypress;
	bool dispatch = false;
	if (message->FindString("bytes", &keypress) == B_OK) 
	{
		if	(	(keypress[0] == '0')
				||
				(keypress[0] == '1')
				||
				(keypress[0] == '2')
				||
				(keypress[0] == '3')
				||
				(keypress[0] == '4')
				||
				(keypress[0] == '5')
				||
				(keypress[0] == '6')
				||
				(keypress[0] == '7')
				||
				(keypress[0] == '8')
				||
				(keypress[0] == '9')
				||
				(keypress[0] == '+')
				||
				(keypress[0] == 8)
				||
				(keypress[0] == 127)
				||
				(keypress[0] == 28)
				||
				(keypress[0] == 29)
				||
				(keypress[0] == 4)
				||
				(keypress[0] == 1)
			)
		{
			dispatch = true;
		}
		else if (keypress[0] == 0xa) 
		{
			message->what = CARRIAGE_RETURN;
			dispatch = true;
		}
	}
	else 
	{
		warning(myPrefs->MessageFindBytes);
	}
	if (dispatch)
	{
		return B_DISPATCH_MESSAGE;
	}
	else
	{
		return B_SKIP_MESSAGE;
	}
}//end