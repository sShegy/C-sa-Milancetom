#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Osoba
{
    char ime[20];
    char teretana[20];
    int sprave;
    int krsprave;
    struct Osoba *left;
    struct Osoba *right;
} Osoba;

Osoba *nova_osoba(char ime[], char teretana[], int sprave, int krsprave)
{
    Osoba *nova = (Osoba *)malloc(sizeof(Osoba));
    if (nova == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(nova->ime, ime);
    strcpy(nova->teretana, teretana);
    nova->sprave = sprave;
    nova->krsprave = krsprave;
    nova->left = nova->right = NULL;
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
        if (strcmp(nova->ime, root->ime) > 0)
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
        printf("Grad: %10s, Teretana: %s , Sprave: %d, Krsprave: %d\n", root->ime, root->teretana, root->sprave, root->krsprave);
        ispisi(root->right);
    }
}

void br_sprave(Osoba *root, int br)
{
    if (root == NULL)
    {
        return;
    }
    if (br < root->sprave)
    {
        printf("Grad: %10s, Teretana: %s , Sprave: %d, Krsprave: %d\n", root->ime, root->teretana, root->sprave, root->krsprave);
    }
    br_sprave(root->left, br);
    br_sprave(root->right, br);
}

char to_lower(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return c + 32;
    }
    return c;
}

void oblast(Osoba *root, char str1[])
{
    if (root != NULL)
    {
        char str2[20];
        strcpy(str2, root->ime);
        int matches = 1;
        for (int i1 = strlen(str1) - 1, i2 = strlen(str2) - 1; i1 >= 0 && i2 >= 0; i1--, i2--)
        {
            if (to_lower(str1[i1]) != to_lower(str2[i2]))
            {
                matches = 0;
                break;
            }
        }
        if (matches)
        {
            printf("Grad: %10s, Teretana: %s , Sprave: %d, Krsprave: %d\n", root->ime, root->teretana, root->sprave, root->krsprave);
        }
        oblast(root->left, str1);
        oblast(root->right, str1);
    }
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
    int command, sprave, krsprave, br_sprava;
    char nazivfajla[20], ime[20], teretana[20], tr[20];

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
            scanf("%s", nazivfajla);
            FILE *fp = fopen(nazivfajla, "r");
            if (fp == NULL)
            {
                printf("Pogresan!!\n");
                break;
            }
            /// Example: Stari grad-Ahilej-120-25
            while (fscanf(fp, "%[^-]-%[^-]-%d-%d\n", ime, teretana, &sprave, &krsprave) != EOF)
            {
                Osoba *osoba = nova_osoba(ime, teretana, sprave, krsprave);
                root = dodaj_osobu(root, osoba);
            }
            fclose(fp);
            break;
        case 2:
            printf("-----------------------\n");
            ispisi(root);
            printf("-----------------------\n");
            break;
        case 3:
            printf("Unesi broj: ");
            scanf("%d", &br_sprava);
            br_sprave(root, br_sprava);
            break;
        case 4:
            printf("Unesite ime oblasti: ");
            scanf("%s", tr);
            oblast(root, tr);
            break;
        case 5:
            printf("-----------------------\n");
            root = izbrisi(root);
            printf("-----------------------\n");
            break;
        default:
            printf("Unknown command!\n");
            break;
        }
    } while (command != 0);

    return 0;
}
