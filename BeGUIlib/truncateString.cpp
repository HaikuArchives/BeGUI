//truncateString.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "truncateString.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "stringBoundsBox.h"
#include "utf8_char_len.h"

bool
TruncateString(	const char * paramString,
				char * paramIntoBuf,
				float paramMaxPixelWidth,
				BFont * paramFont)
{
	float leftOffset;
	float baseline;
	float truncStringPixLen;
	float height;
	if (!StringBoundsBox(	paramString,
							&truncStringPixLen,
							&height,
							&leftOffset,
							&baseline,
							paramFont))
	{
		throw;
	}
	if (truncStringPixLen <= paramMaxPixelWidth)
	{
		strcpy(paramIntoBuf, paramString);
		return true;
	}
	uint32 stringLen = 0; 
	for (uint32 i = 0; paramString[i] != '\0'; stringLen++)
	{
    	i += utf8_char_len(paramString[i]); 
    }
	if (stringLen < 5)
	{
		warning(myPrefs->truncShort);
		return false;
	}
	uint32 stringCenter = stringLen / 2;
	bool tooLong = true;
	uint32 remove = 1;
	char * tempBuf = new char[stringLen];
	do
	{
		tempBuf[0] = '\0';
		uint32 scminus = (stringCenter - remove);
		strncpy(tempBuf, paramString, scminus);
		tempBuf[scminus] = '\0';
		strcat(tempBuf, "…");
		strcat(tempBuf, &paramString[(stringCenter + remove)]);
		if (!StringBoundsBox(	tempBuf,
								&truncStringPixLen,
								&height,
								&leftOffset,
								&baseline,
								paramFont))
		{
			throw;
		}
		if (truncStringPixLen <= paramMaxPixelWidth)
		{
			tooLong = false;
			strcpy(paramIntoBuf, tempBuf);
		}
		else
		{
			remove++;
		}
	}
	while (tooLong);
	delete [] tempBuf;
	return true;
}//end