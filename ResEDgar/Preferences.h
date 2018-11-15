/*	Preferences.h	*/
/*	$Id: Preferences.h,v 1.1 1997/11/07 07:33:54 hplus Exp hplus $	*/
/*	Simple C++ wrapper for the libprefs C-level API	*/
/*	This C++ header is not extensively tested.			*/
/*	Please verify that it works as you want it to.		*/

#if !defined(PREFERENCES_H)
#define PREFERENCES_H

//#pragma once

	#if BUILDING_LIB
		#define	UGLY_IMPEXP	__declspec(dllexport)
	#else
		#define	UGLY_IMPEXP	__declspec(dllimport)
	#endif
	
#if !defined(LIBPREFS_H)
#include "libprefs.h"
#endif


class UGLY_IMPEXP 
Preferences
{
	friend class PreferenceSet;
				/*	not implemented!	*/
								Preferences(
									const Preferences &		dummy);
		Preferences &			operator=(
									const Preferences &		dummy);
public:
								Preferences(
									const char *			application)
									{
										fHandle = NULL;
										fInit = PREFInit(application, &fHandle);
									}
								~Preferences()
									{
										if (fHandle != NULL)
											PREFShutdown(fHandle);
									}

		status_t				InitCheck()
									{
										return fInit;
									}

								operator PREFHandle()
									{
										return fHandle;
									}
protected:

		status_t				fInit;
		PREFHandle				fHandle;
};


class UGLY_IMPEXP 
PreferenceSet
{
					/*	not implemented on purpose!	*/
								PreferenceSet(
									const PreferenceSet &	dummy);
		PreferenceSet &			operator=(
									const PreferenceSet &	dummy);

public:
					/*	user-level means per-user settings	*/
								PreferenceSet(
									Preferences &			preferences,
									const char *			set_name,
									bool					user_level) :
									fPreferences(preferences)
									{
										fData = NULL;
										fInit = PREFLoadSet(preferences.fHandle, set_name, user_level, &fData);
									}
								~PreferenceSet()
									{
										if (fData != NULL)
											PREFDisposeSet(&fData);
									}

		status_t				InitCheck()
									{
										return fInit;
									}

					/*	save is NOT automatically done	*/
		status_t				Save()
									{
										return PREFSaveSet(fData);
									}
		status_t				Reload()
									{
										return PREFReloadSet(fData);
									}

		status_t				SetData(
									const char *			name,
									const void *			data,
									size_t					size,
									uint32					type = B_RAW_TYPE)
									{
										return PREFSetData(fData, name, data, size, type);
									}

		status_t				Delete(
									const char *			name)
									{
										return PREFDelete(fData, name);
									}

					/*	pointer is pointer to original	*/
		status_t				GetData(
									const char *			name,
									const void *&			out_data,
									ssize_t &				out_size,
									uint32 &				out_type)
									{
										return PREFGetData(fData, name, &out_data, &out_size, &out_type);
									}

								operator PREFData()
									{
										return fData;
									}

		BMessage &			GetMessage()
									{
										return *PREFGetMessage(fData);
									}
							operator BMessage * ()
									{
										return PREFGetMessage(fData);
									}
protected:

		Preferences &			fPreferences;
		status_t				fInit;
		PREFData				fData;
};


class UGLY_IMPEXP 
PrefTransaction
{
						/*	unimplemented on purpose!	*/
								PrefTransaction(
									const PrefTransaction &	trans);
		PrefTransaction &		operator=(
									const PrefTransaction &	trans);
public:

								PrefTransaction(
									PreferenceSet &			set)
									{
										fInit = PREFBeginTransaction(set, &fTransaction);
									}
								~PrefTransaction()
									{
										if (fInit >= B_OK)
											PREFEndTransaction(fTransaction);
									}

		status_t				InitCheck()
									{
										return fInit;
									}

protected:

		status_t				fInit;
		PREFTransaction			fTransaction;
};


#endif	/*	PREFERNECES_H		*/


