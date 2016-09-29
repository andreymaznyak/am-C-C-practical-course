#include <stdio.h>

#define N 10

int main(){
  int arr[N] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
  //int arr[N] = {};

  int sumToFind;

  printf("Input number to find: ");
  scanf("%d", &sumToFind);

  for (int l = 0, r = N-1; l < r;) {
    int s = arr[l] + arr[r];

    if (s == sumToFind) {
      // found
      printf("arr[%d] + arr[%d] =\n"
	     "= %d + %d =\n"
	     "= %d\n\n", l, r, arr[l], arr[r], sumToFind);
      return 0;
    }
    else {
      if (s < sumToFind) {
	// not enought
	l++;
      } else{
	// too many
	r--;
      }
    }
  }
  
  printf("Pair, that sums to %d not found\n", sumToFind);
  return 0;
}
