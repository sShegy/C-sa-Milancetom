#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int faktorijel(int arg)
{
    int x = arg;
    int res = 1;
    while (x)
    {
        res *= x;
        x--;
    }
    return res;
}

int lijevi(int n, int iteracija)
{
    int lijevi = 0;
    if (iteracija % 2)
    {
        lijevi = iteracija / 2 + 1;
    }
    else
    {
        lijevi = n - iteracija / 2 + 1;
    }
    printf("LIJEVI: iteracija: %d  lijevi :%d\n", iteracija, lijevi);
    return lijevi;
}

int gornji(int n, int iteracija)
{
    int gornji = 0;
    if (iteracija % 2)
    {
        gornji = n - iteracija / 2;
    }
    else
    {
        gornji = iteracija / 2;
    }
    printf("GORNJI: iteracija: %d  gornji :%d\n", iteracija, gornji);
    return gornji;
}

double rek(int i, int n)
{
    if (i == n)
    {
        return lijevi(n, i) + faktorijel(gornji(n, i));
    }
    else
    {
        return lijevi(n, i) * 1.0 + faktorijel(gornji(n, i)) / rek(i + 1, n);
    }
}

double iter(int n)
{
    double res;
    if (n % 2)
    {
        res = n / 2 + 1.0 + faktorijel(n / 2 + 1);
    }
    else
    {
        res = n / 2 + 1.0 + faktorijel(n / 2);
    }
    for (int i = n - 1; i >= 1; i--)
    {
        res = lijevi(n, i) + (faktorijel(gornji(n, i)) * 1.0 / res);
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("Rekurzivno : %lf\n", rek(1, n));
    printf("Iterativno : %lf\n", iter(n));
    return 0;
}