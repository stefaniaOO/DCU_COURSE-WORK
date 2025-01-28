/*
program: lab11-load-binary.c
author: stefania omoede ogun
input: text file
output: formatted data in text file
date: 26/12/2024
*/


#include<stdio.h>
#include<stdlib.h>


//struct definition
typedef struct Student Student; 

/*
creating a an aliias Student for struct student so when you are creating a new instance of the strcut
student you just need to write:
Student s;
and not 
struct Student s;
*/

struct Student //making a struct student 
{
	char Name[50];
	char College[50];
	int Age;
	float Grade;
};

//function prototype
void Struct_from_file(Student *s, FILE* pfile); 
/*
this function takes two input a pointer to the struct student and a pointer to a file pfile
student is a type just like int or char, same goes for file
(possible mistake:
writing void Struct_from_file(Student s, FILE* file); instead of
void Struct_from_file(Student *s, FILE* pfile); 
when passing s you are passing a copy of struct student, any modificatoin will not affect the s structure in the main
you need to point to the struct so the changes remain
)
*/
void Print_struct(Student s); //function that takes in structure and prints its elements


//main driver function
int main(int argc, char const *argv[]) 
{
	Student s1; //initialise instance of student structure 
	FILE *pfile = NULL; //initialise the file pointer to NULL (FILE) is a type just like int or char
	char *filename = "studentBinary.bin"; //initialise pointer filename to point to the bin file studentbinary.bin
	pfile = fopen(filename, "rb"); //assign the pointer pfile to read the bin file filename

	if(!pfile) //handling error
	{
		printf("Error opening %s for reading.\n", filename); //display this message if there was an error while trying to read the file
		exit(1);
	}


	Struct_from_file(&s1, pfile); //calling the function s1 is the struct instance, pfile is a pointer to filename of type FILE
	/*this function assign the data of in the bin file to the values of the struct */

	fclose(pfile); //we close the file after we have done what we need to do
	pfile = NULL;

	Print_struct(s1); //calling function that print our modified struct


	return 0;
}


//function definition
void Struct_from_file(Student *s, FILE* file) 
{
	int lname, lcollege; //creating 2 variable called lname and lcollege;

	/*fread() takes in 4 parameters:
	unsigned int fread(void * pdata, unsigned int size, unsigned int nitems, FILE * pfile); (put & before this if it is not a char)
	pdata = where you want to paste the array into basically
	size = number of bytes per item, so if you have "era", its an array of char and each char is 8 bytes so it would be 8
	nitems = number of items you want to read, if u want to read one word you put 1 ecc
	pfile = pointer of file you want to read from

	fread() starts from the beginning of the file
	*/





	fread(&lname, sizeof(int), 1, file); //you are reading the first 4 bytes of the file and saving it into lname
	fread(s->Name, sizeof(char), lname, file); //you are reading the next 8 bytes of the file and saving it into the struct member s.name of the student struct s
	s->Name[lname] = '\0'; //you are adding a null charachter at the end of the member s.name as fread() does not handle buffers well
	fread(&lcollege, sizeof(int), 1, file); //you are reading the next 4 bytes
	fread(s->College, sizeof(char), lcollege, file); //you are reading the next 8 bytes
	s->College[lcollege] = '\0';
	fread(&s->Age, sizeof(int), 1, file); //you are reading the next 4 bytes
	fread(&s->Grade, sizeof(float), 1, file); //you are reading the next 4 bytes

	//the file might still have some bytes that could be read idk but we are stopping here
	//if you were to continue it would read the next nth byte.
	//to read from the beginning again you would have to call the function again
}

void Print_struct(Student s) //printing members of struct s formatted
{
	printf("Name: %s\n", s.Name);
	printf("College: %s\n", s.College);
	printf("Age: %d\n", s.Age);
	printf("Grade: %.2f\n", s.Grade);

}