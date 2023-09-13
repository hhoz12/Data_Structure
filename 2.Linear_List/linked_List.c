
#include <stdio.h>

typedef struct linked_list{

    int data;
    struct linked_list *node;

}linked_list;



linked_list* Create_NewNode()
{
    linked_list *temp, *List_head;
    temp = (linked_list*)malloc(sizeof(linked_list));

    List_head = temp;
    List_head ->node = NULL;
    return List_head;

}
/*****************************************************/
// 함수명 : Insert_Node
// 노드에 따라서 link에 노드 포인터를 삽입하는 함수 
// input : Head 노드, 데이터 . output : 없음
//
/*****************************************************/

void Insert_Node(linked_list *head, int data, linked_list *target_node){

    linked_list* temp, *temp_for_rep;

    temp_for_rep = head;
    temp = (linked_list*)malloc(sizeof(linked_list));
    temp->data = data;


    if(head == NULL)
    {
        printf("Error : Head is not existed!");
        return;
    }
    else if(head->node == NULL)
    {
        printf("Inserting first node \n");
        head->node = temp;
        temp->node = NULL;
    }
    else if(target_node == NULL)
    {
        printf("Inserting node \n");
        while(temp_for_rep ->node != NULL){
            temp_for_rep = temp_for_rep->node;
        }
        temp_for_rep->node = temp;
        temp->node = NULL;
    }
    
    else{

        while(temp_for_rep != target_node){
            temp_for_rep = temp_for_rep->node;

            if(temp_for_rep == NULL ){
            printf("Error : The target node that includes %d doesn't exist!", target_node->data);
            return;
            }       
        }
        temp->node = temp_for_rep->node;
        temp_for_rep ->node = temp;
               
        }
    }
    

/*****************************************************/
// 함수명 : Find_Node
// 특정 데이터를 포함하는 노드의 포인터를 리턴하는 함수
// input : Head 노드, 데이터 . output : 포인터
//
/*****************************************************/

linked_list* Find_Node(linked_list* Head, int target_data){

    linked_list* temp;
    int i=0;
    temp = Head;

            while(temp != NULL)
        {
            if(temp->data == target_data)
            {
                printf("Node that include data : '%d' is %d'th node\n", target_data,i);
                return temp;
            }
            else 
            temp = temp->node ;
            i++;
        }

        printf("Error : Can't find Node data!\n");
        return NULL;


}

/*****************************************************/
// 함수명 : Print_All_Node
// 연결 리스트 내 포함되는 모든 노드의 데이터 출력
// input : Head 노드  output : 
//
/*****************************************************/
void Print_All_Node(linked_list* head_node){

    int i=0;
    while(head_node!= NULL){

        if(i==0){
        head_node = head_node->node;
        i++;
        }

        printf("%d's Node Data ===> %d  \n", i, head_node->data);


        head_node = head_node->node;
        i++;

    }

}

void Delete_Node(linked_list* head_node, int target_data){

    linked_list* temp_node;

    
    while(head_node->data != target_data)
    {
        temp_node = head_node;
        head_node = head_node->node;

        if(head_node == NULL)
        {
            printf("Failed to delete node : can't find target_node \n");
            return;
        }  
    }
    temp_node->node= head_node->node;
    free(head_node);
    printf("Node is successfully deleted! \n");
    


}

void Main_Routine(void){
    linked_list List_A, *List_head;
    int data, target_data, Input_data, target_delete_data;
    char answer;
    linked_list* temp;
    List_head = Create_NewNode();
    printf("\n/*********************************/ \n");
    printf("This is a Linked List Program (Function : Insert, Delete, Print) \n");
    printf("Date : 2023.08.20 Version : 1.0 \n");
    printf("Author : Kevin Kwon \n");
    printf("/*********************************/ \n");


    while(1)
    {

        printf("****************************************\n");
        printf("Select Mode to run \n");
        printf("1. Insert Node(series) \n");
        printf("2. Insert Node(specific section) \n");
        printf("3. Find Node \n");
        printf("4. Print Node \n");
        printf("5. Delete Node\n");
        printf("6. Exit Program\n");
        printf("****************************************\n");
        scanf("%d",&Input_data);

        switch(Input_data){
        case 1:
        printf("Please enter data you want to insert\n");
        scanf("%d",&data);
        Insert_Node(List_head,data,NULL);
        printf("Node insert complete\n");
        break;

        case 2:
        printf("Please enter data.\n");
        scanf("%d",&data);
        printf("Please enter Target Node's data. \n");
        scanf("%d",&target_data); //fflush(stdin);
        temp = Find_Node(List_head, target_data);
        
        if(temp == NULL)    continue;
        Insert_Node(List_head,data,temp);
        printf("Node insert complete\n");
        
        break;

        case 3:
        printf("please enter node's data to find\n");
        scanf("%d",&data);
        temp = Find_Node(List_head, data);
        break;


        case 4:
        if(List_head ->node == NULL)
        {printf("Node is empty, please insert node first\n");
        break;}
        printf("The Node is printed in below \n");
        Print_All_Node(List_head);
        break;

        case 5:
        if(List_head ->node == NULL){
            printf("Node is empty, please insert node first\n");
            break;
        }
        printf("please enter data \n");
        scanf(" %d",&target_delete_data);
        Delete_Node(List_head,target_delete_data);
        
        break;

        case 6:
        printf("Program is shut down\n");
        return;
        
        default:
        printf("Wrong Command Please enter again");
        }


    }
}

void main(void)
{
Main_Routine();
    
}