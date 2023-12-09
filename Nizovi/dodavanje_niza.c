#include <stdio.h>

int main() {
    int prvi_niz[] = {1, 2, 5};
    int drugi_niz[] = {4, 5, 6};

    int velicina_prvog_niza = sizeof(prvi_niz) / sizeof(prvi_niz[0]);
    int velicina_drugog_niza = sizeof(drugi_niz) / sizeof(drugi_niz[0]);

    // Alociranje prostora za rezultatni niz
    int rezultat[velicina_prvog_niza + velicina_drugog_niza];

    // Kopiranje elemenata prvog niza u rezultatni niz
    for (int i = 0; i < velicina_prvog_niza; i++) {
        rezultat[i] = prvi_niz[i];
    }

    // Kopiranje elemenata drugog niza u rezultatni niz
    for (int i = 0; i < velicina_drugog_niza; i++) {
        rezultat[velicina_prvog_niza + i] = drugi_niz[i];
    }

    // Ispis rezultatnog niza
    printf("Rezultatni niz:\n");
    for (int i = 0; i < velicina_prvog_niza + velicina_drugog_niza; i++) {
        printf("%d ", rezultat[i]);
    }

    return 0;
}
