/**
 * Resources:
 * https://www.geeksforgeeks.org/signals-c-language/
 * https://stackoverflow.com/questions/231912/what-is-the-difference-between-sigaction-and-signal
 * http://linuxcommand.org/lc3_lts0100.php
 * http://www.csl.mtu.edu/cs4411.ck/www/NOTES/signal/kill.html
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

void term_signal_handler(int sig){
    printf("term signal\n");
    exit(0);
}

int main()
{
    signal(SIGINT, interrupt_handler);
    signal(SIGKILL, kill_signal_handler);
    signal(SIGSTOP, stop_signal_handler);
    signal(SIGUSR1, usr_signal_handler);
    signal(SIGTERM, term_signal_handler);
    pid_t pid;
    
    if((pid = fork()) < 0){
        printf("Error");
        return 1;
    }

    if(pid > 0){
        printf("##### From Parent: \n");
        sleep(10);
        kill(pid, SIGTERM);
    }
    else{
        printf("##### From Child: \n");
        while(1){
            printf("I'm alive:)\n");
            sleep(1);
        }
    }
    while(1);

    return 0;
}