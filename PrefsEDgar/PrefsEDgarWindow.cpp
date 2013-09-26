//PrefsEDgarPrefsEDgarWindow.cpp

#include "commonHeaders.h"
#include "DtinySnooze.h"
#include "DnumSpecificWindows.h"
#include "Preferences.h"
#include "myPreferences.h"
#include "warning.h"
#include "scrollingWindow.h"
#include "simpleWindow.h"
#include "layoutMatrixItem.h"
#include "layoutMatrix.h"
#include "myButton.h"
#include "myFancyButton.h"
#include "myCheckBox.h"
#include "textItem.h"
#include "dataList.h"
#include "dataNode.h"
#include "myStringDrawer.h"
#include "myPopUpMenu.h"
#include "myPopUpMenuData.h"
#include "myPictureButton.h"
#include "myColorControl.h"
#include "colorWell.h"
#include "myStatusBar.h"
#include "myRadioView.h"
#include "myListView.h"
#include "myRadioViewData.h"
#include "myTextView.h"
#include "mySpacer.h"
#include "mySlider.h"
#include "DmenuMsg.h"
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
#include "hexGadget.h"
#include "stringGadget.h"
#include "floatControl.h"
#include "uInt32Control.h"
#include "stringControl.h"
#include "verify.h"
#include "s2f.h"
#include "PrefsEDgarWindow.h"
#include "PrefsEDgarApp.h"
#include "DcarriageReturn.h"
#include "filterFloatNumeric.h"
#include "filterIntNumeric.h"
#include "filterUIntNumeric.h"
#include "filterHexNumeric.h"

//ctor
PrefsEDgarWindow	::	PrefsEDgarWindow(	void)
					: 
						ScrollingWindow(	myApp->preferredPrefsEDgarWindowRect, 
											myApp->PrefsEDgarWindowTitle, 
											"PrefsEDgarView",
											"PrefsEDgarWindowFrame",
											myApp->mpPreferenceSet)
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
////////////////////////////////////////////////
		LayoutMatrix *	pTitleLayoutMatrix = new LayoutMatrix(BESTSIZE, 5, 1, this);//rows,columns
///////////////////////////////////////////////////////////////////////////////
		BFont * pBFont = new BFont(myPrefs->GetPreferredFont());
		float fontSize = pBFont->Size();
		fontSize *= 2.5;
		if (fontSize > 200)
		{
			fontSize = 200;
		}
		pBFont->SetSize(fontSize);
		pBFont->SetShear(122);
		MyStringDrawer * pMSDtitle = new MyStringDrawer(	NULL, 
															myApp->ProgramName,
															pTitleLayoutMatrix,
															pBFont);
	/////////////////////////////////////////////////////////
		BFont * pBFontsub = new BFont(myPrefs->GetPreferredFont());
		fontSize = pBFontsub->Size();
		fontSize *= 1.5;
		if (fontSize > 200)
		{
			fontSize = 200;
		}
		pBFontsub->SetSize(fontSize);
		MyStringDrawer * pMSDsubTitle = new MyStringDrawer(	NULL, 
															myApp->ProgramNameSubTitle,
															pTitleLayoutMatrix,
															pBFontsub);
	///////////////////////////////////////////////////////////////////////
		MyStringDrawer * pMyStringDrawer = new MyStringDrawer(	NULL, 
																myPrefs->DemoTextItemText,
																pTitleLayoutMatrix);
	//////////////////////////////////////////////////////////////
		MyColorControl * pColorControl = new MyColorControl(	myPrefs->mCCL,
																NULL, 
																'a123',
																pTitleLayoutMatrix);
	////////////////////////////////////////////////////////////////////
		ColorWell * pColorWell = new ColorWell(	NULL, 
												'b123',
												myPrefs->DemoRoLabel,
												this,
												pTitleLayoutMatrix);
///////////////////////////////////////////////////////////////////////////////////////////
		LayoutMatrix * pDemoLayoutMatrix = new LayoutMatrix(BESTSIZE, 10, 1, this);//rows,columns
//////////////////////////////////
		rgb_color rgbH;
		rgbH.red = 180;
		rgbH.green = 0;
		rgbH.blue = 0;
		rgb_color rgbL;
		rgbL.red = 20;
		rgbL.green = 100;
		rgbL.blue = 100;
		rgb_color rgbV;
		rgbV.red = 200;
		rgbV.green = 200;
		rgbV.blue = 244;
		BFont * font = new BFont(myPrefs->GetPreferredFont());
		MyFancyButton * pMyFancyButton = new MyFancyButton(	NULL,
															"Fancy Button",
															'x123',
															pDemoLayoutMatrix,
															&rgbH,
															&rgbL,
															&rgbV,
															font,
															B_TWO_STATE_BUTTON,
															true,
															B_CONTROL_OFF);
		MyFancyButton * pMFBDisabled = new MyFancyButton(	NULL,
															"Fancy Button",
															'x123',
															pDemoLayoutMatrix,
															&rgbH,
															&rgbL,
															&rgbV,
															font,
															B_TWO_STATE_BUTTON,
															false,
															B_CONTROL_OFF);
		delete font;
