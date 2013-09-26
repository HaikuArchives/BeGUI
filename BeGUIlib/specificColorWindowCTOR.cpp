//specificColorWindowCTOR.cpp

#define BUILDING_LIB 1

#include "commonHeaders.h"
#include "DmenuMsg.h"
#include "DnumSpecificWindows.h"
#include "DcolorControlMessages.h"
#include "scrollingWindow.h"
#include "s2f.h"
#include "s2uint32.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "textItem.h"
#include "myStringDrawer.h"
#include "Preferences.h"
#include "myTextView.h"
#include "myListView.h"
#include "mySlider.h"
#include "myButton.h"
#include "gadgetBase.h"
#include "int8Gadget.h"
#include "uInt8Gadget.h"
#include "int16Gadget.h"
#include "uInt16Gadget.h"
#include "int32Gadget.h"
#include "uInt32Gadget.h"
#include "int64Gadget.h"
#include "uInt64Gadget.h"
#include "floatGadget.h"
#include "stringGadget.h"
#include "uInt32Control.h"
#include "stringControl.h"
#include "myPictureButton.h"
#include "myStatusBar.h"
#include "myRadioView.h"
#include "myRadioViewData.h"
#include "myStringView.h"
#include "myCheckBox.h"
#include "prefPanelWindow.h"
#include "warning.h"
#include "myroColour.h"
#include "dataNode.h"
#include "dataList.h"
#include "scrollView.h"
#include "verify.h"
#include "colorWell.h"
#include "myColorControl.h"
#include "floatControl.h"
#include "myPreferences.h"
#include "specificColorWindow.h"
#include "filterFloatNumeric.h"
#include "filterIntNumeric.h"
#include "filterUIntNumeric.h"
#include "stringBoundsBox.h"

const char * lScrollViewName[NUMSPECIFICWINDOWS] = 
{
	"scBUTTON",
	"scPICTURE",
	"scRADIOVIEW",
	"scCHECKBOX",
	"scSTATUSBAR",
	"scCOLORCONTROL",
	"scCOLORWELL",
	"scSPECIFICCOLORINT8GADGET",
	"scSPECIFICCOLORUINT8GADGET",
	"scSPECIFICCOLORINT16GADGET",
	"scSPECIFICCOLORUINT16GADGET",
	"scSPECIFICCOLORINT32GADGET",
	"scSPECIFICCOLORUINT32GADGET",
	"scSPECIFICCOLORINT64GADGET",
	"scSPECIFICCOLORUINT64GADGET",
	"scSPECIFICCOLORFLOATGADGET",
	"scSPECIFICCOLORSTRINGGADGET",
	"scSTRINGCONTROL",
	"scTEXTVIEW",
	"scSTRINGDRAWER",
	"scLISTVIEW",
	"scFLOATCONTROL",
	"scUINT32CONTROL",
	"scSLIDER"
};
//the following array is also duplicated in myPreferences.cpp
const char * lNamePrefFrame[NUMSPECIFICWINDOWS] = 
{
	"SPECIFICCOLORBUTTON",
	"SPECIFICCOLORPICTURE",
	"SPECIFICCOLORRADIOVIEW",
	"SPECIFICCOLORCHECKBOX",
	"SPECIFICCOLORSTATUSBAR",
	"SPECIFICCOLORCOLORCONTROL",
	"SPECIFICCOLORCOLORWELL",
	"SPECIFICCOLORINT8GADGET",
	"SPECIFICCOLORUINT8GADGET",
	"SPECIFICCOLORINT16GADGET",
	"SPECIFICCOLORUINT16GADGET",
	"SPECIFICCOLORINT32GADGET",
	"SPECIFICCOLORUINT32GADGET",
	"SPECIFICCOLORINT64GADGET",
	"SPECIFICCOLORUINT64GADGET",
	"SPECIFICCOLORFLOATGADGET",
	"SPECIFICCOLORSTRINGGADGET",
	"SPECIFICCOLORSTRINGCONTROL",
	"SPECIFICCOLORTEXTVIEW",
	"SPECIFICCOLORSTRINGDRAWER",
	"SPECIFICCOLORLISTVIEW",
	"SPECIFICCOLORFLOATCONTROL",
	"SPECIFICCOLORUINT32CONTROL",
	"SPECIFICCOLORSLIDER"
};


