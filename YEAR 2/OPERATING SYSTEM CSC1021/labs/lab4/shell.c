#include <stdio.h>
#include <stdlib.h>


int  main(int argc, char *argv[])
{
	char* command = argv[1];
	if(argc < 2)
	{
		puts("insert command");
	}
	//if(command == "ls")
//	{
		system(command); //The C stdlib library system() function is used to execute an operating system command specified by the string 'command' 
//	}

	
	return 0;
}