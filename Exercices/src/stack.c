#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    struct node *next;
    char *name;
};


/**
* Remove the top element of the stack and return its content.
*
* @head : pointer to the top of the stack
* @result : pointer to store the popped element
*
* @return 0 if no error, 1 otherwise
*
* pre : @result contains a null-terminated correct string
* post : @result contains the string @name from the element at the top of the stack
*/

int pop(struct node **head, char *result){
	if (*head==NULL) return 1;
	strcpy(result, (*head)->name);
	struct node *temp = *head;
	*head = (*head)->next;
	free(temp);
	return 0;
}

/**
* Add @name at the "top" of the stack.
*
* @head : pointer to the top of the stack
* @name : the string to be placed in the element at the top of the stack
*
* @return 0 if no error, 1 otherwise
*/

int push(struct node **head, const char *value){
}

int main() {
	// Test case 1: Pop from an empty stack
    	struct node *emptyStack = NULL;
    	char result[100];
    	int result1 = pop(&emptyStack, result);
    	printf("Test Case 1: Pop from empty stack - Result: %d\n", result1);  // Expected: 1 (error)

    	// Test case 2: Pop from a non-empty stack
    	struct node *stack = malloc(sizeof(struct node));
    	strcpy(stack->name, "Element1");
    	stack->next = NULL;

    	int result2 = pop(&stack, result);
    	printf("Test Case 2: Pop from non-empty stack - Result: %d, Popped Element: %s\n", result2, result);  // Expected: 0 (success), Popped Element: Element1

    	// Test case 3: Pop from an empty stack after previous pop
    	int result3 = pop(&stack, result);
    	printf("Test Case 3: Pop from empty stack after previous pop - Result: %d\n", result3);  // Expected: 1 (error)

    	// Clean up allocated memory
    	free(stack);

	return 0;
}

