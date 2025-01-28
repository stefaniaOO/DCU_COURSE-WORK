/*
program: ex1-show-inventory.c
author: stefania omoede ogun
input:
output:
date: 11/12/2024

approach: i created two function, one to create the struct and the other to print out the member
i was indecided if i wanted the discount member of the struct to be an array with two elements, [1, discount] or [0, no discount]
ultimetly i decided to just store the int and then implement a simple if statement in the print funtion
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//struct definition

typedef struct Inventory Inventory;

struct Inventory 
{
	char *Product[50]; //pointer to char array
	int Quantity;
	float Price;
	int Discount;
};


//function prototype
void Make_inventory(Inventory *inv, int size, char* argv[]); //creates array of type inventory
void Print_members(Inventory *inv, int size); //prints members of array


//main driven function
int  main(int argc, char  *argv[])
{
	int size = (argc - 1) / 4; //inilialize size of array 
	Inventory inventory1[100]; //inilialize inventory array
	Inventory *pInventory = inventory1; //inilializing pointer of type inventory to point to the inventory array created
    Make_inventory(pInventory,size,argv); //calling function created to create the array of struct
    Print_members(pInventory, size); //calling function to print array of inventory created
	
	return 0;
}


//function definition

void Make_inventory(Inventory *inv, int size, char* argv[])
{
	int count = 1; //initializing counter to one
	for (int i = 0; i < size; ++i) //loop thorught the whole command line argument
	{
		*(inv)[i].Product = argv[count]; 
		++count; //incrementing count each time 
		inv[i].Quantity = atoi(argv[count]);
		++count;
		inv[i].Price = atof(argv[count]);
		++count;
		inv[i].Discount = atoi(argv[count]);
		++count;
		
	}
}


void Print_members(Inventory *inv, int size)
{
	for (int i = 0; i < size; ++i) //looping throught the array of type inventory
	{
		if(inv[i].Discount == 1) //checking whether member of  inventory at position i is equal to 1
		{
			printf("%s,%d,%.2f,%s\n",  *(inv)[i].Product, inv[i].Quantity, inv[i].Price, "Discounted" ); //if condition is true this is printed
		}
		else //execute this line of code if previous condition is not true
		{
			printf("%s,%d,%.2f,%s\n",  *(inv)[i].Product, inv[i].Quantity, inv[i].Price, "No Discount" ); //this is printed instead
		}
		

		
	}

}