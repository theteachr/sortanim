#include "core.h"

void sort(struct Arr* nums, swap_fn swap) {
	for (int i = 0; i < nums->size; i++) {
		for (int j = i; j < nums->size; j++) {
			if (nums->elems[i] > nums->elems[j]) {
				swap(nums, i, j);
			}
		}
	}
}
