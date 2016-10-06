#include<stdio.h>
#include<malloc.h>

#define N 5
#define K 2

struct STUDENT
{
	char* name;
	int number, usp[N];
};

int main()
{
	bool b=false;
	STUDENT *spisok = (STUDENT*)malloc(K*sizeof(STUDENT));
	for(int i=0; i<K; i++)
	{
		scanf("%s",&spisok[i].name);
		scanf("%d",&spisok[i].number);
		for(int j=0; j<N; j++) scanf("%d",&spisok[i].usp[j]);		
	}
	for(int i=0; i<K; i++)
	{
		for(int j=0; j<N; j++) 
		{
			if(spisok[i].usp[j]==2)  
			{
				b=true; 
				printf("%s", &spisok[i].name); 
				printf(" %d\n", spisok[i].number); 
				j=N;
			}			
		}
	}
	free(spisok);
	if(!b) printf("Takih studentov net");
	return 0;
}
