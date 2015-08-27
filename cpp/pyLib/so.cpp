#include "boost/python.hpp"
#include "boost/python/def.hpp"
#include <string>

using namespace std;
using namespace boost::python;

string hello_func()
{
	return "hello,Python";
}

BOOST_PYTHON_MODULE(libalqaz)  //注意libalqaz的名字最好和Makefile生成文件的名字相同，具体原因还不知道
{
	def("hello", hello_func, "just a demo");
}