#include<stdio.h>
#include<sys/types.h>

int main()
{

    int n;
    // n = 3;
    n = 5;
    for(int i = 0; i < n; i++){
        fork();
        sleep(5);
    }
    return 0;
}

/**
 *  Explaination:
 *      - pstree prints out the process tree for the all processes
 *      - Every time there is a new process is forked from the parent
 *          and the child that are running in the same time
 *          but the differene in time between each genertion is the 5 seconds.
 *      - That's happen until the parent finishs and killed then all the childs
 *          are not active as the OS will not allow to have children without parent
 *      - When we increased the number of loops, the number of the children has been
 *          increased to 2^5 = 32 instance including the parent.
 */ 
