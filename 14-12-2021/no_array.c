#include <stdio.h>

int main(void) {
    int n;
    printf("Zadej pocet cisel: ");
    if (scanf("%d", &n) != 1) { // NOLINT(cert-err34-c)
        printf("Chyba!\n");
        return 1;
    }

    int x, min = 0, max = 0;
    double mean = 0;
    for (int i = 0; i < n; i++) {
        printf("Zadej %d. cislo: ", i + 1);
        if (scanf("%d", &x) != 1) { // NOLINT(cert-err34-c)
            printf("Chyba!\n");
            return 1;
        }

        if (x < min || !min) min = x; else if (x > max || !max) max = x;
        mean += x / (double) n;
    }

    printf("min = %d max = %d sum = %lf\n", min, max, mean);
}