#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// . (25p) Napisati program koji iz fajla učitava podatke efektima dijete na određene osobe. U svakom
// redu se nalaze ime osobe, naziv dijete i broj kilograma koje je osoba izgubila, razdvojene zapetom.
// Primer: Vladimir,paleo,5. Napraviti meni za interakciju preko konzole sa sledećim opcijama:

// a) (10p) Učitavanje podataka – unosi se naziv fajla, a podaci se učitavaju u binarno pretraživačko stablo,
// sortirani rastuće po nazivu dijete.
// b) (2p) Ispis podataka. Nakon učitavanja ispisati podatke iz stabla sortirano rastuce.
// c) (4p) Ispis najefikasnije dijete – ispisati naziv dijete sa najvećom prosečnom izgubljenom masom po
// osobi i odgovarajuću prosečnu vrednost na dve decimale. Ukoliko ima više najboljih, ispisati bilo koju.
// d) (8p) Pronalaženje podataka o osobi – unosi se string – deo imena osobe, ispisuju se podaci o svim
// osobama čije ime sadrži uneti string. Pretraga treba da bude neosetljiva na mala i velika slova.
// e) (1p) Izlaz iz programa i brisanje stabla

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
    strcpy(nova->ime, ime);
    strcpy(nova->dijeta, dijeta);
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
    if (strcmp(nova->dijeta, root->dijeta) < 0)
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
    if (root == NULL)
    {
        return;
    }
    else
    {
        ispisi(root->left);
        printf("dijeta: %20s, ime: %20s, kg: %d\n", root->dijeta, root->ime, root->kg);
        ispisi(root->right);
    }
}
void najbolja_dijeta(Osoba *root, char dijeta[], char max_dijeta[], double *efikasnost, int *suma_kg, int *br_dijete)
{
    if (root == NULL)
    {
        return;
    }

    najbolja_dijeta(root->left, dijeta, max_dijeta, efikasnost, suma_kg, br_dijete);
    if (strcmp(dijeta, "") == 0)
    {
        strcpy(dijeta, root->dijeta);
        *suma_kg = root->kg;
        *br_dijete = 1;
    }
    else if (strcmp(dijeta, root->dijeta) == 0)
    {
        *suma_kg += root->kg;
        *br_dijete += 1;
    }
    else
    {
        printf("Racunanje dijete: %s, kg: %d, Br: %d\n", dijeta, *suma_kg, *br_dijete);
        double tr_efikasnost = 1.0 * (*suma_kg) / (*br_dijete);
        if (*efikasnost == -1 || tr_efikasnost > (*efikasnost))
        {
            strcpy(max_dijeta, dijeta);
            *efikasnost = tr_efikasnost;
        }
        strcpy(dijeta, root->dijeta);
        *suma_kg = root->kg;
        *br_dijete = 1;
    }

    najbolja_dijeta(root->right, dijeta, max_dijeta, efikasnost, suma_kg, br_dijete);
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
        izbrisi(root->left);
        free(root);
    }
    return NULL;
}

void podatak(Osoba *root, char imen[])
{
    if (root == NULL)
    {
        return;
    }
    char tr_ime[20];
    strcpy(tr_ime, root->ime);
    int len = strlen(tr_ime);
    for (int i = 0; i < len; i++)
    {
        if (tr_ime[i] >= 'A' && tr_ime[i] <= 'Z')
        {
            tr_ime[i] += 32;
        }
    }

    if (strstr(tr_ime, imen) != NULL)
    {
        printf("dijeta: %s, ime: %s, kg: %d\n", root->dijeta, root->ime, root->kg);
    }
    podatak(root->left, imen);
    podatak(root->right, imen);
}

int main()
{
    Osoba *root = NULL;
    int command, kg;
    char ime[20], dijeta[20], naziv_fajla[20], tr_ime[20];
    do
    {
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            printf("End");
            break;
        case 1:
            printf("Naziv fajla: ");
            scanf("%s", &naziv_fajla);
            FILE *fp = fopen(naziv_fajla, "r");
            if (fp == NULL)
            {
                printf("Pogresan file!");
            }
            /// Petar,paleo,2
            while (fscanf(fp, "%[^,],%[^,],%d\n", ime, dijeta, &kg) != EOF)
            {
                Osoba *osobe = nova_osoba(ime, dijeta, kg);
                root = dodaj_osobu(root, osobe);
            }
            fclose(fp);
            break;
        case 2:
            printf("------------------\n");
            ispisi(root);
            printf("\n------------------\n");
            break;
        case 3:
        {
            char max_dijeta[20] = "";
            char tmp_dijeta[20] = "";
            double efikasnost = -1;
            int suma_kg = 0;
            int broj_dijete = 0;

            najbolja_dijeta(root, tmp_dijeta, max_dijeta, &efikasnost, &suma_kg, &broj_dijete);
            printf("Racunanje dijete: %s, kg: %d, Br: %d\n", dijeta, &suma_kg, &broj_dijete);
            double tr_efikasnost = 1.0 * suma_kg / broj_dijete;
            if (tr_efikasnost > efikasnost)
            {
                strcpy(max_dijeta, dijeta);
                efikasnost = tr_efikasnost;
            }
            printf("Najbolja dijeta: %s sa prosekom %2lf\n", max_dijeta, efikasnost);
        }
        break;
        case 4:
            printf("Unesi ime: ");
            scanf("%s", &tr_ime);
            int len = strlen(tr_ime);
            for (int i = 0; i < len; i++)
            {
                if (tr_ime[i] >= 'A' && tr_ime[i] <= 'Z')
                {
                    tr_ime[i] += 32;
                }
            }
            podatak(root, tr_ime);

            break;
        case 5:
            root = izbrisi(root);
            break;
        default:
            break;
        }
    } while (command != 0);
}