#include <stdio.h>

int main(void) {
    int I, N, A[1000];
    scanf("%d", &N);
    for (I = 1; I <= N; I++) A[I] = 1;
    for (I = 2; I < N; I++) A[I] = A[I - 1] + A[I] + A[I + 1];
    for (I = 2; I <= N; I++) A[I] = A[I - 1] + A[I];
    printf("%d\n", A[N]);
}