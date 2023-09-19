
#include "Linked_Tree.h"


Tree_Node* Make_Tree_Node(element data){
    
    Tree_Node* Parent_Node;
    Parent_Node = (Tree_Node*)malloc(sizeof(Tree_Node));
    Parent_Node->data = NULL;
    Parent_Node->Left_Node = NULL;
    Parent_Node->Right_Node = NULL;
   
    return Parent_Node;
}

Tree_Node* Find_empty_Node(Tree_Node* Root_Node){

    Tree_Node* temp_node;

    while(Is_Empty(temp_node)!= True){

    }

}

int Insert_Node(Tree_Node* Root_Node, element Input_data, int level){
    Tree_Node* Child_Node;
    int Result = False;
    
    
    
    if(Is_LeftNode_Empty(Root_Node) == True && level <=3){

        Child_Node = Make_Tree_Node(Input_data);
        Root_Node ->Left_Node = Child_Node;
        return True;

    }
    else if(Is_RightNode_Empty(Root_Node) == True && level <=3){
        Child_Node = Make_Tree_Node(Input_data);
        Root_Node ->Right_Node = Child_Node;
        return True;

    }
    else{

        level ++;
        Result = Insert_Node(Root_Node->Left_Node,Input_data, level);
        if(Result == True)
            return Result;
        else 
            Result = Insert_Node(Root_Node->Right_Node, Input_data, level);

        if(Result == True)
            return Result;
        else
            return False;
        }        

}

int Delete_Queue(Tree_Node* Node){

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


int Is_LeftNode_Empty(Tree_Node* Node){

    if(Node->Left_Node == NULL ){
        printf("Node is empty! \n");
        return True;
    }
    else return False;
}

int Is_RightNode_Empty(Tree_Node* Node){

    if(Node->Right_Node == NULL ){
        printf("Node is empty! \n");
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
    Tree_Node* Root_Node;
    Root_Node = Make_Tree_Node(0);
    printf("\n/*********************************/ \n");
    printf("This is a Complete Binary Tree Simulation Program. (Function : Insert(Preorder Traversal), Delete, Print) \n");
    printf("Date : 2023.09.19 Version : 1.0 \n");
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
            Insert_Node(Root_Node, Input_data);
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