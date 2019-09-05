//Not implemented yet - Quicksort (Optional Exercise)
#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int *arr, int lo, int hi){
    
    int pivot = arr[lo+(hi-lo)/2];
    while(1){
        while(arr[lo] < pivot)
            lo++;
        
        while(arr[hi] > pivot)
            hi--;
        if(lo >= hi)
            return hi;
        swap(arr,lo,hi);

        lo++;
        hi--;
    }
}

void quick_sort(int *arr, int lo, int hi){
    if(lo < hi){
        int p = partition(arr, lo, hi);
        quick_sort(arr, lo, p-1);
        quick_sort(arr, p+1, hi);
    }
}



int main(){

    int arr[8] = {7,6,5,4,3,2,1,0};
    quick_sort(arr,0,7);
    for(int i = 0 ; i < 8; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

}