//ctor
SpecificColorWindow	::	SpecificColorWindow(	BRect paramBound,
												uint32 paramkind)
				: 
				ScrollingWindow(	paramBound, 
									myPrefs->lvwTitleStr[paramkind], 
									lScrollViewName[paramkind],
									lNamePrefFrame[paramkind],
									myPrefs->mpPreferenceSet,
									true,
									false),
				mui32Kind(paramkind),
				mpViewColorControl(NULL),
				mpHighColorControl(NULL),
				mpLowColorControl(NULL),
				mpBarColorControl(NULL),
				mpFillColorControl(NULL),
				mpViewColorWell(NULL),
				mpHighColorWell(NULL),
				mpLowColorWell(NULL),
				mpBarColorWell(NULL),
				mpFillColorWell(NULL),
				mpBarHeightGadget(NULL),
				mpColorWellWidthGadget(NULL),
				mpColorWellHeightGadget(NULL),
				mpThumbRadioView(NULL),
				mpCCLrv(NULL),
				mpSliderBarCB(NULL),
				mpSliderBarFillCB(NULL),
				mpDemoItem(NULL)
{
	sem_id calc_sem;
	if ((calc_sem = create_sem(1, "calc_sem")) < B_NO_ERROR)
	{
		warning(myPrefs->FailCreateSemaphore);
		return;
	}
	acquire_sem(calc_sem);
	try 
	{
		LayoutMatrix *	pholdTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
/////////////////////////////////////////////////////////////////////////////////////////////
		BFont * pBFont = new BFont(myPrefs->GetPreferredFont());
		float fontSize = pBFont->Size();
		fontSize *= 2;
		if (fontSize > 200)
		{
			fontSize = 200;
		}
		pBFont->SetSize(fontSize);
		pBFont->SetShear(122);
		//will need offset for demo--use a seperate matrix and get it's bottom
		MyStringDrawer * pMyStringDrawer = new MyStringDrawer(	"specificTitleMyStringDrawer", 
																myPrefs->lvwTitleStr[mui32Kind],
																pholdTitleLayoutMatrix, 
																pBFont);
/////////////////////////////
		if (!myPrefs->mbUseColorControl && !myPrefs->mbUseColorWell)
		{
			warning(myPrefs->noCCenabled);
		}
		LayoutMatrix * pholdViewCCLayoutMatrix = NULL;
		LayoutMatrix * pholdHighCCLayoutMatrix = NULL;
		LayoutMatrix * pholdLowCCLayoutMatrix = NULL;
		MyStringDrawer * pMyStringDrawerAXX = NULL;
		MyStringDrawer * pMyStringDrawerBXX = NULL;
		MyStringDrawer * pMyStringDrawerCXX = NULL;
		rgb_color color;//re-use for every setvalue
		if (myPrefs->mbUseColorControl)
		{
			pholdViewCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	/////////////////////////////////////////////////////////////////////////////////////
			pMyStringDrawerAXX = new MyStringDrawer(	"MyStringDrawerAXX", 
														myPrefs->ColorWindowHeading2, 
														pholdViewCCLayoutMatrix);
	////////////////////////////////////////////////////////////////////
			mpViewColorControl = new MyColorControl(	myPrefs->mCCL,
														"ColorControlAXX", 
														COLORCONTROL_VIEW,
														pholdViewCCLayoutMatrix);
			switch (mui32Kind)
			{
				case SPECIFIC_COLOR_BUTTON:
					myPrefs->GetPreferredMyButtonViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_PICTURE:
					myPrefs->GetPreferredMyPictureButtonViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_RADIOVIEW:
					myPrefs->GetPreferredMyRadioViewViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_CHECKBOX:
					myPrefs->GetPreferredMyCheckBoxViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STATUSBAR:
					myPrefs->GetPreferredMyStatusBarViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_SLIDER:
					myPrefs->GetPreferredMySliderViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_COLORCONTROL:
					myPrefs->GetPreferredMyColorControlViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_TEXTVIEW:
					myPrefs->GetPreferredMyTextViewViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_LISTVIEW:
					myPrefs->GetPreferredMyListViewViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT32CONTROL:
					myPrefs->GetPreferredUInt32ControlViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT8GADGET:
					myPrefs->GetPreferredInt8GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT8GADGET:
					myPrefs->GetPreferredUInt8GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT16GADGET:
					myPrefs->GetPreferredInt16GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT16GADGET:
					myPrefs->GetPreferredUInt16GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT32GADGET:
					myPrefs->GetPreferredInt32GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT32GADGET:
					myPrefs->GetPreferredUInt32GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT64GADGET:
					myPrefs->GetPreferredInt64GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT64GADGET:
					myPrefs->GetPreferredUInt64GadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_FLOATGADGET:
					myPrefs->GetPreferredFloatGadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGGADGET:
					myPrefs->GetPreferredStringGadgetViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_FLOATCONTROL:
					myPrefs->GetPreferredFloatControlViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGCONTROL:
					myPrefs->GetPreferredStringControlViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_COLORWELL:
					myPrefs->GetPreferredColorWellViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGDRAWER:
					myPrefs->GetPreferredMyStringDrawerViewColor(&color);
					mpViewColorControl->SetValue(color);
				break;
				default:
					warning(myPrefs->BadSpecColorKindView);
					throw;
				break;
			}
	/////////////////////
			pholdHighCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	////////////////////////////////
			pMyStringDrawerBXX = new MyStringDrawer(	"MyStringDrawerBXX", 
														myPrefs->ColorWindowHeading3, 
														pholdHighCCLayoutMatrix);
	/////////////////////////////////////////////
			mpHighColorControl = new MyColorControl(	myPrefs->mCCL,
														"HighColorControlBXX", 
														COLORCONTROL_HIGH,
														pholdHighCCLayoutMatrix);
			switch (mui32Kind)
			{
				case SPECIFIC_COLOR_BUTTON:
					myPrefs->GetPreferredMyButtonHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_PICTURE:
					myPrefs->GetPreferredMyPictureButtonHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_RADIOVIEW:
					myPrefs->GetPreferredMyRadioViewHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_CHECKBOX:
					myPrefs->GetPreferredMyCheckBoxHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STATUSBAR:
					myPrefs->GetPreferredMyStatusBarHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_SLIDER:
					myPrefs->GetPreferredMySliderHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_COLORCONTROL:
					myPrefs->GetPreferredMyColorControlHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_TEXTVIEW:
					myPrefs->GetPreferredMyTextViewHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_LISTVIEW:
					myPrefs->GetPreferredMyListViewHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT32CONTROL:
					myPrefs->GetPreferredUInt32ControlHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT8GADGET:
					myPrefs->GetPreferredInt8GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT8GADGET:
					myPrefs->GetPreferredUInt8GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT16GADGET:
					myPrefs->GetPreferredInt16GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT16GADGET:
					myPrefs->GetPreferredUInt16GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT32GADGET:
					myPrefs->GetPreferredInt32GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT32GADGET:
					myPrefs->GetPreferredUInt32GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT64GADGET:
					myPrefs->GetPreferredInt64GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT64GADGET:
					myPrefs->GetPreferredUInt64GadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_FLOATGADGET:
					myPrefs->GetPreferredFloatGadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGGADGET:
					myPrefs->GetPreferredStringGadgetHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_FLOATCONTROL:
					myPrefs->GetPreferredFloatControlHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGCONTROL:
					myPrefs->GetPreferredStringControlHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_COLORWELL:
					myPrefs->GetPreferredColorWellHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGDRAWER:
					myPrefs->GetPreferredMyStringDrawerHighColor(&color);
					mpHighColorControl->SetValue(color);
				break;
				default:
					warning(myPrefs->BadSpecColorKindHigh);
					throw;
				break;
			}
	//////////////////////////////////////////////////////////////
			pholdLowCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	///////////////////////////////////////////////////
			pMyStringDrawerCXX = new MyStringDrawer(	"MyStringDrawerCXX", 
														myPrefs->ColorWindowHeading4, 
														pholdLowCCLayoutMatrix);
	///////////////////////////////////////////////////////////////////
			mpLowColorControl = new MyColorControl(	myPrefs->mCCL,
													"LowColorControlCXX", 
													COLORCONTROL_LOW,
													pholdLowCCLayoutMatrix);
			switch (mui32Kind)
			{
				case SPECIFIC_COLOR_BUTTON:
					myPrefs->GetPreferredMyButtonLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_PICTURE:
					myPrefs->GetPreferredMyPictureButtonLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_RADIOVIEW:
					myPrefs->GetPreferredMyRadioViewLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_CHECKBOX:
					myPrefs->GetPreferredMyCheckBoxLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STATUSBAR:
					myPrefs->GetPreferredMyStatusBarLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_SLIDER:
					myPrefs->GetPreferredMySliderLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_COLORCONTROL:
					myPrefs->GetPreferredMyColorControlLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_TEXTVIEW:
					myPrefs->GetPreferredMyTextViewLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_LISTVIEW:
					myPrefs->GetPreferredMyListViewLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT32CONTROL:
					myPrefs->GetPreferredUInt32ControlLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT8GADGET:
					myPrefs->GetPreferredInt8GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT8GADGET:
					myPrefs->GetPreferredUInt8GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT16GADGET:
					myPrefs->GetPreferredInt16GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT16GADGET:
					myPrefs->GetPreferredUInt16GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT32GADGET:
					myPrefs->GetPreferredInt32GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT32GADGET:
					myPrefs->GetPreferredUInt32GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_INT64GADGET:
					myPrefs->GetPreferredInt64GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_UINT64GADGET:
					myPrefs->GetPreferredUInt64GadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_FLOATGADGET:
					myPrefs->GetPreferredFloatGadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGGADGET:
					myPrefs->GetPreferredStringGadgetLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_FLOATCONTROL:
					myPrefs->GetPreferredFloatControlLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGCONTROL:
					myPrefs->GetPreferredStringControlLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_COLORWELL:
					myPrefs->GetPreferredColorWellLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				case SPECIFIC_COLOR_STRINGDRAWER:
					myPrefs->GetPreferredMyStringDrawerLowColor(&color);
					mpLowColorControl->SetValue(color);
				break;
				default:
					warning(myPrefs->BadSpecColorKindLow);
					throw;
				break;
			}
		}
////////////////////////
		LayoutMatrix * pholdColorWellLayoutMatrix = NULL;
		if (myPrefs->mbUseColorWell)
		{
			pholdColorWellLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 3, this);//rows,columns
	//////////////
			mpViewColorWell = new ColorWell(	"ColorWellViewColorPref", 
												VIEW_COLOR,
												myPrefs->ColorWindowHeading5,
												this,
												pholdColorWellLayoutMatrix);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			mpHighColorWell = new ColorWell(	"ColorWellHighColorPref", 
												HIGH_COLOR,
												myPrefs->ColorWindowHeading6,
												this,
												pholdColorWellLayoutMatrix);
	////////////////////////////////////////////////////////////////////////////////////////////////////
			mpLowColorWell = new ColorWell(	"ColorWellLowColorPref", 
											LOW_COLOR,
											myPrefs->ColorWindowHeading7,
											this,
											pholdColorWellLayoutMatrix);
		}
///////////////////////////////////////////////////////////////////////
		LayoutMatrix * pholdDemoLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
//////////////////////////////////
		int32 kindDemo;
		void * pholdDemo;
		switch (mui32Kind)
		{
			case SPECIFIC_COLOR_BUTTON:
			{
				MyButton * pholdDemoMyButton = new MyButton(	"demoButton", 
																myPrefs->DemoButtonLabel, 
																DEMOBUTTONMSG,
																pholdDemoLayoutMatrix);
				kindDemo = KIND_MYBUTTON;
				pholdDemo = (void *)pholdDemoMyButton;
			}
			break;
			case SPECIFIC_COLOR_PICTURE:
			{
				BPicture * pOnPicture;
				BPicture * pOnDisabledPicture;
				BPicture * pOffPicture;
				BPicture * pOffDisabledPicture;
				BWindow * bWindow = new BWindow(	BRect(0, 0, 32, 32), //manditory for BPicture
													NULL, 
													B_DOCUMENT_WINDOW, 
													0);
				BView * bView = new BView(	BRect(0, 0, 32, 32), 
											NULL, 
											B_FOLLOW_NONE, 
											0);
//				BWindow bWindow(	BRect(0, 0, 32, 32), //manditory for BPicture
//									NULL, 
//									B_DOCUMENT_WINDOW, 
//									0);
//				BView bView(	BRect(0, 0, 32, 32), 
//								NULL, 
//								B_FOLLOW_NONE, 
//								0);
				bWindow->AddChild(bView);
				bView->BeginPicture(new BPicture);
				bView->MoveTo(5, 5);
				bView->StrokeRect(BRect(0,0,8,8));
				pOffPicture = bView->EndPicture();
				
				bView->BeginPicture(new BPicture);
				bView->MoveTo(10, 5);
				bView->StrokeRect(BRect(0,0,10,15));
				pOnPicture = bView->EndPicture();
				
				bView->BeginPicture(new BPicture);
				bView->MoveTo(2, 5);
				bView->FillRect(BRect(0,0,22,20));
				pOffDisabledPicture = bView->EndPicture();
				
				bView->BeginPicture(new BPicture);
				bView->MoveTo(1, 5);
				bView->FillRect(BRect(0,0,6,15));
				pOnDisabledPicture = bView->EndPicture();
				//bView.RemoveSelf();
				bWindow->Run();
				bWindow->PostMessage(B_QUIT_REQUESTED);
				MyPictureButton * pholdDemoMyPictureButton = new MyPictureButton(	BRect(0, 0, 32, 32),
																					"DemoPictureButton", 
																					pOffPicture,
																					pOnPicture,
																					pOffDisabledPicture,
																					pOnDisabledPicture,
																					DEMOPICTUREBUTTONMSG,
																					B_TWO_STATE_BUTTON,//B_ONE_STATE_BUTTON
																					pholdDemoLayoutMatrix);
				kindDemo = KIND_MYPICTUREBUTTON;
				pholdDemo = (void *)pholdDemoMyPictureButton;
			}
			break;
			case SPECIFIC_COLOR_RADIOVIEW:
			{
				BList * pBList = new BList();
				RadioViewData * pRadioViewDataOne = new RadioViewData(	'_one',
																		myPrefs->DemoRadio1Label,
																		pBList);
				RadioViewData * pRadioViewDataTwo = new RadioViewData(	'_two',
																		myPrefs->DemoRadio2Label,
																		pBList);
				RadioViewData * pRadioViewDataThree = new RadioViewData(	'thre',
																			myPrefs->DemoRadio3Label,
																			pBList);
				MyRadioView * pholdMyRadioView = new MyRadioView(	"demoRadio",
																	false,//true gives vertical orientation
																	pBList,
																	myPrefs->GetPreferredFont(),
																	pholdDemoLayoutMatrix);
				if (!pholdMyRadioView->Initialize())
				{
					warning(myPrefs->RadioViewFailInit);
					throw;
				}
				kindDemo = KIND_MYRADIOVIEW;
				pholdDemo = (void *)pholdMyRadioView;
			}
			break;
			case SPECIFIC_COLOR_CHECKBOX:
			{
				MyCheckBox * pholdCheckBox = new MyCheckBox(	"checkBox", 
																myPrefs->DemoCheckBoxLabel, 
																B_CONTROL_ON,
																'_one',
																pholdDemoLayoutMatrix);
				kindDemo = KIND_MYCHECKBOX;
				pholdDemo = (void *)pholdCheckBox;
			}
			break;
			case SPECIFIC_COLOR_STATUSBAR:
			{
				MyStatusBar * pholdStatusBar = new MyStatusBar(	"StatusBar", 
																myPrefs->DemoStatusBarLeadLabel, 
																myPrefs->DemoStatusBarTrailLabel,
																50,
																10.0,
																pholdDemoLayoutMatrix);
				kindDemo = KIND_MYSTATUSBAR;
				pholdDemo = (void *)pholdStatusBar;
			}
			break;
			case SPECIFIC_COLOR_SLIDER:
			{
				MySlider * pholdSlider = new MySlider(	BRect(1, 1, 65, 32), 
														"Slider",
														"Label",
														'Sldr',
														1,
														10,
														.5,
														pholdDemoLayoutMatrix);
				kindDemo = KIND_MYSLIDER;
				pholdDemo = (void *)pholdSlider;
			}
			break;
			case SPECIFIC_COLOR_COLORCONTROL:
			{
				MyColorControl * pholdColorControl = new MyColorControl(	myPrefs->mCCL,
																			"ColorControl", 
																			DEMOCOLORCONTROLMSG,
																			pholdDemoLayoutMatrix);
			
				kindDemo = KIND_MYCOLORCONTROL;
				pholdDemo = (void *)pholdColorControl;
			}
			break;
			case SPECIFIC_COLOR_TEXTVIEW:
			{
				float leftOffset;
				float baseline;
				float width;
				float height;
				if (!StringBoundsBox(	myPrefs->TextGadgetLabel,
										&width,
										&height,
										&leftOffset,
										&baseline))
				{
					throw;
				}
				MyTextView * pholdTextView = new MyTextView(	"textView", 
																NULL, 
																width,
																6 * height,//allow 6 lines visible
																pholdDemoLayoutMatrix);
				rgb_color textColor;
				myPrefs->GetPreferredMyTextViewHighColor(&textColor);
				pholdTextView->SetFontAndColor(myPrefs->GetPreferredFont(), B_FONT_ALL, &textColor);
				pholdTextView->SetText(myPrefs->TextGadgetLabel);
				kindDemo = KIND_MYTEXTVIEW;
				pholdDemo = (void *)pholdTextView;
			}
			break;
			case SPECIFIC_COLOR_LISTVIEW:
			{
				DataList * dataList = new DataList();
				DataNode * nodeOne = new DataNode(myPrefs->ListViewSample1);
				dataList->AddItem(nodeOne);
				DataNode * nodeTwo = new DataNode(myPrefs->ListViewSample2);
				dataList->AddItem(nodeTwo);
				DataNode * nodeThree = new DataNode(myPrefs->ListViewSample3);
				dataList->AddItem(nodeThree);
				MyListView * mlv = new MyListView(	"mlvTitle",
													dataList,
													'selc',
													'invc',
													B_SINGLE_SELECTION_LIST,
													pholdDemoLayoutMatrix);
				kindDemo = KIND_MYLISTVIEW;
				pholdDemo = (void *)mlv;
			}
			break;
			case SPECIFIC_COLOR_INT8GADGET:
			{
				Int8Gadget * pholdInt8Gadget = new Int8Gadget(	MIN_I8,
																"int8Gadget",
																myPrefs->GetInt8GadgetLabel,
																0,
																this,
																pholdDemoLayoutMatrix);
				kindDemo = KIND_INT8GADGET;
				pholdDemo = (void *)pholdInt8Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterIntNumeric);
				pholdInt8Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_UINT8GADGET:
			{
				UInt8Gadget * pholdUInt8Gadget = new UInt8Gadget(	MAX_UI8,
																	"uInt8Gadget",
																	myPrefs->GetUInt8GadgetLabel,
																	0,
																	this,
																	pholdDemoLayoutMatrix);
				kindDemo = KIND_UINT8GADGET;
				pholdDemo = (void *)pholdUInt8Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterUIntNumeric);
				pholdUInt8Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_INT16GADGET:
			{
				Int16Gadget * pholdInt16Gadget = new Int16Gadget(	MIN_I16,
																	"int16Gadget",
																	myPrefs->GetInt16GadgetLabel,
																	0,
																	this,
																	pholdDemoLayoutMatrix);
				kindDemo = KIND_INT16GADGET;
				pholdDemo = (void *)pholdInt16Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterIntNumeric);
				pholdInt16Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_UINT16GADGET:
			{
				UInt16Gadget * pholdUInt16Gadget = new UInt16Gadget(	MAX_UI16,
																		"uInt16Gadget",
																		myPrefs->GetUInt16GadgetLabel,
																		0,
																		this,
																		pholdDemoLayoutMatrix);
				kindDemo = KIND_UINT16GADGET;
				pholdDemo = (void *)pholdUInt16Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterUIntNumeric);
				pholdUInt16Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_INT32GADGET:
			{
				Int32Gadget * pholdInt32Gadget = new Int32Gadget(	MIN_I32,
																	"int32Gadget",
																	myPrefs->GetInt32GadgetLabel,
																	0,
																	this,
																	pholdDemoLayoutMatrix);
				kindDemo = KIND_INT32GADGET;
				pholdDemo = (void *)pholdInt32Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterIntNumeric);
				pholdInt32Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_UINT32GADGET:
			{
				UInt32Gadget * pholdUInt32Gadget = new UInt32Gadget(	MAX_UI32,
																		"uInt32Gadget",
																		myPrefs->GetUInt32GadgetLabel,
																		0,
																		this,
																		pholdDemoLayoutMatrix);
				kindDemo = KIND_UINT32GADGET;
				pholdDemo = (void *)pholdUInt32Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterUIntNumeric);
				pholdUInt32Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_INT64GADGET:
			{
				Int64Gadget * pholdInt64Gadget = new Int64Gadget(	MIN_I64,
																	"int64Gadget",
																	myPrefs->GetInt64GadgetLabel,
																	0,
																	this,
																	pholdDemoLayoutMatrix);
				kindDemo = KIND_INT64GADGET;
				pholdDemo = (void *)pholdInt64Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterIntNumeric);
				pholdInt64Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_UINT64GADGET:
			{
				UInt64Gadget * pholdUInt64Gadget = new UInt64Gadget(	MAX_UI64,
																		"uInt64Gadget",
																		myPrefs->GetUInt64GadgetLabel,
																		0,
																		this,
																		pholdDemoLayoutMatrix);
				kindDemo = KIND_UINT64GADGET;
				pholdDemo = (void *)pholdUInt64Gadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterUIntNumeric);
				pholdUInt64Gadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_FLOATGADGET:
			{
				FloatGadget * pholdFloatGadget = new FloatGadget(	(float)12.34,
																	"floatGadget",
																	myPrefs->GetFloatGadgetLabel,
																	0,
																	this,
																	pholdDemoLayoutMatrix);
				kindDemo = KIND_FLOATGADGET;
				pholdDemo = (void *)pholdFloatGadget;
				BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																B_LOCAL_SOURCE, 
																'_KYD', 
																filterFloatNumeric);
				pholdFloatGadget->AddFilter(bmfDemo);
			}
			break;
			case SPECIFIC_COLOR_STRINGGADGET:
			{
				StringGadget * pholdStringGadget = new StringGadget(	myPrefs->GetStringGadgetLabel,
																		"stringGadget",
																		myPrefs->GetStringGadgetLabel,
																		0,
																		this,
																		pholdDemoLayoutMatrix);
				kindDemo = KIND_STRINGGADGET;
				pholdDemo = (void *)pholdStringGadget;
			}
			break;
			case SPECIFIC_COLOR_UINT32CONTROL:
			{
				UInt32Control * pholdUInt32Control = new UInt32Control(	123,
																		"uInt32Control", 
																		myPrefs->UInt32ControlLabel, 
																		DEMOINTCONTROLMSG,
																		0,
																		pholdDemoLayoutMatrix);
				kindDemo = KIND_UINT32CONTROL;
				pholdDemo = (void *)pholdUInt32Control;
			}
			break;
			case SPECIFIC_COLOR_FLOATCONTROL:
			{
				FloatControl * pholdFloatControl = new FloatControl(	(float)1.23,
																		"floatControl", 
																		myPrefs->FloatControlLabel, 
																		DEMOFLOATCONTROLMSG,
																		0,
																		pholdDemoLayoutMatrix);
				kindDemo = KIND_FLOATCONTROL;
				pholdDemo = (void *)pholdFloatControl;
			}
			break;
			case SPECIFIC_COLOR_STRINGCONTROL:
			{
				StringControl * pholdStringControl = new StringControl(	"stringControlName", 
																		myPrefs->StringControlLabel, 
																		NULL, 
																		DEMOSTRINGCONTROLMSG,
																		0,
																		pholdDemoLayoutMatrix);
				kindDemo = KIND_STRINGCONTROL;
				pholdDemo = (void *)pholdStringControl;
			}
			break;
			case SPECIFIC_COLOR_COLORWELL:
			{
				ColorWell * pholdColorWell = new ColorWell(	"colorWell", 
															NO_COLOR,
															myPrefs->DemoRoLabel,
															this,
															pholdDemoLayoutMatrix);
				kindDemo = KIND_COLORWELL;
				pholdDemo = (void *)pholdColorWell;
			}
			break;
			case SPECIFIC_COLOR_STRINGDRAWER:
			{
				MyStringDrawer * pholdMyStringDrawer = new MyStringDrawer(	"stringDrawer", 
																			myPrefs->DemoTextItemText, 
																			pholdDemoLayoutMatrix);
				kindDemo = KIND_STRINGDRAWER;
				pholdDemo = (void *)pholdMyStringDrawer;
			}
			break;
			default:
				warning(myPrefs->BadSpecItemKind);
				throw;
			break;
		}
		mpDemoItem = pholdDemo;
