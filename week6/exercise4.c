/**
 * Resources:
 * https://www.geeksforgeeks.org/signals-c-language/
 * https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal
 * http://linuxcommand.org/lc3_lts0100.php
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

void kill_signal_handler(int sig){
    printf("Kill signal\n");
}

void stop_signal_handler(int sig){
    printf("stop signal\n");
}

void usr_signal_handler(int sig){
    printf("usr signal\n");
}

int main()
{
    signal(SIGINT, interrupt_handler);
    signal(SIGKILL, kill_signal_handler);
    signal(SIGSTOP, stop_signal_handler);
    signal(SIGUSR1, usr_signal_handler);
    while (1)
    {
        // printf("In the loop!!\n");
        // sleep(1);
    }
    
    return 0;
}

/*
    Explanation that the kill process with the flag sends a signal to the process,
        and the process has a handler for it, so, it execute the handler and print the text.
*/
