#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include "generated_code.c"


//##################### ALLOCATORS ################################





//##################### ALGORITHMS ################################



//---------------------- QUICKSORT --------------------------------

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {

    // Initialize pivot to be the first element
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        // Find the first element greater than
        // the pivot (from starting)
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }

        // Find the first element smaller than
        // the pivot (from last)
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {

        // call partition function to find Partition Index
        int pi = partition(arr, low, high);

        // Recursively call quickSort() for left and right
        // half based on Partition Index
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//-----------------------------------------------------------------


int is_same_bytes(void* a, void* b, int size) {
    char* x = (char*)a;
    char* y = (char*)b;

    for (int i = 0; i < size; i++) {
        if (x[i] != y[i]) {
            return 0;
        }
    }
    return 1;
}

int binary_search(int needle, int* haystack, int start, int stop) {

    if (needle == haystack[0]) {
        return 0;
    } else {
        stop = stop / 2;
        while (stop > 0) {
            if (needle < haystack[stop]) {
                stop = stop / 2;
            } else if (needle > haystack[stop]) {
                stop = stop + stop/2;
            } else {
                return stop;
            }
        }
    }
    return -1;
}

int count_instances(int needle, intArray* haystack, int sorted) {
    int count = 0;

    int trigger = 0;
    for (int i = 0; i < haystack->end; i++) {
        if (haystack->pointer[i] == needle) {
            trigger = 1;
            count++;
        } else if (trigger && sorted) {
            break;
        }
    }
    return count;
}


//#################################################################


typedef struct {
    char* pointer;
    size_t len;
} String;

typedef struct {
    char* pointer;
    size_t cap;
    size_t len;
} AutoString;





int power(int base, int power) {

    int ret = 1;

    for (int i = 0; i < power; i++) {
        ret *= base;
    }

    return ret;
}

int abs(int input) {
    if (input < 0) {
        return input - input - input;
    } else {
        return input;
    }
}

typedef struct {
    int value;
    char occupied;
} MapSlot;

typedef struct {
    MapSlot* slots;
    size_t cap;
} HashMap;

uint64_t fnv_hash(const char *str) {
    uint64_t hash = 1099511628211;
    while (*str) {
        hash ^= *(uint8_t *)str++;
        hash *= 0x1B;
    }
    return hash;
}

int hashmap_insert(int key, int value, HashMap* map) {
    return 1;
}

typedef unsigned char byte;

typedef struct {
    byte* buffer;
    size_t cap;
    size_t current;
} Arena;

Arena arena_create(size_t cap) {
    byte* buffer = malloc(cap);
    Arena arena;

    arena.buffer = buffer;
    arena.cap = cap;
    arena.current = 0;

    return arena;
}

int arena_free_all(Arena* arena) {
    free(arena->buffer);
    return 1;
}

void arena_reset(Arena* arena) {
    arena->current = 0;
}

void* arena_alloc(size_t number_of_items, size_t sizeof_items, char alignment, Arena* arena) {
    if (arena->current + sizeof_items*number_of_items > arena->cap) {
        arena->buffer = realloc(arena->buffer, arena->cap  + sizeof_items*number_of_items*2);
        arena->cap += sizeof_items*number_of_items*2;
    }
    if (arena->current % alignment != 0) {
        arena->current += alignment - (arena->current % alignment);
    }

    void* ret = arena->buffer + arena->current;

    arena->current += sizeof_items * number_of_items;

    return ret;
}

String get_puzzle_input_string(char* file_name, Arena* arena) {
    FILE* puzzle_input_file = fopen(file_name, "r");

    if (puzzle_input_file == NULL) {
        String err = {NULL, 0};
        return err;
    }

    fseek(puzzle_input_file, 0, SEEK_END);
    long size = ftell(puzzle_input_file);
    fseek(puzzle_input_file, 0, 0);

    char* puzzle_input = arena_alloc(size*2, 1, 1, arena);

    size_t bytes_read = fread(puzzle_input, 1, size, puzzle_input_file);
    printf("HERE!\n");

    String ret = {puzzle_input, bytes_read};

    return ret;
}

AutoString auto_string_new(int cap) {
    char* pointer = malloc(cap);

    size_t len = 0;
    AutoString result = {pointer, cap, len};

    return result;
}

void auto_string_push(char character, AutoString* string) {

    if (string->cap == string->len) {
        string->pointer = realloc(string->pointer, string->cap*2);
    }

    string->pointer[string->len] = character;

    string->pointer++;

    string->cap++;

}

void auto_string_clear(AutoString* string) {
    string->pointer = string->pointer - string->len;
}

int int_from_string(char* string, size_t len) {
    char* temp = string;
    int p = len;
    int result = 0;

    int i = 0;
    while (temp[i] != 0) {
        result += (temp[i] - 0x30) + power(10, len);
    }

    return result;
}

//############################ DOUBLY LINKED LIST ######################################################

// struct IntDoublyLinkedListNode{
//     int value;
//     struct IntDoublyLinkedListNode* previous;
//     struct IntDoublyLinkedListNode* next;
// }; 

// typedef struct IntDoublyLinkedListNode IntDoublyLinkedListNode;

// IntDoublyLinkedListNode* int_doubly_linked_list_init(Arena* arena, int value) {
//     IntDoublyLinkedListNode* first_node = arena_alloc(1, sizeof(IntDoublyLinkedListNode), sizeof(IntDoublyLinkedListNode), arena);
//     first_node->value = value;
//     return first_node;
// }


// void int_doubly_linked_list_push_front(IntDoublyLinkedListNode* node, int value, Arena* arena) {
//     while (node->previous != NULL) {
//         node = node->previous;
//     }

//     IntDoublyLinkedListNode* new_node = arena_alloc(1, sizeof(IntDoublyLinkedListNode), sizeof(IntDoublyLinkedListNode), arena);
//     new_node->value = value;
//     new_node->previous = NULL;
//     new_node->next = node;
//     node->previous = new_node;
// }

// void int_doubly_linked_list_push_back(IntDoublyLinkedListNode* node, int value, Arena* arena) {
//     while (node->next != NULL) {
//         node = node->next;
//     }
//     IntDoublyLinkedListNode* new_node = arena_alloc(1, sizeof(IntDoublyLinkedListNode), sizeof(IntDoublyLinkedListNode), arena);
//     new_node->value = value;
//     new_node->next = NULL;
//     new_node->previous = node;
//     node->next = new_node;
// }

// int int_doubly_linked_list_pop_front(IntDoublyLinkedListNode* node) {
//     while (node->next != NULL) {
//         node = node->next;
//     }
//     int return_value = node->value;
//     if (node->previous != NULL) {
//         node = node->previous;
//         node->next = NULL;
//     }

//     return return_value;
// }

// void int_doubly_linked_list_print_forwards(IntDoublyLinkedListNode* node) {
//     IntDoublyLinkedListNode* save = node; 
//     while (node->previous != NULL) {
//         node = node->previous;
//     }

//     int counter = 0;
//     while (node->next) {
//         printf("%d, ", node->value);
//         node = node->next;
//         counter += 1;
//         if (counter == 10) {
//             counter = 0;
//             printf("\n");
//         }
//     }
//     printf("\n");

//     node = save;
// }

// void int_doubly_linked_list_print_backwards(IntDoublyLinkedListNode* node) {
//     IntDoublyLinkedListNode* save = node; 
//     while (node->next != NULL) {
//         node = node->next;
//     }

//     int counter = 0;
//     while (node->previous != NULL) {
//         printf("%d, ", node->value);
//         node = node->previous;
//         counter += 1;
//         if (counter == 10) {
//             counter = 0;
//             printf("\n");
//         }
//     }

//     node = save;
// }

//######################################################################################################

//############################ QUEUE ###################################################################

typedef struct {
    int* front;
    int* back;
    int* store;
} IntDynamicQueue;

//######################################################################################################

//############################ BINARY TREE #############################################################

struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    struct BinaryTreeNode* up;
};

