#include <stdio.h>
#include <stdlib.h>
#define N 1000

/**
    Za unetu matricu dimenzije NxM ispisati sledecu figuru
    Primer:
    4 4
    1 2 2 1
    2 2 1 1
    1 1 2 3
    1 1 2 2

    Ispis:
    7 10  9  5
    9 14 15 10
    8 13 15 11
    4  8 11  9

    Objasnjenje: (sam element, gore, dole, levo, desno i po dijagonali, ako postoji sve ove vrednosti)
    res[0][0] = mat[0][0] + mat[0][1] + mat[1][0] + mat[1][1]
            7 = 1 + 2 + 2 + 2
    res[1][2] = mat[1][2] + mat[0][2] + mat[2][2] + mat[1][1]
              + mat[1][3] + mat[0][1] + mat[0][3] + mat[2][1] + mat[2][3]

*/

void ucitajmatricu(int n, int niz[N][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &niz[i][j]);
        }
    }
}

void ispisi(int n, int niz[N][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", niz[i][j]);
        }
        printf("\n");
    }
}

void ispisi2(int n, int niz[N][N])
{
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= n + 1; j++)
        {
            printf("%d ", niz[i][j]);
        }
        printf("\n");
    }
}

void kolona(int n, int niz[N][N])
{
    for (int i = 0; i <= n + 1; i++)
    {
        niz[i][0] = 0;
        niz[i][n + 1] = 0;
    }
}

void vrsta(int n, int niz[N][N])
{
    for (int i = 0; i <= n + 1; i++)
    {
        niz[0][i] = 0;
        niz[n + 1][i] = 0;
    }
}

void dos(int n, int res[N][N], int niz[N][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            res[i][j] =
                niz[i][j] +
                niz[i - 1][j] +
                niz[i + 1][j] +
                niz[i][j - 1] +
                niz[i][j + 1] +
                niz[i - 1][j - 1] +
                niz[i - 1][j + 1] +
                niz[i + 1][j - 1] +
                niz[i + 1][j + 1];
        }
    }
}

int main()
{
    int n;
    printf("Unesi dimenziju matrice: ");
    scanf("%d", &n);
    int niz[N][N] = {0};
    int res[N][N] = {0};
    ucitajmatricu(n, niz);
    kolona(n, niz);
    vrsta(n, niz);
    printf("-------------\n");
    ispisi2(n, niz); 
    printf("-------------\n");
    dos(n, res, niz); 
    ispisi(n, res); 
    printf("-------------\n");
}
