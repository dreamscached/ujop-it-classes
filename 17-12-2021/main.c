// x is left -> right
// y is top -> bottom

#include <malloc.h>


typedef struct Point {
    int x, y;
} POINT;

void normalizePts(POINT *p1, POINT *p2) {
    if (p1->x > p2->x && p1->y > p2->y) {
        POINT t = *p1;
        *p1 = *p2;
        *p2 = t;
    }
}

int validatePt(POINT p) {
    return p.x < 0 || p.x > 79 || p.y < 0 || p.y > 79;
}

typedef struct Rectangle {
    POINT p1, p2;
} RECTANGLE;

void normalizeRects(RECTANGLE *r1, RECTANGLE *r2) {
    if (r1->p1.x > r2->p1.x && r1->p1.y > r2->p1.y) {
        RECTANGLE t = *r1;
        *r1 = *r2;
        *r2 = t;
    }
}

#define N_RECTS 2
#define FIRST 0
#define SECOND 1

int getInputRects(RECTANGLE *rects) {
    for (int i = 0; i < N_RECTS; i++) {
        RECTANGLE *r = &rects[i];
        printf("Zadej souradnice %d. obdelnika oddelene carkou (levy hodni roh, pravy spodni roh): ", i + 1);
        if (scanf("%d, %d, %d, %d", &r->p1.x, &r->p1.y, &r->p2.x, &r->p2.y) != 4) { // NOLINT(cert-err34-c)
            return 1;
        }

        if (validatePt(r->p1) || validatePt(r->p2)) {
            return 1;
        }

        normalizePts(&r->p1, &r->p2);
    }

    normalizeRects(&rects[FIRST], &rects[SECOND]);

    return 0;
}

int areRectanglesContained(RECTANGLE r1, RECTANGLE r2) {
    return (r1.p1.x > r2.p1.x && r1.p1.y > r2.p1.y && r1.p2.x < r2.p2.x && r1.p2.y < r2.p2.y) ||
           (r2.p1.x > r1.p1.x && r2.p1.y > r1.p1.y && r2.p2.x < r1.p2.x && r2.p2.y < r1.p2.y);
}

int areRectanglesEqual(RECTANGLE r1, RECTANGLE r2) {
    return r1.p1.x == r2.p1.x && r1.p1.y == r2.p1.y && r1.p2.x == r2.p2.x && r1.p2.y == r2.p2.y;
}

char *getChar(POINT cur, RECTANGLE r1, RECTANGLE r2, int insNc, int eq) {
    if (cur.x == r1.p2.x && cur.y == r1.p2.y && cur.x == r2.p1.x && cur.y == r2.p1.y) {
        return "┼";
    } else if (cur.x == r1.p1.x && cur.y == r1.p1.y ||
               cur.x == r2.p1.x && cur.y == r2.p1.y) {
        if (!insNc && !eq) {
            if (cur.x == r2.p1.x && cur.y == r1.p1.y && !(cur.x == r1.p1.x && cur.y == r1.p1.y)) {
                return "┬";
            } else if (cur.x == r1.p1.x && cur.y == r1.p2.y ||
                       cur.x == r1.p2.x && cur.y == r2.p1.y ||
                       cur.x == r1.p1.x && cur.y == r2.p1.y) {
                return "├";
            }
        }
        return "┌";
    } else if (cur.x == r1.p1.x && cur.y == r1.p2.y ||
               cur.x == r2.p1.x && cur.y == r2.p2.y) {
        if (!insNc && !eq) {
            if (cur.x == r1.p2.x && cur.x == r2.p1.x) {
                return "├";
            }
        }
        return "└";
    } else if (cur.x == r1.p2.x && cur.y == r1.p1.y ||
               cur.x == r2.p2.x && cur.y == r2.p1.y) {
        if (!insNc && !eq) {
            if (cur.x == r2.p2.x && cur.y == r1.p2.y) {
                return "┬";
            }
        }
        return "┐";
    } else if (cur.x == r1.p2.x && cur.y == r1.p2.y ||
               cur.x == r2.p2.x && cur.y == r2.p2.y) {
        if (!insNc && !eq) {
            if (cur.y == r1.p2.y && cur.x > r1.p1.x && cur.x < r1.p2.x) {
                return "┴";
            }
        }
        return "┘";
    } else if ((cur.x >= r1.p1.x && cur.x <= r1.p2.x && (cur.y == r1.p1.y || cur.y == r1.p2.y)) ||
               cur.x >= r2.p1.x && cur.x <= r2.p2.x && (cur.y == r2.p1.y || cur.y == r2.p2.y)) {
        if (!insNc && !eq) {
            if (cur.x == r2.p1.x && cur.y == r1.p2.y ||
                cur.x == r1.p2.x && cur.y == r2.p1.y ||
                cur.x == r1.p1.x && cur.y == r2.p1.y ||
                cur.x == r2.p2.x && cur.y == r1.p2.y) {
                return "┼";
            }
        }

        return "─";
    } else if ((cur.y >= r1.p1.y && cur.y <= r1.p2.y && (cur.x == r1.p1.x || cur.x == r1.p2.x)) ||
               cur.y >= r2.p1.y && cur.y <= r2.p2.y && (cur.x == r2.p1.x || cur.x == r2.p2.x)) {
        return "│";
    } else {
        return " ";
    }
}

#define SCREEN_W 79
#define SCREEN_H 79

void renderRects(RECTANGLE r1, RECTANGLE r2) {
    int insNc = areRectanglesContained(r1, r2);
    int eq = areRectanglesEqual(r1, r2);

    for (int i = 0; i < SCREEN_H; i++) {
        for (int j = 0; j < SCREEN_W; j++) {
            POINT cur = {j, i};
            printf("%s", getChar(cur, r1, r2, insNc, eq));
        }
        printf("\n");
    }
}


int main() {
    RECTANGLE *rects = calloc(sizeof(RECTANGLE), N_RECTS);
    if (getInputRects(rects)) {
        printf("%s\n", "Error!");
        return 1;
    }

    renderRects(rects[0], rects[1]);
}