	#include <stdio.h>
	#include <stdlib.h>
#include <malloc.h>
#include <string>
#include <cstddef>
#define N 3

typedef struct MARSH{
		char dep[20];
		char dest[20];
		int num;
	} MARSH;

void print(MARSH *route)
{
	for (int i = 0; i < N; i++)
	{
		printf("[%d] %s \n", i + 1, &route[i].dep);
		printf("[%d] %s \n", i + 1, &route[i].dest);	
		printf("[%d] %d \n", i + 1, route[i].num);
	}
}

void enter(MARSH *route)
{
	for (int i = 0; i < N; i++)
	{
		printf("Departure: [%d] ", i + 1);
		scanf("%s", &route[i].dep);
		
		printf("Destination: [%d] ", i + 1);
		scanf("%s", &route[i].dest);
		
		printf("Route number: [%d] ", i + 1);
		scanf("%d", &route[i].num);		
	}
}

void sort(MARSH *route)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (route[j].num > route[j+1].num)
			{
				MARSH mem = route[j];
				route[j] = route[j + 1];
				route[j + 1] = mem;
			}
		}
	}
}

int main()
{	
	MARSH *route = (MARSH *) malloc(N * sizeof(MARSH));
	
	int routeN;
	int count = 0;
	
	printf("%d \n", sizeof(MARSH));
	printf("Enter: point of departure, destination, route number \n");
	enter(route);
	
	printf("You entered: \n");
	print(route);
	
	sort(route);	
	printf("Sorted: \n");
	print(route);
		
	printf("Enter route number: \n");			
	scanf("%d", &routeN);
	
	for (int i = 0; i < N; i++)
		if (routeN == route[i].num){
			count++;
			printf("[%d] %s \n", i+1 , &route[i].dep);
			printf("[%d] %s \n", i+1 , &route[i].dest);
			printf("[%d] %d \n", i+1 , route[i].num);
		}
		if (count == 0) {
			printf("No such route number\n");}
		
	free(route);
		
	return 0;
}
