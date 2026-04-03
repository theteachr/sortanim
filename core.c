#include "core.h"
#include <stdbool.h>
#include <stdlib.h>

void swap(struct Arr* arr, int a, int b) {
	int temp = arr->elems[a];
	arr->elems[a] = arr->elems[b];
	arr->elems[b] = temp;
}

void sort(struct Arr* nums, swap_fn swap) {
	for (int i = 0; i < nums->size; i++) {
		for (int j = i; j < nums->size; j++) {
			if (nums->elems[i] > nums->elems[j]) {
				swap(nums, i, j);
			}
		}
	}
}

void init(struct Arr* arr) {
	for (int i = 0; i < arr->size; i++) {
		arr->elems[i] = rand() % 100;
	}
}

bool is_sorted(struct Arr* arr) {
	for (int j = 0; j < arr->size - 1; j++) {
		if (arr->elems[j + 1] < arr->elems[j]) {
			return false;
		}
	}

	return true;
}
