#include <stdio.h>
#include <math.h>

void fraction(double x) { // NOLINT(misc-no-recursion)
    if (x < 0) {
        printf("%s", "-");
        fraction(fabs(x));
        return;
    }

    double h1 = 1, h2 = 0, k1 = 0, k2 = 1;
    double b = x;
    do {
        double a = floor(b);
        double u = h1; h1 = a * h1 + h2; h2 = u;
        u = k1; k1 = a * k1 + k2; k2 = u;
        b = 1 / (b - a);
    } while (fabs(x - h1 / k1) > x * 1.0e-6);

    if (h1 == (int) h1) {
        printf("%d", (int) h1);
    } else {
        printf("%lf", h1);
    }

    printf("%s", " / ");

    if (k1 == (int) k1) {
        printf("%d", (int) k1);
    } else {
        printf("%lf", k1);
    }
}

int main() {
    double x;
    printf("Zadej cislo: ");
    if (scanf("%lf", &x) != 1) { // NOLINT(cert-err34-c)
        printf("%s\n", "Chyba!");
        return 1;
    }

    fraction(x);
}