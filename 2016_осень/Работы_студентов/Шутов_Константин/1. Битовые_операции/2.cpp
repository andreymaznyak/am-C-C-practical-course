#include<stdio.h>

int main()
{
	int N1,N2;
	scanf("%d",&N1);
	scanf("%d",&N2);
	if(~N1 & N2 | N1 & ~N2) printf("Ne ravni");	
	else printf("Ravni");
	return 0;
}
