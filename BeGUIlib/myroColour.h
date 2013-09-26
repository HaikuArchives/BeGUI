//I dug this out of it's own directory and made a copy here so I could distribute a
//compilable app will all .h files
//roColour stuff

#ifndef RO_COLOR_STUFF
#define RO_COLOR_STUFF
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	#define RO_COLOR_STRUCT_128_TYPE 'roCr'

	struct UGLY_IMPEXP
	roSColor 
	{
	    float	m_Red;
	    float	m_Green;
	    float	m_Blue;
	    float	m_Alpha;
	    float	m_Hue;
	};
#endif