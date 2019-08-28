#include<stdio.h>
#include<string.h>

int main(){
    char *in;
    scanf("%s",in);
    for(int i = strlen(in)-1; i >= 0; i--){
        printf("%c", in[i]);
    }
    return 0;
}