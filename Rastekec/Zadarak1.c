#include<stdio.h>
#include<math.h>

int main(){
    int a=1;
    int i;
    for (int i = -10; i < 11; ++i)
    {
        if (i>10)
        {
            continue;
        }
        else{
            a=a+2;
            break;
            
        }
        
    }
    printf("%d",a);

    
}