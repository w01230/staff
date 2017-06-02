/*
 * test file
 *
 *
 * 2016.07.15
 */
#include <stdio.h>
#include "hello.h"

int main(int argc, char** argv)
{
	char point1[] = "Hello";
	char point2[] = "Xello";

	*point2 = *point1;

	printf("string2:%s\n", point2);

	hello();
	
	return 0;
}
