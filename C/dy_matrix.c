#include "stdlib.h"
#include "stdio.h"
#include <time.h>


struct Results{
    int Max;
    int* Avg_Arr;
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

    print_matrix(matrix, rows, cols);


    res res1;
    res1 = find_avg_and_max(matrix, rows, cols);

    if (res1.Max == -1) {
        return -1;
    }

    printf("Max - %d\n", res1.Max);


    // int arr_len = (int) sizeof(res1.Avg_Arr) / sizeof(int);
    for (int i = 0; i < 20; ++i) {
        printf("Avg arr %d - %d\n", i + 1, res1.Avg_Arr[i]);
    }

    free(res1.Avg_Arr);
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
    
    res res1;
    int max = 0;
    int avg = 0;
    int* avg_arr = (int*) malloc(cols * sizeof(int));


    if (sizeof(res1.Avg_Arr) != sizeof(NULL)) {
        res1.Max = -1;
        return res1;
    }

    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            avg += matrix[i][j];
            printf("%d", i);
        }
        printf("\n");
        printf("Max - %d || Avg - %d\n", max, avg);
        avg_arr[j] = avg / 10;
        if (avg > max) {
            max = avg;
        }

        avg = 0;
    }

    
    res1.Max = max;
    res1.Avg_Arr = avg_arr;

    return res1;
}
