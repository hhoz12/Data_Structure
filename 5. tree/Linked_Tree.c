
#include "Linked_Tree.h"


Tree_Node* Make_Tree_Node(element data){
    
    Tree_Node* Parent_Node;
    Parent_Node = (Tree_Node*)malloc(sizeof(Tree_Node));
    Parent_Node->data = data;
    Parent_Node->Left_Node = NULL;
    Parent_Node->Right_Node = NULL;
   
    return Parent_Node;
}

int Insert_Node(Tree_Node* Root_Node, element Input_data, int level){
    Tree_Node* Child_Node;
    int Result = False;

    if(level >3){
        return False;
    }
    
    if(Is_LeftNode_Empty(Root_Node) == True && level <=2){
        printf("Data '%d' is being inserted in %d level Left Node. \n",Input_data,level+1);
        Child_Node = Make_Tree_Node(Input_data);
        Root_Node ->Left_Node = Child_Node;
        
        return True;
    }
    else{
            printf("testing in level %d : shifting to left Node\n",level);
            Result = Insert_Node(Root_Node->Left_Node,Input_data,level+1);

            if(Result == True){
                return Result;
            }
            else if(Root_Node->Right_Node != NULL && level <=1) {
                    printf("testing in level %d : shifting to Right Node\n",level);
                    Result = Insert_Node(Root_Node->Right_Node,Input_data, level+1);
            }
            else if(Root_Node->Right_Node == NULL && level >=1 && level<3)
            {
                printf("Data '%d' is being inserted in %d level Right Node.\n",Input_data,level+1);
                Child_Node = Make_Tree_Node(Input_data);
                Root_Node->Right_Node = Child_Node;
                return True;
            }
            else{
                    if(level == 0){
                        if (Root_Node->Right_Node == NULL)
                        {
                            printf("Data '%d' is being inserted in %d level Right Node.\n", Input_data, level + 1);
                            Child_Node = Make_Tree_Node(Input_data);
                            Root_Node->Right_Node = Child_Node;
                            return True;

                        }
                        else {
                            printf("testing in level %d : shifting to Right Node\n", level);
                            Result = Insert_Node(Root_Node->Right_Node, Input_data, level + 1);
                        }
                    }
                return False;

            }

    }


    return Result;     


}

Tree_Node* Search_Node(Tree_Node* Node, element data){

    static int level_search = 0;
    Tree_Node* Result_Node = NULL;
    printf("level %d \n",level_search);

    if(Node->data == data)
    {
        printf("Find completed : level %d \n",level_search);
        Result_Node = Node;
        level_search = 0;
        return Result_Node;
    }
    else if(Is_LeftNode_Empty(Node) != True && Node->Left_Node->data == data)
    {
        Result_Node = Node->Left_Node;
        level_search = 0;
        return Result_Node;
    }
    else if(Is_RightNode_Empty(Node) != True &&Node->Right_Node->data == data){
        
        Result_Node = Node->Right_Node;
        level_search = 0;
        return Result_Node;
    }
    else {
        if(Is_LeftNode_Empty(Node) != True && level_search <=3){
            level_search ++;
            Result_Node = Search_Node(Node->Left_Node, data);
        }
        else if(Is_RightNode_Empty(Node) != True && level_search <=3){
            level_search ++;
            Result_Node = Search_Node(Node->Right_Node, data);
        }
        
    }

    return Result_Node;
}

int Is_LeftNode_Empty(Tree_Node* Node){

    if(Node->Left_Node == NULL ){
        printf("Left Node is empty! \n");
        return True;
    }
    else return False;
}

int Is_RightNode_Empty(Tree_Node* Node){

    if(Node->Right_Node == NULL ){
        printf("Right Node is empty! \n");
        return True;
    }
    else return False;
}


void Print_Tree(Tree_Node* Node){

    static int level_print = 0;
    
        if(Node == NULL)
            return;
        printf("%d --> ",Node->data);
        level_print++;
        Print_Tree(Node->Left_Node);
        Print_Tree(Node->Right_Node);
        level_print--;
        if(level_print == 0)
        printf("end \n");
        
}

void main_routine(){

    element Input_data, Delete_data;
    Tree_Node* Root_Node, *Search_ptr;
    int Result;
    Root_Node = Make_Tree_Node(0);
    printf("\n/*********************************/ \n");
    printf("This is a Complete Binary Tree Simulation Program. (Function : Insert(Preorder Traversal), Print, Search) \n");
    printf("Date : 2023.09.19 Version : 1.0 \n");
    printf("Author : Kevin Kwon \n");
    printf("/*********************************/ \n");



    while (1)
    {
    
        printf("****************************************\n");
        printf("Select Mode to run \n");
        printf("1. Insert element \n");
        printf("2. Search element \n");
        printf("3. Delete element(TBD)\n");
        printf("4. Print Tree \n");
        printf("5. Exit Program\n");
        printf("****************************************\n");
        scanf_s("%d", &Input_data,sizeof(int));
    
    
        switch (Input_data)
        {
        case Insert:
            printf("please enter data to insert\n");
            scanf_s("%d",&Input_data,sizeof(int));
            Result = Insert_Node(Root_Node, Input_data,0);
            if (Result == False)
                printf("Error : Node wasn't inserted (Tree is Full)\n");
            break;
        case Search:
            printf("please enter data to search\n");
            scanf_s("%d",&Input_data, sizeof(int));
            Search_ptr = Search_Node(Root_Node, Input_data);
            
            if(Search_ptr == NULL)
               printf("Can't find data %d\n",Input_data);
            else 
                printf("Data search is completed (%d)\n", Search_ptr->data);
            break;
        case Print:
            Print_Tree(Root_Node);
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