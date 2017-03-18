#include <stdio.h>
#include <stdlib.h>

#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>
int main(){
  key_t textlenkey = 7654;
  key_t textkey = 7655;
  key_t resultkey = 7656;

  long int* textlen;
  char* text;
  char* result;

  int textlenid;
  int textid;
  int resultid;

  // textlen
  if ((textlenid = shmget(textlenkey,
			  sizeof(long int),
			  0666)) < 0){
    printf("error 1\n");
    exit(0);
  }
  
  if ((char*)(textlen = shmat(textlenid, NULL, 0)) == (char*)-1){
    printf("error 2\n");
    exit(0);
  }
  // textlen /

  // text 
  if ((textid = shmget(textkey,
		      *textlen,
		      IPC_CREAT | 0666)) < 0){
    printf("error 1\n");
    exit(0);
  }
  
  if ((char*)(text = shmat(textid, NULL, 0)) == (char*)-1){
    printf("error 2\n");
    exit(0);
  }
  // text /

  // result
  if ((resultid = shmget(resultkey,
		      sizeof(char),
		      0666)) < 0){
    printf("error 1\n");
    exit(0);
  }
  
  if ((char*)(result = shmat(textid, NULL, 0)) == (char*)-1){
    printf("error 2\n");
    exit(0);
  }
  // result /
  
  for (long int i = 0; i < *textlen; ++i){
    printf("%c", text[i]);
  }

  *result = 1;

  shmdt(text);
  shmdt(textlen);
  shmdt(result);
}
