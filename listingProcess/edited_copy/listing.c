#include<linux/kernel.h>
#include<linux/init.h>	//init
#include<linux/sched.h> //task_struct
#include<linux/syscalls.h>
#include<linux/sched/signal.h> //for_each_process
#include<linux/printk.h> //printk

asmlinkage long sys_listing(void) {

    struct task_struct *task;

    for_each_process(task) {
 	if(task != NULL){
/* printk(
      "Task Detail: %s\n PID: %d\n State: %ld\n Priority: %ld\n RT_Priority: %ld\nStatic Priority: %ld\n Normal Priority: %ld\n PerTask Flags %d\n,Current Cpu %d\n,Base of mmap area %ld\n,Size Task VM space %ld\n My Added Value %d \n ", task->comm,(int)task_pid_nr(task), (long)task->state,(long)task->prio,(long)task->rt_priority,(long)task->static_prio,(long)task->normal_prio,(int)task->flags,(int)task->cpu,(long)task->mm->mmap_base,(long)task->mm->task_size,(int)task->my_added_value); */
      if(task->mm != NULL)
      {
         printk(
              "Task Detail: %s\n PID: %d\n State: %ld\n Priority: %ld\n RT_Priority: %ld\nStatic Priority: %ld\n Normal Priority: %ld\n PerTask Flags %d\n,Current Cpu %d\n,Base of mmap area %ld\n,Size Task VM space %ld\n My Added Value %d \n ", task->comm,(int)task_pid_nr(task), (long)task->state,(long)task->prio,(long)task->rt_priority,(long)task->static_prio,(long)task->normal_prio,(int)task->flags,(int)task->cpu,(long)task->mm->mmap_base,(long)task->mm->task_size,(int)task->my_added_value);
      }else{
    printk(
      "Task Detail: %s\n PID: %d\n State: %ld\n Priority: %ld\n RT_Priority: %ld\nStatic Priority: %ld\n Normal Priority: %ld\n PerTask Flags %d\n,Current Cpu %d\n , My Added Value %d \n", task->comm,(int)task_pid_nr(task), (long)task->state,(long)task->prio,(long)task->rt_priority,(long)task->static_prio,(long)task->normal_prio,(int)task->flags,(int)task->cpu,(int)task->my_added_value);
 }
}else{
	printk("Else of First\n");
}
 /* -1 unrunnable, 0 runnable, >0 stopped: */ //state

   if(task->parent != NULL)
{
/*	printk(
        "Parent process: %s , PID Of That: %d",task->parent->comm,(int)task_pid_nr(task->parent));
   printk("\n\n");*/
      printk(
        "Parent process: %s ",task->parent->comm);
   printk("\n\n");
   // Added extra part
   if(task_pid_nr(task->parent) != 0)
   {
     printk(
       "PID: %d ",(int) task_pid_nr(task->parent));
  printk("\n\n");
   }
   // Added extra part ended
} else{
	printk("task->parent == NULL..... \n\n");
}
  }

  return 0;
}

//defined in #include<linux/sched/signal.h>
//#define for_each_process(p) \
//	for (p = &init_task ; (p = next_task(p)) != &init_task ; )


// my_added_value is added to task_struct , at the end and initialized to 10
// Ali,i have added few changes , now try to compile this again.. and tell me results as ab meray pass laptop ni ubuntu wala
