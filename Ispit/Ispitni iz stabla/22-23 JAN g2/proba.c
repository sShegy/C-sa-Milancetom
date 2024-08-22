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
    else
    {
        if (strcmp(nova->ime, root->ime) < 0)
        {
            root->left = dodaj_osobu(root->left, nova);
        }
        else
        {
            root->right = dodaj_osobu(root->right, nova);
        }
    }
    return root;
}

void ispisi(Osoba *root)
{
    if (root != NULL)
    {
        ispisi(root->left);
        printf("Ime: %10s, Grupa: %5s, Br: %d\n", root->ime, root->grupa, root->br);
        ispisi(root->right);
    }
}

void najveci(Osoba *root, Osoba **tmp, int *max)
{
    if (root != NULL)
    {
        najveci(root->left, tmp, max);
        if (root->br > *max)
        {
            *max = root->br;
            *tmp = root;
        }
        najveci(root->right, tmp, max);
    }
}

int main()
{
    Osoba *root = NULL;
    int command;
    char naziv_fajla[20];
    char ime[20];
    char grupa[20];
    int br;
    Osoba *tmp = NULL;
    int max;

    do
    {
        printf("Unesi komandu: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            printf("Exit!\n");
            break;
        case 1:
            printf("Ime fajla: ");
            scanf("%s", naziv_fajla); // No need for '&' with string
            FILE *fp = fopen(naziv_fajla, "r");
            if (fp == NULL)
            {
                printf("Pogresan file!\n");
                break;
            }
            while (fscanf(fp, "%[^,],%[^,],%d\n", ime, grupa, &br) != EOF)
            {
                Osoba *osobe = nova_osoba(ime, grupa, br);
                root = dodaj_osobu(root, osobe);
            }
            fclose(fp);
            break;
        case 2:
            printf("--------------------------------------------------------\n");
            ispisi(root);
            printf("\n--------------------------------------------------------\n");
            break;
        case 3:
            max = INT_MIN;
            tmp = NULL;
            najveci(root, &tmp, &max);
            if (tmp != NULL)
            {
                printf("Ime: %10s, Grupa: %5s, Br: %d\n", tmp->ime, tmp->grupa, tmp->br);
            }
            else
            {
                printf("Stablo je prazno.\n");
            }
            break;
        default:
            printf("Nepoznata komanda!\n");
            break;
        }
    } while (command != 0);

    return 0;
}
