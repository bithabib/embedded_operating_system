#include <stdio.h>
#include "helper.h"  // Include the header file

void printHelloWorld() {
    printf("Hello, world!\n");
}

int main() {
    printHelloWorld();
    printHelperMessage();  // Call the helper function
    return 0;
}