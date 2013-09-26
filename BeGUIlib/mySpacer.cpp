//mySpacer.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "mySpacer.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "warning.h"
#include "DnumSpecificWindows.h"
#include "Preferences.h"
#include "myPreferences.h"

MySpacer	::	MySpacer(	float paramPreferredWidth,
							float paramPreferredHeight,
							LayoutMatrix * paramLayoutMatrix,
							bool paramSAMEFromWidest)
			:	mfPreferredWidth(paramPreferredWidth),
				mfPreferredHeight(paramPreferredHeight),
				mbSAMEFromWidest(paramSAMEFromWidest)
{
	//does not get added to children of layoutmatrix!
	try
	{
		LayoutMatrixItem * lmi = new LayoutMatrixItem(	(void *)this,
														paramLayoutMatrix,
														KIND_MYSPACER);
		paramLayoutMatrix->mpLayoutMatrixItems->AddItem((void *)lmi);
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
}//end


MySpacer	::	~MySpacer()
{
	//leaving blank
}//end


void
MySpacer	::	ResizeTo(	const float paramWidest,
							const float paramTallest)
{
	if (mbSAMEFromWidest)
	{
		mfPreferredWidth = paramWidest;
		mfPreferredHeight = paramTallest;
	}
}//end


void
MySpacer	::	MyGetPreferredSize(	float * paramWidth,
									float * paramHeight) const
{
	*paramWidth = mfPreferredWidth;
	*paramHeight = mfPreferredHeight;
}//end