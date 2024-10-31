#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int n,cena=0;
    int niz[50];

    printf("Unesi broj niza: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&niz[i]);
        cena+=niz[i];//cena=cena+niz[i]
        
    }
    if (cena>=6000)
    {
        int popust=cena*0.8;
        int nova_cena=cena-2000;
        if (popust<nova_cena)
        {
            printf("Cena je : %d din",popust);
        }else{
           printf("Cena je : %d din",nova_cena); 
        }
        
    }else{
        printf("Cena je : %d din",cena);
    }
    

    


}