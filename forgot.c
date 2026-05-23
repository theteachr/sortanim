#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int(*comparer)(void const*, void const*);

void forgot_my_sort(void* ptr, size_t count, size_t size, comparer comp);

void forgot_my_sort(void* ptr, size_t count, size_t size, comparer comp) {
    void* const temp = malloc(size);
    void* const end = ptr + count*size;

    for (void* left = ptr; left < end; left += size) {
        for (void* right = left + size; right < end; right += size) {      
            if (comp(left, right) > 0) {
                // swap
                memcpy(temp, left, size); // temp = left
                memcpy(left, right, size); // left = right
                memcpy(right, temp, size); // right = temp
            }
        }
    }

    free(temp);
}

int compare_integers(void const* left, void const* right) {
    int const left_value = *((int const*) left);
    int const right_value = *((int const*) right);
    return left_value - right_value;
}

static struct {
    void const* sorted_buffer;
    size_t count;
    size_t element_size;
    int(*element_printer)(void const*);
} animation_data;

int print_int(void const* element) {
    int const value = *((int const*) element);
    return printf("%d", value);
}

void display_compare(void const* left, void const* right, int comparison) {
    if(left > right) {
        void const* tmp = left;
        left = right;
        right = tmp;
    } 
    int left_display_offset = 0;
    int right_display_offset = 0;
    for(void const* p = animation_data.sorted_buffer; p < left; p += animation_data.element_size) {
        int const print_offset = animation_data.element_printer(p) + printf(" ");
        left_display_offset += print_offset;
        right_display_offset += print_offset;
    }
    for(void const* p = left; p < right; p += animation_data.element_size) {
        int const print_offset = animation_data.element_printer(p) + printf(" ");
        right_display_offset += print_offset;
    }
    for(void const* p = right; p < animation_data.sorted_buffer + animation_data.count * animation_data.element_size; p += animation_data.element_size) {
        animation_data.element_printer(p);
        printf(" ");
    }
    printf("\n");
    for(int i = 0; i <= right_display_offset; ++i) {
        if(i == left_display_offset || i == right_display_offset) {
            printf("^");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
    for(int i = 0; i <= right_display_offset; ++i) {
        if(i == left_display_offset || i == right_display_offset) {
            printf("|");
        }
        else {
            printf(" ");
        }
    }
    printf("\n");
    for(int i = 0; i < left_display_offset; ++i) {
        printf(" ");
    }
    printf("+");
    for(int i = left_display_offset + 1; i < right_display_offset; ++i) {
        printf("-");
    }
    printf("+--> ");
    if(comparison > 0) {
        printf("Greater");
    }
    else if(comparison < 0) {
        printf("Less");
    }
    else {
        printf("Equal");
    }
    printf("\n\n");

}

int compare_integers_animate(void const* left, void const* right) {
    int const comparison_result = compare_integers(left, right);
    display_compare(left, right, comparison_result);
    return comparison_result;
}

int main() {
    int arr[] = {99999, 8888, 777, 6, 5, 4, 3, 2, 1};
    animation_data.sorted_buffer = arr;
    animation_data.count = sizeof(arr) / sizeof(*arr);
    animation_data.element_size = sizeof(*arr);
    animation_data.element_printer = print_int;

    forgot_my_sort(arr, sizeof(arr) / sizeof(*arr), sizeof(*arr), compare_integers_animate);

    animation_data.sorted_buffer = NULL;
    animation_data.count = 0;
    animation_data.element_size = 0;
    animation_data.element_printer = NULL;

    printf("\n******** SORTED! ********\n");
    for(size_t i = 0; i < sizeof(arr) / sizeof(*arr); ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}
