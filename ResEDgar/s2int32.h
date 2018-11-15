//s2int32.h

#ifndef GUI_S2I32
#define GUI_S2I32
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	#define S2IERR ('s2ir')
	#if defined(__cplusplus)
 		#define EXTERN_C extern "C"
	#else
		 #define EXTERN_C extern
	#endif
	EXTERN_C UGLY_IMPEXP status_t s2int32(	const char * in, 
											int32 * paramFillMe);
#endif