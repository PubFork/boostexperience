#ifdef	_WIN32
#ifndef ALQAZ_EXT
#define ALQAZ_EXT __declspec(dllexport)
#endif
#else
#define ALQAZ_EXT 
#endif
#include "../includes/commonLibraryDemo.h"

#include <cmath>

int ALQAZ_EXT  func1(int x)
{
	return x;
}

Demo::Demo()
{
	m_x = 1;
	m_y = 1;
}

int Demo::Add()
{
	return m_x + m_y;
}

float Demo::Sqrt()
{
	return sqrt(m_x + m_y);
}

