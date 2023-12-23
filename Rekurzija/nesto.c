#include <stdio.h>

int znak(int i) {
    return i % 2 ? 1 : -1;
}

int Fibonačijev(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }
    int prev = 1;
    int tren = 1;
    int fibo = 0;
    for (int i = 3; i <= n; i++) {
        fibo = prev + tren;
        prev = tren;
        tren = fibo;
    }
    return fibo;
}

int gornji(int n, int i) {
    return (3 * n) - (i - 1) * 3;
}

int levi(int n, int i) {
    return Fibonačijev(i);
}

double rek(int n, int i) {
    if (i == n) {
        return levi(n, i);
    }
    return levi(n, i) + znak(i) * gornji(n, i) * 1.0 / rek(n, i + 1);
}

double iter(int n) {
    double sum = levi(n, n);
    for (int i = n - 1; i >= 1; i--) {
        sum = levi(n, i) + znak(i) * gornji(n, i) * 1.0 / sum;
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("Rek %lf\n", rek(n, 1));
    printf("Iter %lf\n", iter(n));
    return 0;
}
