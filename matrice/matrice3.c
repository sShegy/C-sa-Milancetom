#include<stdio.h>
#include<stdlib.h>


void upisi_matricu(int n,int m,int niz[10][10]){
    int sum1=0,sum2=0;
    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&niz[i][j]);
        }
        
    }
}

int main(){
    int n,m;
    int niz[10][10];
    printf("Unesi matricu: ");
    scanf("%d%d",&n,&m);
    upisi_matricu(n,m,niz);
    int red[10],col[10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            red[i]+=niz[i][j];
            col[j]+=niz[i][j];
    
        }
        
    }
    int max_ind_red=0;
    for (int i = 1; i < n; i++)
    {
        if (red[i]>red[max_ind_red])
        {
            max_ind_red=i;
        }
        
    }
    
    int max_ind_col=0;
    for (int i = 1; i < n; i++)
    {
        if (col[i]>col[max_ind_col])
        {
            max_ind_col=i;
        }
        
    }

    printf("Najveca suma redaj: %d",max_ind_red);
    printf("\nNajveca suma col: %d",max_ind_col);
    return 0;
}