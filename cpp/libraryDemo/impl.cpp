#ifdef _WIN32
#ifndef ALQAZ_EXT
#define ALQAZ_EXT __declspec(dllexport)
#endif
#else
#define ALQAZ_EXT 
#endif
#include "../includes/commonLibraryDemo.h"

int ALQAZ_EXT func1(int x)
{
	return x;
}