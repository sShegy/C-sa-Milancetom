#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int donji(int n, int i)
{
    if (i % 2)
    {
        return pow((n - i / 2), 2);
    }
    else
    {
        return pow((i / 2), 2);
    }
}

int gornji(int n, int i)
{
    if (i % 2)
    {
        return i / 2 + 1;
    }
    else
    {
        return n - i / 2 + 1;
    }
}

double rek(int n, int i)
{
    if (i == n)
    {
        return sqrt(gornji(n, i) * 1.0 / donji(n, i));
    }
    return sqrt(gornji(n, i) * 1.0 / donji(n, i) + rek(n, i + 1));
}

double iter(int n)
{
    double sum = sqrt(gornji(n, n) * 1.0 / donji(n, n));
    for (int i = n - 1; i >= 1; i--)
    {
        sum = sqrt(gornji(n, i) * 1.0 / donji(n, i) + sum);
    }
    return sum;
}

int main()
{
    int n, i = 1;
    printf("Unesi broj: ");
    scanf("%d", &n);
    printf("REK je: %lf\n", rek(n, i));
    printf("ITER je: %lf\n", iter(n));
    return 0;
}
