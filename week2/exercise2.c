#include<stdio.h>
#include<string.h>

int main(){
    char *in;
    printf("Please enter a string:");
    scanf("%s",in);
    printf("Reversed String: ");
    for(int i = strlen(in)-1; i >= 0; i--){
        printf("%c", in[i]);
    }
    printf("\n");
    return 0;
}