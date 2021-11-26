#include <stdio.h>
#include <malloc.h>

int p[] = {5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2};

int main(void) {
    int c;
    if (scanf("%d", &c) != 1) {
        printf("Chyba!\n");
    }

    int *v = calloc(sizeof(int), 12);
    for (int i = 0; i < 11; i++) {
        if (c >= p[i]) {
            v[i] = c / p[i];
            c %= p[i];
        }
    }
    v[11] = c;

    for (int i = 0; i < 11; i++) {
        if (v[i]) {
            printf("%4d Kč ........ %d\n", p[i], v[i]);
        }
    }
    if (v[11]) {
        printf("%4d Kč ........ %d\n", 1, v[11]);
    }
}