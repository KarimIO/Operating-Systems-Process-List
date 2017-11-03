#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

//#define PRINT_NO_TABS
//#define PRINT_NUMBERS

const char *getStateName(long state) {
    switch(state) {
        case 0:
            return "Running";
        case 1:
            return "Interruptible";
        case 2:
            return "Uninterruptible";
        case 4:
            return "Stopped";
        case 8:
            return "Traced";
        case 16:
            return "Dead";
        case 32:
            return "Zombie";
        case 64:
            return "Dead";
        case 128:
            return "WakeKill";
        case 256:
            return "Waking";
        case 512:
            return "Parked";
        case 1024:
            return "Noload";
        default:
            return "Invalid";
    };
}

void depth_first_search(struct task_struct *task, int count) {
    struct task_struct *child;
	struct list_head *task_list;
	
#ifdef PRINT_NO_TABS
    #ifdef PRINT_NUMBERS
        printk(KERN_INFO "Name: %-24s Process ID: %d   State: %ld\n", task->comm, task->pid, task->state);
    #else
        printk(KERN_INFO "Name: %-24s Process ID: %d   State: %s\n", task->comm, task->pid, getStateName(task->state));
    #endif
#else
    #ifdef PRINT_NUMBERS
        printk(KERN_INFO "%*s: %-24s Process ID: %d   State: %ld\n", count*3, "Name", task->comm, task->pid, task->state);
    #else
        printk(KERN_INFO "%*s: %-24s Process ID: %d   State: %s\n", count*3, "Name", task->comm, task->pid, getStateName(task->state));
    #endif
#endif
	list_for_each(task_list, &task->children) {
        child = list_entry(task_list, struct task_struct, sibling);
		depth_first_search(child, count+1);
	}
}

int entry_program(void) {
    printk(KERN_INFO "Listing active processes...");
	depth_first_search(&init_task, 0);
    
    return 0;
}

void exit_module(void) {
    printk(KERN_INFO "Test Exit\n");
}

module_init(entry_program);
module_exit(exit_module);

MODULE_AUTHOR("Karim Abdel Hamid");
MODULE_DESCRIPTION("Test!");
MODULE_LICENSE("UNLICENSE");