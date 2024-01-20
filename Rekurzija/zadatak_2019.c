//
// Created by Korisnik on 1/4/2023.
//
#include <stdio.h>
#include <math.h>
int stepen(int i, int n)
{
    if (i <= n / 2)
    {
        return i;
    }
    if (i == n && n % 2)
        return 1;
    return i - n / 2;
}

int levo(int i, int n)
{
    if (i % 2)
        return pow(2 * n - i, stepen(i, n));
    return i;
}
int desno(int i, int n)
{
    if (!(i % 2))
        return pow(2 * n - i, stepen(i, n));
    return i;
}
double rek(int i, int n)
{

    if (i == n)
        return levo(i, n) + desno(i, n);
    return levo(i, n) + 1.0 * desno(i, n) / rek(i + 1, n);
}
double ite(int n)
{
    double sum = levo(n, n) + desno(n, n);
    for (int i = n - 1; i > 0; i--)
    {
        sum = levo(i, n) + desno(i, n) / sum;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("[REK] %f\n", rek(1, n));
    printf("[ITE] %f\n", ite(n));

    return 0;
}