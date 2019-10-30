#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(){

    int fd = open("hello.txt", O_RDWR);

    if (fd<0) {
        perror("hello.txt open"); 
        exit(1);
    }

    return 0;
}
