#include <stdio.h>
#define N 17

int main(){
  int arr[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 21, 34, 55, 64};
  int sumToFind;

  printf("¬ведите число: ");
  scanf("%d", &sumToFind);

  for (int l = 0, r = N-1; l < r;){
    int s = arr[l] + arr[r];

    if (s == sumToFind) {
      printf( "%d + %d =%d\n\n""arr[%d] + arr[%d] \n", l, r, arr[l], arr[r], sumToFind);
      return 0;
    }
    else {
      if (s < sumToFind) {
	      l++;
      } 
	  else{
	      r--;
      }
    }
  }
  
  printf("„исел, сумма которых равна введЄнному числу, нет \n", sumToFind);
  return 0;
}
