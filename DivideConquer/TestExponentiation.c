#include <stdio.h>
#include "TestRunner.h"
#include "Exponentiation.h"

int test_exponentiation() {
	ulong_t expect1 = 2*2*2*2;
	ulong_t result1 = exponentiation(2, 4);
	_assert(expect1 == result1);

	ulong_t expect2 = 2*2*2*2*2*2*2*2*2;
	ulong_t result2 = exponentiation(2, 9);
	_assert(expect2 == result2);
	return 0;
}

int all_tests() {
	_verify(test_exponentiation);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
