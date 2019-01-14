#include "Exponentiation.h"

ulong_t exponentiation(int base, int exponent) {
	if (exponent == 1) {
		return base;
	}

	ulong_t one = exponentiation(base, exponent/2);
	ulong_t result = one * one;
	if (exponent % 2 == 1) {
		result = result * base;
	}
	return result;
}
