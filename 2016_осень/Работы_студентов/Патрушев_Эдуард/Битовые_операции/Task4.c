#include <stdio.h>

main()
{
	char s = "", a1, a2, b = 0;
	printf("Available commands:\nq - QUIT\ns - SET\ng - GET\n");
	while(s != 'q')
	{
		scanf("%c", &s);
		switch (s)
		{
			case 's':
				printf("\nCommand SET - input number of bit: ");
				scanf("%d", &a1);
				
				if((a1 > 0) && (a1 <= 8))
				{
					printf("\n1/0? ");
					scanf("%d", &a2);
					if(a2 == 1)
					{
						b = b | (1 << a1);
					}
					if(a2 == 0)
					{
						b = b & ~(1 << a1);
					}
					//printf("\n%d %d\n", a2, b);
				}
				else
					printf("\nERROR\n");
				break;
			case 'g':
				printf("\nCommand GET - choose number of bit: ");
				scanf("%d", &a1);
				if((a1 > 0) && (a1 <= 8))
				{
					printf("\nValue of %d bit - %d\n", a1, b & (int) pow(2, a1 - 1));
				}
				else
					printf("\nERROR\n");
				break;
		}
	}
	return 0;
}
