#include <stdio.h>

int f(N) {
    int I, J = -1, K = 5;
    int s = 0;
    while (N > 0) {
        for (I = 1; I <= K; I++) /*printf("*");*/ s++;
        N -= K;
        if (K == 1) J = 1;
        K += J;
    }

    return s;
}

int main(void) {
    for (int i = 0; i < 10000; i++) {
        printf("%d => %d\n", i, f(i));
    }
}