#include <stdio.h>
#include <stdlib.h>

/* Napisati program koji iz unetog niza od n elemenata
   formira novi niz koji sadrži samo elemente unetog
   niza koji su deljivi sa 5. Ispisati dobijeni niz, kao i
   maksimalni indeks tog niza. */

int main() {
    int n, o = 0; // o is the count of elements divisible by 5
    int niz[50];
    int niz2[50]; // To store elements divisible by 5

    printf("Unesi koliko ce da bude niz (max 50): ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Greska: Broj elemenata mora biti između 1 i 50.\n");
        return 1;
    }

    printf("Ubaci elemente niza:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &niz[i]);
    }

    // Formiranje novog niza sa elementima deljivim sa 5
    for (int i = 0; i < n; i++) {
        if (niz[i] % 5 == 0) {
            
            niz2[o] = niz[i]; // Store divisible elements in niz2
            o++;
        }
    }

    if (o > 0) {
        printf("\nElementi koji su deljivi sa 5:\n");
        for (int i = 0; i < o; i++) {
            printf("%d ", niz2[i]);
        }
        printf("\nMaksimalni indeks u novom nizu: %d\n", o - 1);
    } else {
        printf("\nNema elemenata deljivih sa 5.\n");
    }

    return 0;
}
