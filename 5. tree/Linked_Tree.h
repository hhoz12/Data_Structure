#include <stdio.h>
#include <stdlib.h>

/***********************************

This section is a Define list.

************************************/
#define Tree_Size 16
#define True 1
#define False 0
#define Insert (int)1
#define Delete (int)3
#define Search (int)2
#define Print (int)4
#define Exit (int)5

typedef int element;



typedef struct _Tree_Node{

    element data;
    struct Tree_Node* Left_Node, *Right_Node;

}Tree_Node;






/***********************************
This section is a Fucntion list.
************************************/

Tree_Node* Make_Tree_Node(element); 
Tree_Node* Find_empty_Node(Tree_Node*);

int Insert_Node(Tree_Node*, element, int );

int Delete_Queue(Queue_init_type*);
int Is_Empty(Tree_Node*);
void Print_Queue(Queue_init_type*);


