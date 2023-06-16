/*4. Napisati funkciju koja računa i vraća aritmetičku sredinu ynamenaka predanog joj stringa.
Ako string ne sadrži niti jednu znamenku, funkcija vraća vrijednost 0. U svrhu testiranja u funkciji main() dinamički zauzeti memoriju za 
30 podataka tipa char (u potpunosti rukovati memorijom). Omogućiti korisniku unos stringa (osigurati da se ne premaši veličina prethodno zauzetog polja). 
Iskoristiti navedeni string u pozivu napisane funkciju te ispisati na ekran povratnu vrijednost. Dodatno, pozvati funkciju sa stringom "H3ll0 W0r1D" 
i na ekran ispisati povratnu vrijednost. Koristiti isključivo pokazivačku notaciju.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

double aritmeticka_sredina_znamenki(char *s) {
    int broj_znamenki = 0;
    int suma_znamenki = 0;
    while (*s != '\0') {
        if (isdigit(*s)) {
            broj_znamenki++;
            suma_znamenki += (*s - '0');
        }
        s++;
    }
    if (broj_znamenki == 0) {
        return 0.0;
    }
    return (double)suma_znamenki / broj_znamenki;
}

int main() {
    char *s = (char*)malloc(30 * sizeof(char));
    if (s == NULL) {
        printf("Neuspjelo alociranje memorije.\n");
        return 1;
    }
    printf("Unesite string: ");
    scanf("%29s", s);
    printf("Aritmeticka sredina znamenki: %lf\n", aritmeticka_sredina_znamenki(s));
    printf("Aritmeticka sredina znamenki za string \"H3ll0 W0r1D\": %lf\n", aritmeticka_sredina_znamenki("H3ll0 W0r1D"));
    free(s);
    return 0;
}