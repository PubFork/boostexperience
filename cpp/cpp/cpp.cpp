#include <iostream>
//#include "boost/python.hpp"
//#include "boost/python/errors.hpp"
//#include "boost/python/object.hpp"
//#include "boost/python/handle.hpp"
//#include "Python.h"

#include <regex>
#include <mutex>
using namespace std;


int main(void)
{
	cout << lexical_cast<string>(Demx()) << endl;

	int xxx = 11;
	Demx dd = lexical_cast<Demx>(xxx);
	cout << dd.getX() << endl;

	return 1;
}