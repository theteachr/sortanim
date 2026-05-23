#pragma once
#include <stdbool.h>

struct Arr {
	int elems[10];
	int size;
};

typedef void (*swap_fn)(struct Arr*, int, int);

void swap(struct Arr*, int, int);
void init(struct Arr*);
bool is_sorted(struct Arr*);
void print_arr(struct Arr*);
