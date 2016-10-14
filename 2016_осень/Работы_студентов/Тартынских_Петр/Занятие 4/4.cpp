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

void enter(FILE *inf, AEROFLOT *planes)
{
	for (int i = 0; i < N; i++)
	{
		fscanf(inf, "%s", &planes[i].city);
		fscanf(inf, "%d", &planes[i].num);
		fscanf(inf, "%s", &planes[i].planetype);		
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
	FILE *inf, *outf;
	inf = fopen("input.txt" , "r");
	
	AEROFLOT *planes = (AEROFLOT *) malloc(N * sizeof(AEROFLOT));
	
	char typep[32];
	int count = 0;
	
	printf("Scanning ""input.txt""... \n");
	enter(inf, planes);
	fclose(inf);
	
	printf("Entered from file: \n");
	print(planes);
	
	sort(planes);	
	printf("Sorted: \n");
	print(planes);
		
	printf("Enter aircraft type \n");			
	scanf("%s", &typep);
	
	outf = fopen("output.txt" , "w");
	
	for (int i = 0; i < N; i++)
		if (strcmp(typep, planes[i].planetype) == 0){
			count++;
			fprintf(outf, "[%d] %s \n", i+1 , &planes[i].city);
			fprintf(outf, "[%d] %d \n", i+1 , planes[i].num);
		}
		
	if (count == 0)
		fprintf(outf, "No such aircraft type");
	
	printf("The answer has been recorded");	
	free(planes);
	fclose(outf);
			
	return 0;
}
