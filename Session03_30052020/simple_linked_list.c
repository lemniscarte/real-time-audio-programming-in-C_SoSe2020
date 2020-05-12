#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

// Globals
// Define node type
typedef struct Node {
    int data;
    struct Node *next;
} node_t;

// Define node pointer type
typedef node_t *p_node_t;
p_node_t g_p_head;

// Function declaration
void new_node(void);
void insert_node(p_node_t new_node);
void remove_node_with_value(int val);
void list_nodes(void);
void search_node(int searched_data);
bool list_available(void);


int main() {
	// Declare vars
    int choice, val;
	// Set global head ptr to NULL
    g_p_head = NULL;

	// Ask for a user action
    do {
        printf(" -1- Insert new node\n");
        printf(" -2- Remove node with value\n");
        printf(" -3- List all nodes\n");
        printf(" -4- Search node\n");
        printf(" -0- Exit\n");
        printf("Choose an action: ");

        scanf ("%d", &choice);

        switch (choice) {
            case 1: new_node();
                break;

            case 2: printf ("Delete value: ");
                scanf ("%d", &val);
                remove_node_with_value(val);
                break;

            case 3: list_nodes();
                break;

            case 4: printf("Search value: ");
                scanf ("%d", &val);
                search_node (val);
                break;

            default: if (choice !=0) {
                printf ("Wrong input - exit\n");
                choice = 0; // Exit program
            }
                break;
        }

    } while (choice != 0);

    printf ("Exit\n");

    return 0;
}



// Function implementation
void insert_node(p_node_t new_node) {
	// Declare help ptr
    p_node_t p_help;

	// If g_p_head == NULL, there is no list
	// Make first entry
    if (g_p_head == NULL) {
        g_p_head = new_node;
		// Set next ptr to NULL, because its the only node (last one and first too)
        new_node->next = NULL;
    }
    else {
		// We have nodes already, then save the head ptr into the help ptr
        p_help = g_p_head;
		// And jump forwards till we find the last node that is pointing to NULL
        while( p_help->next != NULL ) {
            p_help = p_help->next;
        }
		// Place the new node at last position
        p_help->next = new_node;
		// And tell it, thats the last one in this chain
        new_node->next = NULL;
    }
}


void new_node(void) {
	// Allocate node memory from the heap
    p_node_t new_node = malloc(sizeof(node_t));

	// If we get no memory - stop program
    if (new_node == NULL) {
        printf("No memory!?\n");
        return;
    }

	// Ask for data and save it into the node var
    printf("Value for new node: ");
    do {
        scanf("%d", &new_node->data);
    }
    while( getchar() != '\n');
	// Call function that inserts the new node
    insert_node(new_node);
}



void remove_node_with_value(int val) {
	// Declare two help ptrs
    p_node_t p_help_1;
    p_node_t p_help_2;
	// Give the found flag a false by default
    bool found = false;

    // Check if there is a list
    if (list_available() == true) {
        // Case if the searched data is in the head node
        if (g_p_head->data == val) {
            found = true;
            // Next node is the new head
            p_help_1 = g_p_head->next;
            // Release memory of deleted first node
            free(g_p_head);
			// Store new first node in global head ptr
            g_p_head = p_help_1;
            return;
        }
        // Search the data in the rest of the list
        else
        {   // Start at the beginning
            p_help_1 = g_p_head;
            // Traverse the list till searched data is found
            while (p_help_1->next != NULL) {
                p_help_2 = p_help_1->next;
                // Cut the node by connecting the previous and the next node together
                if (p_help_2->data == val) {
                    found = true;
                    p_help_1->next = p_help_2->next;
                  // Free the memory of the removed node
                  free(p_help_2);
                  // And leave
                    break;
                }
                // Step forward
                p_help_1 = p_help_2;
            } // End while
        } // End else
    } // End if

    if (found == false) printf("Data %d not found!\n", val);

}

bool list_available() {
    // Check if there is a list
    if (g_p_head == NULL) {
        printf("No list,\nyou have to create a node first!\n");
        return false;
    } else {
        return true;
    }
}

void list_nodes() {
    // Check if there is a list
    if (list_available() == false) return;

    p_node_t p_help = g_p_head;

    while (p_help != NULL) {
        printf ("%d\n", p_help->data);
        p_help = p_help->next;
    }
}



void search_node(int val) {
    // Check if there is a list
    if (list_available() == false) return;
    
    if (list_available()) {
    // Get the head node pointer
    p_node_t p_help = g_p_head;
    bool found = false;

    // Case the data is in the head node
    if (p_help->data == val) {
        printf ("Data %d found!\n", p_help->data);
        found = true;
        return;
    }

    // Traverse the list till data is found
    while (p_help->next != NULL) {
            p_help = p_help->next;
        
            if (p_help->data == val) {
                printf ("Data %d found!\n", p_help->data);
                found = true;
                return;
            }
    }

    if (found == false) printf("Data %d not found!\n", val);
    }
}