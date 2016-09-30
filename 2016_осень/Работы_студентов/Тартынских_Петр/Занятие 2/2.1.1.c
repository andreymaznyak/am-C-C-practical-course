#include <stdio.h>

#include <math.h>

int main(){
	
	double a, b, c, d, Xbgn, Xend, Xstep, X, F;
	int ai, bi, ci;
	
	printf("Enter a \n");
	scanf("%lf", &a);
	printf("Enter b \n");
	scanf("%lf", &b);
	printf("Enter c \n");
	scanf("%lf",&c);
	printf("Enter d \n");
	scanf("%lf", &d);
	
	ai = (int) a;
	bi = (int) b;
	ci = (int) c;
	
    printf("Enter Xbgn \n");
	scanf("%lf", &Xbgn);
	printf("Enter Xend \n");
	scanf("%lf", &Xend);
	printf("Enter Xstep \n");
	scanf("%lf", &Xstep);
	
	
	
	printf("X \t F \n");
	for(X = Xbgn; X <= Xend; X = X + Xstep) {
		printf("%.3lf \t", X);
		if ((X < 5.0) && (b != 0.0)){
			F = a*pow((X + 7) , 2) - b;
		} else if ((X > 5.0) && (b == 0.0)){
			F = (X - c * d) / (a*X);
		} else {
			F = X / c;
		}
		printf("%.3lf \n", F);
	}
	
	return 0;
}
