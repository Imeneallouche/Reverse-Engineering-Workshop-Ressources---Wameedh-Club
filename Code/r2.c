#include <stdio.h>

void greet(int x) {
    if (x > 5) {
        printf("Hello!\n");
    } else {
        printf("Hi!\n");
    }
}

int main() {
    int a = 3;
    int b = 7;
    int result = 0;

    for (int i = 0; i < 5; i++) {
        if (i % 2 == 0) {
            result += i;
        } else if (i == 3) {
            result += b;
        } else {
            result += a;
        }
    }

    if (result > 10) {
        greet(result);
    } else {
        printf("Result too small: %d\n", result);
    }

    return 0;
}

