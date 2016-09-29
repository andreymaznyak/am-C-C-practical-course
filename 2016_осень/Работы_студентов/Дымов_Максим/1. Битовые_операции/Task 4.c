#include <stdio.h>

int setZero(int num, char bo)
{
	return bo & ~(1 << num);
}

int setOne(int num, char bo)
{
	return bo | (1 << num);
}

bool status(char bo, int num) 
{
    return (bo & ( 1 << num));
}

char command, bo = 0, num = 0, tf = 0;

int main()
{

	while (command != 'q')
	{
		scanf("%c", &command);
		
		if (command == 's') 
		{
			printf("Enter the bit number: \n");
			scanf("%d", &num);
			
			printf("1 = true, 2 = false \n");
			scanf("%d", &tf);
		
		
			if (tf == 1) bo = setOne(num - 1, bo);
				else if (tf == 2) bo = setZero(num - 1, bo);			
		}
		
		if (command == 'g')
		{
			printf("[Status] Enter the bit number: \n");
			scanf("%d", &num);

			printf("%d \n", status(bo,num - 1));
			
		}		
	}

	return 0;
}