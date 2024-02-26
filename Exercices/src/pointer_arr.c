#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int first(void *ptr) {
	int *first_param_ptr = (int *)((char *)ptr + 12);
	int result = *first_param_ptr;
	return result;
}

char second(void *ptr) {
	char *second_param_ptr = (char *)((char *)ptr + 6);
	char result = *second_param_ptr;
	return result;
}

int third(void *ptr) {
	int *third_param_ptr = (int *)((char *)ptr + 45);
	int result = *third_param_ptr;
	return result;
}

int main() {
    // Test case for the first function
    int a_value = 42;
    void *ptr_first = malloc(12 + sizeof(int));
    *(int *)((char *)ptr_first + 12) = a_value;

    int result_first = first(ptr_first);
    printf("Result for first function: %d (expected: %d)\n", result_first, a_value);
    free(ptr_first);

    // Test case for the second function
    char b_value = 'X';
    void *ptr_second = malloc(6 + sizeof(char));
    *(char *)((char *)ptr_second + 6) = b_value;

    char result_second = second(ptr_second);
    printf("Result for second function: %c (expected: %c)\n", result_second, b_value);
    free(ptr_second);

    // Test case for the third function
    int c_value = 123;
    void *ptr_third = malloc(45 + sizeof(int));
    *(int *)((char *)ptr_third + 45) = c_value;

    int result_third = third(ptr_third);
    printf("Result for third function: %d (expected: %d)\n", result_third, c_value);
    free(ptr_third);

    return 0;
}
