#include <stdio.h>
#include <stdlib.h>

void petlja(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int value = (i < j) ? n - i : n - j;
            printf("%d ", value);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Unesite n: ");
    scanf("%d", &n);
    petlja(n);
    return 0;
}
