//filterIntNumeric.h

#ifndef FILTERINTNUMERIC
#define FILTERINTNUMERIC
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
	EXTERN_C UGLY_IMPEXP filter_result filterIntNumeric(	BMessage * message, 
															BHandler **,// target, 
															BMessageFilter *);// messageFilter);
#endif