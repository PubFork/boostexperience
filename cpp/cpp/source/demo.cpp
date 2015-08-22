#include "demo.h"
#include "common.h"
#include "alqaz_lexical_cast.h"
#include "boost/lexical_cast.hpp"

#include <string>

using namespace boost;

const string const_str_num = "12345";
const int	const_int_number = 11;

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



}