#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include this for INT_MIN and INT_MAX

#define N 100

void ucitajmatricu(int n, int m, int niz[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &niz[i][j]);
        }
    }
}

void ispisimatricu(int n, int m, int niz[N][N])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", niz[i][j]);
        }
        printf("\n");
    }
}

void uradi(int n, int m, int niz[N][N])
{
    int red[N] = {0}; // Initialize all elements to 0
    int kol[N] = {0}; // Initialize all elements to 0

    // Calculate row sums and column sums
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            red[i] += niz[i][j]; // Sum for rows
            kol[j] += niz[i][j]; // Sum for columns
        }
    }

    // Find and print the maximum row sum
    int max = INT_MIN; // Initialize to the minimum possible integer
    int c;
    for (int i = 0; i < n; i++)
    {
        if (red[i] > max)
        {
            max = red[i];
            c = i;
        }
    }
    printf("Najveca suma reda je: %d (%d)\n", c, max);

    // Find and print the maximum column sum
    int mx = INT_MIN; // Initialize to the minimum possible integer
    int t;
    for (int j = 0; j < m; j++)
    {
        if (kol[j] > mx)
        {
            mx = kol[j];
            t = j;
        }
    }
    printf("Najveca suma kolone je: %d (%d)\n", t, mx);
}

int main()
{
    int n, m;
    int niz[N][N];

    printf("Unesi velicinu niza: ");
    scanf("%d %d", &n, &m);

    ucitajmatricu(n, m, niz);
    printf("----------------\n");
    ispisimatricu(n, m, niz);
    printf("----------------\n");
    uradi(n, m, niz);

    return 0;
}
