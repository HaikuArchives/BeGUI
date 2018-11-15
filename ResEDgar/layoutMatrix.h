//layoutMatrix.h

#ifndef GUI_LAYOUTMATRIX
#define GUI_LAYOUTMATRIX
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP ScrollingWindow;
	class UGLY_IMPEXP BaseWindow;
	#define SAMESIZE 1
	#define BESTSIZE 2
	/*the next two are int constants which will hopefully become preferences*/
	#define MATRIXVERTICALOFFSET 5
	#define MATRIXHORIZONTALOFFSET 5

	class UGLY_IMPEXP
	LayoutMatrix 
	{
	private:
						LayoutMatrix(	const LayoutMatrix& copy);//not implemented on purpose
		LayoutMatrix&	operator = (	const LayoutMatrix& assign);//not implemented on purpose
	public:
		BList *			mpItemsList;
		BList *			mpChildrenToAdd;
		BList *			mpItemsToDraw;
		BList *			mpLayoutMatrixItems;
		float			mfBottom;
		float			mfRight;
		uint32			mui32Rows;
		uint32			mui32Columns;
		uint32			mui32Flags;
		virtual void	AddToChildren(	void * paramItem);
		virtual void	AddToDraw(	void * paramItem);
						LayoutMatrix(	const uint32 paramFlags, 
										const uint32 paramRows, 
										const uint32 paramColumns,
	    								ScrollingWindow * paramScrollingWindow);
						LayoutMatrix(	const uint32 paramFlags, 
										const uint32 paramRows, 
										const uint32 paramColumns,
	    								BaseWindow * paramBaseWindow);
		virtual			~LayoutMatrix();
		virtual void	Calc(	const float paramMatrixLeft, 
								const float paramMatrixTop,
								sem_id paramSemID);
	};
#endif
