#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "file_operations.h"

struct errors {
    int err[10];
    int n;
}; typedef struct errors errors;

void print_matrix(char** arr, int rows, int cols);
errors read_file(char* file_name, char** arr, char* flag);
char** create_matrix(int rows, int cols);
void free_matrix(char** arr, int rows);
void replace_erros(char** arr, errors object, int len);



int main() {
    int rows = 10;
    int cols = 20;
    char** arr_user = create_matrix(rows, cols);

    char file_name[20];
    get_variable(file_name);
    
    char flag[20];
    printf("Consequence of simbols to to be replaced: ");
    fgets(flag, 20 , stdin);

    errors object = read_file(file_name, arr_user, flag);
    if (object.n == 0) {
        printf("No similar consequences were found");
        return 0;
    }

    print_matrix(arr_user, rows, cols);
/*
    printf("\nn object is %d\n", object.n);

    for (int i = 0; i < object.n; ++i) {
        printf("object.err[%d] = %d\n", i, object.err[i]);
    }
*/
    replace_erros(arr_user, object, strlen(flag) - 1);

    print_matrix(arr_user, rows, cols);

    write_to_file(file_name, arr_user, rows);

    free_matrix(arr_user, rows);

    return 0;
}


errors read_file(char* file_name, char** arr_user, char* flag) {
    FILE *f = fopen(file_name, "r");
    int len = strlen(flag) - 1;
    // char text[20];

    if (f == NULL) {
        printf("Unable to open file!\n");
    }

    errors object;

    int i = 0;
    object.n = 0;

    while (fgets(arr_user[i], 20, f) != NULL) {
        if (strncmp(flag, arr_user[i], len) == 0) {
            object.err[object.n] = i;
            ++object.n;
        }
        ++i;
    }

    fclose(f);
    return object;
}

char** create_matrix(int rows, int cols) {
    char** arr = (char**) calloc(rows, sizeof(char*));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < rows; ++i) {
        arr[i] = (char*) calloc(cols, sizeof(char));
        if (arr[i] == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
    }
    return arr;
}


void print_matrix(char** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("%s", arr[i]);
    }
    printf("\n");
}


void free_matrix(char** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}


void replace_erros(char** arr, errors object, int len) {
    for (int i = 0; i < object.n; ++i) {
        memmove(arr[object.err[i]], "_", 1);
    }
}