#include <stdio.h>
#include <stdlib.h>

int jeProst(int broj) {
    for(int i = 2; i<broj; i++) {
        if(broj%i == 0) {
            return 0;
        }
    }
    return 1;
}

int podmatrice(int mat[50][50], int n, int w, int h) {

    int brojac = 0;

    // - prva dva fora zadaju dimenzije podmatrice
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y ++) {
            if((w == x && h == y) || (w == y && h == x)) {
                // - druga dva fora "pomeraju" podmatricu dimenzija x i y kroz glavnu matricu
                for(int i = 0; i <= n-x; i++) {
                    for(int j = 0; j<= n-y; j++) {
                        int flag = 0;
                        // - treca dva fora prolaze kroz sve elemente podmatrice
                        for(int p = i; p < i+x; p++) {
                            for(int q = j; q < j+y; q++) {
                                if(jeProst(mat[p][q]) != 1) {
                                    flag++;
                                }
                            }
                        }
                        if(flag == 0) {
                            brojac++;
                        }
                    }
            }
            } else {
                continue;
            }
        }
    }

    return brojac;
}

int main(void) {

    int w;
    int h;
    printf("Unesi w: ");
    scanf("%d", &w);
    printf("\nUnesi h: ");
    scanf("%d", &h);

    int n;
    printf("Unesi n: ");
    scanf("%d", &n);

    int mat[50][50];

    printf("Unesi matricu: ");

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n%d", podmatrice(mat, n, w, h));
}

 