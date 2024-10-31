#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Napisati program koji učitava niz od n celih brojeva,
// a zatim ispisuje samo elemente tog niza koji su
// deljivi sa 3.

int main()
{

    int n;
    int niz[50];

    printf("Unesi koliko ce da bude niz: ");
    scanf("%d", &n);
    printf("Ubaci elemente niza");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &niz[i]);
    }
    printf("Ispis brojeva koji su deljivi sa 3");
    for (int i = 0; i < n; i++)
    {
        if (niz[i] % 3 == 0)
        {
            printf("broj je: %d/n", niz[i]);
        }
    }
}