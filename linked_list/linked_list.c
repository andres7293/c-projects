#include "linked_list.h"

struct node_t * linked_list_init (int key, int value) {
    struct node_t *head = malloc(sizeof(struct node_t));
    if (head == 0) {
        return 0;
    }
    head->next = 0;
    head->key = key;
    head->value = value;
    return head;
}

int linked_list_add  (struct node_t *head, int key, int value) {
    //search last node
    struct node_t *current = head;
    while (current->next != 0) {
        current = current->next;
    }
    struct node_t *new = malloc(sizeof(struct node_t));
    if (new == 0) {
        return -1;
    }
    new->next = 0;
    new->key = key;
    new->value = value;
    current->next = new;
    return 0;
}

int linked_list_remove (struct node_t *head, int key) {
    //search given node
    struct node_t *current = head;
    struct node_t *prev = head;
    while (current != 0) {
        if (current->key == key) {
            prev->next = current->next; 
            free(current);
            return 0;
        }
        prev = current;
        current = current->next;
    }
    return -1;
}

struct node_t * linked_list_search (struct node_t *head, int key) {
    struct node_t *current = head;
    while (current != 0) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return 0;
}
