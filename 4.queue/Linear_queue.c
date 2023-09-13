
#include "Linear_queue.h"


Queue_type* Create_New_Queue(void){
    Queue_type* Queue_init;
    Queue_init = (Queue_type*)malloc(sizeof(Queue_type));
    Queue_init ->front = -1;
    Queue_init -> tail = -1;

    return Queue_init;
}

void Insert_Queue(Queue_type* Queue, data Input_data){
    if(Is_Full(Queue) == True){
        printf("Error : Queue is already full! \n");
        return;
    }
    else if(Is_Empty(Queue) == True){
        Queue->front ++;
        Queue->tail ++;
        Queue -> Queue_array[Queue->tail] = Input_data;

    }
    else 
    {
        Queue->tail ++;
        Queue -> Queue_array[Queue->tail % Queue_Size] = Input_data;
    }

}

int Delete_Queue(Queue_type* Queue){

    element Data_ret;

    if(Is_Empty(Queue) == True){
        printf("Error : Queue is empty\n");
        return -1;
    }
    else {

        if(Queue->front == Queue->tail){
        Data_ret = Queue->Queue_array[Queue->front];
        Queue->front = -1;
        Queue->tail = -1;
        printf("Warning : Queue is empty now\n");
        return Data_ret;
        }
        Data_ret = Queue->Queue_array[Queue->front];
        Queue->front ++;
        
        return Data_ret;
    }
}

int Is_Full(Queue_type* Queue){
    if((Queue ->tail +1) % Queue_Size == Queue-> front % Queue_Size ){
        printf("Queue is Full! \n");
        return True;
    }
    else return False;
}

int Is_Empty(Queue_type* Queue){
    if(Queue->tail == Queue->front && Queue->front == -1 && Queue->tail == -1){
        printf("Queue is empty! \n");
        return True;
    }
    else return False;
}

void Print_Queue(Queue_type Queue){
    int arr_idx=1;

    for(int i = Queue.front; i <= Queue.tail ;i++){
        printf("%d's element : %d \n",arr_idx , Queue.Queue_array[i % Queue_Size]);
        arr_idx++;
    }
}

void main_routine(){

    element Input_data,Delete_data;
    Queue_type* Queue;
    Queue = Create_New_Queue();
printf("\n/*********************************/ \n");
printf("This is a Circular Queue List Program made by array (Function : Insert, Delete, Print) \n");
printf("Date : 2023.09.10 Version : 1.0 \n");
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
        Print_Queue(*Queue);
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