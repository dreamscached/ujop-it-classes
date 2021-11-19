#include <stdio.h>
#include <stdlib.h>

typedef struct coord {
    int x1, y1, x2, y2;
} coord;

int width(coord c) {
    return abs(c.x2 - c.x1);
}

int height(coord c) {
    return abs(c.y2 - c.y1);
}

void printRect(coord c) {
    for (int i = 0; i < c.x1; i++) {
        printf("\n");
    }

    int w = width(c);
    int h = height(c);
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < c.y1; j++) {
            printf(" ");
        }

        if (i == 0) {
            printf("┌");
            for (int j = 0; j < w; j++) {
                printf("─");
            }
            printf("┐");
        } else if (i == c.y2 - 1) {
            printf("└");
            for (int j = 0; j < w; j++) {
                printf("─");
            }
            printf("┘");
        } else {
            printf("│");
            for (int j = 0; j < w; j++) {
                printf(" ");
            }
            printf("│");
        }

        printf("\n");
    }
}

int main(void) {
    coord c;
    printf("x1, y1, x2, y2: ");
    if (scanf("%d, %d, %d, %d", &c.x1, &c.y1, &c.x2, &c.y2) != 4) {
        printf("Vchod není spravný.");
        return 1;
    }

    printRect(c);

    return 0;
}