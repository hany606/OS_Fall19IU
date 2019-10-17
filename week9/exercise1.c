#include<stdio.h>
#include<stdlib.h>

typedef struct Page
{
    unsigned int id;
    unsigned counter;
}Page;



int main(int argc, char** argv){

    // Add condition to check if argv[1] is not exist (argc < 2)
    if(argc < 2)
    {
        printf("Error in reading the command parameter.\nPlease Provide page_frame_num.");
        return 1;
    }
    const int page_frame_num = strtol(argv[1], NULL, 10);
    Page *page_frame_arr = (Page*) calloc(page_frame_num, sizeof(Page));

    FILE *input = fopen("Lab 09 input.txt", "r");
    // Add checker if the file couldn't able to be read
    if(input == NULL){
        printf("Error in reading the file");
        return 1;
    }

    int page_arr[1000];

    // As the file is fixed and I know the number of words from word editior
    // https://www.charactercountonline.com/
    // or it can be implemented for dynamic size with while(EOF != fscanf(...))
    for(int i = 0; i < 1000; i++){
        fscanf(input, "%d ", &page_arr[i]);
    }


    // For debugging to know if we reach the end or not
    // printf("Last page_num: %d\n", page_arr[999]);

    int page_fault_counter = 0;
    for(int x = 0; x < 1000; x++){
        page_fault_counter++;
        for(int i = 0; i < page_frame_num; i++){
            if(page_frame_arr[i].id == page_arr[x])
                page_fault_counter--;
        }

    }

    free(page_frame_arr);
    fclose(input);
    return 0;
}