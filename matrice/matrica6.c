#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
// 2018 G4-Z2
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
int validCheck(int i, int j, int n)
{
    if (i >= 0 && i < n && j >= 0 && j < n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int minSusKol(int trenutnaKolona, int n, int matrix[n][n])
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (validCheck(i, trenutnaKolona - 1, n))
            {
                if (min > matrix[i][trenutnaKolona - 1])
                {
                    min = matrix[i][trenutnaKolona - 1];
                }
            }
            if (validCheck(i, trenutnaKolona + 1, n))
            {
                if (min > matrix[i][trenutnaKolona + 1])
                {
                    min = matrix[i][trenutnaKolona + 1];
                }
            }
        }
    }
    return min;
}
int maxSusVrsta(int trenutnaVrsta, int n, int matrix[n][n])
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (validCheck(trenutnaVrsta - 1, j, n))
            {
                if (max < matrix[trenutnaVrsta - 1][j])
                {
                    max = matrix[trenutnaVrsta - 1][j];
                }
            }
            if (validCheck(trenutnaVrsta + 1, j, n))
            {
                if (max < matrix[trenutnaVrsta + 1][j])
                {
                    max = matrix[trenutnaVrsta + 1][j];
                }
            }
        }
    }
    return max;
}
void doStuff(int n, int input[n][n], int output[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("za element %d , [%d] [%d], minSusKol je %d, a maxSusVrsta je %d\n", input[i][j], i, j, minSusKol(j, n, input),
                   maxSusVrsta(i, n, input));
            output[i][j] = abs(minSusKol(j, n, input) - maxSusVrsta(i, n, input));
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int matrica[n][n];
    int matricaB[n][n];
    loadMatrix(n, matrica);
    doStuff(n, matrica, matricaB);
    printMatrix(n, matricaB);
    return 0;
}
/*
3
 1 2 3
 4 5 6
 7 8 9

 */