#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// a) (10p) Učitavanje podataka. Podaci o osobama učitavaju se u binarno pretraživačko
// stablo. Stablo je alfabetski rastuće sortirano.
// b) (2p) Ispis svih osoba. Ispisati podatke o svim osoba sortirane alfabetski rastuće.
// c) (4p) Ispis najviše i najniže osobe. Ispisati podatke o najvišoj, a zazim o najnižoj osobi.
// d) (8p) Ispisati osobe lakše od određene težine. Korisnik unosi određenu težinu, na
// osnovu koje se ispisuju imena i težine svih osoba lakših od navedene vrednosti, sortirane
// po težini u nerastućem poretku.
// e) (1p) Izlaz iz programa i brisanje stabla

typedef struct Osoba
{
    char ime[20];
    int visina;
    int kg;
    struct Osoba *left;
    struct Osoba *right;
} Osoba;

Osoba *nova_osoba(char ime[], int visina, int kg)
{
    Osoba *nova = malloc(sizeof(Osoba));
    strcpy(nova->ime, ime);
    nova->visina = visina;
    nova->kg = kg;
    nova->left = NULL;
    nova->right = NULL;
    return nova;
}
Osoba *dodaj_osobu(Osoba *root, Osoba *nova)
{
    if (root == NULL)
    {
        return nova;
    }

    if (strcmp(nova->ime, root->ime) < 0)
    {
        root->left = dodaj_osobu(root->left, nova);
    }
    else
    {
        root->right = dodaj_osobu(root->right, nova);
    }
    return root;
}
void ispisi(Osoba *root)
{
    if (root != NULL)
    {
        ispisi(root->left);
        printf("Ime: %10s, Visina: %d , Kg: %d\n", root->ime, root->visina, root->kg);
        ispisi(root->right);
    }
    return;
}

void odredi(Osoba *root, char najniziim[], char najvisiim[], int *najnizi, int *najvisi)
{
    if (root == NULL)
        return;

    // Pronađi najnižu osobu
    if (root->visina < *najnizi)
    {
        strcpy(najniziim, root->ime);
        *najnizi = root->visina;
    }

    // Pronađi najvišu osobu
    if (root->visina > *najvisi)
    {
        strcpy(najvisiim, root->ime);
        *najvisi = root->visina;
    }

    // Nastavi pretragu u levom i desnom podstablu
    odredi(root->left, najniziim, najvisiim, najnizi, najvisi);
    odredi(root->right, najniziim, najvisiim, najnizi, najvisi);
}
Osoba*izbrisi(Osoba*root){
    if (root!=NULL)
    {
        izbrisi(root->left);
        izbrisi(root->right);
        free(root);
    }
    return NULL;
}

void tezina(Osoba *root, int *kg)
{
    if (root == NULL)
    {
        return;
    }
    
    if (*kg > root->kg)
    {
        printf("Ime: %s,Kg: %d\n", root->ime, root->kg);
    }
    tezina(root->right, kg);
    tezina(root->left, kg);
    
}
int main()
{
    Osoba *root = NULL;
    int command, visina, kg, tr_tezina;
    char ime[20], naziv_fajla[20];
    do
    {
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            printf("Exit\n");
            break;
        case 1:
            printf("Naziv fajla: ");
            scanf("%s", &naziv_fajla);
            FILE *fp = fopen(naziv_fajla, "r");
            if (fp == NULL)
            {
                printf("Pogresan!!");
            }
            /// Marko,182,79
            while (fscanf(fp, "%[^,],%d,%d\n", ime, &visina, &kg) != EOF)
            {
                Osoba *osobe = nova_osoba(ime, visina, kg);
                root = dodaj_osobu(root, osobe);
            }
            fclose(fp);
            break;
        case 2:
            printf("-----------------------------\n");
            ispisi(root);
            printf("\n-----------------------------\n");
            break;
        case 3:
        {
            char najnizi_ime[20] = "";
            char najvisi_ime[20] = "";
            int najvisi = -1;
            int najnizi = 9999;
            odredi(root, najnizi_ime, najvisi_ime, &najnizi, &najvisi);
            printf("Najniža osoba: %s, Visina: %d\n", najnizi_ime, najnizi);
            printf("Najviša osoba: %s, Visina: %d\n", najvisi_ime, najvisi);
        }
        break;
        case 4:
            printf("Koja tezina: ");
            scanf("%d", &tr_tezina);
            tezina(root,&tr_tezina);
            break;
        case 5:
            root=izbrisi(root);
            break;
        default:
            break;
        }
    } while (command != 0);
}