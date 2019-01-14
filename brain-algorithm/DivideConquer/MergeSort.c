#include "MergeSort.h"

void mg_merge(int dataset[], int start_idx, int mid_idx, int end_idx) {
	int* tmp = (int*) malloc(sizeof(end_idx - start_idx + 1));

	int left_idx = start_idx;
	int right_idx = mid_idx + 1;
	int tmp_idx = 0;

	// sort merging parts to tmp array
	while (left_idx <= mid_idx && right_idx <= end_idx) {
		if (dataset[left_idx] >= dataset[right_idx]) {
			tmp[tmp_idx++] = dataset[right_idx++];
		} else {
			tmp[tmp_idx++] = dataset[left_idx++];	
		}
	}

	while (left_idx <= mid_idx) {
		tmp[tmp_idx++] = dataset[left_idx++];
	}

	while (right_idx <= end_idx) {
		tmp[tmp_idx++] = dataset[right_idx++];
	}


	tmp_idx = 0;
	for (int i = start_idx ; i <= end_idx; i++ ) {	
		dataset[i] = tmp[tmp_idx++];
	}
	
}

void mg_sort(int dataset[], int start_idx, int end_idx) {
	if ((end_idx - start_idx) < 1)
		return;

	int mid_idx = (start_idx + end_idx) / 2;

	mg_sort(dataset, start_idx, mid_idx);
	mg_sort(dataset, mid_idx + 1, end_idx);

	mg_merge(dataset, start_idx, mid_idx, end_idx);
}
