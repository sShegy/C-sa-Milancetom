#include<stdio.h>
#include<math.h>


int main(){
    int n,m;
    printf("Upisi broj: ");
    scanf("%d %d",&n,&m);
    int niz[50][50];
    int niz1[50][50];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&niz[i][j]);
        }
        
    }
    printf("------(ta matrica)----\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",niz[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");
    //niz1
    int l=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&niz1[i][j]);
            if (niz[i][j]!=niz1[i][j])
            {
                l=1;
            }
            
        }

        
    }
    printf("------(ta matrica)----\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",niz1[i][j]);
        }
        printf("\n");
    }
    if (l==1)
    {
        printf("Matrice nisu iste");
    }else printf("Matrice su iste");
    

    return 0;
}