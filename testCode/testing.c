#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{  
    printf("Invoking 'My Syscall (sys_listing)' system call");

         
    long int ret_status = syscall(548); 
         
    if(ret_status == 0) 
         printf("System call 'sys_listing' executed correctly. Use dmesg to check processInfo\n");
    
    else 
         printf("System call 'sys_listing' did not execute as expected\n");
          
     return 0;
}
