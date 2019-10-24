// Sources:
//https://www.geeksforgeeks.org/c-program-list-files-sub-directories-directory/
#include<stdio.h>
#include<dirnet.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int get_inode (int fd)
{
    struct stat buf;
    int ret;

    ret = fstat(fd, &buf);
    if ( ret <0 ) {
         perror ("fstat");
         return -1;
    }

    return buf.st_ino;
}


int main(){

    DIR *dr = opendir("./tmp/"); 
  
    if (dr == NULL)  
    { 
        printf("Could not open current directory" ); 
        return 0; 
    } 
  
    while ((de = readdir(dr)) != NULL){
		int inode = get_inode(de);
        printf("%s\n", de->); 
	}  
    closedir(dr);     	

	return 0;
}
