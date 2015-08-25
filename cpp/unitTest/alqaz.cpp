
#include "stdafx.h"
#include "../includes/commonLibraryDemo.h"

#include "boost/test/output_test_stream.hpp"
#include "boost/test/floating_point_comparison.hpp"
#include <cmath>
Demo d;

boost::test_tools::predicate_result validate_list(std::list<int>& L1) //�Զ��庯������ֵ���ͱ�����boost::test_tools::predicate_result
{
	for (auto it = L1.begin(); it != L1.end(); ++it)
	{
		if (*it <= 1) return false;
	}
	return true;	//bool���Ϳ���ת��boost::test_tools::predicate_result
}

BOOST_AUTO_TEST_CASE( alqaz )  
{	
	BOOST_REQUIRE(func1(11) == 11);
	BOOST_REQUIRE(d.Add() == 2);
	double dx = 2.0;
	BOOST_CHECK_CLOSE_FRACTION(dx, d.Sqrt()*d.Sqrt(), 0.001);  //���������㵥Ԫ����(ע�⣬dx��Sqrt()*Sqrt()���������ͬ(float, float)����(double, double)���������ͬ�����ɾ��档

	std::list<int> LRight{ 2, 3, 4, 5, 6 };
	std::list<int> LWrong{ 1, 2, 3, 4, 5 };

	BOOST_CHECK(validate_list(LRight));			//�Զ������,��Ԫ����ͨ��
	BOOST_CHECK(validate_list(LWrong));			//���е�һ��ֵ��1,����ͨ������
}

