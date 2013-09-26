#define BUILDING_LIB 1
#define PREF_SHARED_LIBRARY 1
/*	libprefs.cpp	*/
/*	$Id: libprefs.cpp,v 1.1 1997/11/07 07:33:55 hplus Exp hplus $	*/

/*	This file can build various versions of the preferences library, including	*/
/*	a shared library, a static library that requires a plug-in, and a static library	*/
/*	that uses a plug-in when found, but uses a default built-in mechanism if not	*/
/*	See below for various switches to control this behaviour				*/

/*	include necessary files	*/
#if !defined(LIBPREFS_H)
#include "libprefs.h"
#endif

#if !defined(_OS_H)
#include <OS.h>
#endif

#if !defined(_FIND_DIRECTORY_H)
#include <FindDirectory.h>
#endif

#if !defined(_MESSAGE_H)
#include <Message.h>	/*	requires C++	*/
#endif

#if !defined(_STRING_H)
#include <string.h>
#endif

#if !defined(_SYS_STAT_H)
#include <sys/stat.h>
#endif

#if !defined(_FCNTL_H)
#include <fcntl.h>
#endif

#if !defined(_UNISTD_H)
#include <unistd.h>
#endif

#if !defined(_DEBUG_H)
#include <Debug.h>
#endif

#if !defined(_STDLIB_H)
#include <stdlib.h>
#endif

#if !defined(_ERRNO_H)
#include <errno.h>
#endif

#if !defined(_PATH_H)
#include <Path.h>
#endif

#if !defined(_DIRECTORY_H)
#include <Directory.h>
#endif

#if !defined(_IMAGE_H)
#include <image.h>
#endif

#if !defined(_DIRENT_H)
#include <dirent.h>
#endif

#if !defined(_IMAGE_H)
#include <image.h>
#endif


/*	identifier for this implementation of the prefs library	*/
#define	PREF_VERSION_STRING		"simple libprefs.so version 1.2.4"
/*	this is the interval that pref files are polled at - can do with some =
tweaking	*/
/*	the environment variable POLL_INTERVAL will override this value	*/
long long	POLL_INTERVAL = 9000000;	/*	nine seconds	*/
/*	LP_MAGIC is prepended to the application name to separate from possibl=
e other settings	*/
#define LP_MAGIC	"_LP_"
/*	COMMON_DIRNAME is used to disambigue the case where user folder 
 common folder	*/
#define COMMON_DIRNAME	"(libprefs common)"

/*	some magic system calls	*/
extern "C" int _klock_node_(int fd);
extern "C" int _kunlock_node_(int fd);


/*	changes allowing hierarchical sets	*/
#define PRE_121 0

/*	support for building static linkage	*/
/*	set PREF_SHARED_LIBRARY to 1 when building the libprefs.so shared library	*/
/*	set PREF_STATIC_IMPLEMENTATION to 0 if you ONLY want to load add-ons	*/
/*	set it to 1 to get the default behaviour if there is no add-on	*/
//#if !defined(PREF_SHARED_LIBRARY)
//	#define PREF_SHARED_LIBRARY 0
//	#if !defined(PREF_STATIC_IMPLEMENTATION)
//		#define PREF_STATIC_IMPLEMENTATION 1
//	#endif
//#endif
/*	this is the name of the libprefs add-on	*/
#if !defined(LIBPREFS_NAME)
	#define LIBPREFS_NAME "libprefs.so"
#endif
/*	if we're building a shared lib, we HAVE to provide the implementation.	*/
#if PREF_SHARED_LIBRARY
	#if defined(PREF_STATIC_IMPLEMENTATION)
		#undef PREF_STATIC_IMPLEMENTATION
	#endif
	#define PREF_STATIC_IMPLEMENTATION 1
#endif


//#if DEBUG
//
///*	semaphore debugging code	*/
//static status_t my_acquire_sem(sem_id sem, const char * file, int line)
//{
//	printf("ACQUIRE sem: %u  file: %s  line: %d\n", sem, file, line);
//	return acquire_sem(sem);
//}
//
//static status_t my_release_sem(sem_id sem, const char * file, int line)
//{
//	printf("RELEASE sem: %u  file: %s  line: %d\n", sem, file, line);
//	return release_sem(sem);
//}
//
//#define acquire_sem(x) my_acquire_sem(x, __FILE__, __LINE__)
//#define release_sem(x) my_release_sem(x, __FILE__, __LINE__)
//
//#endif


#if PREF_STATIC_IMPLEMENTATION

/*	an active application	*/
struct _PREFHandle {
		PREFHandle			next;
		int					ref_count;
		char *				appname;
		PREFData			data_list;
};

/*	a currently open preferences set	*/
struct _PREFData {
		PREFData			next;
		int					ref_count;
		PREFHandle			handle;
		char *				prefs;
		BMessage *			data;
		PREFTransaction		transaction;
		void				(*listen_func)(PREFData, void *);
		void *				listen_cookie;
		thread_id			listen_thread;
		sem_id				listen_sem;
		int					listen_running;
};

struct _PREFTransaction {
		int					fd;
		int					ref_count;
		PREFData			data;
};

#endif /* PREF_STATIC_IMPLEMENTATION */

#if !PREF_SHARED_LIBRARY
struct _PREFCallbacks {
		image_id				image;

