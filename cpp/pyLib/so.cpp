#include "boost/python.hpp"
#include "boost/python/def.hpp"
#include <string>

using namespace std;
using namespace boost::python;

string hello_func()
{
	return "hello,Python";
}

BOOST_PYTHON_MODULE(libalqaz)  //ע��libalqaz��������ú�Makefile�����ļ���������ͬ������ԭ�򻹲�֪��
{
	def("hello", hello_func, "just a demo");
}