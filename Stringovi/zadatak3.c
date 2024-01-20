#include<stdio.h>
#include<string.h>
#define MAX 256


void pomeranje_u_desno(char*string,int idx){
    int n=strlen(string);
    for (int i =n+1; i >idx; i--)
    {
        string[i]=string[i-1];
    }
    
}
int main(){
    char string[MAX];
    fgets(string,MAX,stdin);
    int n=strlen(string);
    string[n-1]=0;
    char p,t;
    p=string[0];
    for (int i = 1; string[i]!=0 ; i++)
    {
        t=string[i];
        if (p!=t)
        {
            pomeranje_u_desno(string,i);

            string[i]='-';
        }
        p=t;        

    }
    n=strlen(string);
    string[n]='-';
    string[n+1]=0;
    fputs(string,stdout);   

    return 0;
}