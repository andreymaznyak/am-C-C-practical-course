#include <stdio.h>

int main(){
  int a; int max = 32; int result[max];
  scanf("%d", &a);
  for(; a > 0; a /= 2){
    int i = a % 2;
    result[max] = i;
    printf("%d", result[max]);
    max--;
  }
  printf("\n");
}
