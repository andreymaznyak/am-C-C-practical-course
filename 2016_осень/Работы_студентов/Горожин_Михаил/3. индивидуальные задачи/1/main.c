#include <stdio.h>

#define N 10

int main(){
  int arr[N] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
  //int arr[N] = {};

  int sumToFind;
  printf("Input number to find: ");
  scanf("%d", &sumToFind);

  int li = 0;
  for (int l = li+1, r = N;;) {
    // when we finished with one index switch to the next one 
    if ((r <= l)){
      li++;
      l = li+1;
      r = N;
    }

    // exit condition
    // we exit, if leftmost element in the
    // array is bigger then a sum, we look for,
    // or if we looked throught all the indexes
    if ((li >= N) || (arr[li] > sumToFind)){
      printf("Pair, that sums to %d not found\n", sumToFind);
      break;
    } 
    
    
    // midpoint
    int m = l + (r - l) / 2;

    // we find the according one with binary search
    if ((sumToFind - arr[li]) == arr[m]) {
      printf("arr[%d] + arr[%d] = \n"
	     "%d + %d = \n"
	     "= %d\n",
	     li, m, arr[li], arr[m], sumToFind);
      break;
    } else if ((sumToFind - arr[li]) < arr[m]) {
      r = m;
    } else {
      l = m + 1;
    }
  }

}
