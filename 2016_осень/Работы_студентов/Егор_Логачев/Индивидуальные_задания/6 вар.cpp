#include <stdio.h>
#include <math.h>
 
struct CIRCLE
{
    double x;
    double y;
    double r;
} circle;
 
double det(
        double a1, double b1, double c1,
        double a2, double b2, double c2 )
{
    double d  = (a1*a1+a2*a2)*b2 + (b1*b1+b2*b2)*c2 + (c1*c1+c2*c2)*a2;
    d -= (a1*a1+a2*a2)*c2 + (b1*b1+b2*b2)*a2 + (c1*c1+c2*c2)*b2;
    return d;
}
 
double norm(double x1, double y1, double x2, double y2)
{
    double x = x1 - x2;
    double y = y1 - y2;
    return sqrt(x*x+y*y);
}
 
CIRCLE circumscribed(
        double x1, double y1,
        double x2, double y2,
        double x3, double y3 )
{
    CIRCLE crcl;
    double a = norm(x1, y1, x2, y2);
    double b = norm(x1, y1, x3, y3);
    double c = norm(x3, y3, x2, y2);
    double Dinv = 0.5/(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
    crcl.r = a*b*c*fabs(Dinv);
    crcl.x =  Dinv*det(x1, x2, x3, y1, y2, y3);
    crcl.y = -Dinv*det(y1, y2, y3, x1, x2, x3);
    return crcl;
}
 
int main()
{
    double x1, y1;
    double x2, y2;
    double x3, y3;
    CIRCLE c;
 
    printf("Input x1 y1 x2 y2 x3 y3: ");
    scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
 
    c = circumscribed(x1, y1, x2, y2, x3, y3);
    printf("Центр: (%g, %g)\n", c.x, c.y);
    printf("Радиус: %g\n", c.r);
 
    return 0;
}
