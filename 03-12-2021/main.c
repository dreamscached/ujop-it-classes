#include <stdio.h>
#include <stdlib.h>

void mojefunkce(int *x, int *y) {
    *x = 2 * (*x);
    x = y;
    return;
}

int main(void) {
    int i = 2, *j;
    j = (int *) malloc(sizeof(int));
    mojefunkce(&i, j);
    printf("i = %d\n", i);
    return 0;
}