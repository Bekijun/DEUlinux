#include <stdio.h>
#include "arithmetic.h"

int main() {
    int a = 10, b = 5;
    printf("Add: %d + %d = %d\n", a, b, add(a, b));
    return 0;
}
