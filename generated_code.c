//##########################Array############################

//-----------------------int-----------------------------------


typedef struct {
    int* pointer;
    size_t cap;
    size_t end;
} intArray;

intArray int_array_new(size_t cap) {
    int* pointer = malloc(cap * sizeof(int));
    intArray array = {pointer, cap, 0};
    return array;
}

void int_array_clear(intArray* array) {
    size_t i = 0;
    while (i < array->end) {
        array->pointer[i] = 0;
    }
}

void int_array_destroy(intArray* array) {
    free(array->pointer);
    array->cap = 0;
    array->end = 0;
}

size_t int_array_push(int number, intArray* array) {
    if (array->end > array->cap) {
        return 0;
    }

    array->pointer[array->end] = number;
    array->end++;
    return 1;

}

void int_array_print(intArray* array) {
    size_t i = 0;
    while (i < array->end) {
        printf("%d\n", array->pointer[i]);
        i += 1;
    }
}

//-----------------------float-----------------------------------


typedef struct {
    float* pointer;
    size_t cap;
    size_t end;
} floatArray;

floatArray float_array_new(size_t cap) {
    float* pointer = malloc(cap * sizeof(int));
    floatArray array = {pointer, cap, 0};
    return array;
}

void float_array_clear(floatArray* array) {
    size_t i = 0;
    while (i < array->end) {
        array->pointer[i] = 0;
    }
}

void float_array_destroy(floatArray* array) {
    free(array->pointer);
    array->cap = 0;
    array->end = 0;
}

size_t float_array_push(int number, floatArray* array) {
    if (array->end > array->cap) {
        return 0;
    }

    array->pointer[array->end] = number;
    array->end++;
    return 1;

}

void float_array_print(floatArray* array) {
    size_t i = 0;
    while (i < array->end) {
        printf("%f\n", array->pointer[i]);
        i += 1;
    }
}

//###############################################################

//##########################HashMap############################

//-----------------------int-----------------------------------

//Unimplemented

//-----------------------float-----------------------------------

//Unimplemented

//###############################################################

//##########################DoublyLinkedList############################

//-----------------------int-----------------------------------



struct intDoublyLinkedListNode{
    int value;
    struct intDoublyLinkedListNode* previous;
    struct intDoublyLinkedListNode* next;
}; 

typedef struct intDoublyLinkedListNode intDoublyLinkedListNode;

intDoublyLinkedListNode* int_doubly_linked_list_init(Arena* arena, int value) {
    intDoublyLinkedListNode* first_node = arena_alloc(1, sizeof(intDoublyLinkedListNode), sizeof(intDoublyLinkedListNode), arena);
    first_node->value = value;
    return first_node;
}


void int_doubly_linked_list_push_front(intDoublyLinkedListNode* node, int value, Arena* arena) {
    while (node->previous != NULL) {
        node = node->previous;
    }

    intDoublyLinkedListNode* new_node = arena_alloc(1, sizeof(intDoublyLinkedListNode), sizeof(intDoublyLinkedListNode), arena);
    new_node->value = value;
    new_node->previous = NULL;
    new_node->next = node;
    node->previous = new_node;
}

void int_doubly_linked_list_push_back(intDoublyLinkedListNode* node, int value, Arena* arena) {
    while (node->next != NULL) {
        node = node->next;
    }
    intDoublyLinkedListNode* new_node = arena_alloc(1, sizeof(intDoublyLinkedListNode), sizeof(intDoublyLinkedListNode), arena);
    new_node->value = value;
    new_node->next = NULL;
    new_node->previous = node;
    node->next = new_node;
}

int int_doubly_linked_list_pop_front(intDoublyLinkedListNode* node) {
    while (node->next != NULL) {
        node = node->next;
    }
    int return_value = node->value;
    if (node->previous != NULL) {
        node = node->previous;
        node->next = NULL;
    }

    return return_value;
}

void int_doubly_linked_list_print_forwards(intDoublyLinkedListNode* node) {
    intDoublyLinkedListNode* save = node; 
    while (node->previous != NULL) {
        node = node->previous;
    }

    int counter = 0;
    while (node->next) {
        printf("%d, ", node->value);
        node = node->next;
        counter += 1;
        if (counter == 10) {
            counter = 0;
            printf("\n");
        }
    }
    printf("\n");

    node = save;
}

void int_doubly_linked_list_print_backwards(intDoublyLinkedListNode* node) {
    intDoublyLinkedListNode* save = node; 
    while (node->next != NULL) {
        node = node->next;
    }

    int counter = 0;
    while (node->previous != NULL) {
        printf("%d, ", node->value);
        node = node->previous;
        counter += 1;
        if (counter == 10) {
            counter = 0;
            printf("\n");
        }
    }

    node = save;
}

//-----------------------float-----------------------------------



struct floatDoublyLinkedListNode{
    float value;
    struct floatDoublyLinkedListNode* previous;
    struct floatDoublyLinkedListNode* next;
}; 

typedef struct floatDoublyLinkedListNode floatDoublyLinkedListNode;

floatDoublyLinkedListNode* float_doubly_linked_list_init(Arena* arena, float value) {
    floatDoublyLinkedListNode* first_node = arena_alloc(1, sizeof(floatDoublyLinkedListNode), sizeof(floatDoublyLinkedListNode), arena);
    first_node->value = value;
    return first_node;
}


void float_doubly_linked_list_push_front(floatDoublyLinkedListNode* node, float value, Arena* arena) {
    while (node->previous != NULL) {
        node = node->previous;
    }

    floatDoublyLinkedListNode* new_node = arena_alloc(1, sizeof(floatDoublyLinkedListNode), sizeof(floatDoublyLinkedListNode), arena);
    new_node->value = value;
    new_node->previous = NULL;
    new_node->next = node;
    node->previous = new_node;
}

void float_doubly_linked_list_push_back(floatDoublyLinkedListNode* node, float value, Arena* arena) {
    while (node->next != NULL) {
        node = node->next;
    }
    floatDoublyLinkedListNode* new_node = arena_alloc(1, sizeof(floatDoublyLinkedListNode), sizeof(floatDoublyLinkedListNode), arena);
    new_node->value = value;
    new_node->next = NULL;
    new_node->previous = node;
    node->next = new_node;
}

int float_doubly_linked_list_pop_front(floatDoublyLinkedListNode* node) {
    while (node->next != NULL) {
        node = node->next;
    }
    float return_value = node->value;
    if (node->previous != NULL) {
        node = node->previous;
        node->next = NULL;
    }

    return return_value;
}

void float_doubly_linked_list_print_forwards(floatDoublyLinkedListNode* node) {
    floatDoublyLinkedListNode* save = node; 
    while (node->previous != NULL) {
        node = node->previous;
    }

    float counter = 0;
    while (node->next) {
        printf("%d, ", node->value);
        node = node->next;
        counter += 1;
        if (counter == 10) {
            counter = 0;
            printf("\n");
        }
    }
    printf("\n");

    node = save;
}

void float_doubly_linked_list_print_backwards(floatDoublyLinkedListNode* node) {
    floatDoublyLinkedListNode* save = node; 
    while (node->next != NULL) {
        node = node->next;
    }

    float counter = 0;
    while (node->previous != NULL) {
        printf("%d, ", node->value);
        node = node->previous;
        counter += 1;
        if (counter == 10) {
            counter = 0;
            printf("\n");
        }
    }

    node = save;
}

//###############################################################