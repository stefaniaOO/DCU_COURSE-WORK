/*
program: lab4-matrix-diagonal-sum.c
author: stefania omoede ogun
input: command line argument, elements of 2d matrix
output: sum of the diagonal components of 2d matrix
date: 18/11/2024
*/

#include <stdlib.h>
#include <stdio.h>

//function prototype
//creates a 2d matrix from the command line argument, to use a 2d matrix as an argument of your function you
//need to put matrix[][amount of rows]
void Create2dMatrix(int n, int m, int matrix[][m], char *argv[]); 
int Sum_of_diagonal_elemnts(int n, int m, int matrix[][m]); //gets sum of diagonal elements

int main(int argc, char  *argv[])
{
	int n = atoi(argv[1]); //n x n matirx
	int matrix[n][n];

	Create2dMatrix(n, n, matrix, argv); //calling the function we created
	printf("%d\n",Sum_of_diagonal_elemnts(n, n, matrix)); //calling the other function we created and printing the int returned 
	
	return 0;
}



//function declaration

void Create2dMatrix(int n, int m, int matrix[][m], char * argv[])
{
	int count = 1; //initializing count to 1
	for (int i = 0; i < n; ++i) //first loop that loop thorug the columns so it will loop n times
	{

		for (int j = 0; j < m; ++j) //second loop that will loop thorugh the rows so it will loop n * m times
		{
			matrix[i][j] = atoi(argv[count + 1]);//adds component of argv[] to the matrix
			++count;
		}
	
		
	}

}


int Sum_of_diagonal_elemnts(int n, int m, int matrix[][m])
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(j == i) //checks if j = 1, because the diagonal elemnts position are always where j and i are the same; [0][0]. [1][1], [2][2] ect
			{
				sum += matrix[i][j];
			}
		}

    }
    	return sum;
 }