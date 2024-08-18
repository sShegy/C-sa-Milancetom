#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    char smer[3];
    int index;
    int godina;
    double rez_prvi_test;
    double rez_prvi_kolk;
    double rez_drugi_test;
    double rez_drugi_kolk;

    struct Student *next;
} Student;

typedef struct Statistika
{
    char smer[3];
    int br_studenata;
    double broj_poena;

    struct Statistika *next;
} Statistika;

int compare(Student *s1, Student *s2)
{
    if (strcmp(s1->smer, s2->smer) < 0)
    {
        return -1;
    }
    else if (strcmp(s1->smer, s2->smer) > 0)
    {
        return 1;
    }
    else
    {
        if (s1->index < s2->index)
        {
            return -1;
        }
        else if (s1->index > s2->index)
        {
            return 1;
        }
        else
        {
            if (s1->godina < s2->godina)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }
    }
}

double broj_predispitnih(Student *s)
{
    return s->rez_prvi_test + s->rez_prvi_kolk + s->rez_drugi_test + s->rez_drugi_kolk;
}

Student *novi_student(char smer[], int index, int godina, double rez_prvi_test, double rez_prvi_kolk, double rez_drugi_test, double rez_drugi_kolk)
{
    Student *novi = malloc(sizeof(Student)); // alociramo memoriju za novi element
    strcpy(novi->smer, smer);
    novi->index = index;
    novi->godina = godina;
    novi->rez_prvi_test = rez_prvi_test;
    novi->rez_prvi_kolk = rez_prvi_kolk;
    novi->rez_drugi_test = rez_drugi_test;
    novi->rez_drugi_kolk = rez_drugi_kolk;
    novi->next = NULL;

    return novi;
}

Student *dodaj_studenta(Student *root, Student *novi)
{
    if (root == NULL)
    { // lista prazna, dodajemo prvi element
        return novi;
    }

    if (compare(novi, root) == -1)
    { // treba dodati element na pocetak
        novi->next = root;
        return novi;
    }

    Student *tmp = root;
    while (tmp->next != NULL)
    { // treba dodati element negde u listi
        if (compare(novi, tmp->next) == -1)
        {
            break;
        }

        tmp = tmp->next;
    }

    novi->next = tmp->next;
    tmp->next = novi;
    return root;
}

void ispisi_studente(Student *root)
{
    printf("---------------------------------------------------------\n");
    while (root != NULL)
    {
        printf("[%s %d %d] %.2lf %.2lf %.2lf %.2lf\n", root->smer, root->index, root->godina, root->rez_prvi_test, root->rez_prvi_kolk, root->rez_drugi_test, root->rez_drugi_kolk);
        root = root->next;
    }
    printf("---------------------------------------------------------\n");
}

int broj_studenata_za_prolazak_iter(Student *root, int n)
{
    if (root == NULL)
    {
        return 0;
    }

    int cnt = 0;
    while (root != NULL)
    {
        int br_poena = broj_predispitnih(root);
        if ((br_poena + n) < 51)
        {
            cnt++;
        }

        root = root->next;
    }

    return cnt;
}

int broj_studenata_za_prolazak_rek(Student *root, int n, int cnt)
{
    if (root == NULL)
    {
        return cnt;
    }

    int br_poena = broj_predispitnih(root);
    if ((br_poena + n) < 51)
    {
        cnt++;
    }

    return broj_studenata_za_prolazak_rek(root->next, n, cnt);
}

Statistika *nova_statistika(char smer[])
{
    Statistika *nova = malloc(sizeof(Statistika));
    strcpy(nova->smer, smer);
    nova->br_studenata = 0;
    nova->broj_poena = 0;
    nova->next = NULL;

    return nova;
}

Statistika *napravi_statistiku(Statistika *root, Student *studenti)
{
    if (studenti == NULL)
    {
        return NULL;
    }

    while (studenti != NULL)
    {
        if (root == NULL)
        {
            root = nova_statistika(studenti->smer);
        }

        Statistika *tmp = root;
        Statistika *za_smer = NULL;

        // u slucaju da je prvi element
        if (strcmp(tmp->smer, studenti->smer) == 0)
        {
            za_smer = tmp;
        }

        while (tmp->next != NULL && za_smer == NULL)
        {
            if (strcmp(tmp->smer, studenti->smer) == 0)
            {
                za_smer = tmp;
            }

            tmp = tmp->next;
        }

        // u slucaju da je poslednji element
        if (strcmp(tmp->smer, studenti->smer) == 0)
        {
            za_smer = tmp;
        }

        // u slucaju da ne postoji element
        if (za_smer == NULL)
        {
            Statistika *nova = nova_statistika(studenti->smer);
            tmp->next = nova;
            za_smer = nova;
        }

        za_smer->broj_poena = za_smer->broj_poena + broj_predispitnih(studenti);
        za_smer->br_studenata++;

        studenti = studenti->next;
    }

    return root;
}

void ispisi_statistiku(Statistika *root)
{
    printf("---------------------------------------------------------\n");
    while (root != NULL) 
    {
        printf("[%s]: %.2lf\n", root->smer, root->broj_poena / root->br_studenata);
        root = root->next;
    }
    printf("---------------------------------------------------------\n");
}

int main()
{
    FILE *file = fopen("studenti-UUP.txt", "r");
    int command, n;

    char smer[3];
    int index, godina;
    double rez_prvi_test, rez_prvi_kolk, rez_drugi_test, rez_drugi_kolk;

    Student *root_studenti = NULL;
    Statistika *root_statistika = NULL;

    do
    {
        scanf("%d", &command);
        switch (command)
        {
        case 1:
            while (fscanf(file, "%[^,],%d,%d,%lf,%lf,%lf,%lf\n", smer, &index, &godina, &rez_prvi_test, &rez_prvi_kolk, &rez_drugi_test, &rez_drugi_kolk) != EOF)
            {
                root_studenti = dodaj_studenta(root_studenti, novi_student(smer, index, godina, rez_prvi_test, rez_prvi_kolk, rez_drugi_test, rez_drugi_kolk));
            }
            break;
        case 2:
            ispisi_studente(root_studenti);
            break;
        case 3:
            scanf("%d", &n);
            printf("iter = %d, rek = %d\n", broj_studenata_za_prolazak_iter(root_studenti, n), broj_studenata_za_prolazak_rek(root_studenti, n, 0));
            break;
        case 4:
            root_statistika = napravi_statistiku(root_statistika, root_studenti);
            ispisi_statistiku(root_statistika);
            break;
        default:
            break;
        }
    } while (command != 0);

    return 0;
}