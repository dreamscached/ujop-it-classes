#include <stdio.h>

int main(void) {
    printf("Zadej cele cislo ");
    int c;
    if (scanf("%d", &c) != 1) {
        printf("Chyba!\n");
        return 1;
    }
    int d[] = {2, 3, 5, 7};
    int n = 0;
    for (int i = 0; i < 4; i++) {
        if (c % d[i] == 0) {
            if (i == 0) {
                printf("Cislo je delitelne ");
            }
            n = 1;
            printf("%d, ", d[i]);
        }
    }
    if (!n) {
        printf("Cislo neni delitelne");
    }
    printf("\n");
    return 0;
}