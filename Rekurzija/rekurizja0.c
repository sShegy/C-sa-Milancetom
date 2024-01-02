#include <stdio.h>
#include <math.h>
double rek(int p, int q,int i, int n){
    if(i == n/2)
        return p - q;
    if(i % 2)
        return p - 1.0 * q / rek(p,q,i+1,n);
    return q + 1.0 * p / rek(p/2,q*2,i+1,n);
}

int main(){
    int n;
    scanf("%d",&n);
    printf("[REK] %f\n", rek(n,1,1,n));


    return 0;
}