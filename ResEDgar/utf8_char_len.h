//utf8_char_len.h

#ifndef UTF8CHARLEN
#define UTF8CHARLEN
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
	EXTERN_C UGLY_IMPEXP uint32 utf8_char_len(uchar byte);
#endif