/////////////////////
		LayoutMatrix *	pholdBarTitleLayoutMatrix = NULL;
		LayoutMatrix *	pholdBarCCLayoutMatrix = NULL;
		LayoutMatrix * pholdBarCWLayoutMatrix = NULL;
		LayoutMatrix * pholdBarHLayoutMatrix = NULL;
		LayoutMatrix * pholdColorWellWHLayoutMatrix = NULL;
		LayoutMatrix * pholdSliderLayoutMatrix = NULL;
		LayoutMatrix * pholdFillCCLayoutMatrix = NULL;
		LayoutMatrix * pholdFillCWLayoutMatrix = NULL;
		LayoutMatrix * pholdCCLLayoutMatrix = NULL;
///////////////////////////
		if (mui32Kind == SPECIFIC_COLOR_STATUSBAR)
		{
			pholdBarTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
////////////////////////////////////////////////////////////////
			BFont * pBFontBar = new BFont(myPrefs->GetPreferredFont());
			float fontSize = pBFontBar->Size();
			fontSize *= 2;
			if (fontSize > 200)
			{
				fontSize = 200;
			}
			pBFontBar->SetSize(fontSize);
			pBFontBar->SetShear(122);
			//will need offset for demo--use a seperate matrix and get it's bottom
			MyStringDrawer * pBarMyStringDrawer = new MyStringDrawer(	"specificTitleBarMyStringDrawer", 
																		myPrefs->BarColorTitle,
																		pholdBarTitleLayoutMatrix, 
																		pBFontBar);
//////////////////////////////////////////////////
			if (myPrefs->mbUseColorControl)
			{
				pholdBarCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	///////////////////////////////////////////////////////////////////////////////////
				MyStringDrawer * pBarMyStringDrawerAXX = new MyStringDrawer(	"BarMyStringDrawerAXX", 
																				myPrefs->BarCCLabel, 
																				pholdBarCCLayoutMatrix);
	////////////////////////////////////////////////////////////////////
				mpBarColorControl = new MyColorControl(	myPrefs->mCCL,
														"barColorControl", 
														BARCOLORCONTROL,
														pholdBarCCLayoutMatrix);
				myPrefs->GetPreferredMyBarStatusColor(&color);
				mpBarColorControl->SetValue(color);
			}
//////////////////////////////////////
			if (myPrefs->mbUseColorWell)
			{
				pholdBarCWLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
	///////////////////////////////////////////
				mpBarColorWell = new ColorWell(	"ColorWellViewColorPref", 
												BAR_COLOR,
												myPrefs->BarCWLabel,
												this,
												pholdBarCWLayoutMatrix);
			}
///////////////////////////////////////////
			pholdBarHLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
//////////////////////////////////////////////////////////////////////////
			mpBarHeightGadget = new FloatGadget(	myPrefs->GetPreferredBarHeight(),
													"BarHeightFloatGadget", 
													myPrefs->EnterBarHeightLabel,
													0,
													this,
													pholdBarHLayoutMatrix);
				BMessageFilter * bmfBHDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
																	B_LOCAL_SOURCE, 
																	'_KYD', 
																	filterFloatNumeric);
				mpBarHeightGadget->AddFilter(bmfBHDemo);
		}
