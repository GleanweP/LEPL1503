#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

void *calloc2(size_t nmemb, size_t size) {
	if (nmemb == 0 || size == 0) {
        return NULL;
	 }
	size_t total_size = nmemb * size;
	if (total_size / nmemb != size) {
        	return NULL;
	}
	void *ptr = malloc(total_size);
	if (ptr != NULL) {
    		memset(ptr, 0, total_size);
	}
	return ptr;
}


int main() {
    // Test case with valid nmemb and size
    size_t valid_nmemb = 5;
    size_t valid_size = 4;
    void *result_valid = calloc2(valid_nmemb, valid_size);

    assert(result_valid != NULL);
    printf("Memory allocated successfully for valid input.\n");
    free(result_valid);

    // Test case with nmemb = 0
    size_t zero_nmemb = 0;
    size_t non_zero_size = 4;
    void *result_zero_nmemb = calloc2(zero_nmemb, non_zero_size);

    assert(result_zero_nmemb == NULL);
    printf("NULL returned for nmemb = 0.\n");

    // Test case with size = 0
    size_t non_zero_nmemb = 5;
    size_t zero_size = 0;
    void *result_zero_size = calloc2(non_zero_nmemb, zero_size);

    assert(result_zero_size == NULL);
    printf("NULL returned for size = 0.\n");

    // Test case with integer overflow
    size_t overflow_nmemb = SIZE_MAX;
    size_t overflow_size = 2;
    void *result_overflow = calloc2(overflow_nmemb, overflow_size);

    assert(result_overflow == NULL);
    printf("NULL returned for integer overflow.\n");

    return 0;
}
