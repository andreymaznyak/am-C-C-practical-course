#include <stdio.h>

#define n 10

int max(int mas[n]);
int min(int mas[n]);

main()
{
	int mas[n] = {0, 3, 4, 28, 49, 6, 2, -8, 5, 9};
	
	printf("Max = %d, Min = %d", max(mas), min(mas));
	
	return 0;
}

int max(int *mas)
{
	int i = 1, m = mas[0];
	
	for (i; i < n; i++)
	{
		if(mas[i] > m)
		m = mas[i];
	}
	
	return m;
}

int min(int mas[n])
{
	int i = 1, m = mas[0];
	
	for (i; i < n; i++)
	{
		if(mas[i] < m)
		m = mas[i];
	}
	
	return m;
}
