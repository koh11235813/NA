#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DELTA 1e-10

double func(double x){
    return ((x*x/4) - (x/2) - (1/2)); //(1/4)x^2- (1/2)x -(1/2)
}

double dfunc(double x){
    return ((x/2) - (1/2)); //(1/2)*x - (1/2)
}

double newton(double x, long int *count)
{
    double xn = 0.0;

    while(1) {
        *count += 1;
        xn = x - func(x)/dfunc(x);      // (c)
        if (fabs(xn - x) < DELTA) {
            return xn;
        }
        if(*count > 1e+100){
            return -1;
        }
        printf("    (xn, x) = (%e, %e) , %d\n", xn, x, *count);
        x = xn;                         // (e)
    }
    return x;
}

double binary(double low, double high, long int *count)
{
    double l, lv, m, mv, h, hv;

    l = low;
    lv = func(l);
    h = high;
    hv = func(h);

    while (fabs(h - l) > DELTA) {
        m = (l + h)/ 2.0;
        mv = func(m);
        if (lv*mv < 0) {                  // (b)
            h = m;
            hv = mv;
        } else {
            l = m;
            lv = mv;
        }
        if(*count > 50)
        {
            return -1;
        }
        printf("    (h, l) = (%f, %f)\n", h, l);
        *count += 1;
    }
    *count += 1;
    return (l + h)/ 2.0;
}
int main(void) {
    long int count_a, count_b;
    double high, low, x;
    double a_1, a_2;

    count_a = 0;
    count_b = 0;
    high = 3.0;
    low = 2.0;
    x = 2.50;
    
    a_1 = newton(x, &count_a);
    a_2 = binary(low, high, &count_b);

    printf("newton : %lf, count %d\n", a_1, count_a);
    printf("binary : %lf, count %d\n", a_2, count_b);
    
    return 0;
}