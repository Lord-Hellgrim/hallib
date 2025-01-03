

types_and_functions = {
    "Array": ["int", "float"],
    "HashMap": ["int", "float"],
    "DoublyLinkedList": ['int', 'float'],
}

templates = {
    "Array": r"""
typedef struct {
    {{TYPE}}* pointer;
    size_t cap;
    size_t end;
} {{CAPS_TYPE}}Array;

{{CAPS_TYPE}}Array {{TYPE}}_array_new(size_t cap) {
    {{TYPE}}* pointer = malloc(cap * sizeof(int));
    {{CAPS_TYPE}}Array array = {pointer, cap, 0};
    return array;
}

void {{TYPE}}_array_clear({{CAPS_TYPE}}Array* array) {
    size_t i = 0;
    while (i < array->end) {
        array->pointer[i] = 0;
    }
}

void {{TYPE}}_array_destroy({{CAPS_TYPE}}Array* array) {
    free(array->pointer);
    array->cap = 0;
    array->end = 0;
}

size_t {{TYPE}}_array_push(int number, {{CAPS_TYPE}}Array* array) {
    if (array->end > array->cap) {
        return 0;
    }

    array->pointer[array->end] = number;
    array->end++;
    return 1;

}

void {{TYPE}}_array_print({{CAPS_TYPE}}Array* array) {
    size_t i = 0;
    while (i < array->end) {
        printf("%d\n", array->pointer[i]);
        i += 1;
    }
}""",

"HashMap": "//Unimplemented",

"DoublyLinkedList": r"""

struct {{CAPS_TYPE}}DoublyLinkedListNode{
    {{TYPE}} value;
    struct {{CAPS_TYPE}}DoublyLinkedListNode* previous;
    struct {{CAPS_TYPE}}DoublyLinkedListNode* next;
}; 

typedef struct {{CAPS_TYPE}}DoublyLinkedListNode {{CAPS_TYPE}}DoublyLinkedListNode;

{{CAPS_TYPE}}DoublyLinkedListNode* {{TYPE}}_doubly_linked_list_init(Arena* arena, {{TYPE}} value) {
    {{CAPS_TYPE}}DoublyLinkedListNode* first_node = arena_alloc(1, sizeof({{CAPS_TYPE}}DoublyLinkedListNode), sizeof({{CAPS_TYPE}}DoublyLinkedListNode), arena);
    first_node->value = value;
    return first_node;
}


void {{TYPE}}_doubly_linked_list_push_front({{CAPS_TYPE}}DoublyLinkedListNode* node, {{TYPE}} value, Arena* arena) {
    while (node->previous != NULL) {
        node = node->previous;
    }

    {{CAPS_TYPE}}DoublyLinkedListNode* new_node = arena_alloc(1, sizeof({{CAPS_TYPE}}DoublyLinkedListNode), sizeof({{CAPS_TYPE}}DoublyLinkedListNode), arena);
    new_node->value = value;
    new_node->previous = NULL;
    new_node->next = node;
    node->previous = new_node;
}

void {{TYPE}}_doubly_linked_list_push_back({{CAPS_TYPE}}DoublyLinkedListNode* node, {{TYPE}} value, Arena* arena) {
    while (node->next != NULL) {
        node = node->next;
    }
    {{CAPS_TYPE}}DoublyLinkedListNode* new_node = arena_alloc(1, sizeof({{CAPS_TYPE}}DoublyLinkedListNode), sizeof({{CAPS_TYPE}}DoublyLinkedListNode), arena);
    new_node->value = value;
    new_node->next = NULL;
    new_node->previous = node;
    node->next = new_node;
}

int {{TYPE}}_doubly_linked_list_pop_front({{CAPS_TYPE}}DoublyLinkedListNode* node) {
    while (node->next != NULL) {
        node = node->next;
    }
    {{TYPE}} return_value = node->value;
    if (node->previous != NULL) {
        node = node->previous;
        node->next = NULL;
    }

    return return_value;
}

void {{TYPE}}_doubly_linked_list_print_forwards({{CAPS_TYPE}}DoublyLinkedListNode* node) {
    {{CAPS_TYPE}}DoublyLinkedListNode* save = node; 
    while (node->previous != NULL) {
        node = node->previous;
    }

    {{TYPE}} counter = 0;
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

void {{TYPE}}_doubly_linked_list_print_backwards({{CAPS_TYPE}}DoublyLinkedListNode* node) {
    {{CAPS_TYPE}}DoublyLinkedListNode* save = node; 
    while (node->next != NULL) {
        node = node->next;
    }

    {{TYPE}} counter = 0;
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
}"""

}

code = []
for item in types_and_functions:
    code.append(f"//##########################{item}############################")
    for kind in types_and_functions[item]:
        code.append(f"//-----------------------{kind}-----------------------------------")
        template = templates[item]
        template = template.replace(r"{{CAPS_TYPE}}", kind)
        template = template.replace(r"{{TYPE}}", kind.casefold())
        code.append(template)
    code.append("//###############################################################")

code = "\n\n".join(code)
with open("generated_code.c", 'w', encoding = "utf8") as f:
    f.write(code)
