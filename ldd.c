#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohit G");
MODULE_DESCRIPTION("First Dynamically loadable kernel module");

static int driver_module_init (void) {
    printk("Hello world! from Mohittt\n");
    return 0;
}

static void driver_module_exit (void) {
    printk("Bye bye (from mohittt)\n");
}

module_init(driver_module_init);
module_exit(driver_module_exit);