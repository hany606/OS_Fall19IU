#include<stdio.h>
#include<stdlib.h>


typedef struct
{
    struct linked_list_node *next;
    struct linked_list_node *prev;
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
    node->prev = NULL;
    linked_list_node *iter = start;
    while(iter->next != NULL){
        // printf("%d ---",iter->val);
        iter = iter->next;
    }
    
    printf("\n");
    iter->next = node;
    node->prev = iter;
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
        if(iter->val == val && counter != 0){
            iter->next = NULL;
            prev_iter->next = next_iter;
            // printf("FIND IT\n");
        }
        if(counter++ >= 1)
            prev_iter = prev_iter->next;
        iter = iter->next;
    }
    
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
    printf("INSERTED ALL with deletion\n");
    print_list(initial_node);
    delete_node(initial_node, 2);
    print_list(initial_node);

    return 0;
}