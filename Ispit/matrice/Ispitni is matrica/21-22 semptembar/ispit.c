#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define N 99

/*
8     7     2     6     3     9
3     9     5     8     4     1
4     7     2     9     5     3
12   9     4     10   7    15
8     6     3     10   4     5
11   6     8     10   5     3
*/

int jeProst(int broj)
{
    if (broj < 2)
    {
        return 0;
    }

    for (int i = 2; i <= sqrt(broj); i++)
    {
        if (broj % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

void podmatrica(int mat[N][N], int n)
{
    int tr = 0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int i = 0; i <= n - x; i++)
            {
                for (int j = 0; j <= n - y; j++)
                {
                    for (int p = i; p < i + x; p++)
                    {
                        for (int q = j; q < j + y; q++)
                        {
                            if (jeProst(mat[p][q])==0)
                            {
                                tr++;
                            }
                        }
                    }
                    if (tr > 3)
                    {
                        for (int e = i; e < i + x; e++)
                        {
                            for (int o = j; o < j + y; o++)
                            {
                                printf("%d ", mat[e][o]);
                            }
                            printf("\n");
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    int mat[N][N];
    printf("Unesi n: ");
    scanf("%d", &n);

    printf("Unesite elemente matrice:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    podmatrica(mat, n);
    return 0;
}
