#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 99

int min_kolona(int mat[N][N], int n, int m, int i, int j)
{
    int min_val = INT_MAX;

    if (j - 1 >= 0)
    {
        for (int k = 0; k < n; k++)
        {
            if (mat[k][j - 1] < min_val)
            {
                min_val = mat[k][j - 1];
            }
        }
    }

    if (j + 1 < m)
    {
        for (int k = 0; k < n; k++)
        {
            if (mat[k][j + 1] < min_val)
            {
                min_val = mat[k][j + 1];
            }
        }
    }

    return min_val;
}

int max_vrsta(int mat[N][N], int n, int m, int i, int j)
{
    int max_val = INT_MIN;

    if (i - 1 >= 0)
    {
        for (int k = 0; k < m; k++)
        {
            if (mat[i - 1][k] > max_val)
            {
                max_val = mat[i - 1][k];
            }
        }
    }

    if (i + 1 < n)
    {
        for (int k = 0; k < m; k++)
        {
            if (mat[i + 1][k] > max_val)
            {
                max_val = mat[i + 1][k];
            }
        }
    }

    return max_val;
}

void uradi(int mat[N][N], int mat2[N][N], int n, int m)
{
    // Element u novoj matrici jednak je apsolutnoj vrednosti razlike
    // minimalnog elementa iz susednih kolona i maksimalnog elementa
    // iz susednih vrsta odgovarajućeg elementa iz ulazne matrice.
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int min_col = min_kolona(mat, n, m, i, j);
            int max_row = max_vrsta(mat, n, m, i, j);
            mat2[i][j] = abs(min_col - max_row);
        }
    }
}

int main()
{
    int n, m;
    int mat[N][N];
    int mat2[N][N];

    printf("Unesi dimenzije matrice: ");
    scanf("%d %d", &n, &m);

    printf("Unesi elemente matrice:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    uradi(mat, mat2, n, m);

    printf("Nova matrica:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }

    return 0;
}
