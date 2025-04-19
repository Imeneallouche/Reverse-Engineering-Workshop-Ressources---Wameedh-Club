#include <stdio.h>

// Global variables
int global_number = 42;
char* message = "Hello from global variable!";

// Function prototypes
void greet();
int add(int a, int b);

int main() {
    greet();
    int result = add(5, 7);
    printf("5 + 7 = %d\n", result);
    return 0;
}

// Function definitions
void greet() {
    printf("%s\n", message);
}

int add(int a, int b) {
    return a + b;
}

