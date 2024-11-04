#include <stdio.h>
#include "arithmetic.h"

int main() {
    int a = 10, b = 5;
    printf("Multiply: %d * %d = %d\n", a, b, multiply(a, b));
    return 0;
}
