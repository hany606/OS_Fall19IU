
#include<stdio.h>
#include<stdlib.h>

typedef struct Page
{
    unsigned int id;
    unsigned int counter;
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


    // As the file is fixed and I know the number of words from word editior
    // https://www.charactercountonline.com/
    // or it can be implemented for dynamic size with while(EOF != fscanf(...))

    int hit_counter = 0;
    int miss_counter = 0;
    for(int x = 0; x < 1000; x++){
        int needed_page;
        fscanf(input, "%d ", &needed_page);
        int tmp_page_index = -1;

        for(int i = 0; i < page_frame_num; i++){
            if(page_frame_arr[i].id == needed_page){
                tmp_page_index = i;
                hit_counter++;
                break;
            }      
        }
        if(tmp_page_index == -1){
            miss_counter++;
        
            int least_page_counter_index = page_frame_arr[0].counter;
            for(int i = 1; i < page_frame_num; i++){
                if(page_frame_arr[least_page_counter_index].counter > page_frame_arr[i].counter)
                    least_page_counter_index = i;
            }

            page_frame_arr[least_page_counter_index].id = needed_page;
            // page_frame_arr[least_page_counter_index].counter = 1;

        }

        for (int i = 0; i < page_frame_num; i++)
        {
            page_frame_arr[i].counter >>= 1;
            
            if(page_frame_arr[i].id == needed_page)
                page_frame_arr[i].counter |= 1<< ((sizeof(unsigned int)*8));
        }

    }

    printf("Hit:%d\n",hit_counter);
    printf("Miss:%d\n",miss_counter);
    printf("Hit/miss:%f\n",(float)hit_counter/miss_counter);
    


    // For debugging to know if we reach the end or not
    // printf("Last page_num: %d\n", page_arr[999]);

    free(page_frame_arr);
    fclose(input);
    return 0;
}