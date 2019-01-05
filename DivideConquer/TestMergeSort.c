#include <stdio.h>
#include "TestRunner.h"
#include "MergeSort.h"

int test_mg_sort() {
	int dataset[] = {3, 2, 6, 4, 1, 4, 5};
	int result[] = {1, 2, 3, 4, 4, 5, 6};
	int length = 7;
	mg_sort(dataset, 0, length-1);
	
	for (int i = 0; i < length; i++) {
		_assert(result[i] == dataset[i]);
	} 
	return 0;
}


int all_tests() {
	_verify(test_mg_sort);
	return 0;
}

int main(int argc, char **argv) {
	int result = all_tests();
	if (result == 0)
		printf("PASSED\n");
	printf("Tests run: %d\n", tests_run);
	return result!=0;
}
