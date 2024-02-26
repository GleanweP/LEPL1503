#include <stdio.h>

int absval(int i) {
	if (i >= 0)
    		return i;
	else
    		return -i;
}


int main() {
	int a=0;
	int b=5;
	int c=-5;
	printf("test1: a=0 abs(a)=0 result:%d\n",absval(a));
	printf("test2: b=5 abs(b)=5 result:%d\n",absval(b));
	printf("test3: c=-5 abs(c)=5 result:%d\n",absval(c));
	return 0;
}
