#include<stdio.h>
#include<stdlib.h>

int main (){
    int n;
    printf("Unesi broj: ");
    scanf("%d",&n);
    int niz[50];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&niz[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int pret=i;
        for (int j = i+1 ; j < n; j++)
        {
            if (niz[pret]>niz[j])
            {
                pret=j;
            }
        }
        if (pret !=i)
        {
            int temp =niz[i];
            niz[i]=niz[pret];
            niz[pret]=temp;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",niz[i]);
    }
    
    
    return 0;
}