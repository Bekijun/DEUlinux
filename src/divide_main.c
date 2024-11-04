#include <stdio.h>
#include "arithmetic.h"

int main() {
    int a = 10, b = 5;
    printf("Divide: %d / %d = %.2f\n", a, b, divide(a, b));
    return 0;
}
