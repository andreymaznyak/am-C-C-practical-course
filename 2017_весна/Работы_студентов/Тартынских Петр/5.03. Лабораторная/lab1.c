#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    pid_t pid;
    pid = fork();
    int i;
    if (pid == -1) 
	{ 
		printf("Fork failed!\n");
        exit(-1);
    } else if (pid == 0) 
	{
		printf("Child process working\n");
    	printf("I'm child id:%d; My father's id:%d\n", getpid(), getppid());
        printf(" __$$$$___$$$$_$$$$__$$$$$$$$____\n___$$_____$$___$$___$$______$___\n___$$_____$$___$$___$$______$___\n___$$_____$$___$$___$$$$$$$$____\n___$$_____$$___$$___$$__________\n____$$___$$____$$___$$__________\n_____$$$$$____$$$$_$$$$_________");
    } else 
		{ 
			printf("Parent process working\n");
           printf("I'm father id:%d; My child's id:%d\n" , getpid(),pid);
           for (i = 0; i < 100; i++)
              printf("I'm counting:",i);
        }
	exit(0);
}
