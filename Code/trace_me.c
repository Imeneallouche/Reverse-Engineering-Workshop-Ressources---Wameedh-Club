// trace_me.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("Hello, tracing world!\n");
    char* name = malloc(20);
    strcpy(name, "Imene");
    printf("Name: %s\n", name);
    free(name);
    return 0;
}

