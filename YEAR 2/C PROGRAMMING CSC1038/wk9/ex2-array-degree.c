/*
program: lab10-integer-singly-linked-list.c
author: 
input: command line argument array of int
output: formatted input
date: 14/12/2024

approach:
*/

#include<stdlib.h>
#include<stdio.h>

typedef struct Number Number;

struct Number
{
    int data;
    struct Number* next;
};

//functon prototpye
void Memory_allocation(Number **num);
void Create_linked_list(Number *Head, char* argv[], int argc);
void Print_list(Number *Head);

//main driven function
int main(int argc, char *argv[])
{
    Number *Head = NULL;
    Head = (Number*)malloc(sizeof(Number));

    if(Head == NULL)
    {
        return 1;
    }

    Head -> data = atoi(argv[2]);
    Head -> next = NULL;

    //Memory_allocation(&Head);
    Create_linked_list(Head, argv, argc);
    Print_list(Head);


    
    return 0;
}


//function definition

void Memory_allocation(Number **num)
{
    *num = (Number*)malloc(sizeof(Number));
    if (!(*num))
    {
        puts("not able to allocate memory!");
        exit(0);
    }

}


void Create_linked_list(Number *Head, char* argv[], int argc)
{
    Number *current = Head;

    while(current -> next != NULL)
    {
        current = current -> next;
    }


    int i = 3;
    while( i < argc - 4)
    {
        current -> next =(Number*)malloc(sizeof(Number));
        current -> next -> data = atoi(argv[i]);
        current -> next -> next = NULL;
        ++i;
        current = current -> next; //this was correct


    }



}

void Print_list(Number *Head)
{
    Number* current = Head;
    while(current != NULL)
    {
        printf("%d\n", current->data); //we only have int in this case
        current = current->next;
    }


}
