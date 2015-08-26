#include "demo.h"

//#define test_lexical_cast 
//#define test_format 
//#define	test_string_alog
#define test_alqaz_tokenizer
#define test_alqaz_xpress
#define test_alqaz_array
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
#ifdef test_alqaz_tokenizer
	alqaz_test_tokenizer();
#endif
#ifdef test_alqaz_xpress
	alqaz_test_xpress();
#endif
#ifdef test_alqaz_array
	alqaz_test_array();
#endif
	return 1;
}