////////////////////////////////////////////////////////////////////////////
		BString bs(myPrefs->DemoButtonLabel);
		bs += "…";
		MyButton * pDemoMyButton = new MyButton(	NULL, 
													bs.String(), 
													'c123',
													pDemoLayoutMatrix);
	///////////////////////////////////////////////////////////////////////
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
		bWindow->AddChild(bView);
		bView->BeginPicture(new BPicture);
		{
			bView->StrokeRect(BRect(0,0,32,32));
			rgb_color rgb;
			rgb.red = 225;
			rgb.green = 225;
			rgb.blue = 225;
			bView->SetHighColor(rgb);
			bView->FillRect(BRect(2,2,30,30));
			rgb.red = 225;
			rgb.green = 0;
			rgb.blue = 225;
			bView->SetHighColor(rgb);
			bView->FillRect(BRect(10,10,30,22));
		}
		pOffPicture = bView->EndPicture();
		
		bView->BeginPicture(new BPicture);
		{
			bView->StrokeRect(BRect(0,0,32,32));
			rgb_color rgb;
			rgb.red = 65;
			rgb.green = 65;
			rgb.blue = 65;
			bView->SetHighColor(rgb);
			bView->FillRect(BRect(2,2,30,30));
			rgb.red = 185;
			rgb.green = 0;
			rgb.blue = 185;
			bView->SetHighColor(rgb);
			bView->FillRect(BRect(4,4,18,18));
			rgb.red = 185;
			rgb.green = 185;
			rgb.blue = 0;
			bView->SetHighColor(rgb);
			bView->StrokeRect(BRect(6,12,25,28));
		}
		pOnPicture = bView->EndPicture();
		
		bView->BeginPicture(new BPicture);
		pOffDisabledPicture = bView->EndPicture();
		
		bView->BeginPicture(new BPicture);
		pOnDisabledPicture = bView->EndPicture();
		bWindow->Unlock();
		bWindow->PostMessage(B_QUIT_REQUESTED);
		MyPictureButton * pDemoMyPictureButton = new MyPictureButton(	BRect(0, 0, 32, 32),
																		NULL, 
																		pOffPicture,
																		pOnPicture,
																		pOffDisabledPicture,
																		pOnDisabledPicture,
																		'd123',
																		B_TWO_STATE_BUTTON,//B_ONE_STATE_BUTTON
																		pDemoLayoutMatrix);
	///////////////////////////////////////////////////////////////////////
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
		MyRadioView * pMyRadioView = new MyRadioView(	NULL,
														false,//true gives vertical orientation
														pBList,
														myPrefs->GetPreferredFont(),
														pDemoLayoutMatrix);
		if (!pMyRadioView->Initialize())
		{
			warning(myPrefs->RadioViewFailInit);
			throw;
		}
	///////////////////////////////////////////////////////////////////////
		MyCheckBox * pCheckBox = new MyCheckBox(	NULL, 
													myPrefs->DemoCheckBoxLabel, 
													B_CONTROL_ON,
													'_one',
													pDemoLayoutMatrix);
	//////////////////////////////////
		MyStatusBar * pStatusBar = new MyStatusBar(	NULL, 
													myPrefs->DemoStatusBarLeadLabel, 
													myPrefs->DemoStatusBarTrailLabel,
													50,
													10.0,
													pDemoLayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		MySlider * pSlider = new MySlider(	BRect(1, 1, 65, 32), 
											NULL,
											"Label",
											'd123',
											1,
											10,
											.5,
											pDemoLayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		MyTextView * pTextView = new MyTextView(	NULL, 
													NULL, 
													100,
													35,
													pDemoLayoutMatrix);
		rgb_color textColor;
		myPrefs->GetPreferredMyTextViewHighColor(&textColor);
		pTextView->SetFontAndColor(myPrefs->GetPreferredFont(), B_FONT_ALL, &textColor);
		pTextView->SetText(myPrefs->TextGadgetLabel);
	///////////////////////////////////////////////////////////////////////
		DataList * dataList = new DataList();
		DataNode * nodeOne = new DataNode(myPrefs->ListViewSample1);
		dataList->AddItem(nodeOne);
		DataNode * nodeTwo = new DataNode(myPrefs->ListViewSample2);
		dataList->AddItem(nodeTwo);
		DataNode * nodeThree = new DataNode(myPrefs->ListViewSample3);
		dataList->AddItem(nodeThree);
		MyListView * mlv = new MyListView(	NULL,
											dataList,
											'selc',
											'invc',
											B_SINGLE_SELECTION_LIST,
											pDemoLayoutMatrix);
///////////////////////////////////////////////////////////////////////
		LayoutMatrix * pDemo2LayoutMatrix = new LayoutMatrix(BESTSIZE, 4, 3, this);//rows,columns
///////////////////////////////////////////////////////////////////////
		Int8Gadget * pInt8Gadget = new Int8Gadget(	MIN_I8,
													NULL,
													myPrefs->GetInt8GadgetLabel,
													0,
													this,
													pDemo2LayoutMatrix);
		BMessageFilter * bmf8Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
														B_LOCAL_SOURCE, 
														'_KYD', 
														filterIntNumeric);
		pInt8Gadget->AddFilter(bmf8Demo);
	///////////////////////////////////////////////////////////////////////
		MySpacer ms1(5, 0, pDemo2LayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		UInt8Gadget * pUInt8Gadget = new UInt8Gadget(	MAX_UI8,
														NULL,
														myPrefs->GetUInt8GadgetLabel,
														0,
														this,
														pDemo2LayoutMatrix);
		BMessageFilter * bmfU8Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterUIntNumeric);
		pUInt8Gadget->AddFilter(bmfU8Demo);
	///////////////////////////////////////////////////////////////////////
		Int16Gadget * pInt16Gadget = new Int16Gadget(	MIN_I16,
														NULL,
														myPrefs->GetInt16GadgetLabel,
														0,
														this,
														pDemo2LayoutMatrix);
		BMessageFilter * bmf16Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterIntNumeric);
		pInt16Gadget->AddFilter(bmf16Demo);
	///////////////////////////////////////////////////////////////////////
		MySpacer ms2(5, 0, pDemo2LayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		UInt16Gadget * pUInt16Gadget = new UInt16Gadget(	MAX_UI16,
															NULL,
															myPrefs->GetUInt16GadgetLabel,
															0,
															this,
															pDemo2LayoutMatrix);
		BMessageFilter * bmfU16Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterUIntNumeric);
		pUInt16Gadget->AddFilter(bmfU16Demo);
	///////////////////////////////////////////////////////////////////////
		Int32Gadget * pInt32Gadget = new Int32Gadget(	MIN_I32,
														NULL,
														myPrefs->GetInt32GadgetLabel,
														0,
														this,
														pDemo2LayoutMatrix);
		BMessageFilter * bmf32Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterIntNumeric);
		pInt32Gadget->AddFilter(bmf32Demo);
	///////////////////////////////////////////////////////////////////////
		MySpacer ms3(5, 0, pDemo2LayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		UInt32Gadget * pUInt32Gadget = new UInt32Gadget(	MAX_UI32,
															NULL,
															myPrefs->GetUInt32GadgetLabel,
															0,
															this,
															pDemo2LayoutMatrix);
		BMessageFilter * bmfU32Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterUIntNumeric);
		pUInt32Gadget->AddFilter(bmfU32Demo);
	///////////////////////////////////////////////////////////////////////
		Int64Gadget * pInt64Gadget = new Int64Gadget(	MIN_I64,
														NULL,
														myPrefs->GetInt64GadgetLabel,
														0,
														this,
														pDemo2LayoutMatrix);
		BMessageFilter * bmf64Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterIntNumeric);
		pInt64Gadget->AddFilter(bmf64Demo);
	///////////////////////////////////////////////////////////////////////
		MySpacer ms4(5, 0, pDemo2LayoutMatrix);
