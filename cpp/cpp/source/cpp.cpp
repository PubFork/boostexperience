#include "demo.h"

//#define test_lexical_cast 
//#define test_format 
//#define	test_string_alog
//#define test_alqaz_tokenizer
//#define test_alqaz_xpress
//#define test_alqaz_array
// #define test_alqaz_bitset
//#define test_alqaz_unordered
//#define test_alqaz_bimap
//#define test_alqaz_circular_buffer
//#define test_alqaz_tuple
//#define test_alqaz_rational
//#define test_alqaz_crc
#define test_alqaz_io_state
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
#ifdef test_alqaz_bitset
	alqaz_test_bitset();
#endif 
#ifdef test_alqaz_unordered
	alqaz_test_unordered();
#endif
#ifdef test_alqaz_bimap
	alqaz_test_bimap();
#endif
#ifdef test_alqaz_circular_buffer
	alqaz_test_circular_buffer();
#endif
#ifdef test_alqaz_tuple
	alqaz_test_tuple();
#endif
#ifdef test_alqaz_rational
	alqaz_test_rational();
#endif
#ifdef test_alqaz_crc
	alqaz_test_crc();
#endif
#ifdef test_alqaz_io_state
	alqa_test_io_state();
#endif
	return 1;
}