/////////////////////////////////////////////////////////////////
		else if (mui32Kind == SPECIFIC_COLOR_COLORCONTROL)
		{
			pholdCCLLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
//////////////////////////////////////////////////////////////////////////
			BFont * pCCLFont = new BFont(myPrefs->GetPreferredFont());
			float fontSize = pCCLFont->Size();
			fontSize *= 1.5;
			if (fontSize > 200)
			{
				fontSize = 200;
			}
			pCCLFont->SetSize(fontSize);
			MyStringDrawer * pCCLMyStringDrawer = new MyStringDrawer(	"CCLMyStringDrawer", 
																		myPrefs->ColorControlKind,
																		pholdCCLLayoutMatrix, 
																		pCCLFont);
			BList * bl = new BList();
			RadioViewData * pRVD4x64 = new RadioViewData(	CCL4x64RV,
															myPrefs->CC_4x64_Cell,
															bl,
															(B_CELLS_4x64 == myPrefs->mCCL));
			RadioViewData * pRVD8x32 = new RadioViewData(	CCL8x32RV,
															myPrefs->CC_8x32_Cell,
															bl,
															(B_CELLS_8x32 == myPrefs->mCCL));
			RadioViewData * pRVD16x16 = new RadioViewData(	CCL16x16RV,
															myPrefs->CC_16x16_Cell,
															bl,
															(B_CELLS_16x16 == myPrefs->mCCL));
			RadioViewData * pRVD32x8 = new RadioViewData(	CCL32x8RV,
															myPrefs->CC_32x8_Cell,
															bl,
															(B_CELLS_32x8 == myPrefs->mCCL));
			RadioViewData * pRVD64x4 = new RadioViewData(	CCL64x4RV,
															myPrefs->CC_64x4_Cell,
															bl,
															(B_CELLS_64x4 == myPrefs->mCCL));
			mpCCLrv = new MyRadioView(	"CCLRadioView",
										false,
										bl,
										myPrefs->GetPreferredFont(),
										pholdCCLLayoutMatrix);
			if (!mpCCLrv->Initialize())
			{
				warning(myPrefs->RadioViewFailInit);
				throw;
			}
//////////////////////////////////////////////////////////////////////////
		}
		else if (mui32Kind == SPECIFIC_COLOR_SLIDER)
		{
			pholdBarTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
////////////////////////////////////////////////////////////////
			BFont * pBFontBar = new BFont(myPrefs->GetPreferredFont());
			float fontSize = pBFontBar->Size();
			fontSize *= 2;
			if (fontSize > 200)
			{
				fontSize = 200;
			}
			pBFontBar->SetSize(fontSize);
			pBFontBar->SetShear(122);
			//will need offset for demo--use a seperate matrix and get it's bottom
			MyStringDrawer * pBarMyStringDrawer = new MyStringDrawer(	"specificTitleBarMyStringDrawer", 
																		myPrefs->BarColorTitle,
																		pholdBarTitleLayoutMatrix, 
																		pBFontBar);
//////////////////////////////////////////////////
			if (myPrefs->mbUseColorControl)
			{
				pholdBarCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	///////////////////////////////////////////////////////////////////////////////////
				MyStringDrawer * pBarMyStringDrawerAXX = new MyStringDrawer(	"BarMyStringDrawerAXX", 
																				myPrefs->BarCCLabel, 
																				pholdBarCCLayoutMatrix);
	////////////////////////////////////////////////////////////////////
				mpBarColorControl = new MyColorControl(	myPrefs->mCCL,
														"barColorControl", 
														BARCOLORCONTROL,
														pholdBarCCLayoutMatrix);
				myPrefs->GetPreferredMyBarStatusColor(&color);
				mpBarColorControl->SetValue(color);
			}
//////////////////////////////////////
			if (myPrefs->mbUseColorWell)
			{
				pholdBarCWLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
	///////////////////////////////////////////
				mpBarColorWell = new ColorWell(	"ColorWellViewColorPref", 
												BAR_COLOR,
												myPrefs->BarCWLabel,
												this,
												pholdBarCWLayoutMatrix);
			}
////////////////////////////////////////
			if (myPrefs->mbUseColorControl)
			{
				pholdFillCCLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
	///////////////////////////////////////////////////////////////////////////////////
				MyStringDrawer * pFillMSD = new MyStringDrawer(	"FillMSD", 
																myPrefs->FillCCLabel, 
																pholdFillCCLayoutMatrix);
	////////////////////////////////////////////////////////////////////
				mpFillColorControl = new MyColorControl(	myPrefs->mCCL,
															"fillColorControl", 
															FILLCOLORCONTROL,
															pholdFillCCLayoutMatrix);
				myPrefs->GetPreferredMyBarFillSliderColor(&color);
				mpFillColorControl->SetValue(color);
			}
//////////////////////////////////////
			if (myPrefs->mbUseColorWell)
			{
				pholdFillCWLayoutMatrix = new LayoutMatrix(BESTSIZE, 1, 1, this);//rows,columns
	///////////////////////////////////////////
				mpFillColorWell = new ColorWell(	"ColorWellViewColorPref", 
													FILL_COLOR,
													myPrefs->FillCWLabel,
													this,
													pholdFillCWLayoutMatrix);
			}
///////////////////////////////////////////
			pholdSliderLayoutMatrix = new LayoutMatrix(BESTSIZE, 3, 1, this);//rows,columns
//////////////////////////////////////
			mpSliderBarCB = new MyCheckBox(	"SliderBarCheckBox", 
											myPrefs->ColorSliderBarCBLabel,
											myPrefs->mui32ColorSliderBar,
											SLIDERBARCB,
											pholdSliderLayoutMatrix);
			mpSliderBarFillCB = new MyCheckBox(	"SliderBarCheckBoxFill", 
												myPrefs->FillSliderBarCBLabel,
												myPrefs->mui32FillSliderBar,
												SLIDERBARFILLCB,
												pholdSliderLayoutMatrix);
			BList * bl = new BList();
			RadioViewData * pRVDOne = new RadioViewData(	THUMB_RECT,
															myPrefs->DemoRadioLabelThumbRect,
															bl,
															(B_BLOCK_THUMB == myPrefs->GetPreferredThumbStyle()));
			RadioViewData * pRVDTwo = new RadioViewData(	THUMB_TRI,
															myPrefs->DemoRadioLabelThumbTri,
															bl,
															(B_TRIANGLE_THUMB == myPrefs->GetPreferredThumbStyle()));
			mpThumbRadioView = new MyRadioView(	"thumbRadioView",
												true,
												bl,
												myPrefs->GetPreferredFont(),
												pholdSliderLayoutMatrix);
			if (!mpThumbRadioView->Initialize())
			{
				warning(myPrefs->RadioViewFailInit);
				throw;
			}
		}
