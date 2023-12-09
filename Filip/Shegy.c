#include <stdio.h>

int main() {
    int N, M;

    // Unos dimenzija tablice množenja
    printf("Unesi dimenzije tablice množenja (N M): ");
    scanf("%d %d", &N, &M);

    // Ispis tablice množenja
    printf("Tablica množenja %dx%d:\n", N, M);
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            printf("%4d ", i * j); // 4 mjesta za svaki rezultat
        }
        printf("\n");
    }

    return 0;
}
