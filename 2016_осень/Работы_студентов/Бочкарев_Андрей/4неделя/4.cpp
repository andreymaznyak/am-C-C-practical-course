#include <stdio.h>
#include <malloc.h>
#include <string.h>
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

void enter(FILE *inf, MARSH *route)
{
	for (int i = 0; i < N; i++)
	{
		fscanf(inf, "%s", &route[i].dep);
		fscanf(inf, "%s", &route[i].dest);
		fscanf(inf, "%d", &route[i].num);		
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
	FILE *inf, *outf;
	inf = fopen("input.txt" , "r");
	
	MARSH *route = (MARSH *) malloc(N * sizeof(MARSH));
	
	int routeN;
	int count = 0;
	
	printf("Scanning ""input.txt""... \n");
	enter(inf, route);
	fclose(inf);
	
	printf("Entered from file: \n");
	print(route);
	
	sort(route);	
	printf("Sorted: \n");
	print(route);
		
	printf("Enter route number \n");			
	scanf("%d", &routeN);
	
	outf = fopen("output.txt" , "w");
	
	for (int i = 0; i < N; i++)
		if (routeN == route[i].num){
			count++;
			fprintf(outf, "[%d] %s \n", i+1 , &route[i].dep);
			fprintf(outf, "[%d] %s \n", i+1 , &route[i].dest);
		}
		
		if (count == 0)
		fprintf(outf, "No such aircraft type");
	
	printf("The answer has been recorded");	
	free(route);
	fclose(outf);
}
