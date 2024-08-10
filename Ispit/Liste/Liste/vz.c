#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list element
typedef struct Element
{
    int data;
    struct Element *next;
} Element;

// Function to create a new element with given data
Element *novi_element(int data)
{
    Element *novi = malloc(sizeof(Element));
    if (!novi)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    novi->data = data;
    novi->next = NULL;
    return novi;
}

// Function to print the list
void ispisi(Element *head)
{
    printf("----------------\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n----------------\n");
}

// Function to delete the first element and return the new head
Element *izbrisi(Element *head)
{
    if (head == NULL)
        return NULL;

    while (head != NULL)
    {
        Element *tmp = head;
        head = head->next;
        free(tmp);
    }

    return head;
}

// Function to add a new element at the beginning of the list
Element *dodaj_na_pocetak(Element *head, Element *novi)
{
    if (head == NULL)
    {
        return novi;
    }

    novi->next = head;
    return novi;
}

// Function to add a new element at the end of the list iteratively
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

// Function to add a new element at the end of the list recursively
Element *dodaj_na_kraj_rek(Element *head, Element *novi)
{
    if (head == NULL)
    {
        return novi;
    }
    head->next = dodaj_na_kraj_rek(head->next, novi);
    return head;
}

// Function to insert an element at a specific position iteratively
Element *dodaj_na_poziciju(Element *head, Element *novi, int pos)
{
    if (head == NULL || pos == 0)
    {
        novi->next = head;
        return novi;
    }
    Element *tmp = head;
    int idx = 0;
    while (tmp->next != NULL && idx < pos - 1)
    {
        tmp = tmp->next;
        idx++;
    }
    novi->next = tmp->next;
    tmp->next = novi;
    return head;
}

// Function to insert an element at a specific position recursively
Element *dodaj_na_poziciju_rek(Element *head, Element *novi, int pos)
{
    if (head == NULL || pos == 0)
    {
        novi->next = head;
        return novi;
    }
    head->next = dodaj_na_poziciju_rek(head->next, novi, pos - 1);
    return head;
}

// Function to insert elements in sorted order iteratively
Element *sortiraj(Element *head, Element *novi)
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

// Function to insert elements in sorted order recursively
Element *sortiraj_rek(Element *head, Element *novi)
{
    if (head == NULL || novi->data < head->data)
    {
        novi->next = head;
        return novi;
    }
    head->next = sortiraj_rek(head->next, novi);
    return head;
}

// Function to delete the first element of the list
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

// Function to delete the last element of the list iteratively
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

// Function to delete the last element of the list recursively
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
    head->next = brisi_sa_kraja_rek(head->next);
    return head;
}

// Function to delete elements greater than a given criteria iteratively
Element *brisi_sa_kriterijumom(Element *head, int data)
{
    // Remove nodes from the start of the list
    while (head != NULL && head->data > data)
    {
        Element *tmp = head;
        head = head->next;
        free(tmp);
    }
    if (head == NULL)
    {
        return NULL;
    }
    Element *za = head;
    while (za->next != NULL)
    {
        if (za->next->data > data)
        {
            Element *tm = za->next;
            za->next = za->next->next;
            free(tm);
        }
        else
        {
            za = za->next;
        }
    }
    return head;
}

// Function to delete elements greater than a given criteria recursively
Element *brisi_sa_kriterijumom_rek(Element *head, int data)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data > data)
    {
        Element *tmp = head;
        head = head->next;
        free(tmp);
        return brisi_sa_kriterijumom_rek(head, data);
    }
    head->next = brisi_sa_kriterijumom_rek(head->next, data);
    return head;
}

int main()
{
    Element *head = NULL;

    int command;
    int data, pos;
    printf("\033[1mKomanda `15 je menu: \033[0m\n");
    do
    {
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command)
        {
        case 0:
            break;
        case 1: // Add to the beginning
            printf("Enter data to add: ");
            scanf("%d", &data);
            head = dodaj_na_pocetak(head, novi_element(data));
            break;
        case 2: // Print list
            ispisi(head);
            break;
        case 3: // Delete first element
            head = izbrisi(head);
            break;
        case 4: // Add to the end iteratively
            printf("Enter data to add: ");
            scanf("%d", &data);
            head = dodaj_na_kraj(head, novi_element(data));
            break;
        case 5: // Add to the end recursively
            printf("Enter data to add: ");
            scanf("%d", &data);
            head = dodaj_na_kraj_rek(head, novi_element(data));
            break;
        case 6: // Add at a specific position iteratively
            printf("Enter data to add: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            head = dodaj_na_poziciju(head, novi_element(data), pos - 1);
            break;
        case 7: // Add at a specific position recursively
            printf("Enter data to add: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            head = dodaj_na_poziciju_rek(head, novi_element(data), pos - 1);
            break;
        case 8: // Add sorted iteratively
            printf("Enter data to add: ");
            scanf("%d", &data);
            head = sortiraj(head, novi_element(data));
            break;
        case 9: // Add sorted recursively
            printf("Enter data to add: ");
            scanf("%d", &data);
            head = sortiraj_rek(head, novi_element(data));
            break;
        case 10: // Delete from the beginning
            head = brisi_sa_pocetka(head);
            break;
        case 11: // Delete from the end iteratively
            head = brisi_sa_kraja(head);
            break;
        case 12: // Delete from the end recursively
            head = brisi_sa_kraja_rek(head);
            break;
        case 13: // Delete elements greater than given data
            printf("Enter data as criteria: ");
            scanf("%d", &data);
            head = brisi_sa_kriterijumom(head, data);
            break;
        case 14: // Delete elements greater than given data
            printf("Enter data as criteria: ");
            scanf("%d", &data);
            head = brisi_sa_kriterijumom_rek(head, data);
            break;
        case 15:
            printf("Komande su: \n"
                   "1: Dodavanje na pocetak\n"
                   "2: Ispisuje listu\n"
                   "3: Brise prvi element\n"
                   "4: Dodavanje na kraj iterativno\n"
                   "5: Dodavanje na kraj rekurzivno\n"
                   "6: Dodavanje na poziciju iterativno\n"
                   "7: Dodavanje na poziciju rekurzivno\n"
                   "8: Dodavanje sortirano iterativno\n"
                   "9: Dodavanje sortirano rekurzivno\n"
                   "10: Brise sa pocetka liste\n"
                   "11: Brise element sa kraja liste iterativno\n"
                   "12: Brise element sa kraja liste rekurzivno\n"
                   "13: Brise elemente po kriterijumu iterativno\n"
                   "14: Brise elemente po kriterijumu rekurzivno\n");
            break;
        default:
            printf("Invalid command!\n");
            break;
        }
    } while (command != 0);

    // Free remaining elements in the list
    while (head != NULL)
    {
        head = izbrisi(head);
    }

    return 0;
}
