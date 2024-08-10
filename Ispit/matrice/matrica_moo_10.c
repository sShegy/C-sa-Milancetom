#include <stdio.h>
#include <stdlib.h>
#define N 1000

void ispisi(int n, int niz[N][N]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", niz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n = 0, i;
    int niz[N][N] = {0}; // Initialize the matrix to 0
    scanf("%d", &i);
    int cp = i;

    // Count the number of digits
    while (i != 0) {
        n++;
        i /= 10;
    }

    int m = n;
    int kl = m - 1; // Adjust index to be zero-based
    while (m != 0) {
        niz[0][kl--] = cp % 10;
        cp /= 10;
        m--;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            niz[i][j]=(niz[i-1][j]+1)%10;
        }
        
    }
    

    // Print the matrix
    ispisi(n, niz);
    return 0;
}
