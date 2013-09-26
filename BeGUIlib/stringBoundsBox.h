//stringBoundsBox.h

#ifndef STRINGBOUNDSBOX
#define STRINGBOUNDSBOX
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
	const int32 DEFAULT_MAX_FANCY_WIDTH = 600;
	const int32 DEFUALT_MAX_FANCY_HEIGHT = 480;
	const int32 RECTARRAYLENGTH = 1024;
	const int32 GOODJOB = 1;
	const int32 BADJOB = 0;
	const int32 NOJOB = -1;
	
	EXTERN_C UGLY_IMPEXP int32 StringBoundsBox(	const char * paramString,
												float * paramWidth,
												float * paramHeight,
												float * paramLeftOffset,
												float * paramBaseline,
												BFont * paramFont = NULL);
#endif