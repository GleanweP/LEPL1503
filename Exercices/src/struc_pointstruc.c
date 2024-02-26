#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct product {
    char *name;
    double price;
} product_t;

/*
 * @ptrProd != NULL
 * @return: the price of the product ptrProd
 */
double getPtrPrice(product_t *ptrProd) {
	return ptrProd->price;
}

/*
 * @return: the price of the product prod
 */
double getPrice(product_t prod) {
	return prod.price;
}

/*
 * ptrProd != NULL
 * @name in ptrProd != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getPtrName(product_t *ptrProd) {
	if (ptrProd==NULL) return NULL;
	if (ptrProd->name==NULL) return NULL;

	char *buffer = (char *)malloc((strlen(ptrProd->name) + 1) * sizeof(char));

	if (buffer==NULL) return NULL;
	strcpy(buffer, ptrProd->name);
	return buffer;
}

/*
 * @name in prod != NULL
 * @return: a string on the heap that contains the name of the product ptrProd or NULL if an error happens
 */
char* getName(product_t prod) {
	if (prod.name==NULL) return NULL;
	char *buffer = (char *)malloc((strlen(prod.name) + 1) * sizeof(char));
	if (buffer==NULL) return NULL;
	strcpy(buffer, prod.name);
	return buffer;
}

/*
 * @ptrProd != NULL
 * @name in ptrProd != NULL
 * @name in prod != NULL
 * @return: 1 if the two products are the same, i.e., they have the same price and the same name
 */
int prodEquals(product_t *ptrProd, product_t prod) {
	return ptrProd->price == prod.price && !(strcmp(ptrProd->name, prod.name));
}


int main() {
    // Test case for getPtrPrice with a valid pointer
    product_t valid_product = {"Laptop", 999.99};
    product_t *valid_ptr = &valid_product;
    double result_ptr_price = getPtrPrice(valid_ptr);

    assert(result_ptr_price == valid_product.price);
    printf("Test case for getPtrPrice with a valid pointer passed.\n");

    // Test case for getPrice with a valid product
    product_t another_valid_product = {"Smartphone", 599.99};
    double result_price = getPrice(another_valid_product);

    assert(result_price == another_valid_product.price);
    printf("Test case for getPrice with a valid product passed.\n");

    // Test case for getPtrName with a valid pointer and name
    product_t valid_name_product = {"Tablet", 299.99};
    product_t *valid_name_ptr = &valid_name_product;
    char *result_ptr_name = getPtrName(valid_name_ptr);

    assert(result_ptr_name != NULL);
    assert(strcmp(result_ptr_name, valid_name_product.name) == 0);
    printf("Test case for getPtrName with a valid pointer and name passed.\n");
    free(result_ptr_name);

    // Test case for prodEquals with two equal products
    product_t equal_product_1 = {"Camera", 199.99};
    product_t equal_product_2 = {"Camera", 199.99};
    int result_equals_equal = prodEquals(&equal_product_1, equal_product_2);

    assert(result_equals_equal == 1);
    printf("Test case for prodEquals with two equal products passed.\n");

    // Test case for prodEquals with two different products
    product_t different_product_1 = {"Printer", 149.99};
    product_t different_product_2 = {"Scanner", 149.99};
    int result_equals_different = prodEquals(&different_product_1, different_product_2);

    assert(result_equals_different == 0);
    printf("Test case for prodEquals with two different products passed.\n");

    return 0;
}
