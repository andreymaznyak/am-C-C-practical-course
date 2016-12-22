#include <stdio.h>


int main()
{
	char c;
	int m = 0;
	int n = 0;
	int v = 0;


	while(1)
	{
		printf("Введите команду\n");
		c = getchar();
		switch(c)
		{
			case 'q':
				return 0;		
			break;
			case 's':
				printf("Введите номер и значение бита\n");
				scanf("%d", &n);
				scanf("%d", &v);
				m = (v == 1) ? m | (1 << n) : m & ~(1 << n);
			break;
			case 'g':
				printf("Введите номер бита\n");
				scanf("%d", &n);
				printf("%d" ,((m >> n) & 1));
			break;
		}
	}
	return 0;
}