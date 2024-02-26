#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
* Creates a buffer that has the same size as src, and copies the content of src to this buffer.
*
* @src: string to be copied
* @return: return pointer. if src == NULL or in case of error, return NULL
*
* Remember that strings are terminated with '\0' and that strlen("abc") returns 3 even if 4 bytes are required to store this string.
*/
char *buf_strcpy(const char *src) {
	if (src==NULL) return NULL;

	size_t length = 0;
	while (src[length] != '\0') length++;

	char *buffer = (char *)malloc((length + 1) * sizeof(char));

	if (buffer==NULL) return NULL;

	for (size_t i = 0; i <= length; i++) {
       		buffer[i] = src[i];
   	}
	return buffer;
}

int main() {
    // Test case with a non-empty string
    const char *testString = "Hello, World!";
    char *result = buf_strcpy(testString);

    assert(result != NULL);
    printf("Result: %s\n", result);
    free(result);  // Don't forget to free the allocated memory

    // Test case with a NULL string
    const char *nullString = NULL;
    result = buf_strcpy(nullString);

    assert(result == NULL);
    printf("Result for NULL string: NULL (as expected)\n");

    return 0;
}
