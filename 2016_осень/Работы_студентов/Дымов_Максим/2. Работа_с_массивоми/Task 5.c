#include <stdio.h>

#define N 10

int main(){
	
	int array[N];
	
	int min, max;
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &array[i]);
	}
	
	min = array[0];
	
	for (int i = 0; i < N; i++)
	{
		if (array[i] > max) max = array[i];
		if (array[i] < min) min = array[i]; 
	}
	
	printf("Max = %d, min = %d", max, min);
	
	return 0;
}
