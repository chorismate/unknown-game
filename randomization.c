#include <stdlib.h>

double rand_double(void) {
	return (double)arc4random() / (double)UINT32_MAX;
}

double variability(double constant, double var) {
	return constant * (1.0+(rand_double()*var*2.0)-var);
}