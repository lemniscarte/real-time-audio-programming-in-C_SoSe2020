//
//  25_DoublyLinkedLists.h
//  Einführung in C
//
//  mail: markus.haedrich@tu-berlin.de
//

#ifndef _25_DoublyLinkedLists_h
#define _25_DoublyLinkedLists_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* A node of the doubly linked list */
typedef struct Node {
    int data;
    struct Node* p_next;
    struct Node* p_prev;
} node_t;

typedef node_t *p_node_t;
/* Store head */
p_node_t g_p_head;
/* Store tail */
p_node_t g_p_tail;

// Declarations
bool check_validity(p_node_t node);
p_node_t get_tail(p_node_t p_head); //??
void delete_node(p_node_t *p_head, p_node_t p_del);
void delete_node_at_position(p_node_t *head_ref, int position);
void push(p_node_t *p_head);
void list_nodes(struct Node* head);
void search_node_backwards(p_node_t p_tail, int searched_data);
void search_node_forward(p_node_t p_head, int searched_data);



#endif /* _25_DoublyLinkedLists_h */
