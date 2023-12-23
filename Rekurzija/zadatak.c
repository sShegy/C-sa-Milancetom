#include <stdio.h>
#include<math.h>

// Funkcija za proveru da li je broj Fibonačijev
int je_fibonacijev(int n) {
    int a = 0, b = 1, c;

    while (a <= n) {
        if (a == n) {
            return 1; // Broj je Fibonačijev
        }
        c = a + b;
        a = b;
        b = c;
    }

    return 0; // Broj nije Fibonačijev
}

// Funkcija za izbacivanje najveće ili najmanje cifre u zavisnosti od toga da li je broj Fibonačijev
int pom(int arg) {
    int broj = arg;
    int max_cifra = -1; // Inicijalizujemo na negativnu vrednost kako bismo proverili da li smo pronašli cifru
    int min_cifra = 10; // Inicijalizujemo na vrednost veću od maksimalne cifre

    // Prolazimo kroz cifre broja
    while (broj > 0) {
        int cifra = broj % 10;

        // Pronalazimo najveću cifru
        if (cifra > max_cifra) {
            max_cifra = cifra;
        }

        // Pronalazimo najmanju cifru
        if (cifra < min_cifra) {
            min_cifra = cifra;
        }

        broj /= 10;
    }

    // Ako je broj Fibonačijev, vraćamo broj bez najveće cifre
    if (je_fibonacijev(arg)) {
        return arg - max_cifra * (int)pow(10, max_cifra);
    }

    // Ako broj nije Fibonačijev, vraćamo broj bez najmanje cifre
    return arg / 10 * 10 + max_cifra;
}

int main() {
    int broj;

    do {
        // Unos broja od korisnika
        printf("Unesi broj (0 za kraj): ");
        scanf("%d", &broj);

        // Pozivamo funkciju i ispisujemo rezultat
        if (broj != 0) {
            printf("Rezultat: %d\n", pom(broj));
        }

    } while (broj != 0);

    return 0;
}
