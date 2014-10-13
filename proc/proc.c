
static int proc_test_init(void)
{
	printk("proc_test init\n");
}

void proc_test_exit(void)
{
	printk("proc_test exit\n");
}

module_init(proc_test_init);
module_exit(proc_test_exit);
