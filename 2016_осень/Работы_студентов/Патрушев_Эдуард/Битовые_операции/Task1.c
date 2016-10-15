#include <stdio.h>

void main()
{
	int number, numberCopy, i=0; // Input number, copy of it (will be changed), counter
	char numberBit[10]={}; // Holds bit interpretation (suitable for big input numbers)
	
	printf("Input number: ");
	scanf("%d", &number);
	numberCopy = number; // Got copy to change it
	printf("\nNumber interpretations:\n");
	while (numberCopy != 0)
	{
		numberBit[i] = 1 & numberCopy; // Sets the last bit to 1
		numberCopy = numberCopy >> 1; // Moves all bit interpretation to right
		i++; // Gets the number of symbols in bit interpretation
	}
	printf("2 - ");
	for (--i; i>=0; i--)
		printf("%d", numberBit[i]);	// Reverse bit interpretation to normal
	printf("\n8 - %o\n16 - %x", number, number);
}
