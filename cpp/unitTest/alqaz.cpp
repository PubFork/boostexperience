
#include "stdafx.h"
#include "../includes/commonLibraryDemo.h"

Demo d;

BOOST_AUTO_TEST_CASE( alqaz )  
{
	BOOST_REQUIRE(func1(11) == 11);
	BOOST_REQUIRE(d.Add() == 2);
}

