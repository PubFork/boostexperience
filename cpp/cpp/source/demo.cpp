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
	
