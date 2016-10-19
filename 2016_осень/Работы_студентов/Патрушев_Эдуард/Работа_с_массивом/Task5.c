#include <stdio.h>

#define MAX_MAS 10

int extremum(char max_min, int mas[MAX_MAS]);

void main()
{
	int mas[MAX_MAS] = {0, 3, 4, 28, 49, 6, 2, -8, 5, 9};
	
	printf("Max = %d, Min = %d", extremum(1, mas), extremum(0, mas));
}

int extremum(char max_min, int mas[MAX_MAS])
{
	int i = 1, m = mas[0];
	
	if (max_min)
	{
		for (i; i < MAX_MAS; i++)
			if(mas[i] > m)
				m = mas[i];
	}
	else
	{
		for (i; i < MAX_MAS; i++)
			if(mas[i] < m)
				m = mas[i];
	}
	return m;
}
