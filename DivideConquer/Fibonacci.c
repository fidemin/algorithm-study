#include "Fibonacci.h"

ulong_t fb_normal(int n) {
	if (n == 0) {
		return 0;
	}

	if (n == 1 || n == 2) {
		return 1;
	}
	
	return fb_normal(n-1) + fb_normal(n-2);
}

fb_matrix_t fb_multiply_matrix(fb_matrix_t m1, fb_matrix_t m2) {
	fb_matrix_t result;
	result.data[0][0] = m1.data[0][0] * m2.data[0][0] + m1.data[0][1] * m2.data[1][0];
	result.data[0][1] = m1.data[0][0] * m2.data[0][1] + m1.data[0][1] * m2.data[1][1];
	result.data[1][0] = m1.data[1][0] * m2.data[0][0] + m1.data[1][1] * m2.data[1][0];
	result.data[1][1] = m1.data[1][0] * m2.data[0][1] + m1.data[1][1] * m2.data[1][1];
	return result;
}

fb_matrix_t fb_power_matrix(fb_matrix_t base, int power) {
	if (power == 1) {
		return base;
	}

	if (power % 2 == 1) {
		fb_matrix_t fb_powered = fb_power_matrix(base, (power-1)/2);
		return fb_multiply_matrix(fb_multiply_matrix(fb_powered, fb_powered), base);
	}

	return fb_multiply_matrix(fb_power_matrix(base, power/2), fb_power_matrix(base, power/2));
}

ulong_t fb_divide_conquer(int n) {
	if ( n == 0) {
		return 0;
	}

	fb_matrix_t m1;
	m1.data[0][0] = 1;
	m1.data[0][1] = 1;
	m1.data[1][0] = 1;
	m1.data[1][1] = 0;

	fb_matrix_t result_matrix = fb_power_matrix(m1, n);

	return result_matrix.data[0][1];
}


