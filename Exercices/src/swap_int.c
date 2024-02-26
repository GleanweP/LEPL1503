#include <stdio.h>
#include <assert.h>

// Function prototype
void swap(int *i, int *j);

// Function to compare two integers and print the result
void test_assert_int(int expected, int actual, const char* message) {
    if (expected == actual) {
        printf("%s: Passed\n", message);
    } else {
        printf("%s: Failed. Expected %d, got %d\n", message, expected, actual);
    }
}

int main() {
    // Test cases
    int a = 5;
    int b = 10;

    printf("Before swapping: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);

    test_assert_int(10, a, "Test Case 1");
    test_assert_int(5, b, "Test Case 2");

    int x = 3;
    int y = -7;

    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swapping: x = %d, y = %d\n", x, y);

    test_assert_int(-7, x, "Test Case 3");
    test_assert_int(3, y, "Test Case 4");

    return 0;
}

void swap(int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}











































