#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void funk(int n)
{
    if (n == 0)
    {
        return;
    }
    printf("%d\n", n);
    funk(n - 1);
    printf("%d\n", n);
}

int main()
{
    int a;
    printf("Unesi broj: ");
    scanf("%d", &a);
    funk(a);

    return 0;
}