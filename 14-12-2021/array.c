#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define DIAR_SIZE 8

typedef struct DIAR {
    int *val;
    int size;
    int cap;
} DIAR;

DIAR *newDiar() {
    DIAR *val = calloc(sizeof(DIAR), 1);
    val->cap = DIAR_SIZE;
    val->val = malloc(sizeof(int) * val->cap);
    return val;
}

void diarPush(DIAR *diar, int n) {
    if (diar->size + 1 == diar->cap) {
        diar->cap *= 2;
        int *new = malloc(sizeof(int) * diar->cap * 2);

        memcpy(new, diar->val, sizeof(int) * diar->size);
        free(diar->val);

        diar->val = new;
    }
    diar->val[diar->size++] = n;
}

void diarFree(DIAR *diar) {
    free(diar->val);
}

typedef struct INPUT {
    DIAR *val;
    int ok;
} INPUT;

INPUT getInput() {
    INPUT out = {newDiar()};

    for (int i = 0;; i++) {
        int x;
        printf("Zadej %d. cislo: ", i + 1);
        if (scanf("%d", &x) != 1) { // NOLINT(cert-err34-c)
            if (feof(stdin)) {
                printf("\n");
                break;
            }

            printf("Chyba!\n");
            out.ok = 0;
            return out;
        }

        diarPush(out.val, x);
    }

    out.ok = 1;
    return out;
}

void inputFree(INPUT input) {
    diarFree(input.val);
}

typedef struct OUTPUT {
    int min, max;
    double mean;
} OUTPUT;

OUTPUT calculateOutput(INPUT in) {
    OUTPUT out;

    out.min = 0, out.max = 0;
    for (int i = 0; i < in.val->size; i++) {
        int x = in.val->val[i];
        if (x < out.min || !out.min) out.min = x; else if (x > out.max || !out.max) out.max = x;
        out.mean += in.val->val[i] / (double) in.val->size;
    }

    return out;
}

int main() {
    INPUT in = getInput();
    if (!in.ok) {
        return 1;
    }

    OUTPUT out = calculateOutput(in);
    inputFree(in);

    printf("min = %d max = %d mean = %lf\n", out.min, out.max, out.mean);
}