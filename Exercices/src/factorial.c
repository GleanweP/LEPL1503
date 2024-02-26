#include <stdio.h>


int factorial(int a) {
    if (a<0) return 0;
    if (a==0)
        return 1;
    else
        return a*factorial(a-1);
}

int factorial_tail_recursiv(int i, int a) {
	if (i<0) return 0;
	if (i==0) return a;
	else factorial_tail_recursiv(i-1, i*a);
}

int main() {
	int a=5;
	int b=-2;
	int c=0;
	int d=11;
	printf("test1: a=5 fact(a) = 120 result:%d\n",factorial_tail_recursiv(a, 1));
	printf("test2: b=-2 fact(b) = ERROR (return 0) result:%d\n",factorial_tail_recursiv(b, 1));
	printf("test3: c=0 fact(c) = 1 result:%d\n",factorial_tail_recursiv(c, 1));
	printf("test4: d=11 fact(d) = 39916800 result:%d\n",factorial_tail_recursiv(d, 1));
	return 0;
}
