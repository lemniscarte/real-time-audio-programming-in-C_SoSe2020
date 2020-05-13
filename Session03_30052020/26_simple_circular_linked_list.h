

#ifndef _26_simple_circular_linked_list_h
#define _26_simple_circular_linked_list_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Globals
typedef struct Node {
    int data;
    struct Node *next;
} node_t;

typedef node_t *p_node_t;
p_node_t g_p_head;
p_node_t current;

// Prototypes
bool is_empty(void);
void insert_node(p_node_t new_node);
void insert_node_1(p_node_t new_node);
void print_list(void);
void remove_node_with_value(int val);
void new_node(void);
void search_node(int val);
node_t* get_last_node(node_t* head);

#endif /* _26_simple_circular_linked_list_h */