/////////////////////////////////////////////////////////////////////////////////////
		else if (mui32Kind == SPECIFIC_COLOR_COLORWELL)
		{
			pholdColorWellWHLayoutMatrix = new LayoutMatrix(BESTSIZE, 2, 1, this);//rows,columns
////////////////////////////////////////////////////////////////
			mpColorWellWidthGadget = new UInt8Gadget(	myPrefs->GetPreferredColorWellWidth(),
														"ColorWellWidthGadget",
														myPrefs->EnterColorWellWidthLabel,
														0,
														this,
														pholdColorWellWHLayoutMatrix);
			BMessageFilter * bmfW = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
														B_LOCAL_SOURCE, 
														'_KYD', 
														filterUIntNumeric);
			mpColorWellWidthGadget->AddFilter(bmfW);
//////////////////////////////////////////////////////////////
			mpColorWellHeightGadget = new UInt8Gadget(	myPrefs->GetPreferredColorWellHeight(),
														"ColorWellHeightGadget",
														myPrefs->EnterColorWellHeightLabel,
														0,
														this,
														pholdColorWellWHLayoutMatrix);
			BMessageFilter * bmfH = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
														B_LOCAL_SOURCE, 
														'_KYD', 
														filterUIntNumeric);
			mpColorWellHeightGadget->AddFilter(bmfH);
