#include <linux/init.h>
#include <linux/module.h>
#include <linux/proc_fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mohit G");
MODULE_DESCRIPTION("First Dynamically loadable kernel module");

static struct proc_dir_entry * driver_proc_node;
const struct proc_ops driver_proc_ops;

static int driver_module_init (void) {
    printk("driver_module_init: entry\n");

    /* We would like to create a file/logical file whenever our driver loads in /proc/
    * proc_ops holds the operations that can be performed on the file
    * refer https://github.com/torvalds/linux/blob/master/include/linux/proc_fs.h#L35 for details
    */
    driver_proc_node = proc_create("mfile_driver", 0, NULL, &driver_proc_ops); //proc_fs.h#L117

    // handling error if module init fail die to proc node/file creation
    if(driver_proc_node == NULL){
      printk("driver_module_init: initializing proc file/node resulted in error\n");  
      return -1;
    }

    printk("driver_module_init: exit\n");

    return 0;
}

static void driver_module_exit (void) {
    printk("driver_module_exit: entry\n");

    /* We would like to remove the file/logical file whenever our driver is removed
    */
    proc_remove(driver_proc_node);

    printk("driver_module_exit: exiting\n");
}

module_init(driver_module_init);
module_exit(driver_module_exit);