#include<stdio.h>
#include<string.h>

#define MAX 256

void moj_strcat(char* string,char* string2){
    int lokacija0=strlen(string);
    int duzina2=strlen(string2);
    for (int i = 0; i < duzina2; i++)
    {
        string[lokacija0 +i]=string2[i];
    }
    string[lokacija0+duzina2]=0;
    
}
int main(){
    char string[MAX];
    char string2[MAX];
    fgets(string,MAX,stdin);
    fgets(string2,MAX,stdin);
    
    
    
    int n=strlen(string);
    int n2=strlen(string2);
    string[n-1]=0;
    string2[n-1]=0;
    moj_strcat(string,string2);
    fputs(string,stdout);
    
    return 0;
}