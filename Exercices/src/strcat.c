#include <stdio.h>
#include <string.h>
#include <assert.h>

char* strcat_custom(char* dest, const char* src) {
    size_t dest_len = strlen(dest);
    size_t i;
    size_t n = strlen(src);

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[dest_len + i] = src[i];
    }
    dest[dest_len + i] = '\0';

    return dest;
}


// Function to compare two strings and print the result
void test_assert_str(const char* expected, const char* actual, const char* message) {
    if (strcmp(expected, actual) == 0) {
        printf("%s: Passed\n", message);
    } else {
        printf("%s: Failed. Expected \"%s\", got \"%s\"\n", message, expected, actual);
    }
}

int main() {
    // Test cases
    char dest1[20] = "Hello, ";
    const char* src1 = "World!";
    strcat(dest1, src1);
    test_assert_str("Hello, World!", dest1, "Test Case 1");

    char dest2[10] = "123";
    const char* src2 = "456";
    strcat(dest2, src2);
    test_assert_str("123456", dest2, "Test Case 2");

    char dest3[15] = "";
    const char* src3 = "Concatenate";
    strcat(dest3, src3);
    test_assert_str("Concatenate", dest3, "Test Case 3");

    return 0;
}
