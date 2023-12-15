#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int step(int n, int a)
{
    if (a == 0)
    {
        return 1;
    }

    return n * step(n, a - 1);
}

int main()
{
    int a, b;
    printf("Unesi broj: ");
    scanf("%d", &a);
    printf("Unesi stepen: ");
    scanf("%d", &b);
    printf("%d", step(a, b));

    return 0;
}
