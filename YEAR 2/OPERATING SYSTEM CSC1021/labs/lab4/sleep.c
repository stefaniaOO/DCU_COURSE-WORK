
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//function definition
void sleep_f(int seconds);
void handle_sigint(int sig);

int main(int argc, char *argv[])
{
	signal(SIGINT, handle_sigint);
	int seconds = 5;
	int amount = atoi(argv[1]);
	for(int i = 0; i < amount; ++i)
	{
		sleep_f(seconds);


	}
	return 0;
}

//function definition

void sleep_f(int seconds)
{
	signal(SIGINT, handle_sigint);
	int remaining = sleep(seconds);
	pid_t id = getpid();
	printf("current running process is: %d\n", id );
	printf("remaining time %d\n", remaining);
	
}

void handle_sigint(int sig)  { 
    printf(" signal number: %d\t\n", sig); 
} 







/*

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//function definition
void handle_sigint(int sig);

int main(int argc, char *argv[])
{
	signal(SIGINT, handle_sigint);
	int seconds = 5;
	int amount = atoi(argv[1]);


	
	for(int i = 0; i < amount; ++i)
	{
		int remaining = sleep(seconds);
		pid_t id = getpid();
	    printf("current running process is: %d\n", id );
	    printf("remaining time %d\n", remaining);


	}

	

}
void handle_sigint(int sig)  { 
    printf(" signal number: %d,\t\n", sig); 
}

*/