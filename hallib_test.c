#include "hallib.h"

int main() {
    // // The string to be tested
    char hello[100] = "hello there, babygirl!";
    hello[3] = 'X';
    printf("%s", hello);

    // // testing stringlen
    // int len = stringlen(hello);
    // printf("%d: %s", len, hello);
    
    // // testing string_slice
    // char slice[10];
    // string_slice(slice, hello, 6, 11);
    // println(slice);

    // Testing spliter
    void pr(void* temp) {
        char* x = (char*) temp;
        println(x);
    }

    //spliter(hello, ' ', *pr);

    // void all_h(void* s) {
    //     int i = 0;
    //     char* check = (char*) s;
    //     while (*check != '\0') {
    //         check++;
    //     }
    //     char x[i];
    //     int j = 0;
    //     int len = stringlen(x);
    //     while (j<len) {
    //         x[j] = 'h';
    //         j++;
    //     }
    //     x[len] = '\0';
    // }


    // spliter(hello, ' ', *all_h);
    // println(hello);

}
