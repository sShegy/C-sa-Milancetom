#include <stdio.h>
#include <stdlib.h>

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

int main()
{

    /**
        res[i][j] = mat[i][j]       : Element na istoj poziciji
                  + mat[i-1][j]     : Element iznad
                  + mat[i+1][j]     : Element ispod
                  + mat[i][j-1]     : Element levo
                  + mat[i][j+1]     : Element desno
                  + mat[i-1][j-1]   : Element gore levo
                  + mat[i-1][j+1]   : Element gore desno
                  + mat[i+1][j-1]   : Element dole levo
                  + mat[i+1][j+1]   : Element dole desno

        Imamo problem za res[0][0], jer element iznad ne postoji
        Zbog toga cemo elemente matrice uneti od koordinate [1][1]
        i dodati okvir nula oko matrice

        Ako je matrica dimenzije 4x4, zelimo da dobijemo ovako nesto
        0 0 0 0 0 0
        0 x x x x 0
        0 x x x x 0
        0 x x x x 0
        0 x x x x 0
        0 0 0 0 0 0

        Samim tim imamo nule okolo i one ne menjaju sumu
    */

    int mat[100][100];
    int mat2[100][100];
    int n, m;

    // unosimo dimenzije
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    // postavljamo nule na prvu i poslednju vrstu
    for (int i = 0; i <= n + 1; i++)
    {
        mat[i][0] = 0;
        mat[i][m + 1] = 0;
    }

    // postavljamo nule na prvu i poslednju kolonu
    for (int i = 0; i <= m + 1; i++)
    {
        mat[0][i] = 0;
        mat[n + 1][i] = 0;
    }

    // prolazimo kroz sve elemente i racunamo formulom
    for (int i2 = 0, i = 1; i <= n; i++, i2++)
    {
        for (int j2 = 0, j = 1; j <= m; j++, j2++)
        {
            mat2[i2][j2] =
                mat[i][j] +
                mat[i - 1][j] +
                mat[i + 1][j] +
                mat[i][j - 1] +
                mat[i][j + 1] +
                mat[i - 1][j - 1] +
                mat[i - 1][j + 1] +
                mat[i + 1][j - 1] +
                mat[i + 1][j + 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%2d ", mat2[i][j]);
        }

        printf("\n");
    }

    return 0;
}
