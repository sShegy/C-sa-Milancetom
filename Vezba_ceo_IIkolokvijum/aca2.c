#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, t;
    int niz[50];

    printf("Unesi koliko ce da bude niz (max 50): ");
    scanf("%d", &n);

    

    printf("Unesi broj rotacija: ");
    scanf("%d", &m);

    printf("Unesi elemente niza:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }

    // Optimize rotations by reducing m to m % n
    m = m % n;

    // Perform rotation m times
    for (int j = 0; j < m; j++) {
        t = niz[0];
        for (int i = 1; i < n; i++) {
            niz[i - 1] = niz[i];
        }
        niz[n - 1] = t;
    }

    printf("\nRotirani niz:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }

    return 0;
}
