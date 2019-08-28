#include<stdio.h>

void swap(int *n1, int *n2){
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

int main(){
    int n1, n2;
    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("\n");
    printf("Enter second number: ");
    scanf("%d", &n2);
    printf("\n");
    swap(&n1, &n2);
    printf("First number: %d, Second number: %d\n", n1, n2);
    return 0;
}