#include "core.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void swap(struct Arr* arr, int a, int b) {
	int temp = arr->elems[a];
	arr->elems[a] = arr->elems[b];
	arr->elems[b] = temp;
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

void print_arr(struct Arr* arr) {
	for (int i = 0; i < arr->size; i++) {
		printf("%2d ", arr->elems[i]);
	}

	printf("\n");
}

