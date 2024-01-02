#include <stdio.h>

int main()
{
    int n, broj = 0;
    printf("Unesi broj: ");
    scanf("%d", &n);
    int mat[50][50];
    int x = n;
    while (n)
    {
        broj++;
        n /= 10;
    }
    for (int i = broj - 1; i >= 0; i--)
    {
        mat[0][i] = x % 10;
        x /= 10;
    }
    for (int i = 1; i < broj; i++)
    {
        for (int j = 0; j < broj; j++)
        {
            mat[i][j] = (mat[i - 1][j] + 1) % 10;
        }
    }

    for (int i = 0; i < broj; i++)
    {
        for (int j = 0; j < broj; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}