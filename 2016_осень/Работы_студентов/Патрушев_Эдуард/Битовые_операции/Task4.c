#include <stdio.h>

void main()
{
	char symbol = '\0', bitNumber, bitValue, bit = 0;
	printf("Available commands:\nq - QUIT\ns - SET\ng - GET\n");
	while(symbol != 'q')
	{
		scanf("%c", &symbol);
		switch (symbol)
		{
			case 's':
				printf("\nCommand SET - input number of bit: ");
				scanf("%d", &bitNumber);
				
				if((bitNumber > 0) && (bitNumber <= 8))
				{
					printf("\ninput value: 1/0? ");
					scanf("%d", &bitValue);
					if(bitValue == 1)
						bit = bit | (1 << bitNumber);
					if(bitValue == 0)
						bit = bit & ~(1 << bitNumber);
				}
				else
					printf("\nERROR\n");
				break;
				
			case 'g':
				printf("\nCommand GET - choose number of bit: ");
				scanf("%d", &bitNumber);
				if((bitNumber > 0) && (bitNumber <= 8))
					printf("\nValue of %d bit - %d\n", bitNumber, bit & (int) pow(2, bitNumber - 1));
				else
					printf("\nERROR\n");
				break;
		}
	}
}
