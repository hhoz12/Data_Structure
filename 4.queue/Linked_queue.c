
#include "Linked_queue.h"


Queue_init_type* Create_New_Queue(void){
    Queue_init_type* Queue_init;
    

    Queue_init = (Queue_init_type*)malloc(sizeof(Queue_init_type));
    Queue_init ->front = NULL;
    Queue_init -> tail = NULL;

    return Queue_init;
}

void Insert_Queue(Queue_init_type* Queue, data Input_data){
    Queue_type* New_Queue;

    if(Is_Empty(Queue) == True){
        New_Queue = (Queue_type*)malloc(sizeof(Queue_type));
        Queue->front = New_Queue;
        Queue->tail = New_Queue;
        New_Queue->link = NULL;
        New_Queue->data = Input_data; 
    }
    else 
    {
        New_Queue = (Queue_type*)malloc(sizeof(Queue_type));
        Queue->tail->link = New_Queue;
        Queue->tail = New_Queue;
        New_Queue->link = NULL;
        New_Queue -> data = Input_data;
    }

}

int Delete_Queue(Queue_init_type* Queue){

    element Data_ret;
    Queue_type *Old_Node;

    if(Is_Empty(Queue) == True){
        printf("Error : Queue is empty\n");
        return -1;
    }
    else {
        if(Queue->front == Queue->tail){ // Last element
            Data_ret = Queue->front->data;
            Queue->front = NULL;
            Queue->tail = NULL;
            printf("Warning : Queue is empty now\n");
            return Data_ret;
        }

        Data_ret = Queue->front->data;
        Old_Node = Queue->front;
        Queue->front = Queue->front->link;
        free(Old_Node);
        
        return Data_ret;
    }
}


int Is_Empty(Queue_init_type* Queue){
    if(Queue->tail == NULL && 
     Queue->front == NULL ){
        printf("Queue is empty! \n");
        return True;
    }
    else return False;
}

void Print_Queue(Queue_init_type* Queue){
    int arr_idx=1;
    Queue_type* temp_queue;
    temp_queue = Queue->front;

    if(Is_Empty(Queue) == True){

        printf("Can't display Queue (Queue is Empty)\n");
        return;
    }

    while(temp_queue != NULL){
        printf("%d's element : %d \n",arr_idx , temp_queue->data);
        arr_idx++;
        temp_queue = temp_queue->link;
    }
    
}

void main_routine(){

    element Input_data,Delete_data;
    Queue_init_type* Queue;
    Queue = Create_New_Queue();
    printf("\n/*********************************/ \n");
    printf("This is a Linked Queue Simulation Program. (Function : Insert, Delete, Print) \n");
    printf("Date : 2023.09.11 Version : 1.0 \n");
    printf("Author : Kevin Kwon \n");
    printf("/*********************************/ \n");



    while (1)
    {
    
        printf("****************************************\n");
        printf("Select Mode to run \n");
        printf("1. Insert element \n");
        printf("2. Search element \n");
        printf("3. Delete element\n");
        printf("4. Print Queue \n");
        printf("5. Exit Program\n");
        printf("****************************************\n");
        scanf("%d", &Input_data);
    
    
        switch (Input_data)
        {
        case Insert:
            printf("please enter data to insert\n");
            scanf("%d",&Input_data);
            Insert_Queue(Queue, Input_data);
            break;
        case Search:
            printf("please enter data to search\n");
            scanf("%d",&Input_data);
            break;
        case Delete:
            Delete_data = Delete_Queue(Queue);
            printf("Element %d is successfully deleted\n",Delete_data);
            break;
        case Print:
            Print_Queue(Queue);
            break;
        case Exit:
            printf("Program will be closing\n");
            return;
            break;
            
        default:
            printf("Wrong Command please enter again\n");
            break;
    
        }
    
    }
}

int main(void)
{
    main_routine();
}