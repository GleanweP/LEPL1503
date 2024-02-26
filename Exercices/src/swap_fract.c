#include <stdio.h>
#include <assert.h>

// Define the struct
struct fract_t {
    int num;
    int denum;
};

// Function prototype
void swap(struct fract_t *a, struct fract_t *b);

// Function to compare two struct fract_t instances and print the result
void test_assert_fract(struct fract_t expected, struct fract_t actual, const char* message) {
    if (expected.num == actual.num && expected.denum == actual.denum) {
        printf("%s: Passed\n", message);
    } else {
        printf("%s: Failed. Expected (%d/%d), got (%d/%d)\n", message, expected.num, expected.denum, actual.num, actual.denum);
    }
}

int main() {
    // Test cases
    struct fract_t frac1 = {1, 2};
    struct fract_t frac2 = {3, 4};

    printf("Before swapping: frac1 = (%d/%d), frac2 = (%d/%d)\n", frac1.num, frac1.denum, frac2.num, frac2.denum);
    swap(&frac1, &frac2);
    printf("After swapping: frac1 = (%d/%d), frac2 = (%d/%d)\n", frac1.num, frac1.denum, frac2.num, frac2.denum);

    struct fract_t expected1 = {3, 4};
    struct fract_t expected2 = {1, 2};

    test_assert_fract(expected1, frac1, "Test Case 1");
    test_assert_fract(expected2, frac2, "Test Case 2");

    return 0;
}

void swap(struct fract_t *a, struct fract_t *b) {
    struct fract_t temp = *a;
    a->num = b->num;
    a->denum = b->denum;
    b->num = temp.num;
    b->denum = temp.denum;
}

