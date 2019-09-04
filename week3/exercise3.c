#include<stdio.h>
#include<stdlib.h>


typedef struct
{
    struct linked_list_node *next;
    int val;
}linked_list_node;


void print_list(linked_list_node *start){

    linked_list_node *iter = start->next;
    while(iter != NULL){
        printf("%d -> ",iter->val);
        iter = iter->next;
    }
    printf("\n");
}

void insert_node(linked_list_node *start, int val){
    //Linked List is empty
    // printf("%p\n", start);
    if(start == NULL){
        printf("The Linked List is empty, it has zero elements and no head\
                Please at least create an initial node in the linked list\n");
    }
    linked_list_node *node = (linked_list_node*) malloc(sizeof(linked_list_node));
    node->val = val;
    node->next = NULL;
    linked_list_node *iter = start;
    while(iter->next != NULL){
        // printf("%d ---",iter->val);
        iter = iter->next;
    }
    
    printf("\n");
    iter->next = node;
}

void delete_node(linked_list_node *start, int val){
    //Linked List is empty
    // print("%p\n", start);
    if(start == NULL){
        printf("The Linked List is empty, it has zero elements and no head\
                Please at least create an initial node in the linked list\n");
    }

    linked_list_node *iter = start;
    linked_list_node *prev_iter = start;
    linked_list_node *next_iter = start;
    int counter = 0;

    while (iter != NULL)
    {
        next_iter = next_iter->next;
        if(iter->val == val){
            iter->next = NULL;
            prev_iter->next = next_iter;
            // printf("FIND IT\n");
        }
        if(counter++ >= 1)
            prev_iter = prev_iter->next;
        iter = iter->next;
    }
    

    // do{        

    //     if(iter->val == val){
    //         iter->next = NULL;
    //         prev_iter->next = next_iter;
    //     }
    //     if(counter >= 1)
    //         prev_iter = iter->next;
    //     counter++;
    //     iter = iter->next;
    //     //The second expression in the loop is used to just iterate the next_iter var
    //     // Only if the next_iter is not null as C is lazy evaluator so, if the first condition is not 
    //     // true it will not do the second one so, there will be no derefrencing for null values.
    // }while(iter->next != NULL && (next_iter = next_iter->next)->val != NULL);
    // if(iter->val == val)
    //     prev_iter = NULL;
    
}

int main(){
    linked_list_node *initial_node = (linked_list_node*) malloc(sizeof(linked_list_node));
    // printf("%p\n", initial_node->next);
    insert_node(initial_node, 1);
    print_list(initial_node);
    delete_node(initial_node, 1);
    print_list(initial_node);
    insert_node(initial_node, 2);
    insert_node(initial_node, 3);
    printf("INSERTED ALL\n");
    print_list(initial_node);
    delete_node(initial_node, 2);
    print_list(initial_node);

    return 0;
}