#include "demo.h"
#include "common.h"
#include "alqaz_lexical_cast.h"
#include "boost/lexical_cast.hpp"
#include "boost/format.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/tokenizer.hpp"
#include "boost/xpressive/xpressive_dynamic.hpp"

#include <string>
#include <vector>
#include <regex>

using namespace boost;
using namespace boost::io;

const string const_str_num = "12345";
const string const_str_not_num = "alqaz.txt";
string _long_string_not_num = "Long long ago, there was a king";
const int	const_int_number = 11;

//boost/lexical_cast.hpp
void alqaz_test_lexical_cast()
{
	int iTemp = lexical_cast<int>(const_str_num);
	std::cout << "lexical_cast<int>(std::string),由: " << const_str_num << "(" << typeid(const_str_num).hash_code() //用hash_code()而不是name()是因为字符串的名字太长，显示效果差
		<< ")" << "转换结果为 :" << iTemp << "(" << typeid(iTemp).name() << ")" << std::endl;

	alqaz_lexical_cast f{ const_int_number };
	auto from_alqaz_lexical = lexical_cast<string>(f);
	cout << "lexical_cast<string>(alqaz_lexical_cast),由： " << typeid(alqaz_lexical_cast).hash_code() << " 到: " << from_alqaz_lexical << endl;


	alqaz_lexical_cast next = lexical_cast<alqaz_lexical_cast>(const_int_number);
	cout << "lexical_cast<alqaz_lexical_cast>(int),由： " << typeid(const_int_number).name() << " 到： " << typeid(next).name() << endl;
	try{
		auto wrong_cast = lexical_cast<int>(const_str_not_num);
	}
	catch (bad_lexical_cast& e)
	{
		cout << "在:" << __FILE__ << "(" << __LINE__ << ")行" << "转换异常捕获" << e.what() << endl;
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

void alqaz_test_string_algo()
{
	if (ends_with(const_str_not_num, "az"))
	{
		cout << to_upper_copy(const_str_not_num) + " UPPER" << endl;
	}

	string temp = const_str_not_num;
	replace_first(temp, "lq", "LQ");  //将temp中首个lq替换成LQ
	cout << temp << endl;

	vector<char> v(temp.begin(), temp.end());
	vector<char> v2 = to_upper_copy(erase_first_copy(v, "txt"));   //删除首个子串"txt"
	for (auto i : v2){
		cout << i << " ";
	}
	cout << endl;
	to_upper(v);	//v中所有字幕就地变大写
	for (auto i : v) cout << i << " ";
	cout << endl;

	cout << to_lower_copy(const_str_not_num) << endl;

	assert(istarts_with(const_str_not_num, "alq"));  //i打头的函数意思是忽略大小写，const_str_not_num是否以alq开头

	cout << lexicographical_compare(const_str_not_num, "alqa") << endl;;  //按字典顺序检查const_str_not_num和"alqa”的大小，两个字符串长度可以不相等 param1<param2 返回true
	string tempy = "alqaz";
	cout << all(tempy, is_lower()) << endl;;		//检查tempy所有字符是否都是小写,还有is_space, is_alnum, is_alpha， is_any_of, is_from_range等
	tempy = "alqaz.txt";
	cout << "比较两个字符串是否相等 " << is_equal()(const_str_not_num, tempy) << endl;  //比较字符串是否相等，还有 is_less, is_not_greater

	format fmt("|%s|. pos = %d\n");
	iterator_range<string::iterator> rge;

	rge = find_first(_long_string_not_num, "long");	//rge是一个迭代器范围类,类似于pair<it1,it2>但是rge本身指向查找的结果，即，如果找到rgx=long,否则='';其他类似函数还有i.. find_nth, find_head,rge还可以默认转为bool类型
	cout << fmt % rge % (rge.begin() - _long_string_not_num.begin());

	string strLast{ "yangxingping" };
	typedef find_iterator<string::iterator> string_find_iterator;
	string_find_iterator pos, end;
	for (pos = make_find_iterator(strLast, first_finder("ing", is_equal())); pos != end; ++pos)
	{
		cout << "[ " << *pos << " ] " << endl;
	}

	typedef split_iterator<std::string::iterator> string_split_iterator;
	string_split_iterator a, b;
	for (a = make_split_iterator(strLast, first_finder("ng", is_equal())); a != b; ++a){
		cout << "[" << *a << "]";
	}
	cout << endl;

}

void alqaz_test_tokenizer()
{
	string strFirst{ "yang xing ping, hello." };
	tokenizer<> tok(strFirst);
	for (auto item = tok.begin(); item != tok.end(); ++item)
	{
		cout << "[" << *item << "]";
	}
}

void alqaz_test_xpress()
{
	using namespace boost::xpressive;
	cregex cgx = cregex::compile("a.c");
	assert(regex_match("abc", cgx));

	string str{ "subject" };
	std::regex e("(sub)(.*)(t)$");

	std::smatch sm;
	std::regex_match(str, sm, e);
	cout << *(sm.begin()) << endl;
}
	
