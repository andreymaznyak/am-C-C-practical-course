#include <stdio.h>
#include <conio.h>

int main(){
	int n, min, max;
	min = 32767;
	max = 0;
	printf("Put amount of numbers:\n");
	scanf("%d",&n);
	int array[n];
	printf("Put numbers of array:\n");
	for (int i=0; i<n; i++)
	{
		scanf("%d", &array[i]);
		if (array[i]>max) max= array[i];
		if (array[i]<min) min= array[i]; 
	}
	printf("max = %d, min = %d", max, min);
	_getch();
	return 0;
}