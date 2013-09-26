//warning.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"

//blocking BAlert!
void 
warning(	const char * paramWarningText)
{
	try 
	{
		BAlert * myAlert = new BAlert(	"WarnTitle",
										paramWarningText,
										myPrefs->WarningOKLabel,
										NULL,
										NULL,
										B_WIDTH_FROM_LABEL, 
										B_OFFSET_SPACING, 
										B_WARNING_ALERT);
		myAlert->Go();
	}
	catch (...)
	{
		printf("%s\n", paramWarningText);
	}
}//end