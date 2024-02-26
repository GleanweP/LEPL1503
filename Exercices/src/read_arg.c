#include <stdio.h>

int main(int argc, char **argv) {
    if (argc >= 3) {
        for (int i = 1; i < argc; i+=2) {
                printf("%s", argv[i]);
                if (i + 2 < argc) {
                        printf(" ");
                }
        }
    }
    printf("\n");
    return 0;
}
