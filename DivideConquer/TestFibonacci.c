#include <stdio.h>
#include "TestRunner.h"
#include "Fibonacci.h"

int test_fb_multiply_matrix() {
	fb_matrix_t m1;
	fb_matrix_t m2;
	m1.data[0][0] = 1; // {{1, 2}, {2, 3}};
	m1.data[0][1] = 2;
	m1.data[1][0] = 2;
	m1.data[1][1] = 3;
	
	m2.data[0][0] = 1; // {{1, 0}, {3, 4}}; 
	m2.data[0][1] = 0;
	m2.data[1][0] = 3;
	m2.data[1][1] = 4;

	fb_matrix_t result = fb_multiply_matrix(m1, m2);

	fb_matrix_t expect;

	// {{7, 8}, {11, 12}};
	expect.data[0][0] = 7; 
	expect.data[0][1] = 8; 
	expect.data[1][0] = 11; 
	expect.data[1][1] = 12; 

	_assert(expect.data[0][0] == result.data[0][0]);
	_assert(expect.data[0][1] == result.data[0][1]);
	_assert(expect.data[1][0] == result.data[1][0]);
	_assert(expect.data[1][1] == result.data[1][1]);

	
	return 0;
}

int test_fibonacci() {
	int n = 42;
	ulong_t expect = 267914296;

	/*
	ulong_t result1 = fb_normal(n);
	_assert(expect == result1);
	*/

	ulong_t result2 = fb_divide_conquer(n);
	_assert(expect == result2);

	return 0;
}

int all_tests() {
	_verify(test_fibonacci);
	_verify(test_fb_multiply_matrix);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
