/**
 * Resources:
 * https://www.tldp.org/LDP/lpg/node11.html
 * https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/
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
#include<sys/wait.h>

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
    exit(0);
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
    
    int pid1;
    int pid2;
    int fd[2];
    

    if(pipe(fd) == -1){
        printf("Error in pipe system call\n");
        perror("ERROR  in pipe()");
        return 1;
    }

    if((pid1 = fork()) < 0){
        printf("Error");
        return 1;
    }
    
    if(pid1 > 0){
        if((pid2 = fork()) < 0){
            printf("Error");
            return 1;
        }        
        
        if(pid2 > 0){
            printf("##### From Parent: \n");
            close(fd[0]);
            write(fd[1], &pid2, sizeof(pid2));
            close(fd[1]);
            printf("pid1: %d,  pid2: %d\n", pid1, pid2);
            int status;
            printf("Waiting change of state of 2nd child by the 1st child\n");
            waitpid(pid2, &status, 0);
            printf("Parent continue\n");
            printf("Killing the 1st child\n");
            kill(pid1, SIGTERM);

        }
        else{
            printf("##### From Child2: \n");
            while(1){
                printf("Hi from the 2nd child\n");
                sleep(1);
            }
        }
    }
    else{
        printf("##### From Child1: \n");
        sleep(3);
        printf("Stopping the 2nd child\n");
        int buff;
        close(fd[1]);
        read(fd[0], &buff, sizeof(buff));
        close(fd[0]);
        printf("Got the pid of the 2nd child: %d\n", buff);
        kill(buff, SIGSTOP);
        sleep(3);
        printf("Killing the 2nd child\n");
        kill(buff, SIGTERM);
        printf("1st Child finshed\n");
    }
    printf("process: %d\n", getpid());
    while(1);

    return 0;
}