double rek(int n, int i, int gornji, int veci, int manji) {
    // Ako je brojac 'i' stigao do n+1 kraj i dodaj 0
    if (i == n+1) return 0;
    
    // Gornji deo ogledala
    if (i < n/2) {
        if (i % 2 != 0) return (manji + gornji/rek(n, i+1, gornji-1, veci, manji+1));
        else return (veci + gornji/rek(n, i+1, gornji-1, veci-1, manji));
    }
    
    // Donji deo ogledala
    else {
        if (i % 2 != 0) return (manji + gornji/rek(n, i+1, gornji+1, veci, manji+1));
        else return (veci + gornji/rek(n, i+1, gornji+1, veci-1, manji));
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    // n = 6 Pocetno stanje: rek(6, 1, 3, 'F', 'A')
    // n = 7 Pocetno stanje: rek(7, 1, 3, 'G', 'A')
    printf("%lf\n", rek(n, 1, n/2, '@'+n, 'A'));
    return 0;
}
 