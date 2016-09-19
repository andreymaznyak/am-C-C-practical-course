#import <stdio.h>

int main(){
  int a;
  int b;
  printf("Please, input first number: ");
  scanf ("%d",&a);
  printf("Please, input second number: ");
  scanf ("%d",&b);

  if (a & ~b){
    printf("It's \x1b[31mNOT OK\x1b[0m. Numbers are not equal.\n");
  }
  else {
    printf("It's \x1b[32mOK\x1b[0m. Numbers are equal.\n");
  }
}
