#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>


int stringlen(char* s) {
    // Get length of string
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

void println(char* s) {
    // Quick shorthand for printing a char*
    printf("%s\n", s);

}


void string_slice(char* result, char* source, unsigned int start, unsigned int stop) {
    // Result must have enough space to store the slice, so at least stop-start + 1
    // Up to but not including!
    if (sizeof(result) < stop-start+1) {
        result = "";
        printf("one");
        return;
    }
    if (stop > stringlen(source)) {
        result = "";
        printf("two");
        return;
    } else if (start > stop) {
        result = "";
        printf("three");
        return;
    } else if (start == stop) {
        result = "";
        printf("four");
        return;
    }else {
        int len = stop-start;
        int i = start;
        while (i < stop) {
            result[i - start] = source[i];
            i++;
        }
        result[len+1] = '\0';
        return;
    }
    return;
}

// This one is a work in progress...
void spliter(char* s, char split, void (fun(void*))) {
    int len = stringlen(s);
    int i = 0;
    int last_split = 0;
    while(i <= len) {
        printf("%c\n", s[i]);
        printf("%p\n", &s[i]);
        if (s[i] == split) {
            printf("still going");
            // s[i] = '\0';
           // void* x = &s[i];
           // printf("%p\n", x);
           // fun(x);
           // last_split = i;
           // s[i] = split;
            i++;
        } else {
            i++;
        }
        s[i] = 'X';
    }
    void* x = &s[last_split];
    fun(x);

}