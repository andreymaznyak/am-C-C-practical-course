#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 3

struct AEROFLOT
{
	char Destination[10];
	int Number;
	char *typeAircraft;	
};

void print(AEROFLOT *f)
{
	for (int i = 0; i < N; i++)
	{
		printf("Flight destination: [%d] %s \n", i + 1, &f[i].Destination);
		printf("Flight number: [%d] %d \n", i + 1, f[i].Number);
		printf("Type Aircraft [%d] %s \n", i + 1, &f[i].typeAircraft);	
	}
}

void enter(AEROFLOT *f)
{
	for (int i = 0; i < N; i++)
	{
		printf("Flight destination: [%d] ", i + 1);
		scanf("%s", &f[i].Destination);
		
		printf("Flight number: [%d] ", i + 1);
		scanf("%d", &f[i].Number);
		
		printf("Type Aircraft [%d] ", i + 1);
		scanf("%s", &f[i].typeAircraft);		
	}
}

void sort(AEROFLOT *f)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (f[j].Number > f[j + 1].Number)
			{
				AEROFLOT tmp = f[j];
				f[j] = f[j + 1];
				f[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	AEROFLOT *flight = (AEROFLOT *) malloc(7 * sizeof(AEROFLOT));
	
	enter(flight);
	printf("\n");
	
	printf("Enter destination \n");
	char enDestination[10];
	scanf("%s", &enDestination);
	
	sort(flight);
	printf("Sorting: \n");
	print(flight);
	
		for (int i = 0; i < N; i++)
	{
		if (!strcmp(enDestination, flight[i].Destination))
		{
			printf("Flight number: %d \n", flight[i].Number);
			printf("Type of aircraft %s \n", &flight[i].typeAircraft);
		} 
	}
	
	free(flight);
			
	return 0;
}