#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Function to load an n x n matrix from standard input
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

// Function to print an n x n matrix to standard output
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

// Function to check if indices are within bounds of the matrix
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

// Function to find the minimum value in the adjacent columns of the given column
int minSusKol(int trenutnaKolona, int n, int matrix[n][n])
{
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
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
    return min;
}

// Function to find the maximum value in the adjacent rows of the given row
int maxSusVrsta(int trenutnaVrsta, int n, int matrix[n][n])
{
    int max = INT_MIN;
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
    return max;
}

// Function to process the input matrix and store the result in the output matrix
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
    scanf("%d", &n); // Read the size of the matrix
    int matrica[n][n];
    int matricaB[n][n];
    loadMatrix(n, matrica); // Load the matrix
    doStuff(n, matrica, matricaB); // Process the matrix
    printMatrix(n, matricaB); // Print the resulting matrix
    return 0;
}
