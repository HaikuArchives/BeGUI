//verify.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "verify.h"
#include "Preferences.h"
#include "myPreferences.h"

bool
Verify(	const char * msg)
{
	BAlert *myAlert = new BAlert(	"VerifyTitle", 
									msg,
									myPrefs->VerifyCancel, 
									myPrefs->VerifyDoNot, 
									myPrefs->VerifyDo, 
									B_WIDTH_FROM_LABEL, 
									B_OFFSET_SPACING, 
									B_WARNING_ALERT);
	myAlert->SetShortcut(0, B_ESCAPE); 
	int32 button_value = myAlert->Go();
	if (button_value == 2) return true;
	return false;
}//end
	