////////////////////////////////////////////////////////////////////////
		UInt64Gadget * pUInt64Gadget = new UInt64Gadget(	MAX_UI64,
															NULL,
															myPrefs->GetUInt64GadgetLabel,
															0,
															this,
															pDemo2LayoutMatrix);
		BMessageFilter * bmfU64Demo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterUIntNumeric);
		pUInt64Gadget->AddFilter(bmfU64Demo);
///////////////////////////////////////////////////////////////////////
		LayoutMatrix * pDemo3LayoutMatrix = new LayoutMatrix(BESTSIZE, 6, 1, this);//rows,columns
///////////////////////////////////////////////////////////////////////
		FloatGadget * pFloatGadget = new FloatGadget(	(float)12.34,
														NULL,
														myPrefs->GetFloatGadgetLabel,
														0,
														this,
														pDemo3LayoutMatrix);
		BMessageFilter * bmfDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
														B_LOCAL_SOURCE, 
														'_KYD', 
														filterFloatNumeric);
		pFloatGadget->AddFilter(bmfDemo);
	///////////////////////////////////////////////////////////////////////
		HexGadget * pHexGadget = new HexGadget(	"AB12",
												NULL,
												myPrefs->GetHexGadgetLabel,
												0,
												this,
												pDemo3LayoutMatrix);
		BMessageFilter * bmfHexDemo = new BMessageFilter(	B_PROGRAMMED_DELIVERY, 
															B_LOCAL_SOURCE, 
															'_KYD', 
															filterHexNumeric);
		pHexGadget->AddFilter(bmfHexDemo);
	///////////////////////////////////////////////////////////////////////
		StringGadget * pStringGadget = new StringGadget(	"enter text here!",
															NULL,
															myPrefs->GetStringGadgetLabel,
															0,
															this,
															pDemo3LayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		UInt32Control * pUInt32Control = new UInt32Control(	123,
															NULL, 
															myPrefs->UInt32ControlLabel, 
															'e123',
															0,
															pDemo3LayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		FloatControl * pFloatControl = new FloatControl(	(float)1.23,
															NULL, 
															myPrefs->FloatControlLabel, 
															'f123',
															0,
															pDemo3LayoutMatrix);
	///////////////////////////////////////////////////////////////////////
		StringControl * pStringControl = new StringControl(	NULL, 
															myPrefs->StringControlLabel, 
															NULL, 
															'g123',
															0,
															pDemo3LayoutMatrix);
///////////////////////////////////////////////////////////////////////
		release_sem(calc_sem);
		pTitleLayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, MATRIXVERTICALOFFSET, calc_sem);
		pDemoLayoutMatrix->Calc(pTitleLayoutMatrix->mfRight, MATRIXVERTICALOFFSET, calc_sem);
		float bottom = pTitleLayoutMatrix->mfBottom;
		if (bottom < pDemoLayoutMatrix->mfBottom)
		{
			bottom = pDemoLayoutMatrix->mfBottom;
		}
		pDemo2LayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, bottom, calc_sem);
		pDemo3LayoutMatrix->Calc(MATRIXHORIZONTALOFFSET, pDemo2LayoutMatrix->mfBottom, calc_sem);
	}
	catch (...)
	{
		warning(myApp->CaughtPrefsEDgarWindowCTOR);
		release_sem(calc_sem);
		throw;
	}
	try
	{
		BMenuItem *	menuItem;
		BMenu * APPMenu = new BMenu(myApp->AppMenuLabel);
		menuItem = new BMenuItem(	myPrefs->AboutMenuLabel, 
									new BMessage(ABOUT_PREFWINDOW));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myPrefs->PreferenceMenuLabel, 
									new BMessage(PREFSMSG));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myApp->CloseWindow, 
									new BMessage(B_QUIT_REQUESTED));
		APPMenu->AddItem(menuItem);
		menuItem = new BMenuItem(	myApp->QuitMenuLabel, 
									new BMessage(QUIT_APP));
		APPMenu->AddItem(menuItem);
		mpMenuBar->AddItem(APPMenu);
	}
	catch (...)
	{
		warning(myApp->CaughtPrefsEDgarWindowCTOR);
		throw;
	}
}//end


//dtor
PrefsEDgarWindow	::	~PrefsEDgarWindow() 
{
	myApp->mpPrefsEDgarWindow = NULL;
	if (!myPrefs->mbPrefChangesMade)
	{
		myApp->PostMessage(B_QUIT_REQUESTED);
	}
}//end


void
PrefsEDgarWindow	::	MessageReceived(	BMessage * pparamMessage) 
{
	switch(pparamMessage->what) 
	{
		case ABOUT_PREFWINDOW:	
		{
			warning("myApp->AboutPrefsEDgarWindowMsg");
		}
		break;
		case QUIT_APP:
			if (Verify("myApp->ReallyQuitApp"))
			{
				myApp->PostMessage(B_QUIT_REQUESTED);
			}
		break;
		case PREFSMSG:
			myPrefs->OpenPreferencesPanel();
		break;
		default:
			ScrollingWindow::MessageReceived(pparamMessage);
		break;
	}
}//end


bool
PrefsEDgarWindow	::	QuitRequested(	void) 
{
	myApp->preferredPrefsEDgarWindowRect = Frame();
	return(ScrollingWindow::QuitRequested());
}//end