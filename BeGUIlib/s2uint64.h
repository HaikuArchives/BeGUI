//s2uint64.h

#ifndef GUI_S2UI64
#define GUI_S2UI64
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	#define S2UI64ERR ('s2u6')
	#if defined(__cplusplus)
 		#define EXTERN_C extern "C"
	#else
		 #define EXTERN_C extern
	#endif
	EXTERN_C UGLY_IMPEXP status_t s2uint64(	const char * in, 
											uint64 * paramFillMe);
#endif