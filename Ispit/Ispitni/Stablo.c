#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Osoba
{
    char ime[20];
    char dijeta[20];
    int kg;
    struct Osoba *left;
    struct Osoba *right;
} Osoba;

Osoba *nova_osoba(char ime[], char dijeta[], int kg)
{
    Osoba *nova = malloc(sizeof(Osoba));
    strcpy(nova->dijeta, dijeta);
    strcpy(nova->ime, ime);
    nova->kg = kg;
    nova->left = NULL;
    nova->right = NULL;

    return nova;
}

Osoba *dodaj_osobu(Osoba *root, Osoba *novi)
{
    if (root == NULL)
    {
        return novi;
    }
    else if (strcmp(novi->dijeta, root->dijeta) < 0)
    {
        root->left = dodaj_osobu(root->left, novi);
    }
    else
    {
        root->right = dodaj_osobu(root->right, novi);
    }
    return root;
}

void ispisi_osobe(Osoba *root)
{
    if (root == NULL)
        return;

    ispisi_osobe(root->left);
    printf("dijeta: %20s, ime: %20s, kg: %d\n", root->dijeta, root->ime, root->kg);
    ispisi_osobe(root->right);
}

void ispisi_osobe_sa_imenom(Osoba *root, char ime[])
{
    if (root == NULL)
    {
        return;
    }

    char pod_ime[20];
    strcpy(pod_ime, root->ime);
    int len = strlen(pod_ime);
    for (int i = 0; i < len; i++)
    {
        if (pod_ime[i] >= 'A' && pod_ime[i] <= 'Z')
        {
            pod_ime[i] += 32;
        }
    }
    if (strstr(pod_ime, ime) != NULL)
    {
        printf("dijeta: %s, ime: %s, kg: %d\n", root->dijeta, root->ime, root->kg);
    }
    ispisi_osobe_sa_imenom(root->left, ime);
    ispisi_osobe_sa_imenom(root->right, ime);
}

void najbolja_dijeta(Osoba *root, char dijeta[], char naziv_max_dijete[], int *suma_kg, int *br_dijeta, double *max_efikasnost)
{
    if (root == NULL)
        return;

    najbolja_dijeta(root->left, dijeta, naziv_max_dijete, suma_kg, br_dijeta, max_efikasnost);

    if (strcmp(dijeta, "") == 0)
    {
        strcpy(dijeta, root->dijeta);
        *suma_kg = root->kg;
        *br_dijeta = 1;
    }
    else if (strcmp(dijeta, root->dijeta) == 0)
    {
        *suma_kg += root->kg;
        *br_dijeta += 1;
    }
    else
    {
        printf("Racunanje dijete: %s , %d , %d\n", dijeta, *suma_kg, *br_dijeta);
        double efikasnost = 1.0 * (*suma_kg) / (*br_dijeta);
        if (*max_efikasnost == -1 || efikasnost > (*max_efikasnost))
        {
            strcpy(naziv_max_dijete, dijeta);
            *max_efikasnost = efikasnost;
        }
        strcpy(dijeta, root->dijeta);
        *suma_kg = root->kg;
        *br_dijeta = 1;
    }

    najbolja_dijeta(root->right, dijeta, naziv_max_dijete, suma_kg, br_dijeta, max_efikasnost);
}
Osoba *izbrisi(Osoba *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    else
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
    int command, kg;
    char naziv_fajla[20], ime[20], dijeta[20];

    do
    {
        printf("Enter command: ");
        scanf("%d", &command);

        switch (command)
        {
        case 0:
            printf("Exiting program.\n");
            break;
        case 1:
            printf("Enter filename: ");
            scanf("%s", naziv_fajla);
            FILE *fp = fopen(naziv_fajla, "r");
            if (fp == NULL)
            {
                printf("Pogresan naziv fajla!!!\n");
                break;
            }
            // Example data format: Petar,paleo,2
            while (fscanf(fp, "%[^,],%[^,],%d\n", ime, dijeta, &kg) != EOF)
            {
                Osoba *nova = nova_osoba(ime, dijeta, kg);
                root = dodaj_osobu(root, nova);
            }
            fclose(fp);
            break;
        case 2:
            printf("---------------------\n");
            ispisi_osobe(root);
            printf("\n---------------------\n");
            break;
        case 3:
        {
            char max_dijeta[20] = "";
            char tmp_dijeta[20] = "";
            double max_efikasnost = -1;
            int suma_kg = 0;
            int br_dijeta = 0;

            najbolja_dijeta(root, tmp_dijeta, max_dijeta, &suma_kg, &br_dijeta, &max_efikasnost);
            printf("Racunanje dijete: %s , %d , %d\n", tmp_dijeta, suma_kg, br_dijeta);
            double efikasnost = 1.0 * suma_kg / br_dijeta;
            if (efikasnost > max_efikasnost)
            {
                strcpy(max_dijeta, dijeta);
                max_efikasnost = efikasnost;
            }

            // After the entire tree is processed, print the most effective diet
            printf("Najbolja dijeta: %s sa prosekom %2lf\n", max_dijeta, max_efikasnost);
        }
        break;
        case 4:
            printf("Ime: ");
            scanf("%s", ime);
            int len = strlen(ime);
            for (int i = 0; i < len; i++)
            {
                if (ime[i] >= 'A' && ime[i] <= 'Z')
                {
                    ime[i] += 32;
                }
            }
            ispisi_osobe_sa_imenom(root, ime);
            break;
        case 5:
            root = izbrisi(root);
            break;
        default:
            printf("Wrong command!!!\n");
            break;
        }
    } while (command != 0);

    return 0;
}
