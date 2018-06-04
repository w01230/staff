/**
 * head file for select
 *
 *
 * JW@2018.06.01
 */
#define type_void(fn) void fn (void)
#define select_init(ops, n) __attribute__((constructor(n))) static type_void(init_call_##n##_used) {ops_add(ops);}

/* slecet operations call back */
struct select_operations {
	int id;
	void (*write)(char *src);
	void (*read)(void);
};

void ops_add(struct select_operations iops);
