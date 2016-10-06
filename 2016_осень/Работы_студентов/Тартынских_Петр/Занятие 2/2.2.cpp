#include <stdio.h>
 
#include <stdlib.h>

#include <ctime>

#define n 50

int main(){
	
	int array[10];
	
	int num, count, summ;
	
//Заполенение начального массива	

	srand(time(0));
	
	array[0] =0+rand()%n;
	
	for (int i = 1; i < 10; i++)
	{
		array[i] = array[i-1] + rand()%10;
		if (array[i] > n) array[i] = n;
	}

//Вывод элементов
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", array[i]);
	}

//Решение задачи

    printf("Enter a number \n");
    
	scanf("%d", &num);
	
	count = 0;
	
	for (int i = 0; i < 9; i++)
	{		
		for (int j = i + 1; j < 10; j++)
		{
			if (array[i]+array[j] == num)  {
			count++;
			printf("%d, %d \n", i, j);
			}
		}
	}
	
	if (count == 0) {
			printf("No elements equal to n");
		}
		
	return 0;
}
