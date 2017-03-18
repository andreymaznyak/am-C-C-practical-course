#include <stdio.h>
#include <stdlib.h>
#include "seq.h"
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>

int main(){
  int* arr;
  int* arrlen;
  char* result;

  int arrid;
  int arrlenid;
  int resultid;
  
  if ((arrid = shmget(arrkey,
		      len*sizeof(int),
		      IPC_CREAT | 0666)) < 0){
    printf("error 1\n");
    exit(0);
  }
  
  if ((char*)(arr = shmat(arrid, NULL, 0)) == (char*)-1){
    printf("error 2\n");
    exit(0);
  }  
  

  if ((arrlenid = shmget(arrlenkey,
		      sizeof(int),
		      IPC_CREAT | 0666)) < 0 ){
    printf("error 3\n");
    exit(0);
  }
  
  if ((char*)(arrlen = shmat(arrlenid, NULL, 0)) == (char*)-1){
    printf("error 4\n");
    exit(0);
  }  


  if ((resultid = shmget(resultkey,
		      sizeof(int),
		      IPC_CREAT | 0666)) < 0 ){
    printf("error 5\n");
    exit(0);
  }
  
  if ((char*)(result = shmat(resultid, NULL, 0)) == (char*)-1){
    printf("error 6\n");
    exit(0);
  }  

  *result = 0;
  *arrlen = len;
  
  for (int i = 0; i < *arrlen; i++){
    arr[i] = rand() % 10;
    printf("%d ", arr[i]);
  }
  printf("\n\n");
  
  while(!*result) ;

  for (int i = 0; i < *arrlen; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  shmdt(arr);
  shmdt(arrlen);
  shmdt(result);

  
}
