/* 
program: lab10-float-doubly-linked-list.c
author: stefania omoede ogun
input: command line argument
output: formatted floating point numbers
date: 15/12/2024
approach: my initial though was to just store the command line argument in the linked list in reverse and then print it out
but then i thought that it would be more interesting and benefictial to trully unferstand how double linked list works
if i went up till the tail and then went back till the head and printed the number and the traversed the list backwards

*/

#include <stdlib.h>
#include <stdio.h>

//struct definition
typedef struct FLOATINGPOINT FLOATINGPOINT;

struct FLOATINGPOINT
{
    float number;
    struct FLOATINGPOINT* prev;
    struct FLOATINGPOINT* next;
};

//function prototype

void Memory_allocation(FLOATINGPOINT** head);
void Create_linkedlist(FLOATINGPOINT* head, char *argv[], int argc);
void Print_in_reverse(FLOATINGPOINT* head);


int main(int argc, char  *argv[])
{
    int length = atoi(argv[1]);
    FLOATINGPOINT* head = NULL;
    Memory_allocation(&head);
    head -> number = atof(argv[2]);
    head -> prev = NULL;
    head -> next = NULL;
    Create_linkedlist(head, argv, argc);
    Print_in_reverse(head);


    
    return 0;
}

void Memory_allocation(FLOATINGPOINT** head)
{
    *head = (FLOATINGPOINT*)malloc(sizeof(FLOATINGPOINT));

    if(*head == NULL)
    {
        exit(0);
    }
}

void Create_linkedlist(FLOATINGPOINT* head, char *argv[], int argc)
{
    FLOATINGPOINT* current = head;
    while(current -> next != NULL)
    {
        current = current-> next;
    }

    int i = 3;
    while( i < argc)
    {
        FLOATINGPOINT* previous = current; //store the old value of current 
        //current -> prev = current, its wrong because when i the lines below current gets modfied so will what prev points to, come temp, a and b
       

        current -> next = (FLOATINGPOINT*)malloc(sizeof(FLOATINGPOINT));
        current -> next -> number = atof(argv[i]);
        current -> next -> next = NULL;
        current = current -> next; //current now points to the next 
        current -> prev = previous;
        
        ++i;
    }



}

void Print_in_reverse(FLOATINGPOINT* head)
 {
    FLOATINGPOINT* current = head; //starting from head

    while (current -> next) //till tail
     {
        current = current->next;

     
    }
    

    while(current != NULL)
    {
        printf("%.2f\n", current -> number);
        current = current -> prev;
       
      

    }
}

/* side note
 while (current -> next != NULL) //till tail
     {
        current = current->next;

     
    }
    in the example when this stops you are at the last element of the linked list
    so if you start going back and printing prev, it wont print the last element
    (you could have a print statmeent before the loop tho)
    u can go to the null and then from there print all prevs, like what i did

    */
