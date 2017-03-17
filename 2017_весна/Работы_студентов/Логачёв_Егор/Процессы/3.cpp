#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[], char* env[]) {

	if(execvp("./lab2", argv) < 0){
	
     printf("Can't run lab2 \n");	    
	    
   }
	exit(-1);
}
