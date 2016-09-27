#include <stdio.h>

#define N 10

int main(){
  int arr[N] = {1, 1, 2, 3, 5, 8, 13, 21, 44, 65};
  //int arr[N] = {0};
  int sumToFind;
  printf("Input number to find: ");
  scanf("%d", &sumToFind);

  int c = 0;
  for(int i = 0, j = 1; (i < N) && (j < N);){
    // printf("i: %d, j: %d\n", i, j);
    if ((arr[i] + arr[j]) == sumToFind){
      // print them all
      printf("arr[%d] + arr[%d] = \n"
	     "= %d + %d =\n"
	     "= %d\n\n",
	     i, j, arr[i], arr[j], arr[i]+arr[j]);
      c++;
      // or not all
      // break;
    }
    j++;
    if (j == N){
      j = ++i + 1; // no need to check reversed pairs i.e. (1 + 2) == (2 + 1)
      // and pairs where i < j, because they were already checked
    }
  }
  if (!c)
    printf("Pair, that sums to %d not found\n", sumToFind);
}
