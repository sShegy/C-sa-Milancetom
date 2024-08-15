#include <stdio.h>

#define SIZE 100

int main()
{
    int n;
    scanf("%d", &n);

    int a[SIZE][SIZE];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = i; k < n; k++)
            {
                for (int l = j; l < n; l++)
                {
                    int daLiSuParni = 1;
                    for (int x = i; x <= k; x++)
                    {
                        for (int y = j; y <= l; y++)
                        {
                            if (a[x][y] % 2 != 0)
                                daLiSuParni = 0;
                        }
                    }
                    if (daLiSuParni == 1)
                    {
                        for (int x = i; x <= k; x++)
                        {
                            for (int y = j; y <= l; y++)
                            {
                                printf("%d", a[x][y]);
                            }
                            printf("\n");
                        }
                        printf("\n");
                    }
                }
            }
        }
    }
}