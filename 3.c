/*3. Napisati funkciju koja računa i vraća.
$$
f(\mathbf{x})=\frac{10^2}{n^2} \cdot \sum_{i=3}^n \frac{x_{i-2}^2+\left|x_{i-1}\right|+1}{\left|x_i\right|+1}, \quad \mathbf{x}=\left(x_1, \ldots, x_n\right) \in \mathbb{Z}^n
$$
U svrhu testiranja u funkciji main() dinamički zauzeti memoriju za 10 podataka tipa int (u potpunosti rukovati memorijom). Popuniti tako dobiveno polje pseudo-slučajnim brojevima iz $[-15,5] \subset Z$. Iskoristiti navedeno polje u pozivu napisane funkcije te ispisati na ekran povratnu vrijednost. Koristiti isključivo pokazivačku notaciju.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int f(int *x, int n)
{
    int i;
    double suma = 0;
    for (i = 2; i < n; i++)
        suma += (pow(x[i - 2], 2) + abs(x[i - 1]) + 1) / (abs(x[i]) + 1);
    return (int)(pow(10, 2) / pow(n, 2) * suma);
}

int main(void)
{
    int *x, i;
    int DG = -15, GG = 5;
    srand((unsigned)time(NULL));
    int n = 10;

    x = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        x[i] = rand() % (GG + 1 - DG) + DG;

    printf("Povratna vrijednost funkcije f: %d\n", f(x, n));

    free(x);
    return 0;
}