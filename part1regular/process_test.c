#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

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

int entry_program(void) {
    struct task_struct *task;
    printk(KERN_INFO "%16s %16s %16s\n========================================\n", "Name", "State", "Process ID");
    for_each_process(task) {
#ifdef PRINT_NUMBERS
    printk(KERN_INFO "%16s %16ld %16d\n", task->comm, task->state, task->pid);
#else
    printk(KERN_INFO "%16s %16s %16d\n", task->comm, getStateName(task->state), task->pid);
#endif
    }

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