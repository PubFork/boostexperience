#ifndef __COMMON_LIBRARY_H__
#define __COMMON_LIBRARY_H__ 

#ifndef ALQAZ_EXT
#ifdef _WIN32
#define ALQAZ_EXT __declspec(dllimport);
#else
#define ALQAZ_EXT
#endif // WIN32
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	ALQAZ_EXT int   func1(int x);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif