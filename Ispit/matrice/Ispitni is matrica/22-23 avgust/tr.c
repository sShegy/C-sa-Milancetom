#include <stdio.h>
#include <limits.h>
#include <math.h>

#define SIZE 100

int is_prime(int num) {
    if (num <= 1) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int mat[SIZE][SIZE];
    int min_prime = INT_MAX, max_prime = INT_MIN;
    int min_x = -1, min_y = -1, max_x = -1, max_y = -1;

    // Input matrix and find min/max primes
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (is_prime(mat[i][j])) {
                if (mat[i][j] < min_prime) {
                    min_prime = mat[i][j];
                    min_x = i;
                    min_y = j;
                }
                if (mat[i][j] > max_prime) {
                    max_prime = mat[i][j];
                    max_x = i;
                    max_y = j;
                }
            }
        }
    }

    // Check if no primes are found
    if (min_x == -1 || max_x == -1) {
        printf("No primes found in the matrix.\n");
        return 0;
    }

    // Calculate the boundaries of the smallest submatrix containing both primes
    int top = (min_x < max_x) ? min_x : max_x;
    int bottom = (min_x > max_x) ? min_x : max_x;
    int left = (min_y < max_y) ? min_y : max_y;
    int right = (min_y > max_y) ? min_y : max_y;

    // Print the submatrix
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
