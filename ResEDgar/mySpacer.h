//mySpacer.h

#ifndef GUI_MYSPACER
#define GUI_MYSPACER
	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	class UGLY_IMPEXP LayoutMatrix;
	
	class UGLY_IMPEXP
	MySpacer
	{
	private:
					MySpacer(	const MySpacer& copy);//not implemented on purpose
		MySpacer&	operator = (	const MySpacer& assign);//not implemented on purpose
	public:
		float			mfPreferredWidth;
		float			mfPreferredHeight;
		bool			mbSAMEFromWidest;
						MySpacer(	float paramPreferredWidth,
									float paramPreferredHeight,
									LayoutMatrix * paramLayoutMatrix,
									bool paramSAMEFromWidest = false);
		virtual			~MySpacer();
		void			ResizeTo(	const float paramWidest,
									const float paramTallest);
		virtual void	MyGetPreferredSize(	float * paramWidth,
										float * paramHeight) const;
	};
#endif