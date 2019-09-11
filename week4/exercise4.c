#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>

#define BUFFSIZE 10000
#define MAX_COMMANDS_NUM 10


//As I understand wrongly the exercise in begingin as I thought that
//system is only process the command without any parametrs and I need to pass the paramters
//So, I created this tokenizor to get the parametrs
void simple_tokenizor(char *line, char **commands){
    int space_found_flag = 0;
    int commands_index = 0;
    int string_index = 0;
    for(int i = 0; i < BUFFSIZE && line[i] != '\0'; i++){
        if(line[i] == ' '){
            space_found_flag = 1;
            commands[commands_index][string_index] = '\0';
            string_index = 0;
            continue;
        }
        if(line[i] != ' ' && space_found_flag == 1){
            space_found_flag = 0;
            commands[++commands_index][string_index++] = line[i];
        }
        else if(line[i] != ' ' && space_found_flag == 0){
            commands[commands_index][string_index++] = line[i];
        }
    }
    // printf("--------------\n");
    // printf("%s %s\n", commands[0], commands[1]);
}

int main(){
    char line[BUFFSIZE];
    char commands[MAX_COMMANDS_NUM][BUFFSIZE];
    // char **commands = (char**) calloc(MAX_COMMANDS_NUM, BUFFSIZE*sizeof(char*));
    // scanf("%s",line);
    fgets(line,BUFFSIZE, stdin);
    
    
    //to run the process in the background as a child from the parent program
    //or we can add & in the parameters with execve and will work too.
    if(fork() == 0){
        system(line);
        exit(0);
    }
    //2nd method
    // int char_num = 0;
    // for(int i = 0; i < BUFFSIZE && line[i] != '\0'; i++)
    //     char_num++;
    // line[char_num++] = ' ';
    // line[char_num++] = '&';
    // line[char_num] = '\0';
    // system(line);

    return 0;
}