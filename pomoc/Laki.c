#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 20

// Funkcija za unos matrice
void getMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Unesite elemente %dx%d matrice:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

// Funkcija za računanje determinante (samo za kvadratne matrice)
double calculateDeterminant(double matrix[MAX_SIZE][MAX_SIZE], int size) {
    if (size == 1) {
        return matrix[0][0];
    }
    if (size == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double determinant = 0;
    double subMatrix[MAX_SIZE][MAX_SIZE];

    for (int x = 0; x < size; x++) {
        int subCol = 0;
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j == x) continue;
                subMatrix[i - 1][subCol++] = matrix[i][j];
            }
        }
        determinant += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * calculateDeterminant(subMatrix, size - 1);
    }
    return determinant;
}

// Funkcija za transponovanje matrice
void transposeMatrix(double matrix[MAX_SIZE][MAX_SIZE], double transposed[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

// Funkcija za prikaz matrice
void displayMatrix(double matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%8.3f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    double matrix[MAX_SIZE][MAX_SIZE], transposed[MAX_SIZE][MAX_SIZE];

    printf("Unesite broj redova i kolona (do %d): ", MAX_SIZE);
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > MAX_SIZE || cols < 1 || cols > MAX_SIZE) {
        printf("Nevažeća dimenzija matrice! Dozvoljeno je 1 do %d redova i kolona.\n", MAX_SIZE);
        return 1;
    }

    getMatrix(matrix, rows, cols);

    printf("\nOriginalna matrica:\n");
    displayMatrix(matrix, rows, cols);

    if (rows == cols) {  // Provera da li je matrica kvadratna
        double det = calculateDeterminant(matrix, rows);
        printf("\nDeterminanta: %.3f\n", det);
    } else {
        printf("\nMatrica nije kvadratna, pa ne možemo izračunati determinantu.\n");
    }

    transposeMatrix(matrix, transposed, rows, cols);
    printf("\nTransponovana matrica:\n");
    displayMatrix(transposed, cols, rows);

    return 0;
}
