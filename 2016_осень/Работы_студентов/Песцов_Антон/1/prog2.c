#include <conio.h>
#include <stdio.h>

int main()
{
	int a, b;
	printf("Put two numbers\n");
	scanf("%d", &a);
	scanf("%d", &b);
	if (a & ~b) 
	printf("not equal");
		else 
		printf("equal");
	_getch();
	return 0;
}