	const char * (*PREFVersion)(uint32 * out_version, uint32 * out_min_required);
	status_t (*PREFInit)(const char * application, PREFHandle * out_handle);
	status_t (*PREFShutdown)(PREFHandle handle);
	status_t (*PREFLoadSet)(PREFHandle handle, const char * set, bool user_level, PREFData * data);
	status_t (*PREFSaveSet)(PREFData data);
	status_t (*PREFReloadSet)(PREFData data);
	status_t (*PREFDisposeSet)(PREFData * data);
	status_t (*PREFSetData)(PREFData data, const char * setting, const void * buffer, size_t size, uint32 type);
	status_t (*PREFDelete)(PREFData data, const char * setting);
	status_t (*PREFGetData)(PREFData data, const char * setting, const void ** out_data, ssize_t * out_size, uint32 * out_type);
	BMessage * (*PREFGetMessage)(PREFData data);
	status_t (*PREFListApplications)(PREFHandle handle, bool user_level, uint32 * cookie, char * app_name, size_t size);
	status_t (*PREFDisposeApplicationCookie)(PREFHandle handle, uint32 cookie);
	status_t (*PREFListSets)(PREFHandle handle, bool user_level, uint32 * cookie, char * set_name, size_t size);
	status_t (*PREFDisposeSetCookie)(PREFHandle handle, uint32 cookie);
	status_t (*PREFBeginTransaction)(PREFData data, PREFTransaction * transaction);
	status_t (*PREFEndTransaction)(PREFTransaction transaction);
	status_t (*PREFListen)(PREFData data, void (*callback)(PREFData data, void * cookie), void * cookie);
	status_t (*PREFListData)(PREFData data, uint32 * cookie, char * name, size_t size, uint32 * type);
	status_t (*PREFDisposeDataCookie)(PREFData data, uint32 cookie);
	status_t (*PREFRemoveSet)(PREFData data);
	status_t (*PREFRemoveApp)(PREFHandle handle);
};
static	_PREFCallbacks	fCallbacks;
#endif /* !PREF_SHARED_LIBRARY */


#if PREF_STATIC_IMPLEMENTATION
/*	some necessary globals	*/
static	sem_id			fPrefSem = -1;	/*	guards the Handle and Data structures/lists	*/
static	PREFHandle		fPrefs = NULL;
static	sem_id			fTransSem = -1;	/*	never held across blocking system calls	*/
#endif


/*	in AA:PR, find_directory is in the headers, but not in the libraries..	*/
#if 0
status_t
find_directory(
	directory_which	which,
	char			*returned_path,
	int32			path_length)
{
	char * out = "/system/settings";	/*	we hard-code this folder	*/
	switch (which)
	{
	case B_USER_SETTINGS_DIRECTORY:
	case B_COMMON_SETTINGS_DIRECTORY:
		break;
	default:
		return B_ERROR;
	}
	if (strlen(out) > path_length-1)
		return B_ERROR;
	strcpy(returned_path, out);
	return B_OK;
}
#endif


#if !PREF_SHARED_LIBRARY

static int
getappdir(
	char * dir,
	size_t size)
{
	image_info info;
	thread_info tinfo;
	status_t err;
	if (size < 1)
		return B_BAD_VALUE;
	if ((err = get_thread_info(find_thread(NULL), &tinfo)) != B_OK)
		return err;
	for (int32 ix=0; !get_next_image_info(tinfo.team, &ix, &info); )
	{
		if (info.type == B_APP_IMAGE)
		{
			strncpy(dir, info.name, size);
			dir[size-1] = 0;
			char * ptr = strrchr(dir, '/');
			if (ptr) ptr[1] = 0;
			return B_OK;
		}
	}
	return B_ERROR;
}

static int
_PREFLoadCallbacks()
{
	/*	check for previous load	*/
	status_t err = B_OK;
	image_id the_image;
	if (fCallbacks.image < 0)
		return fCallbacks.image;
	if (fCallbacks.image > 0)
		return 0;
	/*	try to load		*/
	fCallbacks.image = load_add_on(LIBPREFS_NAME);
	if (fCallbacks.image < 0)
	{	/*	load through the shared lib path	*/
		char * env = getenv("LIBRARY_PATH");
		char * end, * temp, * str;
		if (!env)
			return fCallbacks.image;
		env = strdup(env);
		temp = env;
		while (1)
		{
			end = strchr(temp, ':');
			if (end)
				*end = 0;
			if (!strncmp(temp, "%A/", 3))
			{
				str = (char *)malloc(1024);
				if (!str)
				{
					free(env);
					return B_NO_MEMORY;
				}
				if ((errno = getappdir(str, 1023)) != B_OK)
				{
					free(env);
					free(str);
					return errno;
				}
				strcat(str, temp+2);	/*	include slash we know is there	*/
			}
			else
			{
				str = (char *)malloc(strlen(temp)+40);
				if (!str)
				{
					free(env);
					return B_NO_MEMORY;
				}
				strcpy(str, temp);
			}
			strcat(str, "/");
			strcat(str, LIBPREFS_NAME);
			fCallbacks.image = load_add_on(str);
			free(str);
			if (fCallbacks.image > 0)
				break;
			if (!end)
				break;
			temp = end+1;
		}
		free(env);
		if (fCallbacks.image < 0)
			return fCallbacks.image;
	}
	the_image = fCallbacks.image;
	fCallbacks.image = -1;
#define SYM(x) if (0 > (err = get_image_symbol(the_image, #x, \
	B_SYMBOL_TYPE_TEXT, (void **)&fCallbacks.x))) return puts(#x),err
	/*	load all the symbols required by a preferences library	*/
	SYM(PREFVersion);
	SYM(PREFInit);
	SYM(PREFShutdown);
	SYM(PREFLoadSet);
	SYM(PREFSaveSet);
	SYM(PREFReloadSet);
	SYM(PREFDisposeSet);
	SYM(PREFSetData);
	SYM(PREFDelete);
	SYM(PREFGetData);
	SYM(PREFGetMessage);
	SYM(PREFListApplications);
	SYM(PREFDisposeApplicationCookie);
	SYM(PREFListSets);
	SYM(PREFDisposeSetCookie);
	SYM(PREFBeginTransaction);
	SYM(PREFEndTransaction);
	SYM(PREFListen);
	SYM(PREFListData);
	SYM(PREFDisposeDataCookie);
	SYM(PREFRemoveApp);
	SYM(PREFRemoveSet);
	fCallbacks.image = the_image;
	return B_OK;
}

