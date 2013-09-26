//myPreferences.h

#ifndef MYPREFERENCES
#define MYPREFERENCES
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP PrefPanelWindow;
	class UGLY_IMPEXP FontData;
	#define OPENFONTDISPLAY_TYPE 'ofdt'
	#define ANTIALIASFONT_TYPE 'aaft'
	#define USECOLORWELL 'ucw '
	#define USECOLORCONTROL 'ucc '
	#define BARHEIGHT 'BarH'
	#define THUMBSTYLE 'Thmb'
	#define COLORWELLWIDTH ' cwW'
	#define COLORWELLHEIGHT ' cwH'
	#define MYSLIDERBARCOLOR 'MsBc'
	#define MYSLIDERBARFILL 'MsBf'
	#define CCLAYOUT 'cLAY'
	#define REOPEN 'rOpn'

	class UGLY_IMPEXP 
	MyPreferences
	{
	private:
		BFont *				preferredFont;
		float				preferredBarHeight;
		thumb_style			mtsThumbStyle;
		uint8				preferredColorWellWidth;
		uint8				preferredColorWellHeight;
		BRect				preferredPrefPanelWindowRect;
		BRect				preferredFontPrefWindowRect;
		BRect				preferredFontDisplayWindowRect;
		BRect				preferredBasicColorWindowRect;
		BRect				preferredSpecificColorButtonWindowRect;
		BRect				preferredSpecificColorPictureButtonWindowRect;
		BRect				preferredSpecificColorRadioButtonWindowRect;
		BRect				preferredSpecificColorCheckBoxWindowRect;
		BRect				preferredSpecificColorStatusBarWindowRect;
		BRect				preferredSpecificColorSliderWindowRect;
		BRect				preferredSpecificColorColorControlWindowRect;
		BRect				preferredSpecificColorTextViewWindowRect;
		BRect				preferredSpecificColorListViewWindowRect;
		BRect				preferredSpecificColorUInt32ControlWindowRect;
		BRect				preferredSpecificColorFloatControlWindowRect;
		BRect				preferredSpecificColorStringControlWindowRect;
		BRect				preferredSpecificColorColorWellWindowRect;
		BRect				preferredSpecificColorStringDrawerWindowRect;
		BRect				preferredSpecificColorInt8GadgetWindowRect;
		BRect				preferredSpecificColorUInt8GadgetWindowRect;
		BRect				preferredSpecificColorInt16GadgetWindowRect;
		BRect				preferredSpecificColorUInt16GadgetWindowRect;
		BRect				preferredSpecificColorInt32GadgetWindowRect;
		BRect				preferredSpecificColorUInt32GadgetWindowRect;
		BRect				preferredSpecificColorInt64GadgetWindowRect;
		BRect				preferredSpecificColorUInt64GadgetWindowRect;
		BRect				preferredSpecificColorFloatGadgetWindowRect;
		BRect				preferredSpecificColorHexGadgetWindowRect;
		BRect				preferredSpecificColorStringGadgetWindowRect;
		BRect				preferredListViewWindowRect;
		rgb_color			preferredHighColor;
		rgb_color			preferredLowColor;
		rgb_color			preferredViewColor;
		rgb_color			preferredUInt32ControlHighColor;
		rgb_color			preferredUInt32ControlLowColor;
		rgb_color			preferredUInt32ControlViewColor;
		rgb_color			preferredFloatControlHighColor;
		rgb_color			preferredFloatControlLowColor;
		rgb_color			preferredFloatControlViewColor;
		rgb_color			preferredInt8GadgetHighColor;
		rgb_color			preferredInt8GadgetLowColor;
		rgb_color			preferredInt8GadgetViewColor;
		rgb_color			preferredUInt8GadgetHighColor;
		rgb_color			preferredUInt8GadgetLowColor;
		rgb_color			preferredUInt8GadgetViewColor;
		rgb_color			preferredInt16GadgetHighColor;
		rgb_color			preferredInt16GadgetLowColor;
		rgb_color			preferredInt16GadgetViewColor;
		rgb_color			preferredUInt16GadgetHighColor;
		rgb_color			preferredUInt16GadgetLowColor;
		rgb_color			preferredUInt16GadgetViewColor;
		rgb_color			preferredInt32GadgetHighColor;
		rgb_color			preferredInt32GadgetLowColor;
		rgb_color			preferredInt32GadgetViewColor;
		rgb_color			preferredUInt32GadgetHighColor;
		rgb_color			preferredUInt32GadgetLowColor;
		rgb_color			preferredUInt32GadgetViewColor;
		rgb_color			preferredInt64GadgetHighColor;
		rgb_color			preferredInt64GadgetLowColor;
		rgb_color			preferredInt64GadgetViewColor;
		rgb_color			preferredUInt64GadgetHighColor;
		rgb_color			preferredUInt64GadgetLowColor;
		rgb_color			preferredUInt64GadgetViewColor;
		rgb_color			preferredFloatGadgetHighColor;
		rgb_color			preferredFloatGadgetLowColor;
		rgb_color			preferredFloatGadgetViewColor;
		rgb_color			preferredHexGadgetHighColor;
		rgb_color			preferredHexGadgetLowColor;
		rgb_color			preferredHexGadgetViewColor;
		rgb_color			preferredStringGadgetHighColor;
		rgb_color			preferredStringGadgetLowColor;
		rgb_color			preferredStringGadgetViewColor;
		rgb_color			preferredMyStatusBarHighColor;
		rgb_color			preferredMyStatusBarLowColor;
		rgb_color			preferredMyStatusBarViewColor;
		rgb_color			preferredMyBarStatusColor;
		rgb_color			preferredMySliderHighColor;
		rgb_color			preferredMySliderLowColor;
		rgb_color			preferredMySliderViewColor;
		rgb_color			preferredMyBarSliderColor;
		rgb_color			preferredMyBarFillSliderColor;
		rgb_color			preferredMyPictureButtonHighColor;
		rgb_color			preferredMyPictureButtonLowColor;
		rgb_color			preferredMyPictureButtonViewColor;
		rgb_color			preferredMyCheckBoxHighColor;
		rgb_color			preferredMyCheckBoxLowColor;
		rgb_color			preferredMyCheckBoxViewColor;
		rgb_color			preferredMyColorControlHighColor;
		rgb_color			preferredMyColorControlLowColor;
		rgb_color			preferredMyColorControlViewColor;
		rgb_color			preferredColorWellHighColor;
		rgb_color			preferredColorWellLowColor;
		rgb_color			preferredColorWellViewColor;
		rgb_color			preferredMyButtonHighColor;
		rgb_color			preferredMyButtonLowColor;
		rgb_color			preferredMyButtonViewColor;
		rgb_color			preferredMyStringDrawerHighColor;
		rgb_color			preferredMyStringDrawerLowColor;
		rgb_color			preferredMyStringDrawerViewColor;
		rgb_color			preferredMyRadioViewHighColor;
		rgb_color			preferredMyRadioViewLowColor;
		rgb_color			preferredMyRadioViewViewColor;
		rgb_color			preferredMyTextViewLowColor;
		rgb_color			preferredMyTextViewHighColor;
		rgb_color			preferredMyTextViewViewColor;
		rgb_color			preferredMyListViewLowColor;
		rgb_color			preferredMyListViewHighColor;
		rgb_color			preferredMyListViewViewColor;
		rgb_color			preferredStringControlHighColor;
		rgb_color			preferredStringControlLowColor;
		rgb_color			preferredStringControlViewColor;
							MyPreferences(	const MyPreferences& copy);//not implemented on purpose
		MyPreferences&		operator = (	const MyPreferences& assign);//not implemented on purpose
	public:
		PrefPanelWindow *	pPrefPanelWindow;
		Preferences *		mpPreferences;
		PreferenceSet *		mpPreferenceSet;
		const char			* lvwTitleStr[NUMPREFPANELS - 1],
							* buttonLabels[NUMPREFPANELS],
							* PrefSignature,
							* PreferencePanelWindowTitle,
							* FailScrollView,
							* FailMemory,
							* NotFoundScrollView,
							* FailLockLooper,
							* PrefNoSetGutFrame,
							* AboutGutMsg,
							* FailAqSem,
							* FailCreateSemaphore,
							* BasicColorWindowTitle,
							* NoBasicColorWindow,
							* NoSpecColorWindow,
							* BasicColorWindowHeading1,
							* noCCenabled,
							* ColorWindowHeading2,
							* ColorWindowHeading3,
							* ColorWindowHeading4,
							* ColorWindowHeading5,
							* ColorWindowHeading6,
							* ColorWindowHeading7,
							* CaughtBasicColorWindowCTOR,
							* AboutBasicColorWindowMsg1,
							* AboutBasicColorWindowMsg2,
							* BadSpecColorKindView,
							* BadSpecColorKindHigh,
							* BadSpecColorKindLow,
							* CaughtSpecificColorWindowCTOR,
							* AboutSpecColorWindow,
							* BadSpecKindQR,
							* SelectFromList,
							* InvokeFromList,
							* BadSpecKindColorSetView,
							* BadSpecKindColorSetHigh,
							* BadSpecKindColorSetLow,
							* DemoButtonLabel,
							* AppMenuLabel,
							* AboutMenuLabel,
							* CloseWindow,
							* QuitMenuLabel,
							* ReallyQuitApp,
							* DemoRadio1Label,
							* DemoRadio2Label,
							* DemoRadio3Label,
							* RadioViewFailInit,
							* DemoCheckBoxLabel,
							* DemoStatusBarLeadLabel,
							* DemoStatusBarTrailLabel,
							* TextGadgetLabel,
							* ListViewSample1,
							* ListViewSample2,
							* ListViewSample3,
							* UInt32ControlLabel,
							* PreferenceMenuLabel,
							* FloatControlLabel,
							* StringControlLabel,
							* DemoRoLabel,
							* DemoTextItemText,
							* BadSpecItemKind,
							* BarColorTitle,
							* BarCCLabel,
							* BarCWLabel,
							* EnterBarHeightLabel,
							* EnterColorWellWidthLabel,
							* EnterColorWellHeightLabel,
							* DemoRoNo,
							* RoBadMsg,
							* FailRadioInit,
							* FailPUMInit,
							* BMsgAddXFailPUMInit,
							* FontPrefWindowTitle,
							* PrefPanelWindowHeading1,
							* PrefPanelFontButtonLabel,
							* PrefPanelWindowHeading2,
							* DisplayBColorControls,
							* DisplayroColourWells,
							* CaughtPrefPanelWindowCTOR,
							* AboutPrefPanelWindow,
							* FontPrefWindowHeading1,
							* BiggerFontButtonLabel,
							* SmallerFontButtonLabel,
							* EnterFontSizeLabel,
							* DisplayFontCheckBoxLabel,
							* FontFamilyPUMLabel,
							* FailPUMInitFontWindow,
							* FontStylePUMLabel,
							* AntiAliasFont,
							* FontDisplayWindowTitle,
							* FailFontDisplayWindow,
							* FontDisplayNotNull,
							* FailMinFontSize,
							* FailMaxFontSize,
							* CaughtFontPrefWindowCTOR,
							* AboutFontPrefWindowMsg1,
							* AboutFontPrefWindowMsg2,
							* AboutFontPrefWindowMsg3,
							* AboutFontPrefWindowMsg4,
							* AboutFontPrefWindowMsg5,
							* AboutFontPrefWindowMsg6,
							* NoAdditem,
							* failMenu,
							* WarningOKLabel,
							* AboutFontDisplayWindow,
							* VerifyCancel,
							* VerifyDoNot,
							* VerifyDo,
							* truncShort,
							* S2UI32Neg,
							* S2UI32OutOfRange,
							* S2UI32Invalid,
							* PrefsNoSetFloatControlHighColor,
							* PrefsNoSetAntiAliasFont,
							* PrefsNoSetBarHeight,
							* PrefsNoSetColorWellWidth,
							* PrefsNoSetColorWellHeight,
							* PrefsNoSetFloatControlLowColor,
							* PrefsNoSetFloatControlViewColor,
							* PrefsNoSetColorWellHighColor,
							* PrefsNoSetolorWellLowColor,
							* PrefsNoSetColorWellViewColor,
							* PrefsNoSetUInt32ControlHighColor,
							* PrefsNoSetUInt32ControlLowColor,
							* PrefsNoSetUInt32ControlViewColor,
							* PrefsNoSetInt8GadgetHighColor,
							* PrefsNoSetInt8GadgetLowColor,
							* PrefsNoSetInt8GadgetViewColor,
							* PrefsNoSetUInt8GadgetHighColor,
							* PrefsNoSetUInt8GadgetLowColor,
							* PrefsNoSetUInt8GadgetViewColor,
							* PrefsNoSetInt16GadgetHighColor,
							* PrefsNoSetInt16GadgetLowColor,
							* PrefsNoSetInt16GadgetViewColor,
							* PrefsNoSetUInt16GadgetHighColor,
							* PrefsNoSetUInt16GadgetLowColor,
							* PrefsNoSetUInt16GadgetViewColor,
							* PrefsNoSetInt32GadgetHighColor,
							* PrefsNoSetInt32GadgetLowColor,
							* PrefsNoSetInt32GadgetViewColor,
							* PrefsNoSetUInt32GadgetHighColor,
							* PrefsNoSetUInt32GadgetLowColor,
							* PrefsNoSetUInt32GadgetViewColor,
							* PrefsNoSetInt64GadgetHighColor,
							* PrefsNoSetInt64GadgetLowColor,
							* PrefsNoSetInt64GadgetViewColor,
							* PrefsNoSetUInt64GadgetHighColor,
							* PrefsNoSetUInt64GadgetLowColor,
							* PrefsNoSetUInt64GadgetViewColor,
							* PrefsNoSetFloatGadgetHighColor,
							* PrefsNoSetFloatGadgetLowColor,
							* PrefsNoSetFloatGadgetViewColor,
							* PrefsNoSetHexGadgetHighColor,
							* PrefsNoSetHexGadgetLowColor,
							* PrefsNoSetHexGadgetViewColor,
							* PrefsNoSetStringGadgetHighColor,
							* PrefsNoSetStringGadgetLowColor,
							* PrefsNoSetStringGadgetViewColor,
							* PrefsNoSetMyButtonHighColor,
							* PrefsNoSetMyButtonLowColor,
							* PrefsNoSetMyButtonViewColor,
							* PrefsNoSetMyPictureButtonHighColor,
							* PrefsNoSetMyPictureButtonLowColor,
							* PrefsNoSetMyPictureButtonViewColor,
							* PrefsNoSetMyCheckBoxHighColor,
							* PrefsNoSetMyCheckBoxLowColor,
							* PrefsNoSetMyCheckBoxViewColor,
							* PrefsNoSetMyStatusBarHighColor,
							* PrefsNoSetMyStatusBarLowColor,
							* PrefsNoSetMyStatusBarViewColor,
							* PrefsNoSetMyBarStatusColor,
							* PrefsNoSetMySliderHighColor,
							* PrefsNoSetMySliderLowColor,
							* PrefsNoSetMySliderViewColor,
							* PrefsNoSetMyBarSliderColor,
							* PrefsNoSetMyColorControlHighColor,
							* PrefsNoSetMyColorControlLowColor,
							* PrefsNoSetMyColorControlViewColor,
							* PrefsNoSetMyStringDrawerHighColor,
							* PrefsNoSetMyStringDrawerLowColor,
							* PrefsNoSetMyStringDrawerViewColor,
							* PrefsNoSetMyRadioViewHighColor,
							* PrefsNoSetMyRadioViewLowColor,
							* PrefsNoSetMyRadioViewViewColor,
							* PrefsNoSetMyTextViewHighColor,
							* PrefsNoSetMyTextViewLowColor,
							* PrefsNoSetMyTextViewViewColor,
							* PrefsNoSetMyListViewHighColor,
							* PrefsNoSetMyListViewLowColor,
							* PrefsNoSetMyListViewViewColor,
							* PrefsNoSetHighColor,
							* PrefsNoSetLowColor,
							* PrefsNoSetViewColor,
							* PrefsNoSetFont,
							* PrefsNoSetOpenFontDisplay,
							* PrefsNoSetUseColorWell,
							* PrefsNoSetUseColorControl,
							* ScreenNotValid,
							* PrefsNoSaveSet,
							* PrefFailInit,
							* PrefFailGetSettings,
							* PrefFailSetSettings,
							* NoPrefPanelWindow,
							* MessageFindBytes,
							* NumStrTooLong,
							* NumTooBig,
							* NumTooSmall,
							* S2I32OutOfRange,
							* S2I32Invalid,
							* S2I64OutOfRange,
							* S2I64Invalid,
							* S2UI64OutOfRange,
							* S2UI64Invalid,
							* WrongKindLMI,
							* AboutSimpleWindowMsg,
							* GetInt8GadgetLabel,
							* GetUInt8GadgetLabel,
							* GetInt16GadgetLabel,
							* GetUInt16GadgetLabel,
							* GetInt32GadgetLabel,
							* GetUInt32GadgetLabel,
							* GetInt64GadgetLabel,
							* GetUInt64GadgetLabel,
							* GetFloatGadgetLabel,
							* GetHexGadgetLabel,
							* GetDoubleGadgetLabel,
							* GetLongDoubleGadgetLabel,
							* GetStringGadgetLabel,
							* PrefNoSetBaseFrame,
							* AboutBaseMsg,
							* DemoRadioLabelThumbRect,
							* DemoRadioLabelThumbTri,
							* PrefsNoSetThumbStyle,
							* IllegalThumb,
							* ColorSliderBarCBLabel,
							* FillSliderBarCBLabel,
							* SliderBarFillColorLabel,
							* PrefsNoSetMyBarFillSliderColor,
							* PrefsNoSetMyBarFillSlider,
							* PrefsNoSetMyBarColorSlider,
							* FillCWLabel,
							* FillCCLabel,
							* ColorControlKind,
							* CC_4x64_Cell,
							* CC_8x32_Cell,
							* CC_16x16_Cell,
							* CC_32x8_Cell,
							* CC_64x4_Cell,
							* PrefsNoSetCCLayout,
							* FailReopen,
							* StringTooLongToMeasure,
							* AlphaNumeric;
		bool				mbPrefChangesMade;
		bool				mbUseColorWell;
		bool				mbUseColorControl;
		bool				mbOpenFontDisplay;
		bool				mbAntiAliasFont;
		int32				mui32ColorSliderBar;
		int32				mui32FillSliderBar;
		color_control_layout	mCCL;
		BString				mbsVersion;
							MyPreferences();
		virtual				~MyPreferences();
		thumb_style			GetPreferredThumbStyle(	void) const;
		void				SetPreferredThumbStyle(	const thumb_style paramThumbStyle);
		float				GetPreferredBarHeight(	void) const;
		void				SetPreferredBarHeight(	const float paramBarHeight);
		uint8				GetPreferredColorWellWidth(	void) const;
		void				SetPreferredColorWellWidth(	const uint8 paramColorWellWidth);
		uint8				GetPreferredColorWellHeight(	void) const;
		void				SetPreferredColorWellHeight(	const uint8 paramColorWellHeight);
		BFont *				GetPreferredFont(	void) const;
		void				SetPreferredFont(	const BFont * paramFont);
		void				SetToPreferredFont(	BFont * paramFont);
		void				SetPreferredFontFromData(	FontData * paramFontData);
		void				GetPreferredPreferencesWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredPreferencesWindowRect(	const BRect paramWindowRect);
		void				GetPreferredPrefPanelWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredPrefPanelWindowRect(	const BRect paramWindowRect);
		void				GetPreferredFontPrefWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredFontPrefWindowRect(	const BRect paramWindowRect);
		void				GetPreferredFontDisplayWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredFontDisplayWindowRect(	const BRect paramWindowRect);
		void				GetPreferredBasicColorWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredBasicColorWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorRadioButtonWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorRadioButtonWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorCheckBoxWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorCheckBoxWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorStatusBarWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorStatusBarWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorSliderWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorSliderWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorColorControlWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorColorControlWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorButtonWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorButtonWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorPictureButtonWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorPictureButtonWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorTextViewWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorTextViewWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorListViewWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorListViewWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorUInt32ControlWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorUInt32ControlWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorFloatControlWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorFloatControlWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorStringControlWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorStringControlWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorColorWellWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorColorWellWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorStringDrawerWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorStringDrawerWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorInt8GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorInt8GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorUInt8GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorUInt8GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorInt16GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorInt16GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorUInt16GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorUInt16GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorInt32GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorInt32GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorUInt32GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorUInt32GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorInt64GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorInt64GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorUInt64GadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorUInt64GadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorFloatGadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorFloatGadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorHexGadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorHexGadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredSpecificColorStringGadgetWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredSpecificColorStringGadgetWindowRect(	const BRect paramWindowRect);
		void				GetPreferredListViewWindowRect(	BRect * paramWindowRect) const;
		void				SetPreferredListViewWindowRect(	const BRect paramWindowRect);
		void				GetPreferredHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt32ControlHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt32ControlHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt32ControlLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt32ControlLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt32ControlViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt32ControlViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredFloatControlHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredFloatControlHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredFloatControlLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredFloatControlLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredFloatControlViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredFloatControlViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt8GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt8GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt8GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt8GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt8GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt8GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt8GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt8GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt8GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt8GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt8GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt8GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt16GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt16GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt16GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt16GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt16GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt16GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt16GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt16GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt16GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt16GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt16GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt16GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt32GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt32GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt32GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt32GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt32GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt32GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt32GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt32GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt32GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt32GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt32GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt32GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt64GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt64GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt64GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt64GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredUInt64GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredUInt64GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt64GadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt64GadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt64GadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt64GadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredInt64GadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredInt64GadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredFloatGadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredFloatGadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredFloatGadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredFloatGadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredFloatGadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredFloatGadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredHexGadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredHexGadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredHexGadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredHexGadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredHexGadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredHexGadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredStringGadgetHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredStringGadgetHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredStringGadgetLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredStringGadgetLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredStringGadgetViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredStringGadgetViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredColorWellHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredColorWellHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredColorWellLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredColorWellLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredColorWellViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredColorWellViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyButtonHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyButtonHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyButtonLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyButtonLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyButtonViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyButtonViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyCheckBoxHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyCheckBoxHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyCheckBoxLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyCheckBoxLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyCheckBoxViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyCheckBoxViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyPictureButtonHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyPictureButtonHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyPictureButtonLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyPictureButtonLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyPictureButtonViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyPictureButtonViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyColorControlHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyColorControlHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyColorControlLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyColorControlLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyColorControlViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyColorControlViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyStatusBarHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyStatusBarHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyStatusBarLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyStatusBarLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyStatusBarViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyStatusBarViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyBarStatusColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyBarStatusColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMySliderHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMySliderHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMySliderLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMySliderLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMySliderViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMySliderViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyBarSliderColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyBarSliderColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyBarFillSliderColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyBarFillSliderColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyStringDrawerHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyStringDrawerHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyStringDrawerLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyStringDrawerLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyStringDrawerViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyStringDrawerViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyRadioViewHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyRadioViewHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyRadioViewLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyRadioViewLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyRadioViewViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyRadioViewViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyTextViewHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyTextViewHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyTextViewLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyTextViewLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyTextViewViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyTextViewViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyListViewHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyListViewHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyListViewLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyListViewLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredMyListViewViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredMyListViewViewColor(	const rgb_color * paramRGBColor);
		void				GetPreferredStringControlHighColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredStringControlHighColor(	const rgb_color * paramRGBColor);
		void				GetPreferredStringControlLowColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredStringControlLowColor(	const rgb_color * paramRGBColor);
		void				GetPreferredStringControlViewColor(	rgb_color * paramRGBColor) const;
		void				SetPreferredStringControlViewColor(	const rgb_color * paramRGBColor);
		void				OpenPreferencesPanel(	void);
	};
	#if NOTX_MYPREF
		UGLY_IMPEXP MyPreferences * myPrefs;
	#else
		UGLY_IMPEXP extern MyPreferences * myPrefs;
	#endif
#endif