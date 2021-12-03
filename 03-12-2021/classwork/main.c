#include <stdio.h>
#include <math.h>

int main() {
    int a = 0, b = 0, c = 0;
    printf("%s", "Zadejte čísla a, b, c: ");
    if (scanf("%d, %d, %d", &a, &b, &c) != 3) {
        printf("%s\n", "Chyba!");
    }

    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                printf("%s\n", "x ∈ R.");
            } else {
                printf("%s\n", "x ∈ ∅.");
            }
        } else {
            double x = (double) -c / b;
            if (ceil(x) == x) {
                printf("X = %d.\n", (int) x);
            } else {
                printf("X = %f.\n", x);
            }
        }
    } else {
        double d = pow(b, 2) - 4 * a * c;
        double sd = sqrt(d);
        if (d < 0) {
            printf("%s\n", "x ∈ ∅.");
        } else if (d == 0) {
            double x0 = (double) -b / (2 * (double) a);
            if (ceil(x0) == x0) {
                printf("X₀ = %d.\n", (int) x0);
            } else {
                printf("X₀ = %f.\n", x0);
            }
        } else if (d > 0) {
            if (ceil(sd) == sd) {
                double x1 = (-b + sqrt(d)) / (2 * (double) a), x2 = (-b - sqrt(d)) / (2 * (double) a);
                if (x1 == -x2) {
                    if (ceil(x1) == x1) {
                        printf("X₁ٖ₂ = ±%d", (int) x1);
                    } else {
                        printf("X₁ٖ₂ = ±%f`", x1);
                    }
                } else {
                    if (ceil(x1) == x1) {
                        printf("X₁ = %d", (int) x1);
                    } else {
                        printf("X₁ = %f", x1);
                    }
                    if (ceil(x2) == x2) {
                        printf(", X₂ = %d.", (int) x2);
                    } else {
                        printf(", X₂ = %f.", x2);
                    }
                }
            } else {
                printf("%s\n", "x ∉ R.");
            }
        }
    }
}