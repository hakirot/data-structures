#include <stdio.h>

int main(){

    printf("Hello, doofus\n");

    int * pointer;
    int c = 10;

    c = 20;

    pointer = &c;

    printf("%d\n", *pointer);

    return 0;
}
