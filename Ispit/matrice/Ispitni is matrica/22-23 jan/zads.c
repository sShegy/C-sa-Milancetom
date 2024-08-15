#include <stdio.h>
#include <limits.h>
#include <math.h>
#define SIZE 100

int main()
{
    int w, h, n;
    int mat[SIZE][SIZE];

    printf("Unesi velicinu matrice: ");
    scanf("%d", &n);

    printf("Unesi velicinu W i H: ");
    scanf("%d %d", &w, &h);

    printf("Matrica:");
    printf("\n\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}