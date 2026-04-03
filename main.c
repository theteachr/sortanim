#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include "core.h"
#include "animate.h"

int main() {
	struct Arr nums = {
		.size = 5,
	};

	srand(time(NULL));
	init(&nums);
	sort(&nums, animate_mark_swap);

	// XXX(1)
	printf("\n");

	return 0;
}

/**
 * 2 0 1 3
 * 0 2 1 3
 * 0 1 2 3
 */

/**
 * 2 0 1 3
 *
 *     1 3
 * 2 0    
 *
 *     1 3
 * 0 2    
 *
 * 0 2 1 3
 */
