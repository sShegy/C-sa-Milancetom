#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 99

int jeProst(int broj)
{
    for (int i = 2; i < broj; i++)
    {
        if (broj % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int podmatrice(int mat[SIZE][SIZE], int w, int h, int n)
{
    int tr=0;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if ((w == x && h == y) || (w == y && h == x))
            {
                for (int i = 0; i <= n - x; i++)
                {
                    int flag = 1;
                    for (int j = 0; j <= n - y; j++)
                    {
                        for (int p = i; p < i + x; p++)
                        {
                            for (int q = j; q < j + y; q++)
                            {
                                if (jeProst(mat[p][q]) != 1)
                                {
                                    flag = 0;
                                }
                            }
                        }
                        if (flag)
                        {
                            tr++;
                        }
                    }
                }
            }
            else
            {
                continue;
            }
        }
    }
    return tr;
}

int main()
{
    int w, h, n;
    int mat[SIZE][SIZE];
    printf("Unesi w, i h: ");
    scanf("%d %d", &w, &h);

    printf("Unesi dimenziju matrice: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Broj je: %d", podmatrice(mat, w, h, n));

    
    return 0;
}