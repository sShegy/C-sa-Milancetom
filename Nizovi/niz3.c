#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, b1 = 0, b2 = 0;
    int niz[50];
    printf("Unesi broj: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }

    int najce = niz[0];
    int tren = 1;

    for (int i = 0; i < n; i++) {
        int naj1 = niz[i];
        int tren1 = 1;

        for (int j = i + 1; j < n; j++) {
            if (naj1 == niz[j]) {
                tren1++;
            }
        }

        if (tren1 > tren ) {
            najce = naj1;
            tren = tren1;
        }
    }

    printf("%d %d\n", najce, tren);

    return 0;
}
