//Not implemented yet - Quicksort (Optional Exercise)
#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(int *arr, int lo, int hi){
    int pivot = arr[hi-1];
    int i = lo;
    for(int j = lo; j < hi; j++){
        if(arr[j] < pivot){
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, hi-1);
    return i;
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

}