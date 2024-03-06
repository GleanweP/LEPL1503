#include <stdint.h>
#include <stdlib.h>
#include "../headers/distance.h"


int64_t squared_manhattan_distance(const point_t *p1, const point_t *p2, int dimension) {
    int64_t sum = 0;
    for (int i = 0; i < dimension; i++) {    
    	int64_t dx = p2[i].x - p1[i].x;
    	int64_t dy = p2[i].y - p1[i].y;  
        sum +=	llabs(dx - dy);
    }
    return sum * sum;
}


int64_t squared_euclidean_distance(const point_t *p1, const point_t *p2, int dimension) {
    	int64_t sum = 0;
	for (int i = 0; i < dimension; i++) {
		int64_t dx = p2[i].x - p1[i].x;
		int64_t dy = p2[i].y - p1[i].y;
		sum += dx * dx - 2 * dx * dy + dy * dy;
	}
    	return sum;
}

// TODO modifier le fichier header distance.h pour correspondre aux fonctions dans ce fichier
