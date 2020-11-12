#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Igor Taraymovich <tarajmovich.i@phystech.edu>");

static int __init init_my_module(void) {
    printk(KERN_INFO "Hello, loading\n");
    return 0;
}

static void __exit cleanup_my_module(void) {
    printk(KERN_INFO "Leaving\n");
}

module_init(init_my_module);
module_exit(cleanup_my_module);
