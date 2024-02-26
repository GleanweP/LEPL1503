#include <stdio.h>
#include <assert.h>

int strcasecmp_custom(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        char char1 = (*s1 >= 'A' && *s1 <= 'Z') ? *s1 + ('a' - 'A') : *s1;
        char char2 = (*s2 >= 'A' && *s2 <= 'Z') ? *s2 + ('a' - 'A') : *s2;

        if (char1 != char2) {
            return char1 - char2;
        }

        s1++;
        s2++;
    }
    return *s1 - *s2;
}

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
    const char* s1_1 = "hello";
    const char* s2_1 = "HELLO";
    int result1 = strcasecmp_custom(s1_1, s2_1);
    test_assert_int(0, result1, "Test Case 1");

    const char* s1_2 = "AbCdEf";
    const char* s2_2 = "aBcDeF";
    int result2 = strcasecmp_custom(s1_2, s2_2);
    test_assert_int(0, result2, "Test Case 2");

    const char* s1_3 = "world";
    const char* s2_3 = "WORLD";
    int result3 = strcasecmp_custom(s1_3, s2_3);
    test_assert_int(0, result3, "Test Case 3");

    const char* s1_4 = "abc";
    const char* s2_4 = "def";
    int result4 = strcasecmp_custom(s1_4, s2_4);
    test_assert_int('a' - 'd', result4, "Test Case 4");

    return 0;
}

