#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int faktorijal(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * faktorijal(n - 1);
}

int main()
{
    int a;
    printf("Unesi broj: ");
    scanf("%d", &a);
    printf("%d", faktorijal(a));

    return 0;
}