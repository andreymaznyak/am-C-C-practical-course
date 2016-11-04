#include <stdio.h>

int main() {
			int a=0;
			int b=0;
			int f=0;
					printf("Введите 2 числа \n");
					scanf("%d", &a);
					scanf("%d", &b);
					f = a+(~b+1);
					printf("%d", f, "\n");
}
