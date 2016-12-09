#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define N 3

typedef struct AEROFLOT{
		char city[32];
		int num;
		char planetype[32];
	} AEROFLOT;

void print(AEROFLOT *planes)
{
	for (int i = 0; i < N; i++)
	{
		printf("[%d] %s \n", i + 1, &planes[i].city);
		printf("[%d] %d \n", i + 1, planes[i].num);
		printf("[%d] %s \n", i + 1, &planes[i].planetype);	
	}
}

void enter(AEROFLOT *planes)
{
	for (int i = 0; i < N; i++)
	{
		printf("Flight destination: [%d] ", i + 1);
		scanf("%s", &planes[i].city);
		
		printf("Flight number: [%d] ", i + 1);
		scanf("%d", &planes[i].num);
		
		printf("Plane type: [%d] ", i + 1);
		scanf("%s", &planes[i].planetype);		
	}
}

void sort(AEROFLOT *planes)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (strcmp (planes[j].city, planes[j+1].city) > 0)
			{
				AEROFLOT mem = planes[j];
				planes[j] = planes[j + 1];
				planes[j + 1] = mem;
			}
		}
	}
}

int main()
{	
	AEROFLOT *planes = (AEROFLOT *) malloc(N * sizeof(AEROFLOT));
	
	char typep[32];
	int count = 0;
	
	printf("%d \n", sizeof(AEROFLOT));
	printf("Enter: fligth destination, fligth number, plane type \n");
	enter(planes);
	
	printf("You entered: \n");
	print(planes);
	
	sort(planes);	
	printf("Sorted: \n");
	print(planes);
		
	printf("Enter aircraft type \n");			
	scanf("%s", &typep);
	
	for (int i = 0; i < N; i++)
		if (strcmp(typep, planes[i].planetype) == 0){
			count++;
			printf("[%d] %s \n", i+1 , &planes[i].city);
			printf("[%d] %d \n", i+1 , planes[i].num);
		}
		
	if (count == 0)
		printf("No such aircraft type");
		
	free(planes);
		
	return 0;
}
