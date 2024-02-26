#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
* Structure node
*
* @next: pointer to the next node in the list, NULL if last node_t
* @value: value stored in the node
*/
typedef struct node {
  struct node *next;
  int value;
} node_t;

/**
* Structure list
*
* @first: first node of the list, NULL if list is empty
* @size: number of nodes in the list
*/
typedef struct list {
  struct node *first;
  int size;
} list_t;

/*
* Create a new node containing the value @value.
*
* @value: value stored in the node
* @next : pointer to next node, initialised to NULL.
* @return: returns the pointer to the newly created node, or NULL if an error occured.
*/
node_t *init_node(int value) {
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
    		return NULL;
	}
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

/*
* Add a node at the head of the list @list and increment the number of nodes in the list (member `size`)
*
* @l: linked list
* @value: value to add to the list
*
* @return: 0 if success, 1 otherwise
*/
int add_node(list_t *list, int value) {
	if (list ==  NULL) return 1;
	node_t *new_node = init_node(value);
	if (new_node == NULL) return 1;
	new_node->next = list->first;
	list->first = new_node;
	list->size++;
	return 0;
}

// Function to free the memory of a list
void free_list(list_t *list) {
    node_t *current = list->first;
    while (current != NULL) {
        node_t *temp = current;
        current = current->next;
        free(temp);
    }
    list->first = NULL;
    list->size = 0;
}

int main() {
    // Test case for creating a new node
    int node_value = 42;
    node_t *test_node = init_node(node_value);

    assert(test_node != NULL);
    assert(test_node->value == node_value);
    assert(test_node->next == NULL);
    free(test_node);
    printf("Test case for creating a new node passed.\n");

    // Test case for adding a node to an empty list
    list_t test_list = {NULL, 0};
    int list_value = 24;
    int result_add_node = add_node(&test_list, list_value);

    assert(result_add_node == 0);
    assert(test_list.size == 1);
    assert(test_list.first != NULL);
    assert(test_list.first->value == list_value);
    assert(test_list.first->next == NULL);
    free_list(&test_list);
    printf("Test case for adding a node to an empty list passed.\n");

    // Test case for adding a node to a non-empty list
    list_t non_empty_list = {init_node(10), 1};
    int new_list_value = 15;
    int result_add_node_non_empty = add_node(&non_empty_list, new_list_value);

    assert(result_add_node_non_empty == 0);
    assert(non_empty_list.size == 2);
    assert(non_empty_list.first != NULL);
    assert(non_empty_list.first->value == new_list_value);
    assert(non_empty_list.first->next != NULL);
    free_list(&non_empty_list);
    printf("Test case for adding a node to a non-empty list passed.\n");

    return 0;
}
