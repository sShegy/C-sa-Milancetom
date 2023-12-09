#include<stdio.h>

int main(){
    int i,j,b=1,o;
	char g='*';
    scanf("%d",&o);
    for ( i = 0; i < o; i++)
    {
        for (j = 1; j <= o; j++)
        {

			printf("*");
        }
        
        printf("\n");
    }
    
    return 0;
}