#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int (*ORDERLIST[10]) (int type, void **data);

static int order_number = 0;
int order_add(int (*order_query) (int type, void **data))
{
	if (order_number < 10)
		ORDERLIST[order_number++] = order_query;

	return 0;
}

int main(int argc, char *argv[])
{
	long order_in = 0;
	int number = 0;
	void (*callback) (void);
	int (*order) (int type, void **data) = NULL;
	void *data = NULL;

	if (argc > 2)
		printf("invalid argc\n");
	
	order_in = strtol(argv[1], NULL, 10);
	printf("max order:%X\n", order_number);
	if (order_in >= order_number) {	
		printf("invaid order\n");
		return 0;
	}

	order = ORDERLIST[order_in];
	data = (void *)&number;
	order(1, &data);
	printf("number:%x\n", number);

	order(0, &data);
	printf("name:%s\n", data);

	order(2, &data);
	callback = (void (*) (void))data;
	callback();
	

	return 0;
}
