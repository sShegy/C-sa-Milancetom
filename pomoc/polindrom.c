#include<stdio.h>
#include<stdlib.h>

int main() {
    int a, b, g = 0, h;
    printf("Unesi broj: ");
    scanf("%d", &a);
    h = a;  // Store the original value of 'a' in 'h'

    while (a != 0) {
        b = a % 10;  // Get the last digit of 'a'
        g = g * 10 + b;  // Build the reversed number
        a /= 10;  // Remove the last digit from 'a'
    }

    if (g == h) {
        printf("jeste\n");  // It's a palindrome
    } else {
        printf("nije\n");  // It's not a palindrome
    }

    return 0;
}
