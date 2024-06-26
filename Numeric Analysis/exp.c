#include <stdio.h>
#include <math.h>

#ifndef DIM
#define DIM 10
#endif

double taylor(double x)
{
	double v = 1.0;
	int i;
	for(i = DIM; i > 0; i--) {
		v = v*x/i +1;
	}
	return v;
}

int main(void)
{
	double x, y, z;

	for(x = 0.0; x < 1.0; x += 0.1) {
		y = taylor(x);
		z = exp(x);
		printf("exp(%e) = %e  (err %+e) \n", x, y, (y - z)/z);
	}
	return 0;
}
