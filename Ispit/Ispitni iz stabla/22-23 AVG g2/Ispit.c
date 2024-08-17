#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct Osoba
{
    /// naziv programa, naziv grada i cenu studija.
    char ime[20];
    char grad[20];
    int cena;

    struct Osoba *left;
    struct Osoba *right;
} Osoba;

Osoba *nova_osoba(char ime[20], char grad[20], int cena)
{
    Osoba *nova = malloc(sizeof(Osoba));
    strcpy(nova->ime, ime);
    strcpy(nova->grad, grad);
    nova->cena = cena;

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
        if (strcmp(nova->grad, root->grad) < 0)
        {
            root->left = dodaj_osobu(root->left, nova);
        }
        else if (strcmp(nova->grad, root->grad) > 0)
        {
            root->right = dodaj_osobu(root->right, nova);
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
    }
    return root;
}

void ispisi(Osoba *root)
{
    if (root != NULL)
    {
        ispisi(root->left);
        printf("Program: %10s, Grad: %5s, Cena: %d\n", root->ime, root->grad, root->cena);
        ispisi(root->right);
    }
}

void najveca_cena(Osoba *root, Osoba **tmp)
{
    if (root == NULL)
    {
        return;
    }

    if (*tmp == NULL || root->cena > (*tmp)->cena || (root->cena == (*tmp)->cena && strcmp(root->grad, (*tmp)->grad) < 0))
    {
        *tmp = root;
    }

    najveca_cena(root->left, tmp);
    najveca_cena(root->right, tmp);
}

void ispis_programa(Osoba *root, char pr[20])
{
    int totalCena = 0;
    int count = 0;

    if (root != NULL)
    {
        char str[20];
        strcpy(str, root->ime);
        int len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
        }

        if (strstr(str, pr) != NULL)
        {
            printf("Program: %10s, Grad: %5s, Cena: %d\n", root->ime, root->grad, root->cena);
            totalCena += root->cena;
            count++;
        }

        ispis_programa(root->left, pr);
        ispis_programa(root->right, pr);
    }

    if (count > 0)
    {
        printf("Srednja vrednost cene: %.2f\n", (float)totalCena / count);
    }
    
    
    
}

void oslobodi_memoriju(Osoba *root)
{
    if (root != NULL)
    {
        oslobodi_memoriju(root->left);
        oslobodi_memoriju(root->right);
        free(root);
    }
}
Osoba* izbrisi(Osoba*root){
    if (root!=NULL)
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
    int command, len;
    char naziv_fajl[20];
    char ime[20], pr[20];
    char grad[20];
    int cena;

    do
    {
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            printf("Exit!\n");
            oslobodi_memoriju(root);
            break;
        case 1:
            printf("Enter file name: ");
            scanf("%s", naziv_fajl);
            FILE *fp = fopen(naziv_fajl, "r");
            if (fp == NULL)
            {
                printf("Neuspešno otvaranje fajla!\n");
            }
            else
            {
                while (fscanf(fp, "%[^,],%[^,],%d\n", ime, grad, &cena) != EOF)
                {
                    Osoba *osobe = nova_osoba(ime, grad, cena);
                    root = dodaj_osobu(root, osobe);
                }
                fclose(fp);
            }
            break;
        case 2:
            printf("---------------------------------------------------------------------------\n");
            ispisi(root);
            printf("\n---------------------------------------------------------------------------\n");
            break;
        case 3:
        {
            Osoba *tmp = NULL;
            najveca_cena(root, &tmp);
            if (tmp != NULL)
            {
                printf("Najskuplji program:\nProgram: %10s, Grad: %5s, Cena: %d\n", tmp->ime, tmp->grad, tmp->cena);
            }
            else
            {
                printf("Nema programa u stablu.\n");
            }
            break;
        }
        case 4:
            printf("Unesi program: ");
            scanf("%s", pr);
            len = strlen(pr);
            for (int i = 0; i < len; i++)
            {
                if (pr[i] >= 'A' && pr[i] <= 'Z')
                {
                    pr[i] += 32;
                }
            }
            ispis_programa(root, pr);
            break;
        case 5:
            printf("---------------------------------------------------------------------------\n");
            root=izbrisi(root);
            printf("\n---------------------------------------------------------------------------\n");
            break;
        default:
            printf("Nepoznata komanda!\n");
            break;
        }
    } while (command != 0);

    return 0;
}
