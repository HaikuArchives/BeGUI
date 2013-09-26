//fontData.cpp
/*
I borrowed this stuff and made some small changes, see:

This archive includes code to help in manipulating BFont objects in
BMessages.  The code is contained in the files FFont.cpp and FFont.h,
which can be copied for use in your own projects. ...

See the file FFont.html for more information. ...

-- Dianne Hackborn <hackbod@lucent.com>, Sept. 22, 1997
*/

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "fontData.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"


FontData		::	 ~FontData()
{
//leaving blank
}//end


FontData		::	 FontData(	void)
{
	try
	{
		BFont *	tempBFont = new BFont();
		mfSize = tempBFont->Size();
		mfShear = tempBFont->Shear();
		mfRotation = tempBFont->Rotation();
		mui32Flags = tempBFont->Flags();
		mui16Face = tempBFont->Face();
		mui8Spacing = tempBFont->Spacing();
		mui32FamilyAndStyle = tempBFont->FamilyAndStyle();
		delete tempBFont;
	}
	catch(...)
	{
		warning(myPrefs->FailMemory);
		mfSize = 12;
		mfShear = 90;
		mfRotation = 0;
		mui32Flags = 0;
		mui16Face = 0;
		mui8Spacing = 2;
		mui32FamilyAndStyle = 131072;
	}
}//end


FontData		::	 FontData(	const BFont * paramFont)
{
	mfSize = paramFont->Size();
	mfShear = paramFont->Shear();
	mfRotation = paramFont->Rotation();
	mui32Flags = paramFont->Flags();
	mui16Face = paramFont->Face();
	mui8Spacing = paramFont->Spacing();
	mui32FamilyAndStyle = paramFont->FamilyAndStyle();
}//end