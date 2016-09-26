#include<stdio.h>

int main()
{
	int N1,N2;
	scanf("%d",&N1);
	scanf("%d",&N2);
	printf("%d",(N1+((~N2) + 1)));
	return 0;
}
