#include "hallib.h"

int main() {
    // // The string to be tested
    char* hello = "hello there, babygirl!";

    // // testing stringlen
    // int len = stringlen(hello);
    // printf("%d: %s", len, hello);
    
    // // testing string_slice
    // char slice[10];
    // string_slice(slice, hello, 6, 11);
    // println(slice);

    // Testing spliter
    void all_h(char* temp) {
        println(temp);
    }
    spliter(hello, ' ', *all_h);


}
