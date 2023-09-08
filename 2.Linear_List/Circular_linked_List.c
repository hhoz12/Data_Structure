
#include <stdio.h>
#include <stdlib.h>


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

    linked_list* temp, *temp_for_rep, *first_node_ptr;

    temp_for_rep = head;
    temp = (linked_list*)malloc(sizeof(linked_list));
    temp->data = data;
    first_node_ptr = head->node;

  

    if(head == NULL)
    {
        printf("Error : Head is not existed!");
        return;
    }
    else if(head->node == NULL)
    {
        printf("Inserting first node \n");
        head->node = temp;
        temp->node = temp;
    }
    else if(target_node == NULL)
    {
        printf("Inserting new node at last node\n");
        do{
            temp_for_rep = temp_for_rep->node;
        }while(temp_for_rep ->node != first_node_ptr);

        temp->node = first_node_ptr;
        temp_for_rep->node = temp;
    }

    else if(target_node == head->node){ //첫번째 노드에 삽입하는 경우

        do{ //마지막 노드까지 이동
        temp_for_rep = temp_for_rep->node;
    }while(temp_for_rep->node != first_node_ptr);
    
      printf("Find last node completed\n");
    
    temp_for_rep->node = temp;
    temp->node = first_node_ptr;
    head->node = temp;

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

    linked_list* temp, *first_node;
    int i=1;
    temp = Head->node;
    first_node = Head->node;
    

        do
        {
            if(temp->data == target_data)
            {
                printf("Node that include data : '%d' is %d'th node\n", target_data,i);
                return temp;
            }
            else 
            temp = temp->node ;
            i++;
        }while(temp != first_node);

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

    int i=1;
    linked_list* temp_node_head;
    temp_node_head = head_node->node;
    head_node = head_node->node;

    
    do{
        printf("%d's Node Data ===> %d  \n", i, head_node->data);
        head_node = head_node->node;
        i++;

    }
    while(head_node!= temp_node_head);

}

linked_list* Find_Node_For_Delete(linked_list* head_node, int target_data)
{
    linked_list* temp;
    int i=1;
    temp = head_node->node;
    
    

        do
        {
            if(temp->node->data == target_data)
            {
                printf("Node that include data : '%d' is %d'th node\n", target_data,i+1);
                return temp;
            }
            temp = temp->node ;
            i++;
        }while(temp != head_node->node);

        printf("Error : Can't find Node data!\n");
        return NULL;

}

void Delete_Node(linked_list* head_node, int target_data){

    linked_list* temp_node, *delete_node;
    
    
    temp_node = Find_Node_For_Delete(head_node, target_data); //output : behind target node ex) 1, 2, 3  if target node '2' -> output 1

    if(temp_node == NULL){
        printf("Err : Can't find target node!");
        return;
    }
    else if(temp_node->node->node == head_node->node){ //last node
        delete_node = temp_node->node ;
        printf("test : %d\n",head_node->node->data);
        temp_node-> node = head_node->node;
        free(delete_node);
    
    }
    else if(temp_node->node == head_node->node) {// First node
        delete_node = temp_node->node ;
        head_node->node = temp_node->node->node;
        temp_node->node = head_node->node;
        
        free(delete_node);

    }
    else {
        delete_node = temp_node->node ;
        temp_node -> node = temp_node->node->node;
        free(delete_node);
        
    }

    // temp_node->node= temp_node_for_rep->node;
    printf("Node deleted successfully! \n");
    return;


}

void Main_Routine(void){
    linked_list List_A, *List_head;
    int data, target_data, Input_data, target_delete_data;
    char answer;
    linked_list* temp;
    List_head = Create_NewNode();
    printf("\n/*********************************/ \n");
    printf("This is a Circular Linked List Program (Function : Insert, Delete, Print) \n");
    printf("Date : 2023.08.29 Version : 1.0 \n");
    printf("Author : Kevin Kwon \n");
    printf("/*********************************/ \n");


    while(1)
    {

        printf("****************************************\n");
        printf("Select Mode to run \n");
        printf("1. Insert Node(series) \n");
        printf("2. Insert Node(specific section) \n");
        printf("3. Search Node \n");
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
        
        if(temp == NULL) continue;
        Insert_Node(List_head,data,temp);
        printf("Node insert complete\n");
        
        break;

        case 3:
        printf("please enter node's data you want to delete\n");
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