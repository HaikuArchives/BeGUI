//myPreferencesCTOR.cpp

#define BUILDING_LIB 1
#define NOTX_MYPREF 1

#include "commonHeaders.h"
#include "beGUI_Version.h"
#include "DnumSpecificWindows.h"
#include "DmenuMsg.h"
#include "Preferences.h"
#include "myroColour.h"
#include "myPreferences.h"
#include "myButton.h"
#include "stringControl.h"
#include "uInt32Control.h"
#include "warning.h"
#include "fontData.h"
#include "layoutMatrix.h"
#include "colorWell.h"
#include "myColorControl.h"
#include "myTextView.h"
#include "myListView.h"
#include "scrollingWindow.h"
#include "myCheckBox.h"
#include "gadgetBase.h"
#include "floatGadget.h"
#include "specificColorWindow.h"
#include "scrollingWindow.h"
#include "prefPanelWindow.h"
#include "smallerRect.h"


//the following array is also duplicated in specificColorWindow.cpp as lNamePrefFrame[NUMSPECIFICWINDOWS]
const char * namePrefFrame[NUMSPECIFICWINDOWS] = 
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


MyPreferences	::	MyPreferences()
				:	preferredFont(new BFont()),
					pPrefPanelWindow(NULL),
					mpPreferenceSet(NULL),
					VerifyCancel(NULL),
					AntiAliasFont(NULL),
					NoAdditem(NULL),
					failMenu(NULL),
					PrefsNoSetAntiAliasFont(NULL),
					EnterBarHeightLabel(NULL),
					EnterColorWellWidthLabel(NULL),
					EnterColorWellHeightLabel(NULL),
					PrefsNoSetBarHeight(NULL),
					PrefsNoSetColorWellWidth(NULL),
					PrefsNoSetColorWellHeight(NULL),
					BMsgAddXFailPUMInit(NULL),
					VerifyDoNot(NULL),
					PrefSignature(NULL),
					VerifyDo(NULL),
					AboutMenuLabel(NULL),
					FontFamilyPUMLabel(NULL),
					FontStylePUMLabel(NULL),
					AboutPrefPanelWindow(NULL),
					AboutFontPrefWindowMsg1(NULL),
					AboutFontPrefWindowMsg2(NULL),
					AboutFontPrefWindowMsg3(NULL),
					AboutFontPrefWindowMsg4(NULL),
					AboutFontPrefWindowMsg5(NULL),
					AboutFontPrefWindowMsg6(NULL),
					AboutGutMsg(NULL),
					AboutBasicColorWindowMsg1(NULL),
					AboutBasicColorWindowMsg2(NULL),
					AboutSpecColorWindow(NULL),
					AboutFontDisplayWindow(NULL),
					FailLockLooper(NULL),
					ReallyQuitApp(NULL),
					CaughtFontPrefWindowCTOR(NULL),
					CaughtPrefPanelWindowCTOR(NULL),
					NoPrefPanelWindow(NULL),
					CaughtBasicColorWindowCTOR(NULL),
					CaughtSpecificColorWindowCTOR(NULL),
					BadSpecColorKindView(NULL),
					BadSpecColorKindHigh(NULL),
					BadSpecColorKindLow(NULL),
					WarningOKLabel(NULL),
					FailMemory(NULL),
					FailScrollView(NULL),
					PreferenceMenuLabel(NULL),
					PrefFailInit(NULL),
					PrefFailGetSettings(NULL),
					PrefFailSetSettings(NULL),
					PreferencePanelWindowTitle(NULL),
					PrefsNoSetColorWellHighColor(NULL),
					PrefsNoSetolorWellLowColor(NULL),
					PrefsNoSetColorWellViewColor(NULL),
					PrefsNoSetMyButtonHighColor(NULL),
					PrefsNoSetMyButtonLowColor(NULL),
					PrefsNoSetMyButtonViewColor(NULL),
					PrefsNoSetMyPictureButtonHighColor(NULL),
					PrefsNoSetMyPictureButtonLowColor(NULL),
					PrefsNoSetMyPictureButtonViewColor(NULL),
					PrefsNoSetMyCheckBoxHighColor(NULL),
					PrefsNoSetMyCheckBoxLowColor(NULL),
					PrefsNoSetMyCheckBoxViewColor(NULL),
					PrefsNoSetMyStatusBarHighColor(NULL),
					PrefsNoSetMyStatusBarLowColor(NULL),
					PrefsNoSetMyStatusBarViewColor(NULL),
					PrefsNoSetMyBarStatusColor(NULL),
					PrefsNoSetMySliderHighColor(NULL),
					PrefsNoSetMySliderLowColor(NULL),
					PrefsNoSetMySliderViewColor(NULL),
					PrefsNoSetMyBarSliderColor(NULL),
					PrefsNoSetMyColorControlHighColor(NULL),
					PrefsNoSetMyColorControlLowColor(NULL),
					PrefsNoSetMyColorControlViewColor(NULL),
					PrefsNoSetMyStringDrawerHighColor(NULL),
					PrefsNoSetMyStringDrawerLowColor(NULL),
					PrefsNoSetMyStringDrawerViewColor(NULL),
					PrefsNoSetMyRadioViewHighColor(NULL),
					PrefsNoSetMyRadioViewLowColor(NULL),
					PrefsNoSetMyRadioViewViewColor(NULL),
					PrefsNoSetMyTextViewHighColor(NULL),
					PrefsNoSetMyTextViewLowColor(NULL),
					PrefsNoSetMyTextViewViewColor(NULL),
					PrefsNoSetUInt32ControlHighColor(NULL),
					PrefsNoSetUInt32ControlLowColor(NULL),
					PrefsNoSetUInt32ControlViewColor(NULL),
					PrefsNoSetInt8GadgetHighColor(NULL),
					PrefsNoSetInt8GadgetLowColor(NULL),
					PrefsNoSetInt8GadgetViewColor(NULL),
					PrefsNoSetUInt8GadgetHighColor(NULL),
					PrefsNoSetUInt8GadgetLowColor(NULL),
					PrefsNoSetUInt8GadgetViewColor(NULL),
					PrefsNoSetInt16GadgetHighColor(NULL),
					PrefsNoSetInt16GadgetLowColor(NULL),
					PrefsNoSetInt16GadgetViewColor(NULL),
					PrefsNoSetUInt16GadgetHighColor(NULL),
					PrefsNoSetUInt16GadgetLowColor(NULL),
					PrefsNoSetUInt16GadgetViewColor(NULL),
					PrefsNoSetInt32GadgetHighColor(NULL),
					PrefsNoSetInt32GadgetLowColor(NULL),
					PrefsNoSetInt32GadgetViewColor(NULL),
					PrefsNoSetUInt32GadgetHighColor(NULL),
					PrefsNoSetUInt32GadgetLowColor(NULL),
					PrefsNoSetUInt32GadgetViewColor(NULL),
					PrefsNoSetInt64GadgetHighColor(NULL),
					PrefsNoSetInt64GadgetLowColor(NULL),
					PrefsNoSetInt64GadgetViewColor(NULL),
					PrefsNoSetUInt64GadgetHighColor(NULL),
					PrefsNoSetUInt64GadgetLowColor(NULL),
					PrefsNoSetUInt64GadgetViewColor(NULL),
					PrefsNoSetFloatGadgetHighColor(NULL),
					PrefsNoSetFloatGadgetLowColor(NULL),
					PrefsNoSetFloatGadgetViewColor(NULL),
					PrefsNoSetHexGadgetHighColor(NULL),
					PrefsNoSetHexGadgetLowColor(NULL),
					PrefsNoSetHexGadgetViewColor(NULL),
					PrefsNoSetStringGadgetHighColor(NULL),
					PrefsNoSetStringGadgetLowColor(NULL),
					PrefsNoSetStringGadgetViewColor(NULL),
					PrefsNoSetFloatControlHighColor(NULL),
					PrefsNoSetFloatControlLowColor(NULL),
					PrefsNoSetFloatControlViewColor(NULL),
					PrefsNoSetHighColor(NULL),
					PrefsNoSetLowColor(NULL),
					PrefsNoSetViewColor(NULL),
					FontPrefWindowTitle(NULL),
					FontPrefWindowHeading1(NULL),
					BiggerFontButtonLabel(NULL),
					SmallerFontButtonLabel(NULL),
					EnterFontSizeLabel(NULL),
					DisplayFontCheckBoxLabel(NULL),
					FontDisplayNotNull(NULL),
					FontDisplayWindowTitle(NULL),
					FailFontDisplayWindow(NULL),
					FailMinFontSize(NULL),
					FailMaxFontSize(NULL),
					PrefsNoSetFont(NULL),
					PrefsNoSetOpenFontDisplay(NULL),
					PrefsNoSetUseColorWell(NULL),
					PrefsNoSetUseColorControl(NULL),
					PrefsNoSaveSet(NULL),
					PrefPanelWindowHeading1(NULL),
					PrefPanelFontButtonLabel(NULL),
					PrefPanelWindowHeading2(NULL),
					BarCWLabel(NULL),
					BarCCLabel(NULL),
					PrefsNoSetMyListViewHighColor(NULL),
					PrefsNoSetMyListViewLowColor(NULL),
					PrefsNoSetMyListViewViewColor(NULL),
					FailCreateSemaphore(NULL),
					FailAqSem(NULL),
					AppMenuLabel(NULL),
					QuitMenuLabel(NULL),
					CloseWindow(NULL),
					ScreenNotValid(NULL),
					NotFoundScrollView(NULL),
					PrefNoSetGutFrame(NULL),
					S2UI32Neg(NULL),
					S2UI32OutOfRange(NULL),
					S2UI32Invalid(NULL),
					BasicColorWindowHeading1(NULL),
					ColorWindowHeading2(NULL),
					ColorWindowHeading3(NULL),
					ColorWindowHeading4(NULL),
					ColorWindowHeading5(NULL),
					ColorWindowHeading6(NULL),
					ColorWindowHeading7(NULL),
					DemoRoNo(NULL),
					RoBadMsg(NULL),
					BarColorTitle(NULL),
					DemoButtonLabel(NULL),
					DemoRadio1Label(NULL),
					DemoRadio2Label(NULL),
					DemoRadio3Label(NULL),
					RadioViewFailInit(NULL),
					DemoCheckBoxLabel(NULL),
					DemoStatusBarLeadLabel(NULL),
					DemoStatusBarTrailLabel(NULL),
					StringControlLabel(NULL),
					TextGadgetLabel(NULL),
					ListViewSample1(NULL),
					ListViewSample2(NULL),
					ListViewSample3(NULL),
					SelectFromList(NULL),
					InvokeFromList(NULL),
					UInt32ControlLabel(NULL),
					FloatControlLabel(NULL),
					DemoRoLabel(NULL),
					DemoTextItemText(NULL),
					BadSpecItemKind(NULL),
					BadSpecKindQR(NULL),
					BadSpecKindColorSetView(NULL),
					BadSpecKindColorSetHigh(NULL),
					BadSpecKindColorSetLow(NULL),
					DisplayBColorControls(NULL),
					DisplayroColourWells(NULL),
					BasicColorWindowTitle(NULL),
					NoBasicColorWindow(NULL),
					NoSpecColorWindow(NULL),
					FailPUMInitFontWindow(NULL),
					FailPUMInit(NULL),
					FailRadioInit(NULL),
					truncShort(NULL),
					noCCenabled(NULL),
					MessageFindBytes(NULL),
					NumStrTooLong(NULL),
					NumTooBig(NULL),
					NumTooSmall(NULL),
					S2I32OutOfRange(NULL),
					S2I32Invalid(NULL),
					S2I64OutOfRange(NULL),
					S2I64Invalid(NULL),
					S2UI64OutOfRange(NULL),
					S2UI64Invalid(NULL),
					WrongKindLMI(NULL),
					AboutSimpleWindowMsg(NULL),
					GetInt8GadgetLabel(NULL),
					GetUInt8GadgetLabel(NULL),
					GetInt16GadgetLabel(NULL),
					GetUInt16GadgetLabel(NULL),
					GetInt32GadgetLabel(NULL),
					GetUInt32GadgetLabel(NULL),
					GetInt64GadgetLabel(NULL),
					GetUInt64GadgetLabel(NULL),
					GetFloatGadgetLabel(NULL),
					GetHexGadgetLabel(NULL),
					GetDoubleGadgetLabel(NULL),
					GetLongDoubleGadgetLabel(NULL),
					GetStringGadgetLabel(NULL),
					PrefNoSetBaseFrame(NULL),
					AboutBaseMsg(NULL),
					DemoRadioLabelThumbRect(NULL),
					DemoRadioLabelThumbTri(NULL),
					PrefsNoSetThumbStyle(NULL),
					IllegalThumb(NULL),
					ColorSliderBarCBLabel(NULL),
					FillSliderBarCBLabel(NULL),
					SliderBarFillColorLabel(NULL),
					PrefsNoSetMyBarFillSliderColor(NULL),
					PrefsNoSetMyBarFillSlider(NULL),
					PrefsNoSetMyBarColorSlider(NULL),
					FillCWLabel(NULL),
					FillCCLabel(NULL),
					ColorControlKind(NULL),
					CC_4x64_Cell(NULL),
					CC_8x32_Cell(NULL),
					CC_16x16_Cell(NULL),
					CC_32x8_Cell(NULL),
					CC_64x4_Cell(NULL),
					PrefsNoSetCCLayout(NULL),
					FailReopen(NULL),
					StringTooLongToMeasure(NULL),
					AlphaNumeric(NULL),
					mbPrefChangesMade(false),
					mbsVersion(BeGUIVersion)
{
	myPrefs = this;
	image_info info;
	int32 cookie = 0;
	status_t got = get_next_image_info(0, &cookie, &info);
	BEntry theAppEntry(info.name);
	BEntry theAppDir;
	theAppEntry.GetParent(&theAppDir);
	char appLib[MAXPATHLEN + 20];
	BPath appLibPath;
	theAppDir.GetPath(&appLibPath);
	strcpy(appLib, appLibPath.Path());
	strcat(appLib, "/lib");
	BFile refFile;
	BDirectory libDir;
	status_t hasLib = libDir.SetTo(appLib);
	if (hasLib == B_NO_ERROR)
	{
		if (libDir.Contains("libBeGUI.so"))
		{
			strcat(appLib, "/libBeGUI.so");
			refFile.SetTo(appLib, B_READ_ONLY);
		}
		else
		{
			refFile.SetTo("/boot/home/config/lib/libBeGUI.so", B_READ_ONLY);
		}
	}
	else
	{
		refFile.SetTo("/boot/home/config/lib/libBeGUI.so", B_READ_ONLY);
	}
	status_t stat = refFile.InitCheck();
	if (stat == B_NO_ERROR)
	{
		BResources resources;
		stat = resources.SetTo(&refFile);
		if (stat == B_NO_ERROR)
		{
//			for (	int i = 0;
//					i < NUMPREFPANELS;
//					i++
//				)
//			{	
//				buttonLabels[i] = NULL;
//			}
//			for (	int i = 0;
//					i < (NUMPREFPANELS - 1);
//					i++
//				)
//			{	
//				lvwTitleStr[i] = NULL;
//			}
			size_t len;
			VerifyCancel = (const char *)resources.FindResource('CSTR', "VerifyCancel", &len);
			VerifyDoNot = (const char *)resources.FindResource('CSTR', "VerifyDoNot", &len);
			PrefSignature = (const char *)resources.FindResource('CSTR', "BeGUIPreference", &len);
			VerifyDo = (const char *)resources.FindResource('CSTR', "VerifyDo", &len);
			AboutMenuLabel = (const char *)resources.FindResource('CSTR', "AboutMenuLabel", &len);
			FontFamilyPUMLabel = (const char *)resources.FindResource('CSTR', "FontFamilyPUMLabel", &len);
			FontStylePUMLabel = (const char *)resources.FindResource('CSTR', "FontStylePUMLabel", &len);
			AboutPrefPanelWindow = (const char *)resources.FindResource('CSTR', "AboutPrefPanelWindow", &len);
			AboutFontPrefWindowMsg1 = (const char *)resources.FindResource('CSTR', "AboutFontPrefWindowMsg1", &len);
			AboutFontPrefWindowMsg2 = (const char *)resources.FindResource('CSTR', "AboutFontPrefWindowMsg2", &len);
			AboutFontPrefWindowMsg3 = (const char *)resources.FindResource('CSTR', "AboutFontPrefWindowMsg3", &len);
			AboutFontPrefWindowMsg4 = (const char *)resources.FindResource('CSTR', "AboutFontPrefWindowMsg4", &len);
			AboutFontPrefWindowMsg5 = (const char *)resources.FindResource('CSTR', "AboutFontPrefWindowMsg5", &len);
			AboutFontPrefWindowMsg6 = (const char *)resources.FindResource('CSTR', "AboutFontPrefWindowMsg6", &len);
			AboutGutMsg = (const char *)resources.FindResource('CSTR', "AboutGutMsg", &len);
			AboutBasicColorWindowMsg1 = (const char *)resources.FindResource('CSTR', "AboutBasicColorWindowMsg1", &len);
			AboutBasicColorWindowMsg2 = (const char *)resources.FindResource('CSTR', "AboutBasicColorWindowMsg2", &len);
			AboutSpecColorWindow = (const char *)resources.FindResource('CSTR', "AboutSpecColorWindow", &len);
			AboutFontDisplayWindow = (const char *)resources.FindResource('CSTR', "AboutFontDisplayWindow", &len);
			FailLockLooper = (const char *)resources.FindResource('CSTR', "FailLockLooper", &len);
			ReallyQuitApp = (const char *)resources.FindResource('CSTR', "ReallyQuitApp", &len);
			CaughtFontPrefWindowCTOR = (const char *)resources.FindResource('CSTR', "CaughtFontPrefWindowCTOR", &len);
			CaughtPrefPanelWindowCTOR = (const char *)resources.FindResource('CSTR', "CaughtPrefPanelWindowCTOR", &len);
			NoPrefPanelWindow = (const char *)resources.FindResource('CSTR', "NoPrefPanelWindow", &len);
			CaughtBasicColorWindowCTOR = (const char *)resources.FindResource('CSTR', "CaughtBasicColorWindowCTOR", &len);
			CaughtSpecificColorWindowCTOR = (const char *)resources.FindResource('CSTR', "CaughtSpecificColorWindowCTOR", &len);
			BadSpecColorKindView = (const char *)resources.FindResource('CSTR', "BadSpecColorKindView", &len);
			BadSpecColorKindHigh = (const char *)resources.FindResource('CSTR', "BadSpecColorKindHigh", &len);
			BadSpecColorKindLow = (const char *)resources.FindResource('CSTR', "BadSpecColorKindLow", &len);
			WarningOKLabel = (const char *)resources.FindResource('CSTR', "WarningOKLabel", &len);
			FailMemory = (const char *)resources.FindResource('CSTR', "FailMemory", &len);
			FailScrollView = (const char *)resources.FindResource('CSTR', "FailScrollView", &len);
			PreferenceMenuLabel = (const char *)resources.FindResource('CSTR', "PreferenceMenuLabel", &len);
			PrefFailInit = (const char *)resources.FindResource('CSTR', "PrefFailInit", &len);
			PrefFailGetSettings = (const char *)resources.FindResource('CSTR', "PrefFailGetSettings", &len);
			PrefFailSetSettings = (const char *)resources.FindResource('CSTR', "PrefFailSetSettings", &len);
			PreferencePanelWindowTitle = (const char *)resources.FindResource('CSTR', "PreferencePanelWindowTitle", &len);
			PrefsNoSetColorWellHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetColorWellHighColor", &len);
			PrefsNoSetolorWellLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetolorWellLowColor", &len);
			PrefsNoSetColorWellViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetColorWellViewColor", &len);
			PrefsNoSetMyButtonHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyButtonHighColor", &len);
			PrefsNoSetMyButtonLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyButtonLowColor", &len);
			PrefsNoSetMyButtonViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyButtonViewColor", &len);
			PrefsNoSetMyPictureButtonHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyPictureButtonHighColor", &len);
			PrefsNoSetMyPictureButtonLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyPictureButtonLowColor", &len);
			PrefsNoSetMyPictureButtonViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyPictureButtonViewColor", &len);
			PrefsNoSetMyCheckBoxHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyCheckBoxHighColor", &len);
			PrefsNoSetMyCheckBoxLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyCheckBoxLowColor", &len);
			PrefsNoSetMyCheckBoxViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyCheckBoxViewColor", &len);
			PrefsNoSetMyStatusBarHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyStatusBarHighColor", &len);
			PrefsNoSetMyStatusBarLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyStatusBarLowColor", &len);
			PrefsNoSetMyStatusBarViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyStatusBarViewColor", &len);
			PrefsNoSetMyBarStatusColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyBarStatusColor", &len);
			PrefsNoSetMySliderHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMySliderHighColor", &len);
			PrefsNoSetMySliderLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMySliderLowColor", &len);
			PrefsNoSetMySliderViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMySliderViewColor", &len);
			PrefsNoSetMyBarSliderColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyBarStatusColor", &len);
			PrefsNoSetMyColorControlHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyColorControlHighColor", &len);
			PrefsNoSetMyColorControlLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyColorControlLowColor", &len);
			PrefsNoSetMyColorControlViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyColorControlViewColor", &len);
			PrefsNoSetMyStringDrawerHighColor  = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyStringDrawerHighColor", &len);
			PrefsNoSetMyStringDrawerLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyStringDrawerLowColor", &len);
			PrefsNoSetMyStringDrawerViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyStringDrawerViewColor", &len);
			PrefsNoSetMyRadioViewHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyRadioViewHighColor", &len);
			PrefsNoSetMyRadioViewLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyRadioViewLowColor", &len);
			PrefsNoSetMyRadioViewViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyRadioViewViewColor", &len);
			PrefsNoSetMyTextViewHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyTextViewHighColor", &len);
			PrefsNoSetMyTextViewLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyTextViewLowColor", &len);
			PrefsNoSetMyTextViewViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyTextViewViewColor", &len);
			PrefsNoSetUInt32ControlHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt32ControlHighColor", &len);
			PrefsNoSetUInt32ControlLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt32ControlLowColor", &len);
			PrefsNoSetUInt32ControlViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt32ControlViewColor", &len);
			PrefsNoSetInt8GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt8GadgetHighColor", &len);
			PrefsNoSetInt8GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt8GadgetLowColor", &len);
			PrefsNoSetInt8GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt8GadgetViewColor", &len);
			PrefsNoSetUInt8GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt8GadgetHighColor", &len);
			PrefsNoSetUInt8GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt8GadgetLowColor", &len);
			PrefsNoSetUInt8GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt8GadgetViewColor", &len);
			PrefsNoSetInt16GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt16GadgetHighColor", &len);
			PrefsNoSetInt16GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt16GadgetLowColor", &len);
			PrefsNoSetInt16GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt16GadgetViewColor", &len);
			PrefsNoSetUInt16GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt16GadgetHighColor", &len);
			PrefsNoSetUInt16GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt16GadgetLowColor", &len);
			PrefsNoSetUInt16GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt16GadgetViewColor", &len);
			PrefsNoSetInt32GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt32GadgetHighColor", &len);
			PrefsNoSetInt32GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt32GadgetLowColor", &len);
			PrefsNoSetInt32GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt32GadgetViewColor", &len);
			PrefsNoSetUInt32GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt32GadgetHighColor", &len);
			PrefsNoSetUInt32GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt32GadgetLowColor", &len);
			PrefsNoSetUInt32GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt32GadgetViewColor", &len);
			PrefsNoSetInt64GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt64GadgetHighColor", &len);
			PrefsNoSetInt64GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt64GadgetLowColor", &len);
			PrefsNoSetInt64GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetInt64GadgetViewColor", &len);
			PrefsNoSetUInt64GadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt64GadgetHighColor", &len);
			PrefsNoSetUInt64GadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt64GadgetLowColor", &len);
			PrefsNoSetUInt64GadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetUInt64GadgetViewColor", &len);
			PrefsNoSetFloatGadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetFloatGadgetHighColor", &len);
			PrefsNoSetFloatGadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetFloatGadgetLowColor", &len);
			PrefsNoSetFloatGadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetFloatGadgetViewColor", &len);
			PrefsNoSetHexGadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetHexGadgetHighColor", &len);
			PrefsNoSetHexGadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetHexGadgetLowColor", &len);
			PrefsNoSetHexGadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetHexGadgetViewColor", &len);
			PrefsNoSetStringGadgetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetStringGadgetHighColor", &len);
			PrefsNoSetStringGadgetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetStringGadgetLowColor", &len);
			PrefsNoSetStringGadgetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetStringGadgetViewColor", &len);
			PrefsNoSetFloatControlHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetFloatControlHighColor", &len);
			PrefsNoSetFloatControlLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetFloatControlLowColor", &len);
			PrefsNoSetFloatControlViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetFloatControlViewColor", &len);
			PrefsNoSetHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetHighColor", &len);
			PrefsNoSetLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetLowColor", &len);
			PrefsNoSetViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetViewColor", &len);
			FontPrefWindowTitle = (const char *)resources.FindResource('CSTR', "FontPrefWindowTitle", &len);
			FontPrefWindowHeading1 = (const char *)resources.FindResource('CSTR', "FontPrefWindowHeading1", &len);
			BiggerFontButtonLabel = (const char *)resources.FindResource('CSTR', "BiggerFontButtonLabel", &len);
			SmallerFontButtonLabel = (const char *)resources.FindResource('CSTR', "SmallerFontButtonLabel", &len);
			EnterFontSizeLabel = (const char *)resources.FindResource('CSTR', "EnterFontSizeLabel", &len);
			DisplayFontCheckBoxLabel = (const char *)resources.FindResource('CSTR', "DisplayFontCheckBoxLabel", &len);
			FontDisplayNotNull = (const char *)resources.FindResource('CSTR', "FontDisplayNotNull", &len);
			FontDisplayWindowTitle = (const char *)resources.FindResource('CSTR', "FontDisplayWindowTitle", &len);
			FailFontDisplayWindow = (const char *)resources.FindResource('CSTR', "FailFontDisplayWindow", &len);
			FailMinFontSize = (const char *)resources.FindResource('CSTR', "FailMinFontSize", &len);
			FailMaxFontSize = (const char *)resources.FindResource('CSTR', "FailMaxFontSize", &len);
			PrefsNoSetFont = (const char *)resources.FindResource('CSTR', "PrefsNoSetFont", &len);
			PrefsNoSetOpenFontDisplay = (const char *)resources.FindResource('CSTR', "PrefsNoSetOpenFontDisplay", &len);
			PrefsNoSetUseColorWell = (const char *)resources.FindResource('CSTR', "PrefsNoSetUseColorWell", &len);
			PrefsNoSetUseColorControl = (const char *)resources.FindResource('CSTR', "PrefsNoSetUseColorControl", &len);
			PrefsNoSaveSet = (const char *)resources.FindResource('CSTR', "PrefsNoSaveSet", &len);
			PrefPanelWindowHeading1 = (const char *)resources.FindResource('CSTR', "PrefPanelWindowHeading1", &len);
			PrefPanelFontButtonLabel = (const char *)resources.FindResource('CSTR', "PrefPanelFontButtonLabel", &len);
			PrefPanelWindowHeading2 = (const char *)resources.FindResource('CSTR', "PrefPanelWindowHeading2", &len);
			BarCWLabel = (const char *)resources.FindResource('CSTR', "BarCWLabel", &len);
			BarCCLabel = (const char *)resources.FindResource('CSTR', "BarCCLabel", &len);
			PrefsNoSetMyListViewHighColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyListViewHighColor", &len);
			PrefsNoSetMyListViewLowColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyListViewLowColor", &len);
			PrefsNoSetMyListViewViewColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyListViewViewColor", &len);
			FailCreateSemaphore = (const char *)resources.FindResource('CSTR', "FailCreateSemaphore", &len);
			FailAqSem = (const char *)resources.FindResource('CSTR', "FailAqSem", &len);
			AppMenuLabel = (const char *)resources.FindResource('CSTR', "AppMenuLabel", &len);
			QuitMenuLabel = (const char *)resources.FindResource('CSTR', "QuitMenuLabel", &len);
			CloseWindow = (const char *)resources.FindResource('CSTR', "CloseWindow", &len);
			ScreenNotValid = (const char *)resources.FindResource('CSTR', "ScreenNotValid", &len);
			NotFoundScrollView = (const char *)resources.FindResource('CSTR', "NotFoundScrollView", &len);
			PrefNoSetGutFrame = (const char *)resources.FindResource('CSTR', "PrefNoSetGutFrame", &len);
			S2UI32Neg = (const char *)resources.FindResource('CSTR', "S2UI32Neg", &len);
			S2UI32OutOfRange = (const char *)resources.FindResource('CSTR', "S2UI32OutOfRange", &len);
			S2UI32Invalid = (const char *)resources.FindResource('CSTR', "S2UI32Invalid", &len);
			BasicColorWindowHeading1 = (const char *)resources.FindResource('CSTR', "BasicColorWindowHeading1", &len);
			ColorWindowHeading2 = (const char *)resources.FindResource('CSTR', "ColorWindowHeading2", &len);
			ColorWindowHeading3 = (const char *)resources.FindResource('CSTR', "ColorWindowHeading3", &len);
			ColorWindowHeading4 = (const char *)resources.FindResource('CSTR', "ColorWindowHeading4", &len);
			ColorWindowHeading5 = (const char *)resources.FindResource('CSTR', "ColorWindowHeading5", &len);
			ColorWindowHeading6 = (const char *)resources.FindResource('CSTR', "ColorWindowHeading6", &len);
			ColorWindowHeading7 = (const char *)resources.FindResource('CSTR', "ColorWindowHeading7", &len);
			DemoRoNo = (const char *)resources.FindResource('CSTR', "DemoRoNo", &len);
			RoBadMsg = (const char *)resources.FindResource('CSTR', "RoBadMsg", &len);
			BarColorTitle = (const char *)resources.FindResource('CSTR', "BarColorTitle", &len);
			DemoButtonLabel = (const char *)resources.FindResource('CSTR', "DemoButtonLabel", &len);
			DemoRadio1Label = (const char *)resources.FindResource('CSTR', "DemoRadio1Label", &len);
			DemoRadio2Label = (const char *)resources.FindResource('CSTR', "DemoRadio2Label", &len);
			DemoRadio3Label = (const char *)resources.FindResource('CSTR', "DemoRadio3Label", &len);
			RadioViewFailInit = (const char *)resources.FindResource('CSTR', "RadioViewFailInit", &len);
			DemoCheckBoxLabel = (const char *)resources.FindResource('CSTR', "DemoCheckBoxLabel", &len);
			DemoStatusBarLeadLabel = (const char *)resources.FindResource('CSTR', "DemoStatusBarLeadLabel", &len);
			DemoStatusBarTrailLabel = (const char *)resources.FindResource('CSTR', "DemoStatusBarTrailLabel", &len);
			StringControlLabel = (const char *)resources.FindResource('CSTR', "StringControlLabel", &len);
			TextGadgetLabel = (const char *)resources.FindResource('CSTR', "TextGadgetLabel", &len);
			ListViewSample1 = (const char *)resources.FindResource('CSTR', "ListViewSample1", &len);
			ListViewSample2 = (const char *)resources.FindResource('CSTR', "ListViewSample2", &len);
			ListViewSample3 = (const char *)resources.FindResource('CSTR', "ListViewSample3", &len);
			SelectFromList = (const char *)resources.FindResource('CSTR', "SelectFromList", &len);
			InvokeFromList = (const char *)resources.FindResource('CSTR', "InvokeFromList", &len);
			UInt32ControlLabel = (const char *)resources.FindResource('CSTR', "UInt32ControlLabel", &len);
			FloatControlLabel = (const char *)resources.FindResource('CSTR', "FloatControlLabel", &len);
			DemoRoLabel = (const char *)resources.FindResource('CSTR', "DemoRoLabel", &len);
			DemoTextItemText = (const char *)resources.FindResource('CSTR', "DemoTextItemText", &len);
			BadSpecItemKind = (const char *)resources.FindResource('CSTR', "BadSpecItemKind", &len);
			BadSpecKindQR = (const char *)resources.FindResource('CSTR', "BadSpecKindQR", &len);
			BadSpecKindColorSetView = (const char *)resources.FindResource('CSTR', "BadSpecKindColorSetView", &len);
			BadSpecKindColorSetHigh = (const char *)resources.FindResource('CSTR', "BadSpecKindColorSetHigh", &len);
			BadSpecKindColorSetLow = (const char *)resources.FindResource('CSTR', "BadSpecKindColorSetLow", &len);
			DisplayBColorControls = (const char *)resources.FindResource('CSTR', "DisplayBColorControls", &len);
			DisplayroColourWells = (const char *)resources.FindResource('CSTR', "DisplayroColourWells", &len);
			BasicColorWindowTitle = (const char *)resources.FindResource('CSTR', "BasicColorWindowTitle", &len);
			NoBasicColorWindow = (const char *)resources.FindResource('CSTR', "NoBasicColorWindow", &len);
			NoSpecColorWindow = (const char *)resources.FindResource('CSTR', "NoSpecColorWindow", &len);
			FailPUMInitFontWindow = (const char *)resources.FindResource('CSTR', "FailPUMInitFontWindow", &len);
			FailPUMInit = (const char *)resources.FindResource('CSTR', "FailPUMInit", &len);
			FailRadioInit = (const char *)resources.FindResource('CSTR', "FailRadioInit", &len);
			truncShort = (const char *)resources.FindResource('CSTR', "trunc2short", &len);
			noCCenabled = (const char *)resources.FindResource('CSTR', "noCCenabled", &len);
			NoAdditem = (const char *)resources.FindResource('CSTR', "NoAdditem", &len);
			failMenu = (const char *)resources.FindResource('CSTR', "failMenu", &len);
			AntiAliasFont = (const char *)resources.FindResource('CSTR', "AntiAliasFont", &len);
			EnterBarHeightLabel = (const char *)resources.FindResource('CSTR', "EnterBarHeightLabel", &len);
			EnterColorWellWidthLabel = (const char *)resources.FindResource('CSTR', "EnterColorWellWidthLabel", &len);
			EnterColorWellHeightLabel = (const char *)resources.FindResource('CSTR', "EnterColorWellHeightLabel", &len);
			PrefsNoSetBarHeight = (const char *)resources.FindResource('CSTR', "PrefsNoSetBarHeight", &len);
			PrefsNoSetColorWellWidth = (const char *)resources.FindResource('CSTR', "PrefsNoSetColorWellWidth", &len);
			PrefsNoSetColorWellHeight = (const char *)resources.FindResource('CSTR', "PrefsNoSetColorWellHeight", &len);
			PrefsNoSetAntiAliasFont = (const char *)resources.FindResource('CSTR', "PrefsNoSetAntiAliasFont", &len);
			BMsgAddXFailPUMInit = (const char *)resources.FindResource('CSTR', "BMsgAddXFailPUMInit", &len);
			MessageFindBytes = (const char *)resources.FindResource('CSTR', "MessageFindBytes", &len);
			NumStrTooLong = (const char *)resources.FindResource('CSTR', "NumStrTooLong", &len);
			NumTooBig = (const char *)resources.FindResource('CSTR', "NumTooBig", &len);
			NumTooSmall = (const char *)resources.FindResource('CSTR', "NumTooSmall", &len);
			S2I32OutOfRange = (const char *)resources.FindResource('CSTR', "S2I32OutOfRange", &len);
			S2I32Invalid = (const char *)resources.FindResource('CSTR', "S2I32Invalid", &len);
			S2I64OutOfRange = (const char *)resources.FindResource('CSTR', "S2I64OutOfRange", &len);
			S2I64Invalid = (const char *)resources.FindResource('CSTR', "S2I64Invalid", &len);
			S2UI64OutOfRange = (const char *)resources.FindResource('CSTR', "S2UI64OutOfRange", &len);
			S2UI64Invalid = (const char *)resources.FindResource('CSTR', "S2UI64Invalid", &len);
			WrongKindLMI = (const char *)resources.FindResource('CSTR', "WrongKindLMI", &len);
			AboutSimpleWindowMsg = (const char *)resources.FindResource('CSTR', "AboutSimpleWindowMsg", &len);
			GetInt8GadgetLabel = (const char *)resources.FindResource('CSTR', "GetInt8GadgetLabel", &len);
			GetUInt8GadgetLabel = (const char *)resources.FindResource('CSTR', "GetUInt8GadgetLabel", &len);
			GetInt16GadgetLabel = (const char *)resources.FindResource('CSTR', "GetInt16GadgetLabel", &len);
			GetUInt16GadgetLabel = (const char *)resources.FindResource('CSTR', "GetUInt16GadgetLabel", &len);
			GetInt32GadgetLabel = (const char *)resources.FindResource('CSTR', "GetInt32GadgetLabel", &len);
			GetUInt32GadgetLabel = (const char *)resources.FindResource('CSTR', "GetUInt32GadgetLabel", &len);
			GetInt64GadgetLabel = (const char *)resources.FindResource('CSTR', "GetInt64GadgetLabel", &len);
			GetUInt64GadgetLabel = (const char *)resources.FindResource('CSTR', "GetUInt64GadgetLabel", &len);
			GetFloatGadgetLabel = (const char *)resources.FindResource('CSTR', "GetFloatGadgetLabel", &len);
			GetHexGadgetLabel = (const char *)resources.FindResource('CSTR', "GetHexGadgetLabel", &len);
			GetDoubleGadgetLabel = (const char *)resources.FindResource('CSTR', "GetDoubleGadgetLabel", &len);
			GetLongDoubleGadgetLabel = (const char *)resources.FindResource('CSTR', "GetLongDoubleGadgetLabel", &len);
			GetStringGadgetLabel = (const char *)resources.FindResource('CSTR', "GetStringGadgetLabel", &len);
			PrefNoSetBaseFrame = (const char *)resources.FindResource('CSTR', "PrefNoSetBaseFrame", &len);
			AboutBaseMsg = (const char *)resources.FindResource('CSTR', "AboutBaseMsg", &len);
			DemoRadioLabelThumbRect = (const char *)resources.FindResource('CSTR', "DemoRadioLabelThumbRect", &len);
			DemoRadioLabelThumbTri = (const char *)resources.FindResource('CSTR', "DemoRadioLabelThumbTri", &len);
			PrefsNoSetThumbStyle = (const char *)resources.FindResource('CSTR', "PrefsNoSetThumbStyle", &len);
			IllegalThumb = (const char *)resources.FindResource('CSTR', "IllegalThumb", &len);
			ColorSliderBarCBLabel = (const char *)resources.FindResource('CSTR', "ColorSliderBarCBLabel", &len);
			FillSliderBarCBLabel = (const char *)resources.FindResource('CSTR', "FillSliderBarCBLabel", &len);
			SliderBarFillColorLabel = (const char *)resources.FindResource('CSTR', "SliderBarFillColorLabel", &len);
			PrefsNoSetMyBarFillSliderColor = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyBarFillSliderColor", &len);
			PrefsNoSetMyBarFillSlider = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyBarFillSlider", &len);
			PrefsNoSetMyBarColorSlider = (const char *)resources.FindResource('CSTR', "PrefsNoSetMyBarColorSlider", &len);
			FillCWLabel = (const char *)resources.FindResource('CSTR', "FillCWLabel", &len);
			FillCCLabel = (const char *)resources.FindResource('CSTR', "FillCCLabel", &len);
			ColorControlKind = (const char *)resources.FindResource('CSTR', "ColorControlKind", &len);
			CC_4x64_Cell = (const char *)resources.FindResource('CSTR', "CC_4x64_Cell", &len);
			CC_8x32_Cell = (const char *)resources.FindResource('CSTR', "CC_8x32_Cell", &len);
			CC_16x16_Cell = (const char *)resources.FindResource('CSTR', "CC_16x16_Cell", &len);
			CC_32x8_Cell = (const char *)resources.FindResource('CSTR', "CC_32x8_Cell", &len);
			CC_64x4_Cell = (const char *)resources.FindResource('CSTR', "CC_64x4_Cell", &len);
			PrefsNoSetCCLayout = (const char *)resources.FindResource('CSTR', "PrefsNoSetCCLayout", &len);
			FailReopen = (const char *)resources.FindResource('CSTR', "FailReopen", &len);
			StringTooLongToMeasure = (const char *)resources.FindResource('CSTR', "StringTooLongToMeasure", &len);
			AlphaNumeric = (const char *)resources.FindResource('CSTR', "AlphaNumeric", &len);

			int32 i = 0;
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsUnderlyingview", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsButton", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsPictureButton", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsRadioButtons", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsCheckBox", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsStatusBar", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsColorControl", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsroColourColorWell", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsInt8Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsUInt8Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsInt16Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsUInt16Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsInt32Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsUInt32Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsInt64Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsUInt64Gadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsFloatGadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsStringGadget", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsStringControl", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsTextView", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsStringDraw", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsListView", &len);
			buttonLabels[i++] = (const char *)resources.FindResource('CSTR', "buttonLabelsFloatControl", &len);
			buttonLabels[i++]   = (const char *)resources.FindResource('CSTR', "buttonLabelsUInt32Control", &len);
			buttonLabels[i]   = (const char *)resources.FindResource('CSTR', "buttonLabelsSlider", &len);
			i = 0;
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleButton", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitlePicture", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleRadioButton", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleCheckBox", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleStatusBar", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleColorControl", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleroColourColorWell", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleInt8Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleUInt8Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleInt16Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleUInt16Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleInt32Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleUInt32Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleInt64Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleUInt64Gadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleFloatGadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleStringGadget", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleStringControl", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleTextview", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleStringDrawer", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleListview", &len);
			lvwTitleStr[i++] = (const char *)resources.FindResource('CSTR', "cpWindowTitleFloatControl", &len);
			lvwTitleStr[i++]   = (const char *)resources.FindResource('CSTR', "cpWindowTitleUInt32Control", &len);
			lvwTitleStr[i]   = (const char *)resources.FindResource('CSTR', "cpWindowTitleSlider", &len);
		}
	}
	mpPreferences = new Preferences(PrefSignature);
	Preferences& mrPreferences = *mpPreferences;
	mpPreferenceSet = new PreferenceSet(	mrPreferences,  
											"hierarchical/extendable/settings", 
											true);
	if (mpPreferences->InitCheck())
	{
		puts(PrefFailInit);
		exit(1);
	}
	if (mpPreferenceSet->InitCheck())
	{
		puts(PrefFailGetSettings);
		exit(2);
	}
	//following is a bunch of prefs stuff set to default if file not found:
	const void * prefData;
	ssize_t prefDataSize;
	uint32 prefDataType = '    ';
	FontData fontData;
	float floatData;
	if (	mpPreferenceSet->GetData(	"FONTDATA_SIZE_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_SIZE_TYPE))
	{
		//fontData.size = use default;
	}
	else
	{
		memcpy(	&floatData, 
				prefData, 
				prefDataSize);
		fontData.mfSize = floatData;
	}
	if (	mpPreferenceSet->GetData(	"FONTDATA_SHEAR_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_SHEAR_TYPE))
	{
		//fontData.shear = use default;
	}
	else
	{
		memcpy(	&floatData, 
				prefData, 
				prefDataSize);
		fontData.mfShear = floatData;
	}
	if (	mpPreferenceSet->GetData(	"FONTDATA_ROTATION_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_ROTATION_TYPE))
	{
		//fontData.mfRotation = use default;
	}
	else
	{
		memcpy(	&floatData, 
				prefData, 
				prefDataSize);
		fontData.mfRotation = floatData;
	}
	uint32 ui32Data;
	if (	mpPreferenceSet->GetData(	"FONTDATA_FLAGS_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_FLAGS_TYPE))
	{
		//fontData.mui32Flags = use default;
	}
	else
	{
		memcpy(	&ui32Data, 
				prefData, 
				prefDataSize);
		fontData.mui32Flags = ui32Data;
	}
	if (	mpPreferenceSet->GetData(	"FONTDATA_FANDS_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_FANDS_TYPE))
	{
		//fontData.mui32FamilyAndStyle = use default;
	}
	else
	{
		memcpy(	&ui32Data, 
				prefData, 
				prefDataSize);
		fontData.mui32FamilyAndStyle = ui32Data;
	}
	uint16 ui16Data;
	if (	mpPreferenceSet->GetData(	"FONTDATA_FACE_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_FACE_TYPE))
	{
		//fontData.mui16Face = use default;
	}
	else
	{
		memcpy(	&ui16Data, 
				prefData, 
				prefDataSize);
		fontData.mui16Face = ui16Data;
	}
	uint8 ui8Data;
	if (	mpPreferenceSet->GetData(	"FONTDATA_SPACING_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_SPACING_TYPE))
	{
		//fontData.mui8Spacing = use default;
	}
	else
	{
		memcpy(	&ui8Data, 
				prefData, 
				prefDataSize);
		fontData.mui8Spacing = ui8Data;
	}
	if (	mpPreferenceSet->GetData(	"FONTDATA_ENOCDING_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != FONTDATA_ENOCDING_TYPE))
	{
		//fontData.mui8Encoding = use default;
	}
	else
	{
		memcpy(	&ui8Data, 
				prefData, 
				prefDataSize);
		fontData.mui8Encoding = ui8Data;
	}
	SetPreferredFontFromData(&fontData);
	thumb_style thumbStyleData;
	if (	mpPreferenceSet->GetData(	"THUMBSTYLE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != THUMBSTYLE))
	{
		SetPreferredThumbStyle(B_BLOCK_THUMB);
	}
	else
	{
		memcpy(	&thumbStyleData, 
				prefData, 
				prefDataSize);
		SetPreferredThumbStyle(thumbStyleData);
	}
	color_control_layout cclData;
	if (	mpPreferenceSet->GetData(	"CCLAYOUT", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != CCLAYOUT))
	{
		mCCL = B_CELLS_8x32;
	}
	else
	{
		memcpy(	&cclData, 
				prefData, 
				prefDataSize);
		mCCL = cclData;
	}
	int32 i32Data;
	if (	mpPreferenceSet->GetData(	"MYSLIDERBARCOLOR", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != MYSLIDERBARCOLOR))
	{
		mui32ColorSliderBar = B_CONTROL_ON;
	}
	else
	{
		memcpy(	&i32Data, 
				prefData, 
				prefDataSize);
		mui32ColorSliderBar = i32Data;
	}
	if (	mpPreferenceSet->GetData(	"MYSLIDERBARFILL", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != MYSLIDERBARFILL))
	{
		mui32FillSliderBar = B_CONTROL_ON;
	}
	else
	{
		memcpy(	&i32Data, 
				prefData, 
				prefDataSize);
		mui32FillSliderBar = i32Data;
	}
	if (	mpPreferenceSet->GetData(	"BARHEIGHT", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != BARHEIGHT))
	{
		SetPreferredBarHeight(20);
	}
	else
	{
		memcpy(	&floatData, 
				prefData, 
				prefDataSize);
		SetPreferredBarHeight(floatData);
	}
	uint8 iu8Data;
	if (	mpPreferenceSet->GetData(	"COLORWELLWIDTH", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != BARHEIGHT))
	{
		SetPreferredColorWellWidth(20);
	}
	else
	{
		memcpy(	&iu8Data, 
				prefData, 
				prefDataSize);
		SetPreferredColorWellWidth(iu8Data);
	}
	if (	mpPreferenceSet->GetData(	"COLORWELLHEIGHT", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != BARHEIGHT))
	{
		SetPreferredColorWellHeight(20);
	}
	else
	{
		memcpy(	&iu8Data, 
				prefData, 
				prefDataSize);
		SetPreferredColorWellHeight(iu8Data);
	}
	bool boolData;
	if (	mpPreferenceSet->GetData(	"OPENFONTDISPLAY_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != OPENFONTDISPLAY_TYPE))
	{
		mbOpenFontDisplay = true;
	}
	else
	{
		memcpy(	&boolData, 
				prefData, 
				prefDataSize);
		mbOpenFontDisplay = boolData;
	}
	if (	mpPreferenceSet->GetData(	"ANTIALIASFONT_TYPE", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != ANTIALIASFONT_TYPE))
	{
		mbAntiAliasFont = true;
	}
	else
	{
		memcpy(	&boolData, 
				prefData, 
				prefDataSize);
		mbAntiAliasFont = boolData;
	}
	if (	mpPreferenceSet->GetData(	"USECOLORWELL", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != USECOLORWELL))
	{
		mbUseColorWell = true;
	}
	else
	{
		memcpy(	&boolData, 
				prefData, 
				prefDataSize);
		mbUseColorWell = boolData;
	}
	if (	mpPreferenceSet->GetData(	"USECOLORCONTROL", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != USECOLORCONTROL))
	{
		mbUseColorControl = true;
	}
	else
	{
		memcpy(	&boolData, 
				prefData, 
				prefDataSize);
		mbUseColorControl = boolData;
	}
	rgb_color prefsColor;
	if (	mpPreferenceSet->GetData(	"PreferredHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{

		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 100;
		prefsColor.green = 100;
		prefsColor.blue = 100;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredColorWellHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredColorWellHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredColorWellLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredColorWellLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredColorWellViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredColorWellViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt32ControlHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt32ControlHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt32ControlLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt32ControlLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt32ControlViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt32ControlViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt8GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt8GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt8GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 180;
		prefsColor.green = 215;
		prefsColor.blue = 180;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt8GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt8GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 139;
		prefsColor.green = 203;
		prefsColor.blue = 139;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt8GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt8GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt8GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt8GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 180;
		prefsColor.green = 180;
		prefsColor.blue = 215;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt8GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt8GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 139;
		prefsColor.green = 139;
		prefsColor.blue = 203;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt8GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt16GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt16GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt16GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 180;
		prefsColor.green = 203;
		prefsColor.blue = 180;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt16GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt16GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 128;
		prefsColor.green = 168;
		prefsColor.blue = 128;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt16GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt16GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt16GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt16GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 180;
		prefsColor.green = 180;
		prefsColor.blue = 203;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt16GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt16GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 128;
		prefsColor.green = 128;
		prefsColor.blue = 168;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt16GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt32GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt32GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt32GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 145;
		prefsColor.green = 162;
		prefsColor.blue = 145;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt32GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt32GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 93;
		prefsColor.green = 145;
		prefsColor.blue = 93;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt32GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt32GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt32GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt32GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 110;
		prefsColor.green = 110;
		prefsColor.blue = 162;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt32GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt32GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 93;
		prefsColor.green = 93;
		prefsColor.blue = 145;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt32GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt64GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt64GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt64GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 81;
		prefsColor.green = 151;
		prefsColor.blue = 81;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt64GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredInt64GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 116;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredInt64GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt64GadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt64GadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt64GadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 81;
		prefsColor.green = 81;
		prefsColor.blue = 151;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt64GadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredUInt64GadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 58;
		prefsColor.green = 58;
		prefsColor.blue = 209;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredUInt64GadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredFloatGadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredFloatGadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredFloatGadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 255;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredFloatGadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredFloatGadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 203;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredFloatGadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredHexGadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredHexGadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredHexGadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredHexGadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredHexGadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 222;
		prefsColor.green = 222;
		prefsColor.blue = 222;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredHexGadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredStringGadgetHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredStringGadgetHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredStringGadgetLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 151;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredStringGadgetLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredStringGadgetViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 81;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredStringGadgetViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredFloatControlHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredFloatControlHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredFloatControlLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredFloatControlLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredFloatControlViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredFloatControlViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredStringControlHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredStringControlHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredStringControlLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredStringControlLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredStringControlViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredStringControlViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredColorWellHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredColorWellHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredColorWellLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredColorWellLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredColorWellViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredColorWellViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyButtonHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyButtonHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyButtonLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyButtonLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyButtonViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyButtonViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyPictureButtonHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyPictureButtonHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyPictureButtonLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyPictureButtonLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyPictureButtonViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 188;
		prefsColor.green = 188;
		prefsColor.blue = 188;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyPictureButtonViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyCheckBoxHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyCheckBoxHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyCheckBoxLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyCheckBoxLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyCheckBoxViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyCheckBoxViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyStatusBarHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyStatusBarHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyStatusBarLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyStatusBarLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyStatusBarViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyStatusBarViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyBarStatusColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 23;
		prefsColor.green = 12;
		prefsColor.blue = 164;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyBarStatusColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMySliderHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMySliderHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMySliderViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMySliderViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMySliderLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMySliderLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyBarSliderColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 23;
		prefsColor.green = 12;
		prefsColor.blue = 164;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyBarSliderColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyBarFillSliderColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 164;
		prefsColor.green = 48;
		prefsColor.blue = 164;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyBarFillSliderColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyColorControlHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyColorControlHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyColorControlLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyColorControlLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyColorControlViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyColorControlViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyStringDrawerHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyStringDrawerHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyStringDrawerLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{

		prefsColor.red = 151;
		prefsColor.green = 151;
		prefsColor.blue = 151;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyStringDrawerLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyStringDrawerViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyStringDrawerViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyRadioViewHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyRadioViewHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyRadioViewLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{

		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyRadioViewLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyRadioViewViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 166;
		prefsColor.green = 166;
		prefsColor.blue = 166;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyRadioViewViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyTextViewHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{

		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyTextViewHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyTextViewLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{

		prefsColor.red = 200;
		prefsColor.green = 200;
		prefsColor.blue = 200;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyTextViewLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyTextViewViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 254;
		prefsColor.green = 254;
		prefsColor.blue = 254;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyTextViewViewColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyListViewHighColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{

		prefsColor.red = 0;
		prefsColor.green = 0;
		prefsColor.blue = 0;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyListViewHighColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyListViewLowColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{

		prefsColor.red = 145;
		prefsColor.green = 145;
		prefsColor.blue = 168;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyListViewLowColor(&prefsColor);
	if (	mpPreferenceSet->GetData(	"PreferredMyListViewViewColor", 
										prefData, 
										prefDataSize, 
										prefDataType) 
			|| 
			(prefDataType != B_RGB_COLOR_TYPE))
	{
		prefsColor.red = 151;
		prefsColor.green = 151;
		prefsColor.blue = 168;
		prefsColor.alpha = 255;
	}
	else
	{
		memcpy(	&prefsColor, 
				prefData, 
				prefDataSize);
	}
	SetPreferredMyListViewViewColor(&prefsColor);
	BRect	screenResolutionRect;
	{//I do screen like this so it goes away fast
		BScreen	screen(B_MAIN_SCREEN_ID);
		if(!screen.IsValid()) 
		{//may not be valid, if not, this is not a critical app--bail out as best we can
			puts(ScreenNotValid);
			exit(4);
		}
		screenResolutionRect = screen.Frame();
	}
	BRect windowPrefArea;
	const void * windowPrefAreaData;
	ssize_t windowPrefAreaSize;
	uint32 windowPrefAreaType = '    ';
	if (	mpPreferenceSet->GetData(	"PrefPanelFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
					//the - 17 and - 37 were determined based upon trial and error
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredPrefPanelWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	"FontPrefFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredFontPrefWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	"FontDisplayWindowFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredFontDisplayWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	"BasicColorWindowFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredBasicColorWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_BUTTON], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorButtonWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_PICTURE], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorPictureButtonWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_RADIOVIEW], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorRadioButtonWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_CHECKBOX], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorCheckBoxWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_STATUSBAR], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorStatusBarWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_SLIDER], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorSliderWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_COLORCONTROL], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorColorControlWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_TEXTVIEW], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorTextViewWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_LISTVIEW], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorListViewWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_UINT32CONTROL], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorUInt32ControlWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_INT8GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorInt8GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_UINT8GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorUInt8GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_INT16GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorInt16GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_UINT16GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorUInt16GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_INT32GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorInt32GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_UINT32GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorUInt32GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_INT64GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorInt64GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_UINT64GADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorUInt64GadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_FLOATGADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorFloatGadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_STRINGGADGET], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorStringGadgetWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_FLOATCONTROL], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorFloatControlWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_STRINGCONTROL], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorStringControlWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_COLORWELL], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorColorWellWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	namePrefFrame[SPECIFIC_COLOR_STRINGDRAWER], 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredSpecificColorStringDrawerWindowRect(windowPrefArea);
	if (	mpPreferenceSet->GetData(	"ListViewWindowFrame", 
										windowPrefAreaData, 
										windowPrefAreaSize, 
										windowPrefAreaType) 
			|| 
			(windowPrefAreaType != B_RECT_TYPE))
	{
		windowPrefArea.Set(	5,
							22, 
							screenResolutionRect.right - 17,
							screenResolutionRect.bottom - 37);
	}
	else
	{
		memcpy(	&windowPrefArea, 
				windowPrefAreaData, 
				windowPrefAreaSize);
	}
	SetPreferredListViewWindowRect(windowPrefArea);
}//end