#include <stdio.h>
#include <stdlib.h>

void main(int argc, char** argv) {
  for (int i = 1; i < argc; i ++){
    printf("%s\n", argv[i]);
  }

  printf("PATH: %s\n", getenv("PATH"));
  printf("HOME: %s\n", getenv("HOME"));
  
  exit(0);
}
