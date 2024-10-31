#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a, b = 0, c, d = 0, j;
    printf("Unesi broj: ");
    scanf("%d", &a); // Read the input number

    c = a;     // Store the original number in 'c'
    int u = a; // Store the original number in 'u' for comparison

    // Calculate the number of digits in 'a'
    while (a != 0)
    {
        b++;
        a /= 10;
    }

    // Reset 'a' to the original value stored in 'c'
    a = c;

    // Calculate the sum of cubes of digits
    while (b != 0)
    {
        j = a % 10;        // Get the last digit
        a /= 10;           // Remove the last digit
        d = d + pow(j, 3); // Add the cube of the digit to 'd'
        b--;
    }

    // Check if the sum of cubes of digits equals the original number
    if (d == u)
    {
        printf("jeste\n"); // It is an Armstrong number
    }
    else
    {
        printf("nije\n"); // It is not an Armstrong number
    }

    return 0;
}
