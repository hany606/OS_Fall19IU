#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

int n;

int main(){
    if(fork() == 0)
        printf("Hello from child [%d - %d]\n", getpid(), n++);
    else
        printf("Hello from parent [%d - %d]\n", getpid(), n++);
    // fork();
    // printf("Hello from child [%d - %d]\n", getpid(), n++);
    // printf("Hello from parent [%d - %d]\n", getpid(), n++);
    return 0;
}

/*

 * Explaination:
 * The fork return the pid of the child for the parent and retunr 0 for the child if the instructions is being processed from it.
 * So, we can separate between them and decide which process to be processed from each one.
 * */