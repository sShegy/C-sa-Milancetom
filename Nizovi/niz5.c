#include<stdio.h>
#include<stdlib.h>

int main (){
    int n,m;
    int niz[50];
    printf("Unesi broj: ");
    scanf("%d%d",&n,&m);
    int q=n-m;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d",&niz[i]);
    }

    for (int i = 1; i <=m; i++)
    {
        niz[i]=niz[n--];
        
    }
    
    
    for (int i = 0; i < n; i++)
    {
        printf("%d ", niz[i]);
    }

    return 0;
}
