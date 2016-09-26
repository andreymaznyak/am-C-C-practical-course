#import <stdio.h>

int main(){
  int a;
  int b;
  printf("Please, input first number: ");
  scanf ("%d",&a);
  printf("Please, input second number: ");
  scanf ("%d",&b);

  printf("a - b = %d\n", a + (~b + 1));
}
