#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double t, double x)
{
	return (t*t-x);
}

double bisection(double x)
{
	double lo, hi, lv, hv;
	double md, mv;

	lo = 0.0;
	lv = func(lo, x);
	hi = 2.0;
	hv = func(hi, x);

	while(fabs(hi-lo) > 1e-10) {
		printf("	(lo, hi) = (%e, %e)\n", lo, hi);
		md = (lo + hi) / 2.0;
		mv = func(md, x);
		if (mv < 0) {
			lo = md;
			lv = mv;
		}else {
			hi = md;
			hv = mv;
		}
	}
	return (hi+lo)/2.0;
}

int main(int ac, char **av)
{
	double x, y, z;
	int i;

	for(i = 5; i <= 10; i++) {
		x = i * 0.1;
		y = bisection(x);
		z = sqrt(x);
		printf("%e -> %e  (err %+e)\n", x, y, (y - z)/ z);
	}
	return 0;
}
