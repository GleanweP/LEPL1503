#include <stdio.h>

int result;

void sum1(int a1, int b1) {
    a1 = a1 + b1;
}

void sum2(int a, int b) {
	result = a + b;
}

void sum3(int *a, int *b, int *r) {
	*r = *a + *b;
}

void test_assert_sum(int expected, int actual, const char* msg) {
	if (expected==actual) {
	printf("%s: Passed\n", msg);
	} else {
	printf("%s: Failed. Expected %d, got %d\n", msg, expected, actual);
	}

}
void main(int argc, char **argv) {
    int a1 = 5, b1 = 6;

    sum1(a1, b1);
    printf("sum1: %d\n", a1);
    test_assert_sum(5, a1, "Test Case 1");

    int a2 = 3, b2 = 7;
    sum2(a2, b2);
    printf("sum2: %d\n", result);
    test_assert_sum(10, result, "Test Case 2");

    int a3 = 1, b3 = 8;
    int r;
    sum3(&a3, &b3, &r);
    printf("sum3: %d\n", r);
    test_assert_sum(9, r, "Test Case 3");
}
