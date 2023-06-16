/*1. Omogućiti korisniku unos dimenzija matrice (2-D polja) $m \times n$, gdje je $3 \less m \leq 10 i 4 \less n \leq$ 12.
Popuniti matricu pseudo-slučajnim brojevima iz $[1,3] \subset Z$. Odrediti i na ekran ispisati koliko je bilo redaka u kojima su 
svi elementi jednaki.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int m, n, i, j, brojac = 0;
    int DG = 1, GG = 3;
    int matrica[10][12];
    srand((unsigned)time(NULL));

    do
    {
        printf("Unesite dimenzije matrice m: ");
        scanf("%d", &m);

        if (m <= 3 || m > 10)
            printf("Neispravan unos!\n");
    } while (m <= 3 || m > 10 );

    do
    {
        printf("Unesite dimenzije matrice n: ");
        scanf("%d", &n);

        if (n <= 4 || n > 12)
            printf("Neispravan unos!\n");
    } while (n <= 4 || n > 12);
    

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            matrica[i][j] = DG + rand() / RAND_MAX * (GG - DG);

    
    for (i = 0; i < m; i++)
    {
        int brojac2 = 0;
        for (j = 0; j < n; j++)
            if (*(*(matrica + i)+j) == matrica[i][0])
                brojac2++;
        if (brojac2 == n)
            brojac++;
    }

    printf("Broj redaka u kojima su svi elementi jednaki: %d\n", brojac);

    return 0;
}
