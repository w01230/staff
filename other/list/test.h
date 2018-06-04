/**
 * head file for select
 *
 *
 * JW@2018.06.01
 */
#define TYPE_VOID(fn) void fn (void)
#define SELECT_INIT(ops, n) __attribute__((constructor(n))) static TYPE_VOID(init_call_##n##_used) {ops_add(ops);}

/* slecet operations call back */
struct select_operations {
	int id;
	void (*write)(char *src);
	void (*read)(void);
};

void ops_add(struct select_operations iops);