#endif


#if PREF_STATIC_IMPLEMENTATION

static status_t
_PREFRemoveDir(
	const char *		path)
{
	DIR * d;
	struct dirent * dent;
	char rpath[PATH_MAX];
	struct stat stbuf;
	status_t err = B_OK;
	status_t err2 = B_OK;

	d = opendir(path);
	if (!d) return errno;
	while ((dent = readdir(d)) != NULL)
	{
		if (!strcmp(dent->d_name, ".") || !strcmp(dent->d_name, ".."))
			continue;
		strcpy(rpath, path);
		strcat(rpath, "/");
		strcat(rpath, dent->d_name);
		if (stat(rpath, &stbuf))
			continue;
		if (S_ISDIR(stbuf.st_mode))
			err2 = _PREFRemoveDir(rpath);
		if (err2 && !err)
			err = err2;
		if (unlink(rpath) && !err)
			err = errno;
	}
	closedir(d);
	return err;
}

static status_t
_PREFEnsurePath(
	const char *		path)
{
	struct stat stbuf;
	char *str = strdup(path);
	char *end, *temp = str;
	if (!str)
		return stat(path, &stbuf);	/*	fallback at out of memory	*/
	if (*temp == '/')
		temp++;
	while (1)
	{
		end = strchr(temp, '/');
		if (end == NULL)
			break;
		*end = 0;
		if (stat(str, &stbuf))
		{
			mkdir(str, 0x1ff);
			if (stat(str, &stbuf))
				return B_ENTRY_NOT_FOUND;
		}
		if (!S_ISDIR(stbuf.st_mode))
			return B_NOT_A_DIRECTORY;
		*end = '/';
		temp = end+1;
	}
	return B_OK;
}


static status_t
_PREFMakePath(
	PREFHandle		handle,
	const char *		set,
	bool				user_level,
	char *			path,
	int				path_max)
{
	status_t err = B_OK;
	BPath bpath;
	err = find_directory(user_level ? B_USER_SETTINGS_DIRECTORY : B_COMMON_SETTINGS_DIRECTORY, &bpath, true, NULL);
	if (err < B_OK) return err;
	strncpy(path, bpath.Path(), path_max);
	path[path_max-1] = 0;
	/*	find the application folder in that folder	*/
	if (strlen(set)+strlen(handle->appname)+strlen(path)+6 > PATH_MAX)
		return PREF_TOO_LARGE;
	strcat(path, "/" LP_MAGIC);
	strcat(path, handle->appname);
	mkdir(path, 0x1ff);		/*	this mkdir is harmless	*/
	if (!user_level)
	{
		strcat(path, "/" COMMON_DIRNAME);
		mkdir(path, 0x1fff);	/*	this mkdir is harmless	*/
	}
	struct stat st;
	err = stat(path, &st);
	if (err < 0) return errno;
	strcat(path, "/");
	strcat(path, set);
	return _PREFEnsurePath(path);
}

#endif /* PREF_STATIC_IMPLEMENTATION */



const char *
PREFVersion(
	uint32 *			out_version,
	uint32 *			out_min)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFVersion(out_version, out_min);
#endif
#if PREF_STATIC_IMPLEMENTATION
	*out_version = PREF_CUR_VERSION;
	*out_min = PREF_MIN_VERSION;
	return PREF_VERSION_STRING;
#else
	return NULL;
#endif
}


status_t
PREFInit(const char * application, PREFHandle * out_handle)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFInit(application, out_handle);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	check for a user preference for polling time	*/
	const char * poll = getenv("POLL_INTERVAL");
	if (poll != NULL) {
		char * temp;
		uint32 pt = strtol(poll, &temp, 10);
		if (pt != 0)
			if (pt < 500000)
				if (pt < 4000)
					POLL_INTERVAL = pt * 1000000;
				else
					POLL_INTERVAL = pt * 1000;
			else
				POLL_INTERVAL = pt;
	}

	status_t err = B_OK;
	*out_handle = NULL;
	/*	slashes not allowed in application name	*/
	if (NULL != strchr(application, '/')) return B_BAD_VALUE;

	/*	initialize library if necessary	*/
	if (fPrefSem == -1)
	{
		fPrefSem = create_sem(0, "prefs sem");
		if (fPrefSem < 0) return fPrefSem;
		fTransSem = create_sem(1, "prefs trans sem");
		if (fTransSem < 0) { delete_sem(fPrefSem); fPrefSem = -1; return fTransSem; }
	}
	else
	/*	get semaphore	*/
		err = acquire_sem(fPrefSem);
	if (err < 0) return err;

	/*	find previous instance	*/
	PREFHandle data = fPrefs;
	while (data != NULL)
	{
		if (!strcmp(data->appname, application))
		{
			data->ref_count++;
			*out_handle = data;
			break;
		}
		data = data->next;
	}

	/*	create new if not found	*/
	if (data == NULL)
	{
		data = new _PREFHandle;
		data->next = fPrefs;
		data->ref_count = 1;
		data->appname = strdup(application);
		data->data_list = NULL;
		if (!data->appname)
		{
			err = B_NO_MEMORY;
			delete data;
		}
		else
		{
			fPrefs = data;
			*out_handle = data;
		}
	}

	/*	release semaphore and go home	*/
	release_sem(fPrefSem);

	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


#if PREF_STATIC_IMPLEMENTATION

