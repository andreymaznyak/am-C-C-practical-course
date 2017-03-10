#include <stdio.h>

float func(float a, float b, float c, float x)
{
	if (x < 0 && b != 0)
		return -(2*x - c)/(c*x - a);
	else
	if (x > 0 && b == 0)
			return (x-a)/(x-c);
	else
		return -x/c -c/(2*x);

}

int main() 
{
	float a, b, c, x, endX, dx;
	float result = 0;

	printf("Enter a");
	scanf("%f", &a);

	printf("Enter b");
	scanf("%f", &b);

	printf("Enter c");
	scanf("%f", &c);

	printf("Enter sart x");
	scanf("%f", &x);

	printf("Enter end x");
	scanf("%f", &endX);

	printf("Enter dx");
	scanf("%f", &dx);

	if (b != 0)
		printf("|============== b != 0 ==============|\n");
	else
		printf("|============== b = 0 ==============|\n");
	while (x <= endX)
	{
		if(x < 0)
			printf("x < 0, x = %f\tf = %f\n", x, func(a, b, c, x));
		else if (x == 0)
			printf("x = 0, x = %f\tf = %f\n", x, func(a, b, c, x));
		else
			printf("x > 0, x = %f\tf = %f\n", x, func(a, b, c, x));
		x+=dx;
	}

	getchar();
	getchar();
	return 0;
}