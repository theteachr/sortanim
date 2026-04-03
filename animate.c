#include "animate.h"
#include "core.h" 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_arr(struct Arr* arr) {
	for (int i = 0; i < arr->size; i++) {
		printf("%2d ", arr->elems[i]);
	}

	printf("\n");
}

void print_offset(struct Arr* arr, int a, int b) {
	for (int i = 0; i < a; i++) {
		printf("   ");
	}

	printf("%2d ", arr->elems[a]);

	for (int i = a + 1; i < b; i++) {
		printf("   ");
	}

	printf("%2d ", arr->elems[b]);

	for (int i = b + 1; i < arr->size; i++) {
		printf("   ");
	}

	printf("\n");

	for (int i = 0; i < a; i++) {
		printf("%2d ", arr->elems[i]);
	}

	printf("   ");

	for (int i = a + 1; i < b; i++) {
		printf("%2d ", arr->elems[i]);
	}

	printf("   ");

	for (int i = b + 1; i < arr->size; i++) {
		printf("%2d ", arr->elems[i]);
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

void animate_swap_swap(struct Arr* arr, int a, int b) {
	system("clear");
	printf("\n");
	print_arr(arr);
	sleep(1);
	system("clear");
	print_offset(arr, a, b);
	swap(arr, a, b);
	sleep(1);
	system("clear");
	print_offset(arr, a, b);
	sleep(1);
	system("clear");
	printf("\n");
	print_arr(arr);
}
