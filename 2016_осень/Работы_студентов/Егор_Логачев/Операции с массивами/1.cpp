#include<stdio.h>
#include<limits.h>

int main()
{
	int a[]={4,6,2,8,3,11,16,1,3,7};
	int size=sizeof(a)/sizeof(a[0]);
	int max=-1,min=INT_MAX;
	for(int i=0;i<size;i++)
	{
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
	printf("max=%d\nmin=%d",max,min);
}
