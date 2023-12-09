#include <stdio.h>

int main() {
    int x, a = 0, b = 1, c;
    
    printf("Unesi broj: ");
    scanf("%d", &x);

    int jeFibonacci = 0;

    while (c <= x) {
        if (c == x) {
            jeFibonacci = 1;
            break;
        }
        c = a + b;
        a = b;
        b = c;
    }

    if (jeFibonacci) {
        printf("Broj je Fibonacci broj.\n");
    } else {
        printf("Broj nije Fibonacci broj.\n");
    }

    return 0;
}