////////////////////
		}
/////////////////////////////////////////////////////////////
		release_sem(calc_sem);
		pholdTitleLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, MATRIXVERTICALOFFSET, calc_sem);
		float bottom = pholdTitleLayoutMatrix->mfBottom;
		float right = MATRIXHORIZONTALOFFSET;
		if (myPrefs->mbUseColorControl)
		{
			pholdViewCCLayoutMatrix->Calc(right, bottom, calc_sem);
			pholdHighCCLayoutMatrix->Calc(pholdViewCCLayoutMatrix->mfRight, bottom, calc_sem);
			pholdLowCCLayoutMatrix->Calc(pholdHighCCLayoutMatrix->mfRight, bottom, calc_sem);
			bottom = pholdLowCCLayoutMatrix->mfBottom;
			if (bottom < pholdHighCCLayoutMatrix->mfBottom)
			{
				bottom = pholdHighCCLayoutMatrix->mfBottom;
			}
			if (bottom < pholdViewCCLayoutMatrix->mfBottom)
			{
				bottom = pholdViewCCLayoutMatrix->mfBottom;
			}
			right = pholdLowCCLayoutMatrix->mfRight;
		}
		float cwRight = MATRIXHORIZONTALOFFSET;
		if (myPrefs->mbUseColorWell)
		{
			pholdColorWellLayoutMatrix->Calc(cwRight, bottom, calc_sem);
			bottom = pholdColorWellLayoutMatrix->mfBottom;
			cwRight = pholdColorWellLayoutMatrix->mfRight;
		}
		if (cwRight > right)
		{
			right = cwRight;
		}
		pholdDemoLayoutMatrix->Calc(right, pholdTitleLayoutMatrix->mfBottom, calc_sem);
		if (	(mui32Kind == SPECIFIC_COLOR_STATUSBAR)
				||
				(mui32Kind == SPECIFIC_COLOR_SLIDER))
		{
			pholdBarTitleLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, bottom, calc_sem);
			if (myPrefs->mbUseColorControl)
			{
				pholdBarCCLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pholdBarTitleLayoutMatrix->mfBottom, calc_sem);
				bottom = pholdBarCCLayoutMatrix->mfBottom;
			}
			if (myPrefs->mbUseColorWell)
			{
				pholdBarCWLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, bottom, calc_sem);
				bottom = pholdBarCWLayoutMatrix->mfBottom;
			}
			float ccRightSB = cwRight;
			float cwRightSB = cwRight;
			if (myPrefs->mbUseColorControl)
			{
				ccRightSB = pholdBarCCLayoutMatrix->mfRight;
			}
			if (myPrefs->mbUseColorWell)
			{
				cwRightSB = pholdBarCWLayoutMatrix->mfRight;
			}
			if (ccRightSB > cwRightSB)
			{
				cwRightSB = ccRightSB;
			}
			if (mui32Kind == SPECIFIC_COLOR_STATUSBAR)
			{
				pholdBarHLayoutMatrix->Calc(cwRightSB, pholdBarTitleLayoutMatrix->mfBottom, calc_sem);
			}
			else //if (mui32Kind == SPECIFIC_COLOR_SLIDER)
			{
				if (myPrefs->mbUseColorControl)
				{
					pholdFillCCLayoutMatrix->Calc(cwRightSB, pholdBarTitleLayoutMatrix->mfBottom, calc_sem);
					bottom = pholdFillCCLayoutMatrix->mfBottom;
				}
				else
				{
					bottom = pholdBarTitleLayoutMatrix->mfBottom;
				}
				if (myPrefs->mbUseColorWell)
				{
					pholdFillCWLayoutMatrix->Calc(cwRightSB, bottom, calc_sem);
				}
				float fccRightSB = cwRightSB;
				float fcwRightSB = cwRightSB;
				if (myPrefs->mbUseColorControl)
				{
					fccRightSB = pholdFillCCLayoutMatrix->mfRight;
				}
				if (myPrefs->mbUseColorWell)
				{
					fcwRightSB = pholdFillCWLayoutMatrix->mfRight;
				}
				if (fccRightSB > fcwRightSB)
				{
					fcwRightSB = fccRightSB;
				}
				pholdSliderLayoutMatrix->Calc(fcwRightSB + 3, pholdBarTitleLayoutMatrix->mfBottom, calc_sem);
			}
		}
		else if (mui32Kind == SPECIFIC_COLOR_COLORWELL)
		{
			pholdColorWellWHLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, bottom, calc_sem);
		}
		else if (mui32Kind == SPECIFIC_COLOR_COLORCONTROL)
		{
			pholdCCLLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, bottom + 3, calc_sem);
		}
	}
	catch (...)
	{
		warning(myPrefs->CaughtSpecificColorWindowCTOR);
		release_sem(calc_sem);
		throw;
	}
	try 
	{
		BMenuItem *	menuItem;
		BMenu * APPMenu = new BMenu(myPrefs->AppMenuLabel);
		menuItem = new BMenuItem(	myPrefs->AboutMenuLabel, 
									new BMessage(ABOUT_SPECIFICCOLORWINDOW));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->CloseWindow, 
									new BMessage(B_QUIT_REQUESTED));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->QuitMenuLabel, 
									new BMessage(QUIT_APP));
		APPMenu->AddItem(menuItem);
		mpMenuBar->AddItem(APPMenu);
	}
	catch(...) 
	{
		throw;
	}
}//end