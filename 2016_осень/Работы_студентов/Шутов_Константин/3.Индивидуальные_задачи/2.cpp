#include<stdio.h>
#define N 10
int main()
{
	int a[N]={1,2,3,4,5,6,7,8,9,10}, c;
	scanf("%d",&c);
	for(int i=0, j=N-1; i!=j;)
	{
		if(a[i] + a[j] == c) 
		{
			printf("%d[%d], %d[%d]\n", a[i], i, a[j], j);
			return 0;
		}
		j--;
		if(a[i] + a[j] < c) i++, j=N-1;	
	}
	printf("Такие числа не нашли\n");
	return 0;
}
