#include<stdio.h>
#include<stdlib.h>
#define N 5

int main(){
    int n,sum=0;
    printf("Unesi koliko zelis da imas brojeva u nizu: ");
    scanf("%d",&n);
    int niz[n];
    int a[n],b[n];
    int f=0,g=0;
    for (int i = 0; i <n; i++)
    {
        scanf("%d",&niz[i]);
        if(niz[i]%2==0){
            a[f++]=niz[i];
            
        }else{
            b[g++]=niz[i];
            
        }
    }
    printf("Niz A: ");
    for (int i = 0; i <f; i++)
    {
        printf("%d",a[i]);
    }
    printf("\nNiz B: ");
        for (int i = 0; i < g; i++)
    {
        printf("%d",b[i]);
    }
  
    return 0;
}