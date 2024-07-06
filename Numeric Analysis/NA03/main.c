#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DELTA 1e-10

double func(double x)
{
    return (1/3)*x*x*x + (1/8)*x*x - 6; //(1/3)x^3 + (1/8)x^2 -6
}

double dfunc(double x)
{
    return x*x + (1/4)*x; //x^2 + (1/4)x
}

double newton(double x)
{
    double xn;

    while(1) {
        xn = x = func(x)/dfunc(x);      // (c)
        if (fabs(xn - x) < DELTA) {
            return xn;
        }
        x = xn;                         // (e)
    }
    return x;
}
double binary(const double low, const double high, int *count)
{
    double l, lv, m, mv, h, hv;

    l = low;
    lv = func(l);
    h = high;
    hv = func(h);

    count = 0;
    while (fabs(h - l) > DELTA) {
        m = (l + h)/ 2;
        mv = func(m);
        if ( mv < 0) {                  // (b)
            h = m;
            hv = mv;
        } else {
            l = m;
            lv = mv;
        }
        count++;
    }
    return (l + h)/ 2;
}
int main(void) {
    int count;

    double high, low, x;

    high = 3.0;
    low = 2.0;
    x = 3.0;

    printf("newton : %lf\n", newton(x));
    printf("binary : %lf, count %d\n", binary(low, high,&count));
    
    return 0;
}