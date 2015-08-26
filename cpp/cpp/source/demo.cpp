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


#include <string>
#include <vector>
#include <regex>
#include <array>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

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
	std::cout << "lexical_cast<int>(std::string),��: " << const_str_num << "(" << typeid(const_str_num).hash_code() //��hash_code()������name()����Ϊ�ַ���������̫������ʾЧ����
		<< ")" << "ת�����Ϊ :" << iTemp << "(" << typeid(iTemp).name() << ")" << std::endl;

	alqaz_lexical_cast f{ const_int_number };
	auto from_alqaz_lexical = lexical_cast<string>(f);
	cout << "lexical_cast<string>(alqaz_lexical_cast),�ɣ� " << typeid(alqaz_lexical_cast).hash_code() << " ��: " << from_alqaz_lexical << endl;


	alqaz_lexical_cast next = lexical_cast<alqaz_lexical_cast>(const_int_number);
	cout << "lexical_cast<alqaz_lexical_cast>(int),�ɣ� " << typeid(const_int_number).name() << " ���� " << typeid(next).name() << endl;
	try{
		auto wrong_cast = lexical_cast<int>(const_str_not_num);
	}
	catch (bad_lexical_cast& e)
	{
		cout << "��:" << __FILE__ << "(" << __LINE__ << ")��" << "ת���쳣����" << e.what() << endl;
	}
}

//boost/format.hpp
//����Ƚϼ򵥣���Ҫ�õ���ʱ��һ�¼��ɡ�
void alqaz_test_format()
{
	cout << format("%s: %d + %d = %d") % "sum" % 1 % 2 % (1 + 2) << endl;  //������ʽ��printf�ǳ���������ͬ�����Լ����ʽ���Ʒ������� %05d
	format fmt("(%1% + %2%)* %2% = %3%\n");		//������ʽ�� %n% ��ʾ����ᱻ��n��������ֵ�滻��
	fmt % 2 % 5;
	fmt % ((2 + 5) * 5);
	cout << fmt.str();

	format f("%1% %2% %3% %2% %1% \n");
	f.bind_arg(2, 10); //��%2% Ϊ10
	f % 100 % 90;
	auto out = f.str();  cout << out << endl;
	f.clear();  //�󶨵� %2% ����ı�,����10

	cout << f % group(showbase, oct, 111) % 333; // %1%��Ϊ�����ʽΪ�˽���

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
	replace_first(temp, "lq", "LQ");  //��temp���׸�lq�滻��LQ
	cout << temp << endl;

	vector<char> v(temp.begin(), temp.end());
	vector<char> v2 = to_upper_copy(erase_first_copy(v, "txt"));   //ɾ���׸��Ӵ�"txt"
	for (auto i : v2){
		cout << i << " ";
	}
	cout << endl;
	to_upper(v);	//v��������Ļ�͵ر��д
	for (auto i : v) cout << i << " ";
	cout << endl;

	cout << to_lower_copy(const_str_not_num) << endl;

	assert(istarts_with(const_str_not_num, "alq"));  //i��ͷ�ĺ�����˼�Ǻ��Դ�Сд��const_str_not_num�Ƿ���alq��ͷ

	cout << lexicographical_compare(const_str_not_num, "alqa") << endl;;  //���ֵ�˳����const_str_not_num��"alqa���Ĵ�С�������ַ������ȿ��Բ���� param1<param2 ����true
	string tempy = "alqaz";
	cout << all(tempy, is_lower()) << endl;;		//���tempy�����ַ��Ƿ���Сд,����is_space, is_alnum, is_alpha�� is_any_of, is_from_range��
	tempy = "alqaz.txt";
	cout << "�Ƚ������ַ����Ƿ���� " << is_equal()(const_str_not_num, tempy) << endl;  //�Ƚ��ַ����Ƿ���ȣ����� is_less, is_not_greater

	format fmt("|%s|. pos = %d\n");
	iterator_range<string::iterator> rge;

	rge = find_first(_long_string_not_num, "long");	//rge��һ����������Χ��,������pair<it1,it2>����rge����ָ����ҵĽ������������ҵ�rgx=long,����='';�������ƺ�������i.. find_nth, find_head,rge������Ĭ��תΪbool����
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

	ar.assign(777);
	for (auto x = ar.begin(); x != ar.end(); ++x)
	{
		std::cout << *x << " �� ";
	}
	ar.at(3);
	cout << " �������" << endl;
	//c++11��û��ar.c_array()��arrayת��c��ָ�� ar.at(xx)����б߽��飬ar[xx]
}

void alqaz_test_bitset()
{
	std::bitset<5> v;  //����ÿһ������true/falseֵ
	v[0] = true;  //
	v[2] = false;
	bool b_all_true = v.all();		//�Ƿ����ж�Ϊtrue
	bool b_any_true = v.any();
	cout << v.to_string() << endl; //���00001,ע��˳��
	cout << v.to_string('*'/*0��*�����*/, 'X'/*1��X���*/) << endl;
	cout << v.to_ullong() << endl;
	v.flip();	//��ת true->false, false->true
	cout << v.to_string('*', 'X') << endl;
	v.flip(4/*���巴ת�ĸ�λ�õ�ֵ*/);
	cout << v.to_string('*', 'X') << endl;
	int isize = v.size();
}

void alqaz_test_unordered()
{
	std::unordered_set<int> a = { 1, 2, 3, 4, 5, 6 };
	for (auto i = a.begin(); i != a.end(); ++i)
	{
		cout << *i << " ";  //ע�����˳�򣬲�����1,2,3,4,,5,6
	}
	cout << endl;
	//cout << a.size() << endl;
	cout << a.bucket_count() << endl;
	cout << a.bucket_size(1) << endl;  //���ص�n��Ͱ��Ԫ�صĸ���

}

void alqaz_test_bimap()
{
	/************************************************************************/
	/* ������ض�����º����ã���ǰ�ڱ���װ�ҳ������ҳid֮���ӳ���õ���             */
	/************************************************************************/
	bimap<int, string> bm;	//˫��Map
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

	auto left_pos = bm2.by<id>().find(11);  //project_rightӳ�䷽���ָ��Left�ĵ�����ת����ָ��Right�ĵ�����
	auto right_pos = bm2.project_right(left_pos);

	cout << "right [" << right_pos->first << "]" << right_pos->second << endl;

	//typedef bimap<set_of<bimaps::tagged<int, struct id>>, multi_set<bimaps::tagged<string, struct name>>> bm_t2; ע��bimap������ģ���������
}