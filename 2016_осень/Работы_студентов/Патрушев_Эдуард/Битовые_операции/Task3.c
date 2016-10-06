#include <stdio.h>

main()
{
	int n1, n2;
	
	scanf("%d %d", &n1, &n2);
	
	printf("%d", (n1 + ~n2 + 1));
	
	return 0;
}
