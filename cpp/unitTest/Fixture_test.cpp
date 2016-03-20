      
#include "stdafx.h"



struct F
{
	F() :i(0)
	{
		std::cout << "setup" << std::endl;
	}
	~F()
	{
		std::cout << "tear down" << std::endl;
	}
	int i;
};

//BOOST_AUTO_TEST_SUITE(Fixture_test) 
/************************************************************************/
/* fixture���� BOOST_FIXTURE_TEST_CASE �ڵ�ǰ����case������һ�������������ڲ������ʱɾ����*/
/************************************************************************/

BOOST_FIXTURE_TEST_CASE(test_case1, F)
{
	BOOST_CHECK(i == 0);
	++i;
	BOOST_CHECK(i == 1);
}

BOOST_AUTO_TEST_CASE( Fixture_test )  
{
     // TODO: Your test code here
}

//BOOST_AUTO_TEST_SUITE_END()