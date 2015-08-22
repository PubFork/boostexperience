#include "demo.h"

//#define test_lexical_cast 
//#define test_format 
#define	test_string_alog
int main(void)
{
#ifdef test_lexical_cast
	alqaz_test_lexical_cast();
#endif
#ifdef test_format
	alqaz_test_format();
#endif // test_format

#ifdef test_string_alog
	alqaz_test_string_algo();
#endif

	return 1;
}
