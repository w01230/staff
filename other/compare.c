/**
 * macro test
 *
 *
 * J.W@2017/07/19
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(A, B)    ({__typeof(A) __a =(A); typeof(B) __b = (B); __a < __b ? __a : __b;})


int main(int argc, char *argv[])
{
	int a = 100;
	int b = 200;

	printf("%d\n", MIN(a, b));
	a = 5;
	printf("%d\n", MIN(a--, --a));
	
	return 0;
}
