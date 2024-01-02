
#include <stdio.h>
#include <stdlib.h>


/**
    Za unete brojeve n i m, ispisati sledecu matricu:

    Primer:
    4 5

    Ispis:
     1  2  3  4  5
    14 15 16 17  6
    13 20 19 18  7
    12 11 10  9  8
*/


int main() {
    int n, m;
    int br = 1;

    int mat[100][100];

    scanf("%d %d", &n, &m);

    int levo, desno, gore, dole;
    levo = gore = 0;
    desno = m - 1;
    dole = n - 1;

    while(levo <= desno && gore <= dole) {

        // gornji red
        for (int i = levo; i <= desno; i++)
            mat[gore][i] = br++;
        gore++;

        if (gore > dole)
            break;

        // desna kolona
        for (int i = gore; i <= dole; i++)
            mat[i][desno] = br++;
        desno--;

        if (desno < levo)
            break;

        // donji red
        for (int i = desno; i >= levo; i--)
            mat[dole][i] = br++;
        dole--;

        if (gore > dole)
            break;

        // leva kolona
        for (int i = dole; i >= gore; i--)
            mat[i][levo] = br++;
        levo++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}