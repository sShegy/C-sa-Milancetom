#define SIZE 50

/*
1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
*/

#include <stdio.h>
#include <math.h>
#include <limits.h>

void podmatrice(int mat[SIZE][SIZE], int n)
{
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
                            printf("%d ", mat[p][q]);
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
            }
        }
    }
}

int main()
{

    int n;
    scanf("%d", &n);

    int mat[SIZE][SIZE];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    podmatrice(mat, n);

    return 0;
}