static void
_PREFCloseListen(
	PREFData		data)
{
	if (data->listen_running)
	{
		data->listen_running = 0;
		release_sem(data->listen_sem);
		int32 status = 0;
		wait_for_thread(data->listen_thread, &status);
		delete_sem(data->listen_sem);
	}
}


static void
_PREFDoDisposeSet(
	PREFData *		data)
{

	/*	iterate over handle's item to find self	*/
	for (PREFData * ptr = &((*data)->handle->data_list); *ptr != NULL; ptr = &((*ptr)->next))
	{
		if (*ptr == *data)
		{
			/*	unlink item	*/
			*ptr = (*data)->next;
			break;
		}
	}
	/*	dispose all allocated memory	*/
	free((*data)->prefs);
	delete (*data)->data;
	if ((*data)->transaction)
	{
		close((*data)->transaction->fd);
		delete (*data)->transaction;
	}
	/*	dispose item	*/
	delete *data;
	*data = NULL;
}

#endif /* PREF_STATIC_IMPLEMENTATION */


status_t
PREFShutdown(PREFHandle handle)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFShutdown(handle);
#endif
#if PREF_STATIC_IMPLEMENTATION
	status_t err = PREF_NOT_FOUND;
	PREFHandle *data = &fPrefs;
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	iterate over all active handles to find ourselves	*/
	while (*data != NULL)
	{
		if (*data == handle)
		{
			/*	decrease refcount	*/
			(*data)->ref_count--;
			/*	delete and unlink if we're gone	*/
			if ((*data)->ref_count < 1)
			{
				PREFHandle next = (*data)->next;
				/*	here, we should assert that all loaded items are disposed	*/
				/*	and dispose them if not										*/
				for (PREFData *nxptr = NULL, *ptr = &(*data)->data_list; *ptr != NULL; ptr = nxptr)
				{
					nxptr = &(*ptr)->next;
					_PREFDoDisposeSet(ptr);
				}
				delete *data;
				*data = next;
				err = B_OK;
				break;
			}
		}
		data = &(*data)->next;
	}
	/*	release semaphore and go home	*/
	if (fPrefs == NULL)
	{	/*	delete if there's nothing left	*/
		delete_sem(fTransSem);
		fTransSem = -1;
		sem_id del = fPrefSem;
		fPrefSem = -1;
		delete_sem(del);
	}
	else
		release_sem(fPrefSem);

	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFRemoveApp(PREFHandle handle)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFRemoveApp(handle);
#endif
#if PREF_STATIC_IMPLEMENTATION
	status_t err = PREF_NOT_FOUND;
	PREFHandle *data = &fPrefs;
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	iterate over all active handles to find ourselves	*/
	while (*data != NULL)
	{
		if (*data == handle)
		{
			err = PREF_REMOVE_FAILED;
			if ((*data)->ref_count > 1)
				break;
			/*	delete and unlink	*/
			PREFHandle next = (*data)->next;
			/*	here, we should assert that all loaded items are disposed	*/
			/*	and dispose them if not										*/
			for (PREFData *nxptr = NULL, *ptr = &(*data)->data_list; *ptr != NULL; ptr = nxptr)
			{
				nxptr = &(*ptr)->next;
				_PREFDoDisposeSet(ptr);
			}
			/*	delete from disk	*/
			char path[PATH_MAX];
			if (!_PREFMakePath(*data, ".", true, path, PATH_MAX))
			{
				err = _PREFRemoveDir(path);
			}
			if (!err && !_PREFMakePath(*data, ".", false, path, PATH_MAX))
			{
				err = _PREFRemoveDir(path);
			}
			delete *data;
			*data = next;
			err = B_OK;
			break;
		}
		data = &(*data)->next;
	}
	/*	release semaphore and go home	*/
	if (fPrefs == NULL)
	{	/*	delete if there's nothing left	*/
		delete_sem(fTransSem);
		fTransSem = -1;
		sem_id del = fPrefSem;
		fPrefSem = -1;
		delete_sem(del);
	}
	else
		release_sem(fPrefSem);

	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFLoadSet(PREFHandle handle, const char * set, bool user_level, PREFData * data)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFLoadSet(handle, set, user_level, data);
#endif
#if PREF_STATIC_IMPLEMENTATION
	status_t err = B_OK;
	*data = NULL;
	/*	check for bad data	*/
#if PRE_121
	if (NULL != strchr(set, '/')) return B_BAD_VALUE;
#endif
	/*	find the folder in question	*/
	char path[PATH_MAX];
	err = _PREFMakePath(handle, set, user_level, path, PATH_MAX);
	if (err < B_OK) return err;
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	find already loaded item	*/
	for (PREFData ptr = handle->data_list; ptr != NULL; ptr = ptr->next)
	{
		if (!strcmp(path, ptr->prefs))
		{
			*data = ptr;
			ptr->ref_count++;
			release_sem(fPrefSem);
			return B_OK;
		}
	}
	/*	create the settings item	*/
	*data = new _PREFData;
	if (!*data)
	{
		release_sem(fPrefSem);
		return B_NO_MEMORY;
	}
	(*data)->next = handle->data_list;
	(*data)->ref_count = 1;
	(*data)->handle = handle;
	(*data)->prefs = strdup(path);
	(*data)->transaction = NULL;
	(*data)->listen_func = NULL;
	(*data)->listen_cookie = NULL;
	(*data)->listen_thread = 0;
	(*data)->listen_sem = 0;
	(*data)->listen_running = 0;
	if (!(*data)->prefs)
	{	/*	yukky error handling code	*/
		delete *data;
		*data = NULL;
		release_sem(fPrefSem);
		return B_NO_MEMORY;
	}
	(*data)->data = NULL;
	err = PREFBeginTransaction(*data, &(*data)->transaction);
	if (err < B_OK)
	{	/*	yukky error handling code	*/
		free((*data)->prefs);
		delete *data;
		*data = NULL;
		release_sem(fPrefSem);
		return err;
	}

	/*	read message and close, if success	*/
	//uint32 size = 0;
	int size = 0;
	lseek((*data)->transaction->fd, 0, SEEK_SET);
