/**
 * test 0
 *
 *
 *
 * JW@2018.06.01
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "test.h"

static char buffer[256] = {0};

static void write_1(char *src)
{
	int len = 0;

	if (src == NULL)
		printf("invalid source\n");

	len = strlen(src);
	if (len > 256)
		printf("copy part of the input data\n");

	len = len > (sizeof(buffer) - 1) ? sizeof(buffer) - 1 : len;
	strncpy(buffer, src, len);

	return;
}

static void read_1(void)
{
	printf("read 1:%s\n", buffer);
}


static struct select_operations ops = {
	.id = 0x2000,
	.write = write_1,
	.read = read_1
};


select_init(ops, 102)

