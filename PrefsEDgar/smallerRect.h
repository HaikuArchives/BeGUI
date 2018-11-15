//smallerRect.h

#ifndef SMALLERRECT
#define SMALLERRECT
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
	EXTERN_C UGLY_IMPEXP bool RectASmallerRectB(	BRect paramA,
													BRect paramB);
#endif