//#if DEBUG
//	printf("fd %d  ptr %08x  size %d\n", (*data)->transaction->fd, &size, sizeof(size));
//#endif
	int rd = read((*data)->transaction->fd, &size, sizeof(size));
	if (rd < 0)
	{
		release_sem(fPrefSem);
		return rd;
	}
	(*data)->data = new BMessage;
	if (!(*data)->data)
	{	/*	yukky error handling code	*/
		PREFEndTransaction((*data)->transaction);
		free((*data)->prefs);
		delete *data;
		*data = NULL;
		release_sem(fPrefSem);
		return B_NO_MEMORY;
	}
	if (rd == sizeof(size))
	{
		char * buffer = (char *)malloc(size);
		if (!buffer)
		{
			err = B_NO_MEMORY;
			goto err_exit;
		}
		rd = read((*data)->transaction->fd, buffer, size);
		if (rd != size)
		{
			if (rd < 0)
			{
				err = rd;
				goto err_exit;
			}
			/*	if truncated, we create a clear record with no settings in it	*/
			free(buffer);
			goto no_pref;
		}
		err = (*data)->data->Unflatten(buffer);
		free(buffer);
		if (err < 0) goto err_exit;

		ASSERT(err >= 0);
		/*	deal with various errors in initializing the data	*/
err_exit:
		if (err < 0)
		{	/*	yukky error handling code	*/
			PREFEndTransaction((*data)->transaction);
			free((*data)->prefs);
			delete (*data)->data;
			delete *data;
			*data = NULL;
			release_sem(fPrefSem);
			return B_NO_MEMORY;
		}
	}
no_pref:
	/*	link it in	*/
	handle->data_list = *data;
	PREFEndTransaction((*data)->transaction);
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFReloadSet(PREFData data)
{
	char * buffer = NULL;
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFReloadSet(data);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	enter (nest) transaction	*/
	status_t err = PREFBeginTransaction(data, &data->transaction);
	if (err < B_OK) { return err; }
	int32 size = 0;
	/*	read in preferences data	*/
	lseek(data->transaction->fd, 0, 0);
	int rd = read(data->transaction->fd, &size, sizeof(size));
//#if DEBUG
//	printf("reload read %d\n", rd);
//#endif
	if (rd < 0) 
	{
		err = rd; 
		//goto cleanup; 
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return err;
	}
	if (rd != sizeof(size)) 
	{
		err = B_ERROR; 
		//goto cleanup; 
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return err;
	}
	buffer = (char *)malloc(size);
	if (buffer == NULL) 
	{ 
		err = B_NO_MEMORY; 
		//goto cleanup; 
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return err;
	}
	rd = read(data->transaction->fd, buffer, size);
//#if DEBUG
//	printf("reload read %d\n", rd);
//#endif
	if (rd < 0) 
	{
		err = rd;
		//goto cleanup_buf;
		free(buffer);
		if (err > 0) err = 0;
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return err;
	}
	if (rd != size) 
	{
		err = B_IO_ERROR;
		//goto cleanup_buf;
		free(buffer);
		if (err > 0) err = 0;
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return err;
	}
	/*	unflatten into current preferences message	*/
	err = data->data->Unflatten(buffer);
//#if DEBUG
//	printf("reload unflatten %d\n", err);
//#endif
//cleanup_buf:
	free(buffer);
	if (err > 0) err = 0;
//cleanup:
	PREFEndTransaction(data->transaction);
	release_sem(fPrefSem);
	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFSaveSet(PREFData data)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFSaveSet(data);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	enter transaction	*/
	status_t err = PREFBeginTransaction(data, &data->transaction);
//#if DEBUG
//	printf("saveset transaction %d\n", err);
//#endif
	if (err < B_OK) { release_sem(fPrefSem); return err; }
	/*	write message and end transaction	*/
	//uint32 size = data->data->FlattenedSize();
	int size = data->data->FlattenedSize();
	lseek(data->transaction->fd, 0, 0);
	int wr = write(data->transaction->fd, &size, sizeof(size));
	if (wr != sizeof(size))
	{
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return (wr < 0) ? wr : B_IO_ERROR;
	}
	char * buffer = (char *)malloc(size);
	if (!buffer)
	{
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return B_NO_MEMORY;
	}
	wr = data->data->Flatten(buffer, size);
	if (wr < B_OK)
	{
		PREFEndTransaction(data->transaction);
		free(buffer);
		release_sem(fPrefSem);
		return B_NO_MEMORY;
	}
	wr = write(data->transaction->fd, buffer, size);
	free(buffer);
	if (wr != size)
	{
		PREFEndTransaction(data->transaction);
		release_sem(fPrefSem);
		return (wr < 0) ? wr : B_IO_ERROR;
	}
	/*	end transaction	*/
//#if DEBUG
//	printf("saveset done\n", err);
//#endif
	PREFEndTransaction(data->transaction);
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFDisposeSet(PREFData * data)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFDisposeSet(data);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	start a transaction on the preference to make sure no-one else is using it	*/
	PREFTransaction trans = NULL;
	/*	do not use data->transaction, becuase that will always immediately return (we want exclusive)	*/
	status_t err = PREFBeginTransaction(*data, &trans);
	if (err < 0) return err;

	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	decrease refcount	*/
	if ((*data)->ref_count-- > 1)
	{
		/*	return if not gone	*/
		PREFEndTransaction(trans);
		release_sem(fPrefSem);
		return B_OK;
	}
	_PREFDoDisposeSet(data);
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFRemoveSet(PREFData data)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFRemoveSet(data);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	start a transaction on the preference to make sure no-one else is using it	*/
	PREFTransaction trans = NULL;
	/*	do not use data->transaction, becuase that will always immediately return (we want exclusive)	*/
	status_t err = PREFBeginTransaction(data, &trans);
	if (err < 0) return err;

	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	decrease refcount	*/
	if (data->ref_count > 1)
	{
		/*	return if not gone	*/
		release_sem(fPrefSem);
		PREFEndTransaction(trans);
		return PREF_REMOVE_FAILED;
	}
	char * path = strdup(data->prefs);
	_PREFDoDisposeSet(&data);
	if (!path)
		err = B_NO_MEMORY;
	else
		err = _PREFRemoveDir(path);
	free(path);
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFSetData(PREFData data, const char * setting, const void * buffer, size_t size, uint32 type)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFSetData(data, setting, buffer, size, type);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	call upon message to set data	*/
	data->data->RemoveName(setting);
	status_t err = data->data->AddData(setting, type, buffer, size);
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFDelete(PREFData data, const char * setting)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFDelete(data, setting);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	call upon message to delete data	*/
	status_t err = data->data->RemoveName(setting);
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFGetData(PREFData data, const char * setting, const void ** out_data, ssize_t * out_size, uint32 * out_type)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFGetData(data, setting, out_data, out_size, out_type);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	call upon message to get data	*/
	status_t err = data->data->GetInfo(setting, out_type);
	if (err >= B_OK) err = data->data->FindData(setting, *out_type, out_data, out_size);
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return (err >= 0) ? B_OK : PREF_NOT_FOUND;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


BMessage *
PREFGetMessage(PREFData data)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFGetMessage(data);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return NULL;
	/*	call upon message to get data	*/
	BMessage * ret = data->data;
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return ret;
#else
	return NULL;
#endif
}


