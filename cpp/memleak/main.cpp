#include "common.h"

void leak_function()
{
	char* p = new char[100];
	int x = 1;
	int y = x + 1;
}

int main(void)
{
	leak_function();

	return 1;
}

