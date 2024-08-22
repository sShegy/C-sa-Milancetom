#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
typedef struct Film
{
    char ime[20];
    int godina;
    int ocena;
    char zanr[20];

    struct Film *left;
    struct Film *right;

} Film;
Film *novi_film(char ime[20], int godina, int ocena, char zanr[20])
{
    Film *nova = malloc(sizeof(Film));
    strcpy(nova->ime, ime);
    strcpy(nova->zanr, zanr);
    nova->godina = godina;
    nova->ocena = ocena;
    nova->left = NULL;
    nova->right = NULL;
    return nova;
}
Film *dodaj(Film *root, Film *nova)
{
    if (root == NULL)
    {
        return nova;
    }
    else
    {
        if (strcmp(nova->zanr, root->zanr) < 0)
        {
            root->left = dodaj(root->left, nova);
        }
        else if (strcmp(nova->zanr, root->zanr) > 0)
        {
            root->right = dodaj(root->right, nova);
        }
        else
        {
            if (nova->godina < root->godina)
            {
                root->left = dodaj(root->left, nova);
            }
            else
            {
                root->right = dodaj(root->right, nova);
            }
        }
    }
    return root;
}
void ispisi(Film *root)
{
    if (root != NULL)
    {
        ispisi(root->left);
        printf("Ime: %10s,Godina: %d,Ocena: %d,Zanr: %5s\n", root->ime, root->godina, root->ocena, root->zanr);
        ispisi(root->right);
    }
    return;
}
Film *obrisi(Film *root)
{
    if (root != NULL)
    {
        obrisi(root->left);
        obrisi(root->right);
        free(root);
    }
    return NULL;
}

void najbolji(Film *root, Film **tm)
{
    if (root == NULL)
    {
        return ;
    }
    else
    {
        //  Ispis podataka o najbolje ocenjenom filmu. Ispisuju se naziv, godina premijere,
        // ocena i žanr. Ukoliko više filmova ima istu najbolju ocenu ispisati najstariji
        najbolji(root->left, tm);
        if (*tm == NULL || root->ocena > (*tm)->ocena || (root->ocena == (*tm)->ocena && (root->godina < (*tm)->godina)))
        {
            *tm = root;
        }
        najbolji(root->right, tm);
    }
    return;
}
int main()
{
    char ime[20];
    int godina;
    int ocena;
    char zanr[20];
    int command;
    FILE *fp;
    Film *root = NULL;
    Film *tmp = NULL;
    do
    {
        printf("Unesite komandu: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            printf("Exit");
            break;
        case 1:
            fp = fopen("g1.txt", "r");
            if (fp == NULL)
            {
                printf("Greska");

            } /// Forrest Gump,1994,88,Drama
            while (fscanf(fp, "%19[^,],%d,%d,%19[^\n]", ime, &godina, &ocena, zanr) != EOF)
            {
                Film *bilosta = novi_film(ime, godina, ocena, zanr);
                root = dodaj(root, bilosta);
            }
            fclose(fp);

            break;
        case 2:
            printf("-------------------------------------\n");
            ispisi(root);
            printf("\n-------------------------------------\n");
            break;
        case 3:
            najbolji(root, &tmp);
            printf("Ime: %10s,Godina: %d,Ocena: %d,Zanr: %5s\n", tmp->ime, tmp->godina, tmp->ocena, tmp->zanr);

            break;
        case 5:
            printf("-------------------------------------\n");
            root = obrisi(root);
            printf("\n-------------------------------------\n");
            break;
        default:
            break;
        }
    } while (command != 0);
}