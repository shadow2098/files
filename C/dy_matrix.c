#include "stdlib.h"
#include "stdio.h"
#include <time.h>

int main() {
    int rows = 10;
    int cols = 20;

    int** matrix = (int**) malloc(rows * sizeof(int*));

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*) malloc(cols * sizeof(int));
    }

    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
    }

    int avg = 0;
    for (int j = 0; j < rows; ++j) {
        for (int y = 0; y < cols; ++y) {
            avg += matrix[j][y];
        }
        printf("%d\n", avg / 20);
        avg = 0;
    }
    
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}