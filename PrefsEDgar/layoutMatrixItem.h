//layoutMatrixItem.h

#ifndef GUI_LAYOUTMATRIXITEM
#define GUI_LAYOUTMATRIXITEM
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	#define KIND_MYBUTTON 0
	#define KIND_MYPICTUREBUTTON 1
	#define KIND_MYRADIOVIEW 2
	#define KIND_MYCHECKBOX 3
	#define KIND_MYSTATUSBAR 4
	#define KIND_MYCOLORCONTROL 5
	#define KIND_COLORWELL 6
	#define KIND_INT8GADGET 7
	#define KIND_UINT8GADGET 8
	#define KIND_INT16GADGET 9
	#define KIND_UINT16GADGET 10
	#define KIND_INT32GADGET 11
	#define KIND_UINT32GADGET 12
	#define KIND_INT64GADGET 13
	#define KIND_UINT64GADGET 14
	#define KIND_FLOATGADGET 15
	#define KIND_STRINGGADGET 16
	#define KIND_STRINGCONTROL 17
	#define KIND_MYTEXTVIEW 18
	#define KIND_STRINGDRAWER 19
	#define KIND_MYLISTVIEW 20
	#define KIND_FLOATCONTROL 21
	#define KIND_UINT32CONTROL 22
	#define KIND_MYPOPUPMENU 23
	#define KIND_MYSPACER 24
	#define KIND_TEXT 25
	#define KIND_MYSLIDER 26
	#define KIND_HEXGADGET 27
	#define MINVIEWGADGETWIDTH 10

	class UGLY_IMPEXP
	LayoutMatrixItem 
	{
	private:
							LayoutMatrixItem(	const LayoutMatrixItem& copy);//not implemented on purpose
		LayoutMatrixItem&	operator = (	const LayoutMatrixItem& assign);//not implemented on purpose
	public:
		void *				mpItem;
		float				mfWidthPref;
		float				mfHeightPref;
		uint32				mui32Kind;
							LayoutMatrixItem(	void * paramItem, 
												LayoutMatrix * paramLayoutMatrix,
												const uint32 paramKind);
		virtual				~LayoutMatrixItem();
		virtual void		Calc();
	};
#endif
