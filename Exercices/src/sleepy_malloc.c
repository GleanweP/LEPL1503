#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>

/* Wrapper to the malloc system call.
 * If malloc fails, sleep for 5 seconds, and then try again.
 * If malloc failed 10 times in a row, return NULL.
 */
void *sleepy_malloc(size_t s) {
	void *ptr = NULL;
	int attempts = 0;
	const int max_attempts = 10;
	const int sleep_duration = 5;
	while (attempts < max_attempts) {
    		ptr = malloc(s);
    		if (ptr != NULL) {
        		break;
    		}
    	sleep(sleep_duration);
    	attempts++;
	}
	return ptr;
}

int main() {
    // Test case with successful allocation on the first attempt
    size_t successful_size = 10;
    void *result_successful = sleepy_malloc(successful_size);

    assert(result_successful != NULL);
    printf("Memory allocated successfully on the first attempt.\n");
    free(result_successful);

    // Test case with unsuccessful allocation (reaching max attempts)
    size_t unsuccessful_size = SIZE_MAX;  // Attempting to allocate the maximum possible size
    void *result_unsuccessful = sleepy_malloc(unsuccessful_size);

    assert(result_unsuccessful == NULL);
    printf("NULL returned after reaching maximum attempts.\n");

    // Test case with a small sleep duration and multiple attempts
    size_t small_sleep_size = 5;
    void *result_small_sleep = sleepy_malloc(small_sleep_size);

    assert(result_small_sleep != NULL);
    printf("Memory allocated successfully with multiple attempts and small sleep duration.\n");
    free(result_small_sleep);

    return 0;
}
