#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef char** Block;

Block make_block(int times) {
    char** result = malloc(11 * sizeof(char*));

    for (int i = 1 ; i <= 10 ; ++i) {
        result[i-1] = malloc(17 * sizeof(char));
        sprintf(result[i-1], "%2d * %2d = %-3d", i, times, i*times);
    }

    return result;
}

void free_block(Block bl) {
    for (int i = 0 ; i < 10 ; ++i)
        free(bl[i]);
    free(bl);
}

void print_ten_blocks(Block* blocks, char* bar) {
    int p1 = rand() % 10;
    int p2 = rand() % 10;

    for (int i = 0 ; i < 5 ; ++i)
        printf("%s  ", bar);
    printf("\n");

    for (int i = 0 ; i < 10 ; ++i) {
        for (int j = 0 ; j < 5 ; ++j) {
            if (i == p1 && j == p2)
                printf("|>%s<|  ", blocks[j][i]);
            else
                printf("| %s |  ", blocks[j][i]);
        }
        printf("\n");
    }

    for (int i = 0 ; i < 5 ; ++i)
        printf("%s  ", bar);
    printf("\n");

    for (int i = 0 ; i < 5 ; ++i)
        printf("%s  ", bar);
    printf("\n");

    for (int i = 0 ; i < 10 ; ++i) {
        for (int j = 5 ; j < 10  ; ++j) {
            if (i == p1 && j == p2)
                printf("|>%s<|  ", blocks[j][i]);
            else
                printf("| %s |  ", blocks[j][i]);
        }
        printf("\n");
    }

    for (int i = 0 ; i < 5 ; ++i)
        printf("%s  ", bar);
    printf("\n");
}

int main() {
    srand(time(NULL));

    char* bar = "+---------------+";
    Block blocks[10];

    for (int i = 0 ; i < 10 ; ++i)
        blocks[i] = make_block(i+1);

    print_ten_blocks(blocks, bar);

    for (int i = 0 ; i < 10 ; ++i)
        free_block(blocks[i]);

    return 0;
}
