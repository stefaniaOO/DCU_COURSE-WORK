/*
program: lab10-inside-the-queue.c
author: stefania omoede ogun
input:
output:
date: 16/12/2024

approach:
*/

#include <stdlib.h>
#include <stdio.h>

//struct definition
typedef struct NUMBER NUMBER;

struct NUMBER
{
	int num;
	struct NUMBER* next_num;
	struct NUMBER* prev_num;
};

//function prototype
void Create_linked_list(NUMBER** head, int* numlist, int length);
void print_list(NUMBER* head);
void remove_last_num(NUMBER *head);
void Add_to_end(NUMBER *head, int num_to_add);
int Add_after_index(NUMBER *head, int *n, int num_insert); 




//main driven function
int  main(int argc, char  *argv[])
{
	int list_num[] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
	int length = sizeof(list_num)/sizeof(list_num[0]);


	int num1, num2;
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	NUMBER* head = NULL;

	Create_linked_list(&head,list_num, length);
	Add_after_index(head, &num1, num2);

	//remove_last_num(head);
	//remove_last_num(head);
   //Add_to_end(head,num1);
   //Add_to_end(head,num2);
	print_list(head);


	
	return 0;
}





//function definition
void Create_linked_list(NUMBER** head, int* numlist, int length)
{
	*head = (NUMBER*)malloc(sizeof(NUMBER));
	if(*head == NULL)
	{
		exit(0);
	}
	(*head) -> num = numlist[0];
	(*head) -> prev_num = NULL;
	(*head) -> next_num = NULL;

	NUMBER* current = *head;

	int i = 0;
	while(i < length - 1)
	{

		NUMBER* previous = current;
		

		current -> next_num = (NUMBER*)malloc(sizeof(NUMBER));
		current -> next_num -> num = numlist[i + 1];
	
		current -> next_num -> next_num = NULL;
		
		current = current -> next_num;
		current -> prev_num = previous;

		++i;

	}
}




void print_list(NUMBER* head) {
    NUMBER* current = head; //starting from head


    while (current != NULL) //till tail
     {
        printf("%d\n", current->num); //we only have int in this case
        current = current->next_num;
    }
}


void remove_last_num(NUMBER *head)
{

    if (head->next_num == NULL) //we check to see if the head points at nothing
    {
        free(head); //if soo we free the head (meaning no more linked list)
    }

    NUMBER * current = head; //new number variable to points to head
    while (current-> next_num-> next_num != NULL) //loops keeps going as long as the node after the one we are currently in doesnt point to null so lik3
    // 3 -> 4 -> 5 , it keeps going but 3 -> 4 -> NULL, it stops
    { 
        current = current-> next_num; //we go to the next node
    }

    //after this loop we should be in this node: slast -> last -> NULL, we are here slast -> last

    /* now current points to the second to last item of the list, so let's remove current->next */
    free(current->next_num); //we are freeing the number that slast is pointing to which is last , after this current points to nothing
    //current ->
    current->next_num = NULL; //now we make current point to null


}

void Add_to_end(NUMBER *head, int num_to_add)
{
	NUMBER *current = head;

	while(current -> next_num)
	{
		current = current -> next_num;
	}

	current -> next_num = (NUMBER*)malloc(sizeof(NUMBER));
	current -> next_num -> num = num_to_add;
	current -> next_num -> next_num = NULL;
}


int Add_after_index(NUMBER *head, int *n, int num_insert) 
{

	NUMBER* current = head;

	while(current -> num != *n) //this goes on till the data stored in the node is not equal to n
	{
		current = current -> next_num; //moves to the next node
	}


    NUMBER* temp_current = current->next_num; //storing the number inside the node after the current one we are in

    current -> next_num = (NUMBER*)malloc(sizeof(NUMBER)); //our current node now points to something else
    current -> next_num -> num = num_insert; //the new node that our current node now points to stores num_insert
    current -> next_num -> next_num = temp_current; //the new node we created points to the old node that our current used to point to

}