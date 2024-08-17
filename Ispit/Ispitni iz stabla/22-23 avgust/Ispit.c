#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Struktura za filmove (naziv filma, godinu premijere, ocenu i žanr)
typedef struct Osoba
{
    char ime[20];
    int godina;
    int ocena;
    char zanr[20];
    struct Osoba *left;
    struct Osoba *right;
} Osoba;

Osoba *nova_osoba(char ime[], int godina, int ocena, char zanr[])
{
    Osoba *nova = malloc(sizeof(Osoba));
    strcpy(nova->ime, ime);
    strcpy(nova->zanr, zanr);
    nova->godina = godina;
    nova->ocena = ocena;
    nova->left = NULL;
    nova->right = NULL;
    return nova;
}

// Dodavanje filma u binarno pretraživačko stablo sortirano po žanru i godini
Osoba *dodaj_osobu(Osoba *root, Osoba *nova)
{
    if (root == NULL)
    {
        return nova;
    }

    int genre_compare = strcmp(nova->zanr, root->zanr);

    if (genre_compare < 0)
    {
        root->left = dodaj_osobu(root->left, nova);
    }
    else if (genre_compare > 0)
    {
        root->right = dodaj_osobu(root->right, nova);
    }
    else
    {
        if (nova->godina < root->godina)
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

// Ispis svih filmova u stablu
void ispisi(Osoba *root)
{
    if (root != NULL)
    {
        ispisi(root->left);
        printf("Film: %s, Godina: %d, Ocena: %d, Zanr: %s\n", root->ime, root->godina, root->ocena, root->zanr);
        ispisi(root->right);
    }
}

// Ispis podataka o najbolje ocenjenom filmu
void ispisi_najbolji(Osoba *root, Osoba **najbolji)
{
    if (root == NULL)
    {
        return;
    }

    // Traverse the left subtree
    ispisi_najbolji(root->left, najbolji);

    // Update the best movie if this one is better
    if (*najbolji == NULL || root->ocena > (*najbolji)->ocena ||
        (root->ocena == (*najbolji)->ocena && root->godina < (*najbolji)->godina))
    {
        *najbolji = root;
    }

    // Traverse the right subtree
    ispisi_najbolji(root->right, najbolji);
}

// Ispis filmova u opadajućem poretku prema oceni
// Ispis filmova u opadajućem poretku prema oceni
void ispisi_opadajuce(Osoba *root, int oc)
{
    if (root == NULL)
    {
        return;
    }

    ispisi_opadajuce(root->right, oc);

    if (oc >= root->ocena)
    {
        oc = root->ocena;
        printf("Film: %s, Godina: %d, Ocena: %d, Zanr: %s\n", root->ime, root->godina, root->ocena, root->zanr);
    }

    ispisi_opadajuce(root->left, oc);
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
    int command, godina, ocena, taj;
    char file[20], ime[20], zanr[20];

    do
    {
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            break;
        case 1:
            printf("Ime fajla: ");
            scanf("%s", file);
            FILE *fp = fopen(file, "r");
            if (fp == NULL)
            {
                printf("Pogresan file\n");
                break;
            }
            // Primer linije: Forrest Gump,1994,88,Drama
            while (fscanf(fp, "%[^,],%d,%d,%[^\n]", ime, &godina, &ocena, zanr) != EOF)
            {
                Osoba *osoba = nova_osoba(ime, godina, ocena, zanr);
                root = dodaj_osobu(root, osoba);
            }
            fclose(fp);
            break;
        case 2:
            printf("---------------------------------\n");
            ispisi(root);
            printf("---------------------------------\n");
            break;
        case 3:
        {
            Osoba *najbolji = NULL;
            ispisi_najbolji(root, &najbolji);
            if (najbolji != NULL)
            {
                printf("Najbolje ocenjen film:\n");
                printf("Naziv: %s\n", najbolji->ime);
                printf("Godina premijere: %d\n", najbolji->godina);
                printf("Ocena: %d\n", najbolji->ocena);
                printf("Zanr: %s\n", najbolji->zanr);
            }
            else
            {
                printf("Nema filmova u bazi.\n");
            }
            break;
        }
        case 4:
            taj = 999;
            printf("---------------------------------\n");
            ispisi_opadajuce(root, taj);
            printf("---------------------------------\n");
            break;
        case 5:
            printf("---------------------------------\n");
            root = izbrisi(root);
            printf("---------------------------------\n");
            break;
        default:
            printf("Nepoznata komanda.\n");
            break;
        }
    } while (command != 0);

    return 0;
}
