#include "Exponentiation.h"

ulong_t exponentiation(int base, int exponent) {
	if (exponent == 1) {
		return base;
	}

	
	if (exponent % 2 == 1) {
		return exponentiation(base, (exponent-1)/2) * exponentiation(base, (exponent-1)/2) * base;
	} 

	return exponentiation(base, exponent/2) * exponentiation(base, exponent/2);
}
