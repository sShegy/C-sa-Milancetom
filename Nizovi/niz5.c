#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double rek(int n,int i){
    if(n == 1){
        return n - i;
    }
    return n - i / (i + n / rek(n/2,i*2));
}

double iter(int n){
    int temp = 0;
    int temp_n = n;
    while(temp_n > 1){
        temp_n /= 2;
        temp *= 2;
    }
    double res = 1 - temp;
    while(temp_n < n){
        temp /= 2;
        int a = n,b = n;

        while(b > temp_n){
            a = b;
            b /= 2;
        }
        temp_n = a;
        res = temp_n - temp / (temp + temp_n / res);
    }
    return res;
}





int main(){
    int n;
    scanf("%d",&n);
    printf("REKURZIVNO : %lf \n",rek(n,1));
    printf("ITERATIVNO : %lf \n",iter(n));
    return 0;
}


