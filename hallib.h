#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* string_sum(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    char* result = (char*)malloc((len1 + len2 + 1) * sizeof(char));

    if (result == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    
    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

void println(char* s) {
    
    printf("%s\n", s);

}
