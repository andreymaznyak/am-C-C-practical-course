#include <stdio.h>

int main()
{
	int arr [6] = {60,5,10,54,92,4};
	int max = arr[0];
	int min = arr[0];
	for (int i = 0; i < (sizeof(arr)/sizeof(*arr)); i++){
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	printf("%s%d\n", "min: ", min);
	printf("%s%d", "max: ", max);
}
