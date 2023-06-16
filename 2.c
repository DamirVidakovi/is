/*2. Napisati funkciju koja provjeri je li prva znamenka veca od zadnje, a ako je, ispisat koliko je takvih brojeva u tom polju predanog joj cijelog broja. U svrhu testiranja u
funkciji main() omogućiti korisniku unos isključivo negativnih vrijednosti (ako unos nije negativan broj, ponoviti ga) u 
cjelobrojno polje od 10 elemenata. Pozvati napisanu funkciju sa svakim elementom polja 
kao argumentom $\mathrm{i}$ ispisati na ekran povratnu vrijednost (vrijednosti ispisivati jednu ispod druge).*/

#include <stdio.h>
#include <stdlib.h>

int provjeri_znamenke(int n) {
    int prva_znamenka = abs(n);
    while (prva_znamenka >= 10) {
        prva_znamenka /= 10;
    }
    int zadnja_znamenka = abs(n) % 10;
    if (prva_znamenka > zadnja_znamenka) {
        return 1;
    }
    return 0;
}

int main() {
    int polje[10];
    int i, brojac = 0;
    for (i = 0; i < 10; i++) {
        do {
            printf("Unesite negativan cijeli broj: ");
            scanf("%d", &polje[i]);
        } while (polje[i] >= 0);
        brojac += provjeri_znamenke(polje[i]);
    }
    for (i = 0; i < 10; i++) {
        printf("%d\n", provjeri_znamenke(polje[i]));
    }
    printf("Broj: %d\n", brojac);
    return 0;
}