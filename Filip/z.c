
#include <stdio.h>


/**
    Napisati rekurzivnu funkciju koja za uneti ceo broj n ispisuje sledecu figuru:

    Unos: 5
    Ispis:
    5
    4
    3
    2
    1
    1
    2
    3
    4
    5

*/


void ispis(int n) {
    // osnovni slucaj, kada naidjemo na nulu ne radimo nista
    if (n == 0)
        return;

    printf("%d\n", n);  // ispisemo n
    ispis(n-1);  // pozovemo da se resi problem za (n-1)
     // kada se vrati u ovu funkciju, opet ispisuje n

    return;
}


int main() {
    int n;
    scanf("%d", &n);

    ispis(n);
    return 0;
}