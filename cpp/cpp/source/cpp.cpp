#include "demo.h"

//#define test_lexical_cast 
#define test_format 
int main(void)
{
#ifdef test_lexical_cast
	alqaz_test_lexical_cast();
#endif
#ifdef test_format
	alqaz_test_format();
#endif // test_format



	return 1;
}
