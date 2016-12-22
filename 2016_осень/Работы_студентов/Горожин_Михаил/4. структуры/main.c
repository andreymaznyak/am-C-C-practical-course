#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main(){
  student* arr = (student*)calloc(NUMBER_OF_STUDENTS, sizeof(student));
  FILE* in = fopen("in", "r");
  FILE* out = fopen("out", "w");
  for (int i = 0; i < NUMBER_OF_STUDENTS; i++){
    addStudent(in, arr, i);
  }

  
  
  sort(arr, 0, NUMBER_OF_STUDENTS-1);
  char p = 0;
  for (int i = 0; i < NUMBER_OF_STUDENTS; i++){
    if (predicate(arr[i])){
      print(arr[i], out);
      p = 1;
    }
  }
  if (!p){
    printf("No according students found\n");
  }

  for (int i = 0; i < NUMBER_OF_STUDENTS; i++){
    free(arr[i].fullname);
  }
  free(arr);
  fclose(in);
  fclose(out);
  return 0;
}

