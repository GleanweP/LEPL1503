#include <stdint.h>
#include "../headers/distance.h"

int64_t squared_manhattan_distance(const point_t *p1, const point_t *p2) {
    int64_t dx = p2->x - p1->x;
    int64_t dy = p2->y - p1->y;  
    int64_t ar = abs(dx-dy); 
    return ar*ar;
}


int64_t squared_euclidean_distance(const point_t *p1, const point_t *p2) {
    int64_t dx = p2->x - p1->x;
    int64_t dy = p2->y - p1->y;
    int64_t d = dx - dy;
    return d*d;
}


static int64_t abs(int64_t n) {
	if (n<0) return -n;
	else return n;
}
