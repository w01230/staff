/**
 *  allow to select operations
 *
 *
 * 
 * JW@2018.06.01
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"

int count = 0;
struct select_operations ops[10];

void ops_add(struct select_operations iops)
{
	memcpy(&ops[count++], &iops, sizeof(struct select_operations));
}

int main(int argc, char *argv[])
{
	long select = 0;

	if (argc < 3) {
		printf("invalid argc\n");
		return 0;
	}

	select = strtol(argv[1], NULL, 10);
	if (select > count -1) {
		printf("invalid select\n");
		return 0;
	}

	printf("id:%X\n", ops[select].id);
	ops[select].write(argv[2]);
	ops[select].read();

	return 0;
}
