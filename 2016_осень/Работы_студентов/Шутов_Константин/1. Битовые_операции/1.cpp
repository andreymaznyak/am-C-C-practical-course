#include<stdio.h>
#include<math.h>

bool bit(int N, int P) 
{
    return (N & ( 1 << P ));
}

int main()
{
	int N,j=3,S=0;
	scanf("%d",&N);
	for(int i=sizeof(N)*8-1;i!=-1;i--) printf("%d",bit(N,i));	
	printf("\n");
	for(int i=sizeof(N)*8-1;i!=-1;i--) 
	{
		if(j!=-1) S+=pow(2,j--)*bit(N,i);
		if(j==-1) 
		{
			j=3;
			switch(S)
			{
				case 10: printf("A"); break;
				case 11: printf("B"); break;
				case 12: printf("C"); break;
				case 13: printf("D"); break;
				case 14: printf("E"); break;
				case 15: printf("F"); break;
				default: printf("%d",S); break;
			}
			S=0;
		}
	}
	return 0;
}
