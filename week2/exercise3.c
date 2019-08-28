#include<stdio.h>

int main(int args, char **argv){
    int n;
    if(args < 2){
        printf("Please provide the n- parameter\n");
        return 1;
    }
    sscanf(argv[1], "%d", &n);
    int star_num = 1;
    for(int h = 1; h <= n; h++){
        for(int w = 0; w < ((2*n -1)-(star_num))/2; w++){
            printf(" ");
        }

        for(int w = 0; w < star_num; w++){
            printf("*");
        }

        for(int w = 0; w < ((2*n -1)-(star_num))/2; w++){
            printf(" ");
        }
        printf("\n");
        star_num += 2;

    }
    
    return 0;

}