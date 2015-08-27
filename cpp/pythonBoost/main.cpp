
#include "boost/python.hpp"
#include <iostream>
#include <string>
using namespace boost::python;
int main(void)
{
	using namespace std;
	Py_InitializeEx(1);

	cout << Py_GetVersion() << endl;

	object i(10);

	i = i * 10;
	cout << extract<int>(i) << endl;

	object str("alqaz");
	string strx = extract<string>(str * 5);
	cout << strx << endl;

	list l;
	l.append("alqaz");
	l.append(12.3);
	l.append("alqaz");
	cout << len(l) << endl;
	cout << " alqaz count : " << l.count("alqaz") << endl;

	cout << "3**3=" <<  extract<int>(eval("3**3")) << endl;

	exec("print'hello, world'");

	object main_ns = import("__main__").attr("__dict__");

	string statement = "for i in range(1,5):\n"
		"\tprint i";
	try
	{
		exec(statement.c_str(), main_ns);
	}
	catch (error_already_set&)
	{
		PyErr_Print();
	}

	Py_Finalize();

	return 0;
}