#if PREF_STATIC_IMPLEMENTATION

typedef struct _PREFAppIterator {
	_PREFAppIterator(
		bool				user_level)
		{
			int block = 16;
			numItems = 0;
			curItem = 0;
			item = new char*[block];
			BPath bpath;
			if (!find_directory(user_level ? B_USER_SETTINGS_DIRECTORY : B_COMMON_SETTINGS_DIRECTORY, &bpath, true, NULL))
			{
				BDirectory dir(bpath.Path());
				BEntry entry;
				status_t err;
//				if (B_OK == (err = dir.Lock()))
					 while ((err = dir.GetNextEntry(&entry)) >= B_OK)
				{
					char name[B_FILE_NAME_LENGTH];
					if (entry.IsDirectory() && (entry.GetName(name) >= B_OK) && !strncmp(name, LP_MAGIC, strlen(LP_MAGIC)))
					{
						/*	Failure here is less well reported than it could be.	*/
						/*	When we run out of memory, we just keep what's there and don't tell the user there might have been more	*/
						if (numItems >= block)
						{
							int nblock = numItems+16;
							char ** newitems = new char*[nblock];
							memcpy(newitems, item, numItems*sizeof(char *));
							delete[] item;
							item = newitems;
							block = nblock;
						}
						item[numItems] = strdup(&name[strlen(LP_MAGIC)]);
						if (item[numItems] != NULL) numItems++;
					}
//					dir.Unlock();
				}
			}
		}
	~_PREFAppIterator()
		{
			for (int ix=0; ix<numItems; ix++)
			{
				if (item[ix])
					free(item[ix]);
			}
			delete[] item;
		}
	int			curItem;
	int			numItems;
	char **		item;
} * PREFAppIterator;

#endif /* PREF_STATIC_IMPLEMENTATION */


status_t
PREFListApplications(PREFHandle handle, bool user_level, uint32 * cookie, char * app_name, size_t size)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFListApplications(handle, user_level, cookie, app_name, size);
#endif
#if PREF_STATIC_IMPLEMENTATION
	handle = handle;
	/*	acquire semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	validate parameters	*/
	if (!handle || !cookie || !app_name || size < 1) { release_sem(fPrefSem); return B_BAD_VALUE; }
	/*	if this is the first call, allocate the data structures	*/
	_PREFAppIterator * ptr = (_PREFAppIterator *)*cookie;
	if (!ptr)
	{
		ptr = new _PREFAppIterator(user_level);
		*cookie = (uint32)ptr;
	}
	/*	get the Nth item out of the struct	*/
	status_t ret = B_OK;
	if (ptr->curItem >= ptr->numItems)
	{
		ret = PREF_NOT_FOUND;
	}
	else
	{
		strncpy(app_name, ptr->item[ptr->curItem], size);
		app_name[size-1] = 0;
		ptr->curItem++;
	}
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return ret;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFDisposeApplicationCookie(PREFHandle handle, uint32 cookie)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFDisposeApplicationCookie(handle, cookie);
#endif
#if PREF_STATIC_IMPLEMENTATION
	handle = handle;
	/*	test arguments	*/
	if (cookie == 0)
		return B_ERROR;
	/*	delete item	*/
	delete (_PREFAppIterator *)cookie;
	/*	declare success	*/
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


#if PREF_STATIC_IMPLEMENTATION

