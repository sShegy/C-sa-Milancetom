#include <stdio.h>
#include <string.h>

// Funkcija za ispisivanje palindromskog podniza
void ispisiPalindromskiPodniz(char *niz, int pocetak, int kraj) {
    for (int i = pocetak; i <= kraj; i++) {
        printf("%c", niz[i]);
    }
}

// Funkcija za pronalaženje najdužeg palindromskog podniza
void najduziPalindromskiPodniz(char *niz, int duzina) {
    int pocetak = 0;  // Početak najdužeg palindromskog podniza
    int maxDuzina = 1;  // Trenutna maksimalna dužina palindromskog podniza

    // Tablica za dinamičko programiranje za praćenje palindromskih podniza
    int tabela[duzina][duzina];
    memset(tabela, 0, sizeof(tabela)); // Inicijalizacija tablice na 0

    // Svi pojedinačni znakovi su palindromski podnizi
    for (int i = 0; i < duzina; i++) {
        tabela[i][i] = 1;
    }

    // Provjeravamo palindromske podnize dužine 2
    for (int i = 0; i < duzina - 1; i++) {
        if (niz[i] == niz[i + 1]) {
            tabela[i][i + 1] = 1;
            pocetak = i;
            maxDuzina = 2;
        }
    }

    // Provjeravamo palindromske podnize duže od 2
    for (int trenDuzina = 3; trenDuzina <= duzina; trenDuzina++) {
        for (int i = 0; i < duzina - trenDuzina + 1; i++) {
            int j = i + trenDuzina - 1; // Krajnji indeks trenutnog podniza

            // Provjeravamo da li su krajevi trenutnog podniza isti i da li je unutrašnjost palindromski podniz
            if (tabela[i + 1][j - 1] && niz[i] == niz[j]) {
                tabela[i][j] = 1;

                // Ako je trenutni palindromski podniz duži od prethodnih, ažuriramo pocetak i maxDuzina
                if (trenDuzina > maxDuzina) {
                    pocetak = i;
                    maxDuzina = trenDuzina;
                }
            }
        }
    }

    // Ispisivanje najdužeg palindromskog podniza
    printf("Najduzi palindromski podniz: ");
    ispisiPalindromskiPodniz(niz, pocetak, pocetak + maxDuzina - 1);
    printf("\n");
}

int main() {
    char niz[] = "abacdfgdcaba";
    int duzina = strlen(niz);

    najduziPalindromskiPodniz(niz, duzina);

    return 0;
}
