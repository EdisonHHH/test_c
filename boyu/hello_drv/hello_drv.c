#include <linux/module.h>
#include <linux/kernel.h>        /* printk() */
#include <linux/fs.h>            /* everything... */
#include <linux/init.h>
#include <linux/delay.h>
#include <asm/uaccess.h>         /* copy_*_user */
#include <asm/irq.h>
#include <asm/io.h>

#include <linux/device.h>

#include <linux/cdev.h>
#include <linux/mm.h>
#include <linux/i2c.h>
#include <linux/slab.h>         /* kmalloc() */
#include <linux/version.h>

#include <linux/ioctl.h>

#include <linux/io.h>

#define LEN 0x1000
static struct class *buttondrv_class;
static struct class_device	*buttondrv_class_dev;


unsigned char buf_mem[LEN];

static int button_drv_open(struct inode *inode, struct file *file)
{

	return 0;
}



static ssize_t button_drv_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
	unsigned long p=*ppos;
	unsigned int count=size;
	int ret;
	
	if(p>=LEN)
		return count? -ENXIO:0;
	if(count>LEN-p)
		count=LEN-p;

	if(copy_to_user(buf,(void*)(buf_mem+p),count))
	{
		ret=EFAULT;
	}
	else
	{
		*ppos+=count;
		ret=count;
	}
	return ret;
}

static ssize_t button_drv_write(struct file *filp,const char __user *buf,size_t size,loff_t *ppos)
{
	unsigned long p=*ppos;
	unsigned int count=size;
	int ret=0;

	if(p>=LEN)
		return count? -ENXIO:0;
	if(count>LEN-p)
		count=LEN-p;
	
	if(copy_from_user(buf_mem+p,buf,count))
		ret=-EFAULT;
	else
	{
		*ppos+=count;
		ret=count;
	}
	return ret;
}
static struct file_operations button_drv_fops = {
    .owner  =   THIS_MODULE,    /* 这是一个宏，推向编译模块时自动创建的__this_module变量 */
    .open   =   button_drv_open,     
	.read	=	button_drv_read,
	.write  =   button_drv_write  
};


static dev_t dev=0;
static struct cdev my_cdev;
static int button_drv_init(void)
{
	int result=0;
	

	result=alloc_chrdev_region(&dev,0,1,"button_drv");
	cdev_init(&my_cdev,&button_drv_fops);
	my_cdev.owner=THIS_MODULE;
	my_cdev.ops=&button_drv_fops;
	cdev_add(&my_cdev,dev,1);


	buttondrv_class = class_create(THIS_MODULE, "button_drv");
	buttondrv_class_dev = device_create(buttondrv_class, NULL, dev, NULL, "buttons"); /* /dev/buttons */



	return 0;
}

static void button_drv_exit(void)
{
    cdev_del(&my_cdev);
	unregister_chrdev_region(dev,1);

	device_unregister(buttondrv_class_dev);
	class_destroy(buttondrv_class);
	
}
module_init(button_drv_init);

module_exit(button_drv_exit);

MODULE_LICENSE("GPL");


