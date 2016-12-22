#import <stdio.h>

#define N 10

int main(){
  
  int arr[N] = {6,5,4,8,7,2,5,9,4,7};

  int size = sizeof(arr)/sizeof(arr[0]); // pretend that i don't know array size

  int min = arr[0];
  int max = arr[0];

  
  for (int i = 0; i < size; i ++){
    if (arr[i] < min) {
      min = arr[i];
    }
    
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  printf("Min: %d\nMax: %d\n", min, max);
}
