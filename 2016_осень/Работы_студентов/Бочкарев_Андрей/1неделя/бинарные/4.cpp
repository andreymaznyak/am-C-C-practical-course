
#include <iostream>

int main()
{
	char c;
	int m = 0;
	int n = 0;
	int v = 0;


	while(true)
	{
		printf("Enter command: q, s, g\n");
		std::cin >> c;
		switch(c)
		{
			case 'q':
				return 0;		
			break;
			case 's':
				printf("Enter number and value of bit\n");
				scanf("%d", &n);
				scanf("%d", &v);
				m = (v == 1) ? m | (1 << n) : m & ~(1 << n);
			break;
			case 'g':
				printf("Enter number of bit\n");
				scanf("%d", &n);
				printf("%d\n" ,((m >> n) & 1));
			break;
		}
	}

	return 0;
}
