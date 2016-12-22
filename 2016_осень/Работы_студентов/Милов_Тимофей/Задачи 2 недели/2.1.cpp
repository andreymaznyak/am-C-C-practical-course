#include <stdio.h>
#include "stdafx.h"

#define N 10

int main() {
	int arr[N] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int d, tmp;

	printf("Enter your number: ");
	scanf_s("%d", &d);

	for (int i = 0, j = N - 1; i < j;)
	{
		tmp = arr[i] + arr[j];
		if (tmp == d)
		{
			printf("i = %d; j = %d\n arr[i] = %d arr[j] = %d\n", i, j, arr[i], arr[j]);
			getchar();
			getchar();
			return 0;
		}
		else
			if (tmp < d)
				i++;
			else
				j--;
	}

	printf("Not found");
	getchar();
	getchar();
	return 0;
}

