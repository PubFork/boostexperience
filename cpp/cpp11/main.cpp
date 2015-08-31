#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
#include <random>
#include <functional>

using namespace std;

struct square
{

	//typedef void result_type;
	int operator()(int& x)
	{
		return  x*x;
	}

	void func()
	{
		cout << "hello, world" << endl;
	}

};

//大小端
union Endian
{
	short i;
	char c;
};

int main(void)
{
	using namespace std;

	square* sqr = new square();

	auto f = std::bind(&square::func, sqr);

	cout << typeid(f).name() << endl;

	std::function<int (int&)> fx = square();

	int xy = 11;
	 auto ret =  fx(xy);

	 
	 /************************************************************************/
	 /* short=1含有连个字节   高位=0，低位=1 ,给Endian.i=1,在取值Endian.c==1,说明低地址保存了short的低位，是小                           */
	 /************************************************************************/
	 Endian e;
	 e.i = 1;
	 if (e.c == 1)
	 {
		 cout << "win is :small endian" << endl;
	 }
	 else
	 {
		 cout << "win is big endian" << endl;
	 }

	return 1;
}
