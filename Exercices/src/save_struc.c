#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

typedef struct point {
    int x;
    int y;
    int z;
} point_t;


/*
 * @pre pt != NULL, pointer to the first point_t in the array
 *      size > 0, the length of the array.
 *      filename != NULL
 * @post writes the array of point_t in the file.
 *       return 0 is everything worked correctly
 *       -1 if open() failed.
 *       -2 if close() failed.
 *       -3 if mmap() failed.
 *       -4 if munmap() failed.
 *       -5 if msync() failed.
 *       -6 if ftruncate() failed.
 *
 */
int save(point_t *pt, int size, char *filename) {
	size_t full_size = size * sizeof(point_t);
	int f = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (f==-1) return -1;
	if (ftruncate(f, full_size) == -1) {
		close(f);
		return -6;
	}
	point_t *map_ptr = mmap(NULL, full_size, PROT_WRITE, MAP_SHARED, f, 0);
	if (map_ptr == MAP_FAILED) {
		close(f);
		return -3;
	}
	memcpy(map_ptr, pt, full_size);
	if (msync(map_ptr, full_size, MS_SYNC) == -1) {
		munmap(map_ptr, full_size);
		close(f);
		return -5;
	}
	if (munmap(map_ptr, full_size) == -1) {
		close(f);
		return -4;
	}
	if (close(f) == -1) return -2;
	return 0;

}
