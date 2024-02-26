#include <stdio.h>
/* tab_find

@tab : an array of int
@len : the number of int in tab
@elem : the elem looked for
@return : return the index at which elem is found, else returns -1 if not found. */
int tab_find(int tab[], int len, int elem) {
	if (len<=0) return -1;
	for (int i = 0; i < len; i++) 
    		if (tab[i] == elem)
        		return i;
	return -1;
}

int main() {
    	int arr1[] = {1, 2, 3, 4, 5};
    	int len1 = sizeof(arr1) / sizeof(arr1[0]);
    	int elem1 = 3;
    	int result1 = tab_find(arr1, len1, elem1);
    	printf("Index of %d in arr1: %d\n", elem1, result1);

    	int arr2[] = {10, 20, 30, 40, 50};
    	int len2 = sizeof(arr2) / sizeof(arr2[0]);
    	int elem2 = 25;
    	int result2 = tab_find(arr2, len2, elem2);
    	printf("Index of %d in arr2: %d\n", elem2, result2);
	return 0;
}

