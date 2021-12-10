#include <stdio.h>
#include <math.h>

void fraction(double x) { // NOLINT(misc-no-recursion)
    if (x < 0) {
        printf("%s", "-(");
        fraction(fabs(x));
        printf("%s", ")");
        return;
    }

    double r;
    for (int b = 1; b < 10000; b++) {
        for (int a = 1; a < 10000; a++) {
            r = (double) a / b;
            if (r == x) {
                printf("%d / %d", a, b);
                return;
            }
        }
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