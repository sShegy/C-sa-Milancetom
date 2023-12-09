#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, k, l;
    int mat[10][10];
    int mat2[10][10];
    int flag = 1;
    printf("Unesite redove i kolone: ");
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("-------------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("Unesite drugu matricu: ");
    scanf("%d%d", &k, &l);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            scanf("%d", &mat2[i][j]);
            if (mat[i][j] != mat2[i][j])
            {
                flag = 0;
            }
        }
    }
    printf("-------------\n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < l; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n");
    }
    if (flag != 1)
    {
        printf("Nisu");
    }
    else
    {
        printf("Jesu");
    }

    return 0;
}