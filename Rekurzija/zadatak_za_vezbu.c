#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void loadMatrix(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int n, int matrix[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int reverse(int a)
{
    int x = a;
    int res = 0;
    while (x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
int validPos(int i, int j, int n)
{
    if (i >= 0 && i <= n - 1 && j >= 0 && j <= n - 1)
        return 1;
    return 0;
}

int maxParniSusjed(int i, int j, int n, int matrix[n][n])
{
    int arraySusjedi[4];
    int arrIndex = 0;
    int maxParni = 0;
    if (validPos(i + 1, j, n))
        arraySusjedi[arrIndex++] = matrix[i + 1][j];
    if (validPos(i - 1, j, n))
        arraySusjedi[arrIndex++] = matrix[i - 1][j];
    if (validPos(i, j + 1, n))
        arraySusjedi[arrIndex++] = matrix[i][j + 1];
    if (validPos(i, j - 1, n))
        arraySusjedi[arrIndex++] = matrix[i][j - 1];

    for (int i = 0; i < arrIndex; i++)
    {
        if (arraySusjedi[i] % 2 == 0)
        {
            if (arraySusjedi[i] > maxParni)
            {
                maxParni = arraySusjedi[i];
            }
        }
    }
    return maxParni;
}

int main()
{
    int n;
    scanf("%d", &n);
    int matrica[n][n];
    loadMatrix(n, matrica);
    int dijagonala1 = 0;
    int dijagonala2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            { // orginalana glavna dijagonala
                dijagonala1 = 10 * dijagonala1 + matrica[i][j];
            }
            if (i + j == n - 1)
            { // orginalna sporedna matrica
                dijagonala2 = 10 * dijagonala2 + matrica[i][j];
            }
        }
    }
    // postavljamo dijagonale u matricuB
    int matricaB[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matricaB[i][j] = dijagonala2 % 10;
                dijagonala2 /= 10;
            }
            else if (i + j == n - 1)
            {
                matricaB[i][j] = dijagonala1 % 10;
                dijagonala1 /= 10;
            }
            else
            {
                matricaB[i][j] = maxParniSusjed(i, j, n, matrica);
            }
        }
    }
    printMatrix(n, matricaB);
    return 0;
}