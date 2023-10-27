#include <stdio.h>
#include "clist.h"

void print_clist(CList *list) {
    CListNode *current = clist_head(list);

    if (current == NULL) {
        printf("Circular list is empty.\n");
        return;
    }

    printf("Circular list elements: ");
    while (1) {
        printf("%d ", *(int *)clist_data(current));
        current = clist_next(current);
        if (current == clist_head(list))
            break;
    }
    printf("\n");
}

int main() {
    CList clist;
    clist_init(&clist, NULL);

    int elements[] = {10, 20, 30, 40, 50};
    int num_elements = sizeof(elements) / sizeof(elements[0]);

    // Inserta elementos en la lista circular
    CListNode *current = NULL;
    for (int i = 0; i < num_elements; i++) {
        int *data = (int *)malloc(sizeof(int));
        *data = elements[i];
        if (i == 0) {
            current = clist_head(&clist);
            clist_ins_next(&clist, clist_head(&clist), data);
        } else {
            clist_ins_next(&clist, current, data);
        }
        current = clist_next(current);
        print_clist(&clist);
    }

    // Elimina algunos elementos de la lista circular
    for (int i = 0; i < 2; i++) {
        void *data;
        if (clist_rem_next(&clist, clist_head(&clist), &data) == 0) {
            printf("Removed: %d\n", *(int *)data);
            print_clist(&clist);
            free(data);
        }
    }

    // Destruye la lista circular
    while (clist_size(&clist) > 0) {
        void *data;
        clist_rem_next(&clist, clist_head(&clist), &data);
        free(data);
    }
    clist_destroy(&clist);

    return 0;
}
