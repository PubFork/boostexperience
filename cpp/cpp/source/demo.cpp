#include "demo.h"
#include "common.h"
#include "alqaz_lexical_cast.h"
#include "boost/lexical_cast.hpp"
#include "boost/format.hpp"

#include <string>

using namespace boost;
using namespace boost::io;

const string const_str_num = "12345";
const string const_str_not_num = "alqaz";
const int	const_int_number = 11;

//boost/lexical_cast.hpp
void alqaz_test_lexical_cast()
{
	int iTemp = lexical_cast<int>(const_str_num);
	std::cout << "lexical_cast<int>(std::string),由: " << const_str_num <<"("<<typeid(const_str_num).hash_code() //用hash_code()而不是name()是因为字符串的名字太长，显示效果差
		<< ")" <<  "转换结果为 :"  << iTemp << "(" << typeid(iTemp).name() << ")" <<  std::endl;

	alqaz_lexical_cast f{ const_int_number };	
	auto from_alqaz_lexical = lexical_cast<string>(f);
	cout << "lexical_cast<string>(alqaz_lexical_cast),由： " << typeid(alqaz_lexical_cast).hash_code() << " 到: " << from_alqaz_lexical << endl;


	alqaz_lexical_cast next = lexical_cast<alqaz_lexical_cast>(const_int_number);
	cout << "lexical_cast<alqaz_lexical_cast>(int),由： " << typeid(const_int_number).name() << " 到： " << typeid(next).name() << endl;
	try{
		auto wrong_cast = lexical_cast<int>(const_str_not_num);
	}
	catch(bad_lexical_cast& e)
	{
		cout <<"在:"<< __FILE__ << "(" << __LINE__ << ")行" << "转换异常捕获" << e.what() << endl;
	}
}

//boost/format.hpp
//这个比较简单，需要用到的时候看一下即可。
void alqaz_test_format()
{
	cout << format("%s: %d + %d = %d") % "sum" % 1 % 2 % (1 + 2) << endl;  //这种形式和printf非常相像，这里同样可以加入格式控制符，例如 %05d
	format fmt("(%1% + %2%)* %2% = %3%\n");		//这种形式是 %n% 表示这里会被第n个参数的值替换。
	fmt % 2 % 5;
	fmt % ((2 + 5) * 5);
	cout << fmt.str();

	format f("%1% %2% %3% %2% %1% \n");
	f.bind_arg(2, 10); //绑定%2% 为10
	f % 100 % 90;
	auto out = f.str();  cout << out << endl;
	f.clear();  //绑定的 %2% 不会改变,还是10
	
	cout << f % group(showbase, oct, 111) % 333; // %1%改为输出格式为八进制

	f.clear_binds();
	f.modify_item(1, group(hex, right, showbase, setw(8), setfill('*')));
	cout << f % 49 % 20 % 100;

	int tempForDebug;
}