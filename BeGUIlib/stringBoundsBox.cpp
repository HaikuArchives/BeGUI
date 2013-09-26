//stringBoundsBox.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "warning.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "stringBoundsBox.h"
#include "utf8_char_len.h"

int32 StringBoundsBox(	const char * paramString,
						float * paramWidth,
						float * paramHeight,
						float * paramLeftOffset,
						float * paramBaseline,
						BFont * paramFont)
{
	if (!paramString) 
	{
		return NOJOB;
	}
	BFont * useFont;
	if (paramFont)
	{
		useFont	= paramFont;
	}
	else
	{
		useFont = myPrefs->GetPreferredFont();
	}
	uint32 len = 0; 
	for (uint32 i = 0; paramString[i] != '\0'; len++) 
	{
		i += utf8_char_len(paramString[i]); 
	}
	if (len > RECTARRAYLENGTH) 
	{
		warning(myPrefs->StringTooLongToMeasure);
		return BADJOB;
	}
	BRect arrayRect[RECTARRAYLENGTH];
	escapement_delta ed = {0,0};
	useFont->GetBoundingBoxesAsString(	paramString,
										len, 
										B_SCREEN_METRIC,
										&ed,
										arrayRect);
	*paramWidth = 0;
	*paramHeight = 0;
	float biggestAscent = 0;
	float biggestDescent = 0;
	uint32 i;
	for (i = 0; i < len; i++ ) 
	{
		float localAscent = 0;
		if (arrayRect[i].top < 0) 
		{
			localAscent = -arrayRect[i].top;
			/*ascents are negative offsets from baseline*/
			if (localAscent > biggestAscent) 
			{
				biggestAscent = localAscent;
			}
		}
		float localDescent = 0;
		if (arrayRect[i].bottom > 0) 
		{
			localDescent = arrayRect[i].bottom;
			if (localDescent > biggestDescent) 
			{
				biggestDescent = localDescent;
			}
		}
	}
	*paramLeftOffset = arrayRect[0].left;
	*paramBaseline = biggestAscent;
	*paramWidth = arrayRect[--i].right + 1;
	/*must add 1 as zero is a full pixel wide*/
	*paramHeight = biggestAscent + biggestDescent + 1;
	return GOODJOB;
}//end