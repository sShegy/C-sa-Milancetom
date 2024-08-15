

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define N 99
/*
9 5 6 10 3 7 5
4 10 7 7 6 12 1
7 13 1 8 6 5 4
12 8 7 9 1 13 6
4 10 3 9 12 8 7
9 6 5 11 4 8 10
3 6 8 16 5 4 11
*/
int jeProst(int broj)
{
    if (broj < 2)
        return 0;
    for (int i = 2; i <= sqrt(broj); i++)
    {
        if (broj % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void podmatrica(int mat[N][N], int najmanji, int najveci, int n)
{
    int dim = INT_MAX;
    int xx = 0, yy = 0, ii = 0, jj = 0;

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int i = 0; i <= n - x; i++)
            {
                for (int j = 0; j <= n - y; j++)
                {
                    int flag = 0;
                    for (int p = i; p < x + i; p++)
                    {
                        for (int q = j; q < y + j; q++)
                        {
                            if (mat[p][q] == najmanji || mat[p][q] == najveci)
                            {
                                flag++;
                            }
                        }
                    }
                    if (flag == 2)
                    {
                        if (x * y < dim)
                        {
                            dim = x * y;
                            xx = x;
                            yy = y;
                            ii = i;
                            jj = j;
                        }
                    }
                }
            }
        }
    }

    for (int i = ii; i < ii + xx; i++)
    {
        for (int j = jj; j < jj + yy; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    int min = INT_MAX;
    int max = INT_MIN;
    int mat[N][N];

    printf("Unesi dimenziju matrice: ");
    scanf("%d", &n);

    printf("Unesi matricu:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (jeProst(mat[i][j]))
            {
                if (mat[i][j] > max)
                {
                    max = mat[i][j];
                }
                if (mat[i][j] < min && mat[i][j] != 1)
                {
                    min = mat[i][j];
                }
            }
        }
    }

    printf("Najmanji prost: %d, Najveci prost: %d\n", min, max);
    printf("Podmatrica:\n");
    podmatrica(mat, min, max, n);

    return 0;
}
