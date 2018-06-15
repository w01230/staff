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
#include <signal.h>
#include <stdbool.h>

int globalvarfd = 0;

void input_handler(int signal)
{
	int data = 0;
	printf("catch singal:%d\n", signal);
	read(globalvarfd, &data, sizeof(int));
	printf("read:%d\n", data);
}

int main(int argc, char *argv[])
{
	int flags = 0;

	globalvarfd = open("/dev/globalvar0", O_RDONLY);
	if (globalvarfd < 0) {
		perror("open globalvar0 failed\n");
		return -1;
	}

	signal(SIGIO, input_handler);
	fcntl(globalvarfd, F_SETOWN, getpid());
	flags = fcntl(globalvarfd, F_GETFL);
	fcntl(globalvarfd, F_SETFL, flags | FASYNC);
	while (true);

	
	return 0;
}
