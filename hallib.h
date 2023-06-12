#include <stdio.h>
#include <stdlib.h>

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
        return;
    }
    if (stop > stringlen(source)) {
        result = "";
        return;
    } else if (start > stop) {
        result = "";
        return;
    } else if (start == stop) {
        result = "";
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
void spliter(char* s, char split, void (fun(char*))) {
    int len = stringlen(s);
    int i = 0;
    int word = 0;
    while(s[i] != '\0') {
        if (s[i] == split) {
            char temp[word+1];
            string_slice(temp, s, i-word, i+1);
            fun(temp);
            printf("word: %d, i: %d\n", word, i);
            word = 0;
            i++;
        } else {
            word++;
            i++;
        }
    }
    // Start back here when you get back.................................................................................
    char temp[word+1];
    string_slice(temp, s, i-word, i+1);
    fun(temp);
    printf("word: %d, i: %d\n", word, i);

}