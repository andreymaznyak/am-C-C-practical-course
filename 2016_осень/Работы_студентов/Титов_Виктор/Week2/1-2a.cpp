#include <stdio.h>

#define N 5

int main() 
{
	int arr[N];
	int n = 0;
	int err = 1;
	printf("Enter array\n");

	for(int i=0;i<5;++i)
	{
		arr[i] = 0;
		scanf("%d", &arr[i]);
	}

	printf("Enter number\n");
	scanf("%d", &n);

	for(int i=0;i<5;++i)
		for(int j=i+1;j<5;++j)
			if(arr[i]+arr[j] == n){
				printf("i1: %d i2: %d n1: %d n2: %d", i, j, arr[i], arr[j]);
				err = 0;
			}
	if(err)
		printf("not found");
			

	getchar();
	getchar();
	return 0;
}