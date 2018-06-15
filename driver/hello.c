#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/spinlock.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/semaphore.h>
#include <linux/poll.h>

#define MAJOR_NUM   0 
#define DEVICE_NAME  "globalvar"

static struct cdev cdev;
static struct class *globalvar_class;
static dev_t devno;
static struct semaphore sem;
static DEFINE_SPINLOCK(spin);
static wait_queue_head_t waitqueue;
static struct fasync_struct *fasync_queue;
static int globalvar = 0;
static int global_count = 0;
static int status = 0;

static int globalvar_open(struct inode *inode, struct file *filp)
{
	int ret = 0;
	
	spin_lock(&spin);
	global_count++;
	spin_unlock(&spin);

	return ret;
}

static int globalvar_release(struct inode *inode, struct file *filp)
{
	int ret = 0;

	spin_lock(&spin);
	global_count--;
	spin_unlock(&spin);

	return ret;
}

static ssize_t globalvar_read(struct file *filp, char __user *buf, size_t count, loff_t *offp)
{
	ssize_t ret = 0;

	if (wait_event_interruptible(waitqueue, status != 0) != 0)
		return -ERESTARTSYS;

	if (down_interruptible(&sem) != 0)
		return -ERESTARTSYS;

	if (copy_to_user(buf, &globalvar, sizeof(int)) != 0)
		ret =  -EFAULT;
	status = 0;

	up(&sem);

	return ret;
}

static ssize_t globalvar_write(struct file *filp, const char *buf, size_t len, loff_t *offp)
{
	ssize_t ret = sizeof(int);

	if (down_interruptible(&sem) != 0)
		return -ERESTARTSYS;

	if (copy_from_user(&globalvar, buf, sizeof(int)) != 0)
		ret = -EFAULT;

	status = 1;
	if (fasync_queue != NULL)
		kill_fasync(&fasync_queue, SIGIO, POLLIN);

	up(&sem);

	wake_up_interruptible(&waitqueue);

	return ret;
}

static unsigned int globalvar_poll(struct file *filp, poll_table *wait)
{
	unsigned int mask = 0;

	poll_wait(filp, &waitqueue, wait);

	if (down_interruptible(&sem) != 0)
		return -ERESTARTSYS;
	if (status != 0)
		mask |= POLLIN | POLLRDNORM;
	up(&sem);

	return mask;
}

static int globalvar_fasync(int fd, struct file *filp, int mode)
{
	return fasync_helper(fd, filp, mode, &fasync_queue);
}

struct file_operations globalvar_fops = {
	.owner = THIS_MODULE,
	.open = globalvar_open,
	.release = globalvar_release,
	.read = globalvar_read,
	.write= globalvar_write,
	.poll = globalvar_poll,
	.fasync = globalvar_fasync,
};

static int __init globalvar_init(void)
{
	struct device *dev;
	int ret = 0;
	unsigned int major = 0;
	
	printk("globalvar init...\n");
	
	devno = MKDEV(MAJOR_NUM, 0);
	major = MAJOR(devno);
	if (major != 0)
		ret = register_chrdev_region(devno, 1, DEVICE_NAME);
	else 
		ret = alloc_chrdev_region(&devno, 0, 1, DEVICE_NAME);
	
	if (ret < 0) {
		printk(KERN_ERR "failed to register dev\n");
		return ret;
	}

	cdev_init(&cdev, &globalvar_fops);
	cdev.owner = THIS_MODULE;
	ret = cdev_add(&cdev, devno, 1);
	if (ret < 0) {
		printk(KERN_ERR "failed to setup dev\n");
		return ret;
	}

	globalvar_class = class_create(THIS_MODULE, DEVICE_NAME);
	if (IS_ERR(globalvar_class)) {
		printk(KERN_ALERT "failed to create class\n");
		return -1;
	}

	dev = device_create(globalvar_class, NULL, devno, NULL, DEVICE_NAME "%d", 0);
	if (IS_ERR(dev)) {
		printk(KERN_ALERT "failed to create device");
		return -1;
	}
	printk("init done\n");

	sema_init(&sem, 1);
	init_waitqueue_head(&waitqueue);

	return ret;
}

static void __exit globalvar_exit(void)
{
	cdev_del(&cdev);
	unregister_chrdev_region(devno, 1);
	device_destroy(globalvar_class, devno);
	class_destroy(globalvar_class);
}

module_init(globalvar_init);
module_exit(globalvar_exit);

MODULE_LICENSE("GPL");
