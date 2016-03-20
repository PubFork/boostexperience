      
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


BOOST_GLOBAL_FIXTURE(F);

BOOST_AUTO_TEST_CASE( GlobalFixture )  
{
     // TODO: Your test code here
	
}

