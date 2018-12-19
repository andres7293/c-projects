#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdlib.h>

struct node_t {
    int key;
    int value;
    struct node_t *next;
};

struct node_t* linked_list_init (int key, int value);
int linked_list_add  (struct node_t *head, int key, int value);
int linked_list_remove (struct node_t *head, int key);
struct node_t * linked_list_search (struct node_t *head, int key);

#endif