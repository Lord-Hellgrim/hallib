#include <stdio.h>
#include <stdlib.h>

// char* string_sum(const char* str1, const char* str2) {
//     size_t len1 = strlen(str1);
//     size_t len2 = strlen(str2);

//     char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));

//     if (result == NULL) {
//         printf("Memory allocation failed.\n");
//         return NULL;
//     }
    
//     strcpy(result, str1);
//     strcat(result, str2);

//     return result;
// }

void println(char* s) {
    
    printf("%s\n", s);

}

int stringlen(char* s) {
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

void string_slice(char* result, char* source, unsigned int start, unsigned int stop) {
    // Result must have enough space to store the slice, so at least stop-start + 1
    // Up to but not including!
    if (stop > stringlen(source)) {
        return;
    } else if (start > stop) {
        return;
    } else if (start == stop) {
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
void split_string(char* s, char split, void* (fun(char*))) {
    int len = stringlen(s);
    int i = 0;
    while(s[i] != '\0') {
        if (s[i] == split) {
            char* temp[i+1];
            string_slice(temp, s, 0, i+1);
            fun(temp);
        }
    }

}