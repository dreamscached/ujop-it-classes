#include <malloc.h>

#define LList struct LListNode*
#define null 0

struct LListNode {
    int value;
    LList next;
    LList last;
} LList_T;

LList LList_New() {
    LList list = malloc(sizeof(LList_T));
    list->last = list;
    return list;
}

void LList_Push(LList list, int val) {
    LList node = LList_New();
    node->value = val;

    list->last->next = node;
    list->last = node;
}

int LList_Len(LList list) {
    int len = 0;
    LList node = list;
    while ((node = node->next) != null) len++;
    return len;
}

LList LList_Node(LList list, int index) {
    LList node = list;
    for (int i = 0; i < index && node != null; i++) node = node->next;
    return node;
}

int LList_Count(LList list, int value) {
    int count = 0;

    int len = LList_Len(list);
    for (int i = 0; i < len; i++) {
        int item = LList_Node(list, i)->value;
        if (item == value) count++;
    }

    return count;
}

int main(void) {
    LList list = LList_New();

    for (int i = 1;; i++) {
        printf("Zadej prvek %d.: ", i);
        fflush(stdout); // ensure this prints out

        int n;
        if (scanf("%d", &n) != 1) { // NOLINT(cert-err34-c)
            getchar(); // skip one char (likely \n)
            break;
        }

        LList_Push(list, n);
    }

    printf("\n\nZadej prvek ktery chces zpocitat: ");
    fflush(stdout); // ensure this prints out

    int c;
    if (scanf("%d", &c) != 1) { // NOLINT(cert-err34-c)
        printf("Chyba!\n");
        return 1;
    }

    printf("Pocet prvku %d je %d.", c, LList_Count(list, c));

    printf("\nZadane prvky:\n");
    fflush(stdout); // ensure this prints out

    int len = LList_Len(list);
    if (len > 0) printf("%d", LList_Node(list, 0)->value);
    for (int i = 1; i <= len; i++) printf(", %d", LList_Node(list, i)->value);
}