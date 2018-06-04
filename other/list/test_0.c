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

static void write_0(char *src)
{
	int len = 0;

	if (src == NULL)
		printf("invalid source\n");

	len = strlen(src);
	if (len >= 256)
		printf("copy part of the input data\n");

	len = len > (sizeof(buffer) - 1) ? sizeof(buffer) - 1 : len;
	strncpy(buffer, src, len);

	return;
}

static void read_0(void)
{
	printf("read 0:%s\n", buffer);
}


static struct select_operations ops = {
	.id = 0x1000,
	.write = write_0,
	.read = read_0
};



select_init(ops, 101)

