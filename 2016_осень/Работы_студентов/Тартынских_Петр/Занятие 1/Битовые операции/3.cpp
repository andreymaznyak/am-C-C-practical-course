#include <stdio.h>

int main(){
	
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	
	printf("%d", (num1 + ~num2 + 1));
	
	return 0;
}
