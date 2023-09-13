#include <stdio.h>
#include <stdlib.h>

/***********************************

This section is a Define list.

************************************/
#define Queue_Size 5
#define True 1
#define False 0
#define Insert (int)1
#define Delete (int)3
#define Search (int)2
#define Print (int)4
#define Exit (int)5

typedef int element;
typedef int data;

typedef struct _Queue_type{

    element data;
    struct Queue_type* link;

}Queue_type;

typedef struct _Queue_init_type{

    element data;
    Queue_type* front, *tail;

}Queue_init_type;






/***********************************
This section is a Fucntion list.
************************************/

Queue_init_type* Create_New_Queue(void);
void Insert_Queue(Queue_init_type*, data);
int Delete_Queue(Queue_init_type*);
int Is_Empty(Queue_init_type*);
void Print_Queue(Queue_init_type*);


