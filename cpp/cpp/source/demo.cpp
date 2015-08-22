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
	std::cout << "lexical_cast<int>(std::string),��: " << const_str_num <<"("<<typeid(const_str_num).hash_code() //��hash_code()������name()����Ϊ�ַ���������̫������ʾЧ����
		<< ")" <<  "ת�����Ϊ :"  << iTemp << "(" << typeid(iTemp).name() << ")" <<  std::endl;

	alqaz_lexical_cast f{ const_int_number };	
	auto from_alqaz_lexical = lexical_cast<string>(f);
	cout << "lexical_cast<string>(alqaz_lexical_cast),�ɣ� " << typeid(alqaz_lexical_cast).hash_code() << " ��: " << from_alqaz_lexical << endl;


	alqaz_lexical_cast next = lexical_cast<alqaz_lexical_cast>(const_int_number);
	cout << "lexical_cast<alqaz_lexical_cast>(int),�ɣ� " << typeid(const_int_number).name() << " ���� " << typeid(next).name() << endl;
	try{
		auto wrong_cast = lexical_cast<int>(const_str_not_num);
	}
	catch(bad_lexical_cast& e)
	{
		cout <<"��:"<< __FILE__ << "(" << __LINE__ << ")��" << "ת���쳣����" << e.what() << endl;
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