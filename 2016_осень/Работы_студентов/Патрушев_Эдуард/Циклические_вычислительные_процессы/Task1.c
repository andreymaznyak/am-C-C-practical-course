#include <stdio.h>
#include <math.h>

int absolut(double n);

void main()
{
	float a, b, c, x, X1, X2, dX, F;
	printf("Input a, b, c, X1, X2, dX: ");
	scanf("%f %f %f %f %f %f", &a, &b, &c, &X1, &X2, &dX);
	printf("\n");
	x = X1;
	while (x <= X2)
	{
		if ((x + 10 < 0) && (b != 0))
			F = a*x*x - c*x + b;
		else
			if ((x + 10 > 0) && (b = 0))
				F = (x-a)/(x-c);
			else
				F = (-x)/(a-c);
	
		if (((absolut(a) | absolut(b)) & ~(absolut(a) | absolut(c))) == 0)
			F = absolut(F);
		printf("X = %4.2f F = %4.2f\n", x, F);
		x += dX;
	}
}

int absolut(double n)
{
	return (int) n;
}
