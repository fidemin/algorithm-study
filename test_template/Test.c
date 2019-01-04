#include <stdio.h>
#include "TestRunner.h"

int test_sample() {
	return 0;
}

int all_tests() {
	_verify(test_sample);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
