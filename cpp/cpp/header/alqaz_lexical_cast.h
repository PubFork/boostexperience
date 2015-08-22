#ifndef ALQAZ_LEXICAL_CAST_H
#define ALQAZ_LEXICAL_CAST_H

#include "common.h"
using namespace std;

class alqaz_lexical_cast 
{
public:
	alqaz_lexical_cast(int x = 0) :m_nAlqaz(x){}
	friend ostream& operator <<(ostream& os, const alqaz_lexical_cast& x);	//对类重载了<<运算符，则可以调用lexical_cast<string>(alqaz_lexical_cast&)函数
	friend istream& operator >>(istream&, alqaz_lexical_cast& out);		//对类重载了>>运算符，则可以调用lexical_cast<alqaz_lexical_cast>(int&)函数, 注意第二个参数类型

	int get_Alqaz();
	bool set_Alqaz(int x);
private:
	int m_nAlqaz;
};

#endif //ALQAZ_LEXICAL_CAST_H