#include <stdio.h>
#include <string.h>

size_t strlen1(const char* s) {
	int i = 0;
	size_t c = 0;
	for (i = 0; s[i]!='\0'; i++) c++;
	return c;
}

// Function to compare two size_t values and print the result
void test_assert_size_t(size_t expected, size_t actual, const char* message) {
    if (expected == actual) {
        printf("%s: Passed\n", message);
    } else {
        printf("%s: Failed. Expected %zu, got %zu\n", message, expected, actual);
    }
}

int main() {
    // Test cases
    const char* str1 = "Hello, World!";
    size_t expected1 = strlen(str1);
    size_t actual1 = strlen1(str1);
    test_assert_size_t(expected1, actual1, "Test Case 1");

    const char* str2 = "";
    size_t expected2 = strlen(str2);
    size_t actual2 = strlen1(str2);
    test_assert_size_t(expected2, actual2, "Test Case 2");

    const char* str3 = "12345";
    size_t expected3 = strlen(str3);
    size_t actual3 = strlen1(str3);
    test_assert_size_t(expected3, actual3, "Test Case 3");

    const char* str4 = "This is a longer string with spaces!";
    size_t expected4 = strlen(str4);
    size_t actual4 = strlen1(str4);
    test_assert_size_t(expected4, actual4, "Test Case 4");

    return 0;
}
