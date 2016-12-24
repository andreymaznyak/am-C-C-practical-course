#include <stdio.h>

//вариант 15

float func(float a, float b, float c, float x)
{
	if (x < 0 && b != 0)
		return -(a*x*x)+ b;
	else if (x > 0 && b == 0)
		return x/(x-c) + 5.5;
	else
		return x/(-c);

}

int main() 
{
	float a, b, c, x, endX, dX;
	float result = 0;

	printf("Enter a: ");
	scanf("%f", &a);

	printf("Enter b: ");
	scanf("%f", &b);

	printf("Enter c: ");
	scanf("%f", &c);

	printf("Enter start X: ");
	scanf("%f", &x);

	printf("Enter end X: ");
	scanf("%f", &endX);

	printf("Enter dX: ");
	scanf("%f", &dX);

	if (b != 0)
		printf("|=============== b != 0 ===============|\n");
	else
		printf("|=============== b = 0 ===============|\n");
	while (x <= endX)
	{
		if(x < 0)
			printf("x < 0, x = %f\tf = %f\n", x, func(a, b, c, x));
		else if (x == 0)
			printf("x = 0, x = %f\tf = %f\n", x, func(a, b, c, x));
		else
			printf("x > 0, x = %f\tf = %f\n", x, func(a, b, c, x));
		x+=dX;
	}
}
