#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "headers/portable_endian.h"
#include "headers/point.h"

void parse_binary(FILE *input_file, point_t **vectors, uint64_t *num_vectors, uint32_t *dimension) {
	//reading the dimension and converting
	fread(dimension, sizeof(uint32_t), 1, input_file);
	*dimension = be32toh(*dimension);
	//reading the vectors and converting
	fread(num_vectors, sizeof(uint64_t), 1, input_file);
	*num_vectors = be64toh(*num_vectors);
	//allocating memory for the vectors and testing if malloc failed
	*vectors = malloc(*num_vectors * sizeof(point_t));
	if (*vectors == NULL) {
		fprintf(stderr, "Memory allocation failed !\n");
		exit(EXIT_FAILURE);
	}
	//parsing the file
	for (uint64_t i = 0; i < *num_vectors; i++) {
		fread(&((*vectors)[i].x), sizeof(int64_t), 1, input_file);
		(*vectors)[i].x = be64toh((*vectors)[i].x);
		fread(&((*vectors)[i].y), sizeof(int64_t), 1, input_file);
		(*vectors)[i].y = be64toh((*vectors)[i].y);
	}

}

int main() {
	FILE *file = fopen("exemple.bin", "rb");
	if (file == NULL) {
		fprintf(stderr, "Failed to open the file\n");
		return 1;
	}
	point_t *vectors;
	uint64_t num_vectors;
	uint32_t dimension;
	parse_binary(file, &vectors, &num_vectors, &dimension);

	for (uint64_t i = 0; i < num_vectors; i++) {
		printf("Vector %llu: (%lld, %lld)\n", (unsigned long long) i, (long long) vectors[i].x, (long long) vectors[i].y);
	}	
	free(vectors);
	fclose(file);
	return 0;
}

