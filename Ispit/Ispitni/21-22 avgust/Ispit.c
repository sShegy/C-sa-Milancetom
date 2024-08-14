#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BankovniRacun
{
    char banka[30];
    char ime[50];
    int novac;
    char grad[30];
    struct BankovniRacun *next;
} BankovniRacun;

BankovniRacun *dodaj_sortirano(BankovniRacun *head, BankovniRacun *novi)
{
    if (head == NULL || strcmp(novi->banka, head->banka) < 0)
    {
        novi->next = head;
        return novi;
    }
    else
    {
        BankovniRacun *trenutni = head;
        while (trenutni->next != NULL && strcmp(trenutni->next->banka, novi->banka) < 0)
        {
            trenutni = trenutni->next;
        }
        novi->next = trenutni->next;
        trenutni->next = novi;
        return head;
    }
}

void ucitaj_podatke(BankovniRacun **head)
{
    char nazivfajla[50];
    printf("Unesite naziv fajla: ");
    scanf("%s", nazivfajla);

    FILE *fp = fopen(nazivfajla, "r");
    if (fp == NULL)
    {
        printf("Greska pri otvaranju fajla!\n");
        return;
    }

    char linija[150];
    while (fgets(linija, sizeof(linija), fp))
    {
        BankovniRacun *novi = malloc(sizeof(BankovniRacun));
        if (novi == NULL)
        {
            printf("Greska pri alokaciji memorije!\n");
            fclose(fp);
            return;
        }

        sscanf(linija, "%[^,],%[^,],%d,%[^,\n]", novi->banka, novi->ime, &novi->novac, novi->grad);
        novi->next = NULL;
        *head = dodaj_sortirano(*head, novi);
    }

    fclose(fp);
}

void ispisi_sve(BankovniRacun *head)
{
    if (head == NULL)
    {
        printf("Lista je prazna.\n");
        return;
    }

    BankovniRacun *trenutni = head;
    while (trenutni != NULL)
    {
        printf("Banka: %s, Ime: %s, Novac: %d, Grad: %s\n", trenutni->banka, trenutni->ime, trenutni->novac, trenutni->grad);
        trenutni = trenutni->next;
    }
}

void ispisi_gradove(BankovniRacun *head)
{
    if (head == NULL)
    {
        printf("Lista je prazna.\n");
        return;
    }

    typedef struct Grad
    {
        char naziv[30];
        int ukupno;
        struct Grad *next;
    } Grad;

    Grad *gradovi = NULL;

    BankovniRacun *trenutni = head;
    while (trenutni != NULL)
    {
        Grad *g = gradovi;
        while (g != NULL && strcmp(g->naziv, trenutni->grad) != 0)
        {
            g = g->next;
        }
        if (g == NULL)
        {
            Grad *novi = (Grad *)malloc(sizeof(Grad));
            if (novi == NULL)
            {
                printf("Greska pri alokaciji memorije!\n");
                return;
            }
            strcpy(novi->naziv, trenutni->grad);
            novi->ukupno = trenutni->novac;
            novi->next = gradovi;
            gradovi = novi;
        }
        else
        {
            g->ukupno += trenutni->novac;
        }
        trenutni = trenutni->next;
    }

    Grad *g = gradovi;
    while (g != NULL)
    {
        if (g->ukupno > 10000)
        {
            printf("Grad: %s, Ukupno: %d\n", g->naziv, g->ukupno);
        }
        Grad *temp = g;
        g = g->next;
        free(temp);
    }
}

BankovniRacun *izbrisi_ispod_sume(BankovniRacun *head, int suma)
{
    BankovniRacun *trenutni = head;
    BankovniRacun *prethodni = NULL;

    while (trenutni != NULL)
    {
        if (trenutni->novac < suma)
        {
            if (prethodni == NULL)
            {
                head = trenutni->next;
            }
            else
            {
                prethodni->next = trenutni->next;
            }
            BankovniRacun *temp = trenutni;
            trenutni = trenutni->next;
            free(temp);
        }
        else
        {
            prethodni = trenutni;
            trenutni = trenutni->next;
        }
    }
    return head;
}

void oslobodi_listu(BankovniRacun *head)
{
    while (head != NULL)
    {
        BankovniRacun *temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    BankovniRacun *head = NULL;
    int opcija, suma;

    do
    {
        printf("\nMeni:\n");
        printf("1. Ucitavanje podataka\n");
        printf("2. Ispis svih bankovnih racuna\n");
        printf("3. Ispis svih gradova sa ukupnim uplatama vecim od 10000\n");
        printf("4. Brisanje racuna sa manje od navedene sume\n");
        printf("5. Izlaz\n");
        printf("Unesite opciju: ");
        scanf("%d", &opcija);

        switch (opcija)
        {
        case 1:
            ucitaj_podatke(&head);
            break;
        case 2:
            ispisi_sve(head);
            break;
        case 3:
            ispisi_gradove(head);
            break;
        case 4:
            printf("Unesite sumu: ");
            scanf("%d", &suma);
            head = izbrisi_ispod_sume(head, suma);
            break;
        case 5:
            oslobodi_listu(head);
            printf("Izlaz iz programa.\n");
            break;
        default:
            printf("Nepoznata opcija, pokusajte ponovo.\n");
        }
    } while (opcija != 5);

    return 0;
}
