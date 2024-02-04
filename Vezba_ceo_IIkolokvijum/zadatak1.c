#include <stdio.h>
#include <string.h>
#define SIZE 100
int dalslovo(char c)
{
    if((c>='a' && c<='z')  (c>='A' && c<='Z'))
        return 1;
    else
        return 0;
}
int dalsamoglasnik(char c)
{
    if(c=='a'  c=='e'  c=='i'  c=='o' || c=='u')
        return 1;
    else
        return 0;
}
void uklonislova(char str[],int velicina,int samoglasnik,int pocetak)
{
    int k=0;
    if(samoglasnik%2!=0)
    {
        for (int i = pocetak; i < velicina+pocetak+1; i++)
        {
            if(!dalsamoglasnik(str[i]))
            {
                //printf("%c\n",str[i]);
                str[i]=' ';
            }
        }
    }
    else
    {
        for (int i = pocetak; i < velicina+pocetak+1; i++)
        {
            if(dalsamoglasnik(str[i]))
            {
                str[i]=' ';
            }

        }
    }

}

int main() {
    char str[SIZE];
    fgets(str,100,stdin);
    int velicina=0;
    int samoglasnik=0;
    int niz[SIZE];
    for (int i = 0,j=0; i < strlen(str); i++)
    {
        if(str[i]==' ')
        {
            niz[j]=i;
            j++;
        }

    }
   int pocetak=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if(dalslovo(str[i]))
        {
            velicina++;
            if(dalsamoglasnik(str[i]))
                samoglasnik++;
        }
        else if(velicina>0 && !dalslovo(str[i]))
        {

            uklonislova(str,velicina,samoglasnik,pocetak);
            velicina=0;
            pocetak=i;
            samoglasnik=0;
        }


    }

    fputs(str,stdout);
    return 0;
}
'''#include <stdio.h>
#include <string.h>
#define SIZE 100
int dalslovo(char c)
{
    if((c>='a' && c<='z')  (c>='A' && c<='Z'))
        return 1;
    else
        return 0;
}
int dalsamoglasnik(char c)
{
    if(c=='a'  c=='e'  c=='i'  c=='o' || c=='u')
        return 1;
    else
        return 0;
}
void uklonislova(char str[],int velicina,int samoglasnik,int pocetak)
{
    int k=0;
    if(samoglasnik%2!=0)
    {
        for (int i = pocetak; i < velicina+pocetak+1; i++)
        {
            if(!dalsamoglasnik(str[i]))
            {
                //printf("%c\n",str[i]);
                str[i]=' ';
            }
        }
    }
    else
    {
        for (int i = pocetak; i < velicina+pocetak+1; i++)
        {
            if(dalsamoglasnik(str[i]))
            {
                str[i]=' ';
            }

        }
    }

}

int main() {
    char str[SIZE];
    fgets(str,100,stdin);
    int velicina=0;
    int samoglasnik=0;
    int niz[SIZE];
    for (int i = 0,j=0; i < strlen(str); i++)
    {
        if(str[i]==' ')
        {
            niz[j]=i;
            j++;
        }

    }
   int pocetak=0;
    for (int i = 0; i < strlen(str); i++)
    {
        if(dalslovo(str[i]))
        {
            velicina++;
            if(dalsamoglasnik(str[i]))
                samoglasnik++;
        }
        else if(velicina>0 && !dalslovo(str[i]))
        {

            uklonislova(str,velicina,samoglasnik,pocetak);
            velicina=0;
            pocetak=i;
            samoglasnik=0;
        }


    }

    fputs(str,stdout);
    return 0;
}