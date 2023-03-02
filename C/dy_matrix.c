#include "stdlib.h"
#include "stdio.h"
#include <time.h>

struct Results{
    int Max;
    int** Avg_Arr;
}; typedef struct Results res;


void free_matrix(int** matrix, int rows);
int** create_matrix(int rows, int cols);
void fill_matrix(int** matrix, int rows, int cols);
void print_matrix(int** matrix, int rows, int cols);
res find_avg_and_max(int** matrix, int rows, int cols);


int main() {
    int rows = 10;
    int cols = 20;

    int** matrix = create_matrix(rows, cols);

    if (matrix == NULL) {
        printf("Unable to allocate memory for matrix\n");
        return 0;
    }

    fill_matrix(matrix, rows, cols);

    // print_matrix(matrix, rows, cols);

    find_avg_and_max(matrix, rows, cols);

    free_matrix(matrix, rows);
}



void free_matrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


int** create_matrix(int rows, int cols) {
    int** matrix = (int**) malloc(rows * sizeof(int*));

    if (matrix == NULL) {
        return NULL;
    }

    for (int i = 0; i < rows; ++i) {
        matrix[i] = (int*) malloc(cols * sizeof(int));

        if (matrix[i] == NULL) {
            free_matrix(matrix, i);
            return NULL;
        }
    }
    return matrix;
}


void fill_matrix(int** matrix, int rows, int cols) {
    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
}


void print_matrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
    }
    printf("\n");
}

res find_avg_and_max(int** matrix, int rows, int cols) {
    int y = 1;
    int max = 0;
    int avg = 0;
    int** avg_arr = create_matrix(y, cols);

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            avg += matrix[i][j];
        }

        if (avg > max) {
            max = avg;
        }
        avg_arr[y][j] = avg / 10;
        avg = 0;
    }

    res res1;
    res1.Max = max;
    res1.Avg_Arr = avg_arr;

    free_matrix(avg_arr, y);
    return res1;
}