#import <stdio.h>
#define N 8 // size of the bit field

int promptForAnInteger(char message[], int minPosition, int maxPosition);

int main(){
  char mem = 0;
  char c;

  while (1) {
    //scanf("%c", &c);
    // need to use this to prevent newline character
    // 
    fseek(stdin,0,SEEK_END);
    c = getc(stdin);
    switch (c) {
      case 'Q' :
      case 'q' :
        printf("Bye-bye.\n");
        return 0;
      case 'S' :      
      case 's' :
        {
          // i define a block here to have a scope that is
          // specific for this part of switch
          int p = promptForAnInteger("Enter bit position: ", 0, N-1);
          int newValue = promptForAnInteger("Enter bit value: ", 1, 2);
	  mem = (newValue == 1) ? mem | (1 << p) : mem & ~(1 << p);
        };
        break;
      case 'G' :
      case 'g' :
        {
          // same as above
          int p = promptForAnInteger("Enter bit position: ", 0, N-1);
          printf("%d\n", (mem >> p) & 1);
        };
        break;
      case 'H' :
      case 'h' :
        printf(" g\tAsks for a position and prints a value in that position\n"
               " s\tAsks for a position and a new value writes a value in the position\n"
               " h\tShows this help\n"
               " q\tQuits the program\n");
        break;
      default :
        printf("Unrecognised command, please provide a valid command or 'h' for help\n");
        break;
    }
  }
}

int promptForAnInteger(char message[], int minPosition, int maxPosition){
  int p = -1;
  do {
    printf("%s",message);
    scanf("%d", &p);
  }
  while (!((p >= minPosition) && (p <= maxPosition)));
  return p;
}
