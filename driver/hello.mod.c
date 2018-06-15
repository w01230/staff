#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x58d45940, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x1074a15d, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x5670749f, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0xf583f4ec, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0x19ad6985, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x8f211b3, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x98cac03c, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x5a6e8fef, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0x95a73d0c, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xce31b8a1, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0xb44ad4b3, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xced6bcd8, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x69e43cfd, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xfe487975, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0x5b205e34, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0x6ac24f3c, __VMLINUX_SYMBOL_STR(kill_fasync) },
	{ 0x362ef408, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x78e739aa, __VMLINUX_SYMBOL_STR(up) },
	{ 0x6dc0c9dc, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0x2ea2c95c, __VMLINUX_SYMBOL_STR(__x86_indirect_thunk_rax) },
	{ 0xa1513a0d, __VMLINUX_SYMBOL_STR(fasync_helper) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "66E2B033CD12CF542316D68");
