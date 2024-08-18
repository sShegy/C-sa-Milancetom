#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Osoba
{
    char ime[20];
    char grupa[20];
    int br;

    struct Osoba *left;
    struct Osoba *right;
} Osoba;

Osoba *nova_osoba(char ime[20], char grupa[20], int br)
{
    Osoba *nova = malloc(sizeof(Osoba));
    strcpy(nova->ime, ime);
    strcpy(nova->grupa, grupa);
    nova->br = br;

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

void ispis(Osoba *root)
{
    if (root != NULL)
    {
        ispis(root->left);
        printf("Ime: %10s, Grupa: %5s, Broj: %d\n", root->ime, root->grupa, root->br);
        ispis(root->right);
    }
}

void najbolji(Osoba *root, Osoba **tmp, int *max)
{
    if (root != NULL)
    {
        najbolji(root->right, tmp, max);
        if (root->br > *max)
        {
            *max = root->br;
            *tmp = root;
        }
        najbolji(root->left, tmp, max);
    }
}

void ispisi_grupe(Osoba *root)
{
    // Implement this part to gather group data, calculate averages, and sort by average score
    // Hint: You may want to store group information in a temporary structure or array for sorting
}

void oslobodi_stablo(Osoba *root)
{
    if (root == NULL)
        return;
    oslobodi_stablo(root->left);
    oslobodi_stablo(root->right);
    free(root);
}
Osoba *izbrisi(Osoba *root)
{
    if (root != NULL)
    {
        izbrisi(root->left);
        izbrisi(root->right);
        free(root);
    }
    return NULL;
}
int main()
{
    Osoba *root = NULL;
    int command, broj_poen;
    char naziv_fajla[20], ime[20], grupa[20];

    do
    {
        printf("Unesi commandu: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            break;
        case 1:
            printf("Unesi fajl: ");
            scanf("%s", naziv_fajla);
            FILE *fp = fopen(naziv_fajla, "r");
            if (fp == NULL)
            {
                printf("Pogresan AI!\n");
                break;
            }
            while (fscanf(fp, "%[^,],%[^,],%d\n", ime, grupa, &broj_poen) != EOF)
            {
                Osoba *osoba = nova_osoba(ime, grupa, broj_poen);
                root = dodaj_osobu(root, osoba);
            }
            fclose(fp);
            break;
        case 2:
            printf("--------------------------------------\n");
            ispis(root);
            printf("\n--------------------------------------\n");
            break;
        case 3:
        {
            Osoba *tmp = NULL;
            int max = INT_MIN;
            najbolji(root, &tmp, &max);
            if (tmp != NULL)
            {
                printf("Ime: %10s, Grupa: %5s, Broj: %d\n", tmp->ime, tmp->grupa, tmp->br);
            }
            else
            {
                printf("Nema osoba u bazi.\n");
            }
            break;
        }
        case 4:
            Osoba *tmp = NULL;
            int cb = 999;
            najbolji(root, &tmp, &cb); // Implement this function
            break;
        case 5:
            oslobodi_stablo(root);
            root = NULL;
            printf("Stablo je obrisano.\n");
            break;
        default:
            printf("Nepoznata komanda.\n");
            break;
        }
    } while (command != 0);

    return 0;
}
