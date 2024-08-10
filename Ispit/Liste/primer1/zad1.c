#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int main() {
    FILE *f = fopen("/Users/shegy/C-sa-Milancetom3232/Ispit/Liste/test.txt", "r");
    if (f == NULL) {
        printf("File could not be opened or does not exist.\n");
        return -1;
    } else {
        printf("File opened successfully.\n");
    }

    int broj;
    char pred[50];
    char ocene[50];
    int ocena[50];

    while (fscanf(f, "%d %[^ ] %[^\n]\n", &broj, pred, ocene) != EOF) {
        char *token = strtok(ocene, " ");
        int idx = 0;
        while (token != NULL) {
            ocena[idx++] = atoi(token);
            token = strtok(NULL, " ");
        }

        printf("---------------\n");
        printf("Br:%d Pred:%s Ocene: ", broj, pred);
        for (int i = 0; i < idx; i++) {
            printf("%d ", ocena[i]);
        }
        printf("\n---------------\n");
    }

    fclose(f);
    return 0;
}
