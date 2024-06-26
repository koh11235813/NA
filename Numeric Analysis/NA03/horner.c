#include <stdio.h>
#include <math.h>

#ifndef PI
#define PI 3.14159265359
#endif

double horner(double x)
{
    double v = 1.0;
    int i;

    for(i = 3; i > 0; i--) {
        v =1.0 - v*x*x/(2*i*(2*i+1));
    }
    return v*x;
}
// x - x^3/3! + x^5/5! - x^7/7!
// x(1 - x^2/3! + x^4/5! - x^6/7!)
// x(1 - x^2/3!(1 - x^2/4*5 + x^4/4*5*6*7))
// x(1 - x^2/3!(1 - x^2/4*5(1- x^2/6*7)))
// 

double func(double x)
{
    double v = x;
    double xx = x;
    int i;

    for(i = 1; i <= 100; i++){
        xx *= -x*x/(2*i*(2*i+1));
        v += xx;
    }
    return v;
}
int main(void)
{
    double x = sin(PI/4);
    
    printf("horner %lf\n",horner(x));
    printf("func %lf\n",func(x));
    return 0;
}