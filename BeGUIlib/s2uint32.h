//s2uint32.h

#ifndef GUI_S2UI32
#define GUI_S2UI32
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	#define S2UIERR ('s2ur')
	#if defined(__cplusplus)
 		#define EXTERN_C extern "C"
	#else
		 #define EXTERN_C extern
	#endif
	EXTERN_C UGLY_IMPEXP status_t s2uint32(	const char * in, 
											uint32 * paramFillMe);
#endif