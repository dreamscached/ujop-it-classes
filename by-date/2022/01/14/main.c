#include <stdio.h>
#include <malloc.h>

int isPrime(int x) {
    if (x < 3) {
        return 1;
    }

    for (int i = 2; i < x / 2; i++) {
        if (x % i == 0) {
            return 0;
        }
    }

    return 1;
}

void sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int x = arr[i], y = arr[i + 1];
        if (x > y) arr[i] = y, arr[i + 1] = x;
    }
}

int main() {
    int x;
    printf("Zadejte cislo: ");
    if (scanf("%d", &x) != 1) { // NOLINT(cert-err34-c)
        printf("Chyba!\n");
    }

    int *factors = malloc(sizeof(int) * (x / 2));
    int cur = 0, y = x;

    for (int i = 2; i < x / 2; i++) {
        if (x % i == 0 && isPrime(i)) {
            factors[cur++] = i;
            y /= i;
        }
    }

    int cur2 = cur;
    while (y > 1) {
        for (int i = 0; i < cur; i++) {
            if (y % factors[i] == 0) {
                factors[cur2++] = factors[i];
                y /= factors[i];
            }
        }
    }

    sort(factors, cur2);

    int *map = calloc(sizeof(int), factors[cur2 - 1]);
    for (int i = 0; i < cur2; i++) {
        map[factors[i]-2]++;
    }

    for (int i = 0; i < factors[cur2 - 1]; i++) {
        if (map[i] > 0) {
            if (i > 0 && i < factors[cur2 - 1] - 1) {
                printf(" * ");
            }

            if (map[i] > 1) {
                printf("%d ^ %d", i + 2, map[i]);
            } else {
                printf("%d", i + 2);
            }
        }
    }
}