/** 
 *  order test0
 *
 *
 * JW@2018.06.01
 */
#include <stdio.h>

int order_add(int (*order_query) (int type, void **data));
static void order_2(void);
static char order_name[10] = "order 2";
static int order_number = 0x3000;
static void (*order_callback)(void) = order_2;

static int order_query(int type, void **data);
static int dummy = order_add(order_query);

static int order_query(int type, void **data)
{
	int ret = 0;

	switch(type) {
	case 0:
		*data = (void *)order_name;
		break;

	case 1:
		*((int *)(*data)) = order_number;
		break;

	case 2:
		*data = (void *)order_callback;
		break;

	default:
		ret = -1;
		break;
	}

	return ret;
}

static void order_2(void)
{
	printf("this is:%s\n", order_name);
}
