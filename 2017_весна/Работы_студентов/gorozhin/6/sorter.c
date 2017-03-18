#include <stdio.h>
#include <stdlib.h>
#include "seq.h"
#include <sys/wait.h>
#include <sys/shm.h>
#include <unistd.h>

void swap(int* origin, int i, int j){
  if (i != j){
    int temp = origin[i];
    origin[i] = origin[j];
    origin[j] = temp;
  }
}

void __qsort(int* origin, int ln){
  if (ln <= 1) return;
  
  int w = 0;
  int p = ln - 1;

  for (int i = 0; i < p; i++){
    if (origin[i] <= origin[p]){
      swap(origin, i, w++);
    }
  }
  swap(origin, p, w);

  __qsort(origin, w - 1);
  __qsort(origin + (w+1), ln - w - 1);
}

int main(){

  int* arr;
  int* arrlen;
  char* result;

  int arrid;
  int arrlenid;
  int resultid;
  
  if ((arrid = shmget(arrkey,
		      len*sizeof(int),
		      0666)) < 0){
    printf("error 1\n");
    exit(0);
  }
  
  if ((char*)(arr = shmat(arrid, NULL, 0)) == (char*)-1){
    printf("error 2\n");
    exit(0);
  }  
  

  if ((arrlenid = shmget(arrlenkey,
		      sizeof(int),
		      0666)) < 0 ){
    printf("error 3\n");
    exit(0);
  }
  
  if ((char*)(arrlen = shmat(arrlenid, NULL, 0)) == (char*)-1){
    printf("error 4\n");
    exit(0);
  }  


  if ((resultid = shmget(resultkey,
		      sizeof(int),
		      0666)) < 0 ){
    printf("error 5\n");
    exit(0);
  }
  
  if ((char*)(result = shmat(resultid, NULL, 0)) == (char*)-1){
    printf("error 6\n");
    exit(0);
  }  

  __qsort(arr, *arrlen);
  *result = 1;
  shmdt(arr);
  shmdt(arrlen);
  shmdt(result);
}
