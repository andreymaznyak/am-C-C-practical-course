#include <stdio.h>

int main(){
	
	int num;
	
	scanf("%d", &num);
	
	for (int i = sizeof(num) * 8 - 1; i >= 0; i--)
	{
		printf("%d", 1 & (num >> i));
	}
	
	printf("\n");
	
	printf("%X", num);
	
	return 0;
}
