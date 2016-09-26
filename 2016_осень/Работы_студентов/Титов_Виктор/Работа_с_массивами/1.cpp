#include <stdio.h>


int main()
{
	int min;
	int max;
	int mas[5] = {5, 22, 8, 3, 5};
	max = min = mas[0];
	for(int i=0;i<5;++i)
	{
		if (mas[i] < min)
			min = mas[i];
		if(mas[i] > max)
			max = mas[i];
	}

	printf("Max: %d", max);
	printf(" ");
	printf("Min: %d", min);

	getchar();

	return 0;
}