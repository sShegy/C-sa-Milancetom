
#include <stdio.h>
#include <stdlib.h>

/**
    Za uneti broj n, ispisati sledecu matricu.

    Primer:
    76896

    Ispis:
    7 6 8 9 6
    8 7 9 0 7
    9 8 0 1 8
    0 9 1 2 9
    1 0 2 3 0

*/

int main()
{
    int n;
    int mat[100][100];

    // unosimo broj
    scanf("%d", &n);

    // dimenzija matrice zavisi od broja cifara
    int x = n;
    int br = 0;

    // brojimo cifre
    while (x != 0)
    {
        br++;
        x /= 10;
    }

    // ubacujemo cifre u nulti red matrice
    // od poslednje do prve kolone
    for (int i = br - 1; i >= 0; i--)
    {
        mat[0][i] = n % 10;
        n /= 10;
    }

    // preskacemo nulti red matrice preskacemo jer se u njemu nalazi broj
    // svaki element matrice je za 1 veci od elementa tacno iznad njega
    // u matricu unosimo vrednosti mod 10
    for (int i = 1; i < br; i++)
    {
        for (int j = 0; j < br; j++)
        {
            mat[i][j] = (mat[i - 1][j] + 1) % 10;
        }
    }

    // ispisujemo matricu
    for (int i = 0; i < br; i++)
    {
        for (int j = 0; j < br; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}