
#include <stdio.h>
#include <string.h>

/*
 Ulaz: abc eef cba eed ghi dee aaa

 Izlaz: abc cba eed dee
 */
void obrni(char* rec){
    for(int i = 0; i < strlen(rec) / 2; i++){
        char tmp = rec[i];
        rec[i] = rec[strlen(rec) - 1 - i];
        rec[strlen(rec) - 1 - i] = tmp;
    }

}
int obrnuto(char* rec1, char* rec2){
    int len1 = strlen(rec1);
    int len2 = strlen(rec2);

    if(len1 != len2) // reci nam nisu iste duzine
        return 0;
    for(int i1 = 0, i2 = len2 - 1; i1 < len1 && i2 >= 0;i1++,i2--){
        if(rec1[i1] != rec2[i2])
            return 0;
    }
    return 1;
}

int main(){
    char str[100], novi[100];
    novi[0] = 0;
    char* token;
    fgets(str,sizeof(str),stdin);
    str[(strlen(str) - 1)] = 0;
    char reci[50][50];
    int idx = 0;
    token = strtok(str," ");
    while(token != NULL){
        strcpy(reci[idx++],token);
        token = strtok(NULL, " ");
    }
    for(int i = 0; i < idx - 1; i++){
        for(int j = i + 1; j < idx; j++){
            if(obrnuto(reci[i],reci[j])){
                strcat(novi,reci[i]);
                obrni(reci[i]);
                strcat(novi," ");
                strcat(novi,reci[i]);
                strcat(novi," ");

            }

        }
    }

    fputs(novi,stdout);

    return 0;
}