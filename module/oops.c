#include <linux/kernel.h> 
#include <linux/module.h> 
#include <linux/init.h> 
 
static int __init my_oops_init(void) { 
	int ret = 0;
        printk("oops from the module\n"); 
        //create_oops(); 
       return ret; 
} 
static void __exit my_oops_exit(void) { 
        printk("Goodbye world\n"); 
} 
 
module_init(my_oops_init); 
module_exit(my_oops_exit);
