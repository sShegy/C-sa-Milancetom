#include<stdio.h>
#include<string.h>

#define MAX 256

void pomeranje_u_levo(char*string,int idx){
    for (int i =idx; i < strlen(string); i++)
    {
        string[i]=string[i+1];
    }
        
}

int main (){
    char string[MAX];
    fgets(string,MAX,stdin);
    int n=strlen(string);
    string[n-1]=0;

    int i=0;
    while (string[i]!=0)
    {
        if (string[i]==' ')
        {
            pomeranje_u_levo(string,i);
            continue;
        }
        i++;
    }
    fputs(string,stdout);
    return 0;
}