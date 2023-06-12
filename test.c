#include <stdio.h>
#include <stdlib.h>

int main() {
  char* hello = malloc(500);
  
  printf("%ld", sizeof(hello));
}
