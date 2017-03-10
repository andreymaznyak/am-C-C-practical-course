#include <stdio.h>

#define N 5

int main(){
  int arr[N] = {1, 2, 3, 4, 5};

  int d, tmp;

  printf("Enter your number: ");
  scanf("%d", &d);

  for (int i = 0, j = N-1; i < j;) 
  {
    tmp = arr[i] + arr[j];
    if (tmp == d) 
	{
      printf("i: %d; j: %d; arr[i]: %d arr[j]: %d\n", i, j, arr[i], arr[j]);
	  getchar();
	  getchar();
      return 0;
    }
    else 
      if (tmp < d) 
		i++;
      else
		j--;
  }
  
  printf("Not found");
  return 0;
}