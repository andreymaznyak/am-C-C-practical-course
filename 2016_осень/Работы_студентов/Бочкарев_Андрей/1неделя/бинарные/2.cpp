#include <stdio.h>

int main(){
  int n1;
  int n2;
  scanf ("%d",&n1);
  scanf ("%d",&n2);

  if (!(n1 > n2) && !(n1 < n2)){
    printf("true");
  }
  else {
    printf("false");
  }
}
