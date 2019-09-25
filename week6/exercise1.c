/**
 * Resource:
 * https://www.tldp.org/LDP/lpg/node11.html
 * https://www.geeksforgeeks.org/c-program-demonstrate-fork-and-pipe/
 *
 * */

/**
 * fd[0] for reading, fd[1] for writing
 * 
 * */
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>


#define MAX_LEN 100

int main(){
    
    char *source_string = "SOURCE";

    char *string1 = (char*) malloc(MAX_LEN*sizeof(char));
    char *string2 = (char*) malloc(MAX_LEN*sizeof(char));
    
    int fd[2];

    strcpy(string1,source_string);

    printf("String1: %s, len: %d\n", string1,strlen(string1));
    printf("String2: %s, len: %d\n", string2,strlen(string2));

    // printf("Debug\n");
    if(pipe(fd) == -1){
        printf("Error in pipe system call\n");
        perror("ERROR  in pipe()");
        return 1;
    }
    // close(fd[0]);

    write(fd[1], string1, strlen(string1)+1);

    // close(fd[1]);
    
    read(fd[0], string2, MAX_LEN);

    printf("String1: %s, len: %d\n", string1,strlen(string1));
    printf("String2: %s, len: %d\n", string2,strlen(string2));

    return 0;
}
