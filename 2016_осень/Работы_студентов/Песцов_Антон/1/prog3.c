#include <conio.h>
#include <stdio.h>

int main()
{
	int a, b;
	printf("Put two numbers\n");
	scanf("%d", &a);
	scanf("%d", &b);
	printf("result:\n");
	printf("%d", (a+ ~b+1));
	_getch();
	return 0;
}