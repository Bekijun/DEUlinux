#include <stdio.h>
#include "arithmetic.h"

int main() {
    int a = 10, b = 5;
    printf("Subtract: %d - %d = %d\n", a, b, subtract(a, b));
    return 0;
}
