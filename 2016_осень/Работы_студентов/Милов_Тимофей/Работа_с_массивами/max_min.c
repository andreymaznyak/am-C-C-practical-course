#include <stdio.h>

int main() {
	
			int mass[5];
			int max = mass[0];
			int min = mass[1];
			
					printf("Введите элементы массива\n");
					
					for (int i = 0; i < 5; i++)
					{
						scanf("%d", &mass[i]);
					}
					
					for (int i = 0; i < 5; i++)
					{
						if (mass[i] > max) max = mass[i];
					}
					
					for (int i = 0; i < 5; i++)
					{
						if (mass[i] < min) min = mass[i];
					}
					
					printf("Max = %d\n", max);
					printf("Min = %d\n", min);
	
}
