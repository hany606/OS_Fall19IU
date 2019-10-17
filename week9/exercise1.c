#include<stdio.h>
#include<stdlib.h>


int main(int args, char** argv){

    const int page_frame_num = atoi(argv[1]);
    int page_frame_arr[page_frame_num];
    for(int i = 0 ; i < page_frame_num; i++){
        page_frame_arr[i] = -1;
    }

    FILE *fp = fopen("Lab 09 input.txt", "r");
    int page_arr[1000];

    // As the file is fixed and I know the number of words from word editior
    // https://www.charactercountonline.com/
    // or it can be implemented for dynamic size with while(EOF != fscanf(...))
    for(int i = 0; i < 1000; i++){
        fscanf(fp, "%d ", &page_arr[i]);
    }


    // For debugging to know if we reach the end or not
    // printf("Last page_num: %d\n", page_arr[999]);

    int page_fault_counter = 0;
    for(int x = 0; x < 1000; x++){
        page_fault_counter++;
        for(int i = 0; i < page_frame_num; i++){
            if(page_frame_arr[i] == page_arr)
                page_fault_counter--;
        }


    }


    fclose(fp);
    return 0;
}