typedef struct BinaryTreeNode BinaryTreeNode;

BinaryTreeNode* binary_tree_create() {
    
    BinaryTreeNode* root = malloc(sizeof(BinaryTreeNode));

    root->value = 0;
    root->up = NULL;
    root->left = NULL;
    root->right = NULL;

    return root;
}

BinaryTreeNode* binary_tree_new_node(int value, BinaryTreeNode* parent, BinaryTreeNode* left, BinaryTreeNode* right) {
    BinaryTreeNode* new_node = malloc(sizeof(BinaryTreeNode));

    new_node->value = value;
    new_node->up = parent;
    new_node->left = left;
    new_node->right = left;

    return new_node;
}

void binary_tree_add_node(BinaryTreeNode* root_node, int value) {
    BinaryTreeNode* top = root_node;

    while (1) {
        printf("Value: '%d'\n", value);
        if (root_node->value == value) {
            root_node = top;
            return;
        }
        else if (value < root_node->value) {
            if (root_node->left == NULL) {
                root_node->left = binary_tree_new_node(value, root_node, NULL, NULL);
                root_node = top;
                return;
            }
            root_node = root_node->left;
        } else if (value > root_node->value) {
            if (root_node->right == NULL) {
                root_node->right = binary_tree_new_node(value, root_node, NULL, NULL);
                root_node = top;
                return;
            }
            root_node = root_node->right;
        }
    }
}

void breadth_first_search(BinaryTreeNode* root_node, int needle) {

}

//#########################################################################################