typedef struct _PREFSetIterator
{
	_PREFSetIterator(
		PREFHandle		handle,
		bool				user_level)
		{
			int block = 16;
			numItems = 0;
			curItem = 0;
			item = new char*[block];
			BPath bpath;
			if (!find_directory(user_level ? B_USER_SETTINGS_DIRECTORY : B_COMMON_SETTINGS_DIRECTORY, &bpath, true, NULL))
			{
				char str[B_FILE_NAME_LENGTH+20];
				strcpy(str, LP_MAGIC);
				strcat(str, handle->appname);
				bpath.Append(str);
				if (!user_level)
					bpath.Append(COMMON_DIRNAME);
				BDirectory dir(bpath.Path());
				if (!dir.InitCheck())
					AddItems(dir, bpath.Path(), block);
			}
		}
	~_PREFSetIterator()
		{
			for (int ix=0; ix<numItems; ix++)
			{
				if (item[ix])
					free(item[ix]);
			}
			delete[] item;
		}
	void AddItems(
		BDirectory & dir,
		const char * prepath,
		int & block)
	{
		status_t err = 0;
		BEntry entry;
//				if (B_OK == (err = dir.Lock()))
		while ((err = dir.GetNextEntry(&entry)) >= B_OK)
		{
			BPath path;
			if (entry.IsFile() && (entry.GetPath(&path) >= B_OK))
			{
				/*	Failure here is less well reported than it could be.	*/
				/*	When we run out of memory, we just keep what's there and don't tell the user there might have been more	*/
				if (numItems >= block)
				{
					int nblock = numItems+16;
					char ** newitems = new char*[nblock];
					memcpy(newitems, item, numItems*sizeof(char *));
					delete[] item;
					item = newitems;
					block = nblock;
				}
				/*	If there's a link somewhere else, deal with it gracefully	*/
				int prefix = strlen(prepath)+1;
				if (strncmp(prepath, path.Path(), prefix-1))
					prefix = 0;
				item[numItems] = strdup(path.Path()+prefix);
				if (item[numItems] != NULL)
					numItems++;
			}
			else if (entry.IsDirectory())
			{
				BDirectory newDir(&entry);
				if (!newDir.InitCheck())
					AddItems(newDir, prepath, block);
			}
//					dir.Unlock();
		}
	}
	int		curItem;
	int		numItems;
	char **	item;
} * PREFSetIterator;

#endif /* PREF_STATIC_IMPLEMENTATION */


status_t
PREFListSets(PREFHandle handle, bool user_level, uint32 * cookie, char * set_name, size_t size)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFListSets(handle, user_level, cookie, set_name, size);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	test parameters	*/
	if (!handle || !cookie || !set_name || (size < 1))
		return B_BAD_VALUE;
	/*	acquire the semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	create the item if not available	*/
	_PREFSetIterator * ptr = (_PREFSetIterator *)*cookie;
	if (!ptr)
	{
		ptr = new _PREFSetIterator(handle, user_level);
		*cookie = (uint32)ptr;
	}
	/*	get the Nth item out of the struct	*/
	status_t ret = B_OK;
	if (ptr->curItem >= ptr->numItems)
	{
		ret = PREF_NOT_FOUND;
	}
	else
	{
		strncpy(set_name, ptr->item[ptr->curItem], size);
		set_name[size-1] = 0;
		ptr->curItem++;
	}
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return ret;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFDisposeSetCookie(PREFHandle handle, uint32 cookie)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFDisposeSetCookie(handle, cookie);
#endif
#if PREF_STATIC_IMPLEMENTATION
	handle = handle;
	if (cookie == 0)
		return B_ERROR;
	delete (_PREFSetIterator *)cookie;
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


#if PREF_STATIC_IMPLEMENTATION

typedef struct _PREFIterator
{
	_PREFIterator(
		PREFData			data)
		{
			m_message = data->data;
			m_pos = 0;
		}
	~_PREFIterator()
		{
		}

	BMessage * m_message;
	int m_pos;

} * PREFIterator;

#endif /* PREF_STATIC_IMPLEMENTATION */


status_t
PREFListData(PREFData data, uint32 * cookie, char * set_name, size_t size, uint32 * type)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFListData(data, cookie, set_name, size, type);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	test parameters	*/
	if (!data || !cookie || !set_name || (size < 1) || !type)
		return B_BAD_VALUE;
	/*	acquire the semaphore	*/
	if (acquire_sem(fPrefSem) < B_OK) return PREF_NOT_INITED;
	/*	create the item if not available	*/
	_PREFIterator * ptr = (_PREFIterator *)*cookie;
	if (!ptr)
	{
		ptr = new _PREFIterator(data);
		*cookie = (uint32)ptr;
	}
	/*	get the Nth item out of the struct	*/
	status_t ret = ptr->m_message ? B_OK : PREF_NOT_FOUND;
	if (ret == B_OK)
	{
		char * name = NULL;
		int32 count = 0;
		ret = ptr->m_message->GetInfo(B_ANY_TYPE, ptr->m_pos++, &name, type, &count);
		if (ret == B_OK)
		{
			strncpy(set_name, name, size);
			set_name[size-1] = 0;
		}
	}
	/*	release semaphore and go home	*/
	release_sem(fPrefSem);
	return ret;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFDisposeDataCookie(PREFData data, uint32 cookie)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFDisposeDataCookie(data, cookie);
#endif
#if PREF_STATIC_IMPLEMENTATION
	data = data;
	if (cookie == 0)
		return B_ERROR;
	delete (_PREFIterator *)cookie;
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFBeginTransaction(
	PREFData			data,
	PREFTransaction *	transaction)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFBeginTransaction(data, transaction);
#endif
#if PREF_STATIC_IMPLEMENTATION
	ASSERT(transaction != NULL);
	if (transaction == NULL) return B_BAD_VALUE;
	*transaction = NULL;
	/*	acquire transaction semaphore	*/
	if (acquire_sem(fTransSem) < B_OK) return PREF_NOT_INITED;
//#if DEBUG
//	printf("BeginTransaction <%d>\n", find_thread(NULL));
//#endif
	/*	test for nesting	*/
	if (data->transaction && (data->transaction == *transaction))
	{
//#if DEBUG
//		printf("nest transaction level %d\n", data->transaction->ref_count);
//#endif
		data->transaction->ref_count++;
		release_sem(fTransSem);
		return B_OK;
	}
	/*	release semaphore while we block for file access	*/
	release_sem(fTransSem);
	/*	open and lock file	*/
