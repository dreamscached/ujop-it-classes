#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define N_LOCATIONS 26
#define T_STOP "-"

#define true 1

#define fatalErrorExit(n) printf("Chyba!\n"); return (n)

int getStoreIndex(char c) {
    return c >= 'a' && c <= 'z' ? c - 'a' : c - 'A';
}

char getLocationByStoreIndex(int i) {
    return i + 'A'; // NOLINT(cppcoreguidelines-narrowing-conversions)
}

void traverse(char **store, char *visited, char entry) { // NOLINT(misc-no-recursion)
    char *links = store[getStoreIndex(entry)];
    if (!links) return;

    for (int i = 0; i < N_LOCATIONS; i++) {
        if (links[i] && !visited[i]) { // if linked
            visited[i] = true;
            traverse(store, visited, getLocationByStoreIndex(i));
        }
    }
}

int main(void) {
    char **store = calloc(sizeof(char *), N_LOCATIONS);
    for (int i = 0; i < N_LOCATIONS; i++) store[i] = calloc(sizeof(char), N_LOCATIONS);

    printf("Zadej linku (napr. AB nebo - aby ukoncit vstup):\n");
    fflush(stdout);

    while (1) {
        char *in = calloc(sizeof(char), 2);
        if (scanf("%s", in) != 1 || strlen(in) != 2 && strcmp(in, T_STOP) != 0) { fatalErrorExit(1); }
        else if (strlen(in) != 2 && strcmp(in, T_STOP) == 0) {
            scanf("%*c");
            break;
        }

        char from = in[0], to = in[1];
        int fromIdx = getStoreIndex(from), toIdx = getStoreIndex(to);

        store[fromIdx][toIdx] = true;
        store[toIdx][fromIdx] = true;
    }

    char entry;
    printf("Zadej tecku vstupu (napr. A): ");
    if (scanf("%c", &entry) != 1) { fatalErrorExit(1); }

    char *visited = calloc(sizeof(char), N_LOCATIONS);
    traverse(store, visited, entry);

    printf("Navstivene body:");
    for (int i = 0; i < N_LOCATIONS; i++) if (visited[i]) printf(" %c", getLocationByStoreIndex(i));
    printf("\n");
}