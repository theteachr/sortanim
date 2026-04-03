#include "core.h" 
#include <unistd.h>
#include <stdio.h>

void print_arr(struct Arr* arr) {
	for (int i = 0; i < arr->size; i++) {
		printf("%d ", arr->elems[i]);
	}

	printf("\n");
}

void mark_arr(struct Arr* arr, int a, int b) {
	printf("\r");

	for (int i = 0; i < a; i++) {
		printf("%d ", arr->elems[i]);
	}

	printf("[%d] ", arr->elems[a]);

	for (int i = a + 1; i < b; i++) {
		printf("%d ", arr->elems[i]);
	}

	printf("[%d] ", arr->elems[b]);

	for (int i = b + 1; i < arr->size; i++) {
		printf("%d ", arr->elems[i]);
	}

	fflush(stdout);
}

void animate_mark_swap(struct Arr* arr, int a, int b) {
	sleep(1);
	swap(arr, a, b);
	mark_arr(arr, a, b);
	// XXX(1): Why printing a new line here is printing newlines in `mark_arr`?
	// printf("\n");
}

void animate_print_swap(struct Arr* arr, int a, int b) {
	sleep(1);
	print_arr(arr);
	swap(arr, a, b);
}
