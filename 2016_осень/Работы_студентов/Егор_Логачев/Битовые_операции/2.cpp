#include<stdio.h>

int main()
{
	int N1,N2,S;
	scanf("%d",&N1);
	scanf("%d",&N2);
	S=N1&N2;
	if(S>=N2 && S<=N2 && S>=N1 && S<=N1) 
	{
		printf("Равно");	
	}
	else printf("Не равно");
	return 0;
}
