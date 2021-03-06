#include "demo.h"
#include "common.h"
#include "alqaz_lexical_cast.h"
#include "boost/lexical_cast.hpp"
#include "boost/format.hpp"
#include "boost/algorithm/string.hpp"
#include "boost/tokenizer.hpp"
#include "boost/xpressive/xpressive_dynamic.hpp"
#include "boost/assign.hpp"
#include "boost/bimap.hpp"
#include "boost/bimap/tags/tagged.hpp"
#include "boost/circular_buffer.hpp"
#include "boost/rational.hpp"
#include "boost/crc.hpp"
#include "boost/io/ios_state.hpp"
#include "boost/ref.hpp"
#include "boost/typeof/typeof.hpp"
#include "boost/assign.hpp"
#include "boost/is_placeholder.hpp"

#include <string>
#include <vector>
#include <regex>
#include <array>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <iostream>
#include <fstream>
#include <typeinfo>

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
	
void alqaz_test_array()
{
	std::array<int, 10> ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ar[0] = 1;
	ar.back() = 10;
	assert(ar[ar.size() - 1] == 10);

	//ar.assign(777);
	for (auto x = ar.begin(); x != ar.end(); ++x)
	{
		std::cout << *x << " ， ";
	}
	ar.at(3);
	cout << " 数组输出" << endl;
	//c++11中没有ar.c_array()把array转成c的指针 ar.at(xx)会进行边界检查，ar[xx]
}

void alqaz_test_bitset()
{
	std::bitset<5> v;  //其中每一个都是true/false值
	v[0] = true;  //
	v[2] = false;
	bool b_all_true = v.all();		//是否所有都为true
	bool b_any_true = v.any();
	cout << v.to_string() << endl; //输出00001,注意顺序
	cout << v.to_string('*'/*0用*号替代*/, 'X'/*1用X替代*/) << endl;
	cout << v.to_ullong() << endl;
	v.flip();	//反转 true->false, false->true
	cout << v.to_string('*', 'X') << endl;
	v.flip(4/*具体反转哪个位置的值*/);
	cout << v.to_string('*', 'X') << endl;
	int isize = v.size();
}

void alqaz_test_unordered()
{
	std::unordered_set<int> a = { 1, 2, 3, 4, 5, 6 };
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		cout << *i << " ";  //注意输出顺序，并非是1,2,3,4,,5,6
	}
	cout << endl;
	//cout << a.size() << endl;
	cout << a.bucket_count() << endl;
	cout << a.bucket_size(1) << endl;  //返回第n个桶中元素的个数

}

void alqaz_test_bimap()
{
	/************************************************************************/
	/* 这个在特定情况下很有用，以前在保存白板页索引到页id之间的映射用到了             */
	/************************************************************************/
	bimap<int, string> bm;	//双向Map
	bm.left.insert(make_pair(1, "111"));
	bm.right.insert(make_pair("222", 2));

	for (auto x = bm.left.begin(); x != bm.left.end(); ++x)
	{
		cout << "left [" << x->first << "]=" << x->second << endl;
	}

	bimap<bimaps::tagged<int, struct id>, bimaps::tagged<string, struct name>> bm2;
	bm2.by<id>().insert(make_pair(1, "111"));
	bm2.by<name>().insert(make_pair("222", 2));

	for (auto x = bm2.by<id>().begin(); x != bm2.by<id>().end(); ++x)
	{
		cout << "left [" << x->first << "]=" << x->second << endl;
	}

	auto pos = bm2.by<id>().find(1);
	bm2.by<id>().replace_key(pos, 11);
	bm2.by<id>().replace_data(pos, "alqaz");

	for (auto x = bm2.by<id>().begin(); x != bm2.by<id>().end(); ++x)
	{
		cout << "left [" << x->first << "]=" << x->second << endl;
	}

	auto left_pos = bm2.by<id>().find(11);  //project_right映射方便把指向Left的迭代器转换成指向Right的迭代器
	auto right_pos = bm2.project_right(left_pos);

	cout << "right [" << right_pos->first << "]" << right_pos->second << endl;

	//typedef bimap<set_of<bimaps::tagged<int, struct id>>, multi_set<bimaps::tagged<string, struct name>>> bm_t2; 注意bimap的两个模板参数类型
}

void alqaz_test_circular_buffer()
{
	//环形缓冲区（大小固定）,这个曾经用在白板的撤销重做实现里正好（因为支持的最大撤销重做的步数是固定的，所以使用环形缓冲正好)
	circular_buffer<int> v(3);

	for (int i = 1; i < 5; ++i)
	{
		v.push_back(i);
	}

	auto b_full = v.full();//判断是否已满
	auto arrayx = v.linearize(); //返回数组的头指针

	

	for (auto x = v.begin(); x != v.end(); ++x)
	{
		cout << *x << endl;
	}

	v.rotate(v.begin() + 1);//旋转
	for (auto x = v.begin(); x != v.end(); ++x)
	{
		cout << *x << endl;
	}

	circular_buffer_space_optimized<int> cb(10);		//除了内存大小分配时动态的，其他和circular_buffer基本相同
}

void alqaz_test_tuple()
{
	//c++11支持tuple
	using namespace std;

	auto x = std::make_tuple(1, "char", 100.0, "alqaz");
	auto y = std::make_tuple(1, "char", 100.0, "def");
	cout << std::get<1>(x) << endl;
	cout << (x < y) << endl;
	//cout << x << endl; c++11好像不支持tuple的流输出，对ostream没有重载<<运算符 而boost::tuple支持,boost::tuple还支持tie等其他函数，需要添加头文件///boost/tuple/tuple_io.hpp
	
}

void alqaz_test_rational()
{
	rational<int> a(3), b(65534), c(22, 7);
	
	

	b += a;
	c -= a;
	if (c >= 0)
	{
		c = c*b;
		++a;
	}

	int big_x = gcd(11, 22);  //最大公约数
	int samll_x = lcm(11, 22);	//最小公倍数

}

void alqaz_test_crc()
{
	//crc_option based on byte  ---fast
	//crc_baisc  base on bit ---slow
	crc_32_type crc32;
	cout << hex;
	cout << crc32.checksum() << endl;
	crc32.process_byte('a');
	cout << crc32.checksum() << endl;
	crc32.process_bytes("0123456789", 10);
	cout << crc32.checksum() << endl;
	cout << crc32() << endl;//直接返回计算值，和checksum()相同
	//crc32(param1);相当于调用 process_byte，即
}

void alqa_test_io_state()
{
	{
		io::ios_all_saver iis(cout);   //iis先保存了cout的所有 flag状态，在iis离开作用域时重置cout为iis,不知道为什么，在windows下会崩溃
		std::string pathx = "/opt/test.log";
		ofstream of(pathx.c_str());
		cout.rdbuf(of.rdbuf());
		cout << "log" << endl;
	}
	cout << "one " << endl;
	cout << "two" << endl;
}

void alqaz_test_reference_wrapper()
{
	int x = 10;
	auto rw =  std::ref(x);

	
	assert(x == rw);
	(int&)rw = 100;
	assert(x == 100);
	assert(std::_Is_reference_wrapper<BOOST_TYPEOF(rw)>::value);
	assert(!std::_Is_reference_wrapper<BOOST_TYPEOF(x)>::value);
}

void alqaz_test_bind()
{
	//c++11中有实现
}


void alqaz_test_bigendian()
{
	//c++11中有实现
}