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

  FILE* f = fopen("waiter.c", "rb");

  if (!f){
    printf("ERROR 1\n");
    exit(0);
  }

  // textlen
  if ((textlenid = shmget(textlenkey,
			  sizeof(long int),
			  IPC_CREAT | 0666)) < 0){
    printf("error 1\n");
    exit(0);
  }
  
  if ((char*)(textlen = shmat(textlenid, NULL, 0)) == (char*)-1){
    printf("error 2\n");
    exit(0);
  }
  
  fseek(f, 0, SEEK_END);
  *textlen = ftell(f);

  if (!*textlen) {
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

  fseek(f, 0, SEEK_SET);
  fread(text, 1, *textlen, f);
  // text /

  // result
  if ((resultid = shmget(resultkey,
		      sizeof(char),
		      IPC_CREAT | 0666)) < 0){
    printf("error 1\n");
    exit(0);
  }
  
  if ((char*)(result = shmat(textid, NULL, 0)) == (char*)-1){
    printf("error 2\n");
    exit(0);
  }
  // result /
  
  
  *result = 0;
  printf("waiting");

  while(!*result) ;

  shmdt(text);
  shmdt(textlen);
  shmdt(result);  
}
