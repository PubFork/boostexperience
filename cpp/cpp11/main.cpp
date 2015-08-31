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

//��С��
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
	 /* short=1���������ֽ�   ��λ=0����λ=1 ,��Endian.i=1,��ȡֵEndian.c==1,˵���͵�ַ������short�ĵ�λ����С                           */
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
