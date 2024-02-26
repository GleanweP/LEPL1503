#include <stdio.h>
#include <assert.h>
#include <string.h>

int pal(char *str);

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
    char str1[] = "level";
    int result1 = pal(str1);
    test_assert_int(1, result1, "Test Case 1");

    char str3[] = "hello";
    int result3 = pal(str3);
    test_assert_int(0, result3, "Test Case 2");

    char* str4 = NULL;
    int result4 = pal(str4);
    test_assert_int(-1, result4, "Test Case 3");

    char str5[] = "ka y  a k";
    int result5 = pal(str5);
    test_assert_int(1, result5, "Test Case 4");

    return 0;
}

int pal(char *str) {
    if (str == NULL) {
        return -1;
    }

    int length = strlen(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        while (start < length && str[start] == ' ') {
            start++;
        }

        while (end >= 0 && str[end] == ' ') {
            end--;
        }

        if (start < length && end >= 0 && str[start] != str[end]) {
            return 0;
        }

        start++;
        end--;
    }
    return 1;
}

