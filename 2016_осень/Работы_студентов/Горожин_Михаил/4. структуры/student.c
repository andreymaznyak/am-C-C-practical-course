#include "student.h"

void addStudent(FILE* in, student* arr, int offset){
  int buffsize = 4096;
  (*(arr+offset)).fullname = (char*)malloc(sizeof(char)*buffsize);
  char trash[buffsize];

  fscanf(in,"%[^\n]s",arr[offset].fullname);
  fscanf(in,"%[\n]",trash);
  
  fscanf(in,"%d",&arr[offset].group);
  fscanf(in,"%[\n]",trash);

  for (int i = 0; i < NUMBER_OF_MARKS; i++) {
    fscanf(in,"%d",(int*)&arr[offset].marks[i]);
    fscanf(in,"%[\n]",trash);
  }
}

char predicate(student s){
  for (int i = 0; i < NUMBER_OF_MARKS; i++){
    if (((s.marks[i]) > 5) || ((s.marks[i]) < 4))
      return 0;
  }
  return 1;
}

float average(student s){
  char res = 0;
  for (int i = 0; i < NUMBER_OF_MARKS; i++){
    res += s.marks[i];
  }
  return (res*1.0)/NUMBER_OF_MARKS;
}

void print(student arr, FILE* f){
  fprintf(f, "%s\n", arr.fullname);
  fprintf(f, "%d\n", arr.group);
  for (int j = 0; j < NUMBER_OF_MARKS; j++)
    fprintf(f, j == 4 ? "%d" : "%d, ", arr.marks[j]);
  fprintf(f, "\n\n");
}

void swap(student* arr, int i, int j){
  student temp = *(arr+i);
  *(arr+i) = *(arr+j);
  *(arr+j) = temp;
}

void sort(student* arr, int from, int to){
  if (from >= to) return;
  int pivot = to;
  int wall = from;
  
  for(int i = from; i < to; i++) {
    if (average(*(arr+i)) <= average(*(arr+pivot))){
      swap(arr, i, wall);
      wall++;
    }
  }
  swap(arr, pivot, wall);
  sort(arr, from, wall-1);
  sort(arr, wall+1, to);
}
