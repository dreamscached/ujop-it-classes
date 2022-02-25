#include <stdio.h>
#include <math.h>

#define SW 20
#define SH 30

int main(void) {
    printf("%s", "Zadej sirku a delku podlahy v cm (oddelene carkou): ");
    int w, h;
    if (scanf("%d,%d", &w, &h) != 2) {
        printf("Chyba!\n");
        return 1;
    }

    int mc = 0, mi = 0;
    double gaps[4] = {0.02, 0.03, 0.04, 0.05};
    for (int i = 0; i < 4; i++) {
        double p = (SW + gaps[i]) * (SH + gaps[i]);
        int c = (int) ((w * h) / p);
        if (c > mc) {
            mc = c;
            mi = i;
        }
    }

    if (mc == 1) {
        printf("Pocet dlazdic: %d\n", mc);
    } else {
        printf("Pocet dlazdic: %d, spara: %d\n", mc, mi + 2);
    }
}