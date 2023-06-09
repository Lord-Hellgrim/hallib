#include "hallib.h"

int main() {
    char* hello = "hello there, babygirl!";
    int len = stringlen(hello);
    println(hello);
    char slice[10];
    string_slice(slice, hello, 6, 11);
    println(slice);
    printf("%d\n", len);
}
