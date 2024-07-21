#include <stdio.h>
#include <stdlib.h>

void ucitajniz(int n, int niz[n]) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }
}

void ispitiniz(int n, int niz[n]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", niz[i]);
    }
    printf("\n");
}

void sortirajniz(int n, int niz[n]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (niz[i] > niz[j]) {
                int temp = niz[i];
                niz[i] = niz[j];
                niz[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Upisi velicinu niza: ");
    scanf("%d", &n);
    int niz[n];
    ucitajniz(n, niz);
    sortirajniz(n, niz);
    ispitiniz(n, niz);

    return 0;
}
