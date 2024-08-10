#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// Element* kreiraj_element(int data);
/// void ispisi_listu(Element* head);
/// Element* obrisi_glavu(Element* head);
/// Element* dodaj_na_pocetak(Element* head, Element* novi);
/// Element* dodaj_na_kraj(Element* head, Element* novi);
/// Element* dodaj_na_kraj_rekurzivno(Element* head, Element* novi);
/// Element* dodaj_na_poziciju(Element* head, Element* novi, int pozicija);
/// Element* dodaj_na_poziciju_rekurzivno(Element* head, Element* novi, int pozicija);
/// Element* obrisi_element(Element* head, Element* cilj);
/// Element* dodaj_u_sredinu(Element* head, Element* novi);
/// Element* obrni_listu(Element* head);
/// Element* pronadji_kraj(Element* head);
/// Element* obrni_listu_rekurzivno(Element* head);
/// Element* pretrazi_element(Element* head, int data);
/// Element* obrisi_po_vrednosti(Element* head, int data);

typedef struct Element
{
    int data;
    struct Element *next;

} Element;

Element *novi_element(int data)
{
    Element *novi = malloc(sizeof(Element));
    novi->data = data;
    novi->next = NULL;
    return novi;
}
Element *dodaj_na_pocetak(Element *head, Element *novi)
{
    if (head == NULL)
    {
        return novi;
    }
    novi->next = head;
    return novi;
}
Element *dodaj_na_kraj(Element *head, Element *novi)
{
    if (head == NULL)
    {
        return novi;
    }

    Element *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = novi;
    return head;
}
Element *dodaj_na_kraj_rek(Element *head, Element *novi)
{
    if (head == NULL)
    {
        return novi;
    }
    head->next = dodaj_na_kraj_rek(head->next, novi);
    return head;
}
Element *dodaj_na_pozociju(Element *head, Element *novi, int pos)
{
    if (head == NULL)
    {
        return novi;
    }
    Element *tmp = head;
    int cnt;
    while (tmp->next != NULL && cnt < pos - 1)
    {
        tmp = tmp->next;
        cnt++;
    }
    novi->next = tmp->next;
    tmp->next = novi;
    return head;
}
Element *dodaj_na_pozociju_rek(Element *head, Element *novi, int pos)
{
    if (head == NULL || pos == 0)
    {
        novi->next = head;
        return novi;
    }
    head->next = dodaj_na_pozociju_rek(head->next, novi, pos - 1);
    return head;
}
Element *dodaj_sortirano(Element *head, Element *novi)
{
    if (head == NULL || novi->data < head->data)
    {
        novi->next = head;
        return novi;
    }
    Element *tmp = head;
    while (tmp->next != NULL && tmp->next->data < novi->data)
    {
        tmp = tmp->next;
    }
    novi->next = tmp->next;
    tmp->next = novi;
    return head;
}
Element *dodaj_sortirano_rek(Element *head, Element *novi)
{
    if (head == NULL || novi->data < head->data)
    {
        novi->next = head;
        return novi;
    }
    head->next = dodaj_sortirano_rek(head->next, novi);
    return head;
}
Element *brisi_sa_pocetka(Element *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Element *tmp = head;
    head = head->next;
    free(tmp);
    return head;
}
Element *brisi_sa_kraja(Element *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    Element *tmp = head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
    return head;
}
Element *brisi_sa_kraja_rek(Element *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    head->next = brisi_sa_kraja_rek(head->next, novi);
    return head;
}

void ispisi(Element *head)
{
    printf("----------------\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n----------------\n");

    return;
}
Element* izbrisi(Element *head)
{
    if (head==NULL)
    {
        return NULL
    }
    
    while (head != NULL)
    {
        Element *fre = head;
        head = head->next;
        free(fre);
    }
    return;
}

int main()
{
    Element *head = NULL;

    int command;
    int data, post;
    do
    {
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            break;
        case 1:
            scanf("%d", &data);
            head = dodaj_na_pocetak(head, novi_element(data));
            break;
        case 2:
            ispisi(head);
            break;
        case 3:
            scanf("%d", &data);
            head = dodaj_na_kraj(head, novi_element(data));
            break;
        case 5:
            izbrisi(head);
            break;
        case 4:
            scanf("%d", &data);
            head = dodaj_na_kraj_rek(head, novi_element(data));
            break;
        case 6:
            scanf("%d %d", &data, &post);
            head = dodaj_na_pozociju(head, novi_element(data), post);
            break;
        case 7:
            scanf("%d %d", &data, &post);
            head = dodaj_na_pozociju_rek(head, novi_element(data), post);
            break;
        case 8:
            scanf("%d", &data);
            head = dodaj_sortirano(head, novi_element(data));
            break;
        case 9:
            scanf("%d", &data);
            head = dodaj_sortirano_rek(head, novi_element(data));
            break;
        case 10:
            head = brisi_sa_pocetka(head);
            break;
        case 11:
            head = brisi_sa_kraja(head);
            break;
        case 12:
            head = brisi_sa_kraja_rek(head);
            break;
        default:
            printf("Wrong command!\n");
            break;
        }
    } while (command != 0);
    return 0;
}