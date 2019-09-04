#include<stdio.h>


void buble_sort(int arr[], int n){
    // int n = sizeof(arr)/sizeof(arr[0]);
    // printf("%d\n", n);
    for(int i = 0; i < n; i++){
        for(int x = 0; x < n-1; x++){
            if(arr[x] > arr[x+1]){
                int tmp = arr[x];
                arr[x] = arr[x+1];
                arr[x+1] = tmp;
            }
        }
    }
}

int main(){
    int arr[8] = {9,8,7,6,5,4,3,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    buble_sort(arr, n);
    for(int i = 0 ; i < 8; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}