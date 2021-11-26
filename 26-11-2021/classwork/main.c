#include <stdio.h>
#include <malloc.h>

int main(void) {
    int c;
    if (scanf("%d", &c) != 1) {
        printf("Chyba!\n");
    }

    int *p2 = calloc(sizeof(int), 12);
    int x = 5000;
    p2[0] = x;
    int j = 1;
    while (x > 0) {
        if (x / 1000 == 5) {
            x = 2000;
        } else if (x / 100 == 5) {
            x = 200;
        } else if (x / 10 == 5) {
            x = 20;
        } else {
            x /= 2;
        }

        p2[j++] = x;
    }

    for (int i = 0; i < 11; i++) {
        if (c >= p2[i]) {
            printf("%4d Kč ........ %d\n", p2[i], c / p2[i]);
            c %= p2[i];
        }
    }
    if (c) {
        printf("%4d Kč ........ %d\n", 1, c);
    }
}