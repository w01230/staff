/**
 * test about threadpool
 *
 *
 * J.W@Shanghai 2017/07/26
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "threadpool.h"

void *work(void *arg)
{
	printf("thread:%s\n", arg);
}

int main(int argc, char* argv[])
{
	threadpool_t *pool = NULL;
	char index[256] = {0};

	pool = threadpool_init(10, 20);
	for (int i = 0; i < 40; i++) {
		sprintf(index + 4 * i, "%d", i);
		threadpool_add_job(pool, work, index + 4 * i);
	}

	threadpool_destory(pool);

	return 0;
}
