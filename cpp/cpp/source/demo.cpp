#include "common.h"


void alqaz_test_lexical_cast()
{
	using namespace boost;
	int iTemp = lexical_cast<int>("11111");
	std::cout << "�� lexical_cast<int>(std::string)ת������ : " <<  iTemp << std::endl;
}