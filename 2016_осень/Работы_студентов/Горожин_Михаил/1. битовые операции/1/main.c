#import <stdio.h>
#import <limits.h>

int main(){
  unsigned int n;

  printf("Please input a number: \n");
  scanf("%d", &n);
  
  printf("Binary representation: ");
  // (sizeof(unsigned int) * CHAR_BIT - 1) is a number of bits in unsigned integer
  // so on every step we are getting leftmost bit of an integer and printing it
  // not very beautifull(i mean leading zeroes) but works for every unsigned int
  for (int i = (sizeof(unsigned int) * CHAR_BIT - 1); i >= 0; i--){
    int highestBit = (n >> i) & 1; // ignore garbage at the left
    printf("%d", highestBit);
  }
  printf("\nHexidecimal representation: %X\n", n);
}
