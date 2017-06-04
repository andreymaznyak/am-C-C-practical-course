#include <stdio.h>
#include <conio.h>

int main(){
    int num, i;
    printf("Put your number:\n");
    scanf("%d", &num);
    printf("\nBinary: ");
    for(i=sizeof(num)*8; i>0; i--){
        printf("%d", (num >> i)&1);
    }
    printf("\nHexidecimal: %X\n", num);
    _getch();
    return 0;
}
	