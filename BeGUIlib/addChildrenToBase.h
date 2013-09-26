//addChildrenToBase.h

#ifndef ADDCHILDREN
#define ADDCHILDREN
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	#if defined(__cplusplus)
 		#define EXTERN_C extern "C"
	#else
		 #define EXTERN_C extern
	#endif
	EXTERN_C UGLY_IMPEXP void AddChildrenToBase(	BList * paramBList,
													BView * paramBView,
													int32 paramNumItems,
													BList * paramBListSVL,
													BList * paramBListTIL,
													BLooper * paramLooper);
#endif