#include <stdio.h>
#include <limits.h>

#define N 10

int main() {
  int mass[N] = {10, 22, 0, -10, 43, -32, 24, 27, -19, -50};
  int max = mass[0]; int min = mass[0];
  int size = sizeof(mass) / sizeof(mass[0]);
  for (int i = 0; i < size; i++){
    if(mass[i] > max) {
      max = mass[i];
    }
    if (mass[i] < min) {
      min = mass[i];
    }
  }
  printf("Min: %d\nMax: %d\n", min, max);

  return 0;
}
