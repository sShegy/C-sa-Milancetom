#include <stdio.h>
#include<math.h>

/*Napisati funkciju int zameniNajmanjom(int arg, int x) koja vraća ceo broj koji se
dobije kada se u celom broju arg cifra na poziciji x zameni najmanjom cifrom broja.
Pozicije se gledaju od poslednje cifre i počinju od 1. Ako je najmanja cifra na datoj
poziciji, ostaje isti broj. Korišćenjem date funkcije ispisati sve brojeve iz intervala (u kom
su brojevi veći od 100) koje unosi korisnik takve da im cifra stotina nije najmanja cifra.
Napomena: funkcija zameniNajmanjom(7683, 2) vraća broj 7633, u broju 7683 na
poziciju 2 se postavlja cifra 3 koja je najmanja cifra datog broja.
Primer: 230 250
Ispis: 230, 231, 240, 241*/
int cf(int n){
    int b=0;
    while (n)
    {
        b++;
        n/=10;
    }
    return b;
}
int rev(int n){
    int br,h,j,k=cf(n);
    while (k!=0)
    {
        if(k !=1){
            j=n%10;
            h=n%100;
            if(j<h)br=j;
            n/=10;
        }else{
            if(br>(n%10))br=n%10;
        }
        k--;
        return br;
    }
    
    return h;
}

int zamena(int n, int m){
    int a,b,c,d=rev(n),f;
    for (int i = 1; i <=m; i++)
    {
        a=n/m;
        b=n%m;
        b=(b%(m-1)+d*m);
        f=a+b;
    }
    return f;
}
int main (){
    int a,b;
    
    do
    {
        printf(" Unesi broj: ");
        scanf("%d %d",&a,&b);
        printf(" revje %d",rev(a));
        printf("Broj je: %d",zamena(a,b));
    } while (a);
    
    return 0;
}