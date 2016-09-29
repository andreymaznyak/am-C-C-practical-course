#include <stdio.h>

//Этот блок сделал по совету
int setFalse(int bit, char bo)
{
	return (bo & ~(1 << bit));
}

int setTrue(int bit, char bo)
{
	return (bo | (1 << bit));
}

bool check(char bo, int bit) 
{
    return (bo & ( 1 << bit));
}
//
char command, bo = 0, bit = 0, stat = 0;

int main()
{
	printf("S - set bit, G - check bit, Q - quit \n");

	while (command != 'q')
	{
		scanf("%c", &command);
		
		if (command == 's') 
		{
			printf("Set bit number: \n");
			scanf("%d", &bit);
			
			printf("1 = true, 2 = false \n");
			scanf("%d", &stat);
		
		
			if (stat == 1) bo = setTrue(bit - 1, bo);					
				else if (stat == 2) bo = setFalse(bit - 1, bo);
			
		}
		
		if (command == 'g')
		{
			printf("Check bit number: \n");
			scanf("%d", &bit);

			printf("%d \n", check(bo,bit - 1));
			
		}		
	}

	return 0;
}
