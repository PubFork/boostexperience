
#include "stdafx.h"
#include "../includes/commonLibraryDemo.h"

#include "boost/test/output_test_stream.hpp"
#include "boost/test/floating_point_comparison.hpp"
#include <cmath>
Demo d;

boost::test_tools::predicate_result validate_list(std::list<int>& L1) //自定义函数返回值类型必须是boost::test_tools::predicate_result
{
	for (auto it = L1.begin(); it != L1.end(); ++it)
	{
		if (*it <= 1) return false;
	}
	return true;	//bool类型可以转成boost::test_tools::predicate_result
}

BOOST_AUTO_TEST_CASE( alqaz )  
{	
	BOOST_REQUIRE(func1(11) == 11);
	BOOST_REQUIRE(d.Add() == 2);
	double dx = 2.0;
	BOOST_CHECK_CLOSE_FRACTION(dx, d.Sqrt()*d.Sqrt(), 0.001);  //浮点数计算单元测试(注意，dx和Sqrt()*Sqrt()类型最好相同(float, float)或者(double, double)，如果不相同，生成警告。

	std::list<int> LRight{ 2, 3, 4, 5, 6 };
	std::list<int> LWrong{ 1, 2, 3, 4, 5 };

	BOOST_CHECK(validate_list(LRight));			//自定义断言,单元测试通过
	BOOST_CHECK(validate_list(LWrong));			//其中第一个值是1,不能通过测试
}

