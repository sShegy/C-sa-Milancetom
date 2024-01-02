#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int stepen(int a, int b)
{
    int res = 1;
    while (b)
    {
        res *= a;
        b--;
    }
    return res;
}

int gornji(int n, int i)
{
    int gornji = 0;
    gornji = i;
    // printf("ITERACIJA : %d , GORNJI : %d \n",i,gornji);
    return gornji;
}
int donji(int n, int i)
{
    int donji = 0;
    if (i % 2)
    {
        donji = i + 1;
    }
    else
    {
        donji = stepen((i + 1), 2);
    }
    // printf("ITERACIJA : %d , DONJI : %d \n",i,donji);
    return donji;
}

double rek(int n, int i)
{
    if (i == n)
    {
        return sqrt(gornji(n, i) * 1.0 / donji(n, i));
    }
    if (i % 2)
    {
        return sqrt(gornji(n, i) * 1.0 / donji(n, i) + (i + 1) * rek(n, i + 1));
    }
    else
    {
        return sqrt(gornji(n, i) * 1.0 / donji(n, i) + rek(n, i + 1));
    }
}

double iter(int n)
{
    double res = sqrt(gornji(n, n) * 1.0 / donji(n, n));
    for (int i = n - 1; i >= 1; i--)
    {
        if (i % 2)
        {
            res = sqrt(gornji(n, i) * 1.0 / donji(n, i) + (i + 1) * res);
        }
        else
        {
            res = sqrt(gornji(n, i) * 1.0 / donji(n, i) + res);
        }
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("REKURZIVNO : %lf \n", rek(n, 1));
    printf("ITERATIVNO : %lf \n", iter(n));
    return 0;
}