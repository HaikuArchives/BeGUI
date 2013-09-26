//filterHexNumeric.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "truncateString.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "filterHexNumeric.h"
#include "DcarriageReturn.h"

filter_result 
filterHexNumeric(	BMessage * message,
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
				(keypress[0] == 'a')
				||
				(keypress[0] == 'b')
				||
				(keypress[0] == 'c')
				||
				(keypress[0] == 'd')
				||
				(keypress[0] == 'e')
				||
				(keypress[0] == 'f')
				||
				(keypress[0] == 'A')
				||
				(keypress[0] == 'B')
				||
				(keypress[0] == 'C')
				||
				(keypress[0] == 'D')
				||
				(keypress[0] == 'E')
				||
				(keypress[0] == 'F')
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