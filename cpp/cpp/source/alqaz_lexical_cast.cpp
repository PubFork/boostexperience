#include "common.h"
#include "alqaz_lexical_cast.h"

int alqaz_lexical_cast::get_Alqaz()
{
	return m_nAlqaz;
}

bool alqaz_lexical_cast::set_Alqaz(int x)
{
	m_nAlqaz = x;
	return true;
}

ostream& operator << (ostream&os, const alqaz_lexical_cast& x)
{
	os << typeid(x).name();
	return os;
}

istream& operator >> (istream& in, alqaz_lexical_cast& out)
{
	int itemp;
	in >> itemp;
	out.set_Alqaz(itemp);

	return in;
}

