#include <stdio.h>
#define N 10

int main()
{
	
	int mas[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int i = 0, j = N - 1, num, sum, bo;
	
	printf("Enter the number: \n");
	scanf("%d", &num);
	
	for(; i < j;)
	{
		sum = mas[i] + mas[j];
		
		if (sum == num)
		{
			printf("[%d]: %d + [%d]: %d = %d \n", i, mas[i], j, mas[j], sum);
			bo++;
		}
			
		j--;
		
		if (sum < num) i++, j = N - 1;
		
	}
	
	if (bo == 0) printf("Such numbers not found");
	
	return 0;
}
