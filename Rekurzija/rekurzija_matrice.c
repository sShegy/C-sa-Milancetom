#include <stdio.h>

void matrica_zvezdica(int n, int m, int i, int j)
{
    // Ako smo došli do kraja matrice, završavamo rekurziju
    if (i == n)
    {
        return;
    }

    // Ako smo došli do kraja reda, prelazimo u novi red
    if (j == m)
    {
        printf("\n");
        matrica_zvezdica(n, m, i + 1, 0);
        return;
    }

    // Ispisujemo zvezdicu i pozivamo funkciju za sledeći element
    printf("* ");
    matrica_zvezdica(n, m, i, j + 1);
}

int main()
{
    int n, m;

    // Unos dimenzija matrice od korisnika
    printf("Unesi broj redova matrice: ");
    scanf("%d", &n);

    printf("Unesi broj kolona matrice: ");
    scanf("%d", &m);

    // Pozivamo funkciju za ispis matrice zvezdica
    matrica_zvezdica(n, m, 0, 0);

    return 0;
}
