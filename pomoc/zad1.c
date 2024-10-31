#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{

    int a, c = 0, h;
    printf("Unesi neki broj: ");
    scanf("%d", &a);
    int b = a;
    h = b;
    int j = a;
    while (a != 0)
    {
        c++;
        a /= 10;
    }

    // c=5
    int prvacifra = c--;

    int prvacifra1 = h / pow(prvacifra,10);
    printf("jdsad %d",prvacifra1);
    int poslednja_cifra = b % 10;

    int ostatak = (j / 10) % ((c - 2) * 10);
    printf("dada %d", ostatak);
    int resenje = (poslednja_cifra * (prvacifra * 10)) + ostatak;
    resenje = resenje * 10 + prvacifra1;

    printf("Resenje je %d", resenje);

    return 0;
}