open_again:
	int fd = open(data->prefs, O_RDWR | O_CREAT, 0666);
//#if DEBUG
//	printf("open %s returns %d\n", data->prefs, fd);
//#endif
	if ((fd < 0) && (errno == EINTR)) goto open_again;
//#if DEBUG
//	if (fd < 0) printf("errno = %08x\n", errno);
//#endif
	if ((fd < 0) && (errno != EBUSY)) return fd;
	if ((fd < 0) || (_klock_node_(fd) < B_OK))
	{	/*	it is unfortunate that there is no atomic/blocking way to wait	*/
		/*	for exclusive access to a file - now we are forces to busy-wait	*/
		if (fd >= 0) close(fd);
//#if DEBUG
//		printf("can't lock - snoozing\n", fd);
//#endif
		snooze((rand()&0x7fff)+(find_thread(NULL)&0x7fff)+10000);	//	random snooze time to break ties
		goto open_again;
	}
	/*	acquire transaction semaphore - this will always work,							*/
	/*	because the transaction semaphore is never held across blocking system calls	*/
	acquire_sem(fTransSem);
	/*	create transaction object	*/
	*transaction = new _PREFTransaction;
	(*transaction)->ref_count = 1;
	(*transaction)->data = data;
	(*transaction)->fd = fd;
	data->transaction = *transaction;
	/*	release semaphore and go home	*/
	release_sem(fTransSem);
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


status_t
PREFEndTransaction(
	PREFTransaction		transaction)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFEndTransaction(transaction);
#endif
#if PREF_STATIC_IMPLEMENTATION
	ASSERT(transaction != NULL);
	if (transaction == NULL) return B_BAD_VALUE;
	ASSERT(transaction->data->transaction == transaction);
	if (acquire_sem(fTransSem) < 0) return PREF_NOT_INITED;
//#if DEBUG
//	printf("EndTransaction <%d>\n", find_thread(NULL));
//#endif
	transaction->ref_count--;
	if (transaction->ref_count == 0)
	{
//#if DEBUG
//		printf("closing fd %d (%s)\n", transaction->fd, transaction->data->prefs);
//#endif
		close(transaction->fd);
		transaction->data->transaction = NULL;
		delete transaction;
	}
	release_sem(fTransSem);
	return B_OK;
#else
	return PREF_NOT_AVAILABLE;
#endif
}


#if PREF_STATIC_IMPLEMENTATION

static status_t
_PREFListenFunc(
	void *				param)
{
	/*	this thread function polls the specified settings item for change in its mod date		*/
	PREFData data = (PREFData)param;
	if (!data->listen_func)
	{
//#if DEBUG
//		printf("no listen_func???\n");
//#endif
		return -1;
	}
	struct stat old_stat, new_stat;
	int err = stat(data->prefs, &old_stat);
	if (err < 0) return err;
	while ((acquire_sem_etc(data->listen_sem, 1, B_TIMEOUT, POLL_INTERVAL) == B_TIMED_OUT) &&
		data->listen_running)
	{
		err = stat(data->prefs, &new_stat);
		if (err) return err;
		/*	if mod date differs from what we saw before, we notify the client	*/
		if (new_stat.st_mtime != old_stat.st_mtime)
		{
			(*data->listen_func)(data, data->listen_cookie);
			stat(data->prefs, &old_stat);	/*	update the date stamp (we may have changed it ourselves)	*/
		}
	}
	return B_OK;
}

#endif /* PREF_STATIC_IMPLEMENTATION */


status_t
PREFListen(
	PREFData			data,
	void				(*listen_func)(
							PREFData			data,
							void *				cookie),
	void *				cookie)
{
#if !PREF_SHARED_LIBRARY
	if (!_PREFLoadCallbacks())
		return fCallbacks.PREFListen(data, listen_func, cookie);
#endif
#if PREF_STATIC_IMPLEMENTATION
	/*	a client wants to be informed when we detect changes in these preferences in "permanent storage"	*/
	if ((data == NULL) || (listen_func == NULL)) return B_BAD_VALUE;
	if (acquire_sem(fPrefSem)) { return PREF_NOT_INITED; }
	/*	if a poller is already currently running, we tell it to die and wait for it	*/
	_PREFCloseListen(data);

	/*	make sure we're in a transaction on the PREFData in question	*/
	PREFTransaction transaction = NULL;
	status_t err = PREFBeginTransaction(data, &transaction);
//#if DEBUG
//	printf("listen trans = %08x\n", err);
//#endif
	if (err < 0) { release_sem(fPrefSem); return err; }
	err = B_OK;

	data->listen_cookie = cookie;
	if (listen_func == NULL)
	{
		/*	setting the listen_func to NULL means we don't want any more notifications	*/
		data->listen_sem = 0;
		data->listen_func = NULL;
		data->listen_thread = 0;
	}
	else
	{
		/*	start up the polling apparatus	*/
		data->listen_sem = create_sem(0, "prefs listen sem");
		if (data->listen_sem < 0) return data->listen_sem;
		data->listen_thread = spawn_thread(_PREFListenFunc, "pref listen func", B_LOW_PRIORITY, data);
		if (data->listen_thread < 0) { delete_sem(data->listen_sem); return data->listen_thread; }
		data->listen_func = listen_func;
		data->listen_running = 1;
	}
//#if DEBUG
//	printf("listen end trans\n", err);
//#endif
	PREFEndTransaction(transaction);
	if (data->listen_thread > 0) err = resume_thread(data->listen_thread);
	release_sem(fPrefSem);
	return err;
#else
	return PREF_NOT_AVAILABLE;
#endif
}



