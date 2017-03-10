#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *env[])
{
    int i = 0;
    printf("Вывод аргументов переданных в main\n В массиве argv %d элементов:\n", argc);
    while(i < argc )
    {
        printf("%d, %s\n" , i, argv[i]);
        i++;
    }
	
    i = 0;
    while( env[i] != NULL )
	{
        printf("%d, %s\n" , i, env[i]);
        i++;
    }
    exit(0);
}
