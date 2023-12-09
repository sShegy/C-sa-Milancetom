#include<stdio.h>
#include<math.h>
/*Koristeći naredbu while i funkciju getchar() za čitanje karaktera obraditi ulaznu
sekvencu slova tako da se proveri da li su zagrade [] i () pravilno zatvorene. Zagrade
mogu biti ugneždene jedna u drugu, s time da je dozvoljen samo jedan nivo
ugneždenosti. Ako su sve zagrade pravilno zatvorene, ispisati “ok”, inače “greska”.
Ulaz: (jedan[dva][tri][četiri]) Izlaz: ok
Ulaz: (jedan][dva) Izlaz: greska*/

int main()
{
    int ch;
    int mala = 0, velika = 0;
    while ((ch = getchar()) != EOF && ch != '\n') {
        if (ch == '(') mala++;
        else if (ch == '[') velika++;
        else if (ch == ')') {
            mala--;
            if (mala == -1) {printf("GRESKA"); return 0;} // [)
        }
        else if (ch == ']') {
            velika--;
            if (velika == -1) {printf("GRESKA"); return 0;} // (]
        }
    }
    if (mala != 0 || velika != 0) printf("GRESKA");
    else printf("OK");
}
