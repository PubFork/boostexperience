#ifndef ALQAZ_LEXICAL_CAST_H
#define ALQAZ_LEXICAL_CAST_H

#include "common.h"
using namespace std;

class alqaz_lexical_cast 
{
public:
	alqaz_lexical_cast(int x = 0) :m_nAlqaz(x){}
	friend ostream& operator <<(ostream& os, const alqaz_lexical_cast& x);	//����������<<�����������Ե���lexical_cast<string>(alqaz_lexical_cast&)����
	friend istream& operator >>(istream&, alqaz_lexical_cast& out);		//����������>>�����������Ե���lexical_cast<alqaz_lexical_cast>(int&)����, ע��ڶ�����������

	int get_Alqaz();
	bool set_Alqaz(int x);
private:
	int m_nAlqaz;
};

#endif //ALQAZ_LEXICAL_CAST_H