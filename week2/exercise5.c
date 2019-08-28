#include<stdio.h>

void star_pyramid_normal(int n){
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
}

void star_pyramid_left(int n){
    for(int h = 1; h <= n; h++){
        for(int w = 0; w < h; w++){
            printf("*");
        }
        printf("\n");
    }
}
void star_pyramid_middle(int n){
    int sign_var = 1;
    int star_num = 1;
    // The condition star_num > 0 for the even n to delete the extra endline
    for(int h = 1; h <= n && star_num > 0; h++){
        for(int w = 0; w < star_num; w++){
            printf("*");
        }
        if(star_num == n/2+(n%2))
            sign_var = -1;
        star_num += sign_var;
        printf("\n");
    }
}
void star_square(int n){
    for(int h = 1; h <= n; h++){
        for(int w = 0; w < n; w++){
            printf("*");
        }
        printf("\n");
    }
}


int main(int args, char **argv){
    int n;
    if(args < 2){
        printf("Please provide the n- parameter\n");
        return 1;
    }
    sscanf(argv[1], "%d", &n);
    star_pyramid_normal(n);
    printf("------------------\n");
    star_pyramid_left(n);
    printf("------------------\n");
    star_pyramid_middle(n);
    printf("------------------\n");
    star_square(n);
    printf("------------------\n");
    
    return 0;
}