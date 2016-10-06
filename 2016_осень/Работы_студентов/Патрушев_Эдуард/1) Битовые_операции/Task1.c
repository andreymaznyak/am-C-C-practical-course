#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL, "RUS");
	
	int n, n1, i=0;
	char n2[10]={};
	
	printf("Введите число: ");
	scanf("%d", &n);
	n1 = n;
	printf("\nПредставления числа:\n");
	
	while (n1 != 0)
	{
		n2[i] = 1 & n1;
		n1 = n1 >> 1;
		i++;
	}
	
	printf("двоичное - ");
	
	for (--i; i>=0; i--)
	{
		printf("%d", n2[i]);
	}
	
	printf("\n");
	
	printf("восьмеричное - %o\nшестнадцатеричное - %x", n, n);
	
	return 0;
}
