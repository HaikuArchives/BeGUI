//s2int64.h

#ifndef GUI_S2I64
#define GUI_S2I64
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	#define S2I64ERR ('s26r')
	#if defined(__cplusplus)
 		#define EXTERN_C extern "C"
	#else
		 #define EXTERN_C extern
	#endif
	EXTERN_C UGLY_IMPEXP status_t s2int64(	const char * in, 
											int64 * paramFillMe);
#endif