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
	fd_set fds;
	struct timeval tv;
	int input = 0;

	globalvarfd = open("/dev/globalvar0", O_RDONLY);
	if (globalvarfd < 0) {
		perror("open globalvar0 failed\n");
		return -1;
	}


	do {

		FD_ZERO(&fds);
		FD_SET(globalvarfd, &fds);

		tv.tv_sec = 5;
		tv.tv_usec = 0;

		select(globalvarfd + 1, &fds, NULL, NULL, &tv);
		if (!FD_ISSET(globalvarfd, &fds)) {
			printf("no input data in 5 seconds\n");
			continue;
		}
		read(globalvarfd, &input, sizeof(int));
		printf("read:%d\n", input);
	} while (input != 0xFF);

	return 0;
}
