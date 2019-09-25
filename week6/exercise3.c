/**
 * Resources:
 * https://www.geeksforgeeks.org/signals-c-language/
 * https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal
 * */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>

#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */
#define SIGKILL 9
#define SIGUSR1 10
#define SIGSEGV 11
#define SIGUSR2 12
#define SIGPIPE 13
#define SIGALRM 14
#define SIGTERM 15

void interrupt_handler(int sig){
    printf("You pressed Ctrl-C\n");
}

int main()
{
    signal(SIGINT, interrupt_handler);
    while (1)
    {
        printf("In the loop!!\n");
        sleep(1);
    }
    
    return 0;
}
