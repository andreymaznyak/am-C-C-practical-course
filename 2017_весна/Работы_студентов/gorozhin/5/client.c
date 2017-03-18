#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
void main(int argc, char** argv) { 
  char* strings1[10];
  
  strings1[0] = strdup("Do you know the warm progress under the stars?");
  strings1[1] = strdup("Do you know we exist?");
  strings1[2] = strdup("Have you forgotten the keys to the kingdom");
  strings1[3] = strdup("Have you been borne yet and are you alive?");
  strings1[4] = strdup("Let's reinvent the gods, all teh myths of the ages");
  strings1[5] = strdup("Celebrate symbols from deep elder forests");
  strings1[6] = strdup("Have you forgotten the lessons of the ancient war?");
  strings1[7] = strdup("We need great golden copulations");
  strings1[8] = strdup("The fathers are cackling in trees of the forest");
  strings1[9] = strdup("Our mother is dead in the sea");

  pid_t pid = fork();
  if (pid == 0){
    execl("./server","", (char*)0);
    exit(0);
  }
  
  int fd = open("fifo", O_RDONLY);

  fd_set rfds;
  struct timeval tv;
  int retval;
  
  FD_ZERO(&rfds);
  FD_SET(fd, &rfds);
  
  tv.tv_sec = 0;
  tv.tv_usec = 1;

  char buff;

  for(;;){
    //    retval = select(fd+1, &rfds, NULL, NULL, &tv);
    //if (retval){
    //if(FD_ISSET(fd, &rfds)){
	int nbytes = read(fd, &buff, sizeof(char));
	if(nbytes){
	  printf("%s\n", strings1[buff]);
	}
	//}
	//}
  }
  wait(NULL);
  exit(0);
}
