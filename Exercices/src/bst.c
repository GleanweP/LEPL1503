#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
* Node has a value, @value, and two children, @left and @right.
* All the children of @left and itself have a smaller value than the node and all the children of @right and itself have a larger value than node
*/
typedef struct node{
    int value;
    struct node* left; // to smaller values
    struct node* right; // to larger values
} node_t;

typedef struct bt{
    struct node* root;
} bt_t;


int contains_recursive(node_t* current, int value);

int contains_recursive(node_t* current, int value) {
    if (current == NULL) return 0;
    if (value == current->value) return 1;
    if (value < current->value) return contains_recursive(current->left, value);
    else return contains_recursive(current->right, value);
}

/*
* Return 1 if there is a node containing @value in @tree and 0 otherwise.
*/
int contains(bt_t* tree, int value){
	if (tree == NULL || tree->root == NULL) return 0;
	return contains_recursive(tree->root, value);
}

// Function to create a new node
node_t *create_node(int value) {
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a value into the binary tree
node_t *insert_node(node_t *root, int value) {
    if (root == NULL) {
        return create_node(value);
    }

    if (value < root->value) {
        root->left = insert_node(root->left, value);
    } else if (value > root->value) {
        root->right = insert_node(root->right, value);
    }

    return root;
}

int main() {
    // Test case for an empty tree
    bt_t empty_tree = {NULL};
    int value_to_find = 42;
    int result_empty_tree = contains(&empty_tree, value_to_find);

    assert(result_empty_tree == 0);
    printf("Test case for an empty tree passed.\n");

    // Test case for a tree with one node
    bt_t single_node_tree = {create_node(10)};
    int single_node_value = 10;
    int result_single_node_tree = contains(&single_node_tree, single_node_value);

    assert(result_single_node_tree == 1);
    printf("Test case for a tree with one node passed.\n");

    // Test case for a tree with multiple nodes
    bt_t multiple_node_tree = {NULL};
    int values_to_insert[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < sizeof(values_to_insert) / sizeof(values_to_insert[0]); i++) {
        multiple_node_tree.root = insert_node(multiple_node_tree.root, values_to_insert[i]);
    }

    int value_to_find_in_tree = 40;
    int result_multiple_node_tree = contains(&multiple_node_tree, value_to_find_in_tree);

    assert(result_multiple_node_tree == 1);
    printf("Test case for a tree with multiple nodes passed.\n");

    // Free memory
    free(single_node_tree.root);
    free(multiple_node_tree.root);

    return 0;
}

