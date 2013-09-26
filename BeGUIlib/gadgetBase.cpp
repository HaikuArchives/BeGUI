//gadgetBase.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DnumSpecificWindows.h"
#include "myStringView.h"
#include "gadgetBase.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "warning.h"

GadgetBase	::	~GadgetBase() 
{
	//leaving blank
};//end


//ctor
GadgetBase	::	GadgetBase(	const char * paramName,
							const char * paramLabel,
							BLooper * paramMessageTarget,
							bool paramMakeFocus)
			: 	BTextView(	BRect(0, 0, 32, 32),
							paramName,
							BRect(0, 0, 32, 32),
							B_FOLLOW_NONE,
							B_WILL_DRAW | B_NAVIGABLE),
				mfTop(0),
				mpMessageTarget(paramMessageTarget),
				mpLabel(NULL),
				mpLabelView(NULL),
				mbMakeFocus(paramMakeFocus)
{
	try
	{
		if (paramLabel)
		{
			mpLabelView = new MyStringView(	"GadgetBaseView", 
											paramLabel);
			mpLabel = new BString(paramLabel);
		}
	}
	catch (...)
	{
		warning(myPrefs->FailMemory);
		return;
	}
}//end

void
GadgetBase	::	SetTop(	const float paramTop)
{
	mfTop = paramTop;
}//end


float
GadgetBase	::	GetTop(	void) const
{
	return mfTop;
}//end


void
GadgetBase	::	SetLeft(	const float paramLeft)
{
	mfLeft = paramLeft;
}//end


float
GadgetBase	::	GetLeft(	void) const
{
	return mfLeft;
}//end