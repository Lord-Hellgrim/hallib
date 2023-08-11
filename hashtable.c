#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


typedef struct {
    char key[50];
    int value;
    bool assigned;
} HashTableEntry;

HashTableEntry new_empty_hashtable_entry() {
    HashTableEntry r;
    strcpy(r.key, "not assigned");
    r.value = 0xBAD;
    r.assigned = false;
    return r;
}

HashTableEntry r = new_empty_hashtable_entry();
HashTableEntry* x = &r;

HashTableEntry* table[1000];

int main() {
    printf("table[2] = %d\n", table[2]->value);
}