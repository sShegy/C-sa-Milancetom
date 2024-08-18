#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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
    for (int i = 2; i < broj; i++)
    {
        if (broj % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int podmatrice(int mat[50][50], int n, int smallest, int biggest)
{
    int smallestDimension = INT_MAX;
    int smallestX = 0;
    int smallestY = 0;
    int smallestI = 0;
    int smallestJ = 0;

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int i = 0; i <= n - x; i++)
            {
                for (int j = 0; j <= n - y; j++)
                {
                    int flag = 0;
                    for (int p = i; p < i + x; p++)
                    {
                        for (int q = j; q < j + y; q++)
                        {
                            if (mat[p][q] == smallest || mat[p][q] == biggest)
                            {
                                flag++;
                            }
                        }
                    }
                    if (flag == 2)
                    {
                        if (x * y < smallestDimension)
                        {
                            smallestDimension = x * y;
                            smallestX = x;
                            smallestY = y;
                            smallestI = i;
                            smallestJ = j;
                        }
                    }
                }
            }
        }
    }

    for (int p = smallestI; p < smallestI + smallestX; p++)
    {
        for (int q = smallestJ; q < smallestJ + smallestY; q++)
        {
            printf("%d ", mat[p][q]);
        }
        printf("\n");
    }

    return 0;
}

int main(void)
{

    int najveci = 0;
    int najmanji = INT_MAX;

    int n;
    printf("Unesi n: ");
    scanf("%d", &n);

    int mat[50][50];

    printf("Unesi matricu: \n");

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
            if (jeProst(mat[i][j]) == 1)
            {
                if (mat[i][j] > najveci)
                {
                    najveci = mat[i][j];
                }
                else if ((mat[i][j] < najmanji) && mat[i][j] != 1)
                {
                    najmanji = mat[i][j];
                }
            }
        }
    }

    podmatrice(mat, n, najmanji, najveci);

    // printf("najmanji = %d, najveci = %d\n", najmanji, najveci);
}
