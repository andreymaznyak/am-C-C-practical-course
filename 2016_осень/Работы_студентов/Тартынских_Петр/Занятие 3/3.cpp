#include <stdio.h>
#include <string.h>
#define n 3

int main()
{
	typedef struct AEROFLOT{
		char city[32];
		int num;
		char type[32];
	} AEROFLOT;
	
	AEROFLOT planes[7];
	AEROFLOT mem;
	char typep[32];
	int count = 0;
	
	printf("Enter: city (to), number, plane type \n");
	
	for (int i = 0; i < n; i++)
		scanf("%s %d %s", &planes[i].city, &planes[i].num, &planes[i].type);
	
	
	printf("You entered: \n");
	
	for (int i = 0; i < n; i++)
		printf("%d %s %d %s \n",i+1 , planes[i].city, planes[i].num, planes[i].type);
	
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++){
			if (strcmp (planes[j].city, planes[j+1].city) > 0){
				mem = planes[j];
				planes[j] = planes[j+1];
				planes[j+1] = mem;			
			}
		}
		
	printf("Sorted: \n");
	
	for (int i = 0; i < n; i++)
		printf("%d %s %d %s \n",i+1 , planes[i].city, planes[i].num, planes[i].type);
		
	printf("Enter aircraft type \n");			
	scanf("%s", &typep);
	
	for (int i = 0; i < n; i++)
		if (strcmp(typep, planes[i].type) == 0){
			count++;
			printf("%s %d \n", planes[i].city, planes[i].num);
		}
		
	if (count == 0)
		printf("No such aircraft type");
		
	return 0;
}
