#include <stdio.h>

int main() {
			char n=0;
			int dv=0;
			int i;
			printf("Введите число ");
			scanf("%d", &n);
			for ( i=7; i>=0; i--) {
					printf("%d", (n>>i)&1);
			}
					printf("\n");
			printf("%X", n);
			printf("\n");
			

}
