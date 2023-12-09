#include <stdio.h>
#include <stdlib.h>

void unesi_matricu(int n, int m, int niz[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &niz[i][j]);
        }
    }
}

void ispisi_matricu(int n, int m, int niz[10][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", niz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m;
    int niz[10][10];

    printf("Unesi dimenzije matrice (n m): ");
    scanf("%d %d", &n, &m);

    printf("Unesi matricu:\n");
    unesi_matricu(n, m, niz);

    printf("Ispis matrice:\n");
    ispisi_matricu(n, m, niz);

    return 0;
}
