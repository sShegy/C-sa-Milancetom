#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Osoba {
    char ime[20];
    char naziv_dijete[20];
    int kg;

    struct Osoba *left;
    struct Osoba *right;
} Osoba;


Osoba* napravi_osobu(char ime[], char naziv_dijete[], int kg) {
    Osoba *nova_osoba = malloc(sizeof(Osoba));

    strcpy(nova_osoba->ime, ime);
    strcpy(nova_osoba->naziv_dijete, naziv_dijete);
    nova_osoba->kg = kg;

    nova_osoba->left = NULL;
    nova_osoba->right = NULL;

    return nova_osoba;
}


Osoba* dodaj_u_stablo_sortirano(Osoba *root, Osoba *nova_osoba) {
    if (root == NULL)
        return nova_osoba;

    // printf("%s %s %d\n", root->naziv_dijete, nova_osoba->naziv_dijete, strcmp(root->naziv_dijete, nova_osoba->naziv_dijete));
    if (strcmp(root->naziv_dijete, nova_osoba->naziv_dijete) >= 0) {
        root->left = dodaj_u_stablo_sortirano(root->left, nova_osoba);
    }
    else {
        root->right = dodaj_u_stablo_sortirano(root->right, nova_osoba);
    }

    return root;
}


void ispisi_osobe(Osoba *root) {
    if (root == NULL)
        return;

    ispisi_osobe(root->left);
    printf("dijeta: %s, ime: %s, kg: %d\n", root->naziv_dijete, root->ime, root->kg);
    ispisi_osobe(root->right);
}


Osoba* obrisi_celo_stablo(Osoba *root) {
    if (root != NULL) {
        obrisi_celo_stablo(root->left);
        obrisi_celo_stablo(root->right);
        free(root);
    }

    return NULL;
}


void najefikasnija_dijeta(Osoba *root, int *suma_kg, int *br_dijeta, double *max, char naziv[], char max_naziv[]) {
    if (root == NULL)
        return;
    
    najefikasnija_dijeta(root->left, suma_kg, br_dijeta, max, naziv, max_naziv);
    // printf("dijeta: %s\n", root->naziv_dijete);

    if (*max == -1) {  // prva dijeta
        *max = 0;
        strcpy(naziv, root->naziv_dijete);
    }

    if (strcmp(naziv, root->naziv_dijete) != 0) {
        double efikasnost = 1.0 * (*suma_kg) / (*br_dijeta);

        printf("racunanje dijete: %s %d %d %.2lf\n", naziv, *suma_kg, *br_dijeta, efikasnost);

        if (efikasnost > *max) {
            *max = efikasnost;
            strcpy(max_naziv, root->naziv_dijete);
        }

        *suma_kg = root->kg;
        *br_dijeta = 1;
        strcpy(naziv, root->naziv_dijete);
    } else {
        (*suma_kg) += root->kg;
        (*br_dijeta)++;
    }

    najefikasnija_dijeta(root->right, suma_kg, br_dijeta, max, naziv, max_naziv);
}


void ispisi_osobe_sa_imenom(Osoba *root, char ime[]) {
    if (root == NULL)
        return;

    char ime_osobe[20];
    strcpy(ime_osobe, root->ime);

    int len = strlen(ime_osobe);
    for (int i = 0; i < len; i++) {
        if (ime_osobe[i] >= 'A' && ime_osobe[i] <= 'Z')
            ime_osobe[i] += 32;
    }

    if (strstr(ime_osobe, ime) != NULL)
        printf("dijeta: %s, ime: %s, kg: %d\n", root->naziv_dijete, root->ime, root->kg);

    ispisi_osobe_sa_imenom(root->left, ime);
    ispisi_osobe_sa_imenom(root->right, ime);
}


int main() {
    Osoba *root = NULL;
    FILE *fp;

    char naziv_fajla[20];

    int command;
    char ime[20];
    char naziv_dijete[20];
    int kg;

    char max_naziv[20] = "";
    char naziv[20] = "";
    double max = -1;
    int suma_kg = 0;
    int br_dijeta = 0;
    double efikasnost;
    int len;

    do {
        scanf("%d", &command);
        switch (command) {
            case 0:
                break;
            case 1:
                scanf("%s", naziv_fajla);
                fp = fopen(naziv_fajla, "r");

                if (fp == NULL) {
                    printf("Greska pri citanju fajla\n");
                    return -1;
                }

                while (fscanf(fp, "%[^,],%[^,],%d\n", ime, naziv_dijete, &kg) != EOF) {
                    Osoba *nova_osoba = napravi_osobu(ime, naziv_dijete, kg);
                    root = dodaj_u_stablo_sortirano(root, nova_osoba);
                }

                break;
            case 2:
                printf("-----------------------------------------\n");
                ispisi_osobe(root);
                printf("-----------------------------------------\n");
                break;
            case 3:
                strcpy(max_naziv, "");
                strcpy(naziv, "");
                max = -1;
                suma_kg = 0;
                br_dijeta = 0;

                najefikasnija_dijeta(root, &suma_kg, &br_dijeta, &max, naziv, max_naziv);
                efikasnost = 1.0 * suma_kg / br_dijeta;

                printf("racunanje dijete: %s %d %d %.2lf\n", naziv, suma_kg, br_dijeta, efikasnost);
                if (efikasnost > max) {
                    max = efikasnost;
                    strcpy(max_naziv, naziv);
                }

                printf("Najefikasnija dijeta: %s, kg: %.2lf\n", max_naziv, max);
                break;

            case 4:
                scanf("%s", ime);
                len = strlen(ime);
                for (int i = 0; i < len; i++) {
                    if (ime[i] >= 'A' && ime[i] <= 'Z')
                        ime[i] += 32;
                }
                ispisi_osobe_sa_imenom(root, ime);
                break;
            case 5:
                root = obrisi_celo_stablo(root);
                break;
            default:
                printf("Pogresna komanda\n");
        }


    } while (command != 0);

    return 0;
}