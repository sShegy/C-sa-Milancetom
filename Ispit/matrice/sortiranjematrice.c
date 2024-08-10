#include <stdio.h>

void sortiraj_kolonu(int kolona, int n, int mat[][20]) {
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n - 1 ; j++) {
            if (mat[j][kolona] > mat[j + 1][kolona]) {
                int tmp = mat[j][kolona];
                mat[j][kolona] = mat[j + 1][kolona];
                mat[j + 1][kolona] = tmp;
            }
        }
    }
}

int main() {
    int n = 5;
    int mat[5][20] = {
        {5, 12, 17, 9, 3},
        {13, 4, 8, 14, 1},
        {9, 6, 3, 7, 21},
        {7, 15, 6, 18, 10},
        {8, 11, 13, 5, 2}
    };

    for (int kolona = 0; kolona < 5; kolona++)
    {
        sortiraj_kolonu(kolona, n, mat);
    }
    

   

    // Ispisujemo sortiranu matricu
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
