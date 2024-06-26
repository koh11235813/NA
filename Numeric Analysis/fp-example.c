#include <stdio.h>

#define DELTA 0.1

int main(void)
{
	float f;
	unsigned long i, max;

	for(max = 10; max <= 1000000000; max *= 10) {
		f = max;
		for(i = 0; i < max; i++) {
			f = f + DELTA;
		}
		printf("%e\t%e\n", (float)max, f);
	}
	return 0;
}
