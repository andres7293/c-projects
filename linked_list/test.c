#include <stdio.h>
#include <stdint.h>
#include "linked_list.h"

int size = 500;

int main (void) {
    struct node_t *head;
    head = linked_list_init(0, 0);
    for (int i = 1; i < size; i++) {
        linked_list_add(head, i, i);
    }

    linked_list_remove(head, 1);
    struct node_t *node = linked_list_search(head, 315);

    printf("key = %i : value = %i\n", node->key, node->value);

    return 0;
}