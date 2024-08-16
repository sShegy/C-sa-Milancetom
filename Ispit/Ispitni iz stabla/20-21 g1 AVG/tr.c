#include<stdio.h>
#include<stdlib.h>
#include<string.h>
# define N 99

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





int main(){

    FILE *file = fopen("studenti-UUP.txt", "r");
    int command, n;

    char smer[3];
    int index, godina;
    double rez_prvi_test, rez_prvi_kolk, rez_drugi_test, rez_drugi_kolk;

    do
    {
        printf("Enter commend: ");
        scanf("%d",&command);
        switch (command)
        {
        case 0 :
            printf("Exit!");
            break;
        case 1:
            while (fscanf())
            {
                /* code */
            }
            
        default:
            break;
        }
    } while (command!=0);
    

    return 0;
}