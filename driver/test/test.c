/**
 *  test.c
 *
 *
 *  driver test source code
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int globalvarfd = 0;
	int input = 0;

	globalvarfd = open("/dev/globalvar0", O_RDWR);
	if (globalvarfd < 0) {
		perror("open globalvar0 failed\n");
		return -1;
	}
	
	do {
		scanf("%d", &input);
		write(globalvarfd, &input, sizeof(int));
	} while (input != 0xFF);

	return 0;
}
