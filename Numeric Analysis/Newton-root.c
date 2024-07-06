#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double newton(double x)
{
	double v, vv;

	v = 2.0;
	vv = v + 1.0;
	while(fabs(vv - v) > 1e-10) {
		printf("	v = %e\n", v);
		vv = v;
		v = (v*v+x) / (2*v);
	}
	return v;
}

int main(int ac, char **av)
{
	double x, y, z;
	int i;

	for(i = 5; i <= 10; i++) {
		x = i * 0.1;
		y = newton(x);
		z = sqrt(x);
		printf("%e -> %e  (err %+e)\n", x, y, (y - z)/ z);
	}
	return 0;
}
