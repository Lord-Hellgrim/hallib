#include "advent.h"


intArray make_test_array(size_t cap) {
    intArray test_array = new_int_array(cap);

    for (int i = 0; i < cap; i++) {
        int_array_push(i, &test_array);
    }

    return test_array;
}

int test_abs() {
    int j = 1000;
    for (int i = -1000; i < 0; i++) {
        if (abs(i) != j) {
            printf("i: %d, j: %d\n", i, j);
            return -1;
        }
        j--;
    }

    for (int x = 0; x < 1000; x++) {
        if (abs(x) != x) {
            printf("x: %d\n", x);
            return -1;
        }
    }

    return 1;
}

int test_int_array() {
    intArray test_array = new_int_array(1000);

    int_array_push(5, &test_array);

    return 1;
}

int test_float_array() {
    FloatArray test_array = new_float_array(1000);

    float_array_push(5, &test_array);

    return 1;
}

int test_quicksort() {
    intArray test_array = new_int_array(100);

    for (int i = 100; i > 0; i--) {
        int_array_push(i, &test_array);
    }

    // print_int_array(&test_array);
    quickSort(test_array.pointer, 0, test_array.end-1);
    for (int j = 0; j < test_array.end; j++) {
        if (test_array.pointer[j] != j+1) {
            printf("j: %d, arr[j]: %d\n", j, test_array.pointer[j]);
            return -1;
        }
    }

    return 1;
}

int test_binary_search() {
    int test_array[5] = {1,2,6,9,10};

    int index = binary_search(2, test_array, 0, 5);

    if (index != 1) {
        return -1;
    }

    return 1;
}

int test_count_instances() {
    intArray test_array = new_int_array(100);
    
    int_array_push(1, &test_array);
    int_array_push(2, &test_array);
    int_array_push(2, &test_array);
    int_array_push(3, &test_array);
    int_array_push(3, &test_array);
    int_array_push(3, &test_array);
    int_array_push(4, &test_array);
    int_array_push(4, &test_array);
    int_array_push(4, &test_array);
    int_array_push(4, &test_array);
    int_array_push(5, &test_array);
    int_array_push(5, &test_array);

    int count1 = count_instances(2, &test_array, 0);
    int count2 = count_instances(2, &test_array, 0);
    int count3 = count_instances(2, &test_array, 0);
    int count4 = count_instances(2, &test_array, 0);
    int count5 = count_instances(2, &test_array, 0);

    if (count1 != 1) { return -1; }
    if (count2 != 2) { return -1; }
    if (count3 != 3) { return -1; }
    if (count4 != 4) { return -1; }
    if (count5 != 2) { return -1; }

    return 1;
}

int test_arena() {

    Arena arena = arena_create(100);

    int* pointer = arena_alloc(10, 4, 4, &arena);

    for (int i = 0; i < 10; i++) {
        int* temp = pointer + i;
        *temp = i;
    }


    return 1;   
}

int test_doubly_linked_list() {
    Arena arena = arena_create(100);
    IntDoublyLinkedListNode* root_node = int_doubly_linked_list_init(&arena, 0);

    for (int i = 1; i < 32; i += 1) {
        int_doubly_linked_list_push_back(root_node, i, &arena);
    }

    int_doubly_linked_list_print_backwards(root_node);
}

#define RUN_TEST(test_func)                                                         \
    do {                                                                            \
        printf("\x1b[1;33mRunning test: %s...\x1b[1;0m", #test_func);               \
        if (test_func()) {                                                          \
            printf("\x1b[1;32mTest %s passed.\x1b[1;0m\n", #test_func);             \
        } else {                                                                    \
            printf("\x1b[1;31mTest %s failed.\x1b[1;0m\n", #test_func);             \
        }                                                                           \
    } while (0)                                                  

int main() {

    RUN_TEST(test_abs);
    RUN_TEST(test_int_array);
    RUN_TEST(test_float_array);
    RUN_TEST(test_quicksort);
    RUN_TEST(test_binary_search);
    RUN_TEST(test_count_instances);
    RUN_TEST(test_arena);
    RUN_TEST(test_doubly_linked_list);
}