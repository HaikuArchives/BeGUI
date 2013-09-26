//s2f.h

#ifndef GUI_S2F
#define GUI_S2F
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
	#define S2FERR ('s2fr')
	
	EXTERN_C UGLY_IMPEXP status_t s2f(	const char * in, 
										float *paramFillMe);
#endif