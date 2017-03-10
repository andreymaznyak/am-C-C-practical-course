#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	for(int i = 7; i >= 0; --i) {
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	printf("%X", n);
}
