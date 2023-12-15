#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int step(int n)
{
    if (n == 2 || n == 1)
    {
        return 1;
    }

    return step(n - 1) + step(n - 2);
}

int main()
{
    int a, b;
    printf("Unesi broj: ");
    scanf("%d", &a);
    printf("%d", step(a));

    return 0;
}
