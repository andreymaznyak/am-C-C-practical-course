#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct student {
  char* fullname;
  int group;
  char marks[5];
} student;

void addStudent(student* arr, int offset){
  int buffsize = 255;
  (*(arr+offset)).fullname = (char*)malloc(sizeof(char)*buffsize);
  printf("Enter name: ");
  scanf("%s", arr[offset].fullname);
  
  printf("Enter group: ");
  scanf("%d", &arr[offset].group);
  
  printf("Enter marks(splitted with space): ");
  scanf("%d %d %d %d %d",
	(int*)&arr[offset].marks[0],
	(int*)&arr[offset].marks[1],
	(int*)&arr[offset].marks[2],
	(int*)&arr[offset].marks[3],
	(int*)&arr[offset].marks[4]);
  printf("\n");

}

char predicate(student s){
  for (int i = 0; i < 5; i++){
    if (((s.marks[i]) > 5) || ((s.marks[i]) < 4))
      return 0;
  }
  return 1;
}

float average(student s){
  char res = 0;
  for (int i = 0; i < 5; i++){
    res += s.marks[i];
  }
  return res/5.0;
}

void print(student arr){
  printf("%s\n", arr.fullname);
  printf("%d\n", arr.group);
  for (int j = 0; j < 5; j++)
    printf(j == 4 ? "%d" : "%d, ", arr.marks[j]);
  printf("\n\n");
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
    }
  }
  swap(arr, pivot, wall);
  sort(arr, from, wall-1);
  sort(arr, wall+1, to);
}

int main(){
  student* arr = (student*)calloc(N, sizeof(student));
  for (int i = 0; i < N; i++){
    addStudent(arr, i);
  }
  sort(arr, 0, N-1);
  char p = 0;
  for (int i = 0; i < N; i++){
    if (predicate(arr[i])){
      print(arr[i]);
      p = 1;
    }
  }
  if (!p){
    printf("No according students found\n");	  
  }

  for (int i = 0; i < N; i++){
    free(arr[i].fullname);
  }
  free(arr);

  return 0;
}

