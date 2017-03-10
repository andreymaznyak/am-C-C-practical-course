#include<stdio.h>
#define N 10
int main()
{
	int a[N]={1,2,3,4,5,6,7,8,9,10}, c, v=0;
	scanf("%d",&c);
	for(int i=0, j=N-1; i!=j;)
	{
		if(a[i] + a[j] == c) 
		{
			v++;
			printf("%d[%d], %d[%d]\n", a[i], i, a[j], j);
		}
		j--;
		if(a[i] + a[j] < c) i++, j=N-1;	
	}
	if(v==0) printf("Òàêèå ÷èñëà íå íàøëè\n");
	return 0;
}
