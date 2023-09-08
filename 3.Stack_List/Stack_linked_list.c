
#include <stdio.h>
#include <stdlib.h>

typedef int element;

#define push_stack (int) 1
#define search (int) 2
#define delete (int) 3
#define printstack (int) 4
#define change_stack_size (int) 5
#define exit (int) 6



typedef struct Stack_List {

    element data;
    struct Stack_List* link;

}Stack_List;


int Is_Overflow(Stack_List* top, int stack_size) {

    int i = 0;
    Stack_List* temp;
    temp = top->link;
    while (temp != NULL)
    {
        i++;
        temp = temp->link;
    }

    if (i == stack_size)
    {
        printf("Stack is Full! \n");
        return 1;
    }
    printf("Stack is available! \n");
    return 0;

}


Stack_List* Create_New_Stack() {

    Stack_List *top;
    top = (Stack_List*)malloc(sizeof(Stack_List));
    top->link = NULL;
    return top;

}

void Push(Stack_List* top, element data, int stack_size) {

    Stack_List* new_element, * temp;

    new_element = (Stack_List*)malloc(sizeof(Stack_List));
    new_element->data = data;
    if (Is_Overflow(top, stack_size) == 1)
    {
        printf("Can't push element (Stack is already full) \n");
        return;
    }
    else {
        temp = top->link;
        top->link = new_element;
        new_element->link = temp;
        printf("Stack insert completed \n");
    }

}

Stack_List* pop(Stack_List* top) {

    Stack_List* first_element_ptr = top->link;
    

    if(first_element_ptr == NULL)
    {            
        perror("Error : Stack is underflow\n");
        return NULL;
    }
    else
    {   
        top->link = first_element_ptr->link;
        return first_element_ptr;
    }

}

Stack_List* Search_Element(Stack_List* top, element data) {
    
    Stack_List* temp;
    int i=1;
    temp = top ->link;
    while(temp != NULL )
    {
        if(temp->data == data)
        {
            printf("element %d is in %d'th node \n",data, i);
            return temp;
        }
        i++;
        temp = temp->link;

    }

    printf("Can't find element %d \n", data);
    return NULL;


}

void print_stack(Stack_List* top) {

    int i = 1;
    Stack_List* Element;

    Element = top->link;
    while (Element != NULL)
    {
        printf("%d element : %d\n", i, Element->data);
        Element = Element->link;
        i++;
    }


}

void Main_Routine() {

    Stack_List *top, *pop_element;
    top = Create_New_Stack();

    int Input_data;
    static int stack_size = 5, temp;
    element data;

    printf("\n/*********************************/ \n");
    printf("This is a Stack Linked List Program (Function : Insert, Delete, Print) \n");
    printf("Date : 2023.09.06 Version : 1.0 \n");
    printf("Author : Kevin Kwon \n");
    printf("/*********************************/ \n");


    while (1)
    {

        printf("****************************************\n");
        printf("Select Mode to run \n");
        printf("1. Push element \n");
        printf("2. Search element \n");
        printf("3. Pop element\n");
        printf("4. Print Stack \n");
        printf("5. Change Stack_Size(Current_Stack_Size : %d) \n", stack_size);
        printf("6. Exit Program\n");
        printf("****************************************\n");
        scanf("%d", &Input_data);

        switch (Input_data) {
        case push_stack:
            printf("Please enter data you want to insert\n");
            scanf("%d", &data);
            Push(top, data, stack_size);
            printf("Element insert completed\n");
            break;

        case search :
            printf("Please enter data to search.\n");
            scanf("%d", &data);
            Search_Element(top, data);
            break;

        case delete:
            printf("This is pop mode\n");
            pop_element = pop(top);
            if(pop_element == NULL) break;
            data = pop_element->data;
            free(pop_element);
            printf("Operation is successfully completed (pop data : %d)\n", data);
            break;


        case printstack:
            printf("The Node is printed in below \n");
            print_stack(top);
            break;

        case change_stack_size:
            printf("Please enter Stack size to change\n");
            scanf("%d", &temp);
            if(temp >= stack_size)
            stack_size = temp;
            else
            printf("Error ! Please enter stack size bigger than current size \n");
            
            break;

        case exit:
            printf("Program is shut down\n");
            return;

        default:
            printf("Wrong Command Please enter again");
        }


    }

}

int main()
{

    Main_Routine();
}