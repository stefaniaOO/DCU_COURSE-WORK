/*
program: ex1-inventory-value.c
authour: stefania omoede ogun
input:
output:
date: 11/12/2024

approach: used the calculation provided in the lab sheet to calculated how much discount to apply
used an if statement to dicide which product would be getting the discount
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
float Total_price(Inventory *inv, int size); //return total price of products in the inventory as a float


//main driven function
int  main(int argc, char  *argv[])
{
	int size = (argc - 1) / 4; //inilialize size of array 
	Inventory inventory1[100]; //inilialize inventory array
	Inventory *pInventory = inventory1; //inilializing pointer of type inventory to point to the inventory array created
    Make_inventory(pInventory,size,argv); //calling function created to create the array of struct
	printf("%.2f\n",Total_price(pInventory,size)); //calling and printing function created to calculate price of all item in the inventory
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
float Total_price(Inventory *inv, int size)
{
	float Total_price = 0; //initializing total price to zero
	for (int i = 0; i < size; ++i) //looping across the entire array
	{
		if(inv[i].Discount == 1) //checking wether the item should be discounted or not
		{
			Total_price += (inv[i].Quantity * (inv[i].Price) * 0.9); //calculating how much the discount is and adding it to total price
		}
		else //if item is not to be discounted, this is executed
		{
			Total_price += (inv[i].Quantity * (inv[i].Price)); //summing product of price * quantity;

		}


	}
	return Total_price; //returning price.
}