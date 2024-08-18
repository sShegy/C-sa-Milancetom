#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 99

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
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int i = 0; i <= n - x; i++)
            {
                for (int j = 0; j <= n - y; j++)
                {
                    int tr = 0; // Reset the count for each submatrix

                    // Count non-prime numbers in the current submatrix
                    for (int p = i; p < i + x; p++)
                    {
                        for (int q = j; q < j + y; q++)
                        {
                            if (jeProst(mat[p][q]) == 0)
                            {
                                tr++;
                            }
                        }
                    }

                    // If more than 3 non-prime numbers, print the submatrix
                    if (tr > 3)
                    {
                        printf("Submatrica (%d x %d) starting at (%d, %d):\n", x, y, i, j);
                        for (int e = i; e < i + x; e++)
                        {
                            for (int o = j; o < j + y; o++)
                            {
                                printf("%d ", mat[e][o]);
                            }
                            printf("\n");
                        }
                        printf("\n");
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
