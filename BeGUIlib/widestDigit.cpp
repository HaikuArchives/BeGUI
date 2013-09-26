//widestDigit.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "widestDigit.h"

float
WidestDigit(	void)
{
	BView bv(BRect(0, 0, 32, 32), NULL, B_FOLLOW_NONE, 0);
	bv.SetFont(myPrefs->GetPreferredFont());
	float holdFa = bv.StringWidth("0");//known not utf8
	float holdFb = bv.StringWidth("1");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("2");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("3");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("4");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("5");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("6");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("7");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("8");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("9");//known not utf8
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("+");
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	holdFb = bv.StringWidth("-");
	if (holdFb > holdFa)
	{
		holdFa = holdFb;
	}
	return holdFa;
}//end