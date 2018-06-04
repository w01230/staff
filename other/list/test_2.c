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

static void write_2(char *src)
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

static void read_2(void)
{
	printf("read 2:%s\n", buffer);
}


static struct select_operations ops = {
	.id = 0x3000,
	.write = write_2,
	.read = read_2
};


SELECT_INIT(ops, 103);

