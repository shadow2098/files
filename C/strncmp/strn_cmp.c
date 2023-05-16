#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "get_data.h"


/*
Считать данные из файла, 
	в котором на каждой строке находится никнейм пользователя.
Посчитать какое количество никнеймов начинается на 
	заданную последовательность символов 
		(то есть предполагается 
			что эту заданную последовательность символов 
				можно менять в коде)
*/
void print_matrix(char** arr, int rows, int cols);
void read_file(char* file_name, char** arr);
char** create_matrix(int rows, int cols);
void free_matrix(char** arr, int rows);


int main() {
    int rows = 10;
    int cols = 20;
    char** arr_user = create_matrix(rows, cols);

    char file_name[20];
    get_variable(file_name);
    
    read_file(file_name, arr_user);

    print_matrix(arr_user, rows, cols);

    free_matrix(arr_user, rows);

    return 0;
}

void read_file(char* file_name, char** arr_user) {
    FILE *f = fopen(file_name, "r");

    if (f == NULL) {
        printf("Unable to open file!\n");
    }
    else {
        int i = 0;
        char text[20];
        while (fgets(text, 20, f) != NULL) {
            arr_user[i] = text;
            ++i;
        }
    }
    fclose(f);
}


char** create_matrix(int rows, int cols) {
    char** arr = (char**) malloc(rows * sizeof(char));

    for (int i = 0; i < rows; ++i) {
        arr[i] = (char*) malloc(cols * sizeof(char));
    }
    return arr;
}


void print_matrix(char** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        printf("\n");
        for (int j = 0; j < cols; j++) {
            printf("%c ", arr[i][j]);
        }
    }
    printf("\n");
}


void free_matrix(char** arr, int rows) {
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}