//font data 
/*
I borrowed some of this this stuff, see:

This archive includes code to help in manipulating BFont objects in
BMessages.  The code is contained in the files FFont.cpp and FFont.h,
which can be copied for use in your own projects....

See the file FFont.html for more information.  Note that this
documentation was written very quickly just to get something out.  It
has been minimally proof-read, so there are surely lots of spelling
mistakes and problems.  Please feel free to e-mail me with any
questions, suggestions, or corrections.

-- Dianne Hackborn <hackbod@lucent.com>, Sept. 22, 1997
*/

#ifndef FONTDATA
#define FONTDATA
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	#define FONTDATA_SIZE_TYPE 'size'
	#define FONTDATA_SHEAR_TYPE 'shea'
	#define FONTDATA_ROTATION_TYPE 'rota'
	#define FONTDATA_FLAGS_TYPE 'flag'
	#define FONTDATA_FACE_TYPE 'face'
	#define FONTDATA_SPACING_TYPE 'spac'
	#define FONTDATA_ENOCDING_TYPE 'enco'
	#define FONTDATA_FANDS_TYPE 'FanS'

	class UGLY_IMPEXP
	FontData
	{
	private:
					FontData(	const FontData& copy);//not implemented on purpose
		FontData&	operator = (	const FontData& assign);//not implemented on purpose
	public:
		float		mfSize;
		float		mfShear;
		float		mfRotation;
		uint32		mui32Flags;
		uint32		mui32FamilyAndStyle;
		uint16		mui16Face;
		uint8		mui8Spacing;
		uint8		mui8Encoding;
					FontData(	void);
					FontData(	const BFont * paramFont);
		virtual		~FontData();
		void		SetFontFromData(	BFont * paramFont);
	};
#endif