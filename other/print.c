/**
 * test for printf
 *
 *
 * J.W@2017/07/19
 */
#include <stdlib.h>
#include <stdio.h>

#define GET_FUNCTION_NAME(x)  #x

static int test(void)
{
	printf("test\n");
	
	return 0;
}

int main(int argc, char* argv[])
{
	char data = 43;

	printf("%d\n", printf("%d", printf("%d", data)));
	printf("name:%s\n", GET_FUNCTION_NAME(test));

	return 0;
}
