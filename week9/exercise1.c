#include<stdio.h>
#include<stdlib.h>


int main(){

    FILE *fp = fopen("Lab 09 input.txt", "r");
    int page_list[1000];

    // As the file is fixed and I know the number of words from word editior
    // https://www.charactercountonline.com/
    // or it can be implemented for dynamic size with while(EOF != fscanf(...))
    for(int i = 0; i < 1000; i++){
        fscanf(fp, "%d ", &page_list[i]);
    }


    // For debugging to know if we reach the end or not
    printf("Last page_num: %d\n", page_list[999]);




    fclose(fp);
    return 0;
}