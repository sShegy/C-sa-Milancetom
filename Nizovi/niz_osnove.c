#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,m;
    int niz[50];
    int a[50],b[50];
    printf("Upisi broj: ");
    scanf("%d",&n);
    int t=0,y=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&niz[i]);
        if (niz[i]%2==0)
        {
            a[t++]=niz[i];
        }else{
            b[y++]=niz[i];
        }
        
    }
    for (int i = 0; i < t; i++)
    {
        printf("%d ",a[i]);
    }
    
    printf("\n");
    for (int i = 0; i <y; i++)
    {
        printf("%d ",b[i]);
    }
    

    return 0;
}