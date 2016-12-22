#include <stdio.h>

int main() {
  int a,b;
  scanf("%d %d", &a, &b);
  if(a ^ b){
    printf("Числа не равны\n");
  } else printf("Числа равны\n");
  return 0;
}
