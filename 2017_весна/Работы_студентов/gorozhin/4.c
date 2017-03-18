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
  
  int ptoc[2]; // 0 - read;  1 - write
  pipe(ptoc); // parent writes, child listens
  
  int ctop[2]; // 0 - read;  1 - write
  pipe(ctop); // child writes, parent listens

  pid_t pid = fork();
  
  if (pid == 0){
    // child
    close(ptoc[1]);
    close(ctop[0]);

    char buff[80];
    
    int nbytes = 1;
    for(;;){
      fd_set rfds;
      struct timeval tv;
      int retval;

      FD_ZERO(&rfds);
      FD_SET(ptoc[0], &rfds);
      
      tv.tv_sec = 0;
      tv.tv_usec = 1;
      
      printf(": ");
      char* str = fgets(buff, 80, stdin);
      write(ctop[1], str, strlen(str) + 1);

      retval = select(ptoc[0]+1, &rfds, NULL, NULL, &tv);
      if (retval){
	if(FD_ISSET(ptoc[0], &rfds)){
	  nbytes = read(ptoc[0], buff, sizeof(buff));
	  if(nbytes){
	    printf("%s\n", buff);
	  }
	}
      }
    }
    
    
    close(ptoc[0]);
    close(ctop[1]);
    
    exit(0);
  } else {
    // parent
    close(ptoc[0]);
    close(ctop[1]);
    
    char buff[80];

    int nbytes = 1;
    while(nbytes) {
      nbytes = read(ctop[0], buff, sizeof(buff));
      if (nbytes){
	int rnd = rand()%10;
	write(ptoc[1], strings1[rnd], strlen(strings1[rnd]) + 1);
      }
    }
  }

  close(ptoc[1]);
  close(ctop[0]);

  wait(NULL);
  exit(0);
}
