#include <stdio.h>

int fibonacci(int x)
{
    if (x == 1 || x == 2)
    {
        return 1;
    }
    int prev = 1;
    int tren = 1;
    int fibo = 0;
    for (int i = 3; i <= x; i++)
    {
        fibo = prev + tren;
        prev = tren;
        tren = fibo;
    }
    return fibo;
}

int levi(int i)
{
    return fibonacci(i);
}

int gornji(int i, int n)
{
    return (3 * n) - ((i - 1) * 3);
}

int znak(int i)
{
    return (i % 2) ? 1 : -1;
}

double rek(int i, int n)
{
    if (i == n)
    {
        return levi(i);
    }
    return levi(i) + znak(i) * gornji(i, n) / rek(i + 1, n);
}
double ite(int n)
{
    double sum = levi(n);
    for (int i = n - 1; i >= 1; i--)
    {
        sum = levi(i) + znak(i) * gornji(i, n) / sum;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("REK %f\n", rek(1, n));
    printf("ITER %f\n", ite(n));

    return 0;
}