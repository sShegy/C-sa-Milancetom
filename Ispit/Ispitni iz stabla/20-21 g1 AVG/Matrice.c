#include <stdio.h>
#include <stdbool.h>
#define N 99
/*
n = 23561
 3 6 7 3  
 2 5 5 6
 3 1 6 8
 1 6 6 9
*/
bool is_digit_in_number(int digit, int digits[], int digit_count)
{
    for (int i = 0; i < digit_count; i++)
    {
        if (digit == digits[i])
        {
            return true;
        }
    }
    return false;
}

void find_largest_square_submatrix(int mat[N][N], int size, int digits[], int digit_count)
{
    int max_square_size = 0;
    int start_row = -1;
    int start_col = -1;

    for (int x = 1; x <= size; x++)
    {
        for (int i = 0; i <= size - x; i++)
        {
            for (int j = 0; j <= size - x; j++)
            {
                bool valid_square = true;
                for (int p = i; p < i + x; p++)
                {
                    for (int q = j; q < j + x; q++)
                    {
                        if (!is_digit_in_number(mat[p][q], digits, digit_count))
                        {
                            valid_square = false;
                            break;
                        }
                    }
                    if (!valid_square)
                    {
                        break;
                    }
                }
                if (valid_square && x > max_square_size)
                {
                    max_square_size = x;
                    start_row = i;
                    start_col = j;
                }
            }
        }
    }

    if (max_square_size > 0)
    {
        printf("Theme: (%d, %d) dim:%dx%d\n", start_row + 1, start_col + 1, max_square_size, max_square_size);
    }
    else
    {
        printf("No valid square submatrix found.\n");
    }
}

int main()
{
    int matrix_size, number;
    int matrix[N][N];

    printf("Enter the size of the matrix: ");
    scanf("%d", &matrix_size);

    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Enter the number: ");
    scanf("%d", &number);

    // Extract digits from the number
    int digits[10];
    int digit_count = 0;
    while (number > 0)
    {
        digits[digit_count++] = number % 10;
        number /= 10;
    }

    find_largest_square_submatrix(matrix, matrix_size, digits, digit_count);

    return 0;
}
