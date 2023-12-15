#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int step(int n)
{
    if (n==0)
    {
        return 0;
    }

    return n%10+step(n/10);
}

int main()
{
    int a, b;
    printf("Unesi broj: ");
    scanf("%d", &a);
    printf("%d", step(a));

    return 0;
}
